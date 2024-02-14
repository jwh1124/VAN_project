
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "timeout_server.pc"
};


static unsigned int sqlctx = 10396475;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
   unsigned char  *sqhstv[14];
   unsigned long  sqhstl[14];
            int   sqhsts[14];
            short *sqindv[14];
            int   sqinds[14];
   unsigned long  sqharm[14];
   unsigned long  *sqharc[14];
   unsigned short  sqadto[14];
   unsigned short  sqtdso[14];
} sqlstm = {13,14};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ unsigned char *, signed int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,0,0,0,27,146,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,30,896,0,0,0,0,0,1,0,
51,0,0,3,0,0,17,903,0,0,1,1,0,1,0,1,97,0,0,
70,0,0,3,0,0,45,917,0,0,0,0,0,1,0,
85,0,0,3,0,0,15,921,0,0,0,0,0,1,0,
100,0,0,3,0,0,13,925,0,0,1,0,0,1,0,2,3,0,0,
119,0,0,3,0,0,15,929,0,0,0,0,0,1,0,
134,0,0,3,0,0,15,933,0,0,0,0,0,1,0,
149,0,0,3,0,0,17,949,0,0,1,1,0,1,0,1,97,0,0,
168,0,0,3,0,0,45,961,0,0,0,0,0,1,0,
183,0,0,3,0,0,15,965,0,0,0,0,0,1,0,
198,0,0,3,0,0,13,968,0,0,1,0,0,1,0,2,97,0,0,
217,0,0,3,0,0,15,972,0,0,0,0,0,1,0,
232,0,0,3,0,0,15,975,0,0,0,0,0,1,0,
247,0,0,4,0,0,17,998,0,0,1,1,0,1,0,1,97,0,0,
266,0,0,4,0,0,21,1006,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
337,0,0,5,0,0,31,1011,0,0,0,0,0,1,0,
352,0,0,6,0,0,29,1016,0,0,0,0,0,1,0,
367,0,0,7,0,0,17,1039,0,0,1,1,0,1,0,1,97,0,0,
386,0,0,7,0,0,21,1046,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
421,0,0,7,0,0,17,1058,0,0,1,1,0,1,0,1,97,0,0,
440,0,0,7,0,0,21,1065,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
475,0,0,7,0,0,17,1074,0,0,1,1,0,1,0,1,97,0,0,
494,0,0,7,0,0,21,1081,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
529,0,0,7,0,0,17,1094,0,0,1,1,0,1,0,1,97,0,0,
548,0,0,7,0,0,21,1102,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
583,0,0,7,0,0,17,1112,0,0,1,1,0,1,0,1,97,0,0,
602,0,0,7,0,0,21,1120,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
637,0,0,7,0,0,17,1128,0,0,1,1,0,1,0,1,97,0,0,
656,0,0,7,0,0,21,1136,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
691,0,0,8,0,0,31,1143,0,0,0,0,0,1,0,
706,0,0,9,0,0,29,1148,0,0,0,0,0,1,0,
};


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
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>

#if 1
#define FFL
#else
#define FFL printf("------> [%.10s %.15s %04d \n", __FILE__, __FUNCTION__, __LINE__)
#endif

#define MAX_CLNT 256       // �ִ� ���� ���� ���� ��
#define BUF_SIZE 168       // ���� �ִ� SIZE�� 168
#define CARD_FRONT_SIZE 16 // ī�� ���ڸ� 16
#define CARD_BACK_SIZE 20  // ī�� ���ڸ� 20
#define CARD_EXP_SIZE 4    // ī�� ��ȿ�Ⱓ 4
#define CARD_BIN_SIZE 8
#define MEM_ZERO 0x00      // memset �ʱ�ȭ ���
#define RE_ZERO 0          // 0 �ʱ�ȭ ���
#define FAIL -1            // FAIL ���
#define FAIL_S -2          // �ٸ� FAIL ���
#define SUCCESS 0          // SUCCESS ���
#define ISCHK_FAIL 0       // is�Լ����� fail�� 0
#define MIN_AMT 1000       // �ּ� ���ο�û�ݾ�
#define MAX_AMT 1000000000 // �ִ� ���ο�û�ݾ�
#define INS_AMT 50000      // �Һΰ��� ���ο�û�ݾ�
#define ZERO_INS 0         // �Ͻú�
#define MIN_INS 2          // �ּ� �Һ� ������
#define MAX_INS 12         // �ִ� �Һ� ������

#define NO_ERROR "0000"
#define TEL_LEN_ERROR "0001"
#define TRAN_DATE_ERROR "0010"
#define TERM_NUM_ERROR "0011"
#define CARD_NUM_ERROR "0020"
#define CARD_EXP_ERROR "0021"
#define AMT_ERROR "0022"
#define INS_MON_ERROR "0023"
#define NO_TRAN_ORG "0030"

#define APPROVE_I 1     // ����
#define DENY_I 2        // ���
#define AUTODENY_I 8    // �������
#define APPROVE_S "01"  // ����
#define DENY_S "02"     // ���
#define AUTODENY_S "08" // �������

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

commTel reqStruct;
bizTel bizStruct;

