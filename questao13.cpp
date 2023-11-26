//Dado uma árvore binaria com exatos 3 nós, a raiz, o filho da esquerda 
//e o filho da direita, retorne TRUE se a soma dos filhos 
//for igual ao valor da raiz,
//e FALSE caso seja diferente.

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

bool verifySoma(NoArvore *&raiz){
    if(raiz == NULL){
        return false;
    }

    int soma = 0;

    if(raiz->left != NULL){
        soma += raiz->left->data;
    }

    if(raiz->right != NULL){
        soma += raiz->right->data;
    }
    return soma == raiz->data;
}

int main(){
    NoArvore *raiz = inserirNo(10);
    raiz->left = inserirNo(6);
    raiz->right = inserirNo(4);

    if(verifySoma(raiz)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}