package com.twin.van.terminal.service;

import java.util.ArrayList;
import java.util.Map;

import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

public interface TerminalService {
	
	//단말기 검색
	public ArrayList<Terminal> searchTerminal(Map<String, Object> paramMap, PageInfo pi);
	
	//단말기 등록
	public int insertTerminal(Map<String, Object> paramMap);
	
	//단말기 수정
	public int updateTerminal(Map<String, Object> paramMap);

	//단말기 삭제
	public int deleteTerminal(String termNum);
	
	public int searchCount(Map<String, Object> paramMap);
}
