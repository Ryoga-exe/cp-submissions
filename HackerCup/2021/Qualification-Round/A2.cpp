/*
 * Author: Ryoga.exe
 * Submitted at: 2021-08-28 03:55:02 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
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
        string s;
        int k;
        Graph2 g(26);
        cin >> s;
        cin >> k;
        rep(kkk, k) {
            string to;
            cin >> to;
            int a = to[0] - 'A', b = to[1] - 'A';
            g[a].push_back(b);
            // g[b].push_back(a);
        }

        vector<vector<int>> cost(26, vector<int>(26, -1));
        rep(i, 26) cost[i][i] = 0;
        rep(go, 26) {
            queue<int> que;
            VI dist(26, -1);
            que.push(go);
            dist[go] = 0;
            while (!que.empty()) {
                int q = que.front();
                que.pop();
                for (auto v: g[q]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[q] + 1;
                        que.push(v);
                    }
                }

            }
            rep(i, 26) {
                cost[go][i] = dist[i];
                // cost[i][go] = dist[i];
            }
        }
        int ans = -1;
        rep(alpha, 26) {
            int now = 0;
            for (char c: s) {
                if (cost[c - 'A'][alpha] == -1) {
                    now = -1;
                    break;
                }
                else {
                    now += cost[c - 'A'][alpha];
                }
            }
            if (now == -1) continue;
            if (ans == -1) ans = now;
            else chmin(ans, now);
        }
        
        cout << "Case #" << ttt + 1 << ": " << ans << endl;
    }
    return 0;
}
