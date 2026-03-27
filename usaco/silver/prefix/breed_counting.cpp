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
    int n, q;
    cin >> n >> q;

    int br1[n + 1], br2[n + 1], br3[n + 1];
    br1[0] = 0;
    br2[0] = 0;
    br3[0] = 0;

    for (int i = 1; i <= n; i++) {
        int br;
        cin >> br;

        br1[i] = br1[i-1];
        br2[i] = br2[i-1];
        br3[i] = br3[i-1];

        switch (br) {
            case 1:
            br1[i]++;
            break;
            case 2:
            br2[i]++;
            break;
            case 3:
            br3[i]++;
            break;
        }
    }

    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;

        cout << br1[to] - br1[from - 1] << " ";
        cout << br2[to] - br2[from - 1] << " ";
        cout << br3[to] - br3[from - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
