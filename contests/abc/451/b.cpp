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
    int n, m;
    cin >> n >> m;
    
    vector<int> v(m + 1);
    
    for (int i = 0; i < n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        
        v[ai]--;
        v[bi]++;
    }
    
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << endl;
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
