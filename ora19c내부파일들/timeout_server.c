
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

#define MAX_CLNT 256       // 최대 동시 접속 가능 수
#define BUF_SIZE 168       // 전문 최대 SIZE는 168
#define CARD_FRONT_SIZE 16 // 카드 앞자리 16
#define CARD_BACK_SIZE 20  // 카드 뒷자리 20
#define CARD_EXP_SIZE 4    // 카드 유효기간 4
#define CARD_BIN_SIZE 8
#define MEM_ZERO 0x00      // memset 초기화 상수
#define RE_ZERO 0          // 0 초기화 상수
#define FAIL -1            // FAIL 상수
#define FAIL_S -2          // 다른 FAIL 상수
#define SUCCESS 0          // SUCCESS 상수
#define ISCHK_FAIL 0       // is함수에서 fail은 0
#define MIN_AMT 1000       // 최소 승인요청금액
#define MAX_AMT 1000000000 // 최대 승인요청금액
#define INS_AMT 50000      // 할부가능 승인요청금액
#define ZERO_INS 0         // 일시불
#define MIN_INS 2          // 최소 할부 개월수
#define MAX_INS 12         // 최대 할부 개월수

#define NO_ERROR "0000"
#define TEL_LEN_ERROR "0001"
#define TRAN_DATE_ERROR "0010"
#define TERM_NUM_ERROR "0011"
#define CARD_NUM_ERROR "0020"
#define CARD_EXP_ERROR "0021"
#define AMT_ERROR "0022"
#define INS_MON_ERROR "0023"
#define NO_TRAN_ORG "0030"

#define APPROVE_I 1     // 승인
#define DENY_I 2        // 취소
#define AUTODENY_I 8    // 망상취소
#define APPROVE_S "01"  // 승인
#define DENY_S "02"     // 취소
#define AUTODENY_S "08" // 망상취소

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

commTel reqStruct;
bizTel bizStruct;

int sToInt(char *orgData, int size);                                   // string to int(해당 사이즈까지 잘라준다)
long long sToLLong(char *orgData, int size);                           // string to llong(해당 사이즈까지 잘라준다)
int chkUnitNumeric(char *chkData, int size);                           // 개별 N체크
int isAlphaNumeric(char *chkData, int size);                           // 개별 AN, =체크
int chkNumerics(commTel chkStruct);                                    // 전체 N체크
void copyCommToBizTel(commTel srcStruct, bizTel *destStruct);          // 수신 N 타입 전문을 비지니스 구조체로 변환
void printStruct(bizTel printStruct);                                  // 정상 전문 출력
int cardNumChk(bizTel chkStruct);                                      // 카드번호 정합성 검사
int amtChk(bizTel chkStruct);                                          // 가격 관련 검사
void resetStruct();                                                    // 초기화
int getNowDate();                                                      // 날짜 얻는 함수 YYYYMMDD
int getNowTime();                                                      // 시간 얻는 함수 HHMMSS
void autoApprove(char *tempApproveNum, int *approveSeqNum); // 승인번호 채번 함수
void autoUnique(char *tempApproveNum, int *uniqueSeqNum); // 거래고유번호 채번 함수
void DbReleaseFunc();
int executeSqlQuery(char *sSqlBuff, int nCount);
void executeBigSqlQuery(char *sSqlBuff, char* nBigCount);
int tranInsertSqlQuery(char *TranUniqNum, char *TranDate, char *TermNum, char *TranNum, char *TranType, char *CardInfo, long long ApproveAmt, char *InstMon, char *ApproveNum, char *ResCode, char *ResMsg, char *TranOrgDate, char *Cancle, char *ApproveOrgNum);
int tranUpdateSqlQuery(char *TranType, char *TermNum, char *TranNum, char *TranDate, char *OrgTranDate, char *CardInfo, char *ApproveNum, char *Cancle);
void *handelClnt(void *arg);
void errorHandling(char *msg);

time_t rawTime;       // 현재 시간 받아오는 변수
struct tm *pTimeInfo; // 시간을 사람이 보기 쉽게 변환하는 구조체

