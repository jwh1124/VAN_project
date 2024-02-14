package com.twin.van.cardbin.controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.twin.van.cardbin.model.vo.CardBin;
import com.twin.van.cardbin.service.CardBinServiceImpl;
import com.twin.van.page.temp.Pagination;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;

@Controller
public class CardBinController {

	@Autowired
	public CardBinServiceImpl bService;

	//메뉴바에서 뷰 이동요청
	@RequestMapping(value = "moveBin.bi")
	public String moveBin() {
		return "binView";
	}
		
	//빈 서치 요청이 들어오면?
	@RequestMapping(value = "searchCardBin.bi")
	public String searchTerminal(HttpServletRequest request, CardBin b,
			@RequestParam(value = "currentPage", defaultValue = "1")int currentPage,
			@RequestParam(value = "cardBin",defaultValue = "")String pageCardBin,
			@RequestParam(value = "cardDif",defaultValue="")String pageCardDif,
			@RequestParam(value = "cardStatus", defaultValue = "")String pageCardStatus) {
		
		//조회값이 null이면 미리 저장
		if(b.getCardBin() == null) {
			b.setCardBin(pageCardBin);
		}
		if(b.getCardDif() == null) {
			b.setCardDif(pageCardDif);
		}
		if(b.getCardStatus() == null) {
			b.setCardStatus(pageCardStatus);
		}
		
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		System.out.println(b); //테스트
		
		paramMap.put("cardBin", b.getCardBin());
		paramMap.put("cardDif", b.getCardDif());
		paramMap.put("cardStatus", b.getCardStatus());
		
	    int searchCount = bService.searchCount(paramMap); // 현재 검색결과에 맞는 단말기의 총 개수
	    int pageLimit = 10;
	    int vanLimit = 15;

	    PageInfo pi = Pagination.getPageInfo(searchCount, currentPage, pageLimit, vanLimit);
	        
		// 검색 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		ArrayList<CardBin> binList = bService.searchCardBin(paramMap,pi);
		
		System.out.println(binList.size());
		for (int i = 0; i < binList.size(); i++) {
			System.out.println(binList.get(i));
		}
		request.setAttribute("paramMap", paramMap);
		request.setAttribute("binList", binList);
		request.setAttribute("pi", pi);

		return "binView";
	}
	
	//BIN 등록 요청이 들어오면?
	@RequestMapping(value = "insertCardBin.bi")
	public String insertTerminal(HttpServletRequest request, CardBin b) {
		        
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		System.out.println("insertBin List :"+ b ); //테스트
		
		paramMap.put("cardBin", b.getCardBin());
		paramMap.put("cardDif", b.getCardDif());
		paramMap.put("cardStatus", b.getCardStatus());
		
		// 등록 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int result = bService.insertCardBin(paramMap);
		
        if (result > 0) {
            System.out.println("등록 성공");
        } else {
            System.out.println("등록 실패");
        }
        
		request.setAttribute("insertResult", result);
		
		return "binView";
	}
	
	//BIN 수정 요청이 들어오면?
	@RequestMapping(value = "updateCardBin.bi")
	public String updateTerminal(HttpServletRequest request, CardBin b) {
		
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
		System.out.println("updateCardBin List :"+ b ); //테스트
		
		paramMap.put("cardBin", b.getCardBin());
		paramMap.put("cardDif", b.getCardDif());
		paramMap.put("cardStatus", b.getCardStatus());

		// 검색 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int updateResult = bService.updateCardBin(paramMap);
		
		if(updateResult > 0) {
			System.out.println("수정 성공");
		} else {
			System.out.println("수정 실패");
		}
		
		
		request.setAttribute("updateResult", updateResult);

		return "binView";
	}
	
	//터미널 삭제 요청이 들어오면?
	@RequestMapping(value = "deleteCardBin.bi")
	public String deleteTerminal(HttpServletRequest request, CardBin b) {
		
		System.out.println("deleteCardBin List :"+ b ); //테스트
		
		String cardBin = b.getCardBin();

		// 등록 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		int deleteResult = bService.deleteCardBin(cardBin);

		if(deleteResult > 0) {
			System.out.println("삭제 성공");
		} else {
			System.out.println("삭제 실패");
		}
		
		request.setAttribute("deleteResult", deleteResult);
		
		return "binView";
	}
}
