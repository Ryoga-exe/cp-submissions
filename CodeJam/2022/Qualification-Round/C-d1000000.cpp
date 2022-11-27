/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-03 01:39:30 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
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
    rep(query, 1, t+1) {
        int n;
        cin >> n;
        vector<int> s(n);
        rep(i, n) {
            cin >> s[i];
        }
        sort(all(s));
        int ans = 1;
        rep(i, n) {
            if (ans <= s[i]) {
                ans++;
            }
        }
        cout << "Case #" << query << ": " << ans - 1 << endl;
    }
    return 0;
}
