#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    stack <int> santasPile, minPile;
    string command;
    cin >> t;

    while(t--){
        cin >> command;
        if(command == "PUSH"){
            int n;
            cin >> n;
            santasPile.push(n);
            if(minPile.empty() || minPile.top() >= n) minPile.push(n); 

        }

        else if(command == "POP"){
            if(santasPile.empty()) cout << "EMPTY\n\n";
            else{
                if(santasPile.top()==minPile.top()) minPile.pop();
                santasPile.pop();
            }
        }

        else{
            if(santasPile.empty()) cout << "EMPTY\n\n";
            else cout << minPile.top() << "\n\n";
        }
    }


    return 0;
}