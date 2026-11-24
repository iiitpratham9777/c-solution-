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

    long long answer = 0;
    for (int l = 0; l < n; ++l) {
        int minimum = l;
        for (int r = l; r < n; ++r) {
            if (a[r] < a[minimum]) {
                minimum = r;
            }

            if (prefix[minimum] - prefix[l] ==
                prefix[r + 1] - prefix[minimum + 1]) {
                ++answer;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
