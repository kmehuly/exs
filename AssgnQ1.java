/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assgnq1;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Random;
/**
 *
 * @author mehul
 */
public class AssgnQ1 {
    public static void main(String[] args) {
        // TODO code application logic here
    try {
        FileWriter myWriter = new FileWriter("filename.txt");
        int lol;
        Random r = new Random();
        for(int i=0;i<20;i++){
            lol = r.nextInt(100);
            myWriter.write(" "+String.valueOf(lol));}
        myWriter.close();
        System.out.println("Successfully wrote to the file.");
        Path filepath = Paths.get("filename.txt");
        Scanner sc = new Scanner(filepath);
        List<Integer> integereven = new ArrayList<>();
        List<Integer> integerodd = new ArrayList<>();
        while(sc.hasNext()){
            int lol2 = sc.nextInt();
            if(lol2%2==0)
                integereven.add(lol2);
            else
                integerodd.add(lol2);}
        System.out.println("Even Numbers are :- ");
        System.out.println(integereven);
        System.out.println("Odd Numbers are :- ");
        System.out.println(integerodd);
    }
    catch (IOException e) {
        System.out.println("An error occurred.");
        e.printStackTrace();
    }}}
