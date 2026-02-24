// znnr competitive programming journey
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
    string s;
    cin >> s;

    int seattle = 0;
    int sanfran = 0;
    char prev = s[0];
    for (char c : s) {
        if (c != prev) {
            if (c == 'S') {
                seattle++;
            } else {
                sanfran++;
            }
            prev = c;
        }
    }


    if (seattle >= sanfran) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
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
