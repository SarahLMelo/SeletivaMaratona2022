#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> cards(n);
    for(int i=0; i<n; i++) cin >> cards[i];

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = 0;

            for(int k=0; k<n; k++){
                if(k>=i && k<=j) temp += (1-cards[k]);
                else temp += cards[k];
            }

            ans = max(ans, temp);
        }
    }

    cout << ans << "\n";

    return 0;
}