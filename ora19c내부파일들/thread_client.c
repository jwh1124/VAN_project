#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <ctype.h>

#define BUF_SIZE 168         // ���� �ִ� SIZE�� 168
#define MEM_ZERO 0x00        // memset �ʱ�ȭ ���
#define RE_ZERO 0            // 0 �ʱ�ȭ ���
#define FAIL -1              // FAIL ���
#define SUCCESS 0            // SUCCESS ���
#define SELECT_ERROR -1      // SELECT ����
#define SELECT_TIMEOUT -2    // SELECT Ÿ�Ӿƿ�
#define READ_SOCKET_CLOSE -3 // READ SOCKET CLOSE

#define APPROVE 1  // ����
#define DENY 2     // ���
#define AUTODENY 8 // �������

typedef struct commTelegram // ���� ����ü ����
{
    char tranDate[8];    // �ŷ����� 8 N
    char termNum[10];    // �ܸ����ȣ 10 N
    char tranNum[8];     // �ŷ� �Ϸù�ȣ 8 N
    char tranType[2];    // �ŷ����� 2 N
    char cardInfo[37];   // ī������ A
    char approveAmt[10]; // ���ο�û�ݾ� 10N
    char instMon[2];     // �Һ� ������ 2 N
    char approveNum[15]; // ���ι�ȣ AN
    char resCode[4];     // ���� �ڵ� AN
    char resMsg[64];     // ���� �޼��� AN
    char tranOrgDate[8]; // ���ŷ� ���� AN
} commTel;

typedef struct bizTelegram // ���� ����ü ����
{
    char tranDate[8 + 1];    // �ŷ����� 8 N
    char termNum[10 + 1];    // �ܸ����ȣ 10 N
    char tranNum[8 + 1];     // �ŷ� �Ϸù�ȣ 8 N
    char tranType[2 + 1];    // �ŷ����� 2 N
    char cardInfo[37 + 1];   // ī������ AN
    long long approveAmt;    // ���ο�û�ݾ� 10 N
    char instMon[2 + 1];     // �Һ� ������ 2 N
    char approveNum[15 + 1]; // ���ι�ȣ AN
    char resCode[4 + 1];     // ���� �ڵ� AN
    char resMsg[64 + 1];     // ���� �޼��� AN
    char tranOrgDate[8 + 1]; // ���ŷ� ���� AN8
} bizTel;

bizTel reqStruct;
commTel commStruct;
bizTel ansStruct;

void *threadMain(void *arg); // ���� �۽� �Լ�
void printMsg(int type);     // ���� ��� �Լ�
void insertApprove(int num); // �������� �Է� �Լ�
void insertDeny(int cnt);
void resetStruct();
void printStruct(bizTel printStruct);                         // ���� ���� ���
void errorHandling(char *msg);                                // ���� ��� �Լ�
void copyCommToBizTel(commTel srcStruct, bizTel *destStruct); // ���� N Ÿ�� ������ �����Ͻ� ����ü�� ��ȯ
int sToInt(char *orgData, int size);                          // string to int(�ش� ��������� �߶��ش�)
long long sToLLong(char *orgData, int size);                  // string to llong(�ش� ��������� �߶��ش�)
int read_with_timeout(int fd, char *buf, int buf_size);       // �����Լ�
void autoInsert();                                            // �ڵ�ä�� �Լ�

