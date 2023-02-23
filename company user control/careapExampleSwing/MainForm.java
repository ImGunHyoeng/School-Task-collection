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
		
		super("CARE LAB 사원 관리 프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//프레임 윈도우 닫으면 프로그램 정지
		Container contentPane=getContentPane();//컨텐트 팬을 알아낸다.
		contentPane.setLayout(new FlowLayout());
		//게임평가 요소 넣기
		
		JPanel nameP = new JPanel();
		JLabel nameL = new JLabel("**이름**");
		nameT = new JTextField(10);
		nameP.add(nameL);
		nameP.add(nameT);
		
		
		JPanel rankP = new JPanel();
		JLabel rankL= new JLabel("**직급**");
		rankT=new JTextField(10);
		rankP.add(rankL);
		rankP.add(rankT);
		
		JPanel bpP = new JPanel();
		JLabel bpL=new JLabel("*기본급*");
		bpT=new JTextField(10);
		bpP.add(bpL);
		bpP.add(bpT);
		
		JPanel epP = new JPanel();
		JLabel epL=new JLabel("**수당**");
		epT=new JTextField(10);
		epP.add(epL);
		epP.add(epT);
		
	
		JPanel leftP = new JPanel();
		leftP.setLayout(new GridLayout(4, 1, 3, 4));
		leftP.add(nameP);
		leftP.add(rankP);
		leftP.add(bpP);
		leftP.add(epP);
		
		company=new CompanyCARELAB();//안에 구성요소 넣기
		ta = new JTextArea(10, 53);//필드창 크기
		boolean cham=true;//참거짓
		
		JScrollPane jsp = new JScrollPane(ta); // 창 스크롤
		JPanel rightP = new JPanel();
		rightP.setLayout(new GridLayout(1, 1));
		rightP.add(jsp);
		
		// 왼쪽 + 오른쪽 */
		
		JPanel centerP = new JPanel();
		centerP.setLayout(new GridLayout(1, 2));
		centerP.add(leftP);
		centerP.add(rightP);
	
		
		insertBtn = new JButton("등록");
		printBtn = new JButton("월급순으로출력");	
		modifyBtn = new JButton("수정");
		deleteBtn = new JButton("삭제");
		searchBtn = new JButton("검색");
		saveBtn = new JButton("파일저장");
		loadBtn = new JButton("파일열기");
		upgradeBtn=new JButton("올해의 인재");
		
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
		

		
		Container c = getContentPane();//전체 컴포넌트
		c.add("West", leftP);//모든것을 왼쪽으로
		c.add("East", rightP);
		c.add("BOTTON",btnP);
		
		setBounds(300, 500, 790, 300);
		setVisible(true);
	}
	
		
	public void event() {
		insertBtn.addActionListener(this);
		modifyBtn.addActionListener(this);
		deleteBtn.addActionListener(this);
		printBtn.addActionListener(this);//수당순으로 출력
		searchBtn.addActionListener(this);	
		saveBtn.addActionListener(this);
		loadBtn.addActionListener(this);	
		upgradeBtn.addActionListener(this);
	}


	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == insertBtn) {	//삽입
			
			
			int findIndex = company.findIndex(nameT.getText());
			if (findIndex != -1) {
				JOptionPane.showMessageDialog(this, "해당사원이 존재합니다.");
				return ;
			}
			
			// TextField 값을 가져온다.  
			CompanyBasics flash=new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()));

			CompanyBasics dto = new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()),flash.getTaxRate(),flash.getBasicSalary());

			
			
			
			company.saveWorker(dto);
			company.print(ta);
			
			JOptionPane.showMessageDialog(this, "등록 완료");
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
				great="사원";
			else if(i==2)
				great="대리";
			else if(i==3)
				great="과장";
			else if(i==4)
				great="부장";
			company.upgrade(great);
		}
		else if (e.getSource() == modifyBtn){  //수정
			// TextField 값을 가져온다. 
			CompanyBasics flash=new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()));

			CompanyBasics dto = new CompanyBasics(nameT.getText(),rankT.getText(), Integer.parseInt(bpT.getText()),Integer.parseInt(epT.getText()),flash.getTaxRate(),flash.getBasicSalary());

			int sw = company.modify(dto);
			if(sw == 0) { JOptionPane.showMessageDialog(this, "동일한 이름이 존재하지 않습니다."); return;}
			else {
				company.print(ta);
				JOptionPane.showMessageDialog(this, "수정 완료");
			}
			nameT.setText("");
			rankT.setText("");
			bpT.setText("");
			epT.setText("");		
		}
		
		else if(e.getSource() == deleteBtn) {	// 삭제
			// 삭제하고자 하는 값을 찾는다 
			CompanyBasics dto = new CompanyBasics();
			String num = JOptionPane.showInputDialog(this, "삭제할 이름을 입력하세요.");
			if(num == null || num.equals("")) return;
		
			int sw = company.delete(dto, num);
			if(sw == 1) {
				company.print(ta);
				JOptionPane.showMessageDialog(this, "삭제 완료");			
			}
			if(sw == 0) JOptionPane.showMessageDialog(this, "삭제할 정보가 없습니다.");
		}
		
		else if(e.getSource() == printBtn) {	// 수당순으로 출력
			// table에 데이터를 넣으려면 model에다 데이터를 넣어준다. 
			// table은 직접 데이터를 수정할 수 없고 수정 및 추가는 model에서 이루어지기 때문
			company.compare(ta);
			
		}
		else if(e.getSource() == searchBtn) {	// 학번검색
			// impl에서 물어보면 위와 같이 또 dialog가 frame 밖에 생성되기 때문에 여기서 물어본다.
			 String num = JOptionPane.showInputDialog(this, "검색할 이름을 입력하세요");
			 if(num == null || num.equals("")) return; // 없으면 나가기
			 
			 int sw = company.search(ta, num);
			 // 찾고자 하는 num을 model과 함께 넘겨전다 
			 // 결과를 table에 뿌릴 것이기 때문에 model 값을 가지고 간다
			 if(sw == 0) JOptionPane.showMessageDialog(this, "찾는 정보가 없습니다");
		}
		else if(e.getSource() == saveBtn) {	//파일저장
			company.save();
			}
		else if(e.getSource() == loadBtn) {	//파일열기
			company.load();
			company.print(ta);
			// 불러온 파일 내용을 print()로 뿌려준다. 
		}
		/*else if(e.getSource() == sortBtn) {	// 성적순출력
			// 총점으로 내림차순
			score.sort(model);			
		}  
		} */
		}
	}
	

