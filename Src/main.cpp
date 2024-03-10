#include <iostream>

#include "linkedlist.h"
Linked ll;
bool fail;

std::string getLinkedListString();

void testLinkedList(std::string expected)
{
    if(expected==getLinkedListString())
        std::cout<<"Test Succesfull"<<std::endl;
    else
    {
        std::cout<<"Test Failed!\n";
        std::cout<<"Your Result:"<<getLinkedListString()<<std::endl;
        std::cout<<"Expected:"<<expected<<std::endl;
        fail=true;
    }
        
}

std::string getLinkedListString()
{
    auto temp= ll.getHead();
    std::string res="";
    while(temp)
    {
        res+=std::to_string(temp->data)+",";
        temp=temp->next; 
    }
    return res;
}


int main() {
    fail=false;
    ll.insert(10);
    ll.insert(12);
    ll.insert(13);
    ll.insert(14);
    testLinkedList("10,12,13,14,");

    if(ll.search(13))
    {
        ll.getDataFromIndex(ll.findIndex(13));

    }

    ll.remove(13);
    testLinkedList("10,12,14,");
    ll.insertAtIndex(0,9);
    ll.insertAtIndex(1,11);
    ll.insertAtIndex(3,15);
    ll.insertAtIndex(ll.length(),20);
    testLinkedList("9,11,10,15,12,14,20,");
    if(!fail)
    {
        std::cout<<"All tests were succesfull congratz!!"<<std::endl;
    }

    else
    {
        std::cout<<"Some tests dumped go back and check again!!"<<std::endl;
    }

   

    return 0;
}
