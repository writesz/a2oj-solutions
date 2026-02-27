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

int maxDivisor(int n) {
    if (n <= 1) return n;
    int best = 2;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            best = d;
            n /= d;
        }
    }
    if (n > 1) best = n;
    return best;
}

void solve() {
    int n;
    cin >> n;

    vi v;

    while (n--) {
        int nn;
        cin >> nn;
        v.push_back(nn);
    }

    int prev = maxDivisor(v[0]);

    bool alice = true;

    for (int i = 1; i < v.size(); i++) {
        int nn = v[i];
        int div = 1;

        if (nn > 1) {
            div = 2;

            for (int d = 2; d * d <= nn; d++) {
                while (nn % d == 0) {
                    if (d > prev) {
                        alice = false;
                    }

                    div = d;
                    nn /= d;
                }
            }
            if (nn > 1) div = nn;
            if (div > prev) {
                alice = false;
            }
        }

        prev = div;
    }

    if (alice) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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
