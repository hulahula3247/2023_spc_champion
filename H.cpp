#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
const ll V = 1000005;
ll N, raw[V], arr[V], pf[V], ft[V];
map<ll, ll> m;

struct Seg {
    ll tree[4 * V], lazy[4 * V];
    void prop(ll n, ll s, ll e) {
        if (s != e) {
            lazy[2 * n] += lazy[n];
            lazy[2 * n + 1] += lazy[n];
        }
        tree[n] += lazy[n]*(e-s+1);
        lazy[n] = 0;
    }

    void u1(ll n, ll s, ll e, ll idx) {
        if (lazy[n]) prop(n, s, e);
        if (s == e) {
            tree[n] = min(tree[n] - 1, ll(-1));
            return;
        }
        ll m = (s + e) / 2;
        if (idx <= m) u1(2 * n, s, m, idx);
        else u1(2 * n + 1, m + 1, e, idx);
        tree[n] = tree[2 * n] + tree[2 * n + 1];
    }

    ll q1(ll n, ll s, ll e, ll idx) {
        if (lazy[n]) prop(n, s, e);
        if (s == e) return tree[n];
        ll m = (s + e) / 2;
        if (idx <= m) return q1(2 * n, s, m, idx);
        else return q1(2 * n + 1, m + 1, e, idx);
    }

}seg;


void solve() {

    cin >> N;
    ll cur = 0;
    for (int i = 0; i < N; i++) {
        cin >> raw[i];
        cur += raw[i];
    }
    for (int i = 0; i < N; i++) {
        arr[i] = raw[i] * N - cur;
    }

    ll cnt = 1;
    ll start = N-1;
    for (int i = 0; i < N-1; i++) {
        pf[i+1] += pf[i] + arr[i];
        if (pf[i + 1] == 0) {
			start--;
			continue;
		}
        if (!m[pf[i + 1]]) {
            m[pf[i + 1]] = cnt;
            cnt++;
        }
        ft[i] = m[pf[i + 1]];
    }

    ll ans = start;
    for (int i = 0; i < N - 1; i++) {
        if (pf[i + 1] == 0) {
            seg.lazy[1]++;
            seg.prop(1, 0, N - 1);
        }
        else {
            seg.u1(1, 0, N - 1, ft[i]);
            ans = min(ans, start + seg.q1(1, 0, N - 1, ft[i]) + 1);
        }
    }
    cout << ans;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}
