/* Coder: Juan Chavez
 * Date:  9.2.2015
 * Objective: Implement towers of Hanoi with stacks
 */

#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct hanoi {
    stack<int> tower[3];
    //Number of disks in tower
    int n;

    //Constructor, takes number of disks
    hanoi(int N) : n(N) {
        //Push disks into the first stack/tower
        for(int i = n; i > 0; i --) {
            tower[0].push(i);
        }
    }

    //Moves disk on top of one stack to another stack
    void moveTop(int origin, int target) {
        if(!tower[origin].empty()) {
            int tmp = tower[origin].top();
            tower[origin].pop();
            tower[target].push(tmp);
        }
    }

    //Recursive function that solves towers (d = disk number)
    void diskMove(int d, int origin, int target, int buff) {
        if(d > 0) {
            //First call: Moving d - 1 disks to buff
            diskMove(d - 1, origin, buff, target);

            //Second call: Move bot disk once to destination
            moveTop(origin, target);

            //Third call: Move the d - 1 disks to the destination
            diskMove(d - 1, buff, target, origin);
        }
    }

    //Print what's on each stack
    void printStack(int i) {
        //Make copy and use that to see contents
        for(stack<int> tmp = tower[i]; !tmp.empty(); tmp.pop()) {
            cout << tmp.top() << endl;
        }
    }

    void print() {
        cout << "tower 1: \n";
        printStack(0);
        cout << "tower 2: \n";
        printStack(1);
        cout << "tower 3: \n";
        printStack(2);
    }
};

int main(int argc, char *argv[]) {
    hanoi h(5);
    cout << "Initial towers:\n";
    h.print();
    cout << "Moving to third tower\n";
    h.diskMove(5, 0, 2, 1);
    cout << "final towers:\n";
    h.print();
}

