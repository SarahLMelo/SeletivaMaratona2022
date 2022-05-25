#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int A, B;
vector <ll> w;

int comb(int n, int k){
    double res = 1;
    for(int i=1; i<=k; i++){
        res = res*(n-k+i)/i;
    }

    return (int) (res+0.01);
}

int bt(int i, int taken, int sum){
    if(k==taken && sum>=A && sum<=B) return 1;

    if(k < taken) return 0;
    if(sum > B) return 0;
    if(i == n) return 0;

    int take, notTake;
    take = (i+1, taken+1, sum+w[i]);
    notTake = (i+1, taken, sum);

    return take+notTake;
}

int main(){
    cin >> n >> k;

    w.resize(n);
    for(int i=0; i<n; i++) cin >> w[i];

    cin >> A >> B;

    cout << bt(0, 0, 0) << "\n";

    return 0;
}