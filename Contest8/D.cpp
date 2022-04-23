#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

long long countDivisor(int a, int b){
    long long ans = 0;

    //cout << "HERE" << endl;

    for(int i=1; i*i<=(a-b); i++){
        if(!((a-b)%i)){
            if(i>b) ans++;
            if((a-b)/i > b) ans++;
        }

        //cout << "HERE" << endl;
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);  

    int a, b;
    cin >> a >> b;

    if(a<b) cout << 0 << "\n";
    else if(a == b) cout << "infinity\n";
    else cout << countDivisor(a, b) << "\n";

  return 0;
}