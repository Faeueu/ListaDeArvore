//Dado uma árvore, retorne se ela é um BST ou não.
#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore *left; 
    NoArvore *right;
};

NoArvore *newNo(int valor){
    NoArvore *raiz = new NoArvore;
    raiz->data = valor;
    raiz->left = NULL;
    raiz->right = NULL;
    return raiz;
}

void inserir(NoArvore *&raiz, int valor){
    if(raiz == NULL){
        raiz = newNo(valor);
    }else{
        if(valor < raiz->data){
            inserir(raiz->left, valor);
        }else{
            inserir(raiz->right, valor);
        }
    }
}

bool verifyBST(NoArvore *&raiz, NoArvore *left=NULL, NoArvore *right=NULL) {
    if (raiz == NULL){
        return true;
    }

    if (left != NULL && raiz->data <= left->data){
        return false;
    }

    if (right != NULL && raiz->data >= right->data){
        return false;
    }

    return verifyBST(raiz->left, left, raiz) && 
        verifyBST(raiz->right, raiz, right);
}


int main() {
    NoArvore *raiz = NULL;
    inserir(raiz, 1);
    inserir(raiz, 2);
    inserir(raiz, 5);
    inserir(raiz, 9);
    inserir(raiz, 4);

    if (verifyBST(raiz, NULL, NULL))
        cout << "Esta arvore e um BST";
    else
        cout << "Esta arvore nao e um BST";

    return 0;
}