/*
 * Author: Ryoga.exe
 * Submitted at: 2021-08-30 15:54:25 (JST)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
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
bool second_compare(P a,P b){if(a.second!=b.second){return a.second<b.second;} else return true;}

int main() {
    int t;
    cin >> t;
    rep(ttt, t) {
        int n;
        cin >> n;
        vector<string> cell(n);
        rep(i, n) cin >> cell[i];
        
        map<int, int> mp;
        
        rep(i, n) {
            int now = 0;
            int xx = 0;
            rep(j, n) {
                if (cell[i][j] == '.' || cell[i][j] == '!') now++, xx = j;
                else if (cell[i][j] == 'O') {
                    now = -1;
                    break;
                }
            }
            if (now >= 0) {
                mp[now]++;
                if (now == 1) {
                    cell[i][xx] = '!';
                }
            }
        }

        rep(j, n) {
            int now = 0;
            bool h = false;
            rep(i, n) {
                if (cell[i][j] == '.' || cell[i][j] == '!') now++;
                if (cell[i][j] == '!') h = true;
                else if (cell[i][j] == 'O') {
                    now = -1;
                    break;
                }
            }
            
            if (now >= 0) {
                mp[now]++;
                if (now == 1 && h) {
                    mp[now]--;
                }
            }
        }

        cout << "Case #" << ttt + 1 << ": ";
        bool has = false;
        for (auto [x, y] : mp) {
            cout << x << ' ' << y << endl;
            has = true;
            break;
        }
        if (!has) cout << "Impossible" << endl;
    }
    return 0;
}
