/* Coder: Juan Chavez
 * Date:  9.21.2015
 * Objective: Given a binary tree, create a linked list of all the nodes
 * at each depth (e.g. A tree with depth D will have D linked lists).
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

// Treenode struct
struct Node {
    int dat;
    Node *left, *right;

    // Default constructor, no data = -1, pointers set to null
    Node() {
        dat = -1;
        left = NULL;
        right = NULL;
    }
};

// Creates and maintains binary search tree
class Tree {
public:

    Node *root;

private:

    // Destructor's helper funciton, recursively deletes trees
    void delNode(Node *n) {
        if(n != NULL) {
            delNode(n->left);
            delNode(n->right);
            delete(n);
        }
    }

public:

    // Default constructor: Set root to null
    Tree() : root(NULL) {
    }

    // Destructor: Calls on helper to delete tree from heap
    ~Tree() {
        delNode(root);
    }

    // Root accessor
    Node *getRoot() {
        return root;
    }

private:

    // Addnode's helper function (overloaded version)
    void addNode(int d, Node *n) {
        /* Case1: Node is smaller than n's value for dat (or equal), so
         * d must be placed leftwards
         */
        if(d <= n->dat) {
            // Case1.1: n's left node is non-empty, then recurse left
            if(n->left != NULL) {
                addNode(d, n->left);
            }
            /* Case 1.2: n's left node is empty, place d's node to left
             * of n.
             */
            else {
                // Temporary pointer for creation
                Node *t = new Node();
                t->dat = d;
                n->left = t;
            }
        }
        // Case2: d is larger, place it to right of n
        else {
            // Case2.1: Non-empty n->right node, recurse right
            if(n->right != NULL) {
                addNode(d, n->right);
            }
            //Case2.2: Empty n->right, place d to right of n
            else {
                //Temporary pointer for creation
                Node *t = new Node();
                t->dat = d;
                n->right = t;
            }
        }
    }

public:

    addNode(int d) {
        //Case1: Empty tree
        if(root == NULL) {
            root = new Node();
            root->dat = d;
        }
        //Case2: Non-empty tree, call helper
        else {
            addNode(d, root);
        }
    }

    //Print tree in-order
    void inOrder(Node *n) {
        if(n != NULL) {
            inOrder(n->left);
            cout << n->dat << " ";
            inOrder(n->right);
        }
    }
};

//Makes list for nodes at each depth
void makeList(Node *n, vector<vector<int> > &list, int lv) {
    //Base case 1: Tree/Subtree ends
    if(n == NULL) { return; }
    //cout << "depth lv: " << lv << endl;
    //cout << "node val: " << n->dat << endl;
    //Case 1: New depth level
    if(list.size() == lv) {
        vector<int> v; //= new vector<int>();
        list.push_back(v);
    }
    //vector<int> tList = list[lv];
    list[lv].push_back(n->dat);
    makeList(n->left, list, lv + 1);
    makeList(n->right, list, lv + 1);
}

int main(int argc, char *argv[]) {
    Tree tree;
    tree.addNode(1);
    tree.addNode(10);
    tree.addNode(20);
    tree.inOrder(tree.root);
    cout << "Making list:\n";
    vector<vector<int> > list;
    makeList(tree.getRoot(), list, 0);
    cout << "Printing list:\n";
    for(int i = 0; i < list.size(); i++) {
       for(int j = 0; j < list[i].size(); j++) {
          cout << list[i][j] << " ";
       }
    }
   cout << endl;
   cout << "Done.\n";
   return 0;
}
