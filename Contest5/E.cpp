#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, r = 0, b = 0;

    cin >> n;

    for(int i=0; i<n; i++){
        long long x;
        cin >> x;

        if(!(x%2)){
            r += (x/2);
            b += (x/2);
        }
        else{
            if(i%2){
                r += (x/2) + 1;
                b += (x/2);
            }
            else{
                b += (x/2) + 1;
                r += (x/2);
            }
        }
    }

    //cout << r << b << "\n";

    cout << min(r, b) << "\n";

    return 0;
}