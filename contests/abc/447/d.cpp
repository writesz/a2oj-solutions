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

    if (s.size() < 3) {
        cout << 0 << endl;
        return;
    }

    int a = 0;
    int ab = 0;
    int ans = 0;

    for (char c : s) {
        if (c == 'A') {
            a++;
        } else if (c == 'B') {
            if (a > 0) {
                a--;
                ab++;
            }
        } else {
            if (ab > 0) {
                ab--;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return;
}

/*
BBBAAABCBCBAACBBCAAC
BBBAABCBAACBBCAAC
BBBAA
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
