#include <iostream>
#include <exception>

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(){
        data=0;
        next=nullptr;
        prev=nullptr;

    }
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        prev=nullptr;

    }
    Node(int data,Node* next,Node* prev)
    {
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

class Linked{

    private:
    Node* head;
    Node* tail;

    public:
    void insert(int data);
    void remove(int data);
    void printList();
    bool search(int data);
    int getDataFromIndex(int index);
    void insertAtIndex(int data);
    int findIndex(int data);
    bool isEmpty();
    int length();
    ~Linked();




};


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
    if(isEmpty())
    {
        Node* temp=head;
        while(temp)
        {
            if(temp->data==data)
                return true;
        }
    }
    return false;
}

int Linked::getDataFromIndex(int index)
{
    if(isEmpty() && index < length())
    {
        int i=0;
        Node* temp=head;
        while(temp)
        {
            if(index=i)
                return temp->data;

            temp=temp->next;
            i++;
        }
        

    }
    return -1;
}

bool Linked::isEmpty()
{
    return (tail);
}
int Linked::length()
{
    if(isEmpty())
    {
        Node* temp=head;
        int i=0;
        while(temp)
        {
            temp=temp->next;
            i++;
        }
        
        return i;
    }
    return 0;
}

int main()
{
    Linked ll;
    ll.insert(10);

    ll.insert(12);

    ll.insert(13);

    ll.insert(14);
   
    ll.remove(10);

    ll.printList();





}

