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

int somaNos(NoArvore *raiz){
    if (raiz == NULL){
        return 0;
    }

    if(raiz->left == NULL && raiz->right == NULL){
        return raiz->data;
    }

    return somaNos(raiz->left) + somaNos(raiz->right);
}

void printArvore(NoArvore *&raiz){
    if(raiz != NULL){
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
    raiz->left->right = inserirNo(3);
    raiz->right->left = inserirNo(5);
    // raiz->right->right = inserirNo(1);

    printArvore(raiz);
    cout<<endl;

    int soma = somaNos(raiz);
    cout << "Soma dos Nos folhas: " << soma << endl;

    return 0;
}
