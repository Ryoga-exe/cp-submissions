/*
 * Author: Ryoga.exe
 * Submitted at: 2021-08-28 02:41:53 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
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

    auto isVowel = [](char _c) -> bool {
        if (_c == 'A' || _c == 'E' || _c == 'I' || _c == 'O' || _c == 'U') {
            return true;
        }
        else return false;
    };

    rep(ttt, t) {
        string s;
        cin >> s;
        map<char, int> mp1, mp2;
        for (char c : s) {
            if (isVowel(c)) mp1[c]++;
            else mp2[c]++;
        }
        char mxV, mxC;
        int mx = 0;
        for (auto [x, y] : mp1) {
            if (mx < y) {
                mx = y;
                mxV = x;
            }
        }
        mx = 0;
        for (auto [x, y] : mp2) {
            if (mx < y) {
                mx = y;
                mxC = x;
            }
        }

        int ans1 = 0, ans2 = 0;
        rep(i, s.size()) {
            if (!isVowel(s[i])) ans1++;
            else {
                if (s[i] != mxV) ans1 += 2;
            }
        }

        rep(i, s.size()) {
            if (isVowel(s[i])) ans2++;
            else {
                if (s[i] != mxC) ans2 += 2;
            }
        }

        int ans = min(ans1, ans2);
        cout << "Case #" << ttt + 1 << ": " << ans << endl;
    }
    return 0;
}
