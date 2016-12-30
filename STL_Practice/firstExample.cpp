#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;

    // add at the end of the vector
    // size is adjusted according to the additions
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(5);
    vec.push_back(0);

    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end();

    // printing the vector using iterator
    for (vector<int>::iterator i= itr1; i != itr2 ; i++) {
        cout << *i << endl;
    }

    // sort the vector using iterators
    sort(itr1, itr2);

    for (vector<int>::iterator i= itr1; i != itr2 ; i++) {
        cout << *i<< endl;
    }

    cout << "Size: "<<vec.size()<<endl;
    return 0;
}