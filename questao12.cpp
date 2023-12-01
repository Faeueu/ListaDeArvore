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

NoArvore *merge(NoArvore *raiz1, NoArvore *raiz2){
    if (raiz1 == NULL){
        return raiz2;
    }
    if (raiz2 == NULL){
        return raiz1;
    }

    NoArvore *newNo = inserirNo(raiz1->data + raiz2->data);

    newNo->left = merge(raiz1->left, raiz2->left);
    newNo->right = merge(raiz1->right, raiz2->right);

    return newNo;
}

void printArvore(NoArvore *&raiz){
    if(raiz != NULL){
        cout << raiz->data << " ";
        printArvore(raiz->left);
        printArvore(raiz->right);
    }
}

int main(){
    NoArvore *raiz1 = inserirNo(1);
    raiz1->left = inserirNo(3);
    raiz1->right = inserirNo(2);
    raiz1->left->left = inserirNo(5);

    NoArvore *raiz2 = inserirNo(2);
    raiz2->left = inserirNo(1);
    raiz2->right = inserirNo(3);
    raiz2->left->right = inserirNo(4);
    raiz2->right->right = inserirNo(7);
    
    cout << "Raiz1: ";
    printArvore(raiz1);
    cout<<endl;
    
    cout << "Raiz2: ";
    printArvore(raiz2);
    cout<<endl;

    NoArvore *mergeArvore = merge(raiz1, raiz2);
    cout << "Merge de Raiz1 e Raiz2: " << endl;
    printArvore(mergeArvore);

    return 0;
}
