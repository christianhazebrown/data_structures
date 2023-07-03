#include <iostream>
#include <linkedList.h>
#include <binary_tree.h>
using namespace std;

int main(int argc, char** argv){
    LinkedList list;

    list.insertNode(1);
    list.insertNode(3);
    list.insertNode(2);
    list.printList();
    list.deleteNode(1);
    cout << " " << endl;
    list.printList();
    return 0;
}