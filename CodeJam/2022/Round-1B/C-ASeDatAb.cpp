/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-25 03:26:46 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd29b
 * Result:
 *   - TestSet1: Wrong Answer
 *   - TestSet2: Skipped
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
        string s = "00000001";
        while(true) {
            cout << s << endl;
            int n;
            cin >> n;
            if (n == 0) {
                break;
            }
            if (n == -1) {
                return 0; // WA
            }

            if (n > 4) {
                s = "11111111";
            }
            else if (n == 4) {
                s = "00001111";
            }
            else if (n == 3) {
                s = "00000111";
            }
            else if (n == 2) {
                s = "00000011";
            }
            else {
                s = "00000001";
            }
        }
        
    }
    return 0;
}