int approveSeqNum = RE_ZERO; // 승인번호 시퀀스넘버
int uniqueSeqNum = RE_ZERO; // 거래고유번호 시퀀스넘버

char sTmpBuff[BUF_SIZE]; // 송신버퍼
char rTmpBuff[BUF_SIZE]; // 수신 버퍼

int clntCnt = RE_ZERO;        // 접속한 클라이언트 수
int clntSockThread[MAX_CLNT]; // 클라이언트 최대 256명
pthread_mutex_t mutx;         // mutex 선언 - 다중 스레드끼리 전역변수 사용시 데이터의 혼선 방지

int main(int argc, char *argv[])
{

    int servSock, clntSock;
    struct sockaddr_in servAddr, clntAddr;
    int clntAddrSize;
    pthread_t threadId; // thread 선언

    char sSqlBuff[512]; // sql 사용 버퍼
    char sID[62];
    char spwd[62];
    int nRetCode = SUCCESS;
    int option; // 소켓 옵션 설정을 위한 두 변수

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

    if (argc != 2) // 파일명 & port번호
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutx, NULL);            // 뮤텍스 만들기
    servSock = socket(PF_INET, SOCK_STREAM, 0); // socket()

    optlen = sizeof(option);
    option = 1;
    setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, (void *)&option, optlen); // SO_REUSEADDR 를 0에서 1로 변경

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
    while (1) // client의 접속 대기
    {
        clntAddrSize = sizeof(clntAddr);
        clntSock = accept(servSock, (struct sockaddr *)&clntAddr, &clntAddrSize);

        pthread_mutex_lock(&mutx);            // clntSockThread[], clntCnt 전역변수를 사용하기 위해 뮤텍스 잠금
        clntSockThread[clntCnt++] = clntSock; // 클라이언트 카운터 올리고, 소켓 배정 . 첫 번째 클라이언트라면, clntSockThread[0] 에 들어갈 것
        pthread_mutex_unlock(&mutx);          // 뮤텍스 잠금해제

        pthread_create(&threadId, NULL, handelClnt, (void *)&clntSock);
        pthread_detach(threadId); // 만약 해당 쓰레드가 NULL 값을 리턴했다면, 쓰레드 종료
        printf("Connected client IP: %s \n", inet_ntoa(clntAddr.sin_addr));
    }
    DbReleaseFunc();
    close(servSock); // ctrl + c 로 프로그램 종료 시, 서버 소켓 종료
    return 0;
}