time_t rawTime;          // ���� �ð� �޾ƿ��� ����
struct tm *pTimeInfo;    // �ð��� ����� ���� ���� ��ȯ�ϴ� ����ü
int preSec;              // ���� �ð� ��������
int autoDenyFlag = FAIL; // ����� �÷��� ��������
char sTmpBuff[BUF_SIZE]; // �۽Ź���
char rTmpBuff[BUF_SIZE]; // ���� ����

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in servAddr;
    pthread_t clntThread;
    void *threadReturn;      // pthread_join���� �����带 �����ϱ� ���� ���ȴ�.
    int iTranType = 0;       // �ŷ����� INTŸ������ Ȯ��
    int menuCount = RE_ZERO; // ����� �Է� �޴� ��ȣ
    int nRetCode = RE_ZERO;

    resetStruct();

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]); // IP,PORT �Է� ������ ��µǴ� MSG
        exit(1);
    }

    printf("Select your TranType \n 1 : Approve request \n 2 : Cancle request \n Type Number and Press 'ENTER' \n"); // ���ο�û, ��ҿ�û �б��Ѵ�.

    scanf(" %d", &iTranType);
    sprintf(reqStruct.tranType, "%02d", iTranType);

    autoInsert(); // �ڵ� ä�� �Լ�

    if (iTranType == APPROVE) // ���� ��û ���� �÷���
    {
        for (menuCount = 0; menuCount < 4; menuCount++)
        {
            printMsg(iTranType);
            insertApprove(menuCount);
        }
    }
    else if (iTranType == DENY) // ��� ��û
    {
        for (menuCount = 0; menuCount < 4; menuCount++)
        {
            printMsg(iTranType);
            insertDeny(menuCount);
        }
    }

    nRetCode = sprintf(sTmpBuff, "%08s%010s%08s%02s%-37s%010lld%02s% 15s% 4s% 64s%08s", &reqStruct.tranDate, &reqStruct.termNum, &reqStruct.tranNum, &reqStruct.tranType, &reqStruct.cardInfo, reqStruct.approveAmt, &reqStruct.instMon, &reqStruct.approveNum, &reqStruct.resCode, &reqStruct.resMsg, &reqStruct.tranOrgDate);

    sock = socket(PF_INET, SOCK_STREAM, RE_ZERO); // socket()

    memset(&servAddr, RE_ZERO, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(atoi(argv[2]));                                 // bind()
    nRetCode = connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)); // connect()
    if (nRetCode == FAIL)
    {
        errorHandling("Connection Fail!"); // ���� ���н�
    }

    pthread_create(&clntThread, NULL, threadMain, (void *)&sock); // ������ ����
    pthread_join(clntThread, &threadReturn);                      // ������ ���� ��� �� �Ҹ� ����

    if (SUCCESS == autoDenyFlag) // ��� ���μ����� ����Ǿ��� ��, ����� �÷��װ� SUCCESS��?
    {
        printf("AutoDeny processing : 08 \n");
        int errChk = RE_ZERO;
        memset(&sTmpBuff, RE_ZERO, sizeof(sTmpBuff));
        strcpy(reqStruct.tranType, "08");
        strcpy(reqStruct.tranOrgDate, reqStruct.tranDate);
        nRetCode = sprintf(sTmpBuff, "%8s%10s%8s%2s%-37s%010lld%2s%-15s%-4s%-64s%08s", &reqStruct.tranDate, &reqStruct.termNum, &reqStruct.tranNum, &reqStruct.tranType, &reqStruct.cardInfo, reqStruct.approveAmt, &reqStruct.instMon, &reqStruct.approveNum, &reqStruct.resCode, &reqStruct.resMsg, &reqStruct.tranOrgDate);

        sock = socket(PF_INET, SOCK_STREAM, RE_ZERO); // socket()

        memset(&servAddr, RE_ZERO, sizeof(servAddr));
        servAddr.sin_family = AF_INET;
        servAddr.sin_addr.s_addr = inet_addr(argv[1]);
        servAddr.sin_port = htons(atoi(argv[2])); // bind()

        nRetCode = connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)); // connect()
        if (nRetCode == FAIL)
        {
            errorHandling("Connection Fail!"); // ���� ���н�
        }

        pthread_create(&clntThread, NULL, threadMain, (void *)&sock); // ������ ����
        pthread_join(clntThread, &threadReturn);                      // ������ ���� ��� �� �Ҹ� ����
    }

    close(sock); // Ŭ���̾�Ʈ ���� ����
    return 0;
}

