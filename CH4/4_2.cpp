/* Coder: Juan Chavez
 * Date:  9.9.2015
 * Objective: Determine if there is a route between two nodes in a directed
 * graph
 */
#include <queue>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

//Graph node with adjacency list
struct node {
    int val;
    vector<int> adjL;
    
    //Check if adjacent node wasn't in list before
    /*bool isNew(int v) {
        for(int i = 0; i < adjL.size(); i++) {
            if(v == adjL[i].val) {
                return false;
            }
        }
        return true;
    }*/

    //Print adj list
    void print() {
        for(typename std::vector<int>::iterator it = adjL.begin(); it != adjL.end(); it ++) {
            cout << "-> " << *it << endl;
        }
    }

    //Add new adjacency list node
    void addN(int v) {
        //if(isNew(v)) {
            adjL.push_back(v);
        //}
    }
};

//Graph, list of graph nodes
struct graph {
    vector<node> nodeL;
    //Keep track of nodes
    int n;

    //Constructor: Initialize n
    graph() : n(0) {
    }

    //Add node to graph
    void addN() {
        int val = n;
        n ++;
        node tmpN;
        tmpN.val = val;
        nodeL.push_back(tmpN);
    }

    //Adds edge(directional)
    void addE(int node1, int node2) {
        nodeL[node1].addN(node2);
    }

    //Prints graph node's adjacency lists
    void print() {
        for(typename std::vector<node>::iterator it = nodeL.begin(); it != nodeL.end(); it ++) {
            cout << "Node " << it->val << "'s adj list:\n";
            it->print();
            cout << endl;
        }
    }

    //Breadth-first path check
    bool bfs(int startN, int endN) {
        //Create list of visited and unvisited nodes
        bool visited[n];
        //Initialize to false
        for(int i = 0; i < n; i ++) {
            visited[i] = false;
        }
        //Breadth-first queue
        queue<int> bq;
        //Push in start element
        bq.push(startN);
        //Mark as visited
        visited[startN] = true;
        while(!bq.empty()) {
            int tmp = bq.front();
            bq.pop();
            //Check if reached endN
            if(tmp == endN) {
                return true;
            }
            //Push unvisited adjacent nodes onto queue
            int s = nodeL[tmp].adjL.size();
            for(int i = 0; i < s; i ++) {
                if(!visited[nodeL[tmp].adjL[i]]) {
                    visited[nodeL[tmp].adjL[i]] = true;
                    bq.push(nodeL[tmp].adjL[i]);
                }
            }
        }
        return false;
    }

    //Depth-first path check
    //Recursive utility function
    void dfsUtil(int n, int endN, bool visited[], bool &p) {
        //Mark current node n as visisted
        visited[n] = true;
        //Return if endN is reached
        if(n == endN) {
            p = true;
            return;
        }
        //Recur for all of n's adjacent nodes
        int s = nodeL[n].adjL.size();
        for(int i = 0; i < s; i ++) {
            if(!visited[nodeL[n].adjL[i]]) {
                dfsUtil(nodeL[n].adjL[i], endN, visited, p);
            }
        }
    }

    bool dfs(int startN, int endN) {
        bool visited[n];
        for(int i = 0; i < n; i ++) {
            visited[i] = false;
        }
        //Recurse utility function for DFS
        bool found = false;
        dfsUtil(startN, endN, visited, found);
        return found;
    }
};

int main(int argc, char *argv[]) {
    graph g;
    cout << "Adding nodes to graph:\n";
    g.addN();
    g.addN();
    g.addN();
    g.addN();
    cout << "Adding node edges:\n";
    cout << "0 -> 1\n";
    g.addE(0, 1);
    cout << "1 -> 0\n";
    g.addE(1, 0);
    cout << "1 -> 3\n";
    g.addE(1, 3);
    cout << "1 -> 2\n";
    g.addE(1, 2);
    cout << "Printing graph:\n";
    g.print();
    cout << "Doing DFS check on paths:\n";
    cout << "Path from 0 to 3?\n";
    if(g.dfs(0, 3)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    cout << "Path from 2 to 3?\n";
    if(g.dfs(2, 3)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    cout << "Path from 0 to 2?\n";
    if(g.dfs(0, 2)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