void *handelClnt(void *arg)
{
    int clntSock = *((int *)arg); // 소켓 파일 디스크립터가 void 포인터로 들어왔으므로, int 로 형변환
    char errorCode[4 + 1];
    char errorMsg[64 + 1];
    char TranUniqNum[16 + 1];
    char tempApproveNum[15 + 1];
    char ApproveOrgNum[15 + 1];
    char sSqlBuff[512]; // sql 사용 버퍼
    char sqlBigAns[15+1];
    char sqlBigCode[15+1];
    int sqlCode = SUCCESS;
    int sqlCount = RE_ZERO;
    int nRetCode = RE_ZERO;
    int strLen = RE_ZERO;
    char Cancle[2 + 1];
    time_t startTime, currentTime; // 시간받기
    double elapsedTime;            // 지나간 시간 측정

    int nowDate;

    strcpy(Cancle, "");
    strcpy(ApproveOrgNum, "");

    resetStruct(); // 구조체 및 버퍼 초기화

    strLen = read(clntSock, rTmpBuff, sizeof(rTmpBuff));

    /* 공통 정합성 체크 모듈 */
    strcpy(errorCode, NO_ERROR);
    strcpy(errorMsg, "APPROVE OK");
    if (BUF_SIZE != strLen)
    {
        strcpy(errorCode, TEL_LEN_ERROR);
        strcpy(errorMsg, "TelLenError"); // 전문 길이 오류
        pthread_mutex_unlock(&mutx);
    }
    else // 전문 사이즈 체크 후 메인로직
    {
        pthread_mutex_lock(&mutx); // clntCnt, clntSockThread[] 사용 위해 뮤텍스 잠금
        printf("Request_From_Client : %s \n", rTmpBuff);

        memset(&reqStruct, MEM_ZERO, sizeof(reqStruct)); // 요청전문 받기 전 초기화
        memcpy(&reqStruct, rTmpBuff, sizeof(reqStruct)); // 전문 임시 버퍼에 한번에 복사.

        copyCommToBizTel(reqStruct, &bizStruct); // 전문 구조 변경

        nowDate = getNowDate();

        /*단말기 원장 체크 -> 함수화*/
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        sprintf(sSqlBuff, "SELECT count(*) FROM TBL_TERM WHERE TERM_NUM = %s  AND TERM_STATUS = '01'", bizStruct.termNum);
        sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));

        nRetCode = chkNumerics(reqStruct);
        if (FAIL == nRetCode) // reqStrunct 타입체크
        {
            strcpy(errorCode, TEL_LEN_ERROR);
            strcpy(errorMsg, "TelLenError");
        }
        else if (sToInt(bizStruct.tranDate, sizeof(bizStruct.tranDate)) > nowDate) // 거래일자 체크
        {
            strcpy(errorCode, TRAN_DATE_ERROR);
            strcpy(errorMsg, "tranDateError");
        }
        else if (sqlCode == FAIL || sqlCode == RE_ZERO) // 단말기 원장 체크
        {
            strcpy(errorCode, TERM_NUM_ERROR);
            strcpy(errorMsg, "TERM_NUM_ERROR");
        }
        else // 오류 없음
        {
            printStruct(bizStruct);
        }
    }

    // 공통 정합성에 통과하고, 승인 요청전문 이라면?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(APPROVE_S, bizStruct.tranType))
    {
        nRetCode = cardNumChk(bizStruct); // 카드정보 체크

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

        nRetCode = amtChk(bizStruct); // 승인 요청 금액 체크
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

    // 공통 정합성에 통과하고, 취소 요청전문 이라면?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(DENY_S, bizStruct.tranType))
    {

        /*거래원장 체크 -> 함수화*/
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
            // 성공하면 원거래에서 승인금액, 할부개월수 가져와서 데이터 입력하기
            }
            else
            {
            sprintf(sSqlBuff, "SELECT APPROVE_AMT  FROM TBL_TLF_BATCH WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            bizStruct.approveAmt = sqlCode;
            sprintf(sSqlBuff, "SELECT INST_MON  FROM TBL_TLF_BATCH WHERE TERM_NUM = '%s'  AND TRAN_DATE = '%s' AND CARD_INFO = '%s' AND APPROVE_NUM = '%s'", bizStruct.termNum, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum);
            sqlCode = executeSqlQuery(sSqlBuff, sqlCount);
            sprintf(bizStruct.instMon, "%02d", sqlCode);
            // 성공하면 원거래에서 승인금액, 할부개월수 가져와서 데이터 입력하기
            }
        }
    }

    // 공통정합성 통과, 망상취소 전문이라면?
    if (SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(AUTODENY_S, bizStruct.tranType))
    {
        /*거래원장 체크 -> 함수화*/
        strcpy(Cancle, "R");
        
        /*원승인번호 체크*/
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

		if(SUCCESS == strcmp(APPROVE_S, bizStruct.tranType)) //승인전문이라면?
		{
		 autoApprove(tempApproveNum, &approveSeqNum); // 에러가 하나도 없으면 소켓별 승인번호 채번
        strcpy(bizStruct.approveNum, tempApproveNum);
		}
		else //취소, 망상취소일 경우는 원승인번호를 따라가야 하니
		{
			strcpy(tempApproveNum, ApproveOrgNum);
		}


		 autoUnique(TranUniqNum, &uniqueSeqNum); // 거래 고유번호 채번

        sprintf(bizStruct.resCode, errorCode);
        sprintf(bizStruct.resMsg, errorMsg);

        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, tempApproveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
        // 거래내역에 집어넣어야한다.

        nRetCode = sprintf(sTmpBuff, "%8s%10s%8s%2s%-37s%010lld%2s%-15s%-4s%-64s%08s", bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, &bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, &bizStruct.approveNum, &bizStruct.resCode, &bizStruct.resMsg, bizStruct.tranOrgDate);

		 //write를 하지 않음으로 자체 망취소 및 client의 망상취소를 유도!
        //nRetCode = write(clntSock, sTmpBuff, sizeof(sTmpBuff));
       // sleep(6);
    	 nRetCode = -1;
    }
    else // 에러가 있으면
    {
        autoUnique(TranUniqNum, &uniqueSeqNum); // 거래 고유번호 채번
        printf("Error Occ : %s %s\n", errorCode, errorMsg);

        sprintf(bizStruct.resCode, errorCode);
        sprintf(bizStruct.resMsg, errorMsg);

        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, bizStruct.approveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
        // 거래내역에 집어넣어야한다.
        nRetCode = sprintf(sTmpBuff, "%8s%10s%8s%2s%-37s%010lld%2s%-15s%-4s%-64s%08s", bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, &bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, &bizStruct.approveNum, &bizStruct.resCode, &bizStruct.resMsg, bizStruct.tranOrgDate);
        nRetCode = write(clntSock, sTmpBuff, sizeof(sTmpBuff));
    }
    
    // 클라이언트로 보내기 실패하였다면?, 승인 난 건이라면?, 승인 요청 거래라면?	
    if(nRetCode < 0 && SUCCESS == strcmp(NO_ERROR, errorCode) && SUCCESS == strcmp(APPROVE_S, bizStruct.tranType)) 
    {
    	 //자체 망취소 실시
        strcpy(Cancle, "R");
        strcpy(ApproveOrgNum, bizStruct.approveNum);
        strcpy(tempApproveNum, bizStruct.approveNum);

        sprintf(bizStruct.tranType,"08");

        autoUnique(TranUniqNum, &uniqueSeqNum); // 거래 고유번호 채번
    	
        //거래내역에 08번 취소전문 추가
        nRetCode = tranInsertSqlQuery(TranUniqNum, bizStruct.tranDate, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranType, bizStruct.cardInfo, bizStruct.approveAmt, bizStruct.instMon, tempApproveNum, bizStruct.resCode, bizStruct.resMsg, bizStruct.tranOrgDate, Cancle, ApproveOrgNum);
      
      	//망상취소로 원거래 update
        sqlCode = tranUpdateSqlQuery(bizStruct.tranType, bizStruct.termNum, bizStruct.tranNum, bizStruct.tranDate, bizStruct.tranOrgDate, bizStruct.cardInfo, bizStruct.approveNum, Cancle);
        memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
        
        printf("Send To Client Fail! Self 'R' Cancle Success. \n");
    }

    pthread_mutex_unlock(&mutx);

    resetStruct(); // 구조체 및 버퍼 초기화
    
    pthread_mutex_lock(&mutx);
    int i = RE_ZERO;
    
    for (i; i < clntCnt; i++) // 연결 끊어진 클라이언트인 "현재 쓰레드에서 담당하는 소켓" 삭제
    {
            // 현재 담당하는 클라이언트 소켓의 파일 디스크립터 위치를 찾으면,
            if (clntSock == clntSockThread[i])
            {
                // 현재 소켓이 원래 위치했던 곳을 기준으로
                // 뒤의 클라이언트들을 땡겨옴
                while (i++ < clntCnt - 1) // 쓰레드 1개 삭제할 것이기 때문에 -1 해줘야 함
                {
                    clntSockThread[i] = clntSockThread[i + 1];
                }
                break;
            }
    }

    clntCnt--;                   // 클라이언트 수 하나 줄임
    pthread_mutex_unlock(&mutx); // 뮤텍스 잠금해제
    sleep(6);
    close(clntSock);             // 서버의 쓰레드에서 담당하는 클라이언트 소켓 종료
    return NULL;
}

