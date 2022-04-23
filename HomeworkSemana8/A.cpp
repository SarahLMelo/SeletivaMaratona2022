#include <bits/stdc++.h>

using namespace std;

#define alphabetSize 2

class trieNode{
    public:
    trieNode *children[alphabetSize];
    bool isEnd;
    int value;

    trieNode(){
        for(int i=0; i<alphabetSize; i++) children[i] = NULL;
        isEnd = false;
        value = -1;
    }
};

class trie{
    trieNode *root;


    public:
    trie(){
        root = new trieNode();
    }

    void insert(int x){
        trieNode *cur = root;
        for(int i = 31; i>=0; i--){
            bool bit = (1<<i) & x; //Olhando para o bit certo

            if(!cur->children[bit]){
                cur->children[bit] = new trieNode;
            }

            cur = cur->children[bit];
        }

        cur->isEnd = true;
        cur->value = x;

        return;
    }

    int query(int x){
        trieNode *cur = root;

        for(int i=31; i>=0; i--){ 
            bool bit = (1<<i) & x;

            if(cur->children[!bit]){ //Se tiver o bit oposto para ficar 1 no ^
                cur = cur->children[!bit];
            }
            else cur = cur->children[bit]; //O famoso é o jeito
        }

        return x ^ cur->value;
    }
};

void solve(vector <int> &v){
    trie dic;
    dic.insert(0);

    int result = INT_MIN, prefixXor = 0;

    for(int i=0; i<v.size(); i++){
        prefixXor ^= v[i];
        dic.insert(prefixXor);
        
        result = max(result, dic.query(prefixXor));
    }

    cout << result << "\n";

    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        solve(v);
    }

    return 0;
}