#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l = 0, r = 0, k = 0;
    vector <bool> doors;
    cin >> n;

    for(int i=0; i<n; i++){
        bool door;
        cin >> door;
        doors.push_back(door);

        if(door == 0) l++;
        else r++;
    }

    while(r>0 && l>0){
        if(doors[k] == 0) l--;
        else r--;
        k++;
    }

    cout << k << "\n";


    return 0;
}