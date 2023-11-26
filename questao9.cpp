//Dado uma árvore não balanceada, retorne ela balanceada.
#include <iostream>
using namespace std;

struct NoArvore{
    int data;
    NoArvore *left;
    NoArvore *right;
};

NoArvore* inserirNo(int value) {
    NoArvore* newNo = new NoArvore;
    newNo->data = value;
    newNo->left = NULL;
    newNo->right = NULL;
    return newNo;
}

int altura(NoArvore *raiz){
    if (raiz == NULL){
        return 0;
    }
    return 1 + max(altura(raiz->left), altura(raiz->right));
}

void rotacaoEsquerda(NoArvore *&raiz){
    NoArvore *filho = raiz->right;
    NoArvore *subArvore = filho->left;

    filho->left = raiz;
    raiz->right = subArvore;

    raiz = filho;
}

void rotacaoDireita(NoArvore *&raiz){
    NoArvore *filho = raiz->left;
    NoArvore *subArvore = filho->right;

    filho->right = raiz;
    raiz->left = subArvore;

    raiz = filho;
}

void balancear(NoArvore *&raiz){
    if(raiz == NULL){
        return;
    }

    int balanceamento = altura(raiz->left) - altura(raiz->right);

    if (balanceamento > 1){
        if (altura(raiz->left->left) >= altura(raiz->left->right)){
            rotacaoDireita(raiz);
        }else{
            raiz->left = raiz->left;
            rotacaoEsquerda(raiz->left);
            rotacaoDireita(raiz);
        }

    }else if (balanceamento < -1){
        if (altura(raiz->right->right) >= altura(raiz->right->left)){
            rotacaoEsquerda(raiz);
        }else{
            raiz->right = raiz->right;
            rotacaoDireita(raiz->right);
            rotacaoEsquerda(raiz);
        }
    }
    balancear(raiz->left);
    balancear(raiz->right);
}

void printArvore(NoArvore *&raiz){
    if (raiz != NULL){
        cout << raiz->data << " ";
        printArvore(raiz->left);
        printArvore(raiz->right);
    }
}

int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(3);
    raiz->left->left = inserirNo(4);
    raiz->left->right = inserirNo(5);
    raiz->right->left = inserirNo(6);
    raiz->right->right = inserirNo(7);
    raiz->left->left->left = inserirNo(8);
    raiz->left->left->left->left = inserirNo(9);
    

    printArvore(raiz);
    cout << endl;

    
    balancear(raiz);
    printArvore(raiz);

    return 0;
}