int sToInt(char *orgData, int size);                                   // string to int(�ش� ��������� �߶��ش�)
long long sToLLong(char *orgData, int size);                           // string to llong(�ش� ��������� �߶��ش�)
int chkUnitNumeric(char *chkData, int size);                           // ���� Nüũ
int isAlphaNumeric(char *chkData, int size);                           // ���� AN, =üũ
int chkNumerics(commTel chkStruct);                                    // ��ü Nüũ
void copyCommToBizTel(commTel srcStruct, bizTel *destStruct);          // ���� N Ÿ�� ������ �����Ͻ� ����ü�� ��ȯ
void printStruct(bizTel printStruct);                                  // ���� ���� ���
int cardNumChk(bizTel chkStruct);                                      // ī���ȣ ���ռ� �˻�
int amtChk(bizTel chkStruct);                                          // ���� ���� �˻�
void resetStruct();                                                    // �ʱ�ȭ
int getNowDate();                                                      // ��¥ ��� �Լ� YYYYMMDD
int getNowTime();                                                      // �ð� ��� �Լ� HHMMSS
void autoApprove(char *tempApproveNum, int *approveSeqNum); // ���ι�ȣ ä�� �Լ�
void autoUnique(char *tempApproveNum, int *uniqueSeqNum); // �ŷ�������ȣ ä�� �Լ�
void DbReleaseFunc();
int executeSqlQuery(char *sSqlBuff, int nCount);
void executeBigSqlQuery(char *sSqlBuff, char* nBigCount);
int tranInsertSqlQuery(char *TranUniqNum, char *TranDate, char *TermNum, char *TranNum, char *TranType, char *CardInfo, long long ApproveAmt, char *InstMon, char *ApproveNum, char *ResCode, char *ResMsg, char *TranOrgDate, char *Cancle, char *ApproveOrgNum);
int tranUpdateSqlQuery(char *TranType, char *TermNum, char *TranNum, char *TranDate, char *OrgTranDate, char *CardInfo, char *ApproveNum, char *Cancle);
void *handelClnt(void *arg);
void errorHandling(char *msg);

time_t rawTime;       // ���� �ð� �޾ƿ��� ����
struct tm *pTimeInfo; // �ð��� ����� ���� ���� ��ȯ�ϴ� ����ü

int approveSeqNum = RE_ZERO; // ���ι�ȣ �������ѹ�
int uniqueSeqNum = RE_ZERO; // �ŷ�������ȣ �������ѹ�

char sTmpBuff[BUF_SIZE]; // �۽Ź���
char rTmpBuff[BUF_SIZE]; // ���� ����

int clntCnt = RE_ZERO;        // ������ Ŭ���̾�Ʈ ��
int clntSockThread[MAX_CLNT]; // Ŭ���̾�Ʈ �ִ� 256��
pthread_mutex_t mutx;         // mutex ���� - ���� �����峢�� �������� ���� �������� ȥ�� ����

