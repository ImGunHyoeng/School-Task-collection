package careapExampleSwing;

import java.util.ArrayList;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public interface Company {
	//�Է�
	public void saveWorker(CompanyBasics dto);//���� �Ѹ��� �� ���� �޼ҵ�
	//����
	public int modify(CompanyBasics dto);//Ư�� ������ ����, �⺻��, ���� ���� �޼ҵ�
	public int search(JTextArea ta, String num);//�̸� ������ �ش� ���� ���� ���� ã��& �ش� �� ��� �޼ҵ�
	//���
	public int delete(CompanyBasics dto, String num);//��µǴ� �������� Ÿ��Ʋ ��� �޼ҵ�
	public void save();
	public void print(JTextArea ta);
	public void compare(JTextArea ta);
	public void load();
	public int findIndex(String nameT);
	public void upgrade(String Rank); 
	
}
