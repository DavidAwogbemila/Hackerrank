/*
Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.

For example, if  and , we can delete  from string  and  from string  so that both remaining strings are and  which are anagrams.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char, int> aMap, bMap;
    
    for (int i = 0; i < a.length(); i++) {
        if (aMap.find(a[i]) != aMap.end()) {
            aMap[a[i]]++;
        } else {
            aMap[a[i]] = 1;
        }
    }
    
    for (int i = 0; i < b.length(); i++) {
        if (bMap.find(b[i]) != bMap.end()) {
            bMap[b[i]]++;
        } else {
            bMap[b[i]] = 1;
        }
    }

    for (int i = 0; i < b.length(); i++) {
        if (aMap.find(b[i]) != aMap.end()) {
            aMap[b[i]]--;
        } else {
            aMap[b[i]] = -1;
        }
    }
    
    for (int i = 0; i < a.length(); i++) {
        if (bMap.find(a[i]) != bMap.end()) {
            bMap[a[i]]--;
        } else {
            bMap[a[i]] = -1;
        }
    }
    
    int min = 0;
    for (map<char, int>::iterator it = aMap.begin(); it != aMap.end(); it++) {
        if (it->second >= 0) {
            min += it->second;
        } else {
            min += (-1) * it->second;
        }
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
