#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), left(n), right(n);
    vector<long long> prefix(n + 1);
    for (int &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }

    unordered_map<long long, int> position;
    for (int i = 0; i <= n; ++i) {
        position[prefix[i]] = i;
    }

    long long answer = 0;
    for (int k = 0; k < n; ++k) {
        long long target = prefix[k] + prefix[k + 1];
        if (k - left[k] <= right[k] - k) {
            for (int l = left[k] + 1; l <= k; ++l) {
                auto it = position.find(target - prefix[l]);
                if (it != position.end() &&
                    it->second >= k && it->second < right[k]) {
                    ++answer;
                }
            }
        } else {
            for (int r = k; r < right[k]; ++r) {
                auto it = position.find(target - prefix[r]);
                if (it != position.end() &&
                    it->second > left[k] && it->second <= k) {
                    ++answer;
                }
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
