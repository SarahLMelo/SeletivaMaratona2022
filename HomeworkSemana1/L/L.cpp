#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        long long int l, oc = 0;
        int m, cnt = 0;
        queue <int> left, right;
        bool side = false; //0 -> left
        cin >> l >> m;
        l *= 100;

        for(int i=0; i<m; i++){
            int size;
            string command;

            cin >> size >> command;
            if(command == "left") left.push(size);
            else right.push(size);
        }

        while(!left.empty() || !right.empty()){
            if(side == false){
                while(!left.empty() && oc+left.front() <= l){
                    oc += left.front();
                    left.pop();
                }
                cnt++;
                side = !side;
                oc = 0;
            }

            else{
                while(!right.empty() && oc+right.front() <= l){
                    oc += right.front();
                    right.pop();
                }
                cnt++;
                side = !side;
                oc = 0;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}