//Dado uma árvore retorne todos os caminhos da raiz até as folhas
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

int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(3);
    raiz->left->left = NULL;
    raiz->left->right = inserirNo(5);



    return 0;
}