/* Coder: Juan Chavez
 * Date:  8.18.2015
 * Objective: Find and return start of linked list node
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
    char data;
    node *next;
};

//Add node to lsit
void add(node *&t, char d) {
    //Case1: List is empty
    if(t == NULL) {
        t = new node;
        t->next = NULL;
        t->data = d;
    }
    //Case2: Non empty list
    else {
        t->next = new node;
        t = t->next;
        t->next = NULL;
        t->data = d;
    }
}

//Function prototype for objective
node *loopStart(node *h);

int main(int argc, char *argv[]) {
    node *h = new node, *t = h;
    //Adding 'A, B, C, D, E' to list
    add(t, 'A');
    add(t, 'B');
    add(t, 'C');
    //Point to where loop will be made
    node *l = t;
    add(t, 'D');
    add(t, 'E');
    //Create the loop
    t->next = l;
    node *n = loopStart(h);
    //Node: If no loop, returns null and nothing will be printed
    cout << n->data << endl;
    return 0;
}

node *loopStart(node *h) {
    //Create the fast and slow pointers (using runner technique)
    node *f = h, *s = h;
    bool first = true, loop = false;
    while(f->next) {
        //Case1: Both pointing at head
        if(s == f && first) {
            first = false;
        }
        //Case2: First true collision
        if(s == f && !first) {
            //Collision detection, leave loop
            loop = true;
            break;
        }
        s = s->next;
        f = f->next->next;
    }
    //Case1: No loop, return NULL
    if(!loop) {
        return NULL;
    }
    //Case2: Loop, move one pointer to head and have them meet up at loop's 
    //start
    else {
        s = h;
        while(s != f) {
            s = s->next;
            f = f->next;
        }
        return s;
    }
}
