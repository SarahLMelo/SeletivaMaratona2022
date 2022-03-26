#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<bool, int> ib;

/*
 DP(pos, cor) -> NumeroDePretos (1);
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        //vector <int> color(n, -1);
        vector <vector <int>> g(n);
        vector <int> color(n, -1);
        vector <int> ans;

        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        priority_queue <ii, vector<ii>, greater<ii>> pq;
        for(int i=0; i<n; i++){
            pq.push({g[i].size(), i});
        }

        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();

            if(color[i] != -1) continue;
            color[i] = 1;
            ans.push_back(i+1);

            for(auto j:g[i]) color[j] = 0;
        }

        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}