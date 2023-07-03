#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

class LinkedList{
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    // function prototype for inserting node at end of list
    void insertNode(int);
    // function prototype to print entire list
    void printList();
    // function prototype to delete node at position
    void deleteNode(int);

};

void LinkedList :: deleteNode(int pos){
    Node *tmp = head;
    Node *cur = NULL;
    int listLen = 0;
    
    if(head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    //get length of linked list
    while(tmp != NULL){
        tmp = tmp->next;
        listLen++;
    }
    //check if the pos is greater than list length
    if(listLen < pos){
        cout << "Index out of range" << endl;
        return;
    }

    tmp = head;
    
    //if pos is equal to 0 delete at head
    if(pos == 1){
        head = head->next;
        delete tmp;
        return;
    }
    //navigate to position
    while(pos-- > 1){
        cur = tmp;
        tmp = tmp->next;
    }

    cur->next = tmp->next;

    delete tmp;
} 

void LinkedList :: insertNode(int data){
    Node* newNode = new Node(data);
    
    if(head == NULL){ //if head is null make the newNode the head of the list
        head = newNode;
        return;
    }

    //create a tmp var
    Node* tmp = head;
    //traverse to end of list
    while(tmp->next != NULL){
        // update curent tmp value
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void LinkedList::printList(){
    Node* tmp = head;

    if(head == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    int i = 0;
    while(tmp != NULL){
        cout << "At Index " << i << ": " << tmp->data << endl;
        tmp = tmp->next;
        i++;
    }
}