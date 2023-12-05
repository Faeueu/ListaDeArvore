#include <iostream>
using namespace std;

struct NoArvore{
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

void converter(NoArvore *&raiz, int array[], int inicio, int fim){
    if(inicio > fim){
        return;
    }

    int meio = (inicio + fim) / 2;
    raiz = newNo(array[meio]);

    converter(raiz->left, array, inicio, meio-1);
    converter(raiz->right, array, meio+1, fim);
}

void printArvore(NoArvore *&raiz){
    if(raiz != NULL){
        printArvore(raiz->left);
        cout << raiz->data << " ";
        printArvore(raiz->right);
    }
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho = sizeof(array) / sizeof(array[0]);

    NoArvore *raiz = NULL;
    converter(raiz, array, 0, tamanho - 1);

    cout << "Array convertido em Arvore: " << endl;
    printArvore(raiz);

    return 0;
}