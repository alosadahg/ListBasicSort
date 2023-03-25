#include "list.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
/**
 * Your ArrayList must have an initial capacity of 4.
 * If the array is full, allocate an additional capacity of 50% its current size.
 * Example, 4 becomes 6, then 6 becomes 9, so on.
 * If the array reaches less than two-thirds the capacity, reallocate it to 2/3 its size.
 * Example, 9 goes back to 6, 6 goes back to 4.
 * Maintain a minimum capacity of 4.
 * 
 * On the fields:
 * array - holds the pointer to the array itself
 * index - holds the current size, initially zero
 * capacity - holds the current capacity of the array - minimum of 4
 */
class ArrayList : public List { 
    int* array;
    int index;
    int capacity;

    public:
        // CONSTRUCTOR
        ArrayList() {
            array = (int*) malloc(sizeof(int) * capacity);
            index = 0;
            capacity = 4;
        }

        int add(int num) {
            //Reallocate array when size is full
            if(index == capacity) {
                capacity += ceil(capacity*0.50);
                array = (int*) realloc(array, sizeof(int) * capacity);
            }
            array[index] = num;
            index++;
          return index;
        }

        int get(int pos){
            //Find the element inside index pos-1
            for(int i=0; i<index; i++) {
                if(i==pos-1) {
                    return array[i];
                }
            }
          return -1;
        }
        
        int size(){
            return index;
        }

        void swap(int pos1, int pos2){
            //Swap indices pos1 & pos2 (subtract 1 to get index)
            int temp = array[pos1-1];
            array[pos1-1] = array[pos2-1];
            array[pos2-1] = temp;
        }

        // WARNING! Do not modify the print method.
        // Doing so will nullify your score for this activity.
        void print() {
            cout << "[";
            for (int i = 0; i < capacity; i++) {
                if (i < index) {
                    cout << *(array + i);
                } else {
                    cout << "?";
                }
                
                if (i != capacity - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
};