package careapExample;
 
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        CompanyCARELAB company = new CompanyCARELAB();
        Scanner input = new Scanner(System.in);
        while(true) {
            System.out.println("==== CARE LAB ��� ���� ���α׷� ====");
            System.out.println("1. ���");
            System.out.println("2. ���޼��������");
            System.out.println("3. ����");
            System.out.println("4. ����");
            System.out.println("5. �˻�");
            System.out.println("6. ����");
            System.out.println("7. �ҷ�����");
            System.out.println("8. ����������");
            System.out.println("9. ����");
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
            	// TextField ���� �����´�. 
            	String great = null;
    			int i=(int)(Math.random()*4)+1;
    			if(i==1)
    				great="���";
    			else if(i==2)
    				great="�븮";
    			else if(i==3)
    				great="����";
    			else if(i==4)
    				great="����";
    			company.upgrade(great);
    			break;
            case 9:
            	System.exit(0);
            	
            default:
                System.out.println("�߸��� �Է�");
                break;
            }
        }
    }
}