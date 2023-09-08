#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node* next;
    int value;
    string key;
    Node(string key,int value)
    {
        this->value=value;
        this->key=key;
        next=nullptr;
    }
};
class HashTable
{  
    static const int size=7;
    Node* dataMap[size];
    public:
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<i<<':'<<endl;
            if(dataMap[i])
            {
                Node* temp=dataMap[i];
                while(temp)
                {
                    cout<<" {"<<temp->key<<", "<<temp->value<<"} "<<endl;
                    temp=temp->next;
                }
            }
        }
    }
    int hash(string key)
    {
        int hash=0;
        for(int i=0;i<key.length();i++)
        {
            int askii=int(key[i]);
            hash=(hash+askii*23)%7;
        }
        return hash;
    }
    void set(string key,int value)
    {
        int index=hash(key);
        Node* newNode=new Node(key,value);
        if(dataMap[index]==nullptr)
        {
            dataMap[index]=newNode;
        }
        else
        {
            Node* temp=dataMap[index];
            while (temp->next)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            
        }
    }
    int get(string key)
    {
        cout<<endl<<"heres the key and its value: "<<key<<", ";
        int index=hash(key);
        Node* temp=dataMap[index];
        while (temp)
        {
            if(temp->key!=key)
            {
                temp=temp->next;
            }
            else
            {
                return temp->value;
            }
        }   
        return 0;
        
    }
    vector<string> keys()
    {
        vector<string> keyval;
        for(int i=0;i<size;i++)
        {
            Node*temp=dataMap[i];
            {
                while(temp)
                {
                    keyval.push_back(temp->key);
                    temp=temp->next;
                }
            }
        }
        return keyval;
    }
};
int main()
{
    HashTable* h=new HashTable();
    h->set("prosche",6);
    h->set("mecleren",10);
    h->set("ferrari",12);
    h->set("tata",3);
    h->set("bmw",6);
    h->display();
    cout<<h->get("prosche");
    cout<<endl<<endl;
    vector<string> mykeys=h->keys();
    for(auto i:mykeys)
    {
        cout<<"key: "<<i<<endl;
    }
    return 0;
}