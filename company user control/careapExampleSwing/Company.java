package careapExampleSwing;

import java.util.ArrayList;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public interface Company {
	//입력
	public void saveWorker(CompanyBasics dto);//직원 한명의 값 전달 메소드
	//연산
	public int modify(CompanyBasics dto);//특정 직원의 직급, 기본금, 수당 수정 메소드
	public int search(JTextArea ta, String num);//이름 값으로 해당 값을 가진 직원 찾기& 해당 값 출력 메소드
	//출력
	public int delete(CompanyBasics dto, String num);//출력되는 정보들의 타이틀 출력 메소드
	public void save();
	public void print(JTextArea ta);
	public void compare(JTextArea ta);
	public void load();
	public int findIndex(String nameT);
	public void upgrade(String Rank); 
	
}