void *threadMain(void *arg) // clntThread ��  main
{
    int sock = *((int *)arg); // ���� ���� ��ũ���Ͱ� void �����ͷ� �������Ƿ�, int �� ����ȯ
    int nRetCode = RE_ZERO;

    nRetCode = write(sock, sTmpBuff, sizeof(sTmpBuff)); // Server�� ���� �۽�
    printf("Socket Write Success\n", nRetCode);         // write�� ���ϰ� ����

    nRetCode = read_with_timeout(sock, rTmpBuff, sizeof(rTmpBuff));

    if (SUCCESS == nRetCode) //Read�� �������� ��
    {
        memset(&commStruct, MEM_ZERO, sizeof(commStruct));
        memset(&ansStruct, MEM_ZERO, sizeof(ansStruct));
        memcpy(&commStruct, rTmpBuff, sizeof(commStruct)); // ���� �ӽ� ���ۿ� �ѹ��� ����.

        copyCommToBizTel(commStruct, &ansStruct); // ���� ���� ����
        printStruct(ansStruct);

        close(sock);
    }
    else											//Read�� �������� ��
    {
        close(sock);
        autoDenyFlag = SUCCESS;
    }

    return NULL;
}

void errorHandling(char *msg)
{ // ���� �߻��� �޽��� ���
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void printMsg(int type)
{ // ����ڰ� �Է� �� �� �������� ����ش�.
    if (type == APPROVE)
    {
    	printf("TranDate          : %s\n", reqStruct.tranDate);
    	printf("TermNum           : %s\n", reqStruct.termNum);
    	printf("TranNum           : %s\n", reqStruct.tranNum);
    	printf("TranType          : %s\n", reqStruct.tranType);
    	printf("CardInfo          : %s\n", & reqStruct.cardInfo);
    	printf("ApproveAmt        : %lld\n", reqStruct.approveAmt);
    	printf("InstMon           : %s\n", reqStruct.instMon);
    }
    if (type == DENY)
    {
    	printf("sTranOrgDate       : %s\n", reqStruct.tranOrgDate);
    	printf("TermNum            : %s\n", reqStruct.termNum);
    	printf("TranNum            : %s\n", reqStruct.tranNum);
    	printf("TranType           : %s\n", reqStruct.tranType);
    	printf("CardInfo           : %s\n", & reqStruct.cardInfo);
    	printf("ApproveNum         : %s\n", &reqStruct.approveNum);
    }
}

void insertApprove(int cnt)
{ // ���� ��û�� ����ڰ� �Է��� ������
    long long termNum = RE_ZERO;
    int instMon = RE_ZERO;
    if (cnt == 0)
    {
        printf("Insert TermNum   : ");
        scanf("%010lld", &termNum);
        sprintf(reqStruct.termNum, "%010lld", termNum);
    }
    else if (cnt == 1)
    {
        printf("Insert CardInfo  : ");
        scanf("%37s", &reqStruct.cardInfo);
    }
    else if (cnt == 2)
    {
        printf("Insert ApproveAmt : ");
        scanf("%lld", &reqStruct.approveAmt);
    }
    else if (cnt == 3)
    {
        printf("Insert InstMonth : ");
        scanf("%02d", &instMon);
        sprintf(reqStruct.instMon, "%02d", instMon);
    }
}

void insertDeny(int cnt)
{ // ���� ��û�� ����ڰ� �Է��� ������
    long long termNum;
    int instMon;
    if (cnt == 0)
    {
        printf("Insert TranOrgDate : ");
        scanf("%8s", &reqStruct.tranOrgDate);
    }
    else if (cnt == 1)
    {
        printf("Insert TermNum  : ");
        scanf("%010lld", &termNum);
        sprintf(reqStruct.termNum, "%010lld", termNum);
    }
    else if (cnt == 2)
    {
        printf("Insert CardInfo     : ");
        scanf("%37s", &reqStruct.cardInfo);
    }
    else if (cnt == 3)
    {
        printf("Insert ApproveNum : ");
        scanf("%15s", &reqStruct.approveNum);
    }
}

void autoInsert()
{ // �ڵ�ä�� �Լ�
    char yyyymmdd[8];
    char ddhhmmss[8];
    rawTime = time(NULL);            // ���� �ð� �ޱ�
    pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ
    sprintf(yyyymmdd, "%04d%02d%02d", pTimeInfo->tm_year + 1900, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
    sprintf(ddhhmmss, "%02d%02d%02d%02d", pTimeInfo->tm_mday, pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec);
    sprintf(reqStruct.tranDate, yyyymmdd);
    //�ӽ÷� ������ ���� ���� ������
   	//sprintf(reqStruct.tranDate, "20240108");
    sprintf(reqStruct.tranNum, ddhhmmss);
}

void resetStruct()
{ // ����ü �ʱ�ȭ �Լ�
    memset(reqStruct.tranDate, MEM_ZERO, sizeof(reqStruct.tranDate));
    memset(reqStruct.termNum, MEM_ZERO, sizeof(reqStruct.termNum));
    memset(reqStruct.tranNum, MEM_ZERO, sizeof(reqStruct.tranNum));
    memset(reqStruct.tranType, MEM_ZERO, sizeof(reqStruct.tranType));
    memset(reqStruct.cardInfo, MEM_ZERO, sizeof(reqStruct.cardInfo));
    reqStruct.approveAmt = RE_ZERO;
    memset(reqStruct.instMon, MEM_ZERO, sizeof(reqStruct.instMon));
    memset(reqStruct.approveNum, MEM_ZERO, sizeof(reqStruct.approveNum));
    memset(reqStruct.resCode, MEM_ZERO, sizeof(reqStruct.resCode));
    memset(reqStruct.resMsg, MEM_ZERO, sizeof(reqStruct.resMsg));
    memset(reqStruct.tranOrgDate, MEM_ZERO, sizeof(reqStruct.tranOrgDate));

    memset(ansStruct.tranDate, MEM_ZERO, sizeof(ansStruct.tranDate));
    memset(ansStruct.termNum, MEM_ZERO, sizeof(ansStruct.termNum));
    memset(ansStruct.tranNum, MEM_ZERO, sizeof(ansStruct.tranNum));
    memset(ansStruct.tranType, MEM_ZERO, sizeof(ansStruct.tranType));
    memset(ansStruct.cardInfo, MEM_ZERO, sizeof(ansStruct.cardInfo));
    ansStruct.approveAmt = RE_ZERO;
    memset(ansStruct.instMon, MEM_ZERO, sizeof(ansStruct.instMon));
    memset(ansStruct.approveNum, MEM_ZERO, sizeof(ansStruct.approveNum));
    memset(ansStruct.resCode, MEM_ZERO, sizeof(ansStruct.resCode));
    memset(ansStruct.resMsg, MEM_ZERO, sizeof(ansStruct.resMsg));
    memset(ansStruct.tranOrgDate, MEM_ZERO, sizeof(ansStruct.tranOrgDate));

    memset(commStruct.tranDate, MEM_ZERO, sizeof(commStruct.tranDate));
    memset(commStruct.termNum, MEM_ZERO, sizeof(commStruct.termNum));
    memset(commStruct.tranNum, MEM_ZERO, sizeof(commStruct.tranNum));
    memset(commStruct.tranType, MEM_ZERO, sizeof(commStruct.tranType));
    memset(commStruct.cardInfo, MEM_ZERO, sizeof(commStruct.cardInfo));
    memset(commStruct.approveAmt, MEM_ZERO, sizeof(commStruct.approveAmt));
    memset(commStruct.instMon, MEM_ZERO, sizeof(commStruct.instMon));
    memset(commStruct.approveNum, MEM_ZERO, sizeof(commStruct.approveNum));
    memset(commStruct.resCode, MEM_ZERO, sizeof(commStruct.resCode));
    memset(commStruct.resMsg, MEM_ZERO, sizeof(commStruct.resMsg));
    memset(commStruct.tranOrgDate, MEM_ZERO, sizeof(commStruct.tranOrgDate));

    memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));
    memset(rTmpBuff, MEM_ZERO, sizeof(rTmpBuff));
}

