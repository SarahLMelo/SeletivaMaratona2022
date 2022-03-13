#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
vector <int> ordemDeLeitura((2*1e5) + 5);

bool cmp(int a, int b){
    return ordemDeLeitura[a] < ordemDeLeitura[b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <vector <int>> g(n);
    vector <int> vis(n);
    int arr[n];

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        --x;
        --y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i]--;
        ordemDeLeitura[arr[i]] = i;
    }

    for(int i=0; i<n; i++){
        sort(g[i].begin(), g[i].end(), cmp);
    }

    queue <int> q;
    vector <int> ans;
    q.push(0);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(vis[temp] == 1) continue;
        
        vis[temp] = 1;
        ans.push_back(temp);
        
        for(auto i:g[temp]) q.push(i);
    }

    for(int i=0; i<n; i++){
        if(arr[i] != ans[i]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}