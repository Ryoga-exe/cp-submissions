/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-25 01:22:37 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd59d
 * Result:
 *   - TestSet1: Passed
 *   - TestSet2: Passed
 *   - TestSet3: Passed
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
        int n;
        cin >> n;
        vector<int> d(n);
        deque<int> deq;
        rep(i, n) {
            cin >> d[i];
            deq.push_back(d[i]);
        }
        int now = -1;
        int ans = 0;
        while(!deq.empty()) {
            if (deq.front() < deq.back()) {
                if (now <= deq.front()) {
                    ans++;
                }
                chmax(now, deq.front());
                deq.pop_front();
            }
            else {
                if (now <= deq.back()) {
                    ans++;
                }
                chmax(now, deq.back());
                deq.pop_back();
            }
        }

        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