int main(int argc, char *argv[])
{

    int servSock, clntSock;
    struct sockaddr_in servAddr, clntAddr;
    int clntAddrSize;
    pthread_t threadId; // thread ����

    char sSqlBuff[512]; // sql ��� ����
    char sID[62];
    char spwd[62];
    int nRetCode = SUCCESS;
    int option; // ���� �ɼ� ������ ���� �� ����

    memset(sID, MEM_ZERO, sizeof(sID));
    memset(spwd, MEM_ZERO, sizeof(spwd));
    strcpy(sID, "twin");
    strcpy(spwd, "twin1234");
    memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
    sprintf(sSqlBuff, "%s/%s", sID, spwd);

    /* EXEC SQL CONNECT : sSqlBuff; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sSqlBuff;
    sqlstm.sqhstl[0] = (unsigned long )512;
    sqlstm.sqhsts[0] = (         int  )512;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (sqlca.sqlcode != SUCCESS)
    {
        printf("DB CON Error \n");
    }
    else
    {
        printf("DB CON SUCCESS\n");
    }
    memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));

    socklen_t optlen;

    if (argc != 2) // ���ϸ� & port��ȣ
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutx, NULL);            // ���ؽ� �����
    servSock = socket(PF_INET, SOCK_STREAM, 0); // socket()

    optlen = sizeof(option);
    option = 1;
    setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, (void *)&option, optlen); // SO_REUSEADDR �� 0���� 1�� ����

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]));

    if (bind(servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) == -1) // bind()
    {
        errorHandling("bind() error");
    }
    if (listen(servSock, 5) == -1) // listen()
    {
        errorHandling("listen() error");
    }
    while (1) // client�� ���� ���
    {
        clntAddrSize = sizeof(clntAddr);
        clntSock = accept(servSock, (struct sockaddr *)&clntAddr, &clntAddrSize);

        pthread_mutex_lock(&mutx);            // clntSockThread[], clntCnt ���������� ����ϱ� ���� ���ؽ� ���
        clntSockThread[clntCnt++] = clntSock; // Ŭ���̾�Ʈ ī���� �ø���, ���� ���� . ù ��° Ŭ���̾�Ʈ���, clntSockThread[0] �� �� ��
        pthread_mutex_unlock(&mutx);          // ���ؽ� �������

        pthread_create(&threadId, NULL, handelClnt, (void *)&clntSock);
        pthread_detach(threadId); // ���� �ش� �����尡 NULL ���� �����ߴٸ�, ������ ����
        printf("Connected client IP: %s \n", inet_ntoa(clntAddr.sin_addr));
    }
    DbReleaseFunc();
    close(servSock); // ctrl + c �� ���α׷� ���� ��, ���� ���� ����
    return 0;
}

void *handelClnt(void *arg)
{
    int clntSock = *((int *)arg); // ���� ���� ��ũ���Ͱ� void �����ͷ� �������Ƿ�, int �� ����ȯ
    char errorCode[4 + 1];
    char errorMsg[64 + 1];
    char TranUniqNum[16 + 1];
    char tempApproveNum[15 + 1];
    char ApproveOrgNum[15 + 1];
    char sSqlBuff[512]; // sql ��� ����
    char sqlBigAns[15+1];
    char sqlBigCode[15+1];
    int sqlCode = SUCCESS;
    int sqlCount = RE_ZERO;
    int nRetCode = RE_ZERO;
    int strLen = RE_ZERO;
    char Cancle[2 + 1];
    time_t startTime, currentTime; // �ð��ޱ�
    double elapsedTime;            // ������ �ð� ����

    int nowDate;

    strcpy(Cancle, "");
    strcpy(ApproveOrgNum, "");

    resetStruct(); // ����ü �� ���� �ʱ�ȭ

    strLen = read(clntSock, rTmpBuff, sizeof(rTmpBuff));

    /* ���� ���ռ� üũ ��� */
    strcpy(errorCode, NO_ERROR);
    strcpy(errorMsg, "APPROVE OK");
    if (BUF_SIZE != strLen)
    {
        strcpy(errorCode, TEL_LEN_ERROR);
        strcpy(errorMsg, "TelLenError"); // ���� ���� ����
        pthread_mutex_unlock(&mutx);
    }
    else // ���� ������ üũ �� ���η���
    {
        pthread_mutex_lock(&mutx); // clntCnt, clntSockThread[] ��� ���� ���ؽ� ���
        printf("Request_From_Client : %s \n", rTmpBuff);

        memset(&reqStruct, MEM_ZERO, sizeof(reqStruct)); // ��û���� �ޱ� �� �ʱ�ȭ
        memcpy(&reqStruct, rTmpBuff, sizeof(reqStruct)); // ���� �ӽ� ���ۿ� �ѹ��� ����.

        copyCommToBizTel(reqStruct, &bizStruct); // ���� ���� ����

        nowDate = getNowDate();

        /*�ܸ��� ���� üũ -> �Լ�ȭ*/
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        sprintf(sSqlBuff, "SELECT count(*) FROM TBL_TERM WHERE TERM_NUM = %s  AND TERM_STATUS = '01'", bizStruct.termNum);
        sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));

        nRetCode = chkNumerics(reqStruct);
        if (FAIL == nRetCode) // reqStrunct Ÿ��üũ
        {
            strcpy(errorCode, TEL_LEN_ERROR);
            strcpy(errorMsg, "TelLenError");
        }
        else if (sToInt(bizStruct.tranDate, sizeof(bizStruct.tranDate)) > nowDate) // �ŷ����� üũ
        {
            strcpy(errorCode, TRAN_DATE_ERROR);
            strcpy(errorMsg, "tranDateError");
        }
        else if (sqlCode == FAIL || sqlCode == RE_ZERO) // �ܸ��� ���� üũ
        {
            strcpy(errorCode, TERM_NUM_ERROR);
            strcpy(errorMsg, "TERM_NUM_ERROR");
        }
        else // ���� ����
        {
            printStruct(bizStruct);
        }
    }

    // ���� ���ռ��� ����ϰ�, ���� ��û���� �̶��?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(APPROVE_S, bizStruct.tranType))
    {
        nRetCode = cardNumChk(bizStruct); // ī������ üũ

        if (SUCCESS != nRetCode)
        {
            if (FAIL != nRetCode)
            {
                strcpy(errorCode, CARD_EXP_ERROR);
                strcpy(errorMsg, "CardExpError");
            }
            else
            {
                strcpy(errorCode, CARD_NUM_ERROR);
                strcpy(errorMsg, "CardNumError");
            }
        }

        nRetCode = amtChk(bizStruct); // ���� ��û �ݾ� üũ
        if (SUCCESS != nRetCode)
        {
            if (FAIL != nRetCode)
            {
                strcpy(errorCode, INS_MON_ERROR);
                strcpy(errorMsg, "InsMon Error");
            }
            else
            {
                strcpy(errorCode, AMT_ERROR);
                strcpy(errorMsg, "AMTError");
            }
        }

        strcpy(bizStruct.tranOrgDate, bizStruct.tranDate);
    }

    // ���� ���ռ��� ����ϰ�, ��� ��û���� �̶��?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(DENY_S, bizStruct.tranType))
    {

        /*�ŷ����� üũ -> �Լ�ȭ*/
        strcpy(Cancle, "C");
        strcpy(ApproveOrgNum, bizStruct.approveNum);
        sqlCode = tranUpdateSqlQuery(bizStruct.tranType, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranDate, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum, Cancle);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        if (SUCCESS != sqlCode)
        {
            strcpy(errorCode, NO_TRAN_ORG);
            strcpy(errorMsg, "No Tran Org Error");
        }
        else
        {
        	  if (sToInt(bizStruct.tranOrgDate, sizeof(bizStruct.tranOrgDate)) == nowDate)
        	  {
            sprintf(sSqlBuff, "SELECT APPROVE_AMT  FROM TBL_TLF_ON WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            bizStruct.approveAmt = sqlCode;
            sprintf(sSqlBuff, "SELECT INST_MON  FROM TBL_TLF_ON WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            sprintf(bizStruct.instMon, "%02d", sqlCode);
            // �����ϸ� ���ŷ����� ���αݾ�, �Һΰ����� �����ͼ� ������ �Է��ϱ�
            }
            else
            {
            sprintf(sSqlBuff, "SELECT APPROVE_AMT  FROM TBL_TLF_BATCH WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            bizStruct.approveAmt = sqlCode;
            sprintf(sSqlBuff, "SELECT INST_MON  FROM TBL_TLF_BATCH WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            sprintf(bizStruct.instMon, "%02d", sqlCode);
            // �����ϸ� ���ŷ����� ���αݾ�, �Һΰ����� �����ͼ� ������ �Է��ϱ�
            }
        }
    }

    // �������ռ� ���, ������� �����̶��?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(AUTODENY_S, bizStruct.tranType))
    {
        /*�ŷ����� üũ -> �Լ�ȭ*/
        strcpy(Cancle, "R");
        
        /*�����ι�ȣ üũ*/
        if (sToInt(bizStruct.tranDate, sizeof(bizStruct.tranDate)) == nowDate)
        {
        	memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        	sprintf(sSqlBuff, "SELECT APPROVE_NUM FROM TBL_TLF_ON WHERE TRAN_ORG_DATE = '%s' AND TERM_NUM = '%s' AND CARD_INFO = '%s' AND TRAN_NUM = '%s' AND TRAN_TYPE = '01'", bizStruct.tranOrgDate, bizStruct.termNum, bizStruct.cardInfo, bizStruct.tranNum);
			executeBigSqlQuery(sSqlBuff, sqlBigAns);
        	memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        }
        else
        {
        	memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        	sprintf(sSqlBuff, "SELECT APPROVE_NUM FROM TBL_TLF_BATCH WHERE TRAN_ORG_DATE = '%s' AND TERM_NUM = '%s' AND CARD_INFO = '%s' AND TRAN_NUM = '%s' AND TRAN_TYPE = '01'", bizStruct.tranOrgDate, bizStruct.termNum, bizStruct.cardInfo, bizStruct.tranNum);
        	executeBigSqlQuery(sSqlBuff, sqlBigAns);
        	memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        }
        sprintf(ApproveOrgNum,"%s", sqlBigAns);
        
        sqlCode = tranUpdateSqlQuery(bizStruct.tranType, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranDate, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum, Cancle);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        if (SUCCESS != sqlCode)
        {
            strcpy(errorCode, NO_TRAN_ORG);
            strcpy(errorMsg, "No Tran Org Error");
        }
        else
        {
            sprintf(sSqlBuff, "SELECT APPROVE_AMT  FROM TBL_TLF_ON WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND TRAN_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.tranNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            bizStruct.approveAmt = sqlCode;
            sprintf(sSqlBuff, "SELECT INST_MON  FROM TBL_TLF_ON WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND TRAN_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.tranNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            sprintf(bizStruct.instMon, "%02d", sqlCode);
        }
    }

    memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));

    if (SUCCESS == strcmp(NO_ERROR, errorCode))
    {
    	 printf("No Error : %s %s\n", errorCode, errorMsg);

		if(SUCCESS == strcmp(APPROVE_S, bizStruct.tranType)) //���������̶��?
		{
		 autoApprove(tempApproveNum, &approveSeqNum); // ������ �ϳ��� ������ ���Ϻ� ���ι�ȣ ä��
        strcpy(bizStruct.approveNum, tempApproveNum);
		}
		else //���, ��������� ���� �����ι�ȣ�� ���󰡾� �ϴ�
		{
			strcpy(tempApproveNum, ApproveOrgNum);
		}


		 autoUnique(TranUniqNum, &uniqueSeqNum); // �ŷ� ������ȣ ä��

        sprintf(bizStruct.resCode, errorCode);
        sprintf(bizStruct.resMsg, errorMsg);

        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, tempApproveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
        // �ŷ������� ����־���Ѵ�.

        nRetCode = sprintf(sTmpBuff, "%8s%10s%8s%2s%-37s%010lld%2s%-15s%-4s%-64s%08s", bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, &bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, &bizStruct.approveNum, &bizStruct.resCode, &bizStruct.resMsg, bizStruct.tranOrgDate);

		 //write�� ���� �������� ��ü ����� �� client�� ������Ҹ� ����!
        //nRetCode = write(clntSock, sTmpBuff, sizeof(sTmpBuff));
       // sleep(6);
    	 nRetCode = -1;
    }
    else // ������ ������
    {
        autoUnique(TranUniqNum, &uniqueSeqNum); // �ŷ� ������ȣ ä��
        printf("Error Occ : %s %s\n", errorCode, errorMsg);

        sprintf(bizStruct.resCode, errorCode);
        sprintf(bizStruct.resMsg, errorMsg);

        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, bizStruct.approveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
        // �ŷ������� ����־���Ѵ�.
        nRetCode = sprintf(sTmpBuff, "%8s%10s%8s%2s%-37s%010lld%2s%-15s%-4s%-64s%08s", bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, &bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, &bizStruct.approveNum, &bizStruct.resCode, &bizStruct.resMsg, bizStruct.tranOrgDate);
        nRetCode = write(clntSock, sTmpBuff, sizeof(sTmpBuff));
    }
    
    // Ŭ���̾�Ʈ�� ������ �����Ͽ��ٸ�?, ���� �� ���̶��?, ���� ��û �ŷ����?	
    if(nRetCode < 0 && SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(APPROVE_S, bizStruct.tranType)) 
    {
    	 //��ü ����� �ǽ�
        strcpy(Cancle, "R");
        strcpy(ApproveOrgNum, bizStruct.approveNum);
        strcpy(tempApproveNum, bizStruct.approveNum);

        sprintf(bizStruct.tranType,"08");

        autoUnique(TranUniqNum, &uniqueSeqNum); // �ŷ� ������ȣ ä��
    	
        //�ŷ������� 08�� ������� �߰�
        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, tempApproveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
      
      	//������ҷ� ���ŷ� update
        sqlCode = tranUpdateSqlQuery(bizStruct.tranType, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranDate, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum, Cancle);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        
        printf("Send To Client Fail! Self 'R' Cancle Success. \n");
    }

    pthread_mutex_unlock(&mutx);

    resetStruct(); // ����ü �� ���� �ʱ�ȭ
    
    pthread_mutex_lock(&mutx);
    int i = RE_ZERO;
    
    for (i; i < clntCnt; i++) // ���� ������ Ŭ���̾�Ʈ�� "���� �����忡�� ����ϴ� ����" ����
    {
            // ���� ����ϴ� Ŭ���̾�Ʈ ������ ���� ��ũ���� ��ġ�� ã����,
            if (clntSock == clntSockThread[i])
            {
                // ���� ������ ���� ��ġ�ߴ� ���� ��������
                // ���� Ŭ���̾�Ʈ���� ���ܿ�
                while (i++ < clntCnt - 1) // ������ 1�� ������ ���̱� ������ -1 ����� ��
                {
                    clntSockThread[i] = clntSockThread[i + 1];
                }
                break;
            }
    }

    clntCnt--;                   // Ŭ���̾�Ʈ �� �ϳ� ����
    pthread_mutex_unlock(&mutx); // ���ؽ� �������
    sleep(6);
    close(clntSock);             // ������ �����忡�� ����ϴ� Ŭ���̾�Ʈ ���� ����
    return NULL;
}

void autoApprove(char *tempApproveNum, int *approveSeqNum)
{

    rawTime = time(NULL);            // ���� �ð� �ޱ�
    pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ
    int nowSec = pTimeInfo->tm_sec;

	*approveSeqNum = *approveSeqNum+1;
    sprintf(tempApproveNum, "%02d%02d%02d%02d%02d%02d%03d",
            pTimeInfo->tm_year - 100, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday, pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec,
            *approveSeqNum);
	if(*approveSeqNum >= 999)
	{
		*approveSeqNum = RE_ZERO;
	}
}

void autoUnique(char *tempApproveNum, int *uniqueSeqNum)
{

    rawTime = time(NULL);            // ���� �ð� �ޱ�
    pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ

	*uniqueSeqNum = *uniqueSeqNum+1;
    sprintf(tempApproveNum, "%04d%02d%02d%02d%02d%02d%02d",
            pTimeInfo->tm_year + 1900, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday, pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec,
           *uniqueSeqNum);
    if(*uniqueSeqNum >= 999)
	{
		*uniqueSeqNum = RE_ZERO;
	}
}

/*=========================================== */
/*amtChk                                      */
/*bizTel -> �����Ͻ� ���� ���� ����ü            */
/*bizTel ����ü�� ���ο�û�ݾ� ������             */
/* ���ռ� ����                                  */
/*=========================================== */
int amtChk(bizTel chkStruct)
{
    int result = SUCCESS;

    /*���� ��û �ݾ�*/
    if (MIN_AMT <= chkStruct.approveAmt && MAX_AMT >= chkStruct.approveAmt) // ���ο�û�ݾ��� 1õ~1�� ����
    {
        if (INS_AMT <= chkStruct.approveAmt) // 5���� �̻��̸�?
        {
            if (ZERO_INS > sToInt(chkStruct.instMon, sizeof(bizStruct.instMon)) || MAX_INS < sToInt(chkStruct.instMon, sizeof(bizStruct.instMon))) // �������� 0~12���̶��?
            {
                result = FAIL_S;
            }
        }
        else
        {
            if (sToInt(chkStruct.instMon, sizeof(bizStruct.instMon)) >= MIN_INS) // �Һΰ������� 01 ���϶��?
            {
                result = FAIL_S;
            }
        }
    }
    else // ��û�ݾ� ����
    {
        result = FAIL;
    }
    return result;
}

/*=========================================== */
/*cardNumChk                                    */
/*bizTel -> �����Ͻ� ���� ���� ����ü            */
/*bizTel ����ü�� ī�� ���� ������               */
/*'=' �������� ������ ���� ��ҿ� ���� ���ռ� ���� */
/*=========================================== */

int cardNumChk(bizTel chkStruct)
{
    /* ī�� */
    char cardFInfo[CARD_FRONT_SIZE + 1];
    char cardBInfo[CARD_BACK_SIZE + 1];
    char cardExpInfo[CARD_EXP_SIZE + 1];
    char cardBinNum[CARD_BIN_SIZE + 1];
    char cardBinNumSix[CARD_BIN_SIZE + 1 - 2];
    char *sPoint;
    char sWork[BUF_SIZE];
    int result = SUCCESS;
    char sSqlBuff[512]; // sql ��� ����
    int sqlCode = SUCCESS;
    int sqlCount = RE_ZERO;
    char syymm[4];
    char sCardExpInfo[4];
    int iCardExpInfo;
    int iyymm;

    memset(cardFInfo, MEM_ZERO, sizeof(cardFInfo));
    memset(cardBInfo, MEM_ZERO, sizeof(cardBInfo));
    memset(cardExpInfo, MEM_ZERO, sizeof(cardExpInfo));
    memset(cardBinNum, MEM_ZERO, sizeof(cardBinNum));
    memset(sWork, MEM_ZERO, sizeof(sWork));

    memcpy(sWork, chkStruct.cardInfo, sizeof(sWork)); // sWork�� ī������ �޾ƿ���
    sPoint = strtok(sWork, "=");                      // sWork�� =���� �߶� sPoint�� ����

    if (16 > strlen(sPoint) || 16 < strlen(sPoint)) // ī���ȣ 16�ڸ�
    {
        result = FAIL;
    }

    if (FAIL != result) // ī���ȣ ���ڸ��� 16�ڸ��� ������?
    {
        memcpy(cardFInfo, sPoint, CARD_FRONT_SIZE); // sPoint�� 16���� �߶� cardFInfo�� ����
        sPoint = strtok(NULL, "=");                 //=���� ������ ���� sPoint�� ����

        memcpy(sWork, sPoint, strlen(sPoint)); // sWork�� ������ �� ����
        sWork[CARD_BACK_SIZE] = MEM_ZERO;      // ������ ������ ���� ũ�⿡ �°� ����

        memcpy(cardBInfo, sWork, CARD_BACK_SIZE); // cardBInfo�� ������ �� ����

        cardBInfo[CARD_BACK_SIZE] = MEM_ZERO; // �� �� �߰�

        memcpy(cardExpInfo, sWork, CARD_EXP_SIZE); // cardExpInfo�� ��ȿ�Ⱓ ����
        cardExpInfo[CARD_EXP_SIZE] = MEM_ZERO;     // �� �� �߰�

        memcpy(cardBinNum, cardFInfo, CARD_BIN_SIZE); // ������ ����
        cardBinNum[CARD_BIN_SIZE] = MEM_ZERO;         // �� �� �߰�

        memcpy(cardBinNumSix, cardFInfo, CARD_BIN_SIZE - 2); // ������ ����
        cardBinNumSix[CARD_BIN_SIZE - 2] = MEM_ZERO;         // �� �� �߰�

        if (FAIL == chkUnitNumeric(cardFInfo, sizeof(cardFInfo) - 1) || FAIL == chkUnitNumeric(cardBInfo, sizeof(cardBInfo) - 1))
        {
            result = FAIL;
            printf("card is not num \n");
        }
        /*ī�� �չ�ȣ*/
        if (SUCCESS != strncmp("9", cardFInfo, 1))
        {
            printf("card Front is not 9 \n");
            result = FAIL;
        }

        /*ī�� �� üũ*/
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        sprintf(sSqlBuff, "SELECT count(*) FROM TBL_CARD_BIN WHERE CARD_BIN = %s AND CARD_STATUS = '01'", cardBinNum);
        sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        if (1 > sqlCode)
        {
            sprintf(sSqlBuff, "SELECT count(*) FROM TBL_CARD_BIN WHERE CARD_BIN = %s AND CARD_STATUS = '01'", cardBinNumSix);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
            if (1 > sqlCode)
            {
                result = FAIL;
            }
        }

        rawTime = time(NULL);            // ���� �ð� �ޱ�
        pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ

        rawTime = time(NULL);            // ���� �ð� �ޱ�
        pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ
        sprintf(syymm, "%02d%02d", pTimeInfo->tm_year - 100, pTimeInfo->tm_mon + 1);

        sprintf(sCardExpInfo, cardExpInfo, sizeof(sCardExpInfo));

        iyymm = sToInt(syymm, sizeof(syymm));
        iCardExpInfo = sToInt(sCardExpInfo, sizeof(sCardExpInfo));

        /*��ȿ�Ⱓ*/
        if (iCardExpInfo < iyymm)
        {
            result = FAIL_S;
        }
    }
    return result;
}

int getNowDate()
{ // �ڵ�ä�� �Լ�
    char yyyymmdd[8];
    rawTime = time(NULL);            // ���� �ð� �ޱ�
    pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ
    sprintf(yyyymmdd, "%04d%02d%02d", pTimeInfo->tm_year + 1900, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
    return atoi(yyyymmdd); // �ŷ����� �ڵ�ä��
}

int getNowTime()
{ // �ڵ�ä�� �Լ�
    char hhmmss[6];
    rawTime = time(NULL);            // ���� �ð� �ޱ�
    pTimeInfo = localtime(&rawTime); // ���� �ð� struct�� ��ȯ
    sprintf(hhmmss, "%02d%02d%02d", pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec);
    return atoi(hhmmss); // �ŷ����� �ڵ�ä��
}
// -> ��¥, �ð� �ѹ��� �ҷ��ͼ� �߶󾲴°� ����

/*=========================================== */
/*copyCommToBizTel                             */
/*commTel -> ���ʷ� ���� ���� ����ü,           */
/*bizTel -> �����Ͻ� ���� ���� ����ü              */
/*bizTel ����ü�� NŸ�� �����鿡                */
/*commTel �������� ���� ���� �Ѵ�.              */
/*=========================================== */

void copyCommToBizTel(commTel srcStruct, bizTel *destStruct)
{
    memset(destStruct, MEM_ZERO, sizeof(struct bizTelegram)); // �����Ͻ� ���� ī�� �� �ʱ�ȭ

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

/*=========================================== */
/*chkNumeric                                  */
/*commTel ����ü�� �Է¹޴´�.                  */
/*�ش� ����ü�� �������� N Ÿ������ Ȯ���ϰ�     */
/*NŸ���̶�� SUCCESS, �ƴ϶�� FAIL�� ��ȯ�Ѵ�.*/
/*=========================================== */

int chkNumerics(commTel chkStruct)
{
    int flag = SUCCESS;

    if (SUCCESS == strcmp(chkStruct.tranType, APPROVE_S) || SUCCESS == strcmp(chkStruct.tranType, AUTODENY_S))
    {
        if (FAIL == chkUnitNumeric(chkStruct.tranDate, sizeof(chkStruct.tranDate)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.termNum, sizeof(chkStruct.termNum)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.tranNum, sizeof(chkStruct.tranNum)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.approveAmt, sizeof(chkStruct.approveAmt)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.instMon, sizeof(chkStruct.instMon)))
        {
            flag = FAIL;
        }
    }
    else
    {
        if (FAIL == chkUnitNumeric(chkStruct.tranDate, sizeof(chkStruct.tranDate)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.termNum, sizeof(chkStruct.termNum)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.tranNum, sizeof(chkStruct.tranNum)))
        {
            flag = FAIL;
        }
        else if (FAIL == chkUnitNumeric(chkStruct.approveAmt, sizeof(chkStruct.approveAmt)))
        {
            flag = FAIL;
        }
    }
    return flag;
}

/*=========================================== */
/*sToInt                                      */
/*String�� �Է¹޴´�.                         */
/*Integer Ÿ������ ��ȯ�Ѵ�.                    */
/*��ȯ�Ѵ�.                                     */
/*=========================================== */
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
/*=========================================== */
/*chkUnitNumeric                              */
/*String �� �Է¹޴´�.                       */
/*�ش� String�� �������� N Ÿ������ Ȯ���ϰ�    */
/*NŸ���̶�� SUCCESS, �ƴ϶�� FAIL�� ��ȯ�Ѵ�.*/
/*=========================================== */
int chkUnitNumeric(char *chkData, int size)
{
    char sWork[BUF_SIZE];
    int result = RE_ZERO;
    memset(sWork, MEM_ZERO, sizeof(sWork));
    memcpy(sWork, chkData, size);
    int i;
    for (i = RE_ZERO; i < size; i++)
    {
        if (ISCHK_FAIL == isdigit(sWork[i]))
        {
            result = FAIL; // ���ڰ� �ƴ� ���ڰ� �����Ƿ� int �迭�� �ƴ�
        }
    }
    return result;
}

/*=========================================== */
/*chkUnitAlphaNu                              */
/*String �� �Է¹޴´�.                       */
/*�ش� String�� �������� AN Ÿ������ Ȯ���ϰ�    */
/*ANŸ���̶�� SUCCESS, �ƴ϶�� FAIL�� ��ȯ�Ѵ�.*/
/*=========================================== */
int chkUnitAlphaNu(char *chkData, int size)
{
    char sWork[BUF_SIZE];
    int result = RE_ZERO;
    memset(sWork, MEM_ZERO, sizeof(sWork));
    memcpy(sWork, chkData, size);
    int i;
    for (i = RE_ZERO; i < size; i++)
    {
        if (ISCHK_FAIL == isalnum(sWork[i]) && '=' != sWork[i])
        {
            result = FAIL; // ����, ���� �� �ƴ� ���ڰ� �����Ƿ� int �迭�� �ƴ�
        }
    }
    return result;
}

void errorHandling(char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void printStruct(bizTel printStruct)
{
	printf("\n");
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

void resetStruct() // ����ü �ʱ�ȭ �Լ�
{
    memset(reqStruct.tranDate, MEM_ZERO, sizeof(reqStruct.tranDate));
    memset(reqStruct.termNum, MEM_ZERO, sizeof(reqStruct.termNum));
    memset(reqStruct.tranNum, MEM_ZERO, sizeof(reqStruct.tranNum));
    memset(reqStruct.tranType, MEM_ZERO, sizeof(reqStruct.tranType));
    memset(reqStruct.cardInfo, MEM_ZERO, sizeof(reqStruct.cardInfo));
    memset(reqStruct.approveAmt, MEM_ZERO, sizeof(reqStruct.approveAmt));
    memset(reqStruct.instMon, MEM_ZERO, sizeof(reqStruct.instMon));
    memset(reqStruct.approveNum, MEM_ZERO, sizeof(reqStruct.approveNum));
    memset(reqStruct.resCode, MEM_ZERO, sizeof(reqStruct.resCode));
    memset(reqStruct.resMsg, MEM_ZERO, sizeof(reqStruct.resMsg));
    memset(reqStruct.tranOrgDate, MEM_ZERO, sizeof(reqStruct.tranOrgDate));

    memset(bizStruct.tranDate, MEM_ZERO, sizeof(bizStruct.tranDate));
    memset(bizStruct.termNum, MEM_ZERO, sizeof(bizStruct.termNum));
    memset(bizStruct.tranNum, MEM_ZERO, sizeof(bizStruct.tranNum));
    memset(bizStruct.tranType, MEM_ZERO, sizeof(bizStruct.tranType));
    memset(bizStruct.cardInfo, MEM_ZERO, sizeof(bizStruct.cardInfo));
    bizStruct.approveAmt = RE_ZERO;
    memset(bizStruct.instMon, MEM_ZERO, sizeof(bizStruct.instMon));
    memset(bizStruct.approveNum, MEM_ZERO, sizeof(bizStruct.approveNum));
    memset(bizStruct.resCode, MEM_ZERO, sizeof(bizStruct.resCode));
    memset(bizStruct.resMsg, MEM_ZERO, sizeof(bizStruct.resMsg));
    memset(bizStruct.tranOrgDate, MEM_ZERO, sizeof(bizStruct.tranOrgDate));

    memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));
    memset(rTmpBuff, MEM_ZERO, sizeof(rTmpBuff));
}

void DbReleaseFunc()
{
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

int executeSqlQuery(char *sSqlBuff, int nCount)
{
    int nDataCount = 0;

    /* EXEC SQL PREPARE select_smt FROM : sSqlBuff; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )51;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sSqlBuff;
    sqlstm.sqhstl[0] = (unsigned long )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("SELECT PREPARE ERROR [%d] \n", sqlca.sqlcode);
        return FAIL;
    }

    /* EXEC SQL DECLARE select_cur CURSOR FOR select_smt; */ 

    if (sqlca.sqlcode != SUCCESS)
    {
        printf("DECLARE ERROR [%d] \n", sqlca.sqlcode);
        return FAIL;
    }

    /* EXEC SQL OPEN select_cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )70;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("OPEN ERROR [%d] \n", sqlca.sqlcode);
        /* EXEC SQL CLOSE select_cur; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )85;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAIL;
    }

    /* EXEC SQL FETCH select_cur INTO : nDataCount; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )100;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&nDataCount;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("FETCH ERROR [%d] \n", sqlca.sqlcode);
        /* EXEC SQL CLOSE select_cur; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )119;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAIL;
    }

    /* EXEC SQL CLOSE select_cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )134;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("CLOSE ERROR [%d] \n", sqlca.sqlcode);
        return FAIL;
    }

    nCount = nDataCount;

    return nCount;
}

void executeBigSqlQuery(char *sSqlBuff, char *nBigCount)
{
    char approveNum[15+1];

    /* EXEC SQL PREPARE select_smt FROM : sSqlBuff; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )149;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sSqlBuff;
    sqlstm.sqhstl[0] = (unsigned long )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("SELECT PREPARE ERROR [%d] \n", sqlca.sqlcode);
    }

    /* EXEC SQL DECLARE select_cur CURSOR FOR select_smt; */ 

    if (sqlca.sqlcode != SUCCESS)
    {
        printf("DECLARE ERROR [%d] \n", sqlca.sqlcode);
    }

    /* EXEC SQL OPEN select_cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )168;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("OPEN ERROR [%d] \n", sqlca.sqlcode);
        /* EXEC SQL CLOSE select_cur; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )183;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }

    /* EXEC SQL FETCH select_cur INTO : approveNum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )198;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)approveNum;
    sqlstm.sqhstl[0] = (unsigned long )16;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("FETCH ERROR [%d] \n", sqlca.sqlcode);
        /* EXEC SQL CLOSE select_cur; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )217;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }

    /* EXEC SQL CLOSE select_cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )232;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (sqlca.sqlcode != SUCCESS)
    {
        printf("CLOSE ERROR [%d] \n", sqlca.sqlcode);
    }

    sprintf(nBigCount,"%s",approveNum);
}

int tranInsertSqlQuery(char *TranUniqNum, char *TranDate, char *TermNum, char *TranNum, char *TranType, char *CardInfo, long long ApproveAmt, char *InstMon, char *ApproveNum, char *ResCode, char *ResMsg, char *TranOrgDate, char *Cancle, char *ApproveOrgNum)
{

    char sTmpBuff[1024 + 1];
    int nRetCode;
    memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));

    sprintf(sTmpBuff, "INSERT INTO TBL_TLF_ON \n"
                      "(TRAN_UNIQ_NUM, TRAN_DATE, TERM_NUM, TRAN_NUM, TRAN_TYPE, CARD_INFO, APPROVE_AMT, \n"
                      "INST_MON, APPROVE_NUM, RES_CODE, RES_MSG, TRAN_ORG_DATE, CANCLE, APPROVE_ORG_NUM) \n"
                      " VALUES \n"
                      "(:TranUniqNum, : TranDate, :TermNum, :TranNum, :TranType, :CardInfo, \n"
                      " :ApproveAmt, :InstMon, :ApproveNum, :ResCode, :ResMsg, :TranOrgDate, :Cancle, :ApproveOrgNum) ");

    /* EXEC SQL PREPARE insert_smt FROM : sTmpBuff; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )247;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
    sqlstm.sqhstl[0] = (unsigned long )1025;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (sqlca.sqlcode != SUCCESS)
    {
        printf(" INSERT PREPARE ERROR [%d] \n", sqlca.sqlcode);
        nRetCode = FAIL;
    }

    /* EXEC SQL EXECUTE insert_smt USING : TranUniqNum, : TranDate, : TermNum, : TranNum, : TranType, : CardInfo, : ApproveAmt, : InstMon, : ApproveNum, : ResCode, : ResMsg, : TranOrgDate, : Cancle, : ApproveOrgNum; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )266;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)TranUniqNum;
    sqlstm.sqhstl[0] = (unsigned long )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)TranDate;
    sqlstm.sqhstl[1] = (unsigned long )0;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)TermNum;
    sqlstm.sqhstl[2] = (unsigned long )0;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)TranNum;
    sqlstm.sqhstl[3] = (unsigned long )0;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)TranType;
    sqlstm.sqhstl[4] = (unsigned long )0;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)CardInfo;
    sqlstm.sqhstl[5] = (unsigned long )0;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&ApproveAmt;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)InstMon;
    sqlstm.sqhstl[7] = (unsigned long )0;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)ApproveNum;
    sqlstm.sqhstl[8] = (unsigned long )0;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)ResCode;
    sqlstm.sqhstl[9] = (unsigned long )0;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)ResMsg;
    sqlstm.sqhstl[10] = (unsigned long )0;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)TranOrgDate;
    sqlstm.sqhstl[11] = (unsigned long )0;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)Cancle;
    sqlstm.sqhstl[12] = (unsigned long )0;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)ApproveOrgNum;
    sqlstm.sqhstl[13] = (unsigned long )0;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (sqlca.sqlcode != SUCCESS)
    {
        printf("INSERT EXECUTE Error! [%d] \n", sqlca.sqlcode);
        /* EXEC SQL ROLLBACK WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )337;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        nRetCode = FAIL;
    }
    else
    {
        /* EXEC SQL COMMIT WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )352;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    return nRetCode;
}

int tranUpdateSqlQuery(char *TranType, char *TermNum, char *TranNum, char *TranDate, char *OrgTranDate, char *CardInfo, char *ApproveNum, char *Cancle)
{
    char sTmpBuff[1024 + 1];
    int nRetCode = SUCCESS;
    memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));
    int nowDate;
    nowDate = getNowDate();
    if (strcmp(TranType, DENY_S) == SUCCESS)
    { // �Ϲ� ��ҽ� UPDATE
        if (sToInt(OrgTranDate, sizeof(OrgTranDate)) == nowDate)
        { // �����̸� �¶��� UPDATE
            sprintf(sTmpBuff, "UPDATE TBL_TLF_ON \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM = :TermNum \n"
                              "AND TRAN_ORG_DATE = :OrgTranDate \n"
                              "AND CARD_INFO = :CardInfo \n"
                              "AND APPROVE_NUM = :ApproveNum");

            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )367;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }
            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : OrgTranDate, : CardInfo, : ApproveNum; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )386;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)OrgTranDate;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)ApproveNum;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
        else
        { // ���� ���ŷ��� �ƴϸ� �¶���, ��ġ ������Ʈ

            sprintf(sTmpBuff, "UPDATE TBL_TLF_ON \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM = :TermNum \n"
                              "AND TRAN_ORG_DATE = :OrgTranDate \n"
                              "AND CARD_INFO = :CardInfo \n"
                              "AND APPROVE_NUM = :ApproveNum");

            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )421;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }
            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : OrgTranDate, : CardInfo, : ApproveNum; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )440;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)OrgTranDate;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)ApproveNum;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            sprintf(sTmpBuff, "UPDATE TBL_TLF_BATCH \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM = :TermNum \n"
                              "AND TRAN_ORG_DATE = :OrgTranDate \n"
                              "AND CARD_INFO = :CardInfo \n"
                              "AND APPROVE_NUM = :ApproveNum");

            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )475;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }
            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : OrgTranDate, : CardInfo, : ApproveNum; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )494;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)OrgTranDate;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)ApproveNum;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
    }
    else // ������� �� UPDATE
    {
        if (sToInt(OrgTranDate, sizeof(OrgTranDate)) == nowDate)
        { // �����̸� �¶��� UPDATE
            sprintf(sTmpBuff, "UPDATE TBL_TLF_ON \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM= :TermNum \n"
                              "AND TRAN_NUM = :TranNum \n"
                              "AND TRAN_DATE = :TranDate \n"
                              "AND CARD_INFO = :CardInfo");
            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )529;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }

            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : TranNum, : TranDate, : CardInfo; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )548;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)TranNum;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)TranDate;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
        else
        { // �ƴϸ� �¶���, ��ġ ������Ʈ
            sprintf(sTmpBuff, "UPDATE TBL_TLF_ON \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM= :TermNum \n"
                              "AND TRAN_NUM = :TranNum \n"
                              "AND TRAN_DATE = :TranDate \n"
                              "AND CARD_INFO = :CardInfo");
            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )583;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }

            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : TranNum, : TranDate, : CardInfo; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )602;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)TranNum;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)TranDate;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            sprintf(sTmpBuff, "UPDATE TBL_TLF_BATCH \n"
                              "SET CANCLE = :Cancle \n"
                              "WHERE TERM_NUM= :TermNum \n"
                              "AND TRAN_NUM = :TranNum \n"
                              "AND TRAN_DATE = :TranDate \n"
                              "AND CARD_INFO = :CardInfo");
            /* EXEC SQL PREPARE update_smt FROM : sTmpBuff; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )637;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)sTmpBuff;
            sqlstm.sqhstl[0] = (unsigned long )1025;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (sqlca.sqlcode != SUCCESS)
            {
                printf("UPDATE PREPARE ERROR [%d] \n", sqlca.sqlcode);
                nRetCode = FAIL;
            }

            /* EXEC SQL EXECUTE update_smt USING : Cancle, : TermNum, : TranNum, : TranDate, : CardInfo; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )656;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)Cancle;
            sqlstm.sqhstl[0] = (unsigned long )0;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)TermNum;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)TranNum;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)TranDate;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)CardInfo;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        }
    }

    if (sqlca.sqlcode != SUCCESS)
    {
        printf("UPDATE EXECUTE Error! [%d] \n", sqlca.sqlcode);
        /* EXEC SQL ROLLBACK WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )691;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        nRetCode = FAIL;
    }
    else
    {
        /* EXEC SQL COMMIT WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )706;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }

    return nRetCode;
}