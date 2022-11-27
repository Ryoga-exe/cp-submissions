/*
 * Author: Ryoga.exe
 * Submitted at: 2022-09-11 18:49:31 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A1
 * Result: Accepted
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto main() -> int {
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        int start = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == a[0]) {
                start = i;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[(start + i) % n]) {
                ok = false;
            }
        }

        if (k == 0) {
            if (start != 0) {
                ok = false;
            }
        }
        else if (n == 2) {
            if (start == 0 && k % 2 == 1) {
                ok = false;
            }
            if (start == 1 && k % 2 == 0) {
                ok = false;
            }
        }
        else if (start == 0) {
            if (k == 1) {
                ok = false;
            }
        }
        cout << "Case #" << casenum << ": " << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
