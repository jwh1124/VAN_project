package com.twin.van.cardbin.model.dao;

import java.util.ArrayList;
import java.util.Map;

import org.apache.ibatis.session.RowBounds;
import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.stereotype.Repository;

import com.twin.van.cardbin.model.vo.CardBin;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

@Repository
public class CardBinDao {
	
	//BIN 검색
	public ArrayList<CardBin> searchCardBin(SqlSessionTemplate sqlSession , Map<String, Object> paramMap, PageInfo pi) {
		System.out.println("pi = "+pi);
		System.out.println("pi get currentPage"+pi.getCurrentPage());
		
		int offset = (pi.getCurrentPage() -1) * pi.getVanLimit(); //termLimit(조회할 숫자) 이 나옴
		RowBounds rowBounds = new RowBounds(offset, pi.getVanLimit());
		
		return (ArrayList)sqlSession.selectList("binMapper.searchCardBin", paramMap, rowBounds);
	}
	
	//BIN 등록
	public int insertCardBin(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.insert("binMapper.insertCardBin",paramMap);
	}
	
	//BIN 수정
	public int updateCardBin(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.insert("binMapper.updateCardBin",paramMap);
	}
	
	//BIN 삭제
	public int deleteCardBin(SqlSessionTemplate sqlSession , String cardBin) {
		return sqlSession.insert("binMapper.deleteCardBin",cardBin);
	}
	
	//BIN 총계
	public int searchCount(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.selectOne("binMapper.searchCount",paramMap);
	}

}