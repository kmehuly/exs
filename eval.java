/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package student;

import java.util.Scanner;

/**
 *
 * @author mehul
 */
public class eval {
    Scanner sc=new Scanner(System.in);
    String name;
    double cgpa;
    String enrno;
    String password;
    public void getdata(){
        try{
            System.out.println("Enter name:");
            name=sc.next();
            if(name==" "){
                throw new NameException("InvalidFormat");
            }
            System.out.println("Enter cgpa:");
            cgpa=sc.nextDouble();
            System.out.println("Enter Enrollment No:");
            enrno=sc.next();
            if(!enrno.substring(0,2).equals("BE")){
               throw new NameException("InvalidFormat");
            }
            String s2=enrno.substring(2,4);
            int i=Integer.parseInt(s2);
            if(i<11 || i>20){
                throw new NameException("InvalidFormat");
            }
            String s3=enrno.substring(4,7);
            //char ch=s3.charAt(6);
            //if(Character.isDigit(ch))
              //  throw new NameException("InvalidFormat");
            if(s3.equals("CSU")||s3.equals("ENU")||s3.equals("ECU")||s3.equals("ECU")){
                int j=5;
            }
            else
                throw new NameException("InvalidFormat");
            String s4=enrno.substring(7,10);
            int g=Integer.parseInt(s4);
            if(g<1 || g>250){
                throw new NameException("InvalidFormat");
            }
            System.out.println("Enter password");
            password=sc.next();
            boolean flag1=false;
            boolean flag2=true;
            boolean flag3=true;
            boolean flag4=true;
            boolean flag5=true;
            if(password.length()<8 ){
                flag1=true;
                
            }    
            for(int j=0;j<password.length();j++){
                char v=password.charAt(j);
                if(Character.isUpperCase(v)){
                    flag2=false;
                    
                }
                if(Character.isLowerCase(v)){    
                    flag3=false;
                    
                }    
                if(v=='*'||v=='$'||v=='&'||v=='#'||v=='!'){
                    flag4=false;
                    
                    }
                if(Character.isDigit(v)){
                    flag5=false;
                    
                }
           
            }
            if(flag1==true || flag2==true || flag3==true || flag4==true || flag5==true){
               throw new NameException("InvalidFormat");
            }
       }
        catch(NameException e){
            //System.out.println(e);
            e.printStackTrace();
        }
        catch(NumberFormatException e){
             System.out.println(e);
        }
        catch(Exception e){
             System.out.println(e);
        }
    }
        public void display(){
        System.out.println("---------------------");
        System.out.println("STUDENT DETAILS");
        System.out.println("---------------------");
        System.out.println("Name:"+name);
        System.out.println("CGPA:"+cgpa);
        System.out.println("Enrollment No:"+enrno);
        System.out.println("Password:"+password);
    }
       
    
}
class NameException extends Exception{
    String ex;
    public NameException() {
        ex="";
    }
    NameException(String InvalidFormat){
        ex="InvalidFormat";
    }
    @Override
    public String toString(){
            return ("User Defined Exception:"+ex);
    } 
    
    
}
