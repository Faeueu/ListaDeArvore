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
    if(raiz == NULL){
        return 0;
    }
    return 1+max(altura(raiz->left), altura(raiz->right));
}

int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(3);
    raiz->left->left = inserirNo(4);
    raiz->left->right = inserirNo(5);

    cout << "Altura da arvore: " << altura(raiz);

    return 0;
}

