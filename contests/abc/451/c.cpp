// znnr competitive programming journey
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    while (n--) {
        int t, h;
        cin >> t >> h;
        if (t == 1) {
            pq.push(h);

            cout << pq.size() << endl;
        } else {
            while (!pq.empty() && pq.top() <= h) {
                pq.pop();
            }

            cout << pq.size() << endl;
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
