SELECT count(*) FROM TBL_TERM WHERE TERM_NUM = 7000000001

SELECT * FROM TBL_TLF_ON order by TRAN_UNIQ_NUM desc

SELECT APPORVE_ORG_NUM FROM TBL_TLF_BATCH WHERE TRAN_ORG_DATE = %s AND TERM_NUM = %s AND CARD_INFO = %s AND TRAN_NUM = '05145936', TBL_TLF_BATCH, APPROVE_AMT AND TRAN_TYPE = '01'
TRUNCATE TABLE TBL_TLF_ON   
         
 SELECT * FROM TBL_TLF_BATCH order by TRAN_UNIQ_NUM desc
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020115371908'    
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020214325108'    
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020214591908'    
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020515323607'    
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020515323608'    
DELETE FROM TBL_TLF_BATCH WHERE TRAN_UNIQ_NUM = '2024020515413008'    

 DELETE FROM TBL_TLF_ON WHERE TRAN_DATE = '20240208'         
 DELETE FROM TBL_TLF_ON WHERE CANCLE = 'C'
DELETE FROM TBL_TLF_BATCH WHERE TRAN_DATE < '20240208'
commit       
ROLLBACK

APPROVE_AMT BETWEEN 1000 AND 1000000000
AND SUBSTR(CARD_INFO, 1, 16) = '9123456777777777'
order by TRAN_UNIQ_NUM;
     
INSERT INTO TBL_TLF_ON
(SELECT * FROM TBL_TLF_ON)
VALUES (SELECT * FROM TBL_TLF_BATCH)

TRUNCATE TABLE TBL_TLF_ON

DROP TABLE TBL_TLF_ON

SELECT * FROM TBL_TLF_BATCH
SELECT * FROM TBL_TLF_ON

COMMIT

ROLLBACK

CREATE TABLE TBL_TLF_ON
(
	TRAN_UNIQ_NUM VARCHAR2(16) NOT NULL,
	TRAN_DATE VARCHAR2(8) NOT NULL,
	TERM_NUM VARCHAR2(10) NOT NULL,
	TRAN_NUM VARCHAR2(8) NOT NULL,
	TRAN_TYPE VARCHAR2(2) NOT NULL,
	CARD_INFO VARCHAR2(37) NOT NULL,
	APPROVE_AMT NUMBER(10) NOT NULL,
	INST_MON VARCHAR2(2) NOT NULL,
	APPROVE_NUM	VARCHAR2(15),
	RES_CODE VARCHAR2(4),
	RES_MSG VARCHAR2(64),
	TRAN_ORG_DATE VARCHAR2(8),
	CANCLE VARCHAR2(2),
	APPROVE_ORG_NUM VARCHAR2(15),
	CONSTRAINT TBL_TLF_ON_PK PRIMARY KEY(TRAN_UNIQ_NUM)
);

ALTER TABLE TBL_TLF_ON ADD APPROVE_ORG_NUM VARCHAR2(15);

UPDATE TBL_TLF_ON SET CANCLE = '' WHERE TRAN_UNIQ_NUM = 2024011717415501

INSERT INTO TBL_TLF_ON
                      (TRAN_UNIQ_NUM, TRAN_DATE, TERM_NUM, TRAN_NUM, TRAN_TYPE, CARD_INFO,
                      APPROVE_AMT, INST_MON, APPROVE_NUM, RES_CODE, RES_MSG, TRAN_ORG_DATE, CANCLE)
                       VALUES
                      ('1234537387454421', 20240116, 7000000007, 16173502, 01, '9123456777777777=12340000000000000009',
                      100000, 12, '123456787654321', '','' ,20240116 ,'');

COMMIT

DROP TABLE TBL_TLF_BATCH

