//
//  main.cpp
//  FindingFirstOne
//
//  Created by Anubhav Shrimal on 10/04/17.
//  Copyright © 2017 Anubhav Shrimal. All rights reserved.
//

#include <iostream>
using namespace std;

int binarySearch(int a[], int size){
    int start = 0;
    int end = size;
    int mid = (start + end) / 2;
    
    while ( start <= end) {
        if (a[mid] == 1 && a[mid - 1] == 0) {
            return mid;
        }
        else {
            if (a[mid] == 1) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
//    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int size = sizeof(a)/sizeof(a[0]);
    int index = binarySearch(a, size);
    (index != -1) ? cout << "First one is at position: "<< index << endl :
                    cout << "First one not found!" << endl;
    return 0;
}
