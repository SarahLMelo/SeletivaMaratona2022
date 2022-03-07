#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long

int comb(int n, int k){
    double res = 1;
    for(int i=1; i<=k; i++){
        res = res*(n-k+i)/i;
    }

    return (int) (res+0.01);
}

int bt(vector <ll> &w, int &n, int &k, ll &a, ll &b, int pos, ll weightAlready, int carregados){
    if(pos==n || carregados == k){
        if(weightAlready>=a && weightAlready<=b && carregados == k) return 1;
        else return 0;
    }
    if(weightAlready>b) return 0;

    ll sum = 0;
    for(int i = pos; i<n; i++) sum += w[i];

    if(weightAlready + sum < a) return 0;
    if(weightAlready + sum <= b) return comb(n-pos, k - carregados);

    int pega = 0, nPega = 0;
    pega = bt(w, n, k, a, b, pos+1, weightAlready+w[pos], carregados+1);
    if(n-(pos+1) + weightAlready >= k) nPega = bt(w, n, k, a, b, pos+1, weightAlready, carregados);

    return  pega + nPega;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <ll> boxes(n);
    for(int i=0; i<n; i++) cin >> boxes[i];

    ll a, b;
    cin >> a >> b;

    cout << bt(boxes, n, k, a, b, 0, 0, 0) << endl;

    return 0;
}