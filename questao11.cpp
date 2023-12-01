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

void inverter(NoArvore *raiz){
    if(raiz == NULL){
        return;
    }
    NoArvore *temp = raiz->left;
    raiz->left = raiz->right;
    raiz->right = temp;

    inverter(raiz->left);
    inverter(raiz->right);
}

void printArvore(NoArvore *&raiz){
    if(raiz != NULL){
        cout << raiz->data << " ";
        printArvore(raiz->left);
        printArvore(raiz->right);
    }
}

int main(){
    NoArvore *raiz = inserirNo(4);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(7);
    raiz->left->left = inserirNo(1);
    raiz->left->right = inserirNo(3);
    raiz->right->left = inserirNo(6);
    raiz->right->right = inserirNo(9);

    cout << "Arvore original: " << endl;
    printArvore(raiz);
    cout <<endl;

    inverter(raiz);
    cout << "Arvore apos inverter: " << endl;
    printArvore(raiz);

    return 0;
}
