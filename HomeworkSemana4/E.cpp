#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>
#define inf 1e18
#define ll long long

stack <int> dikstra(vector <vector<ii>> &g, vector <ll> &dist, int n){
    dist[0] = 0;
    priority_queue <pair<ii, int>, vector<pair<ii, int>>, greater<pair<ii, int>>> pq;
    pq.push({{0, 0}, n});
    vector <int> pai(n, n);

    while(!pq.empty()){
        int d, index, parent;
        d = pq.top().first.first;
        index = pq.top().first.second;
        parent = pq.top().second;
        pq.pop();

        if(d <= dist[index]){
            pai[index] = parent;
            for(auto i:g[index]){
                int v, w;
                v = i.first;
                w = i.second;

                if(dist[index] + w <dist[v]){
                    dist[v] = dist[index] + w;
                    pq.push({{dist[v], v}, index});
                }
            }
        }
    }

    stack <int> ans;
    int pos = n-1;
    while(pai[pos] != n){
        ans.push(pos);
        pos = pai[pos];
    }
    ans.push(pos);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <vector<ii>> g(n);
    vector <ll> dist(n, inf);

    for(int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        x--;
        y--;

        g[x].push_back({y, w});
        g[y].push_back({x, w});

    }

    stack <int> ans = dikstra(g, dist, n);
    if(ans.top() != 0) cout << "-1\n";
    else while(!ans.empty()){
        cout << ++ans.top() << " ";
        ans.pop();
    }

    return 0;
}