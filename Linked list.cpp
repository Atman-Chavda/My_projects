#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
    
};
class ll
{
    Node* head;
    Node* tail;
    int length;
    public:
    ll()
    {
        head=NULL;
        tail=NULL;
    }
    ll(int data)
    {
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        length=1;
    }
    void append(int data)
    {
        Node* newNode=new Node(data);
        if(tail==NULL)
        {
            head=newNode;
            tail=newNode;
            length++;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
            length++;
        }
    }
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void ddelete()
    {
        Node *temp = head;
        Node *pre = head;
        if (length == 0)
            return;
        while (temp->next != nullptr)
        {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        length--;
        if (length == 0)
        {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }
    Node* get(int index)
    {
        if(index<0 || index>length)
        {
            return nullptr;
        }
        Node* temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    bool set(int index,int data)
    {
        Node* temp=head;
        if(index<0 || index>length)
        {
            return false;
        }
        else{
            for(int i=0;i<index;i++)
            {
                temp=temp->next;
            }
            temp->data=data;
            return true;
        }
    }
    bool insert(int index,int data)
    {
        Node* temp=head;
        Node* newNode=new Node(data);
        if(index<0 || index>length)
        {
            return false;
        }
        else{
            for(int i=0;i<index-1;i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            length++;
            return true;
        }
    }
    void deleteNode(int index)
    {
        Node* temp=head;
        Node* pre=head;
        if(index<0 || index>length)
        {
            return;
        }
        
        else
        {
            for(int i=0;i<index;i++)
            {
                pre=temp;
                temp=temp->next;
            }
            pre->next=temp->next;
            temp=nullptr;
            temp->next=nullptr;
            length--;
        }
    }
    void reverse()
    {
        Node* temp=head;
        Node* after=temp->next;
        Node* before=nullptr;
        head=tail;
        tail=temp;
        for(int i=0;i<length;i++)
        {
            after=temp->next;
            temp->next=before;
            before=temp;
            temp=after;
        }
    }
};
int main()
{
    ll l(1);
    l.append(2); 
    l.display();
    l.reverse();
    l.display();
    l.ddelete();
    cout<<endl;
    l.display();
    return 0;
}
