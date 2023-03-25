#include "arraylist.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// WARNING! Do not modify this struct!
// Doing so will nullify your score for this activity.
struct node {
    int element;
    node* next;
};

/**
 * This implementation is of a Singly-Linked List.
 * Feel free to add helper methods. You might want the create_node helper method.
 */ 
class LinkedList : public List {
    node* head;
    node* tail;
    int index;

    node* create_node(int num) {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->element = num;
        newNode->next = NULL;
      return newNode;
    }

    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
            index = 0;
        }

        int add(int num) {
            //Create node and increment index
            node* addNode = create_node(num);
            index++;
            if(index==1) {
                head = addNode;
                tail = addNode;
                return index;
            } 
            //If linkedlist has existing nodes, add to the end of the linkedlist and reallocate tail
            tail->next = addNode;
            tail = addNode;
          return index;
        }
        
        int get(int pos) {
            //Find the node in pos
            int i=1;
            node* curr = head;
            while(curr) {
                //Find the element in the node
                if(i==pos) {
                    return curr->element;
                }
                //If not found yet, continue to next node and increment index
                curr = curr->next;
                i++;
            }
          return -1;
        }
        
        int size() {
            return index;
        }
        
        void swap(int pos1, int pos2) {
            node* curr = head;
            //Declare the nodes in pos1 & pos2
            node* pos1node;
            node* pos2node;
            //Declare the preceeding nodes
            node* pos1prev = NULL;
            node* pos2prev = NULL;
            int i=1;
            while(curr) {
                //Assign current node to the others if corresponding indices are found
                if(i==pos1-1) 
                    pos1prev = curr;
                if(i==pos2-1) 
                    pos2prev = curr;
                if(i==pos1) 
                    pos1node = curr;
                if(i==pos2) 
                    pos2node = curr;
                //Iterate through the entire linked list
                curr = curr->next;
                i++;
            }
            //If previous node is not null, set the prevnode->next to the other node
            if(pos2prev) {
                pos2prev->next = pos1node;
            } 
            if(pos1prev) { 
                pos1prev->next = pos2node;
            }
            //If previous node is null, then pos1 | pos2 is the head
            if(pos1prev == NULL) {
                head = pos2node;
            } else if(pos2prev == NULL) {
                head = pos1node;
            }
            //Swap the next nodes of the pos1 & pos2 nodes
            node* temp = pos1node->next;
            pos1node->next = pos2node->next;
            pos2node->next = temp;
            //If node->next is null, then node is now the tail
            if(pos1node->next == NULL) {
                tail = pos1node;
            } else if(pos2node->next == NULL) {
                tail = pos2node;
            }
        }
        
        // WARNING! Do not modify this method below!
        // Doing so will nullify your score for this activity.
        void print() {
            node* currnode = head;
            if (head == NULL && tail == NULL) {
                cout << "(empty)";
                return;
            }
            while (true) {
                cout << currnode->element;
                if (currnode == tail) {
                    cout << endl;
                    return;
                }
                cout << " -> ";
                currnode = currnode->next;
            }
        }
};