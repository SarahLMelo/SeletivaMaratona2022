#include <bits/stdc++.h>

using namespace std;

void unionBuild(vector <int> &ds, vector <int> &size, int n){
    for(int i=0; i<n; i++){
        ds[i] = i; //Conjuntos Iniciais Contendo Somente o Elemento
        size[i] = 1; //Logo o tamanho é 1
    }

    return;
}

int unionFind(vector <int> &ds, int x){ //Procura quem é o pai de x
    if(ds[x] != x) ds[x] = unionFind(ds, ds[x]);
    return ds[x];
}

void unionUnion(vector <int> &ds, vector <int> &size, int a, int b){ //Junta os conjuntos
    a = unionFind(ds, ds[a]);
    b = unionFind(ds, ds[b]);

    if(size[a] < size[b]) swap(a,b);
    if(a != b) size[a] += size[b];
    ds[b] = a;

    return; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> p(n);
        vector <int> pais(n);
        vector <int> size(n);
        set <int> s;
        for(int i=0; i<n; i++){
            cin >> p[i];
            p[i]--;
        }

        unionBuild(pais, size, n);

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++) if(p[i] > p[j]) unionUnion(pais, size, i, j);
        }
        //for(auto i:pais) cout << i;
        //cout << endl;
        for(int i=0; i<n; i++) s.insert(unionFind(pais, pais[i]));

        cout << s.size() << "\n";
    }


    return 0;
}