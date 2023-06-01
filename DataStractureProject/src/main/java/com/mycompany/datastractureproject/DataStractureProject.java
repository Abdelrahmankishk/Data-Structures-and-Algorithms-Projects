package com.mycompany.datastractureproject;
import java.util.Scanner;
public class DataStractureProject {

     public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.print("Input: ");
        String infix = x.nextLine();
        
        String postFix = infixToPostfix(infix);
        System.out.println("Postfix = " + postFix);
    }
    public static String infixToPostfix(String infix) {
        Stack myStack = new Stack();
        String postFix = "";
        for (int i = 0; i < infix.length(); i++) {
            char c = infix.charAt(i);
            
            if (Character.isDigit(c)) {
                postFix += c + " ";
            } else if (c == '(') {
                myStack.push(c);
            } else if (c == ')') {
                while (myStack.isEmpty() == false && myStack.top() != '(') {
                    postFix += myStack.pop() + " ";
                }
                myStack.pop(); 
            } else {
                while (myStack.isEmpty() == false && precedence(c) <= precedence(myStack.top())) {
                    postFix += myStack.pop() + " ";
                }
                myStack.push(c);
            }
        }
         while (myStack.isEmpty()== false) {
            postFix += myStack.pop() + " ";
        }
        
        return postFix;
    
    }
     
    public static int precedence(char c) {
        switch (c) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
        return -1;
    }
}
