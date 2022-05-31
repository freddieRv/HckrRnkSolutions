#include <bits/stdc++.h>
#include <map>

using namespace std;

#define MAX_BRIBES 2

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void printMap(map<int, int> m) {
    auto iter = m.begin();
    while (iter != m.end()) {
        printf("%d\t==>\t%d\n", iter->first, iter->second);
        iter++;
    }
}

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    int total_bribes = 0;
    int single_bribe = 0;
    map<int, int> bribes;

    for (size_t i = 0; i < q.size(); i++) {
        if (q[i] > (i + 1)) {
            single_bribe = q[i] - (i + 1);
            bribes[q[i]] = single_bribe;
            total_bribes += single_bribe;

            if (single_bribe > MAX_BRIBES) {
                printf("Too chaotic\n");
                return;
            }
        } else if (q[i] < (i + 1)) {
            single_bribe = (i + 1) - q[i];


            auto range_iter = bribes.equal_range(q[i]);
            auto& greater_iter = range_iter.second;

            while (greater_iter != bribes.end()) {
                single_bribe--;
                greater_iter++;
            }

            // map<int, int>::iterator it = bribes.begin();
            // while (it != bribes.end()) {
            //     if (it->first > q[i]) {
            //         single_bribe--;
            //     }
            //     it++;
            // }

            if (single_bribe > 0) {
                total_bribes += single_bribe;
                bribes[q[i]] = single_bribe;
            }
        }

        printf("Bribe for ID %d: %d\n", q[i], single_bribe);
    }

    printMap(bribes);

    printf("%d\n", total_bribes);
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