void autoApprove(char *tempApproveNum, int *approveSeqNum)
{

    rawTime = time(NULL);            // 현재 시간 받기
    pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환
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

    rawTime = time(NULL);            // 현재 시간 받기
    pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환

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
/*bizTel -> 비지니스 로직 전문 구조체            */
/*bizTel 구조체의 승인용청금액 변수를             */
/* 정합성 검증                                  */
/*=========================================== */
int amtChk(bizTel chkStruct)
{
    int result = SUCCESS;

    /*승인 요청 금액*/
    if (MIN_AMT <= chkStruct.approveAmt && MAX_AMT >= chkStruct.approveAmt) // 승인요청금액이 1천~1억 이하
    {
        if (INS_AMT <= chkStruct.approveAmt) // 5만원 이상이면?
        {
            if (ZERO_INS > sToInt(chkStruct.instMon, sizeof(bizStruct.instMon)) || MAX_INS < sToInt(chkStruct.instMon, sizeof(bizStruct.instMon))) // 개월수가 0~12사이라면?
            {
                result = FAIL_S;
            }
        }
        else
        {
            if (sToInt(chkStruct.instMon, sizeof(bizStruct.instMon)) >= MIN_INS) // 할부개월수가 01 이하라면?
            {
                result = FAIL_S;
            }
        }
    }
    else // 요청금액 오류
    {
        result = FAIL;
    }
    return result;
}

/*=========================================== */
/*cardNumChk                                    */
/*bizTel -> 비지니스 로직 전문 구조체            */
/*bizTel 구조체의 카드 정보 변수를               */
/*'=' 구분으로 나누어 각각 요소에 대한 정합성 검증 */
/*=========================================== */

int cardNumChk(bizTel chkStruct)
{
    /* 카드 */
    char cardFInfo[CARD_FRONT_SIZE + 1];
    char cardBInfo[CARD_BACK_SIZE + 1];
    char cardExpInfo[CARD_EXP_SIZE + 1];
    char cardBinNum[CARD_BIN_SIZE + 1];
    char cardBinNumSix[CARD_BIN_SIZE + 1 - 2];
    char *sPoint;
    char sWork[BUF_SIZE];
    int result = SUCCESS;
    char sSqlBuff[512]; // sql 사용 버퍼
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

    memcpy(sWork, chkStruct.cardInfo, sizeof(sWork)); // sWork에 카드정보 받아오기
    sPoint = strtok(sWork, "=");                      // sWork를 =으로 잘라 sPoint에 저장

    if (16 > strlen(sPoint) || 16 < strlen(sPoint)) // 카드번호 16자리
    {
        result = FAIL;
    }

    if (FAIL != result) // 카드번호 앞자리가 16자리가 맞으면?
    {
        memcpy(cardFInfo, sPoint, CARD_FRONT_SIZE); // sPoint를 16으로 잘라 cardFInfo에 저장
        sPoint = strtok(NULL, "=");                 //=이후 나머지 값을 sPoint에 저장

        memcpy(sWork, sPoint, strlen(sPoint)); // sWork에 나머지 값 저장
        sWork[CARD_BACK_SIZE] = MEM_ZERO;      // 저장한 나머지 값을 크기에 맞게 조절

        memcpy(cardBInfo, sWork, CARD_BACK_SIZE); // cardBInfo에 나머지 값 저장

        cardBInfo[CARD_BACK_SIZE] = MEM_ZERO; // 널 값 추가

        memcpy(cardExpInfo, sWork, CARD_EXP_SIZE); // cardExpInfo에 유효기간 저장
        cardExpInfo[CARD_EXP_SIZE] = MEM_ZERO;     // 널 값 추가

        memcpy(cardBinNum, cardFInfo, CARD_BIN_SIZE); // 빈정보 저장
        cardBinNum[CARD_BIN_SIZE] = MEM_ZERO;         // 널 값 추가

        memcpy(cardBinNumSix, cardFInfo, CARD_BIN_SIZE - 2); // 빈정보 저장
        cardBinNumSix[CARD_BIN_SIZE - 2] = MEM_ZERO;         // 널 값 추가

        if (FAIL == chkUnitNumeric(cardFInfo, sizeof(cardFInfo) - 1) || FAIL == chkUnitNumeric(cardBInfo, sizeof(cardBInfo) - 1))
        {
            result = FAIL;
            printf("card is not num \n");
        }
        /*카드 앞번호*/
        if (SUCCESS != strncmp("9", cardFInfo, 1))
        {
            printf("card Front is not 9 \n");
            result = FAIL;
        }

        /*카드 빈 체크*/
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

        rawTime = time(NULL);            // 현재 시간 받기
        pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환

        rawTime = time(NULL);            // 현재 시간 받기
        pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환
        sprintf(syymm, "%02d%02d", pTimeInfo->tm_year - 100, pTimeInfo->tm_mon + 1);

        sprintf(sCardExpInfo, cardExpInfo, sizeof(sCardExpInfo));

        iyymm = sToInt(syymm, sizeof(syymm));
        iCardExpInfo = sToInt(sCardExpInfo, sizeof(sCardExpInfo));

        /*유효기간*/
        if (iCardExpInfo < iyymm)
        {
            result = FAIL_S;
        }
    }
    return result;
}

int getNowDate()
{ // 자동채번 함수
    char yyyymmdd[8];
    rawTime = time(NULL);            // 현재 시간 받기
    pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환
    sprintf(yyyymmdd, "%04d%02d%02d", pTimeInfo->tm_year + 1900, pTimeInfo->tm_mon + 1, pTimeInfo->tm_mday);
    return atoi(yyyymmdd); // 거래일자 자동채번
}

int getNowTime()
{ // 자동채번 함수
    char hhmmss[6];
    rawTime = time(NULL);            // 현재 시간 받기
    pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환
    sprintf(hhmmss, "%02d%02d%02d", pTimeInfo->tm_hour, pTimeInfo->tm_min, pTimeInfo->tm_sec);
    return atoi(hhmmss); // 거래일자 자동채번
}
// -> 날짜, 시간 한번에 불러와서 잘라쓰는거 생각

/*=========================================== */
/*copyCommToBizTel                             */
/*commTel -> 최초로 받은 전문 구조체,           */
/*bizTel -> 비지니스 로직 전문 구조체              */
/*bizTel 구조체의 N타입 변수들에                */
/*commTel 변수들의 값을 복사 한다.              */
/*=========================================== */

void copyCommToBizTel(commTel srcStruct, bizTel *destStruct)
{
    memset(destStruct, MEM_ZERO, sizeof(struct bizTelegram)); // 비지니스 전문 카피 전 초기화

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
/*commTel 구조체를 입력받는다.                  */
/*해당 구조체의 변수들이 N 타입인지 확인하고     */
/*N타입이라면 SUCCESS, 아니라면 FAIL을 반환한다.*/
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
/*String을 입력받는다.                         */
/*Integer 타입으로 변환한다.                    */
/*반환한다.                                     */
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
/*String 을 입력받는다.                       */
/*해당 String의 변수들이 N 타입인지 확인하고    */
/*N타입이라면 SUCCESS, 아니라면 FAIL을 반환한다.*/
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
            result = FAIL; // 숫자가 아닌 문자가 있으므로 int 배열이 아님
        }
    }
    return result;
}

/*=========================================== */
/*chkUnitAlphaNu                              */
/*String 을 입력받는다.                       */
/*해당 String의 변수들이 AN 타입인지 확인하고    */
/*AN타입이라면 SUCCESS, 아니라면 FAIL을 반환한다.*/
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
            result = FAIL; // 숫자, 문자 가 아닌 문자가 있으므로 int 배열이 아님
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

void resetStruct() // 구조체 초기화 함수
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
    { // 일반 취소시 UPDATE
        if (sToInt(OrgTranDate, sizeof(OrgTranDate)) == nowDate)
        { // 당일이면 온라인 UPDATE
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
        { // 당일 원거래가 아니면 온라인, 배치 업데이트

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
    else // 망상취소 시 UPDATE
    {
        if (sToInt(OrgTranDate, sizeof(OrgTranDate)) == nowDate)
        { // 당일이면 온라인 UPDATE
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
        { // 아니면 온라인, 배치 업데이트
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