<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
	<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
		<%@ page import="java.util.List" %>
			<!DOCTYPE html>
			<html>

			<head>
				<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.min.js"></script>
				<meta charset="EUC-KR" />
				<title>카드 BIN 페이지</title>
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
						const cardBinParam = getQueryParam('cardBin');
						const cardDifParam = getQueryParam('cardDif');
						const cardStatusParam = getQueryParam('cardStatus');

						//각 input, select에 값을 지정한다.
						const inputBinElement = document
							.querySelector('input[name="cardBin"]');
						const inputDifElement = document
							.querySelector('input[name="cardDif"]');
						const selectElement = document
							.querySelector('select[name="cardStatus"]');

						if (cardBinParam) {
							inputBinElement.value = cardBinParam;
						}

						if (cardDifParam) {
							inputDifElement.value = cardDifParam;
						}

						if (cardStatusParam) {
							selectElement.value = cardStatusParam;
						}

					};
				</script>
				<h2>카드 BIN 조회</h2>

				<input type="hidden" name="currentPage" value="1" />
				<form id="searchForm" action="searchCardBin.bi" method="get">
					<table>
						<tr>
							<th>카드 BIN 번호</th>
							<td><input type="text" name="cardBin" pattern="\d{6}|\d{8}" title="8자리 또는 10자리 숫자를 입력하세요."
									style="width: 120px" /></td>
							<th>카드사 코드</th>
							<td><input type="text" name="cardDif" minlength="3" maxlength="3" style="width: 120px" />
							</td>
							<td colspan="2"><input type="submit" value="조회" /></td>
						</tr>
						<tr>
							<th>BIN 상태</th>
							<td><select name="cardStatus">
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
							<th>카드 BIN 번호</th>
							<th>카드사 코드</th>
							<th>카드 상태</th>
						</tr>
					</thead>
					<tbody id="table-body">
						<c:forEach var="b" items="${binList}">
							<tr>
								<td>${b.cardBin}</td>
								<td>${b.cardDif}</td>
								<c:choose>
									<c:when test="${b.cardStatus eq '01'}">
										<td>정상</td>
									</c:when>
									<c:when test="${b.cardStatus eq '02'}">
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

				<c:set var="b" value="${binList}" />

				<!------- 등록 모달 ------->
				<div id="insertBin" class="modal" style="display: none">
					<div class="modal-content">
						<span class="close">&times;</span>
						<h2>BIN 등록</h2>
						<form id="insertForm" action="insertCardBin.bi" method="post">
							<!-- 등록내용 -->
							<table>
								<tr>
									<th>ㆍBIN 번호</th>
									<td><input type="text" id="cardBin" pattern="\d{6}|\d{8}"
											title="6자리 또는 8자리 숫자를 입력하세요." name="cardBin" required /></td>
								</tr>
								<tr>
									<th>ㆍ카드사 코드</th>
									<td><input type="text" id="cardDif" minlength="3" maxlength="3" name="cardDif"
											required /></td>
								</tr>
								<tr>
									<th>ㆍBIN 상태</th>
									<td><select id="cardStatus" name="cardStatus">
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
				<div id="updateBin" class="modal" style="display: none">
					<div class="modal-content2">
						<span class="close">&times;</span>
						<h2>BIN 수정</h2>
						<form id="updateForm" action="updateCardBin.bi" method="post">
							<!-- 수정 내용 -->
							<table>
								<tr>
									<th>ㆍBIN 번호</th>
									<td><input style="background-color: lightgray" type="text" id="updateCardBin"
											name="cardBin" readonly required /></td>
								</tr>
								<tr>
									<th>ㆍBIN 코드</th>
									<td><input type="text" id="updateCardDif" minlength="3" maxlength="3" name="cardDif"
											required /></td>
								</tr>
								<tr>
									<th>ㆍBIN 상태</th>
									<td><select id="updateCardStatus" name="cardStatus">
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
					$(document)
						.ready(
							function () {

								// 등록 버튼 클릭 시 모달 열기
								$(".bt-crud-insert").click(function () {
									$("#insertBin").css("display", "block");
								});

								// 수정 버튼 클릭 시 모달 열기
								$(".bt-crud-update").click(
									function () {
										var selectedRow = $("#table-body")
											.find("tr.selected");

										if (selectedRow.length > 0) {
											// 선택된 행이 있을 경우 모달 열기
											var cardBin = selectedRow.find(
												"td:eq(0)").text();
											var cardDif = selectedRow.find(
												"td:eq(1)").text();
											var cardStatus = selectedRow.find(
												"td:eq(2)").text();

											// 모달에 선택된 행의 값 설정
											$("#updateCardBin").val(cardBin);
											$("#updateCardDif").val(cardDif);
											if (cardStatus == "정상") {
												$("#updateCardStatus")
													.val("01");
											} else if (cardStatus == "일시 정지") {
												$("#updateCardStatus")
													.val("02");
											} else {
												$("#updateCardStatus")
													.val("03");
											}

											$("#updateBin").css("display",
												"block");
										} else {
											alert("수정할 행을 선택해주세요.");
										}
									});

								//딜리트 모달
								$(".bt-crud-delete")
									.click(
										function () {
											var selectedRow = $(
												"#table-body").find(
													"tr.selected");
											if (selectedRow.length > 0) {
												var cardBin = selectedRow
													.find("td:eq(0)")
													.text();

												var binDelete = confirm("삭제하시겠습니까?");

												if (binDelete) {
													$
														.ajax({
															url: "deleteCardBin.bi",
															type: "POST",
															data: {
																cardBin: cardBin,
															},
															success: function (
																response) {
																alert("삭제되었습니다.");
																// 삭제한 행 제거
																selectedRow
																	.remove();
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
									$("#insertBin").css("display", "none");
									$("#updateBin").css("display", "none");
									resetModalInputs();
								});

								// 등록 폼 제출 시 AJAX 요청 수행
								$("#insertForm").submit(
									function (e) {
										e.preventDefault();

										$.ajax({
											url: $(this).attr("action"),
											type: $(this).attr("method"),
											data: $(this).serialize(),
											success: function (response) {
												$("#insertBin").css("display",
													"none");
												alert("등록 되었습니다.");
											},
											error: function () {
												alert("등록 실패했습니다.");
											},
										});
									});

								// 수정 폼 제출 시 AJAX 요청 수행
								$("#updateForm").submit(
									function (e) {
										e.preventDefault();

										$.ajax({
											url: $(this).attr("action"),
											type: $(this).attr("method"),
											data: $(this).serialize(),
											success: function (response) {
												$("#updateBin").css(
													"display", "none");
												alert("수정 되었습니다.");
											},
											error: function () {
												alert("수정 실패했습니다.");
											},
										});
									});

								// 테이블 행 클릭 시 선택 효과
								$("#table-body")
									.on(
										"click",
										"tr",
										function () {
											$(this)
												.toggleClass("selected")
												.siblings()
												.removeClass("selected");

											var trs = $(this).parent();
											trs
												.each(function (e) {
													var $this = $(this)
														.children(
															$("tr"));

													$this
														.each(function () {
															if ($(
																this)
																.attr(
																	"class") == "selected") {
																$(
																	this)
																	.children()
																	.css(
																		"background-color",
																		"lightgray");
															} else {
																$(
																	this)
																	.children()
																	.css(
																		"background-color",
																		"#FAFAFA");
															}
														});
												});
										});

								//모달 초기화
								function resetModalInputs() {
									$("#cardBin").val("");
									$("#cardDif").val("");
									$("#updateCardBin").val("");
									$("#updateCardDif").val("");
								}
							});
				</script>

				<!-- 페이징을-->

				<div id="paging-tb-area" align="center">
						<c:set var="binVal" value="${param.cardBin}" />
						<c:set var="difVal" value="${param.cardDif}" />
						<c:set var="statusVal" value="${param.cardStatus}" />
					<c:if test="${pi.currentPage ne 1 and pi.currentPage ne null}">
						<a
							href="searchCardBin.bi?currentPage=${pi.currentPage - 1}&cardBin=${binVal}&cardDif=${difVal}&cardStatus=${statusVal}">[이전]</a>
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
										href="searchCardBin.bi?currentPage=${p}&cardBin=${binVal}&cardDif=${difVal}&cardStatus=${statusVal}">[${p}]</a>
								</c:if>
							</c:otherwise>
						</c:choose>
					</c:forEach>
					<c:if test="${pi.maxPage ne pi.currentPage}">
						<a
							href="searchCardBin.bi?currentPage=${pi.currentPage + 1}&cardBin=${binVal}&cardDif=${difVal}&cardStatus=${statusVal}">[다음]</a>
					</c:if>
				</div>
			</body>

			</html>