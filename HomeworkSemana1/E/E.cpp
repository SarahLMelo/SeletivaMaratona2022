#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n != 0){
        map <vector<int>, int> m;

        while(n--){
            vector <int> choices;
            for(int i = 0; i<5; i++){
                int x;
                cin >> x;
                choices.push_back(x);
            }
            sort(choices.begin(), choices.end());

            m[choices]++;
        }

        int ans = 0;
        int empate = 0;

        for(auto i:m){
            if(i.second>ans){
                empate = 0;
                ans = i.second;
            }
            else if(i.second == ans) empate++;
        }

        cout << ans*(empate+1) << "\n";

        cin >> n;
    }


    return 0;
}