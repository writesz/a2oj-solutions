// znnr competitive programming journey
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <unordered_map>

using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;



void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> m;
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
        maxLength = max(maxLength, m[s[i]]);
    }

    for (char c : s) {
        if (m[c] != maxLength) {
            cout << c;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
