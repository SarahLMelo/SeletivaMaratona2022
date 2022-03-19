#include <bits/stdc++.h>

using namespace std;

void shiftLeft(vector <int> &arr, int n, int k, int last){
    vector <int> ans;
    for(int i=0; i<n; i++){
        if(i >= last) ans.push_back(arr[i]);
        else{
            int x = (i + k)%(last); 
            ans.push_back(arr[x]);

        }
    }

    swap(ans, arr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> arr(n);
        vector <int> ans(n, 0);

        for(int i=0; i<n; i++) cin >> arr[i];
        
        for(int i=n; i>1; i--){
            int pos = find(arr.begin(), arr.end(), i) - arr.begin();
            int k = pos - i;
            //cout << "i: " << i << endl;
            if(k<0) k = (pos + 1)%i;
            //cout << "k: " << k << endl;

            shiftLeft(arr, n, k, i);
            ans[i-1] = k;
            //for(auto x:arr) cout << x << " ";
            //cout << endl;
        }

        bool flag = false;
        for(int i=1; i<=n; i++) if(arr[i-1] != i) flag = true;
        if(flag) cout << "-1\n";
        else{
            for(int i=0; i<n-1; i++) cout << ans[i] << " ";
            cout << ans[n-1] << endl;
        }
    }

    return 0;
}
