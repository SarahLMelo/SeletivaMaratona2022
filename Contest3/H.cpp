#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, d;
        cin >> n >> d;
        long long int number = 0;

        for(int i=0; i<n; i++){
            int bit;
            cin >> bit;
            number = number << 1;
            number += bit;
        }

        bool check = true;
        int ans = 0;

        while(check && number!=0){
            ans++;
            int temp1 = number, temp2 = 0;

            for(int i=0; i<d; i++){
                int test = 1;
                test = test << i;
                temp2 += (temp1%2) * test;
                temp1 = temp1 >> 1;
            }

            temp2 = temp2 << (n-d);

            temp1 += temp2;

            number = number&temp1;
            if(number == temp1) check = false;
        }

        if(!check) cout << "-1\n";
        else cout << ans << "\n";

    }

    return 0;
}