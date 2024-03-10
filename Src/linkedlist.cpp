#include "linkedlist.h"

Node::Node() {
    data = 0;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int data, Node* next, Node* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}

Linked::Linked() {
    head = nullptr;
    tail = nullptr;
}


void Linked::insert(int data)
{

    if(tail && tail->next==nullptr)
    {
        Node* n=new Node(data);

        tail->next = n;
        n->prev = tail;
        tail = n;
        
    }

    else 
    {
        Node* n=new Node(data);

        head=n;
        tail=n;

        
    }
    
}

void Linked::remove(int data)
{
    bool found=false;
    if(tail!=nullptr  && tail->next==nullptr)
    {
        Node* temp=head;

        while(temp->next != nullptr)
        {
            if(temp->data==data)
            {

                found=true;
                break;
            }
            temp=temp->next;
        }
        if(found==true && temp->next!=nullptr && temp->prev!=nullptr)
        {

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        else if(found &&temp->prev==nullptr)
        {
            head=temp->next;

        }


        else if(found && temp->next==nullptr)
            tail=temp->prev;
    }
}

void Linked::printList()
{
    Node* temp=head;
    
    while (temp!=nullptr)
    {
        std::cout<<temp->data<<std::endl;
        temp=temp->next;
    }
    
   
}

bool Linked::search(int data)
{
    if(!isEmpty())
    {
        Node* temp=head;
        while(temp)
        {
            if(temp->data==data)
                return true;
            temp=temp->next;
        }
    }
    return false;
}

int Linked::getDataFromIndex(int index)
{
    if(!isEmpty() && index < length())
    {
        int i=0;
        Node* temp=head;
        while(temp)
        {
            if(index==i)
                return temp->data;

            temp=temp->next;
            i++;
        }
        

    }
    return -1;
}

bool Linked::isEmpty()
{
    return (!tail);
}
int Linked::length()
{
    if(!isEmpty())
    {
        Node* temp=head;
        int i=0;
        while(temp)
        {
            i++;
            temp=temp->next;
        }
        
        return i;
    }
    return 0;
}

int Linked::findIndex(int data)
{
    if(!isEmpty())
    {
        Node* temp=head;
        int i=0;
        while(temp){
            if(temp->data==data)
                return i;
            temp=temp->next;
            i++;
        }
    }
    return -1;
}

void Linked::insertAtIndex(int index,int data)
{
    if(!isEmpty())
    {
        int i=0;
        int length=this->length();
        Node* temp=head;
        while(i!=index)
        {
            temp=temp->next;
            i++;
        }
        if(i!=0 && index!=length)
        {
            Node* n=new Node(data,temp,temp->prev);
            n->prev->next=n;
            n->next->prev=n;
        }

        else if(index==length)
        {
            Node* n=new Node(data,nullptr,tail);
            n->prev->next=n;
            tail=n;

        }

        else if(i==0)
        {
            Node* n=new Node(data,temp,nullptr);
            n->next->prev=n;
            head=n;
        }


    }
}

Linked::~Linked()
{
    if(!isEmpty())
    {
        Node* temp=head;
        while(temp && temp->next)
        {
            temp=temp->next;
            delete temp->prev;
        }
        if(tail)
         delete tail;
    }
}