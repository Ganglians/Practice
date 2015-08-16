/* Coder: Juan Chavez
 * Date:  7.31.2015
 * Objective: Implement mergesort successfully.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int length;

/* Function where the two sides compared are compared to see which number
 * out of both of them should go first (each 'larger' block comes ordered
 * from previous recursive call).
 */
void mergesort(int *arr, int lm, int mid, int rm) {
    //lbc = left block counter & similarly rbc = right.
    int lbc = lm, rbc = mid + 1;
    int tmparr[length];
    int i = lm;

    //Loop through both blocks.
    while(lbc <= mid && rbc <= rm) {
        if(arr[lbc] < arr[rbc]) {
            tmparr[i] = arr[lbc];
            lbc++;
            i++;
        }
        else {
            tmparr[i] = arr[rbc];
            rbc++;
            i++;
        }
	}
    while(lbc <= mid) {
		tmparr[i] = arr[lbc];
		lbc++;
		i++;
	}
	while(rbc <= rm) {
		tmparr[i] = arr[rbc];
		rbc++;
		i++;
	}
	//Copy contents into original array.
	for(int j = lm; j < i; j++) {
		arr[j] = tmparr[j];
	}
}

//The 'divide' part of 'divide and conquer.' Halves recursively.
//rm = rightmost, lm = leftmost
void sort(int *arr, int lm, int rm) {
    //Boundary check
    if(lm < rm) {
        int mid = (lm + rm)/2;
        sort(arr, lm, mid);
        sort(arr, mid + 1, rm);
        mergesort(arr, lm, mid, rm);
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {10, 8, 7, 1, 6, 5, 4, 9, 2, 3};
    length = sizeof(arr) / sizeof(arr[0]);

    sort(arr, 0, length - 1);

    //Print sorted array.
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
