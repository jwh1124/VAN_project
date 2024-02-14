package com.twin.van.tran.service;

import java.util.ArrayList;
import java.util.Map;

import com.twin.van.cardbin.model.vo.CardBin;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.tran.model.vo.Tran;

public interface TranService {
	//Tran 검색
	public ArrayList<Tran> searchTran(Map<String, Object> paramMap, PageInfo pi);
	
	public int searchCount(Map<String, Object> paramMap);
}
