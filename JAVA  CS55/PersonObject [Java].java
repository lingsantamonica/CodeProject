//YUNPENG_LING   
// Feb 20 JUPITER TIME
// test project





import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.util.*;
import java.io.*;

public class TestAPerson
{
	public static void main(String [] args)
	{
		/*
		JFrame win = new JFrame();
		win.setSize(500,400);
		win.setVisible(true);
		*/
		Student st = new Student("Tony","Jones","888-11-1111",50,"Tony@eng.edu",3.0,"88888");
		//st.setFName("Joe");
	//	st.setLName("Baker");
	    APerson x = st;
		
		
	
	
	    if( x instanceof Student)
		System.out.println("GPa:"+((Student)x).getGPA());
		//APerson x = new APerson();
		System.out.println("====>>>"+APerson.getCount());
		
		
		APerson p3 = 
		new APerson("Tom","Jones","111-11-1111",60,"Tom@eng.edu");
		MyIO.display(p3.toString());
		APerson p1 = new APerson("Lisa","Smith","222-22-2222",21,"Lisa@heaven.com");
	    APerson p2 = new APerson("Jack","Smith","333-22-2222",45,"Jack@heaven.com");
	    p2.marriedTo(p1);
	    MyIO.display(p1.toString() + p2.toString());
	    p3.marriedTo(p1);
		
		
		
		
		p2.divorceFrom(p1);
		p3.marriedTo(p1);MyIO.display(p3.toString());
		System.out.println("====>>>"+APerson.getCount());
	    p3.divorceFrom(p1);
		
		st.marriedTo(p1);
		MyIO.display(st.toString());
	
	}
	
}

interface Driver
{
   public String driverType();
   
	
}



class APerson extends Object implements Driver
{
	private String fName;
	private String lName;
	private String sSN;
	private int age;
	private String eMail;
	private APerson hw;
	private static int count;
	
	// designated constructor
	
	public APerson(String fName,String ln, String s,int a,String e)
	{
		this.fName = fName; lName=ln; sSN=s; age=a;
		eMail = e;count++;
	}
	public APerson()
	{
		count++;
	}
	
	public APerson(String fn,String ln, String s)
	{
		
		this(fn,ln,s,0,"");
		
		
	}
	
	public static int getCount()
	{
		return count;
	}
	public String driverType()
	{
		return ( isMarried() ? "Drives Carefully" : "Drives Recklessly");
		
	}
	
	
	public void marriedTo(APerson p1)
	{
		if(this.isMarried()|| p1.isMarried())
		{
			System.out.println("You are already married");
		}
		else
		{
			this.hw = p1;
			p1.hw = this;
			
		}
		
	}
	
	public void divorceFrom(APerson p1)
	{
		if(this.hw == p1 && p1.hw==this)
		{
			this.hw= null;
			p1.hw=null;
		}
		else
		{
			System.out.println("You are not married to each other");
		}
		
	}
	
	
	
	
	public boolean isMarried()
	{
		
		return hw != null;
		/*if( hw != null)
			return true;
		return false;
		*/
	}
	
	
	// methods or API
	
	public void setFName(String fName)
	{
		this.fName = fName;
	}
	public String getFName()
	{
		return fName;
	}
	
	public void setLName(String lName)
	{
		this.lName = lName;
	}
	public String getLName()
	{
		return lName;
	}
	
	public void setSSN(String fName)
	{
		this.sSN = fName;
	}
	public String getSSN()
	{
		return sSN;
	}
	public void setEmail(String fName)
	{
		this.eMail = fName;
	}
	public String getEmail()
	{
		return eMail;
	}
	
	public void setAge(int a)
	{
		age = a;
	}
	public int getAge()
	{
		return age;
	}
	
	
	public String toString()
	{
		return "First Name:"+fName+"\n"
		      +"Last Name:"+lName+"\n"
			  +"SSN:"+sSN+"\n"
			  +"Age:"+age+"\n"
			  +"Email:"+eMail+"\n"
			  +"Marrital Status:"+(isMarried()? "Married":"Available")+"\n"
			  +"Spouse:"+(isMarried()? hw.getFName(): "???")+"\n"
			  +"Driving Status:"+driverType()+"\n";
		
	}
	
}

class Student extends APerson
{
	private String iD;
	private double gpa;
	
	
	public Student()
	{
		super();
	}
	public Student
	(String fN, String lN, String s, int a, String e, double g,String iD)
	{
		super(fN,lN,s,a,e);
		this.iD = iD;
		this.gpa = g;
		
		
	}
	
	
	
	
	
	
	
	public String getID()
	{
		return iD;
	}
	public void setID(String iD)
	{
		this.iD = iD;
	}
	public void setGPA(double g)
	{
		gpa= g;
	}
	public double getGPA()
	{
		return gpa;
	}
	public String toString()
	{
		
		return super.toString()+"ID: "+iD+"\n"
		+"GPA: "+gpa+"\n";
		
		
	}
	
	
	
}






class MyIO{
	
	public static int getInt(String s)
	{
		String strNum = "";
		int n1 = 0;
		boolean ok = false;
		
		while ( !ok )
		{
			try
			{
				strNum = JOptionPane.showInputDialog(s);
		
		        n1 = Integer.parseInt(strNum);
				ok = true;
				
			}catch (Exception ex)
			{
			  JOptionPane.showMessageDialog(null, strNum + " is not integer try again" );	
				
			}
			
			
			
			
		}
		
		
		
		
		return n1;
		
	}
	public static void display(String x, Color bc, Color fc)
	{
		JTextArea jt = new JTextArea(15,20);
		jt.setBackground(bc);
		jt.setForeground(fc);
		Font f = new Font("Times new Roman",
		Font.BOLD+Font.ITALIC,30);
		jt.setFont(f);
		jt.setText(x);
		
		JScrollPane sr = new JScrollPane(jt);
		
		
		JOptionPane.showMessageDialog
		(null,sr);
		
		
	}
	
	
	
	public static void display(String x)
	{
		JTextArea jt = new JTextArea(15,20);
		jt.setBackground(Color.BLACK);
		jt.setForeground(Color.WHITE);
		Font f = new Font("Times new Roman",
		Font.BOLD+Font.ITALIC,30);
		jt.setFont(f);
		jt.setText(x);
		JScrollPane sr = new JScrollPane(jt);
		
		
		JOptionPane.showMessageDialog
		(null,sr);
		
		
		
		
	}
	
	
	
	
}