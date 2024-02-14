
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<%@ page import="java.util.List"%>
<!DOCTYPE html>
<html>

<head>
<script
	src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
<meta charset="EUC-KR" />
<title>거래내역 페이지</title>
<style>
#searchForm table {
	width: 100%;
}

#searchForm th, #searchForm td {
	padding: 10px;
	font-size: 16px;
}

#searchForm input[type="submit"] {
	padding: 10px 20px;
	font-size: 16px;
}

#searchResultTable {
	width: 100%;
	border-collapse: collapse;
}

#searchResultTable th, #searchResultTable td {
	padding: 10px;
	border: 1px solid #ccc;
	font-size: 16px;
}

#insertTable {
	text-align: center;
}

#selectTable {
	text-align: center;
}

#selectTable td {
	width: 100px;
}

#paging-tb-area {
	margin-top: 20px;
}

#paging-tb-area a {
	display: inline-block;
	padding: 5px 10px;
	margin-right: 5px;
	border: 1px solid #ccc;
	text-decoration: none;
	color: #333;
}

#paging-tb-area b {
	display: inline-block;
	padding: 5px 10px;
	margin-right: 5px;
	border: 1px solid #ff2600;
	text-decoration: none;
	color: #333;
}

select {
	background-color: #ffffff;
	color: #000000;
	width: 130px;
}

/* 드롭다운 목록의 배경색과 테두리 스타일 변경 */
select option {
	background-color: #ffffff;
	border: 1px solid #ccc;
}

/*---------- CRUD style START ----------*/
.crud-bt-area {
	display: flex;
	justify-content: flex-end;
	align-items: center;
}

.bt-crud {
	width: 80px;
	height: 30px;
	background-color: #e0e0e0;
	margin-right: 0;
	/* 기존의 margin-left를 margin-right로 변경 */
}

.table2-area {
	width: auto;
	height: 50px;
	margin-left: auto;
	margin-top: 30px;
}

.bt-crud:hover {
	background-color: #bdbdbd;
}

/*---------모달 스타일 -------------*/
.modal {
	display: none;
	position: fixed;
	z-index: 9999;
	left: 0;
	top: 0;
	width: 100%;
	height: 100%;
	overflow: auto;
	background-color: rgba(0, 0, 0, 0.5);
}

.modal-content {
	background-color: #fff;
	margin: 10% auto;
	padding: 20px;
	border: 1px solid #888;
	width: 350px;
	height: 330px;
}

.modal-content table {
	border-spacing: 10px;
}

.modal-content th {
	text-align: left;
}

.modal-content2 {
	background-color: #fff;
	margin: 10% auto;
	padding: 20px;
	border: 1px solid #888;
	width: 350px;
	height: 380px;
}

.modal-content2 table {
	border-spacing: 10px;
}

.modal-content2 th {
	text-align: left;
}

.close {
	color: #888;
	float: right;
	font-size: 28px;
	font-weight: bold;
}

.close:hover, .close:focus {
	color: #000;
	text-decoration: none;
	cursor: pointer;
}

.submit_bt {
	margin-left: 130px;
	margin-top: 30px;
	width: 80px;
	height: 30px;
	background-color: #e0e0e0;
}
</style>
</head>

