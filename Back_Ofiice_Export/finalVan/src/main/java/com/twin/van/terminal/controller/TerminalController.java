package com.twin.van.terminal.controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.twin.van.page.temp.Pagination;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;
import com.twin.van.terminal.service.TerminalServiceImpl;

@Controller
public class TerminalController {

	@Autowired
	public TerminalServiceImpl tService;

	//메뉴바에서 뷰 이동요청
	@RequestMapping(value = "moveTerminal.te")
	public String moveTerminal() {
		return "termView";
	}

	//터미널 검색 요청이 들어오면?
	@RequestMapping(value = "searchTerminal.te")
	public String searchTerminal(HttpServletRequest request, Terminal t,
			@RequestParam(value = "currentPage", defaultValue = "1")int currentPage,
			@RequestParam(value = "termNum",defaultValue = "")String pageTermNum,
			@RequestParam(value = "bisNum",defaultValue="")String pageBisNum,
			@RequestParam(value = "termStatus", defaultValue = "")String pageTermStatus) {
		
		//조회값이 null이면 미리 저장
		if(t.getTermNum() == null) {
			t.setTermNum(pageTermNum);
		}
		if(t.getBisNum() == null) {
			t.setBisNum(pageBisNum);
		}
		if(t.getTermStatus() == null) {
			t.setTermStatus(pageTermStatus);
		}
		
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		//조회에서 올라온 각 파라미터를 map에 저장
		paramMap.put("termNum", t.getTermNum());
		paramMap.put("bisNum", t.getBisNum());
		
		//date형식에서 - 제거하여 입력
		if(t.getTermOpenDate() == null) 
		{
			paramMap.put("termOpenDate", "");
		}
		else
		{
			paramMap.put("termOpenDate", t.getTermOpenDate().replace("-", ""));
		}
		if(t.getTermCloseDate() == null) 
		{
			paramMap.put("termCloseDate", "");
		}
		else
		{
			paramMap.put("termCloseDate", t.getTermCloseDate().replace("-", ""));
		}
		paramMap.put("termStatus", t.getTermStatus());
		
        int searchCount = tService.searchCount(paramMap); // 현재 검색결과에 맞는 단말기의 총 개수
        int pageLimit = 10;
        int vanLimit = 15;

        PageInfo pi = Pagination.getPageInfo(searchCount, currentPage, pageLimit, vanLimit);
        
		// 검색 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		ArrayList<Terminal> termList = tService.searchTerminal(paramMap, pi);
		
		System.out.println(termList.size());
		for (int i = 0; i < termList.size(); i++) {
			System.out.println(termList.get(i));
		}
		
		//jsp에서 사용 가능하도록 파라미터, 단말기 리스트, 페이지 리스트 넘겨줌
		request.setAttribute("paramMap", paramMap);
		request.setAttribute("termList", termList);
		request.setAttribute("pi", pi);

		return "termView";
	}
	
	//터미널 등록 요청이 들어오면?
	@RequestMapping(value = "insertTerminal.te")
	public String insertTerminal(HttpServletRequest request, Terminal t) {
		        
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		System.out.println("InsertTerminal List :"+ t ); //테스트
		
		paramMap.put("termNum", t.getTermNum());
		paramMap.put("bisNum", t.getBisNum());
		
		//date형식에서 - 제거하여 입력
		paramMap.put("termOpenDate", t.getTermOpenDate().replace("-", ""));
		paramMap.put("termStatus", t.getTermStatus());
		
		// 등록 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int result = tService.insertTerminal(paramMap);
		
        if (result > 0) {
            System.out.println("등록 성공");
        } else {
            System.out.println("등록 실패");
        }
        
		request.setAttribute("insertResult", result);
		
		return "termView";
	}
	
	//터미널 수정 요청이 들어오면?
	@RequestMapping(value = "updateTerminal.te")
	public String updateTerminal(HttpServletRequest request, Terminal t) {
		
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		System.out.println("UpdateTerminal List :"+ t ); //테스트
		
		paramMap.put("termNum", t.getTermNum());
		paramMap.put("bisNum", t.getBisNum());
		paramMap.put("termOpenDate", t.getTermOpenDate().replace("-", ""));
		paramMap.put("termCloseDate", t.getTermCloseDate().replace("-", ""));
		paramMap.put("termStatus", t.getTermStatus());

		// 검색 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int updateResult = tService.updateTerminal(paramMap);
		
		if(updateResult > 0) {
			System.out.println("수정 성공");
		} else {
			System.out.println("수정 실패");
		}
		
		
		request.setAttribute("updateResult", updateResult);

		return "termView";
	}
	
	//터미널 삭제 요청이 들어오면?
	@RequestMapping(value = "deleteTerminal.te")
	public String deleteTerminal(HttpServletRequest request, Terminal t) {
		
		System.out.println("DeleteTerminal List :"+ t ); //테스트
		
		String termNum = t.getTermNum();

		// 등록 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int deleteResult = tService.deleteTerminal(termNum);

		if(deleteResult > 0) {
			System.out.println("삭제 성공");
		} else {
			System.out.println("삭제 실패");
		}
		
		request.setAttribute("deleteResult", deleteResult);
		
		return "termView";
	}
	
}
