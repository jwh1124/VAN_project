<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
	<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
		<%@ page import="java.util.List" %>
			<!DOCTYPE html>
			<html>

			<head>
				<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
				<meta charset="EUC-KR" />
				<title>단말기 페이지</title>
				<style>
					#searchForm table {
						width: 100%;
					}

					#searchForm th,
					#searchForm td {
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

					#searchResultTable th,
					#searchResultTable td {
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

					.close:hover,
					.close:focus {
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
						const termNumParam = getQueryParam('termNum');
						const bisNumParam = getQueryParam('bisNum');
						const termStatusParam = getQueryParam('termStatus');

						//각 input, select에 값을 지정한다.
						const inputTermElement = document.querySelector('input[name="termNum"]');
						const inputBisElement = document.querySelector('input[name="bisNum"]');
						const selectElement = document.querySelector('select[name="termStatus"]');


						if (termNumParam) {
							inputTermElement.value = termNumParam;
						}

						if (bisNumParam) {
							inputBisElement.value = bisNumParam;
						}

						if (termStatusParam) {
							selectElement.value = termStatusParam;
						}


					};
				</script>

				<h2>단말기 조회</h2>
				<input type="hidden" name="currentPage" value="1" />
				<form id="searchForm" action="searchTerminal.te" method="get">
					<table>
						<tr>
							<th>단말기 번호</th>
							<td><input type="text" name="termNum" minlength="10" maxlength="10" style="width: 120px" />
							</td>
							<th>사업자 번호</th>
							<td><input type="text" name="bisNum" minlength="10" maxlength="10" style="width: 120px" />
							</td>
							<td colspan="2"><input type="submit" value="조회" /></td>
						</tr>
						<tr>
							<th>단말기 상태</th>
							<td><select name="termStatus">
									<option value="">===전체===</option>
									<option value="01">정상</option>
									<option value="02">일시 정지</option>
									<option value="03">해지</option>
								</select></td>
						</tr>
					</table>
				</form>

				<div class="crud-bt-area">
					<div class="table2-area">
						<!-- 등록 버튼 -->
						<button class="bt-crud bt-crud-insert">등록</button>
						<button class="bt-crud bt-crud-update">수정</button>
						<button class="bt-crud bt-crud-delete">삭제</button>
					</div>
				</div>

				<!-- 조회결과 테이블 -->
				<table id="searchResultTable">
					<thead>
						<tr>
							<th>단말기 번호</th>
							<th>사업자 번호</th>
							<th>단말기 개통 일자</th>
							<th>단말기 해지 일자</th>
							<th>단말기 상태</th>
						</tr>
					</thead>
					<tbody id="table-body">
						<c:forEach var="t" items="${termList}">
							<tr>
								<td>${t.termNum}</td>
								<td>${t.bisNum}</td>
								<td>${t.termOpenDate}</td>
								<td>${t.termCloseDate}</td>
								<c:choose>
									<c:when test="${t.termStatus eq '01'}">
										<td>정상</td>
									</c:when>
									<c:when test="${t.termStatus eq '02'}">
										<td>일시 정지</td>
									</c:when>
									<c:otherwise>
										<td>해지</td>
									</c:otherwise>
								</c:choose>
							</tr>
						</c:forEach>
					</tbody>
				</table>

				<c:set var="t" value="${termList}" />

				<!------- 등록 모달 ------->
				<div id="insertTerm" class="modal" style="display: none">
					<div class="modal-content">
						<span class="close">&times;</span>
						<h2>단말기 등록</h2>
						<form id="insertForm" action="insertTerminal.te" method="post">
							<!-- 등록내용 -->
							<table>
								<tr>
									<th>ㆍ단말기 번호</th>
									<td><input type="text" id="termNum" minlength="10" maxlength="10" name="termNum"
											required /></td>
								</tr>
								<tr>
									<th>ㆍ사업자 번호</th>
									<td><input type="text" id="bisNum" minlength="10" maxlength="10" name="bisNum"
											required /></td>
								</tr>
								<tr>
									<th>ㆍ단말기 등록일자</th>
									<td><input type="date" id="termOpenDate" name="termOpenDate" style="width: 125px"
											placeholder="YYYY-MM-DD" required /></td>
								</tr>
								<tr>
									<th>ㆍ단말기 상태</th>
									<td><select id="termStatus" name="termStatus">
											<option value="01">정상</option>
											<option value="02">일시 정지</option>
											<option value="03">해지</option>
										</select></td>
								</tr>
							</table>
							<button class="submit_bt" type="submit">등록</button>
						</form>
					</div>
				</div>

				<!------- 수정 모달 ------->
				<div id="updateTerm" class="modal" style="display: none">
					<div class="modal-content2">
						<span class="close">&times;</span>
						<h2>단말기 수정</h2>
						<form id="updateForm" action="updateTerminal.te" method="post">
							<!-- 수정 내용 -->
							<table>
								<tr>
									<th>ㆍ단말기 번호</th>
									<td><input style="background-color: lightgray" type="text" id="updateTermNum"
											name="termNum" readonly required /></td>
								</tr>
								<tr>
									<th>ㆍ사업자 번호</th>
									<td><input type="text" id="updateBisNum" minlength="10" maxlength="10" name="bisNum"
											required /></td>
								</tr>
								<tr>
									<th>ㆍ단말기 등록일자</th>
									<td><input type="date" id="updateTermOpenDate" name="termOpenDate"
											style="width: 125px" placeholder="YYYY-MM-DD" required /></td>
								</tr>
								<tr>
									<th>ㆍ단말기 해지일자</th>
									<td><input type="date" id="updateTermCloseDate" name="termCloseDate"
											style="width: 125px" placeholder="YYYY-MM-DD" /></td>
								</tr>
								<tr>
									<th>ㆍ단말기 상태</th>
									<td><select id="updateTermStatus" name="termStatus">
											<option value="01">정상</option>
											<option value="02">일시 정지</option>
											<option value="03">해지</option>
										</select></td>
								</tr>
							</table>
							<button class="submit_bt" type="submit" onclick="return confirm('수정하시겠습니까?')">수정</button>
						</form>
					</div>
				</div>

				<script>
					$(document).ready(function () {

						// 등록 버튼 클릭 시 모달 열기
						$(".bt-crud-insert").click(function () {
							$("#insertTerm").css("display", "block");
						});

						// 수정 버튼 클릭 시 모달 열기
						$(".bt-crud-update").click(function () {
							var selectedRow = $("#table-body").find("tr.selected");

							if (selectedRow.length > 0) {
								// 선택된 행이 있을 경우 모달 열기
								var termNum = selectedRow.find("td:eq(0)").text();
								var bisNum = selectedRow.find("td:eq(1)").text();
								var termOpenDate = selectedRow.find("td:eq(2)").text();
								var termCloseDate = selectedRow.find("td:eq(3)").text();
								var termStatus = selectedRow.find("td:eq(4)").text();

								var openYear = termOpenDate.substring(0, 4);
								var openMonth = termOpenDate.substring(4, 6);
								var openDay = termOpenDate.substring(6, 8);
								// Date 객체 생성
								// 월은 0부터 시작하므로 1을 빼줍니다. (0 = 1월, 1 = 2월, ...)
								var openDateObj = openYear + "-" + openMonth + "-" + openDay;

								var closeYear = termCloseDate.substring(0, 4);
								var closeMonth = termCloseDate.substring(4, 6);
								var closeDay = termCloseDate.substring(6, 8);
								// Date 객체 생성
								// 월은 0부터 시작하므로 1을 빼줍니다. (0 = 1월, 1 = 2월, ...)
								var closeDateObj = closeYear + "-" + closeMonth + "-" + closeDay;

								// 모달에 선택된 행의 값 설정
								$("#updateTermNum").val(termNum);
								$("#updateBisNum").val(bisNum);
								$("#updateTermOpenDate").val(openDateObj);
								$("#updateTermCloseDate").val(closeDateObj);
								if (termStatus == "정상") {
									$("#updateTermStatus").val("01");
								} else if (termStatus == "일시 정지") {
									$("#updateTermStatus").val("02");
								} else {
									$("#updateTermStatus").val("03");
								}

								$("#updateTerm").css("display", "block");
							} else {
								alert("수정할 행을 선택해주세요.");
							}
						});

						//딜리트 모달
						$(".bt-crud-delete").click(function () {
							var selectedRow = $("#table-body").find("tr.selected");
							if (selectedRow.length > 0) {
								var termNum = selectedRow.find("td:eq(0)").text();

								var termDelete = confirm("삭제하시겠습니까?");

								if (termDelete) {
									$.ajax({
										url: "deleteTerminal.te",
										type: "POST",
										data: {
											termNum: termNum,
										},
										success: function (response) {
											alert("삭제되었습니다.");
											// 삭제한 행 제거
											selectedRow.remove();
										},
										error: function () {
											alert("삭제에 실패하였습니다.");
										},
									});
								}
							} else {
								alert("삭제할 행을 선택해주세요.");
							}
						});

						// 모달 닫기 버튼 클릭 시 모달 닫기
						$(".close").click(function () {
							$("#insertTerm").css("display", "none");
							$("#updateTerm").css("display", "none");
							resetModalInputs();
						});

						// 등록 폼 제출 시 AJAX 요청 수행
						$("#insertForm").submit(function (e) {
							e.preventDefault();

							$.ajax({
								url: $(this).attr("action"),
								type: $(this).attr("method"),
								data: $(this).serialize(),
								success: function (response) {
									$("#insertTerm").css("display", "none");
									alert("등록 되었습니다.");
								},
								error: function () {
									alert("등록 실패했습니다.");
								},
							});
						});

						// 수정 폼 제출 시 AJAX 요청 수행
						$("#updateForm").submit(function (e) {
							e.preventDefault();

							$.ajax({
								url: $(this).attr("action"),
								type: $(this).attr("method"),
								data: $(this).serialize(),
								success: function (response) {
									$("#updateTerm").css("display", "none");
									alert("수정 되었습니다.");
								},
								error: function () {
									alert("수정 실패했습니다.");
								},
							});
						});

						// 테이블 행 클릭 시 선택 효과
						$("#table-body").on("click", "tr", function () {
							$(this).toggleClass("selected").siblings().removeClass("selected");

							var trs = $(this).parent();
							trs.each(function (e) {
								var $this = $(this).children($("tr"));

								$this.each(function () {
									if ($(this).attr("class") == "selected") {
										$(this).children().css("background-color", "lightgray");
									} else {
										$(this).children().css("background-color", "#FAFAFA");
									}
								});
							});
						});

						// 해지일자 입력란과 단말기 상태 선택란 요소를 가져옵니다.
						const termOpenDateInput = document.getElementById('updateTermOpenDate');
						const termCloseDateInput = document.getElementById('updateTermCloseDate');
						const termStatusSelect = document.getElementById('updateTermStatus');

						// 해지일자 입력값이 변경될 때 이벤트 처리
						termCloseDateInput.addEventListener('change', function () {
							if (termCloseDateInput.value) {
								// 해지일자 입력값이 존재하면 단말기 상태를 '해지'로 설정합니다.
								termStatusSelect.value = '03';
							} else {
								// 해지일자 입력값이 없으면 단말기 상태를 '정상'으로 설정합니다.
								termStatusSelect.value = '01';
							}
						});

						// 단말기 상태 값이 변경될 때 이벤트 처리
						termStatusSelect.addEventListener('change', function () {
							if (termStatusSelect.value === '03') {
								// 단말기 상태가 '해지'인 경우 해지일자를 오늘 날짜로 설정합니다.
								const today = new Date().toISOString().split('T')[0];
								termCloseDateInput.value = today;
							} else {
								// 단말기 상태가 '해지'가 아닌 경우 해지일자를 비웁니다.
								termCloseDateInput.value = '';
							}
						});

						// 등록, 수정 날짜는 오늘 이전으로 설정하도록
						var now_utc = Date.now() // 지금 날짜를 밀리초로
						// getTimezoneOffset()은 현재 시간과의 차이를 분 단위로 반환
						var timeOff = new Date().getTimezoneOffset() * 60000; // 분단위를 밀리초로 변환
						// new Date(now_utc-timeOff).toISOString()은 '2022-05-11T18:09:38.134Z'를 반환
						var today = new Date(now_utc - timeOff).toISOString().split("T")[0];
						document.getElementById("termOpenDate").setAttribute("max", today);
						document.getElementById("updateTermOpenDate").setAttribute("max", today);
						document.getElementById("updateTermCloseDate").setAttribute("max", today);

						

						
						termOpenDateInput.addEventListener('input', function() {
							    var termStartDate = new Date(termOpenDateInput.value);
							    var termEndDate = new Date(termCloseDateInput.value);

							    if (termStartDate > termEndDate) {
							    	termOpenDateInput.value = termCloseDateInput.value;
							    }
							  });

						termCloseDateInput.addEventListener('input', function() {
							    var termStartDate = new Date(termOpenDateInput.value);
							    var termEndDate = new Date(termCloseDateInput.value);

							    if (termStartDate > termEndDate) {
							    	termCloseDateInput.value = termOpenDateInput.value;
							    }
							  });
						
						//모달 초기화
						function resetModalInputs() {
							$("#termNum").val("");
							$("#bisNum").val("");
							$("#termOpenDate").val("");
							$("#termCloseDate").val("");
							$("#updateTermNum").val("");
							$("#updateBisNum").val("");
							$("#updateTermOpenDate").val("");
							$("#updateTermCloseDate").val("");
						}
					});
				</script>

				<!-- 페이징을-->

				<div id="paging-tb-area" align="center">
						<c:set var="termVal" value="${param.termNum}" />
						<c:set var="bisVal" value="${param.bisNum}" />
						<c:set var="statusVal" value="${param.termStatus}" />
					<c:if test="${pi.currentPage ne 1 and pi.currentPage ne null}">
						<a
							href="searchTerminal.te?currentPage=${pi.currentPage - 1}&termNum=${termVal}&bisNum=${bisVal}&termStatus=${statusVal}">[이전]</a>
					</c:if>
					<c:forEach var="p" begin="${pi.startPage}" end="${pi.endPage}" step="1">
						<c:choose>
							<c:when test="${p eq pi.currentPage}">
								<b>[${p}]</b>
								<!-- 현재 페이지에 불 들어오게 표시 -->
							</c:when>
							<c:otherwise>
								<c:if test="${pi.currentPage ne null}">
									<a
										href="searchTerminal.te?currentPage=${p}&termNum=${termVal}&bisNum=${bisVal}&termStatus=${statusVal}">[${p}]</a>
								</c:if>
							</c:otherwise>
						</c:choose>
					</c:forEach>
					<c:if test="${pi.maxPage ne pi.currentPage}">
						<a
							href="searchTerminal.te?currentPage=${pi.currentPage + 1}&termNum=${termVal}&bisNum=${bisVal}&termStatus=${statusVal}">[다음]</a>
					</c:if>
				</div>
			</body>

			</html>