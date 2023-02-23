package careapExample;
 
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

import careapExampleSwing.CompanyBasics;
 
public class CompanyCARELAB implements Company,Serializable {
    ArrayList<CompanyBasics> arr = new ArrayList<CompanyBasics>();
    Scanner input = new Scanner(System.in);
    @Override
    public void saveWorker() {
        String name;
        String jobRank;
        int basicSalary;
        int bonus;
        double taxRate;
        int monthSalary;
        CompanyBasics cb = new CompanyBasics();
        System.out.print("사원 이름 : ");
        name = input.next();
        System.out.print("직급 : ");
        jobRank = input.next();
        System.out.println("기본급 : ");
        basicSalary = input.nextInt();
        System.out.println("수당 : ");
        bonus = input.nextInt();
        cb.setName(name);
        cb.setJobRank(jobRank);
        cb.setBasicSalary(basicSalary);
        cb.setBonus(bonus);
        cb.getTaxRate();
        cb.getMonthSalary();
        arr.add(cb);
        System.out.println("등록 완료!!");
    }
    @Override
    public void modify() {//수정
        System.out.println("수정할 사원의 이름을 입력 하세요 : ");
        String yourName = input.next();
        boolean flag = true;
        for (int i = 0 ; i < arr.size(); i++) {
            if (arr.get(i).getName().equals(yourName)) {
                flag = false;
                System.out.println("직급 변경 입력 : ");
                String modiJobRank = input.next();
                arr.get(i).setJobRank(modiJobRank);
                System.out.println("기본급 변경 입력 : ");
                int modiSalary = input.nextInt();
                arr.get(i).setBasicSalary(modiSalary);
                System.out.println("수당 변경 입력 : ");
                int modiBounus = input.nextInt();
                arr.get(i).setBonus(modiBounus);
                System.out.println("수정이 정상적으로 완료되었습니다.");
                break;
            }
        }
        if (flag) {
            System.out.println("해당 사원이 없습니다.");
        }
        
    }
    @Override
    public void search() {
        System.out.print("찾고자하는 사원 이름을 입력하세요 : ");
        String yourName = input.next();
        boolean flag = true;
        for (int i = 0 ; i < arr.size(); i++) {
            if (arr.get(i).getName().equals(yourName)) {
                flag = false;
                System.out.println("이름 : "+arr.get(i).getName());
                System.out.println("직급 : "+arr.get(i).getJobRank());
                System.out.println("기본급 : "+arr.get(i).getBasicSalary());
                System.out.println("수당 : "+arr.get(i).getBonus());
                System.out.println("세율 : "+arr.get(i).getTaxRate());
                System.out.println("월급 : "+arr.get(i).getMonthSalary());
                break;
            }
        }
        if (flag) {
            System.out.println("해당 사원이 없습니다.");
        }
    }
    @Override
    public void delete() {
    	 System.out.print("삭제하고자하는 사원의 이름을 입력하세요 : ");
         String yourName = input.next();
         boolean flag = true;
         for (int i = 0 ; i < arr.size(); i++) {
             if (arr.get(i).getName().equals(yourName)) 
             {
                 flag = false;
                 arr.remove(i);
                 System.out.println("해당 정보가 삭제되었습니다");
                 break;
             }
         }
         if (flag) {
             System.out.println("해당 사원이 없습니다.");
         }
    }
	public void fileSave() {
		try {
			String fileName="C:\\upload\\myfile.txt";
			File myFile=new File(fileName);
			FileOutputStream fos = new FileOutputStream(myFile);
			ObjectOutputStream oos= new ObjectOutputStream(fos);
			oos.writeObject(arr);
			oos.close();
			fos.close();
			System.out.println("파일을 저장하였습니다");
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		
	};
public void upgrade(String Rank)
		{
			
			class hakbunCompare implements Comparator<CompanyBasics> { //compareTo 오버라이딩(월급를 기준으로)
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
	public ArrayList<CompanyBasics> fileRead(){
		ArrayList<CompanyBasics> arr_t=null;
		try {
			String fileName="C:\\upload\\myfile.txt";
			ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName));
			arr_t=(ArrayList<CompanyBasics>)ois.readObject();
			ois.close();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		arr=arr_t;
		System.out.println("파일을 열기하였습니다");
		return arr;
		
	}
    @Override
    public void output() {
        System.out.println("==========모든 사원 정보 출력==========");
        System.out.println("--------------------------------------------------");
        System.out.println("| 이름  | 직급 |   기본급   |   수당   |  세율  |   월급     |");
        System.out.println("--------------------------------------------------");
        
        class hakbunCompare implements Comparator<CompanyBasics> { //compareTo 오버라이딩(학번를 기준으로)
	        public int compare(CompanyBasics o1, CompanyBasics o2) {
	        	return o1.getMonthSalary() < o2.getMonthSalary() ? 1 : o1.getMonthSalary() > o2.getMonthSalary() ? -1 : 0;
	        }
		}		
		Collections.sort(arr, new hakbunCompare());
        for(int i = 0 ; i < arr.size(); i++) {
            System.out.println("|"+arr.get(i).getName()+"| "+arr.get(i).getJobRank()
                    +" | "+arr.get(i).getBasicSalary()+"  | "+arr.get(i).getBonus()
                    +" | "+arr.get(i).getTaxRate()+" | "+arr.get(i).getMonthSalary()+" |");
        }
    }
}

