/* Coder: Juan Chavez
 * Date:  9.21.2015
 * Objective: Turn ascending array to binary search tree of minimal
 * height.
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

//Tree node, binary
struct Tnode {
    int dat;
    Tnode *left, *right;

    //Default constructor, no data = -1, null pointers
    Tnode() {
        dat = -1;
        left = NULL;
        right = NULL;
    }
};

//Creates binary search tree out of ascending array
Tnode *makeTree(int arr[], int start, int end) {
    //Case1: Done when start and end overlap
    if(start > end) {
        return NULL;
    }
    
    //Case2: Non-overlapping, proceed with algorithm
    else {
        //Calculate middle, this will be a node
        int mid = (end + start) / 2;
        Tnode *t = new Tnode();
        t->dat = arr[mid];
        t->left = makeTree(arr, start, mid - 1);
        t->right = makeTree(arr, mid + 1, end);
        return t;
    }
}

//Print tree in order
void inOrder(Tnode *t) {
    if(t != NULL) {
        inOrder(t->left);
        cout << t->dat << " ";
        inOrder(t->right);
    }
}

int main(int argc, char *argv[]) {
    cout << "Creating ascending order array:\n";
    int arr[] = {1, 4, 5, 6, 7, 8, 11, 16, 100};
    cout << "Creating tree:\n";
    int size = sizeof(arr)/sizeof(arr[0]);
    Tnode *r = makeTree(arr, 0, size - 1);
    cout << "Printing tree in-order:\n";
    inOrder(r);
    return 0;
}
