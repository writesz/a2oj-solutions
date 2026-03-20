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
    
    vector<int> C(m + 1);
    
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        C[i] = x;
    }
    
    int counter = 0;
    
    for (int i = 1; i <= n; i++) {
        int pt, gr;
        cin >> pt >> gr;
        
        if (C[pt] > 0) {
            int val = min(C[pt], gr);
            
            if (C[pt] == val) {
                C[pt] = 0;
                counter += val;
            } else {
                C[pt] -= gr;
                counter += gr;
            }
        }
    }
    
    cout << counter << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
