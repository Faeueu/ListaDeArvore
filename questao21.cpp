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

void buscaBST(NoArvore *raiz, int value){
    if(raiz == NULL) {
        cout << "Valor nao encontrado" << endl;
        return;
    }

    if(raiz->data == value){
        cout << "Valor " << value << " encontrado!" << endl;
    }else if(value < raiz->data){
        buscaBST(raiz->left, value);
    }else{
        buscaBST(raiz->right, value);
    }
}
int main(){
    NoArvore *raiz = NULL;
    inserir(raiz, 5);
    inserir(raiz, 3);
    inserir(raiz, 2);
    inserir(raiz, 4);
    inserir(raiz, 7);
    inserir(raiz, 6);
    inserir(raiz, 8);

    int buscaValor = 2;
    buscaBST(raiz, buscaValor);

    return 0;
}