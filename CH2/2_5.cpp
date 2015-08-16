/* Coder: Juan Chavez
 * Date:  8.13.2015
 * Objective: Sum of two linked lists stored in reverse order.
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
    int digit;
    node *prev, *next;
};

struct lList {
    node *head, *tail;
    
    lList():head(NULL) {
    }

    /* Adds a digit to the overall number (warning: for correctness
     * digits need to be 0-9).
     *
     * Note: This is the reversed-digits version.
     */
    void addRev(int i) {
        //Case1: Adding to empty list
        if(head == NULL) {
            head = new node;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
            head->digit = i;
        }
        //Case2: A non-empty list
        else {
            head->prev = new node;
            node *n = head;
            head = head->prev;
            head->prev = NULL;
            head->next = n;
            head->digit = i;
        }
    }
    
    //Adds digits, non-reversed
    void addFwd(int i) {
        //Case1: Adding to empty list
        if(head == NULL) {
            head = new node;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
            head->digit = i;
        }
        //Case2: A non-empty list
        else {
            tail->next = new node;
            node *p = tail;
            tail = tail->next;
            tail->prev = p;
            tail->next = NULL;
            tail->digit = i;
        }
    }
    void print() {
        node *ptr = head;
        while(ptr != NULL) {
            cout << ptr->digit << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    //Sum function(reverse version)
    void sumRev(lList a) {
        //Point to first digits(since reversed, starts end)
        node *p1 = head, *p2 = a.head;
        int c = 0;
        //Loop while native list has digits
        while(p1 != NULL && p2 != NULL) {
            //Add a's digit to native
            p1->digit += p2->digit + c;
            c = 0;
            //Case1: Overflow (carry over)
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        //If addend still has digits
        while(p2 != NULL) {
            addFwd(0);
            //Point to new node (avoid dangling pointer [?])
            //*Note: Got a segfault here if used p1 = p1->next after addFwd
            p1 = tail;
            p1->digit += p2->digit + c;
            c = 0;
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            p2 = p2->next;
        }
        //If carry lasted until the end
        if(c != 0) {
            //Try adding it to last digit
            p1->digit += c;
            c = 0;
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            //Add rest of carry as digits
            while (c > 9) {
                int tmp = c % 10;
                addFwd(tmp);
                c /= 10;
            }
            addFwd(c);
            c = 0;
        }
    }
    //Define later(gonna test it out first)
    void sumFwd(lList a) {
        //Point to last digits
        node *p1 = tail, *p2 = a.tail;
        int c = 0;
        //Loop while native has digits
        while(p1 != NULL && P2 != NULL) {
            //Add a's digit to native
            p1->digit += p1->digit + c;
            c = 0;
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            p1 = p1->prev;
            p2 = p2->prev;
        }
        //If addend still has digits
        while(p2 != NULL) {
            //Add one more digit to native
            addRev(0);
            p1 = head;
            p1->digit += p2->digit + c;
            c = 0;
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            p2 = p2->next;
        }
        //If carry lasted until the end
        if(c != 0) {
            //Try adding it to last digit
            p1->digit += c;
            c = 0;
            while(p1->digit > 9) {
                p1->digit = p1->digit % 10;
                c++;
            }
            //Add rest of carry as digits
            while(c > 9) {
                int tmp = c % 10;
                addRev(tmp);
                c /= 10;
            }
            addRev(c);
            c = 0;
        }
    }
};

int main(int argc, char *argv[]) {
    lList l1;
    l1.addRev(9);
    l1.addRev(9);
    //l1.addRev(7);
    l1.print();
    cout << "+\n";
    lList l2;
    l2.addRev(1);
    //l2.addRev(9);
    //l2.addRev(3);
    l2.print();
    l1.sumRev(l2);
    cout << "=\n";
    l1.print();
    return 0;
}
