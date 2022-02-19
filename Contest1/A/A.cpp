#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        vector <int> entry;
        deque <int> lowest;

        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            entry.push_back(a);
        }

        lowest.push_back(entry[0]);

        for(int i=1; i<n; i++){
            if(entry[i]<=lowest.front()){
                lowest.push_front(entry[i]);
            }
            else lowest.push_back(entry[i]);
        }

        for(auto i:lowest) cout << i << " ";
        cout << "\n";
    }

    return 0;
}