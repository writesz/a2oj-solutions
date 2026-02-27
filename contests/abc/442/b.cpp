// znnr competitive programming journey
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;

void solve() {
    int n; 
    cin >> n;

    bool sorted = true;

    int prev;
    cin >> prev;
    vi v;

    for (int i = 1; i < n; i++) {
        int k;
        cin >> k;

        if (k < prev) {
            sorted = false;
        }
        prev = k;
    }

    if (sorted) {
        cout << n << endl;
    } else {
        cout << 1 << endl;
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
