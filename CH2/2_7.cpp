/* Coder: Juan Chavez
 * Date:  8.19.2015
 * Objective: Make a function to determine if a linked list is a palindrome
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
    char data;
    node *next;
};

//Add a node to the list
void add(node *&t, char c) {
    //Case1: List is empty
    if(t == NULL) {
        t = new node;
        t->next = NULL;
        t->data = c;
    }
    //Case2: Non empty list
    else {
        t->next = new node;
        t = t->next;
        t->next = NULL;
        t->data = c;
    }
}

//Creates reversed version of list
void recRev(node *p, node *&h, node *&t);

//Determiens if list is palindrome
bool pal(node *m);

int main(int argc, char *argv[]) {
    node *h, *t = NULL;
    //Create list with palindrome 'revver'
    add(t, 'r');
    //Make head point to new node
    h = t;
    //Add rest
    add(t, 'e');
    add(t, 'v');
    add(t, 'v');
    add(t, 'e');
    add(t, 'r');
    //Determine if palindrome
    bool p = pal(h);
    if(p) {
        cout << "is ";
    }
    else {
        cout << "isn't ";
    }
    cout << "a palindrome\n";
    return 0;
}

//Objective function defenitions
void recRev(node *p, node *&h, node *&t) {
    //Stopping points
    //Case1: Never a list to begin with
    if(p == NULL) {
        return;
    }
    //Case2: Last element
    else if(p->next == NULL) {
        add(t, p->data);
        h = t;
    }
    else {
        recRev(p->next, h, t);
        add(t, p->data);
    }
}

bool pal(node *m) {
    node *h, *t = NULL;
    recRev(m, h, t);
    //Check to see if palindrome
    node *p1 = m, *p2 = h;
    while(p1 != NULL) {
        if(p1->data != p2->data) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

