/*
 * Author: Ryoga.exe
 * Submitted at: 2022-08-29 02:32:38 (JST)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/B1
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

int main() {
    int testcaseNum;
    cin >> testcaseNum;
    for (int testcase = 1; testcase <= testcaseNum; testcase++) {
        int r, c;
        cin >> r >> c;
        vector<string> s(r);
        int cnt = 0;
        rep(i, r) {
            cin >> s[i];
            rep(j, c) {
                if (s[i][j] == '^') {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            cout << "Case #" << testcase << ": Possible" << endl;
            rep(i, r) {
                cout << s[i] << endl;
            }
        }
        else {
            if (r == 1 or c == 1) {
                cout << "Case #" << testcase << ": Impossible" << endl;
            }
            else {
                cout << "Case #" << testcase << ": Possible" << endl;
                rep(i, r) {
                    rep(j, c) {
                        cout << "^";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
