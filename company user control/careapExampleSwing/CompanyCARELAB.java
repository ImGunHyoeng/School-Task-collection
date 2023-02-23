package careapExampleSwing;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import javax.swing.JFileChooser;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class CompanyCARELAB implements Company,Serializable {

	List<CompanyBasics> arr=new ArrayList<CompanyBasics>();
	// list라는 부모 밑에 자식 중 하나인 Arrayist를 참조한다. 
	// 1 : 1 보다는 1 : 다 형태로, 부모가 ArrayList 말고 다른 것도 참조할 수 있게 만들어 결합도를 끊어준다. 
	
	// 여기에서 받는 값들은 score 인터페이스에도 줘야한다. 
	public void saveWorker(CompanyBasics dto) {	//삽입
		// form에서 온 값 받기 
		arr.add(dto); // list에 받은 dto 값 추가 
		// 등록완료 메시지 
	}
	public int findIndex(String name) {
    	int findIndex=-1;
    	for(CompanyBasics dto : arr)
		if(name.equals(dto.getName())){
			int i=0;
			i++;
			findIndex=i;
    		break;
    	}
    	return findIndex;
    	
    }
	public void print(JTextArea ta) {	// 학번순출력
		// 추가한 내용
		
		
		ta.setText("");
		ta.append("이름"+"\t"+"직급"+"\t"+"기본급"+"\t"+"수당"+"\t"+"세율"+"\t"+"월급"+"\n");
		ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		
		
		for(CompanyBasics dto : arr) {
			// list 값을 하나씩 전달한다(list에 값이 몇개 있는지 모르기 때문에 확장형 for문)	
			ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() + "\t" + dto.getBonus() +"\t"
			+dto.getTaxRate()+"\t"+dto.getMonthSalary()+ "\n");	
		}
		
	}
	
	public void compare(JTextArea ta) {	// 학번순출력
		// 추가한 내용
		class hakbunCompare implements Comparator<CompanyBasics> { //compareTo 오버라이딩(학번를 기준으로)
	        public int compare(CompanyBasics o1, CompanyBasics o2) {
	        	return o1.getMonthSalary() < o2.getMonthSalary() ? 1 : o1.getMonthSalary() > o2.getMonthSalary() ? -1 : 0;
	        }
		}		
		Collections.sort(arr, new hakbunCompare());
		// 추가 끝*/
		
		ta.setText("");
		ta.append("이름"+"\t"+"직급"+"\t"+"기본급"+"\t"+"수당"+"\t"+"세율"+"\t"+"월급"+"\n");
		ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		
		
		for(CompanyBasics dto : arr) {
			// list 값을 하나씩 전달한다(list에 값이 몇개 있는지 모르기 때문에 확장형 for문)	
			ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() + "\t" + dto.getBonus() +"\t"
			+dto.getTaxRate()+"\t"+dto.getMonthSalary()+ "\n");	
		}
		
	}

	public int modify(CompanyBasics dto) {	// 이름 검색
		//수정
			int sw=0;
			for(int i=0;i<arr.size();i++){
				if(dto.getName().equals(arr.get(i).getName())) { //만약 이름과 같은 값을 찾는다면
					arr.remove(i); // 기존 내용 삭제
					
					dto = new CompanyBasics(dto.getName(), dto.getJobRank(), dto.getBasicSalary(), dto.getBonus(),dto.getTaxRate(),dto.getMonthSalary());
					arr.add(dto); // 새로운 내용 삽입

					sw=1;
					break;
				}
			}
			return sw;
	}
	
	public int search(JTextArea ta, String num) { //학번검색 
		ta.setText("");
		int sw = 0; // 찾으면 1이 된다. 
		
		// 찾고자 하는 학점 num을 model과 함께 form에서 받는다.  
		for(CompanyBasics dto : arr) {
			if(num.equals( dto.getName())) {				
				ta.append("이름"+"\t"+"직급"+"\t"+"기본급"+"\t"+"수당"+"\t"+"세율"+"\t"+"월급"+"\n");
				ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		

				ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() +"\t" + dto.getBonus() +"\t" + 
						dto.getTaxRate() +"\t" + dto.getMonthSalary() +"\n");
				
				sw = 1;
			}
		}// for	
		// 찾고자 하는 정보가 없는 dialog는 form에다 찍어준다. 
		return sw; // 찾았는지 찾지 못했는지 알려주는 sw를 return 해 
		// form에 알려준다 (그에 따라 dialog를 띄워야하기 때문)
	}

	public int delete(CompanyBasics dto,String num) {
		// TODO Auto-generated method stub				
			int sw = 0; // 삭제시 1이 된다. 		
			// 선택한 줄 번호 알아내기 
			Iterator<CompanyBasics> it = arr.iterator();
			
			while(it.hasNext()) {
				dto = it.next();
					if(num.equals(dto.getName())) {
						//if(num.equals(dto.getNum())) {
						it.remove();					
						sw = 1;								
					}	
			}
			return sw;				
	}
	
	public void upgrade(String Rank)
	{
		
		class hakbunCompare implements Comparator<CompanyBasics> { //compareTo 오버라이딩(학번를 기준으로)
	        public int compare(CompanyBasics o1, CompanyBasics o2) {
	        	return o1.getMonthSalary() < o2.getMonthSalary() ? 1 : o1.getMonthSalary() > o2.getMonthSalary() ? -1 : 0;
	        }
		}		
		Collections.sort(arr, new hakbunCompare());
		for(CompanyBasics dto:arr)
		{
			String junk="올해의"+Rank;
			if(junk.equals(dto.getJobRank()))
			{
				break;	
			}
			if(Rank.equals(dto.getJobRank()))
			{
				String flash=dto.getJobRank();
				
				dto.setJobRank("올해의"+flash);
				break;
			}
		}
			

	}
	
	/*
	 FileNameExtendionFilter filter;
	 filter= new FileNameExtensionFilter(
	 "JPG&GIF Images","jpg","gif");
	 chooser.setFileFilter(filter);
	 위의 파일의 종류들만 보이게 필터처리한것이다
	 */
	public void save(){	//파일저장 직렬화 Serializable
		Object o =arr;
		File file = null;
		JFileChooser chooser = new JFileChooser();//디렉토리를 쉽게 선택할수 있는 기능
		int result= chooser.showSaveDialog(null);//열기대화상자,저장대화상자
		if(result==JFileChooser.APPROVE_OPTION){//적절하게 열어진다면 APPROVE_OPTION,취소 CANCEL_OPTION,에러 ERROR_OPTION
			file = chooser.getSelectedFile();//선택한 파일 파일객체로 반환 ,이름을 작성한것을 file로 전달
		}
		if(file!=null){
			try{
			FileOutputStream fos = new FileOutputStream(file);//파일 출력 및 전달
			ObjectOutputStream oos = new ObjectOutputStream(fos);//fos를 전달인자로 사용하여 파일스트림과 객체스트림을 연결
			oos.writeObject(o);//파일로 만들 클래스의 객체를 연결
			oos.close();//작업종료
			fos.close();//종료
			} catch(IOException e){}
		}		
	}
	
	public void load(){	//파일열기 역직렬화 Serializable
		try{
			File file = null;
			JFileChooser c= new JFileChooser();
			int result = c.showOpenDialog(null);
			if(result==JFileChooser.APPROVE_OPTION){
				file = c.getSelectedFile();//JFileChooser에서 선택한 파일을 file 에 전송
				FileInputStream fis = new FileInputStream(file);//파일로 부터 파일 인풋스트림 생성
				ObjectInputStream ois = new ObjectInputStream(fis);//fis로 부터 오브젝트 스트림을 생성
				Object o = ois.readObject();//객체를 읽는다
				arr=(List<CompanyBasics>) o;//List<CompanyBascis>형태로 객체를 캐스트한다
				ois.close();//오브젝트스트림을 닫기
				fis.close();
			}
		} catch(IOException | ClassNotFoundException e){ e.printStackTrace(); }
	}
	
	
}