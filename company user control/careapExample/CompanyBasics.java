package careapExample;

import java.io.Serializable;

public class CompanyBasics implements Serializable {
    private String name; //직원의 이름
    private String jobRank; //직원의 직급
    private int basicSalary; //직원의 기본급
    private int bonus; //직원의 수당
    private double taxRate;
    private int monthSalary;
    
    public CompanyBasics() {
    	
    }
    public CompanyBasics(String name,String jobRank,int basicSalary,int bonus,double taxRate,int monthSalary)
    {
    	this.name=name;
    	this.jobRank=jobRank;
    	this.basicSalary=basicSalary;
    	this.bonus=bonus;
    	this.taxRate=taxRate;
    	this.monthSalary=monthSalary;
    }
    public int getMonthSalary() {
        monthSalary = (int)((basicSalary + bonus)*(1.0 - taxRate)); //월급 구하는 공식
        return monthSalary;
    }
    
    public double getTaxRate() { // 기본급에 따른 세율 
        if (basicSalary <= 2000000) {
            taxRate = 0.01;
            return taxRate;
        } else if (basicSalary > 2000000 && basicSalary <= 4000000) {
            taxRate = 0.02;
            return taxRate;
        } else {
            taxRate = 0.03;
            return taxRate;
        }
    }
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getJobRank() {
        return jobRank;
    }
    public void setJobRank(String jobRank) {
        this.jobRank = jobRank;
    }
    public int getBasicSalary() {
        return basicSalary;
    }
    public void setBasicSalary(int basicSalary) {
        this.basicSalary = basicSalary;
    }
    public int getBonus() {
        return bonus;
    }
    public void setBonus(int bonus) {
        this.bonus = bonus;
    }    
}
 
