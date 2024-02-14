package com.twin.van.tran.controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.twin.van.page.temp.Pagination;
import com.twin.van.page.vo.PageInfo;
import com.twin.van.terminal.model.vo.Terminal;
import com.twin.van.tran.model.vo.Tran;
import com.twin.van.tran.service.TranServiceImpl;

@Controller
public class TranController {
	
	@Autowired
	public TranServiceImpl tService;
	
	@RequestMapping(value = "moveTran.tr")
	public String moveTran() {
		return "tranView";
	}
	
	@RequestMapping(value = "searchTran.tr")
	public String selectTran(HttpServletRequest request, Tran tr,
			@RequestParam(value = "currentPage", defaultValue = "1")int currentPage,
			@RequestParam(value = "tranStartDate")String startDate,
			@RequestParam(value = "tranEndDate")String endDate,
			@RequestParam(value = "tranStartAmt")String startAmt,
			@RequestParam(value = "tranEndAmt")String endAmt,
			@RequestParam(value = "cardNum")String cardNum){
		
		Map<String, Object> paramMap = new HashMap<String, Object>();
		
        // 오늘 날짜 구하기
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
        Date today = new Date();
        String todayStr = dateFormat.format(today);

        endDate = endDate.replace("-", "");
        
        if(todayStr.equals(endDate)) //오늘이 endDate라면? 
        {
            // tranEndDate 설정하기 (오늘 날짜의 하루 전)
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(today);
            calendar.add(Calendar.DATE, -1);
            Date todayminus = calendar.getTime();
            endDate = dateFormat.format(todayminus);//tranEndDateStr을 오늘날짜-1   
        }
        else
        {
        	todayStr = "";
        }

        
        paramMap.put("today",todayStr);
		paramMap.put("tranStartDate", startDate.replace("-", ""));
		paramMap.put("tranEndDate", endDate);
		paramMap.put("tranStartAmt", startAmt);
		paramMap.put("tranEndAmt", endAmt);
		paramMap.put("cardNum", cardNum);
		paramMap.put("resCode", tr.getResCode());
		paramMap.put("termNum", tr.getTermNum());
		paramMap.put("tranNum", tr.getTranNum());
		
		System.out.println(paramMap);
		
        int searchCount = tService.searchCount(paramMap); // 현재 검색결과에 맞는 단말기의 총 개수
        int pageLimit = 10;
        int vanLimit = 15;
		
        PageInfo pi = Pagination.getPageInfo(searchCount, currentPage, pageLimit, vanLimit);
        
		// 검색 로직을 구현하고 조회 결과를 데이터베이스에서 가져옴.
		ArrayList<Tran> tranList = tService.searchTran(paramMap, pi);
		
		System.out.println(tranList.size());
		for (int i = 0; i < tranList.size(); i++) {
			System.out.println(tranList.get(i));
		}

		//jsp에서 사용 가능하도록 파라미터, 단말기 리스트, 페이지 리스트 넘겨줌
		request.setAttribute("paramMap", paramMap);
		request.setAttribute("tranList", tranList);
		request.setAttribute("pi", pi);
	return "tranView";
	}
	
}
