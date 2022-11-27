/*
 * Author: Ryoga.exe
 * Submitted at: 2021-09-12 20:54:53 (JST)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A2
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
using ull = unsigned long long;
using P = pair<int, int>;
using PLL = pair<ll, ll>;
using VI = vector<int>;
using VLL = vector<ll>;
using VB = vector<bool>;
using VP = vector<P>;
using Graph2 = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
bool second_compare(P a, P b) { if (a.second != b.second) { return a.second < b.second; } else return true; }

constexpr ll MOD = 1'000'000'007;

int main() {
    int t;
    cin >> t;
    rep(ttt, t) {
        int n;
        string s;
        cin >> n >> s;
        VLL dp(n);
        ll numO = 0;
        ll numX = 0;

        bool isRight = false;
        bool isF = false;
        if (s[0] == 'X') isRight = false, isF = true, numX = 1;
        if (s[0] == 'O') isRight = true, isF = true, numO = 1;
        rep(i, 1, n) {
            if (s[i] == 'F') {
                dp[i] = dp[i - 1];
                continue;
            }
            if (!isF) {
                if (s[i] == 'X') isRight = false, numX = i + 1;
                if (s[i] == 'O') isRight = true, numO = i + 1;
                isF = true;
                continue;
            }
            dp[i] = dp[i - 1];

            if (isRight && s[i] == 'X') {
                dp[i] = dp[i - 1] + numO;
                dp[i] %= MOD;
                isRight = false;
            }
            if (!isRight && s[i] == 'O') {
                dp[i] = dp[i - 1] + numX;
                dp[i] %= MOD;
                isRight = true;
            }

            if (s[i] == 'X') numX = i + 1;
            if (s[i] == 'O') numO = i + 1;
        }
        ll ans = 0;
        rep(i, n) {
            ans += dp[i];
            ans %= MOD;
        }
        cout << "Case #" << ttt + 1 << ": " << ans << endl;
    }
    return 0;
}
