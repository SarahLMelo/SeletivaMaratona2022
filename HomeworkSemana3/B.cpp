#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> priority(n, 0);
    vector <vector <int>> libera(n);
    vector <int> ans;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        priority[y]++;
        libera[x].push_back(y);
    }

    bool end = false;
    while(!end){
        end = true;
        for(int i=0; i<n; i++){
            if(priority[i] == 0){
                end = false;
                ans.push_back(i);
                if(!libera[i].empty()) for(auto j:libera[i]){
                    priority[j]--;
                }
                priority[i]--;
                break;
            }
        }
    }

    if(ans.size() != n) cout << "Sandro fails.\n";
    else for(int i=0; i<ans.size(); i++) cout << ++ans[i] << " ";


    return 0;
}