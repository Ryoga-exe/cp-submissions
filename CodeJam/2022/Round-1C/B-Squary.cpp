/*
 * Author: Ryoga.exe
 * Submitted at: 2022-04-30 20:08:52 (UTC+09:00)
 * Problem URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000877b42/0000000000afdf76
 * Result:
 *   - TestSet1: Passed
 *   - TestSet2: Wrong Answer
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

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
        --d;
        *d = "0123456789"[tmp % 10];
        tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
        --d;
        *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
        dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int main() {
    int t;
    cin >> t;
    for(int casenum = 1; casenum <= t; casenum++) {
        int n, k;
        cin >> n >> k;
        vector<ll> e(n);
        rep(i, n) {
            cin >> e[i];
        }
        ll a = 0, b = 0;
        rep(i, n) {
            a += e[i];
            b += e[i] * e[i];
        }
        printf("Case #%d: ", casenum);
        if (a == 0) {
            if (b == 0) {
                cout << 0 << endl;
            }
            else {
                cout << "IMPOSSIBLE" << endl;
            }
            continue;
        }
        if ((b - a*a) % (2 * a) != 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        ll x = (b - a*a) / (2 * a);
        cout << x << endl;
    }
    return 0;
}
