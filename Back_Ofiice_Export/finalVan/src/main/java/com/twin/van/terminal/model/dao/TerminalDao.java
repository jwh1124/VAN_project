package com.twin.van.terminal.model.dao;

import java.util.ArrayList;
import java.util.Map;

import org.apache.ibatis.session.RowBounds;
import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.stereotype.Repository;

import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

@Repository
public class TerminalDao {
	
	//단말기 검색
	public ArrayList<Terminal> searchTerminal(SqlSessionTemplate sqlSession , Map<String, Object> paramMap, PageInfo pi) {
		System.out.println("pi = "+pi);
		System.out.println("pi get currentPage"+pi.getCurrentPage());
		
		int offset = (pi.getCurrentPage() -1) * pi.getVanLimit(); //termLimit(조회할 숫자) 이 나옴
		RowBounds rowBounds = new RowBounds(offset, pi.getVanLimit());
		
		return (ArrayList)sqlSession.selectList("termMapper.searchTerm", paramMap, rowBounds);
	}
	
	//단말기 등록
	public int insertTerminal(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.insert("termMapper.insertTerm",paramMap);
	}
	
	//단말기 수정
	public int updateTerminal(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.insert("termMapper.updateTerm",paramMap);
	}
	
	//단말기 삭제
	public int deleteTerminal(SqlSessionTemplate sqlSession , String termNum) {
		return sqlSession.insert("termMapper.deleteTerm",termNum);
	}
	
	//단말기 총계
	public int searchCount(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.selectOne("termMapper.searchCount",paramMap);
	}

}