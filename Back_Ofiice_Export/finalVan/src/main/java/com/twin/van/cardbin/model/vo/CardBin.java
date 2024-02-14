package com.twin.van.cardbin.model.vo;

public class CardBin {
	private String cardBin;
	private String cardDif;
	private String cardStatus;

	public CardBin() {
	}

	public CardBin(String cardBin, String cardDif, String cardStatus) {
		super();
		this.cardBin = cardBin;
		this.cardDif = cardDif;
		this.cardStatus = cardStatus;
	}

	public String getCardBin() {
		return cardBin;
	}

	public void setCardBin(String cardBin) {
		this.cardBin = cardBin;
	}

	public String getCardDif() {
		return cardDif;
	}

	public void setCardDif(String cardDif) {
		this.cardDif = cardDif;
	}

	public String getCardStatus() {
		return cardStatus;
	}

	public void setCardStatus(String cardStatus) {
		this.cardStatus = cardStatus;
	}

	@Override
	public String toString() {
		return "CardBin [cardBin=" + cardBin + ", cardDif=" + cardDif + ", cardStatus=" + cardStatus + "]";
	}

}
