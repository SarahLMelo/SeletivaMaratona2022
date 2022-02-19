#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> times (n, 0), programadores(n);
    priority_queue <pair<int, int>> pq;

    for(int i=0; i<n; i++){
        cin >> programadores[i];
        pq.push({programadores[i], i});
    }

    int escolha = 1;
    while(!pq.empty()){
        if(times[pq.top().second]==0){
            times[pq.top().second] = escolha;
            for(int i=1; i<=k; i++){
                if(pq.top().second - i >= 0){
                    if(times[pq.top().second - i]==0) times[pq.top().second - i] = escolha;
                    else{
                        for(int j = i+1; pq.top().second - j>=0; j++){
                            if(times[pq.top().second - j]==0){
                                times[pq.top().second - j] = escolha;
                                break;
                            }
                        }
                    }
                }

                if(pq.top().second + i < n){
                    if(times[pq.top().second + i]==0) times[pq.top().second + i] = escolha;
                    else{
                        for(int j = i+1; pq.top().second + j<n; j++){
                            if(times[pq.top().second + j]==0){
                                times[pq.top().second + j] = escolha;
                                break;
                            }
                        }
                    }
                }
            }

            if(escolha == 1) escolha = 2;
            else escolha = 1;
        }

        pq.pop();
    }

    for(auto i:times) cout << i;
    cout << "\n";

    return 0;
}