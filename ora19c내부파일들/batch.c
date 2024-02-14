
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
           char  filnam[9];
};
static struct sqlcxp sqlfpn =
{
    8,
    "batch.pc"
};


static unsigned int sqlctx = 17355;


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
5,0,0,0,0,0,27,71,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,17,94,0,0,1,1,0,1,0,1,97,0,0,
55,0,0,2,0,0,45,110,0,0,1,1,0,1,0,1,97,0,0,
74,0,0,2,0,0,13,121,0,0,14,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
145,0,0,2,0,0,15,156,0,0,0,0,0,1,0,
160,0,0,3,0,0,17,177,0,0,1,1,0,1,0,1,97,0,0,
179,0,0,3,0,0,21,185,0,0,14,14,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
250,0,0,4,0,0,31,198,0,0,0,0,0,1,0,
265,0,0,5,0,0,29,203,0,0,0,0,0,1,0,
280,0,0,6,0,0,30,210,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>

#define SUCCESS 0	  // SUCCESS 상수
#define FAIL -1		  // FAIL 상수
#define MEM_ZERO 0x00 // memset 초기화 상수
#define RE_ZERO 0

typedef struct sqlTelegram // 전문 구조체 선언
{
	char tranUniqNum[16 + 1];	// 거래 고유번호
	char tranDate[8 + 1];		// 거래일자 8 N
	char termNum[10 + 1];		// 단말기번호 10 N
	char tranNum[8 + 1];		// 거래 일련번호 8 N
	char tranType[2 + 1];		// 거래종류 2 N
	char cardInfo[37 + 1];		// 카드정보 A
	char approveAmt[10 + 1];	// 승인요청금액 10N
	char instMon[2 + 1];		// 할부 개월수 2 N
	char approveNum[15 + 1];	// 승인번호 AN
	char resCode[4 + 1];		// 응답 코드 AN
	char resMsg[64 + 1];		// 응답 메세지 AN
	char tranOrgDate[8 + 1];	// 원거래 일자 AN
	char cancle[2 + 1];			// 취소구분
	char approveOrgNum[15 + 1]; // 원승인번호
} sqlTel;

sqlTel sqlStruct;

int tranInsertSqlQuery(char *TranUniqNum, char *TranDate, char *TermNum, char *TranNum, char *TranType,
					   char *CardInfo, char *ApproveAmt, char *InstMon, char *ApproveNum, char *ResCode,
					   char *ResMsg, char *TranOrgDate, char *Cancle, char *ApproveOrgNum);
void DbReleaseFunc();
void resetStruct();

time_t rawTime;		  // 현재 시간 받아오는 변수
struct tm *pTimeInfo; // 시간을 사람이 보기 쉽게 변환하는 구조체

