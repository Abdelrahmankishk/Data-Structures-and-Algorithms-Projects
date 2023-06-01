
package com.mycompany.mavenproject4;

public class Mavenproject4 {

    public static void main(String[] args) {
        Stack s1 = new Stack();
        System.out.println(s1.isEmpty());
        System.out.println(s1.pop());
        System.out.println(s1.top());
        s1.push("Programing 2");
        s1.push("Advanced Calclus");
        s1.push("Linear Algebra");
        System.out.println(s1.top());
        s1.push("Programming 1");
        System.out.println(s1.top());
        s1.push("Calclus");
        s1.push("Probability and Statistics 1");
        System.out.println(s1.isEmpty()+ "\n");
        while(s1.isEmpty()!= true){
            System.out.println(s1.pop());
        }
    }
}
