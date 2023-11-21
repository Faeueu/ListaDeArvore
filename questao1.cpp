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

void printArvore(NoArvore *&raiz){
    if(raiz != NULL){
        printArvore(raiz->left);
        cout << raiz->data << " ";
        printArvore(raiz->right);
    }
}

int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = NULL;
    raiz->right = inserirNo(2);
    raiz->right->left = inserirNo(3);

    cout << "Arvore em ordem: " << endl;
    printArvore(raiz);

    return 0;
}