int main(int argc, char *argv[])
{
	char sSqlBuff[512];
	char sID[62];
	char spwd[62];
	int nReadCnt;
	int nDupleCnt = RE_ZERO;
	int nRetCode = SUCCESS;
	char sHistTranDate[8 + 1];

	memset(sID, MEM_ZERO, sizeof(sID));
	memset(spwd, MEM_ZERO, sizeof(spwd));
	strcpy(sID, "twin");
	strcpy(spwd, "twin1234");
	memset(sSqlBuff, MEM_ZERO, sizeof(sSqlBuff));
	sprintf(sSqlBuff, "%s/%s", sID, spwd);

	if (argc != 2) // 파일명 & port번호
	{
		printf("Usage : %s <DATE>\n", argv[0]);
		exit(1);
	}

	resetStruct();

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

	memset(sHistTranDate, MEM_ZERO, sizeof(sHistTranDate));
	strcpy(sHistTranDate, argv[1]);

	rawTime = time(NULL);			 // 현재 시간 받기
	pTimeInfo = localtime(&rawTime); // 현재 시간 struct로 변환

	sprintf(sSqlBuff, "SELECT \n"
					  "TRAN_UNIQ_NUM, TRAN_DATE, TERM_NUM, TRAN_NUM, TRAN_TYPE, CARD_INFO, APPROVE_AMT, \n"
					  "INST_MON, APPROVE_NUM, RES_CODE, RES_MSG, TRAN_ORG_DATE, CANCLE, APPROVE_ORG_NUM \n"
					  "FROM TBL_TLF_ON WHERE TRAN_DATE = :sHistTranDate");

	/* EXEC SQL PREPARE SELECT_SMT FROM : sSqlBuff; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sSqlBuff;
 sqlstm.sqhstl[0] = (unsigned long )512;
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


	if (sqlca.sqlcode != 0)
	{
		printf("EXEC SQL PREPARE ERROR [%s] [%d] \n", sSqlBuff,
			   sqlca.sqlcode);
		return -1;
	}

	/* EXEC SQL DECLARE SELECT_CURSOR CURSOR FOR SELECT_SMT; */ 

	if (sqlca.sqlcode != 0)
	{
		printf("EXEC SQL DECLARE ERROR [%s] [%D] \n", sSqlBuff,
			   sqlca.sqlcode);
		return -1;
	}

	/* EXEC SQL OPEN SELECT_CURSOR USING : sHistTranDate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)sHistTranDate;
 sqlstm.sqhstl[0] = (unsigned long )9;
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


	if (sqlca.sqlcode != 0)
	{
		printf("EXEC SQL OPEN ERROR [%s] [%d] \n", sSqlBuff,
			   sqlca.sqlcode);
		return -1;
	}

	while (1)
	{

		/* EXEC SQL FETCH SELECT_CURSOR INTO : sqlStruct.tranUniqNum, : sqlStruct.tranDate, : sqlStruct.termNum, : sqlStruct.tranNum, : sqlStruct.tranType, : sqlStruct.cardInfo, : sqlStruct.approveAmt, : sqlStruct.instMon, : sqlStruct.approveNum, : sqlStruct.resCode, : sqlStruct.resMsg, : sqlStruct.tranOrgDate, : sqlStruct.cancle, : sqlStruct.approveOrgNum; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )74;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)(sqlStruct.tranUniqNum);
  sqlstm.sqhstl[0] = (unsigned long )17;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)(sqlStruct.tranDate);
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)(sqlStruct.termNum);
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(sqlStruct.tranNum);
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)(sqlStruct.tranType);
  sqlstm.sqhstl[4] = (unsigned long )3;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)(sqlStruct.cardInfo);
  sqlstm.sqhstl[5] = (unsigned long )38;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)(sqlStruct.approveAmt);
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)(sqlStruct.instMon);
  sqlstm.sqhstl[7] = (unsigned long )3;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)(sqlStruct.approveNum);
  sqlstm.sqhstl[8] = (unsigned long )16;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)(sqlStruct.resCode);
  sqlstm.sqhstl[9] = (unsigned long )5;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)(sqlStruct.resMsg);
  sqlstm.sqhstl[10] = (unsigned long )65;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)(sqlStruct.tranOrgDate);
  sqlstm.sqhstl[11] = (unsigned long )9;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(sqlStruct.cancle);
  sqlstm.sqhstl[12] = (unsigned long )3;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(sqlStruct.approveOrgNum);
  sqlstm.sqhstl[13] = (unsigned long )16;
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



		if (sqlca.sqlcode == 1403)
		{
			if (nReadCnt == 0)
			{
				printf("Don't Have Target Data\n");
			}
			nRetCode = 0;
			break;
		}

		nReadCnt = nReadCnt + 1;

		nRetCode = tranInsertSqlQuery(sqlStruct.tranUniqNum, sqlStruct.tranDate, sqlStruct.termNum,
									  sqlStruct.tranNum, sqlStruct.tranType, sqlStruct.cardInfo,
									  sqlStruct.approveAmt, sqlStruct.instMon, sqlStruct.approveNum,
									  sqlStruct.resCode, sqlStruct.resMsg, sqlStruct.tranOrgDate,
									  sqlStruct.cancle, sqlStruct.approveOrgNum);
		if (nRetCode != SUCCESS)
		{
			nDupleCnt = nDupleCnt + 1;
		}
	} /* end of while(1) */

	if (nReadCnt - nDupleCnt > 0)
	{
		printf("Batch Counts : ' %d ' SUCCESS\n", nReadCnt - nDupleCnt);
	}
	else
	{
		printf("Fail Counts : ' %d ' FAIL \n",nDupleCnt);
	}

	/*-- EXEC SQL DECLARE 구문에서 선언한 이름과 일치해야 함 --*/
	/* EXEC SQL CLOSE SELECT_CURSOR; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )145;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	DbReleaseFunc();

	return nRetCode;
}

int tranInsertSqlQuery(char *TranUniqNum, char *TranDate, char *TermNum, char *TranNum, char *TranType, char *CardInfo, char *ApproveAmt, char *InstMon, char *ApproveNum, char *ResCode, char *ResMsg, char *TranOrgDate, char *Cancle, char *ApproveOrgNum)
{

	char sTmpBuff[1024 + 1];
	int nRetCode;
	memset(sTmpBuff, MEM_ZERO, sizeof(sTmpBuff));

	sprintf(sTmpBuff, "INSERT INTO TBL_TLF_BATCH \n"
					  "(TRAN_UNIQ_NUM, TRAN_DATE, TERM_NUM, TRAN_NUM, TRAN_TYPE, CARD_INFO, APPROVE_AMT, \n"
					  "INST_MON, APPROVE_NUM, RES_CODE, RES_MSG, TRAN_ORG_DATE, CANCLE, APPROVE_ORG_NUM) \n"
					  " VALUES \n"
					  "(:TranUniqNum, : TranDate, :TermNum, :TranNum, :TranType, :CardInfo, \n"
					  " :ApproveAmt, :InstMon, :ApproveNum, :ResCode, :ResMsg, :TranOrgDate, :Cancle, :ApproveOrgNum)");

	/* EXEC SQL PREPARE insert_smt FROM : sTmpBuff; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )160;
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
 sqlstm.offset = (unsigned int  )179;
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
 sqlstm.sqhstv[6] = (unsigned char  *)ApproveAmt;
 sqlstm.sqhstl[6] = (unsigned long )0;
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
		if(sqlca.sqlcode == -1)
		{

		}
		else
		{
			printf("INSERT EXECUTE Error! [%d] \n", sqlca.sqlcode);
		}

		/* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )250;
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
  sqlstm.offset = (unsigned int  )265;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	}
	return nRetCode;
}

void DbReleaseFunc()
{
	/* EXEC SQL COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )280;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

void resetStruct() // 구조체 초기화 함수
{
	memset(sqlStruct.tranUniqNum, MEM_ZERO, sizeof(sqlStruct.tranUniqNum));
	memset(sqlStruct.tranDate, MEM_ZERO, sizeof(sqlStruct.tranDate));
	memset(sqlStruct.termNum, MEM_ZERO, sizeof(sqlStruct.termNum));
	memset(sqlStruct.tranNum, MEM_ZERO, sizeof(sqlStruct.tranNum));
	memset(sqlStruct.tranType, MEM_ZERO, sizeof(sqlStruct.tranType));
	memset(sqlStruct.cardInfo, MEM_ZERO, sizeof(sqlStruct.cardInfo));
	memset(sqlStruct.approveAmt, MEM_ZERO, sizeof(sqlStruct.approveAmt));
	memset(sqlStruct.instMon, MEM_ZERO, sizeof(sqlStruct.instMon));
	memset(sqlStruct.approveNum, MEM_ZERO, sizeof(sqlStruct.approveNum));
	memset(sqlStruct.resCode, MEM_ZERO, sizeof(sqlStruct.resCode));
	memset(sqlStruct.resMsg, MEM_ZERO, sizeof(sqlStruct.resMsg));
	memset(sqlStruct.tranOrgDate, MEM_ZERO, sizeof(sqlStruct.tranOrgDate));
	memset(sqlStruct.cancle, MEM_ZERO, sizeof(sqlStruct.cancle));
	memset(sqlStruct.approveOrgNum, MEM_ZERO, sizeof(sqlStruct.approveOrgNum));
}