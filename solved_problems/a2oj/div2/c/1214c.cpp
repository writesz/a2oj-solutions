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

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ' ';
        os << v[i];
    }
    return os;
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (n % 2 == 1) {
        cout << "No" << endl;
        return;
    }

    stack<char> st;
    int opening = 0;
    int closing = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == ')') {
            closing++;
            if (!st.empty()) {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        } else {
            opening++;
            st.push(c);
        }
    }

    cout << (st.size() <= 2 && opening == closing ? "Yes" : "No") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
