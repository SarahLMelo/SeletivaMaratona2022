#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, curCap = 0, maxCap=0;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        curCap-=a;
        curCap+=b;

        if(curCap>maxCap) maxCap = curCap;
    }

    cout << maxCap << "\n";

    return 0;
}