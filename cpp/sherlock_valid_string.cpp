#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    string is_valid = "NO";
    set<int> count;
    vector<int> reduced_count;
    vector<int> reduced_count_sec;
    map<int, int> count_count;
    map<char, int> letter_count;
    int pair_diff = 0, appear_diff = 0, temp = 0;
    
    for (size_t i = 0; i < s.size(); i++) {
        letter_count[s[i]] = letter_count.find(s[i]) == letter_count.end() ? 1 : letter_count[s[i]] + 1;
    }

    for (auto& it : letter_count) {
        cout << it.first << " -> " << it.second << endl;

        count_count[it.second] = count_count.find(it.second) == count_count.end() ? 1 : count_count[it.second] + 1;

        count.insert(it.second);
    }

    cout << "Count size: " << count.size() << endl;

    if (count.size() == 1) {
        is_valid = "YES";
    } else if (count_count.size() == 2) {
        for (auto it : count_count) {
            reduced_count.push_back(it.first);
            reduced_count_sec.push_back(it.second);

            cout << it.first << " > " << it.second << endl;
        }
        
        pair_diff = reduced_count[0] - reduced_count[1];
        temp = pair_diff >> 31; //
        pair_diff ^= temp;      // get absolute value
        pair_diff += temp & 1;  //
        appear_diff = reduced_count_sec[0] - reduced_count_sec[1];

        cout << "Diffs: " << pair_diff << ", " << appear_diff << endl;

        cout << (int)(pair_diff == 1) << endl;

        if ((reduced_count[0] == 1 && reduced_count_sec[0] == 1) || //
            (reduced_count[1] == 1 && reduced_count_sec[1] == 1) || // either one is 1 AND appears just once
            (pair_diff == 1 && (reduced_count_sec[0] == 1 || reduced_count_sec[1] == 1))) {
            is_valid = "YES";
        }
    }

    cout << is_valid << endl;

    return is_valid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

