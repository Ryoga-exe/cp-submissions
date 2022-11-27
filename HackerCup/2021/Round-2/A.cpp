/*
 * Author: Ryoga.exe
 * Submitted at: 2021-09-26 02:58:28 (JST)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-2/problems/A
 * Result: Wrong Answer
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
        int n, m;
        cin >> n >> m;

        map<int, int> mp;
        map<int, int> kensa;
        rep(i, m) {
            int s;
            cin >> s;
            mp[s]++;
            kensa[s]++;
        }

        int ans = 0;
        rep(i, n) {
            map<int, int> mp2;
            rep(j, m) {
                int p;
                cin >> p;
                kensa[p]++;
                if (mp[p] > 0) {
                    mp[p]--;
                    mp2[p]++;
                }
                else {
                    ans++;
                    mp2[p]++;
                }
            }
            swap(mp, mp2);
        }

        int cnt = 0;
        for (auto [x, y] : kensa) {
            if (y == n + 1) cnt++;
        }

        ans -= m;
        ans += cnt;
        cout << "Case #" << ttt + 1 << ": " << max(ans, 0) << endl;
    }
    return 0;
}

/*

1 1 4 4 10
----------| 3
1 4 8 5 7
----------| 3 
1 3 6 10 7
----------| 2
1 3 1 7  7
----------| 3
2 3 1 8  5

0 + 0 + 3 + 2 + 1 = 6


10 20 20
--------
10 10 20
30 30 20

0 1 0 = 1

*/
