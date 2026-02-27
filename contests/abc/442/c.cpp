// znnr competitive programming journey
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;

void solve() {
    int n; 
    cin >> n;

    string s;
    cin >> s;

    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (!st.empty()) {
            char c = st.top();
            if (s[i] == c) {
                st.pop();
                continue;
            }
        }

        st.push(s[i]);

    }

    if (st.empty()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
