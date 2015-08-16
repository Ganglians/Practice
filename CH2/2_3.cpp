/* Coder: Juan Chavez
 * Date:  8.11.2015
 * Objective: Delete a node from the middle of a linked list 
 * given only access to that node.
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename t>
struct node {
    t data;
    node *next;
};

template <typename T>
struct lList {
    node<T> *head, *tail;

    //Constructor
    lList():head(NULL) {
    }

    //Add function
    add(T d) {
        //Case1: Empty list
        if(head == NULL) {
            head = new node<T>;
            head->next = NULL;
            tail = head;
            head->data = d;
        }

        //Case2: Non-empty list
        else {
            tail->next = new node<T>;
            tail = tail->next;
            tail->next = NULL;
            tail->data = d;
        }
    }

    //Find node location
    node<T> *find(T d) {
        node<T> *ptr = head;
        while(ptr != NULL) {
            if(ptr->data == d) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    //Delete node in middle given location
    void delMid(T d) {
        node<T> *ptr = find(d);
        if(ptr == NULL) {
            return;
        }
        else {
            while(ptr->next->next != NULL) {
                T tmp1 = ptr->next->data;
                ptr->next->data = ptr->data;
                ptr->data = tmp1;
                ptr = ptr->next;
            }
            node<T> *tmp2 = ptr;
            ptr = ptr->next;
            tmp2->data = ptr->data;
            tmp2->next = NULL;
            free(ptr);
        }
    }

    //Print function
    void print() {
        node<T> *ptr = head;
        while(ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    lList<int> l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.print();
    l.delMid(2);
    l.print();
    return 0;
}
