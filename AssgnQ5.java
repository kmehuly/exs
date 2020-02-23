/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assgnq5;
import java.util.*;


/**
 *
 * @author mehul
 */
interface Test{
    public void getTest1Marks(int l);
    public void getTest2Marks(int m);
}
interface Assignment{
    public void getAssingment1marks(int n);
    public void getAssingment2marks(int o);
}
public class AssgnQ5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Internal marks lodging...");
		
		int t1, t2, a1, roll, a2, choice = 1;
		String name;
        Scanner cin = new Scanner(System.in);
        while(choice != 0){
		    System.out.println("Enter the Name of the student :  ");
		    name = cin.nextLine();
		    System.out.println("Enter the roll no. ");
		    roll = cin.nextInt();
		    Internal in = new Internal(name, roll);
		    System.out.println("Enter the Number of marks in test 1 & test 2");
		    t1 = cin.nextInt();
		    //System.out.println("Enter the Number of marks in test 2 ");
		    t2 = cin.nextInt();
		    System.out.println("Enter the Number of marks in Assignment 1 & 2");
		    a1 = cin.nextInt();
		    //System.out.println("Enter the Number of marks in Assignment 2 ");
		    a2 = cin.nextInt();
		    in.setInternal(t1, t2, a1, a2);
		    in.display();
		    System.out.println("\nWant to Enter more? 1 for yes, 0 for no ");
		    choice = cin.nextInt();
	    }
    }
    
}
class Student{
    String name;
    int roll;
    Student(String name, int roll){
        this.name = name;
        this.roll = roll;
    }
}

class Internal extends Student implements Assignment, Test{
    int test1, test2, asg1, asg2;
    
    Internal(String name, int roll){
        super(name, roll);
    }
    void setInternal(int t1, int t2, int asg1, int asg2){
        this.getTest1Marks(t1);
        this.getTest2Marks(t2);
        this.getAssingment1marks(asg1);
        this.getAssingment2marks(asg2);
    }
    public void getTest1Marks(int t1){
        this.test1 = t1;
    }
    public void getTest2Marks(int t2){
        this.test2 = t2;
    }

    public void getAssingment1marks(int asg1){
        this.asg1 = asg1;
    }
    public void getAssingment2marks(int asg2){
        this.asg2 = asg2;
    }
    void display(){
        System.out.println("Internal Marks of " + name + ", Roll no. : " + roll);
        System.out.println("Marks in Test 1 : \t" + test1);
        System.out.println("Marks in Test 2 : \t" + test2);
        System.out.println("Marks in Assignment 1 : " + asg1);
        System.out.println("Marks in Assingment 2 : " + asg2);
        int total = test1 + test2 + asg1 + asg2;
        System.out.println("\tTotal marks in Internal : " + total);
    }
    
}


