package com.mycompany.datastractureproject;

public class Stack {
    private class Node{
        char data;
        Node next;        
    }
    Node top;
    
    public boolean isEmpty(){
        if(top == null){
            return true;
        }
        else{return false;}
    }
    
    public void push(char x){
        Node temp = new Node();
        temp.data = x;
        temp.next = top;
        top = temp;
    }
    
    public char top(){
        if(isEmpty()== true){
            System.out.println("Stack is empty");
            return 'N';
        }
        else{
            return top.data;
        }
    }
    
    public char pop(){
        Node temp = new Node();
        if (top == null){
            System.out.println("Stack Underflow");
            return 'N';
        }
        else{
            temp =top;   
            top = top.next;
            return temp.data;
        }
    }
    
    
}
