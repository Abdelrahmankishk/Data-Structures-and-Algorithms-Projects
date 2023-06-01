package com.mycompany.mavenproject4;

public class Stack {
    private class Node{
        String data;
        Node next;        
    }
    Node top;
    
    public boolean isEmpty(){
        if(top == null){
            return true;
        }
        else{return false;}
    }
    
    public void push(String x){
        Node temp = new Node();
        temp.data = x;
        temp.next = top;
        top = temp;
    }
    
    public String top(){
        if(isEmpty()== true){
            return "Stack is empty";
        }
        else{
            return top.data;
        }
    }
    
    public String pop(){
        Node temp = new Node();
        if (isEmpty()== true){
            return "Stack Underflow";
        }
        else{
            temp =top;   
            top = top.next;
            return temp.data;
        }
    }
    
    
}
