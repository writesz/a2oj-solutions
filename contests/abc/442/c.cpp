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
    int n, m;
    cin >> n >> m;

    vector<int> r(n + 1);

    while (m--) {
        int r1, r2;
        cin >> r1 >> r2;

        r[r1]++;
        r[r2]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << C3(n-1 -r[i]) << " ";
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