CREATE TABLE TBL_TLF_BATCH
(
	TRAN_UNIQ_NUM VARCHAR2(16) NOT NULL,
	TRAN_DATE VARCHAR2(8) NOT NULL,
	TERM_NUM VARCHAR2(10) NOT NULL,
	TRAN_NUM VARCHAR2(8) NOT NULL,
	TRAN_TYPE VARCHAR2(2) NOT NULL,
	CARD_INFO VARCHAR2(37) NOT NULL,
	APPROVE_AMT NUMBER(10) NOT NULL,
	INST_MON VARCHAR2(2) NOT NULL,
	APPROVE_NUM	VARCHAR2(15),
	RES_CODE VARCHAR2(4),
	RES_MSG VARCHAR2(64),
	TRAN_ORG_DATE VARCHAR2(8),
	CANCLE VARCHAR2(2),
	APPROVE_ORG_NUM VARCHAR2(15),
	CONSTRAINT TBL_TLF_BATCH_PK PRIMARY KEY(TRAN_UNIQ_NUM)
);
COMMIT
SELECT * FROM TBL_TLF_BATCH ORDER BY TRAN_UNIQ_NUM DESC
TRUNCATE TABLE TBL_TLF_BATCH

SELECT * FROM TBL_TLF_ON WHERE TRAN_DATE = '20240126'

SELECT APPROVE_AMT  FROM TBL_TLF_ON WHERE TERM_NUM = '7000000007'  AND TRAN_DATE = '20240126' AND CARD_INFO = '9123456777777777=24010000000000000009' AND APPROVE_NUM = '240126151514001'

SELECT *
FROM
(
SELECT/*+ INDEX_DESC(R P1) */
		R.TRAN_UNIQ_NUM
		,R.TRAN_DATE
		,R.TERM_NUM
		,R.TRAN_NUM
		,R.TRAN_TYPE
		,R.CARD_INFO
		,R.APPROVE_AMT
		,R.INST_MON
		,R.APPROVE_NUM
		,R.RES_CODE
		,R.RES_MSG
		,R.TRAN_ORG_DATE
		,R.CANCLE
		,R.APPROVE_ORG_NUM
		FROM
		TBL_TLF_ON R
		WHERE 1=1
		AND TRAN_DATE = '20240202'  
		UNION ALL  
		SELECT/*+ INDEX_DESC(B P1) */
		B.TRAN_UNIQ_NUM
		,B.TRAN_DATE
		,B.TERM_NUM
		,B.TRAN_NUM
		,B.TRAN_TYPE
		,B.CARD_INFO
		,B.APPROVE_AMT
		,B.INST_MON
		,B.APPROVE_NUM
		,B.RES_CODE
		,B.RES_MSG
		,B.TRAN_ORG_DATE
		,B.CANCLE
		,B.APPROVE_ORG_NUM
		FROM
		TBL_TLF_BATCH B
		WHERE 1=1
		AND B.TRAN_DATE BETWEEN '20240101' AND '20240201'     
)ORDER BY TRAN_UNIQ_NUM DESC

INSERT INTO TBL_TLF_BATCH
    (TRAN_DATE,
    TRAN_UNIQ_NUM,
    TERM_NUM,
    TRAN_NUM,
    TRAN_TYPE,
    CARD_INFO,
    APPROVE_AMT,
    INST_MON,
    APPROVE_NUM,
    RES_CODE,
    RES_MSG,
    TRAN_ORG_DATE)
SELECT
    C.TRAN_DATE AS TRAN_DATE,
    C.TRAN_DATE || '153012' || LPAD(RN, 2, '0'),
    '7000000007',
    D.TIME_VAL,
    '01',
    '9123456777777777=24010000000000000009',
    100 * TO_CHAR(TO_DATE(C.TRAN_DATE, 'YYYYMMDD'), 'DD'),
    '03',
    C.TRAN_DATE|| LPAD(RN, 2, '0'),
    '0000',
    'APPROVE OK',
    C.TRAN_DATE AS TRAN_DATE
FROM
    (SELECT A.*, ROWNUM AS RN FROM (SELECT * FROM TBL_BIZ_MST) A CROSS JOIN (SELECT LEVEL FROM DUAL CONNECT BY LEVEL <= 8) B) A,
    (SELECT TO_CHAR(TO_DATE('20220101', 'YYYYMMDD') + ROWNUM, 'YYYYMMDD') AS TRAN_DATE FROM DUAL CONNECT BY LEVEL <= 125) C,
    (SELECT TO_CHAR(TO_DATE('153035', 'HH24MISS') + ROWNUM * 1000000, 'HH24MISS') AS TIME_VAL FROM DUAL CONNECT BY LEVEL <= 125) D;




