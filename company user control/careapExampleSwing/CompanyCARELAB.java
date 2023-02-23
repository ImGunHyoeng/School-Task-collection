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
	// list��� �θ� �ؿ� �ڽ� �� �ϳ��� Arrayist�� �����Ѵ�. 
	// 1 : 1 ���ٴ� 1 : �� ���·�, �θ� ArrayList ���� �ٸ� �͵� ������ �� �ְ� ����� ���յ��� �����ش�. 
	
	// ���⿡�� �޴� ������ score �������̽����� ����Ѵ�. 
	public void saveWorker(CompanyBasics dto) {	//����
		// form���� �� �� �ޱ� 
		arr.add(dto); // list�� ���� dto �� �߰� 
		// ��ϿϷ� �޽��� 
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
	public void print(JTextArea ta) {	// �й������
		// �߰��� ����
		
		
		ta.setText("");
		ta.append("�̸�"+"\t"+"����"+"\t"+"�⺻��"+"\t"+"����"+"\t"+"����"+"\t"+"����"+"\n");
		ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		
		
		for(CompanyBasics dto : arr) {
			// list ���� �ϳ��� �����Ѵ�(list�� ���� � �ִ��� �𸣱� ������ Ȯ���� for��)	
			ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() + "\t" + dto.getBonus() +"\t"
			+dto.getTaxRate()+"\t"+dto.getMonthSalary()+ "\n");	
		}
		
	}
	
	public void compare(JTextArea ta) {	// �й������
		// �߰��� ����
		class hakbunCompare implements Comparator<CompanyBasics> { //compareTo �������̵�(�й��� ��������)
	        public int compare(CompanyBasics o1, CompanyBasics o2) {
	        	return o1.getMonthSalary() < o2.getMonthSalary() ? 1 : o1.getMonthSalary() > o2.getMonthSalary() ? -1 : 0;
	        }
		}		
		Collections.sort(arr, new hakbunCompare());
		// �߰� ��*/
		
		ta.setText("");
		ta.append("�̸�"+"\t"+"����"+"\t"+"�⺻��"+"\t"+"����"+"\t"+"����"+"\t"+"����"+"\n");
		ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		
		
		for(CompanyBasics dto : arr) {
			// list ���� �ϳ��� �����Ѵ�(list�� ���� � �ִ��� �𸣱� ������ Ȯ���� for��)	
			ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() + "\t" + dto.getBonus() +"\t"
			+dto.getTaxRate()+"\t"+dto.getMonthSalary()+ "\n");	
		}
		
	}

	public int modify(CompanyBasics dto) {	// �̸� �˻�
		//����
			int sw=0;
			for(int i=0;i<arr.size();i++){
				if(dto.getName().equals(arr.get(i).getName())) { //���� �̸��� ���� ���� ã�´ٸ�
					arr.remove(i); // ���� ���� ����
					
					dto = new CompanyBasics(dto.getName(), dto.getJobRank(), dto.getBasicSalary(), dto.getBonus(),dto.getTaxRate(),dto.getMonthSalary());
					arr.add(dto); // ���ο� ���� ����

					sw=1;
					break;
				}
			}
			return sw;
	}
	
	public int search(JTextArea ta, String num) { //�й��˻� 
		ta.setText("");
		int sw = 0; // ã���� 1�� �ȴ�. 
		
		// ã���� �ϴ� ���� num�� model�� �Բ� form���� �޴´�.  
		for(CompanyBasics dto : arr) {
			if(num.equals( dto.getName())) {				
				ta.append("�̸�"+"\t"+"����"+"\t"+"�⺻��"+"\t"+"����"+"\t"+"����"+"\t"+"����"+"\n");
				ta.append("-------------------------------------------------------------------------------------------------------------------------------------------------\n");		

				ta.append(dto.getName() +"\t"+ dto.getJobRank()  +"\t" + dto.getBasicSalary() +"\t" + dto.getBonus() +"\t" + 
						dto.getTaxRate() +"\t" + dto.getMonthSalary() +"\n");
				
				sw = 1;
			}
		}// for	
		// ã���� �ϴ� ������ ���� dialog�� form���� ����ش�. 
		return sw; // ã�Ҵ��� ã�� ���ߴ��� �˷��ִ� sw�� return �� 
		// form�� �˷��ش� (�׿� ���� dialog�� ������ϱ� ����)
	}

	public int delete(CompanyBasics dto,String num) {
		// TODO Auto-generated method stub				
			int sw = 0; // ������ 1�� �ȴ�. 		
			// ������ �� ��ȣ �˾Ƴ��� 
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
		
		class hakbunCompare implements Comparator<CompanyBasics> { //compareTo �������̵�(�й��� ��������)
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
	
	/*
	 FileNameExtendionFilter filter;
	 filter= new FileNameExtensionFilter(
	 "JPG&GIF Images","jpg","gif");
	 chooser.setFileFilter(filter);
	 ���� ������ �����鸸 ���̰� ����ó���Ѱ��̴�
	 */
	public void save(){	//�������� ����ȭ Serializable
		Object o =arr;
		File file = null;
		JFileChooser chooser = new JFileChooser();//���丮�� ���� �����Ҽ� �ִ� ���
		int result= chooser.showSaveDialog(null);//�����ȭ����,�����ȭ����
		if(result==JFileChooser.APPROVE_OPTION){//�����ϰ� �������ٸ� APPROVE_OPTION,��� CANCEL_OPTION,���� ERROR_OPTION
			file = chooser.getSelectedFile();//������ ���� ���ϰ�ü�� ��ȯ ,�̸��� �ۼ��Ѱ��� file�� ����
		}
		if(file!=null){
			try{
			FileOutputStream fos = new FileOutputStream(file);//���� ��� �� ����
			ObjectOutputStream oos = new ObjectOutputStream(fos);//fos�� �������ڷ� ����Ͽ� ���Ͻ�Ʈ���� ��ü��Ʈ���� ����
			oos.writeObject(o);//���Ϸ� ���� Ŭ������ ��ü�� ����
			oos.close();//�۾�����
			fos.close();//����
			} catch(IOException e){}
		}		
	}
	
	public void load(){	//���Ͽ��� ������ȭ Serializable
		try{
			File file = null;
			JFileChooser c= new JFileChooser();
			int result = c.showOpenDialog(null);
			if(result==JFileChooser.APPROVE_OPTION){
				file = c.getSelectedFile();//JFileChooser���� ������ ������ file �� ����
				FileInputStream fis = new FileInputStream(file);//���Ϸ� ���� ���� ��ǲ��Ʈ�� ����
				ObjectInputStream ois = new ObjectInputStream(fis);//fis�� ���� ������Ʈ ��Ʈ���� ����
				Object o = ois.readObject();//��ü�� �д´�
				arr=(List<CompanyBasics>) o;//List<CompanyBascis>���·� ��ü�� ĳ��Ʈ�Ѵ�
				ois.close();//������Ʈ��Ʈ���� �ݱ�
				fis.close();
			}
		} catch(IOException | ClassNotFoundException e){ e.printStackTrace(); }
	}
	
	
}