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

int somaSubArvore(NoArvore *raiz, int &maiorValor){
    if (raiz == NULL){
        return 0;
    }

    int somaLeft = somaSubArvore(raiz->left, maiorValor);
    int somaRight = somaSubArvore(raiz->right, maiorValor);

    int valorSoma = raiz->data + somaLeft + somaRight;

    maiorValor = max(maiorValor, valorSoma);

    return max(raiz->data, raiz->data + max(somaLeft, somaRight));
}

int maxSubArvore(NoArvore *raiz){
    int maiorValor = -2147483648;
    somaSubArvore(raiz, maiorValor);
    return maiorValor;
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
    raiz->left = inserirNo(4);
    raiz->right = inserirNo(3);
    raiz->left->left = inserirNo(2);
    raiz->left->right = inserirNo(4);
    raiz->right->left = inserirNo(2);
    raiz->right->right = inserirNo(5);
    raiz->right->right->left = inserirNo(4);
    raiz->right->right->right = inserirNo(6);

    printArvore(raiz);
    cout << endl;

    int maxSoma = maxSubArvore(raiz);
    cout << "Maior Soma: " << maxSoma << endl;

    return 0;
}