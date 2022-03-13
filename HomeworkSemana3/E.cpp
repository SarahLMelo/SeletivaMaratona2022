#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> g(n);
    vector <bool> vis (n);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector <int> ans;
    priority_queue <int, vector<int>, greater<int>> pq;

    pq.push(0);
    while(!pq.empty()){
        int temp = pq.top();
        pq.pop();

        if(vis[temp] == 1) continue;
        vis[temp] = 1;
        ans.push_back(temp);

        for(auto i:g[temp]) pq.push(i);
    }

    for(auto i:ans){
        cout << ++i << " ";
    }

    return 0;
}