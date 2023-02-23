package careapExampleSwing;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridLayout;

import java.awt.event.*;



import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MainForm extends JFrame implements ActionListener {

	private JTextField nameT, rankT, bpT, epT;
	private JButton insertBtn, printBtn,modifyBtn,deleteBtn, searchBtn, saveBtn, loadBtn,upgradeBtn;
	private Company company;
	private JTextArea ta;
	public MainForm() {
		
		super("CARE LAB ��� ���� ���α׷�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//������ ������ ������ ���α׷� ����
		Container contentPane=getContentPane();//����Ʈ ���� �˾Ƴ���.
		contentPane.setLayout(new FlowLayout());
		//������ ��� �ֱ�
		
		JPanel nameP = new JPanel();
		JLabel nameL = new JLabel("**�̸�**");
		nameT = new JTextField(10);
		nameP.add(nameL);
		nameP.add(nameT);
		
		
		JPanel rankP = new JPanel();
		JLabel rankL= new JLabel("**����**");
		rankT=new JTextField(10);
		rankP.add(rankL);
		rankP.add(rankT);
		
		JPanel bpP = new JPanel();
		JLabel bpL=new JLabel("*�⺻��*");
		bpT=new JTextField(10);
		bpP.add(bpL);
		bpP.add(bpT);
		
		JPanel epP = new JPanel();
		JLabel epL=new JLabel("**����**");
		epT=new JTextField(10);
		epP.add(epL);
		epP.add(epT);
		
	
		JPanel leftP = new JPanel();
		leftP.setLayout(new GridLayout(4, 1, 3, 4));
		leftP.add(nameP);
		leftP.add(rankP);
		leftP.add(bpP);
		leftP.add(epP);
		
		company=new CompanyCARELAB();//�ȿ� ������� �ֱ�
		ta = new JTextArea(10, 53);//�ʵ�â ũ��
		boolean cham=true;//������
		
		JScrollPane jsp = new JScrollPane(ta); // â ��ũ��
		JPanel rightP = new JPanel();
		rightP.setLayout(new GridLayout(1, 1));
		rightP.add(jsp);
		
		// ���� + ������ */
		
		JPanel centerP = new JPanel();
		centerP.setLayout(new GridLayout(1, 2));
		centerP.add(leftP);
		centerP.add(rightP);
	
		
		insertBtn = new JButton("���");
		printBtn = new JButton("���޼��������");	
		modifyBtn = new JButton("����");
		deleteBtn = new JButton("����");
		searchBtn = new JButton("�˻�");
		saveBtn = new JButton("��������");
		loadBtn = new JButton("���Ͽ���");
		upgradeBtn=new JButton("������ ����");
		
		JPanel btnP = new JPanel();
		btnP.setLayout(new FlowLayout(FlowLayout.CENTER,10,20)); 
		btnP.add(insertBtn);
		btnP.add(printBtn);
		btnP.add(modifyBtn);
		btnP.add(deleteBtn);
		btnP.add(searchBtn);		
		btnP.add(saveBtn);
		btnP.add(loadBtn);
		btnP.add(upgradeBtn);
		

		
		Container c = getContentPane();//��ü ������Ʈ
		c.add("West", leftP);//������ ��������
		c.add("East", rightP);
		c.add("BOTTON",btnP);
		
		setBounds(300, 500, 790, 300);
		setVisible(true);
	}
	
		
	public void event() {
		insertBtn.addActionListener(this);
		modifyBtn.addActionListener(this);
		deleteBtn.addActionListener(this);
		printBtn.addActionListener(this);//��������� ���
		searchBtn.addActionListener(this);	
		saveBtn.addActionListener(this);
		loadBtn.addActionListener(this);	
		upgradeBtn.addActionListener(this);
	}


	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == insertBtn) {	//����
			
			
			int findIndex = company.findIndex(nameT.getText());
			if (findIndex != -1) {
				JOptionPane.showMessageDialog(this, "�ش����� �����մϴ�.");
				return ;
			}
			
			// TextField ���� �����´�.  
			CompanyBasics flash=new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()));

			CompanyBasics dto = new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()),flash.getTaxRate(),flash.getBasicSalary());

			
			
			
			company.saveWorker(dto);
			company.print(ta);
			
			JOptionPane.showMessageDialog(this, "��� �Ϸ�");
			nameT.setText("");
			rankT.setText("");
			bpT.setText("");
			epT.setText("");
		}
		else if (e.getSource() == upgradeBtn)
		{
		//	if(cham!=)
				
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
		}
		else if (e.getSource() == modifyBtn){  //����
			// TextField ���� �����´�. 
			CompanyBasics flash=new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()));

			CompanyBasics dto = new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()),flash.getTaxRate(),flash.getBasicSalary());

			int sw = company.modify(dto);
			if(sw == 0) { JOptionPane.showMessageDialog(this, "������ �̸��� �������� �ʽ��ϴ�."); return;}
			else {
				company.print(ta);
				JOptionPane.showMessageDialog(this, "���� �Ϸ�");
			}
			nameT.setText("");
			rankT.setText("");
			bpT.setText("");
			epT.setText("");		
		}
		
		else if(e.getSource() == deleteBtn) {	// ����
			// �����ϰ��� �ϴ� ���� ã�´� 
			CompanyBasics dto = new CompanyBasics();
			String num = JOptionPane.showInputDialog(this, "������ �̸��� �Է��ϼ���.");
			if(num == null || num.equals("")) return;
		
			int sw = company.delete(dto, num);
			if(sw == 1) {
				company.print(ta);
				JOptionPane.showMessageDialog(this, "���� �Ϸ�");			
			}
			if(sw == 0) JOptionPane.showMessageDialog(this, "������ ������ �����ϴ�.");
		}
		
		else if(e.getSource() == printBtn) {	// ��������� ���
			// table�� �����͸� �������� model���� �����͸� �־��ش�. 
			// table�� ���� �����͸� ������ �� ���� ���� �� �߰��� model���� �̷������ ����
			company.compare(ta);
			
		}
		else if(e.getSource() == searchBtn) {	// �й��˻�
			// impl���� ����� ���� ���� �� dialog�� frame �ۿ� �����Ǳ� ������ ���⼭ �����.
			 String num = JOptionPane.showInputDialog(this, "�˻��� �̸��� �Է��ϼ���");
			 if(num == null || num.equals("")) return; // ������ ������
			 
			 int sw = company.search(ta, num);
			 // ã���� �ϴ� num�� model�� �Բ� �Ѱ����� 
			 // ����� table�� �Ѹ� ���̱� ������ model ���� ������ ����
			 if(sw == 0) JOptionPane.showMessageDialog(this, "ã�� ������ �����ϴ�");
		}
		else if(e.getSource() == saveBtn) {	//��������
			company.save();
			}
		else if(e.getSource() == loadBtn) {	//���Ͽ���
			company.load();
			company.print(ta);
			// �ҷ��� ���� ������ print()�� �ѷ��ش�. 
		}
		/*else if(e.getSource() == sortBtn) {	// ���������
			// �������� ��������
			score.sort(model);			
		}  
		} */
		}
	}
	

