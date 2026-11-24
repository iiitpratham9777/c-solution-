#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), prefix(n + 1);
    for (long long &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    unordered_map<long long, int> position;
    for (int i = 0; i <= n; ++i) {
        position[prefix[i]] = i;
    }

    long long answer = 0;
    for (int k = 0; k < n; ++k) {
        long long target = prefix[k] + prefix[k + 1];
        for (int l = 0; l <= k; ++l) {
            auto it = position.find(target - prefix[l]);
            if (it != position.end() && it->second >= k + 1) {
                ++answer;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
