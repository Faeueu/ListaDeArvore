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
        cout << raiz->data << " ";
        printArvore(raiz->left);
        printArvore(raiz->right);
    }
}

bool arvoresIguais(NoArvore* raiz1, NoArvore* raiz2) {
    if (raiz1 == NULL && raiz2 == NULL){
        return true;
    }

    if (raiz1 == NULL || raiz2 == NULL){
        return false;
    }

    return (raiz1->data == raiz2->data) &&
        arvoresIguais(raiz1->left, raiz2->left) &&
        arvoresIguais(raiz1->right, raiz2->right);
}

int main(){
    NoArvore *raiz1 = inserirNo(1);
    raiz1->left = inserirNo(2);
    raiz1->right = inserirNo(3);

    NoArvore *raiz2 = inserirNo(1);
    raiz2->left = inserirNo(2);
    raiz2->right = inserirNo(3);

    printArvore(raiz1);
    cout << endl;
    printArvore(raiz2);
    cout << endl;

    if(arvoresIguais(raiz1, raiz2)){
        cout << "As arvores sao iguais" << endl;
    }else{
        cout << "As arvores nao sao iguais." << endl;
    }

    return 0;
}