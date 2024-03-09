#include <iostream>
#include "linkedlist.h"

int main() {
    Linked ll;
    ll.insert(10);
    ll.insert(12);
    ll.insert(13);
    ll.insert(14);
    
    if (ll.search(13))
        std::cout << ll.getDataFromIndex(2) << std::endl;
   
    ll.insertAtIndex(4, 15);
    ll.printList();

    return 0;
}
