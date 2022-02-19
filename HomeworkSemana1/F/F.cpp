#include <bits/stdc++.h>

using namespace std;

int main(){
    int block;
    cin >> block;

    while(block){
        int test;
        cin >> test;
        if(test != 0){
            bool ans = true;
            stack <int> B, station;
            B.push(test);

            for(int i=1; i<block; i++){
                int x;
                cin >> x;
                B.push(x);
            }

            for(int i=block; i>=1 && ans == true; i--){
                if(station.empty()){
                    station.push(B.top());
                    B.pop();
                }

                while(station.top() != i){
                    if(B.empty()){
                        ans = false;
                        break;
                    }
                    station.push(B.top());
                    B.pop();
                }
                station.pop();
            }

            if(ans == true) cout << "Yes\n";
            else cout << "No\n";
        }
        else{
            cout << "\n";
            cin >> block;
        }
    }


    return 0;
}