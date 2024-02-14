package com.twin.van.cardbin.service;

import java.util.ArrayList;
import java.util.Map;

import com.twin.van.cardbin.model.vo.CardBin;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

public interface CardBinService {

	
	//BIN 검색
	public ArrayList<CardBin> searchCardBin(Map<String, Object> paramMap, PageInfo pi);
	
	//BIN 등록
	public int insertCardBin(Map<String, Object> paramMap);
	
	//BIN 수정
	public int updateCardBin(Map<String, Object> paramMap);

	//BIN 삭제
	public int deleteCardBin(String cardBin);
	
	public int searchCount(Map<String, Object> paramMap);
	
}
