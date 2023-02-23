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
        System.out.print("��� �̸� : ");
        name = input.next();
        System.out.print("���� : ");
        jobRank = input.next();
        System.out.println("�⺻�� : ");
        basicSalary = input.nextInt();
        System.out.println("���� : ");
        bonus = input.nextInt();
        cb.setName(name);
        cb.setJobRank(jobRank);
        cb.setBasicSalary(basicSalary);
        cb.setBonus(bonus);
        cb.getTaxRate();
        cb.getMonthSalary();
        arr.add(cb);
        System.out.println("��� �Ϸ�!!");
    }
    @Override
    public void modify() {//����
        System.out.println("������ ����� �̸��� �Է� �ϼ��� : ");
        String yourName = input.next();
        boolean flag = true;
        for (int i = 0 ; i < arr.size(); i++) {
            if (arr.get(i).getName().equals(yourName)) {
                flag = false;
                System.out.println("���� ���� �Է� : ");
                String modiJobRank = input.next();
                arr.get(i).setJobRank(modiJobRank);
                System.out.println("�⺻�� ���� �Է� : ");
                int modiSalary = input.nextInt();
                arr.get(i).setBasicSalary(modiSalary);
                System.out.println("���� ���� �Է� : ");
                int modiBounus = input.nextInt();
                arr.get(i).setBonus(modiBounus);
                System.out.println("������ ���������� �Ϸ�Ǿ����ϴ�.");
                break;
            }
        }
        if (flag) {
            System.out.println("�ش� ����� �����ϴ�.");
        }
        
    }
    @Override
    public void search() {
        System.out.print("ã�����ϴ� ��� �̸��� �Է��ϼ��� : ");
        String yourName = input.next();
        boolean flag = true;
        for (int i = 0 ; i < arr.size(); i++) {
            if (arr.get(i).getName().equals(yourName)) {
                flag = false;
                System.out.println("�̸� : "+arr.get(i).getName());
                System.out.println("���� : "+arr.get(i).getJobRank());
                System.out.println("�⺻�� : "+arr.get(i).getBasicSalary());
                System.out.println("���� : "+arr.get(i).getBonus());
                System.out.println("���� : "+arr.get(i).getTaxRate());
                System.out.println("���� : "+arr.get(i).getMonthSalary());
                break;
            }
        }
        if (flag) {
            System.out.println("�ش� ����� �����ϴ�.");
        }
    }
    @Override
    public void delete() {
    	 System.out.print("�����ϰ����ϴ� ����� �̸��� �Է��ϼ��� : ");
         String yourName = input.next();
         boolean flag = true;
         for (int i = 0 ; i < arr.size(); i++) {
             if (arr.get(i).getName().equals(yourName)) 
             {
                 flag = false;
                 arr.remove(i);
                 System.out.println("�ش� ������ �����Ǿ����ϴ�");
                 break;
             }
         }
         if (flag) {
             System.out.println("�ش� ����� �����ϴ�.");
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
			System.out.println("������ �����Ͽ����ϴ�");
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		
	};
public void upgrade(String Rank)
		{
			
			class hakbunCompare implements Comparator<CompanyBasics> { //compareTo �������̵�(���޸� ��������)
		        public int compare(CompanyBasics o1, CompanyBasics o2) {
		        	return o1.getMonthSalary() < o2.getMonthSalary() ? 1 : o1.getMonthSalary() > o2.getMonthSalary() ? -1 : 0;
		        }
			}		
			Collections.sort(arr, new hakbunCompare());
			for(CompanyBasics dto:arr)
			{
				String junk="������"+Rank;
				if(junk.equals(dto.getJobRank()))
				{
					break;	
				}
				if(Rank.equals(dto.getJobRank()))
				{
					String flash=dto.getJobRank();
					
					dto.setJobRank("������"+flash);
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
		System.out.println("������ �����Ͽ����ϴ�");
		return arr;
		
	}
    @Override
    public void output() {
        System.out.println("==========��� ��� ���� ���==========");
        System.out.println("--------------------------------------------------");
        System.out.println("| �̸�  | ���� |   �⺻��   |   ����   |  ����  |   ����     |");
        System.out.println("--------------------------------------------------");
        
        class hakbunCompare implements Comparator<CompanyBasics> { //compareTo �������̵�(�й��� ��������)
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

