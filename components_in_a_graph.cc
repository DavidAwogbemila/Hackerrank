#include <bits/stdc++.h>

using namespace std;
// This was my solution. I think it's correct but highly inefficient.
// It passes 11 out of 39 cases in Hackerrank.
// 07/26/2019
int netLength(map<int, vector<int>> m, map<int, bool>& mbool, int root) {
    vector<int> neighbours = m[root];
    int total = 1;
    for (int k = 0 ; k < neighbours.size(); k++) {
        int curr = neighbours[k];
        if (!mbool[curr]) {
            mbool[curr]= true;
            total += netLength(m, mbool, curr);
        }
    }
    cout << "got " << total << "on " << root << endl;
    return total;
}
/*
 * Complete the componentsInGraph function below.
 */
vector<int> componentsInGraph(vector<vector<int>> gb) {
    /*
     * Write your code here.
     */
    int min = -1, max = -1;
    vector<int>g, b;
    for (int k = 0; k < gb.size(); k++) {
        g.push_back(gb.at(k).at(0));
        b.push_back(gb.at(k).at(1));
    }

    vector<int>all(g.size() + b.size());
    int i;
    for(i = 0; i < all.size(); i++) {
        all[i] = i < g.size() ? g[i]: b[i - g.size()];
    }
    map<int, vector<int>>m;
    map<int, bool>mbool;
    map<int, int>kToNetLength;
    for (i = 0; i < g.size(); i++) {
        int curr = g[i];
        vector<int> curr_neighbours = m[curr];
        curr_neighbours.push_back(b[i]);
        m[curr] = curr_neighbours;
        mbool[curr] = false;
    }
    for (i = 0; i < b.size(); i++) {
        int curr = b[i];
        vector<int> curr_neighbours = m[curr];
        curr_neighbours.push_back(g[i]);
        m[curr] = curr_neighbours;
        mbool[curr] = false;
    }
    for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
        int key = it->first;
        cout << "key: " << key << " => "; 
        for (int k = 0; k < m[key].size(); k++) {
            cout << m[key][k] << "--";
        }
        cout << "|" << endl;
    }
    bool firstTry = true;
    for (int k = 0 ; k < g.size(); k++) {
        int curr = g[k];
        if (!mbool[curr]) {
            cout << "Checking: " << curr << endl;
            mbool[curr] = true;
            int networkLength = netLength(m, mbool, curr);
            vector<int> curr_neighbourhood = m[curr];
            kToNetLength[curr] = networkLength;
            for (int j = 0; j < curr_neighbourhood.size(); j++) {
                int neighbour = curr_neighbourhood[j];
                kToNetLength[neighbour] = networkLength;
            }
            max = networkLength > max ? networkLength : max;
            min = firstTry || (networkLength < min && networkLength >= 2) ? networkLength : min;
            firstTry = false;
        }
    }
    min = kToNetLength.begin()->second;
    for (map<int, int>::iterator it = kToNetLength.begin(); it != kToNetLength.end(); it++) {
        max = it->second > max ? it->second : max;
        min = it->second < min ? it->second : min;
    }
    return vector<int>({min, max});
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
