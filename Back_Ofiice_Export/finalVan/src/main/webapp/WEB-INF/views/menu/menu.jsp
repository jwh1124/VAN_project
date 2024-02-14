<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>메뉴바</title>
<style>
	#header {
	  background-color: rgba(138, 138, 138, 0.8); /* 흰색 배경, 약간 불투명 */
	  height: 120px;
	}
	
	#header ul {
	  list-style-type: none;
	  margin: 0;
	  padding: 0;
	  display: flex;
	  justify-content: center;
	  align-items: center;
	  height: 100%;
	}
	
	#header ul li {
	  margin: 0 40px; /* 클릭 메뉴 사이 간격을 더 널찍하게 조정 */
	}
	
	#header ul li a {
	  display: block;
	  color: #333;
	  text-decoration: none;
	  font-size: 30px;
	  font-weight: bold;
	  padding: 10px;
	  border-bottom: 2px solid transparent; /* 각 항목 구분을 위한 바 추가 */
	}
	
	#header ul li a:hover {
	  background-color: #555;
	  color: #ffffff; /* 마우스 호버 시 글자색 변경 */
	}
	
	#header ul li a.active {
	  background-color: #555;
	  color: #ffffff; /* 클릭한 메뉴의 스타일 변경 */
	  border-bottom-color: #ff0000; /* 클릭한 메뉴의 바 색상 변경 */
	}
	
	#header #logo {
	  color: #ffffff; /* 클릭한 메뉴의 스타일 변경 */
	  font-size: 20px;
	  font-weight: bold;
	  margin-right: 20px;
	}
	</style>
	</head>
	<body>
		<div id="header">
			<span id="logo">트인기술 VAN 시스템 백오피스</span>
			<ul>
				<li><a href="moveTerminal.te">단말기</a></li>
				<li><a href="moveBin.bi">카드BIN</a></li>
				<li><a href="moveTran.tr">거래내역</a></li>
			</ul>
		</div>
	</body>
	</html>