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

void exibirMenorNo(NoArvore *raiz, NoArvore *&menorNo){
    if(raiz == NULL){
        return;
    }
    if(raiz->left == NULL){
        menorNo = raiz;
        return;
    }
    exibirMenorNo(raiz->left, menorNo);
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

    NoArvore *menorNoArvore = NULL;
    exibirMenorNo(raiz, menorNoArvore);

    if(menorNoArvore != NULL){
        cout << "O menor no da arvore e: " << menorNoArvore->data << endl;        
    }else{
        cout << "Nao ha nenhum no na arvore" << endl;
    }
    
    return 0;
}