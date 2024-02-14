package com.twin.van.terminal.service;

import java.util.ArrayList;
import java.util.Map;

import javax.inject.Inject;

import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.dao.TerminalDao;
import com.twin.van.terminal.model.vo.Terminal;

@Service
public class TerminalServiceImpl implements TerminalService {

	@Autowired
	private TerminalDao tDao;
	
	@Autowired
	private SqlSessionTemplate sqlSession;
	
	//단말기 검색
	@Override
	public ArrayList<Terminal> searchTerminal(Map<String, Object> paramMap, PageInfo pi) {
		ArrayList<Terminal> termList = tDao.searchTerminal(sqlSession, paramMap, pi);
		return termList;
	}
	
	//단말기 등록
	@Override
	public int insertTerminal(Map<String, Object> paramMap) {
		int result = tDao.insertTerminal(sqlSession, paramMap);
		return result;
	}
	
	//단말기 수정
	@Override
	public int updateTerminal(Map<String, Object> paramMap) {
		int result = tDao.updateTerminal(sqlSession, paramMap);
		return result;
	}
	
	//단말기 삭제
	@Override
	public int deleteTerminal(String termNum) {
		int result = tDao.deleteTerminal(sqlSession, termNum);
		return result;
	}
	
	//단말기 총계
	@Override
	public int searchCount(Map<String, Object> paramMap){
		int result = tDao.searchCount(sqlSession, paramMap);
		return result;
	}
}
