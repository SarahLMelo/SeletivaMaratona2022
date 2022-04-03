#include <iostream>

using namespace std;

struct node{
    int numero, altura, pesodireita, pesoesquerda;
    node *esquerda;
    node *direita;
};

struct BST{
    node *raiz;
    int contaNo;
};

int getBalanced(node *rt);
node* rightRotate(node rt);
node* leftRotate(node rt);

int h(node* a){
    if(a==NULL){
        return -1;
    }
    return a->altura;
}

node* newnode(int a){
    node *temp = (node*)malloc(sizeof(node));
    temp->numero = a;
    temp->pesodireita = temp->pesoesquerda = temp->altura = 0;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

BST* criabst(){
    BST *arvore = (BST*)malloc(sizeof(BST));
    arvore->contaNo = 0;
    arvore->raiz = NULL;
    return arvore;
}

node* inserir(node* no, int numero){
    if(no==NULL){
        return (newnode(numero));
    }
    if(numero<no->numero){
        no->esquerda=inserir(no->esquerda, numero);
        no->pesoesquerda++;
    }
    else if(numero>=no->numero){
        no->direita=inserir(no->direita, numero);
        no->pesodireita++;
    }
    no->altura = 1 + max(h(no->esquerda), h(no->direita));
    int balance = getBalanced(no);
    if ((balance < -1) && (numero >= no->direita->numero)){
        return leftRotate(*no);
    }
    if ((balance > 1) && (numero < no->esquerda->numero)){
        return rightRotate(*no);
    }
    if ((balance > 1) && (numero >= no->esquerda->numero)){
        no->esquerda = leftRotate(*no)->esquerda;
        return rightRotate(*no);
    }
    if((balance < -1) && (numero < no->direita->numero)){
        no->direita = leftRotate(no->direita);
        return leftRotate(*no);
    }
    return no;    
}

node inserthelp(node *rt, int k, int e){

    if(rt==NULL){
        return inserir(k, e);
    }
    if(rt->numero > k){
        rt->esquerda->inserthelp((*rt)->esquerda, k, e);
    }else{
        rt->direita->inserthelp((*rt)->direita, k, e);
    }
    return rt;
}

int getBalanced(node *rt){
    if(rt==NULL){
        return 0;
    }
    return h(rt->esquerda)-h(rt->direita); //ta pendendo pra direita com o -1 e pra esquerda com o 1
}

node* rightRotate(node rt){
    node l* = rt->esquerda;
    node lr = rt->direita;
    rt->direita = rt;
    rt->esquerda = lr;
    rt->altura = max(h(rt->esquerda), h(rt->direita)) + 1;
    l->altura = max(h(l->esquerda), h(l->direita)) + 1;
    return l;
}

node* leftRotate(node rt){
    node r = rt->direita;
    node rl = rt->esquerda;
    rt->esquerda = rt;
    rt->direita = rl;
    rt->altura = max(h(rt->esquerda), h(rt->direita)) + 1;
    r->altura = max(h(r->esquerda), h(r->direita)) + 1;
    return r;
}

void search(node *no, int x){
    if(no==NULL){
        cout>>"data tidak ada\n";
    }
    if(x<no->numero){
        return search(no->esquerda, x);        
    }
    if(x>no->numero){
        return search(no->direita, x);
    }
    if(x==no->numero){
        cout>>no->altura >> "\n";
    }
}


int main()
{
    int queries, operacao, x; 
    BST arvo = criabst();
    cin>>queries;
    while (queries--){
        cin>>operacao>>x;
        switch (operacao){
        case 1:
            inserir(arvo->raiz, x);
            break;
        
        default:
            search(arvo, x);
            break;
        }
    }
    return 0;
}