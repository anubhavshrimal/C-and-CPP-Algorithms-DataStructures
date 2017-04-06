//
//  main.cpp
//  DecimalDominant
//
//  Created by Anubhav Shrimal on 10/04/17.
//  Copyright © 2017 Anubhav Shrimal. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map <int, int> container;
    map <int, int> :: iterator itr;
    
    int n;
    cout << "Enter the number of elements in array: " <<endl;
    cin >> n;
    int a[n];
    
    cout << "Enter elements of the array: "<<endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        auto search = container.find(a[i]);
        if (search == container.end())
            container.insert(pair<int, int> (a[i], 1));
        else {
            search->second = search->second + 1;
        }
    }
    cout << "Element\t" << "Count"<<endl;
    for (itr = container.begin(); itr != container.end(); ++itr)
    {
        if(itr->second >= n/10){
            cout << itr->first << "\t\t" << itr->second <<endl;
        }
    }
    return 0;
}
