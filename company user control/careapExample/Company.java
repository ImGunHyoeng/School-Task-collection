package careapExample;

import java.util.ArrayList;

public interface Company {
	//�Է�
	public void saveWorker();//���� �Ѹ��� �� ���� �޼ҵ�
	//����
	public void modify();//Ư�� ������ ����, �⺻��, ���� ���� �޼ҵ�
	public void search();//�̸� ������ �ش� ���� ���� ���� ã��& �ش� �� ��� �޼ҵ�
	//���
	public void delete();//��µǴ� �������� Ÿ��Ʋ ��� �޼ҵ�
	public void output();//��� ������ ���� ��� �޼ҵ�
	public void fileSave();
	public ArrayList<careapExampleSwing.CompanyBasics> fileRead();
	public void upgrade(String Rank);
}
