#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
ll N, Q, L, ans[100005];

struct Point {
    ll x, y;
    bool operator<(const Point& rhs) const {
        return x < rhs.x;
    }
};
vector<Point> v;

struct Query {
    ll x, y, idx;
    bool operator<(const Query& rhs) const {
        return x < rhs.x;
    }
};
vector<Query> q;

struct Line {
    ll x, y;
    bool operator<(const Line& rhs) const {
        return x * rhs.y > rhs.x * y;
    }
};
set<Line> s;
map<Line, ll> m;

struct Seg {
    ll tree[800005];
    void u1(ll n, ll s, ll e, ll idx) {
        if (s == e) {
            tree[n]++;
            return;
        }
        ll m = (s + e) / 2;
        if (idx <= m) u1(2 * n, s, m, idx);
        else u1(2 * n + 1, m + 1, e, idx);
        tree[n] = tree[2 * n] + tree[2 * n + 1];
    }

    ll q1(ll n, ll s, ll e, ll l, ll r) {
        if (l <= s && e <= r) return tree[n];
        if (e < l || s > r) return 0;
        ll m = (s + e) / 2;
        return q1(2 * n, s, m, l, r) + q1(2 * n + 1, m + 1, e, l, r);
    }
}seg;

void solve() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        v.push_back({ x, y });
        s.insert({ x, y });
    }
    sort(all(v));
    reverse(all(v));

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll x, y; cin >> x >> y;
        q.push_back({ x, y, i });
        s.insert({ x, y });
    }
    sort(all(q));

    int cnt = 0;
    for (auto i = s.begin(); i != s.end(); i++) {
        m[*i] = cnt;
        cnt++;
    }

    int L = s.size();
    for (int i = 0; i < Q; i++) {
        Query cur = q[i];
        while (v.size() && v.back().x <= cur.x) {
            Point p = v.back();
            v.pop_back();
            Line cur = { p.x, p.y };
            seg.u1(1, 0, L - 1, m[cur]);
        }
        ans[cur.idx] = seg.q1(1, 0, L - 1, 0, m[{cur.x, cur.y}]);
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}
