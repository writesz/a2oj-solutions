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

int abs(int a, int b) {
    int res = a - b;

    if (res > 0) {
        return res;
    } else {
        return -res;
    }
}

void solve() {
    string s, t;
    cin >> s >> t;
    string mm = "";
    string tt = "";

    int sc = 0;
    int st = 0;

    vi scc , stt;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            sc++;

            if (i == s.size() - 1) {
                scc.push_back(sc);
            }
        } else {
            mm += s[i];
            scc.push_back(sc);
            sc = 0;

            if (i == s.size() - 1) {
                scc.push_back(0);
            }
        }
    }

    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'A') {
            st++;

            if (i == t.size() - 1) {
                stt.push_back(st);
            }
        } else {
            tt += t[i];
            stt.push_back(st);
            st = 0;

            if (i == t.size() - 1) {
                stt.push_back(0);
            }
        }
    }

    if (mm != tt) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < scc.size(); i++) {
        ans += abs(scc[i] - stt[i]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
