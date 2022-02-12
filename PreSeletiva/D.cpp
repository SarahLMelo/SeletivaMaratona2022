#include <bits/stdc++.h>

using namespace std;


int main(){
    int N, ans;
    cin >> N;

    ans = N/2 + 1;
    cout << ans << "\n";

    for(int i=1; i<=N; i+=2) cout << i << " ";
    if(N%2==0) cout << N << " ";

    return 0;
}