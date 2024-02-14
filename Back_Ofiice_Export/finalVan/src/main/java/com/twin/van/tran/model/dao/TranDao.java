package com.twin.van.tran.model.dao;

import java.util.ArrayList;
import java.util.Map;

import org.apache.ibatis.session.RowBounds;
import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.stereotype.Repository;

import com.twin.van.page.vo.PageInfo;
import com.twin.van.tran.model.vo.Tran;

@Repository
public class TranDao {
	
	//tran 검색
	public ArrayList<Tran> searchTran(SqlSessionTemplate sqlSession , Map<String, Object> paramMap,  PageInfo pi) {
		System.out.println("pi = "+pi);
		System.out.println("pi get currentPage"+pi.getCurrentPage());
		
		int offset = (pi.getCurrentPage() -1) * pi.getVanLimit(); //termLimit(조회할 숫자) 이 나옴
		RowBounds rowBounds = new RowBounds(offset, pi.getVanLimit());
		
		return (ArrayList)sqlSession.selectList("tranMapper.searchTranList", paramMap, rowBounds);
	}
	
	//tran 총계
	public int searchCount(SqlSessionTemplate sqlSession , Map<String, Object> paramMap) {
		return sqlSession.selectOne("tranMapper.searchCount",paramMap);
	}
}