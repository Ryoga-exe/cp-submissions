/*
 * Author: Ryoga.exe
 * Submitted at: 2022-08-29 02:18:05 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/A
 * Result: Accepted
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
    int testcaseNum;
    cin >> testcaseNum;
    for (int testcase = 1; testcase <= testcaseNum; testcase++) {
        int n, k;
        cin >> n >> k;
        bool ok = true;
        map<int, int> mp;
        rep(i, n) {
            int s;
            cin >> s;
            mp[s]++;
        }
        set<int> d1, d2;
        for(auto [x, y] : mp) {
            if (y >= 3) {
                ok = false;
            }
            else if (y == 2) {
                d1.insert(x);
                d2.insert(x);
            }
        }
        for(auto [x, y] : mp) {
            if (y == 1) {
                if (d1.size() < d2.size()) {
                    d1.insert(x);
                }
                else {
                    d2.insert(x);
                }
            }
        }
        if (d1.size() > k or d2.size() > k) {
            ok = false;
        }
        cout << "Case #" << testcase << ": " << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