int read_with_timeout(int fd, char *buf, int buf_size)
{
    int rx_len = RE_ZERO;
    int readReturn = SUCCESS;
    int selectReturn = RE_ZERO;

    struct timeval timeout;
    fd_set readFds;

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    FD_ZERO(&readFds);
    FD_SET(fd, &readFds);

    selectReturn = select(fd + 1, &readFds, NULL, NULL, &timeout); // Ÿ�Ӿƿ� �ð� ���� �̺�Ʈ�� ��ٸ���.
    if (selectReturn < RE_ZERO)
    {
        printf("Socket Select FAIL\n");
        readReturn = SELECT_ERROR;
    }
    if (selectReturn == RE_ZERO)
    {
        printf("TimeOut occure\n");
        readReturn = SELECT_TIMEOUT;
    }
    if (FD_ISSET(fd, &readFds))
    {
        rx_len = read(fd, buf, buf_size);
        if (rx_len == RE_ZERO)
        {
            printf("Socked closed\n");
            readReturn = READ_SOCKET_CLOSE;
        }
    }

    return readReturn;
}

void printStruct(bizTel printStruct)
{
    printf("TranDate          : %s\n", printStruct.tranDate);
    printf("TermNum           : %010lld\n", sToLLong(printStruct.termNum, sizeof(printStruct.termNum)));
    printf("TranNum           : %s\n", printStruct.tranNum);
    printf("TranType          : %02d\n", sToInt(printStruct.tranType, sizeof(printStruct.tranType)));
    printf("CardInfo          : %s\n", printStruct.cardInfo);
    printf("ApproveAmt        : %lld\n", printStruct.approveAmt);
    printf("InstMon           : %02d\n", sToInt(printStruct.instMon, sizeof(printStruct.instMon)));
    printf("ApproveNum        : %s\n", printStruct.approveNum);
    printf("ResCode           : %s\n", printStruct.resCode);
    printf("ResMsg            : %s\n", printStruct.resMsg);
    printf("TranOrgDate     : %s\n", printStruct.tranOrgDate);
}

