/*
 * Author: Ryoga.exe
 * Submitted at: 2021-09-12 09:46:41 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A1
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

int main() {
    int t;
    cin >> t;
    rep(ttt, t) {
        int n;
        string s;
        cin >> n >> s;
        ll ans = 0;
        bool isRight = false;
        rep(i, n) {
            if (!isRight && s[i] == 'O') {
                ans++;
                isRight = true;
            }
            else if (isRight && s[i] == 'X') {
                ans++;
                isRight = false;
            }
        }

        isRight = true;
        ll ans2 = 0;
        rep(i, n) {
            if (!isRight && s[i] == 'O') {
                ans2++;
                isRight = true;
            }
            else if (isRight && s[i] == 'X') {
                ans2++;
                isRight = false;
            }
        }
        cout << "Case #" << ttt + 1 << ": " << min(ans, ans2) << endl;
    }
    return 0;
}
