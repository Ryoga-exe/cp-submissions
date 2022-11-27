/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-30 18:57:33 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000877b42/0000000000afe6a1
 * Result:
 *   - TestSet1: Passed
 *   - TestSet2: Passed
*/
#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define IFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define IREP(i,n) IFOR(i,0,n)
#define rep(...) _overload3(__VA_ARGS__,FOR,REP,)(__VA_ARGS__)
#define irep(...) _overload3(__VA_ARGS__,IFOR,IREP,)(__VA_ARGS__)
#define all(v) begin(v), end(v)
using namespace std;
using ll = long long;
using Graph2 = vector<vector<int>>;
constexpr int INF32 = 1<<29;
constexpr ll INF64 = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int t;
    cin >> t;
    for(int casenum = 1; casenum <= t; casenum++) {
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i, n) {
            cin >> s[i];
        }
        vector<bool> used(n);
        while (true) {
            int cnt = 0;
            rep(i, n) {
                if (used[i]) {
                    continue;
                }
                rep(j, n) {
                    if (used[j]) {
                        continue;
                    }
                    if (i == j) {
                        continue;
                    }
                    map<char, int> mp;
                    for(auto c : s[j]) {
                        mp[c]++;
                    }
                    if (mp.size() == 1) {
                        if (s[i].back() == s[j].front()) {
                            used[j] = true;
                            s[i] += s[j];
                            cnt++;
                        }
                        else if (s[i].front() == s[j].back()) {
                            used[j] = true;
                            s[i] = s[j] + s[i];
                            cnt++;
                        }
                    }
                }
            }
            if (cnt == 0) {
                break;
            }
        }
        while (true) {
            int cnt = 0;
            rep(i, n) {
                if (used[i]) {
                    continue;
                }
                rep(j, n) {
                    if (used[j]) {
                        continue;
                    }
                    if (i == j) {
                        continue;
                    }
                    if (s[i].back() == s[j].front()) {
                        used[j] = true;
                        s[i] += s[j];
                        cnt++;
                    }
                    else if (s[i].front() == s[j].back()) {
                        used[j] = true;
                        s[i] = s[j] + s[i];
                        cnt++;
                    }
                }
            }
            if (cnt == 0) {
                break;
            }
        }
        string as;
        rep(i, n) {
            if (!used[i]) {
                as += s[i];
            }
        }
        string pressed;
        rep(i, 1, as.size()+1) {
            if (i == as.size()) {
                pressed += as[i-1];
            }
            else {
                if (as[i-1] != as[i]) {
                    pressed += as[i-1];
                }
            }
        }
        map<char, int> mp;
        rep(i, pressed.size()) {
            mp[pressed[i]]++;
        }
        for(auto [x, y] : mp) {
            if (y > 1) {
                as = "IMPOSSIBLE";
            }
        }
        printf("Case #%d: ", casenum);
        cout << as << endl;
    }
    return 0;
}
