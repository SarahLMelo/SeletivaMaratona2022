#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i = 1; i<=T; i++){
        int n;
        cin >> n;

        vector <int> runners;

        while(n--){
            int speed;
            cin >> speed;
            runners.push_back(speed);
        }

        cout << "Case " << i << ": " << *max_element(runners.begin(), runners.end()) << "\n";
    }


    return 0;
}