#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node* next;
    Node(int value)
    {
        this->value=value;
        next=nullptr;
    }
};
class Stack
{
    public:
    Node* top;
    int height;
    Stack(int value)
    {
        Node* newNode=new Node(value);
        top=newNode;
        height=1;
    }
    void push(int value)
    {
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        height++;
    }
    int pop()
    {
        Node* temp=top;
        int popedval=temp->value;
        if(top==nullptr)
        {
            return INT_MIN; //smallest number of int possible tho its not working for me
        }
        else
        {
            top=temp->next;
            temp=nullptr;
            height--;
            delete temp;
            return popedval;
        }
    }
};
int main()
{
    Stack s(1);
    s.push(2);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();  
    return 0;
}
