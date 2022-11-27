/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-03 04:09:51 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7
 * Result:
 *   - TestSet1: Wrong Answer
 *   - TestSet2: Skipped
 *   - TestSet3: Skipped
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

int dfs(Graph2& g, vector<int>& f, vector<int>& w, int v) {
    int ret = f[v];
    for(auto e : g[v]) {
        chmax(ret, dfs(g, f, w, e));
    }
    // cout << v << ": " << ret << endl; 
    w[v] = ret;
    return ret;
}

int dfs2(Graph2& g, vector<int>& f, vector<int>& w, int v, int now) {
    int ret = 0;
    vector<pair<int, int>> p;
    for(auto e : g[v]) {
        p.emplace_back(w[e], e);
    }
    if (p.empty()) {
        // cout << "p " << v << " : " << now << endl;
        return now;
    }
    sort(all(p));
    bool is = false;
    for(auto [_, e] : p) {
        if (!is) {
            ret += dfs2(g, f, w, e, max(now, f[e]));
            is = true;
        }
        else {
            ret += dfs2(g, f, w, e, f[e]);
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    rep(query, 1, t+1) {
        int n;
        cin >> n;
        Graph2 g(n), rev_g(n);
        vector<int> f(n);
        rep(i, n) {
            cin >> f[i];
        }

        vector<int> s;
        rep(i, n) {
            int p;
            cin >> p;
            --p;
            if (p == -1) {
                s.push_back(i);
            }
            else {
                g[p].push_back(i);
            }
        }
        vector<int> w(n);
        rep(i, s.size()) {
            dfs(g, f, w, s[i]);
        }

        int ans = 0;
        rep(i, s.size()) {
            ans += dfs2(g, f, w, s[i], f[s[i]]);
        }
        cout << "Case #" << query << ": " << ans << endl;
    }
    return 0;
}
