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

#define BUF_SIZE 168         // 전문 최대 SIZE는 168
#define MEM_ZERO 0x00        // memset 초기화 상수
#define RE_ZERO 0            // 0 초기화 상수
#define FAIL -1              // FAIL 상수
#define SUCCESS 0            // SUCCESS 상수
#define SELECT_ERROR -1      // SELECT 에러
#define SELECT_TIMEOUT -2    // SELECT 타임아웃
#define READ_SOCKET_CLOSE -3 // READ SOCKET CLOSE

#define APPROVE 1  // 승인
#define DENY 2     // 취소
#define AUTODENY 8 // 망상취소

typedef struct commTelegram // 전문 구조체 선언
{
    char tranDate[8];    // 거래일자 8 N
    char termNum[10];    // 단말기번호 10 N
    char tranNum[8];     // 거래 일련번호 8 N
    char tranType[2];    // 거래종류 2 N
    char cardInfo[37];   // 카드정보 A
    char approveAmt[10]; // 승인요청금액 10N
    char instMon[2];     // 할부 개월수 2 N
    char approveNum[15]; // 승인번호 AN
    char resCode[4];     // 응답 코드 AN
    char resMsg[64];     // 응답 메세지 AN
    char tranOrgDate[8]; // 원거래 일자 AN
} commTel;

typedef struct bizTelegram // 전문 구조체 선언
{
    char tranDate[8 + 1];    // 거래일자 8 N
    char termNum[10 + 1];    // 단말기번호 10 N
    char tranNum[8 + 1];     // 거래 일련번호 8 N
    char tranType[2 + 1];    // 거래종류 2 N
    char cardInfo[37 + 1];   // 카드정보 AN
    long long approveAmt;    // 승인요청금액 10 N
    char instMon[2 + 1];     // 할부 개월수 2 N
    char approveNum[15 + 1]; // 승인번호 AN
    char resCode[4 + 1];     // 응답 코드 AN
    char resMsg[64 + 1];     // 응답 메세지 AN
    char tranOrgDate[8 + 1]; // 원거래 일자 AN8
} bizTel;

bizTel reqStruct;
commTel commStruct;
bizTel ansStruct;

void *threadMain(void *arg); // 전문 송신 함수
void printMsg(int type);     // 전문 출력 함수
void insertApprove(int num); // 전문정보 입력 함수
void insertDeny(int cnt);
void resetStruct();
void printStruct(bizTel printStruct);                         // 정상 전문 출력
void errorHandling(char *msg);                                // 에러 출력 함수
void copyCommToBizTel(commTel srcStruct, bizTel *destStruct); // 수신 N 타입 전문을 비지니스 구조체로 변환
int sToInt(char *orgData, int size);                          // string to int(해당 사이즈까지 잘라준다)
long long sToLLong(char *orgData, int size);                  // string to llong(해당 사이즈까지 잘라준다)
int read_with_timeout(int fd, char *buf, int buf_size);       // 리드함수
void autoInsert();                                            // 자동채번 함수

time_t rawTime;          // 현재 시간 받아오는 변수
struct tm *pTimeInfo;    // 시간을 사람이 보기 쉽게 변환하는 구조체
int preSec;              // 이전 시간 전역변수
int autoDenyFlag = FAIL; // 망취소 플래그 전역변수
char sTmpBuff[BUF_SIZE]; // 송신버퍼
char rTmpBuff[BUF_SIZE]; // 수신 버퍼

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in servAddr;
    pthread_t clntThread;
    void *threadReturn;      // pthread_join으로 쓰레드를 종료하기 위해 사용된다.
    int iTranType = 0;       // 거래종류 INT타입으로 확인
    int menuCount = RE_ZERO; // 출력할 입력 메뉴 번호
    int nRetCode = RE_ZERO;

    resetStruct();

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]); // IP,PORT 입력 오류시 출력되는 MSG
        exit(1);
    }

    printf("Select your TranType \n 1 : Approve request \n 2 : Cancle request \n Type Number and Press 'ENTER' \n"); // 승인요청, 취소요청 분기한다.

    scanf(" %d", &iTranType);
    sprintf(reqStruct.tranType, "%02d", iTranType);

    autoInsert(); // 자동 채번 함수

    if (iTranType == APPROVE) // 승인 요청 전문 플래그
    {
        for (menuCount = 0; menuCount < 4; menuCount++)
        {
            printMsg(iTranType);
            insertApprove(menuCount);
        }
    }
    else if (iTranType == DENY) // 취소 요청
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
        errorHandling("Connection Fail!"); // 연결 실패시
    }

    pthread_create(&clntThread, NULL, threadMain, (void *)&sock); // 쓰레드 생성
    pthread_join(clntThread, &threadReturn);                      // 쓰레드 종료 대기 및 소멸 유도

    if (SUCCESS == autoDenyFlag) // 모든 프로세스가 종료되었을 때, 망취소 플래그가 SUCCESS면?
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
            errorHandling("Connection Fail!"); // 연결 실패시
        }

        pthread_create(&clntThread, NULL, threadMain, (void *)&sock); // 쓰레드 생성
        pthread_join(clntThread, &threadReturn);                      // 쓰레드 종료 대기 및 소멸 유도
    }

    close(sock); // 클라이언트 연결 종료
    return 0;
}

void *threadMain(void *arg) // clntThread 의  main
{
    int sock = *((int *)arg); // 소켓 파일 디스크립터가 void 포인터로 들어왔으므로, int 로 형변환
    int nRetCode = RE_ZERO;

    nRetCode = write(sock, sTmpBuff, sizeof(sTmpBuff)); // Server로 전문 송신
    printf("Socket Write Success\n", nRetCode);         // write의 리턴값 측정

    nRetCode = read_with_timeout(sock, rTmpBuff, sizeof(rTmpBuff));

    if (SUCCESS == nRetCode) //Read에 성공했을 때
    {
        memset(&commStruct, MEM_ZERO, sizeof(commStruct));
        memset(&ansStruct, MEM_ZERO, sizeof(ansStruct));
        memcpy(&commStruct, rTmpBuff, sizeof(commStruct)); // 전문 임시 버퍼에 한번에 복사.

        copyCommToBizTel(commStruct, &ansStruct); // 전문 구조 변경
        printStruct(ansStruct);

        close(sock);
    }
    else											//Read에 실패했을 때
    {
        close(sock);
        autoDenyFlag = SUCCESS;
    }

    return NULL;
}

void errorHandling(char *msg)
{ // 에러 발생시 메시지 출력
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void printMsg(int type)
{ // 사용자가 입력 할 때 정보들을 띄워준다.
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
{ // 승인 요청시 사용자가 입력할 정보들
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
{ // 승인 요청시 사용자가 입력할 정보들
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
{ // 자동채번 함수
    char yyyymmdd[8];
    char ddhhmmss[8];
    rawTime = time(NULL);            // 현재 시간 받기
    pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환
    sprintf(yyyymmdd, "%04d%02d%02d", pTimeInfo->tm_year + 1900, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
    sprintf(ddhhmmss, "%02d%02d%02d%02d", pTimeInfo->tm_mday, pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec);
    sprintf(reqStruct.tranDate, yyyymmdd);
    //임시로 생성할 이전 일자 데이터
   	//sprintf(reqStruct.tranDate, "20240108");
    sprintf(reqStruct.tranNum, ddhhmmss);
}

void resetStruct()
{ // 구조체 초기화 함수
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

    selectReturn = select(fd + 1, &readFds, NULL, NULL, &timeout); // 타임아웃 시간 동안 이벤트를 기다린다.
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