<body>
	<jsp:include page="./menu/menu.jsp" />
				<script>
					// URL에서 파라미터 값을 가져오는 함수
					function getQueryParam(param) {
						const urlParams = new URLSearchParams(window.location.search);
						return urlParams.get(param);
					}

					//온로드 되었을 떄?
					window.onload = function () {

						//url 파라미터에 해당 이름들이 잇으면 변수에 저장한다.
						const tranStartDateParam = getQueryParam('tranStartDate');
						const tranEndDateParam = getQueryParam('tranEndDate');
						const tranStartAmtParam = getQueryParam('tranStartAmt');
						const tranEndAmtParam = getQueryParam('tranEndAmt');
						const resCodeParam = getQueryParam('resCode');
						const tranNumParam = getQueryParam('tranNum');
						const termNumParam = getQueryParam('termNum');
						const cardNumParam = getQueryParam('cardNum');

						//각 input, select에 값을 지정한다.
						const inputTranStartDateElement = document.querySelector('input[name="tranStartDate"]');
						const inputTranEndDateElement = document.querySelector('input[name="tranEndDate"]');
						const inputTranStartAmtElement = document.querySelector('input[name="tranStartAmt"]');
						const inputTranEndAmtElement = document.querySelector('input[name="tranEndAmt"]');
						const inputTranNumElement = document.querySelector('input[name="tranNum"]');
						const selectElement = document.querySelector('select[name="resCode"]');
						const inputTermNumElement = document.querySelector('input[name="termNum"]');
						const inputCardNumElement = document.querySelector('input[name="cardNum"]');


						if (tranStartDateParam) {
							inputTranStartDateElement.value = tranStartDateParam;
						}

						if (tranEndDateParam) {
							inputTranEndDateElement.value = tranEndDateParam;
						}

						if (tranStartAmtParam) {
							inputTranStartAmtElement.value = tranStartAmtParam;
						}
						if (tranEndAmtParam) {
							inputTranEndAmtElement.value = tranEndAmtParam;
						}
						if (resCodeParam) {
							selectElement.value = resCodeParam;
						}

						if (tranNumParam) {
							inputTranNumElement.value = tranNumParam;
						}
						if (termNumParam) {
							inputTermNumElement.value = termNumParam;
						}

						if (cardNumParam) {
							inputCardNumElement.value = cardNumParam;
						}

					};
				</script>

	<h2>거래내역 조회</h2>
	<input type="hidden" name="currentPage" value="1" />
	<form id="searchForm" action="searchTran.tr" method="get">
		<table>
			<tr>
				<th>거래 일자</th>
				<td><input type="date" id="tranStartDate" name="tranStartDate"
					style="width: 125px" placeholder="YYYY-MM-DD" required /> ~ <input
					type="date" id="tranEndDate" name="tranEndDate"
					style="width: 125px" placeholder="YYYY-MM-DD" required /></td>
				<th>거래 금액</th>
				<td><input type="text" name="tranStartAmt" minlength="4"
					maxlength="10" style="width: 120px" value="1000" /> ~ 
					<input type="text" name="tranEndAmt" minlength="4"
					maxlength="10" style="width: 120px" value="1000000000" />
				<td colspan="2"><input type="submit" value="조회" /></td>
			</tr>
			<tr>
				<th>카드 번호</th>
				<td><input type="text" name="cardNum" minlength="16"
					maxlength="16" style="width: 120px" /></td>
				<th>응답 코드</th>
				<td><select name="resCode">
						<option value="">===전체===</option>
						<option value="0000">0000 : 정상승인</option>
						<option value="0001">0001 : 전문길이 오류</option>
						<option value="0020">0020 : 카드번호 오류</option>
						<option value="0021">0021 : 카드유효기간 오류</option>
						<option value="0022">0022 : 승인요청금액 오류</option>
						<option value="0023">0023 : 할부개월수 오류</option>
						<option value="0030">0030 : 원거래없음 오류</option>
				</select></td>
			</tr>
			<tr>
				<th>단말기 번호</th>
				<td><input type="text" name="termNum" minlength="10"
					maxlength="10" style="width: 120px" /></td>
				<th>거래 일련번호</th>
				<td><input type="text" name="tranNum" minlength="8"
					maxlength="10" style="width: 120px" /></td>
			</tr>
		</table>
	</form>

	<!-- 조회결과 테이블 -->
	<table id="searchResultTable">
		<thead>
			<tr>
				<th>거래 고유번호</th>
				<th>거래 일자</th>
				<th>단말기 번호</th>
				<th>거래일련번호</th>
				<th>거래 종류</th>
				<th>카드 번호</th>
				<th>요청 금액</th>
				<th>할부 개월수</th>
				<th>승인 번호</th>
				<th>응답 코드</th>
				<th>응답 메세지</th>
				<th>원 거래 일자</th>
				<th>취소 구분</th>
				<th>원 승인번호</th>
			</tr>
		</thead>
		<tbody id="table-body">
			<c:forEach var="tr" items="${tranList}">
				<tr>
					<td>${tr.tranUniqNum}</td>
					<td>${tr.tranDate}</td>
					<td>${tr.termNum}</td>
					<td>${tr.tranNum}</td>
					<td>${tr.tranType}</td>
					<c:set var="cardNumber"
						value="${fn:substringBefore(tr.cardInfo, '=')}" />
					<td><c:out value="${cardNumber}" /></td>
					<td>${tr.approveAmt}</td>
					<td>${tr.instMon}</td>
					<td>${tr.approveNum}</td>
					<td>${tr.resCode}</td>
					<td>${tr.resMsg}</td>
					<td>${tr.tranOrgDate}</td>
					<td>${tr.cancle}</td>
					<td>${tr.approveOrgNum}</td>
				</tr>
			</c:forEach>
		</tbody>
	</table>
	<script>
