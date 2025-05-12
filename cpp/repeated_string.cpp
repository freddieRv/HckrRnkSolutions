#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    long ans = 0;
    long baseAfreq = 0;
    long sCount = 0;
    long sCountRem = 0;
    map<char, short> frequencies;

    for (size_t i = 0; i < s.size(); i++) {
        if (frequencies.find(s[i]) == frequencies.end()) {
            frequencies[s[i]] = 1;
        } else {
            frequencies[s[i]] = frequencies[s[i]] + 1;
        }
    }

    sCount = n / s.size();
    sCountRem = n % s.size();
    baseAfreq = frequencies['a'];

    ans = baseAfreq * sCount;

    cout << "s count: " << sCount << endl;
    cout << "n % s.size: " << (sCountRem) << endl;

    cout << "tmp ans: " << ans << endl;

    for (size_t i = 0; i < (sCountRem); i++) {
        if (s[i] == 'a') {
            ans++;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

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

