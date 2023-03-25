#include <iostream>
#include "linkedlist.h"

void bubbleSort(List*);
void selectionSort(List*);
void insertionSort(List*);

/**
 * This activity is focused on using Arrays and Linked Lists as two different
 * implementations of List. It follows that you are only to use the methods of
 * List and not of the specific array or linkedlist.
 */
int main(void) {
    // WARNING! Do not modify main method!
    // Doing so will nullify your score for this activity.
    cout << "Enter type of list: ";
    char li;
    cin >> li;

    List* list;
    if (li == 'A') {
      list = new ArrayList();
    } else {
      list = new LinkedList();
    }

    cout << "Enter number of elements: ";
    int length;
    cin >> length;
    
    int input;
    for (int i = 0; i < length; i++) {
        cout << "Enter element " << i+1 << ": ";
      cin >> input;
      list->add(input);
    }

    cout << "Enter sorting method: ";
    char sym;
    cin >> sym;

    list->print();
      
    switch (sym) {
      case 'B':
        bubbleSort(list);
        break;
      case 'I':
        insertionSort(list);
        break;
      case 'S':
        selectionSort(list);
        break;
    }
    return 0;
};


//Perform two of three sorting algorithms here.
//Reminder: Do not use methods specific to Array or Linked List.
void bubbleSort(List* list) {
    int n = list->size();
    bool swapped = false;
    for(int i=1; i<=n; i++) {
        
        for(int j=1; j<n-i+1; j++) {
            if(list->get(j) > list->get(j+1)) {
                list->swap(j, j+1);
                list->print();
                swapped = true;
            }
        }
        if(!swapped) {
            list->print();
            return;
        }
    }
    
   
};

void selectionSort(List* list) {
    int n = list->size();
    for(int i=1; i<=n; i++) {
        int min=i;
        for(int j=i+1; j<=n; j++) {
            if(list->get(j) < list->get(min)) {
                min = j;
            }
        }
        if(min!=i) {
            list->swap(i, min);
            list->print();
        }
    }
};

void insertionSort(List* list) {
    int n = list->size();
    for(int i=1; i<=n; i++) {
        for(int j=i; j>0; j--) {
            if(list->get(j-1) > list->get(j)) {
                list->swap(j-1, j);
                list->print();
            }
        }        
    }
};