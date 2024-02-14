package com.twin.van.tran.service;

import java.util.ArrayList;
import java.util.Map;

import javax.inject.Inject;

import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.twin.van.page.vo.PageInfo;
import com.twin.van.tran.model.dao.TranDao;
import com.twin.van.tran.model.vo.Tran;

@Service
public class TranServiceImpl implements TranService {

	@Autowired
	private TranDao trDao;
	
	@Autowired
	private SqlSessionTemplate sqlSession;
	
	@Override
	public ArrayList<Tran> searchTran(Map<String, Object> paramMap, PageInfo pi) {
		ArrayList<Tran> tranList = trDao.searchTran(sqlSession, paramMap, pi);
		return tranList;
	}
	
	//tran 총계
	@Override
	public int searchCount(Map<String, Object> paramMap){
		int result = trDao.searchCount(sqlSession, paramMap);
		return result;
	}
		
}
