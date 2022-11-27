/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-03 01:28:47 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
 * Result:
 *   - TestSet1: Passed
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
    rep(query, 1, t+1) {
        int c = INF32, m = INF32, y = INF32, k = INF32;
        rep(i, 3) {
            int cc, mm, yy, kk;
            cin >> cc >> mm >> yy >> kk;
            chmin(c, cc);
            chmin(m, mm);
            chmin(y, yy);
            chmin(k, kk);
        }
        cout << "Case #" << query << ": ";
        if (c + m + y + k < 1000000) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            int now = 1000000;
            cout << min(c, now) << " ";
            now = max(now - c, 0);
            cout << min(m, now) << " ";
            now = max(now - m, 0);
            cout << min(y, now) << " ";
            now = max(now - y, 0);
            cout << min(k, now) << endl;
        }
    }
    return 0;
}
