#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    /**
     * START OF MY CODE.
     * Find this hackerrank problem at: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem.
     * The approach is basically to build a new list without duplicates.
     * Then for each of Alice's score, conduct a binary search to know where the current score should go.
     */
    vector<int>scores_slim;                                         // Dedupliacted scores list.
    int lastPut = scores.at(0);
    scores_slim.push_back(lastPut);
    for(int s = 1; s < scores.size(); s++) {                        // Populate list without duplicates.
        if(scores.at(s) != lastPut) {
            scores_slim.push_back(scores.at(s));
            lastPut = scores.at(s);
        }
    }
    vector<int>poses;
    int pos = 1;
    for(int i = 0; i < alice.size(); i++) {                         // For each of Alice's scores, conduct binary search
        int alice_score = alice.at(i);
        int l = 0, r = scores_slim.size();
        int mid = (l + r) / 2;
        while(l != mid && r != mid) {
            if(scores_slim.at(mid) > alice_score) {
                l = mid;
            } else {
                r = mid;
            }
            mid = (l + r) / 2 ;
        }
        if(alice_score >= scores_slim.at(l)) pos = l+1;
        else pos = r+1;
        poses.push_back(pos);
    }
    return poses;
    // END OF MY CODE. Everything beyond here is Hackerrank's boiler plate code.
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
