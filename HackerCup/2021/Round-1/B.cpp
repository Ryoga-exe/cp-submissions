/*
 * Author: Ryoga.exe
 * Submitted at: 2021-09-12 12:15:17 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/B
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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int minDis = n + m - 1;
        if (minDis > a || minDis > b) {
            cout << "Case #" << ttt + 1 << ": " << "Impossible" << endl;
            continue;
        }
        cout << "Case #" << ttt + 1 << ": " << "Possible" << endl;
        rep(i, n) {
            rep(j, m) {
                int cell = 999;
                if (i == 0 || j == 0 || j == m - 1) {
                    cell = 1;
                }
                if (i == n - 1) {
                    if (j == 0)   cell = b - minDis + 1;
                    if (j == m - 1) cell = a - minDis + 1;
                }

                cout << cell;
                if (j != m - 1) cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