void copyCommToBizTel(commTel srcStruct, bizTel *destStruct)
{

    destStruct->approveAmt = sToInt(srcStruct.approveAmt, sizeof(srcStruct.approveAmt));

    memcpy(destStruct->tranDate, srcStruct.tranDate, sizeof(srcStruct.tranDate));
    memcpy(destStruct->termNum, srcStruct.termNum, sizeof(srcStruct.termNum));
    memcpy(destStruct->tranNum, srcStruct.tranNum, sizeof(srcStruct.tranNum));
    memcpy(destStruct->tranType, srcStruct.tranType, sizeof(srcStruct.tranType));
    memcpy(destStruct->cardInfo, srcStruct.cardInfo, sizeof(srcStruct.cardInfo));
    memcpy(destStruct->instMon, srcStruct.instMon, sizeof(srcStruct.instMon));
    memcpy(destStruct->approveNum, srcStruct.approveNum, sizeof(srcStruct.approveNum));
    memcpy(destStruct->resCode, srcStruct.resCode, sizeof(srcStruct.resCode));
    memcpy(destStruct->resMsg, srcStruct.resMsg, sizeof(srcStruct.resMsg));
    memcpy(destStruct->tranOrgDate, srcStruct.tranOrgDate, sizeof(srcStruct.tranOrgDate));
}

int sToInt(char *orgData, int size)
{
    char sWork[BUF_SIZE];
    memset(sWork, MEM_ZERO, sizeof(sWork));
    memcpy(sWork, orgData, size);
    return atoi(sWork);
}

long long sToLLong(char *orgData, int size)
{
    char sWork[BUF_SIZE];
    memset(sWork, MEM_ZERO, sizeof(sWork));
    memcpy(sWork, orgData, size);
    return atoll(sWork);
}