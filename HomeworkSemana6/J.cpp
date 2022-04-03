#include <bits/stdc++.h>

using namespace std;

map <int, int> lastTime;

void prime(int l, vector <vector <int>> &g){
    int newL = l;
    if(!(newL%2)){
        if(lastTime.count(2)){
            g[lastTime[2]].push_back(l);   
        }   
        lastTime[2] = l;
        while(!(newL%2)) newL /= 2;
    }

    for(int i=3; i*i<=newL; i+=2){
        if(!(newL%i)){
            if(lastTime.count(i)){
                g[lastTime[i]].push_back(l);   
            }   
            lastTime[i] = l;
            while(!(newL%2)) newL /= i;
        }
    }

    if(newL > 1){
        if(lastTime.count(newL)){
            g[lastTime[newL]].push_back(l);   
        }   
        lastTime[newL] = l;
    }

    return;
}

int dfs(vector <vector <int>> &g, int pos, vector <bool> &vis){
    //cout << pos << " ";
    vis[pos] = 1;
    
    if(g[pos].empty()) return 1;
    int ans = 0;

    for(auto i:g[pos]){
        if(!vis[i]) ans = max(ans, dfs(g, i, vis) + 1);
    }

    return ans;
}

int main(){
    int n, ans = 0;
    cin >> n;
    vector <int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];

    vector <vector <int>> g(v[n-1]+1);

    for(int i=0; i<n; i++) prime(v[i], g);

    for(int i = 0; i<n; i++){
        vector <bool> vis(v[n-1]+1, 0);
        //cout << "ITERACAO " << i << " :";
        ans = max(ans, dfs(g, v[i], vis));
        //cout << "\n";
    }
    //cout << "\n";

    cout << ans << "\n";

    return 0;
}