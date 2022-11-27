/*
 * Author: Ryoga.exe
 * Submitted at: 2022-09-11 19:40:35 (UTC+09:00)
 * Problem URL: https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/B2
 * Result: Accepted
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1'000'000'007;

constexpr inline ll mod(ll a, ll m = MOD) noexcept {
    return (a % m + m) % m;
}

constexpr inline void add(pair<ll, ll>& p, ll a, ll b) noexcept {
    p.first = mod(p.first + a);
    p.second = mod(p.second + b);
}

auto main() -> int {
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++) {
        ll n;
        cin >> n;
        pair<ll, ll> sumT, sumT2;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            add(sumT, mod(a), mod(b));
            add(sumT2, mod(a * a), mod(b * b));
        }
        int q;
        cin >> q;
        ll ans = 0;
        while(q--) {
            ll x, y;
            cin >> x >> y;
            x = mod(x), y = mod(y);
            ll nowX = mod(mod(n) * mod(x * x)) - mod(2 * x * sumT.first) + mod(sumT2.first);
            ll nowY = mod(mod(n) * mod(y * y)) - mod(2 * y * sumT.second) + mod(sumT2.second);
            ans += mod(mod(nowX) + mod(nowY));
            ans = mod(ans);
        }

        cout << "Case #" << casenum << ": " << ans << endl;
    }
    return 0;
}
