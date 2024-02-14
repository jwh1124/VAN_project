# VAN_PROJECT

## 온라인 프로세스 (ora19c 내부파일들)
Cent-OS 7 
리눅스 기반
client, server, batch 구현
Pro*C사용

## 백오피스 (Back_Office_Export)
STS 3 사용
My-batis 사용
jstl 사용

## DB (admin)
oracle 사용
리스너 셋팅 후 윈도우(client) <-> 리눅스(server)

## 흐름
백오피스에서 단말기, 카드 BIN 등록
- DB에 CURD
온라인 프로세스에서 단말기, 카드BIN에 위배되지 않는 거래 생성
- DB에 INSERT
온라인 프로세스 취소 시 원거래 있어야 취소 가능
- DB 체크
온라인 프로세스 TIMEOUT시 망상취소 실시
- 08전문 생성, 서버 자체취소 실시
백오피스에서 거래내역 조회 가능
- DB에서 조회
