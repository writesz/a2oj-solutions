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

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ' ';
        os << v[i];
    }
    return os;
}


void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    int dif = r - l;
    int dif2 = dif;
    int thr = n - dif - l;
    int thr2 = thr;

    vi v1, v2;
    int leftMax = n + 2;
    int leftMaxIdx = 0;
    int rightMax = n + 2;
    int rightMaxIdx = 0;

    vi init;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        init.push_back(k);
    }

    int q = 0;

    while (l--) {
        v1.push_back(init[q]);
        q++;
    }
    while (dif--) {
        v2.push_back(init[q]);
        q++;
    }

    while (thr--) {
        v1.push_back(init[q]);
        q++;
    }

    // rotate vectors
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] < leftMax) {
            leftMax = v1[i];
            leftMaxIdx = i;
        }
    }

    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] < rightMax) {
            rightMax = v2[i];
            rightMaxIdx = i;
        }
    }

    rotate(v2.begin(), v2.begin() + rightMaxIdx, v2.end());


    // sobirat' otvet
    vi ans;

    if (v1.empty()) {
        ans = v2;
    } else if (v2.empty()) {
        ans = v1;
    } else {
        int e = 0;

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[0]) {
                e++;
            } else {
                break;
            }
        }
    
    
        for (int k = 0; k < e; k++) {
            ans.push_back(v1[k]);
        }
    
        for (int k = 0; k < dif2; k++) {
            ans.push_back(v2[k]);
        }
    
        for (int k = e; k < v1.size(); k++) {
            ans.push_back(v1[k]);
        }
    }


    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
