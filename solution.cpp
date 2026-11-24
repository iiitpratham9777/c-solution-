#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + a[i];
    }

    vector<int> L(n), R(n), st;
    st.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        L[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        R[i] = st.empty() ? n : st.back();
        st.push_back(i);
    }

    unordered_map<long long, int> where;
    where.reserve(2 * (n + 1));
    where.max_load_factor(0.7);
    for (int i = 0; i <= n; ++i) {
        where[P[i]] = i;
    }

    long long ans = 0;
    for (int k = 0; k < n; ++k) {
        const long long target = P[k] + P[k + 1];

        if (k - L[k] <= R[k] - k) {
            for (int l = L[k] + 1; l <= k; ++l) {
                auto it = where.find(target - P[l]);
                if (it != where.end()) {
                    int rp1 = it->second;
                    if (k + 1 <= rp1 && rp1 <= R[k]) {
                        ++ans;
                    }
                }
            }
        } else {
            for (int rp1 = k + 1; rp1 <= R[k]; ++rp1) {
                auto it = where.find(target - P[rp1]);
                if (it != where.end()) {
                    int l = it->second;
                    if (L[k] + 1 <= l && l <= k) {
                        ++ans;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
