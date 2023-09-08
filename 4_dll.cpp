#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value=value;
        next=nullptr;
        prev=nullptr;
    }
};
class dll
{
    int length;
    Node* head;
    Node* tail;
    public:
    dll(int value)
    {
        Node* newNdoe=new Node(value);
        head=newNdoe;
        tail=newNdoe;
        length=1;
    }
    void append(int value)
    {
        Node* newNode=new Node(value);
        if(length==0)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        length++;
    }
    void delete_last()
    {
        Node* temp=tail;
        if(length==0)
        {
            return;
        }
        else if(length==1)
        {
            head=nullptr;
            tail=nullptr;
            length--;
        }
        else
        {
            tail=tail->prev;
            tail->next=nullptr;
            length--;
        }
        delete temp;      
    }
    void prepend(int value)
    {
        Node* newNode=new Node(value);
        if(length==0)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
        length++;
    }
    void delete_first()
    {
        Node* temp=head;
        if(length==0)
        {
            return;
        }
        else if(length==1)
        {
            head=nullptr;
            tail=nullptr;
        }
        else
        {
            head=head->next;
            head->prev=nullptr;
        }
        delete temp;
        length--;
    }
    Node* get(int index)
    {
        Node* temp=head;
        if(index<0 || index>length)
        {
            return nullptr;
        }
        if(index<=length/2)
        {
            for(int i=0;i<index;i++)
            {
                temp=temp->next;
            }
            return temp;
        }
        else
        {
            temp=tail;
            for(int i=length-1;i>index;i--)
            {
                temp=temp->prev;
            }
            return temp;
        }
    }
    bool set(int index,int value)
    {
        Node* temp=get(index);
        if(temp)
        {
            temp->value=value;
            return true;
        }
        return false;
    }
    bool insert(int index,int value)
    {
       if (index < 0 || index > length) return false;
    if (index == 0) {
        prepend(value);
        return true;
    }
    if (index == length) {
        append(value);
        return true;
    }
 
    Node* newNode = new Node(value);
    Node* before = get(index - 1);
    Node* after = before->next;
    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;
    length++;
    }
    void delete_node(int index)
    {
        Node* temp=get(index);
        if(index<0 || index>length)
        {
            return;
        }
        else if(index==0)
        {
            return delete_first();
        }
        else if(index==length-1)
        {
            return delete_last();
        }
        else
        {
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
        }
        delete temp;
        length--;
    }
};
int main()
{
    dll l1(1);
    l1.append(2);
    l1.append(3);
    l1.delete_first();
    l1.delete_last();
    l1.prepend(0);
    return 0;
}