// 시작, 끝 날짜는 오늘 이전으로 설정하도록
var now_utc = Date.now() // 지금 날짜를 밀리초로
// getTimezoneOffset()은 현재 시간과의 차이를 분 단위로 반환
var timeOff = new Date().getTimezoneOffset() * 60000; // 분단위를 밀리초로 변환
// new Date(now_utc-timeOff).toISOString()은 '2022-05-11T18:09:38.134Z'를 반환
var today = new Date(now_utc - timeOff).toISOString().split("T")[0];

  var tranStartAmtInput = document.querySelector('input[name="tranStartAmt"]');
  var tranEndAmtInput = document.querySelector('input[name="tranEndAmt"]');
  var tranStartDateInput = document.querySelector('input[name="tranStartDate"]');
  var tranEndDateInput = document.querySelector('input[name="tranEndDate"]');
  
	document.getElementById("tranStartDate").setAttribute("max", today);
	document.getElementById("tranEndDate").setAttribute("max", today);
	document.getElementById("tranStartDate").setAttribute("dafault", today);
	document.getElementById("tranEndDate").setAttribute("dafault", today);
  
	tranStartAmtInput.addEventListener('input', function() {
    var tranStartAmt = parseInt(tranStartAmtInput.value);
    var tranEndAmt = parseInt(tranEndAmtInput.value);

    if (tranStartAmt > tranEndAmt) {
      tranStartAmtInput.value = tranEndAmt;
    }
  });

  tranEndAmtInput.addEventListener('input', function() {
    var tranStartAmt = parseInt(tranStartAmtInput.value);
    var tranEndAmt = parseInt(tranEndAmtInput.value);

    if (tranStartAmt > tranEndAmt) {
      tranEndAmtInput.value = tranStartAmt;
    }
  });
  
  tranStartDateInput.addEventListener('input', function() {
	    var tranStartDate = new Date(tranStartDateInput.value);
	    var tranEndDate = new Date(tranEndDateInput.value);

	    if (tranStartDate > tranEndDate) {
	      tranStartDateInput.value = tranEndDateInput.value;
	    }
	  });

	  tranEndDateInput.addEventListener('input', function() {
	    var tranStartDate = new Date(tranStartDateInput.value);
	    var tranEndDate = new Date(tranEndDateInput.value);

	    if (tranStartDate > tranEndDate) {
	      tranEndDateInput.value = tranStartDateInput.value;
	    }
	  });
  
  
</script>
	<!-- 페이징을-->

	<div id="paging-tb-area" align="center">
		<c:set var="tranStartDateVal" value="${param.tranStartDate}" />
		<c:set var="tranEndDateVal" value="${param.tranEndDate}" />
		<c:set var="tranStartAmtVal" value="${param.tranStartAmt}" />
		<c:set var="tranEndAmtVal" value="${param.tranEndAmt}" />
		<c:set var="cardNumVal" value="${param.cardNum}" />
		<c:set var="resCodeVal" value="${param.resCode}" />
		<c:set var="termNumVal" value="${param.termNum}" />
		<c:set var="tranNumVal" value="${param.tranNum}" />
		<c:if test="${pi.currentPage ne 1 and pi.currentPage ne null}">
			<a
				href="searchTran.tr?currentPage=${pi.currentPage - 1}&tranStartDate=${tranStartDateVal}&tranEndDate=${tranEndDateVal}&tranStartAmt=${tranStartAmtVal}&tranEndAmt=${tranEndAmtVal}&cardNum=${cardNumVal}&resCode=${resCodeVal}&termNum=${termNumVal}&tranNum=${tranNumVal}">[이전]</a>
		</c:if>
		<c:forEach var="p" begin="${pi.startPage}" end="${pi.endPage}"
			step="1">
			<c:choose>
				<c:when test="${p eq pi.currentPage}">
					<b>[${p}]</b>
					<!-- 현재 페이지에 불 들어오게 표시 -->
				</c:when>
				<c:otherwise>
					<c:if test="${pi.currentPage ne null}">
						<a
							href="searchTran.tr?currentPage=${p}&tranStartDate=${tranStartDateVal}&tranEndDate=${tranEndDateVal}&tranStartAmt=${tranStartAmtVal}&tranEndAmt=${tranEndAmtVal}&cardNum=${cardNumVal}&resCode=${resCodeVal}&termNum=${termNumVal}&tranNum=${tranNumVal}">[${p}]</a>
					</c:if>
				</c:otherwise>
			</c:choose>
		</c:forEach>
		<c:if test="${pi.maxPage ne pi.currentPage}">
			<a
				href="searchTran.tr?currentPage=${pi.currentPage + 1}&tranStartDate=${tranStartDateVal}&tranEndDate=${tranEndDateVal}&tranStartAmt=${tranStartAmtVal}&tranEndAmt=${tranEndAmtVal}&cardNum=${cardNumVal}&resCode=${resCodeVal}&termNum=${termNumVal}&tranNum=${tranNumVal}">[다음]</a>
		</c:if>
	</div>
</body>

</html>