#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
const ll V = 100005, INF = 0x3f3f3f3f3f3f3f3f;
ll N, M, K, dis[V][12];
vector<pll> G[V];

struct Node {
    ll d, n, p;
    bool operator<(const Node& rhs) const {
        return d > rhs.d;
    }
};

void solve() {

    cin >> N >> M >> K;
    while (M--) {
        ll a, b, w; cin >> a >> b >> w;
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }

    priority_queue<Node> pq;
    pq.push({ 0, 1, 0 });
    memset(dis, INF, sizeof(dis));
    dis[1][0] = 0;
    while (pq.size()) {
        Node cur = pq.top(); pq.pop();
        if (dis[cur.n][cur.p] < cur.d) continue;
        for (int i = 0; i < G[cur.n].size(); i++) {
            ll nn = G[cur.n][i].first;
            ll nd = G[cur.n][i].second;
            ll cost = cur.d + nd;
            ll np = (cur.p + nd) % 12;
            if (cost < dis[nn][np]) {
                dis[nn][np] = cost;
                pq.push({ cost, nn, np });
            }
        }
    }
    
    ll mk = K % 12;
    if (dis[N][mk] <= K) cout << "YES";
    else cout << "NO";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}
