package com.twin.van.terminal.model.vo;

public class Terminal {
	
	private String termNum;
	private String bisNum;
	private String termOpenDate;
	private String termCloseDate;
	private String termStatus;
	
	public Terminal() {}

	public Terminal(String termNum, String bisNum, String termOpenDate, String termCloseDate, String termStatus) {
		super();
		this.termNum = termNum;
		this.bisNum = bisNum;
		this.termOpenDate = termOpenDate;
		this.termCloseDate = termCloseDate;
		this.termStatus = termStatus;
	}

	public String getTermNum() {
		return termNum;
	}

	public void setTermNum(String termNum) {
		this.termNum = termNum;
	}

	public String getBisNum() {
		return bisNum;
	}

	public void setBisNum(String bisNum) {
		this.bisNum = bisNum;
	}

	public String getTermOpenDate() {
		return termOpenDate;
	}

	public void setTermOpenDate(String termOpenDate) {
		this.termOpenDate = termOpenDate;
	}

	public String getTermCloseDate() {
		return termCloseDate;
	}

	public void setTermCloseDate(String termCloseDate) {
		this.termCloseDate = termCloseDate;
	}

	public String getTermStatus() {
		return termStatus;
	}

	public void setTermStatus(String termStatus) {
		this.termStatus = termStatus;
	}

	@Override
	public String toString() {
		return "Terminal [termNum=" + termNum + ", bisNum=" + bisNum + ", termOpenDate=" + termOpenDate
				+ ", termCloseDate=" + termCloseDate + ", termStatus=" + termStatus + "]";
	}
	
	
	
}
