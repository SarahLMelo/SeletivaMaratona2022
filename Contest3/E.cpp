#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    bool first = true;

    while(t--){
        if(!first) cout << "\n";
        first = false;

        int n;
        int nextColor = 0;
        char c;
        cin >> c;
        n = (int)(c - 'A' + 1);

        vector <vector <int>> g(n);
        vector <int> color(n, -1);

        cin.ignore(1);
        string edge;
        getline(cin, edge);
        while(edge!=""){
            char c2;
            c = edge[0];
            c2 = edge[1];
            g[(int)(c - 'A')].push_back((int)(c2 - 'A'));
            g[(int)(c2 - 'A')].push_back((int)(c - 'A'));
            getline(cin, edge);
            //cout << "HERE" << endl;
        }

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                stack <int> q;
                q.push(i);

                while(!q.empty()){
                    int temp = q.top();
                    q.pop();
                    if(color[temp] != -1) continue;
                    
                    color[temp] = nextColor;
                    for(auto j:g[temp]) q.push(j);
                }

                nextColor++;
            }
        }

        cout << nextColor << "\n";
    }

    return 0;
}