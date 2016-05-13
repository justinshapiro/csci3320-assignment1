// Programming Assignment #1 for CSCI3320 - Advanced Programming
// Written by Justin Shapiro

import java.util.Scanner;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class PA1MD5 {

   public static void md5(int num_string) { 
      for (int i = 0; i < num_string; i++) {
         String no_md5_string = new String("TEST" + Integer.toString(i + 1));
         try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] arr = md.digest(no_md5_string.getBytes()); // ref: Senser, Robert - PA1_MD5_CodeSnippets.txt
            
            StringBuilder md5_string_build = new StringBuilder(); // ref: http://bit.ly/1UUB1Jq
            for (int j = 0; j < arr.length; j++)
               md5_string_build.append(String.format("%02x", arr[j] & 0xff)); 
               // ref: http://bit.ly/20OBWPc, http://bit.ly/1PsKXGn, & Senser, Robert - Lecture3_Day2.pdf (2)
            
            String md5_string = md5_string_build.toString();
            
            if (i == 0 || i == num_string - 1) 
               System.out.println(no_md5_string + " " + md5_string);   
      
         } catch (NoSuchAlgorithmException e) { /* try/catch is just needed to compile */ }
      }
   }
   
   public static void main(String[] args) {
      if (args.length != 0)
         md5(Integer.parseInt(args[0]));
      else
         md5(1);     
   }
}   