#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long res = 0;
    map<long, vector<long>> triplets;
    
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "current: " << arr[i] << '@' << i << endl;

        triplets[i] = vector<long>({arr[i]});
        cout << "inserted " << arr[i] << " in triplet with tindex " << i << endl;

        for (int j = i - 1; j >= 0; j--) {
            vector<long>& current_tripple = triplets[j];
            int triplet_last_index = current_tripple.size() - 1;
            if (current_tripple.size() < 3 &&
                (current_tripple[triplet_last_index] * r) == arr[i]) {
                current_tripple.push_back(arr[i]);
                //triplets[j].push_back(arr[i]);

                cout << "inserting " << arr[i] << " in triplet with tindex " << j << endl;
            }
        }
        
    }

    for (auto it : triplets) {
        //if (it.second.size() == 3) {
        for (auto iit : it.second) {
            cout << iit << ", ";
        }

        cout << endl;
            //res++;
        //}
    }

    cout << res << endl;

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

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

