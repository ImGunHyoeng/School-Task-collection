package careapExample;
 
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        CompanyCARELAB company = new CompanyCARELAB();
        Scanner input = new Scanner(System.in);
        while(true) {
            System.out.println("==== CARE LAB 사원 관리 프로그램 ====");
            System.out.println("1. 등록");
            System.out.println("2. 월급순으로출력");
            System.out.println("3. 수정");
            System.out.println("4. 삭제");
            System.out.println("5. 검색");
            System.out.println("6. 저장");
            System.out.println("7. 불러오기");
            System.out.println("8. 올해의인재");
            System.out.println("9. 종료");
            System.out.print(">>>");
            int select = input.nextInt();
            switch (select) {
            case 1:
                company.saveWorker();
                break;
            case 2:
                company.output();
                break;
            case 3:
                company.modify();
                break;
            case 4:
                company.delete();
                break;
                
            case 5:
            	company.search();
            	break;
                
            case 6:
            	company.fileSave();
            	break;
            case 7:
            	company.fileRead();
            	break;
            case 8:
            	// TextField 값을 가져온다. 
            	String great = null;
    			int i=(int)(Math.random()*4)+1;
    			if(i==1)
    				great="사원";
    			else if(i==2)
    				great="대리";
    			else if(i==3)
    				great="과장";
    			else if(i==4)
    				great="부장";
    			company.upgrade(great);
    			break;
            case 9:
            	System.exit(0);
            	
            default:
                System.out.println("잘못된 입력");
                break;
            }
        }
    }
}