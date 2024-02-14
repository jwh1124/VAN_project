package com.twin.van.tran.model.vo;

public class Tran {
	private String tranUniqNum;
	private String tranDate;
	private String termNum;
	private String TranNum;
	private String tranType;
	private String cardInfo;
	private String approveAmt;
	private String instMon;
	private String approveNum;
	private String resCode;
	private String resMsg;
	private String tranOrgDate;
	private String cancle;
	private String approveOrgNum;
	

	public Tran() {
	}

	public Tran(String tranUniqNum, String tranDate, String termNum, String TranNum, String tranType, String cardInfo,
			String approveAmt, String instMon, String approveNum, String resCode, String resMsg, String tranOrgDate, String cancle, String approveOrgNum) {
		super();
		this.tranUniqNum = tranUniqNum;
		this.tranDate = tranDate;
		this.termNum = termNum;
		this.TranNum = TranNum;
		this.tranType = tranType;
		this.cardInfo = cardInfo;
		this.approveAmt = approveAmt;
		this.instMon = instMon;
		this.approveNum = approveNum;
		this.resCode = resCode;
		this.resMsg = resMsg;
		this.tranOrgDate = tranOrgDate;
		this.cancle = cancle;
		this.approveOrgNum = approveOrgNum;
	}

	public String getTranUniqNum() {
		return tranUniqNum;
	}

	public void setTranUniqNum(String tranUniqNum) {
		this.tranUniqNum = tranUniqNum;
	}

	public String getTranDate() {
		return tranDate;
	}

	public void setTranDate(String tranDate) {
		this.tranDate = tranDate;
	}

	public String getTermNum() {
		return termNum;
	}

	public void setTermNum(String termNum) {
		this.termNum = termNum;
	}

	public String getTranNum() {
		return TranNum;
	}

	public void setTranNum(String tranNum) {
		TranNum = tranNum;
	}

	public String getTranType() {
		return tranType;
	}

	public void setTranType(String tranType) {
		this.tranType = tranType;
	}

	public String getCardInfo() {
		return cardInfo;
	}

	public void setCardInfo(String cardInfo) {
		this.cardInfo = cardInfo;
	}

	public String getApproveAmt() {
		return approveAmt;
	}

	public void setApproveAmt(String approveAmt) {
		this.approveAmt = approveAmt;
	}

	public String getInstMon() {
		return instMon;
	}

	public void setInstMon(String instMon) {
		this.instMon = instMon;
	}

	public String getApproveNum() {
		return approveNum;
	}

	public void setApproveNum(String approveNum) {
		this.approveNum = approveNum;
	}

	public String getResCode() {
		return resCode;
	}

	public void setResCode(String resCode) {
		this.resCode = resCode;
	}

	public String getResMsg() {
		return resMsg;
	}

	public void setResMsg(String resMsg) {
		this.resMsg = resMsg;
	}

	public String getTranOrgDate() {
		return tranOrgDate;
	}

	public void setTranOrgDate(String tranOrgDate) {
		this.tranOrgDate = tranOrgDate;
	}

	public String getCancle() {
		return cancle;
	}

	public void setCancle(String cancle) {
		this.cancle = cancle;
	}

	public String getApproveOrgNum() {
		return approveOrgNum;
	}

	public void setApproveOrgNum(String approveOrgNum) {
		this.approveOrgNum = approveOrgNum;
	}

	@Override
	public String toString() {
		return "Tran [tranUniqNum=" + tranUniqNum + ", tranDate=" + tranDate + ", termNum=" + termNum + ", TranNum="
				+ TranNum + ", tranType=" + tranType + ", cardInfo=" + cardInfo + ", approveAmt=" + approveAmt
				+ ", instMon=" + instMon + ", approveNum=" + approveNum + ", resCode=" + resCode + ", resMsg=" + resMsg
				+ ", tranOrgDate=" + tranOrgDate + ", cancle=" + cancle + ", approveOrgNum=" + approveOrgNum + "]";
	}


}
