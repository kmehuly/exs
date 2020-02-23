/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assgnq4;
import java.util.Scanner;

/**
 *
 * @author mehul
 */
public class AssgnQ4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String name;
        double units;
        double bill=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter customer name:");
        name=sc.nextLine();
        System.out.println("Enter no. of units consumed:");
        units=sc.nextDouble();
        if(units<=100){
            bill=units*5;
        }
        else if(units>100 && units<=500){
            bill=(100*5)+(units-100)*2.36;
        }
        else if(units>500 && units<=2000){
            bill=(100*5)+(400*2.36)+(units-500)*3.5;
        }
        else if(units>2000){
            bill=(100*5)+(400*2.36)+(1500*3.5)+(units-2000)*5.09;
        }
        System.out.println("  -------Electricity Bill-------");
        System.out.println("--------------------------------------");
        System.out.println("Bill Id:"+((bill*units)-500));
        System.out.println("Customer Name:"+name);
        System.out.println("Units consumed:"+units);
        System.out.println("Bill Amount:Rs "+bill);
        
    
}
