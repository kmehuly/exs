/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assgnq3;
import java.util.Scanner;

/**
 *
 * @author mehul
 */
public class AssgnQ3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String vname,reg;
        int j;
        try{
            Scanner sc=new Scanner(System.in);
            System.out.println("Vehicle Name:"); 
            vname=sc.next();
            System.out.println("Vehicle RegNo:");
            reg=sc.nextLine();
            reg+=sc.nextLine();
            sc.close();
            String s2[]=reg.split(" ");
            System.out.println("Details are:");
            System.out.println(vname);
            System.out.println(reg);
            String s1[]=reg.split("-");
            
            if((s1[0].equals("MH")||s1[0].equals("MP")||s1[0].equals("GJ")||s1[0].equals("AP")||s1[0].equals("DL") )&&((s2[0].length()==5) && (s2[1].length()==7)))
            {
                j=5;
            }
            else{
                throw new regException("InvalidFormat");
            }
            
           
        }
        catch(regException e){
            e.printStackTrace(); 
            
        }
    }
}
    class regException extends Exception{
        String name;
        regException(){
            name="";
        }
        regException(String InvalidFormat){
            name="InvalidFformat";
        }
        @Override
        public String toString(){
            return "Reg.Exception:"+name;
        } 
     }
    

