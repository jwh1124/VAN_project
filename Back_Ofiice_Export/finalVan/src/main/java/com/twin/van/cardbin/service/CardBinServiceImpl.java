package com.twin.van.cardbin.service;

import java.util.ArrayList;
import java.util.Map;

import javax.inject.Inject;

import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.twin.van.cardbin.model.dao.CardBinDao;
import com.twin.van.cardbin.model.vo.CardBin;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

@Service
public class CardBinServiceImpl implements CardBinService {

	@Autowired
	private CardBinDao bDao;
	
	@Autowired
	private SqlSessionTemplate sqlSession;
	
	
	//BIN 검색
	@Override
	public ArrayList<CardBin> searchCardBin(Map<String, Object> paramMap, PageInfo pi) {
		ArrayList<CardBin> binList = bDao.searchCardBin(sqlSession, paramMap, pi);
		return binList;
	}
	
	//BIN 등록
	@Override
	public int insertCardBin(Map<String, Object> paramMap) {
		int result = bDao.insertCardBin(sqlSession, paramMap);
		return result;
	}
	
	//BIN 수정
	@Override
	public int updateCardBin(Map<String, Object> paramMap) {
		int result = bDao.updateCardBin(sqlSession, paramMap);
		return result;
	}
	
	//BIN 삭제
	@Override
	public int deleteCardBin(String cardBin) {
		int result = bDao.deleteCardBin(sqlSession, cardBin);
		return result;
	}
	
	//BIN 총계
	@Override
	public int searchCount(Map<String, Object> paramMap){
		int result = bDao.searchCount(sqlSession, paramMap);
		return result;
	}
}
