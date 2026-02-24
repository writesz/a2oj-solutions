// znnr competitive programming journey
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;

long long C3(long long n) {
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vi v(n+1), pref(n+1);
    pref[0] = 0;

    for (int i = 1; i <=n; i++) {
        int number;
        cin >> number;
        v[i] = number;
        pref[i] = pref[i-1] + number;
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            
            if (x != n) {
                int temp = v[x];
                v[x] = v[x+1];
                v[x+1] = temp;
                pref[x] = pref[x] + v[x] - v[x+1];
            }
        } else {
            int l, r;
            cin >> l >> r;

            cout << pref[r] - pref[l-1] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
