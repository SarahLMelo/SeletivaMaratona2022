#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        bool valid = true;
        vector <bool> alreadyFound(n+1, 0);
        long long int x;
        cin >> x;
        stack <long long int> last;
        
        for(int i=1; i<n; i++){
            last.push(x);
            cin >> x;

            if(abs(x-last.top()) >= n || alreadyFound[abs(x-last.top())] == 1) valid = false;
            else alreadyFound[abs(x-last.top())] = 1;
        }

        if(valid == false || alreadyFound[0] == 1) cout << "Not j";
        else cout << "J";
        cout << "olly\n";
    }


    return 0;
}