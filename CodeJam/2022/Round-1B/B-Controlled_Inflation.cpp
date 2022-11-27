/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-25 02:17:07 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb
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
    for(int testcase = 1; testcase <= t; testcase++) {
        int n, p;
        cin >> n >> p;
        ll ans = 0;
        vector x(n, vector(p, 0ll));
        vector y(n, vector(2, 0ll));
        vector dp(n, vector(2, INF64));
        rep(i, n) {
            rep(j, p) {
                cin >> x[i][j];
            }
            sort(all(x[i]));
            y[i][0] = x[i].front();
            y[i][1] = x[i].back();
            rep(j, 1, p) {
                ans += abs(x[i][j-1] - x[i][j]);
            }
        }
        dp[0][0] = y[0][0];
        dp[0][1] = y[0][1];
        rep(i, 1, n) {
            rep(j, 2) {
                rep(k, 2) {
                    // dp[i-1][j] -> dp[i][k]
                    chmin(dp[i][k], dp[i-1][j] + abs(y[i][k] - y[i-1][j^1]));
                }
            }
        }
        ans += min(dp[n-1][0], dp[n-1][1]);
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
