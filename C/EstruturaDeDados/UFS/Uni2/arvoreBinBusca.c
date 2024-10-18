#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int dado;
    struct node *pai;
    struct node *filhoEsq;
    struct node *filhoDir;     
}tipoNode;

//Tipo abaixo só deve ser definido qdo começarmos a fazer buscas na Árvore
typedef struct {
    int encontrou; //Se encontrou recebe 1, caso contrario recebe 0
    tipoNode* noOuPai;
    char tipoFilho;
}tipoVolta;

tipoNode *achou;

tipoVolta* criaVolta(tipoNode* no, char tf , int seAchou){
    tipoVolta* aux = (tipoVolta*) malloc(sizeof(tipoVolta));
    aux->encontrou = seAchou;
    aux->noOuPai = no;
    aux->tipoFilho = tf;
    return aux;
}

//Fun para criar nó

tipoNode* criarNo(int n, tipoNode *noPai){
    tipoNode *novo;
    novo = (tipoNode*) malloc(sizeof(tipoNode));
    novo->dado = n;
    novo->pai = noPai;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}

void exibePosOrdem(tipoNode *atual){
    if (atual !=NULL)
    {
        exibePosOrdem(atual->filhoEsq);
        exibePosOrdem(atual->filhoDir);
        printf("\n %d", atual->dado);
    }
    
}

void exibeInOrdem(tipoNode *atual){
if(atual!=NULL){
    exibeInOrdem(atual->filhoEsq);
    printf("\n%d",atual->dado);
    exibeInOrdem(atual->filhoDir);
    }
}

tipoNode* buscaNo2(tipoNode *atual , int n){
    if (atual != NULL)
    {
        if (atual->dado == n)
        {
            return atual;
        }
        tipoNode *r1 = buscaNo2(atual->filhoEsq , n);
        if(r1 != NULL) return r1;
        tipoNode *r2 = buscaNo2(atual->filhoDir , n);
        if(r2 != NULL) return r2;    
    }
    return NULL;
}

