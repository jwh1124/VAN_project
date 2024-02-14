package com.twin.van.page.temp;

import com.twin.van.page.vo.PageInfo;

public class Pagination {

	public static PageInfo getPageInfo(int listCount, int currentPage, int pageLimit, int vanLimit) {// 페이지인포를 만들어서 보낼꺼다
																										// // 이걸 쓸려면 변수
																										// 4개를 가져와야
																										// 사용가능하다???)
		// 전달 받을 값들

		int totalPages = (int) Math.ceil(((double) listCount / vanLimit));
		int startPage = (currentPage - 1) / pageLimit * pageLimit + 1;
		int endPage = startPage + pageLimit - 1;

		if (endPage > totalPages) {
			endPage = totalPages;
		}
		

		PageInfo pi = new PageInfo(listCount, currentPage, pageLimit, vanLimit, totalPages, startPage, endPage);
		// PageInfo 객체

		return pi;

	}
}
