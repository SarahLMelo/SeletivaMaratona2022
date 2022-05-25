#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b, vector <vector <int>> &g){
    int ans = false;

    queue <int> q;
    q.push(a);

    while(!(q.empty() || ans)){
        int v = q.front();
        q.pop();

        if(v == b) ans = true;
        else{
            for(auto i:g[v]) q.push(i);
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    map <string, int> map1;
    int cnt = 0;
    vector <vector <int>> g;

    for(int i=0; i<n; i++){
        string a, b, trash;
        cin >> a >> trash >> trash >> trash >> b;

        if(map1.find(a) == map1.end()){
            map1[a] = cnt;
            cnt++;
            g.push_back({});
        }
        if(map1.find(b) == map1.end()){
            map1[b] = cnt;
            cnt++;
            g.push_back({});
        }

        g[map1[a]].push_back(map1[b]);
    }

    for(int i=0; i<m; i++){
        string a, b, trash;
        cin >> a >> trash >> trash >> trash >> b;

        if(map1.find(a) == map1.end() || map1.find(b) == map1.end()) cout << "Pants on Fire\n";
        else if(check(map1[a], map1[b], g)) cout << "Fact\n";
        else if(check(map1[b], map1[a], g)) cout << "Alternative Fact\n";
        else cout << "Pants on Fire\n";
    }

    return 0;
}