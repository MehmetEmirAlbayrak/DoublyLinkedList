#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node();
    Node(int data);
    Node(int data, Node* next, Node* prev);
};

class LinkedList{
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    Node* getHead(){
        return head;
    }
    void insert(int data);
    void remove(int data);
    void printList();
    bool search(int data);
    int getDataFromIndex(int index);
    void insertAtIndex(int index, int data);
    int findIndex(int data);
    bool isEmpty();
    int length();
    ~LinkedList();
};

#endif
