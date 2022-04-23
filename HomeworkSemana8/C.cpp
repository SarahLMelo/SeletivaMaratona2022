#include <bits/stdc++.h>

using namespace std;

#define alphabetSize 2

class trieNode{
    public:
    trieNode *children[alphabetSize];
    bool isEnd;
    int maxWordSize;

    trieNode(){
        for(int i=0; i<alphabetSize; i++) children[i] = NULL;
        isEnd = false;
        maxWordSize = 0;
    }
};

class trie{
    trieNode *root;

    public:
    trie(){
        root = new trieNode();
    }

    void insert(string key){
        trieNode *cur = root;
        int keySize = key.size();
        for(int i=0; i<keySize; i++){
            int id = key[i] - 'a';

            if(!cur->children[id]){
                cur->children[id] = new trieNode;
            }

            cur->maxWordSize = max(cur->maxWordSize, keySize - i - 1);
            cur = cur->children[id];
        }

        cur->isEnd = true;
    }

    bool search(string key){
        trieNode *cur = root;
        
        for(auto i:key){
            int id = i - 'a';

            if(!cur->children[id]) return false;

            cur = cur->children[id];
        }

        return cur->isEnd;
    }

    int minMaxSize(){
        int bestAns = 1e9+7;
        for(auto i:root->children){
            if(i == NULL) continue;

            bestAns = min(bestAns, )
        }
    }
};

int main(){
    int n, k;
    trie arv;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        arv.insert(s);
    }


    return 0;
}