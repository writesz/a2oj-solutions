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
    vi v;

    int max = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k > max) {
            max = k;
        }
        v.push_back(k);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == max) {
            l++;
        }
    }



    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
