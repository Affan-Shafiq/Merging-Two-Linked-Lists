﻿#include <iostream>


using namespace std;


struct Node {
    int data;
    Node* next;
};


class LinkedList {
        private:
            Node* head;
        public:
            LinkedList() {
                        head = NULL;
                } 
        
            void insert(int value) {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = NULL;
                if ((!head) || (head->data >= value)) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    Node* current = head;
                    while ((current->next) && (current->next->data < value)) {
                        current = current->next;
                    }
                    newNode->next = current->next;
                    current->next = newNode;
                }
            }
        
            static LinkedList mergeSortedLists(const LinkedList& list1, const LinkedList& list2) {
                LinkedList mergedList;
                Node* current1 = list1.head;
                Node* current2 = list2.head;
        
                while (current1 || current2) {
                    if (!current1) {
                        mergedList.insert(current2->data);
                        current2 = current2->next;
                    } else if (!current2) {
                        mergedList.insert(current1->data);
                        current1 = current1->next;
                    } else {
                        if (current1->data < current2->data) {
                            mergedList.insert(current1->data);
                            current1 = current1->next;
                        } else {
                            mergedList.insert(current2->data);
                            current2 = current2->next;
                        }
                    }
                }
                return mergedList;
            }
        
            void displayNodes() {
                Node* current = head;
                while (current) {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
};


int main() {
    LinkedList l1, l2;
    l1.insert(1);
    l1.insert(3);
    l1.insert(7);
    
        l2.insert(2);
    l2.insert(4);
    l2.insert(5);
    
    LinkedList mergedList = LinkedList::mergeSortedLists(l1, l2);
    mergedList.displayNodes();
    return 0;
}
