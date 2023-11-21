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
int profundidade(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int profundidadeLeft = profundidade(raiz->left);
        int profundidadeRight = profundidade(raiz->right);

        if (profundidadeLeft > profundidadeRight) {
            return profundidadeLeft + 1;
        } else {
            return profundidadeRight + 1;
        }
    }
}

int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(3);
    raiz->left->left = inserirNo(4);
    raiz->left->right = inserirNo(5);

    cout << "Profundidade da arvore: " << profundidade(raiz);

    return 0;
}
