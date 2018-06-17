#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename t>
void printVector(vector<t> v) {
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main (){
    vector<int>v {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < v.size(); ++i){
        printVector(v);
        next_permutation(v.begin(), v.end());
    }
}