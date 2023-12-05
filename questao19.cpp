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

void exibirMaiorNo(NoArvore *raiz, NoArvore *&maiorNo){
    if(raiz == NULL){
        return;
    }
    if(raiz->right == NULL){
        maiorNo = raiz;
        return;
    }
    exibirMaiorNo(raiz->right, maiorNo);
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

    NoArvore *maiorNoArvore = NULL;
    exibirMaiorNo(raiz, maiorNoArvore);

    if(maiorNoArvore != NULL){
        cout << "O maior no da arvore e: " << maiorNoArvore->data << endl;        
    }else{
        cout << "Nao ha nenhum no na arvore" << endl;
    }
    
    return 0;
}