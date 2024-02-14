package com.twin.van.page.vo;

public class PageInfo {

	private int listCount; // 총게시글 개수
	private int currentPage; // 요청받은 페이지
	private int pageLimit; // 하단에 보여질 페이징바의 페이지 목록 최대 개수
	private int vanLimit; // 해당 페이지에 보여질 최대개수
	private int maxPage; // 가장 마지막 페이지의수 (listCount, vanLimit가지고 구함)
	private int startPage;// 해당페이지에 보여질 페이징바의 시작수 (pageLmut, currentPage가지고 구함)
	private int endPage; // 해당 페이지에 보여질 페이징바의 끝수( statrPage, pageLimit, maxPage가지고 구함)

	public PageInfo() {
		super();
	}

	public PageInfo(int listCount, int currentPage, int pageLimit, int vanLimit, int maxPage, int startPage,
			int endPage) {
		super();
		this.listCount = listCount;
		this.currentPage = currentPage;
		this.pageLimit = pageLimit;
		this.vanLimit = vanLimit;
		this.maxPage = maxPage;
		this.startPage = startPage;
		this.endPage = endPage;
	}

	public int getListCount() {
		return listCount;
	}

	public void setListCount(int listCount) {
		this.listCount = listCount;
	}

	public int getCurrentPage() {
		return currentPage;
	}

	public void setCurrentPage(int currentPage) {
		this.currentPage = currentPage;
	}

	public int getPageLimit() {
		return pageLimit;
	}

	public void setPageLimit(int pageLimit) {
		this.pageLimit = pageLimit;
	}

	public int getVanLimit() {
		return vanLimit;
	}

	public void setVanLimit(int vanLimit) {
		this.vanLimit = vanLimit;
	}

	public int getMaxPage() {
		return maxPage;
	}

	public void setMaxPage(int maxPage) {
		this.maxPage = maxPage;
	}

	public int getStartPage() {
		return startPage;
	}

	public void setStartPage(int startPage) {
		this.startPage = startPage;
	}

	public int getEndPage() {
		return endPage;
	}

	public void setEndPage(int endPage) {
		this.endPage = endPage;
	}

	@Override
	public String toString() {
		return "PageInfo [listCount=" + listCount + ", currentPage=" + currentPage + ", pageLimit=" + pageLimit
				+ ", vanLimit=" + vanLimit + ", maxPage=" + maxPage + ", startPage=" + startPage + ", endPage="
				+ endPage + "]";
	}

}
