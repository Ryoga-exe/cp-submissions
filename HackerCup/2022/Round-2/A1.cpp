/*
 * Author: Ryoga.exe
 * Submitted at: 2022-09-25 02:38:31 (JST)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-2/problems/A1
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
using Graph2 = vector<vector<int>>;
constexpr int INF32 = 1<<29;
constexpr ll INF64 = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int ans = 0;
    int n = s.size();
    vector sum(n+1, vector(26, 0));
    rep(i, n) {
        rep(j, 26) {
            sum[i+1][j] += sum[i][j];
            if (s[i] - 'a' == j) {
                sum[i+1][j]++;
            }
        }
    }
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        int mid = (l + r) / 2;
        int t1 = 0, t2 = 0;
        rep(i, 26) {
            int p1 = (sum[r][i] - sum[mid][i]) - (sum[mid][i] - sum[l-1][i]);
            int p2 = (sum[r][i] - sum[mid-1][i]) - (sum[mid-1][i] - sum[l-1][i]);
            t1 += abs(p1);
            t2 += abs(p2);
        }
        if (t1 == 1 || t2 == 1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
