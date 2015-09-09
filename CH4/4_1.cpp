/* Coder: Juan Chavez
 * Date:  9.8.2015
 * Objective: Check if binary tree is balanced (two subtrees' height never
 * differ by more than one)
 */
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

//Binary Tree Node
template <typename T>
struct node {
    T data;
    node<T> *left, *right;
    node() : left(NULL), right(NULL) {
    }
};

//Check to see if tree is balanced
template <typename T>
int balanced(node<T> *t) {
    //Case1: Empty tree/subtree
    if(t == NULL) {
        return 0;
    }

    //Case2: Recurse into left branch
    int lHeight = balanced(t->left);
    //Check balance
    if(lHeight == -1) {
        return -1;
    }

    //Case3: Recurse into right branch
    int rHeight = balanced(t->right);
    //Check balance
    if(rHeight == -1) {
        return -1;
    }

    //Case4: Branch in question
    //Height check, return if unbalanced
    int dHeight = lHeight - rHeight;
    if(abs(dHeight) > 1) {
        return -1;
    }
    //Return max height
    else {
        return max(lHeight, rHeight) + 1;
    }
}

int main(int argc, char *argv[]) {
    cout << "Testing balanced tree\n";
    node<int> *r = new node<int>;
    node<int> *lptr = r, *rptr = r;
    lptr->left = new node<int>;
    lptr = lptr->left;
    lptr->right = new node<int>;
    rptr->right = new node<int>;
    if (balanced(r) != -1) {
        cout << "Tree is balanced\n";
    }
    lptr = lptr->right;
    lptr->right = new node<int>;
    cout << "Testing unbalanced tree\n";
    if(balanced(r) == -1) {
        cout << "Tree is unbalanced\n";
    }
    return 0;
}
