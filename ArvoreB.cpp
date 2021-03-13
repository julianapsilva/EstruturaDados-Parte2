#include "ArvoreB.h"
#include "NoB.h"
#include <iostream>

using namespace std;

ArvoreB::ArvoreB(int dMin, HashTable *t)
{
    raiz = NULL;
    this->ordem=2*dMin;
    this->t=t;

}

int ArvoreB::busca(int val)
{
    if(raiz==NULL)
        return 0;
    else
       return raiz->busca(val);
}

void ArvoreB::insere(string data, int codCidade){

    if(raiz == NULL){
        raiz = new NoB(ordem,t);
        raiz->setFolha(true);
        raiz->setChave(t->getIndice(data,codCidade),0);
        raiz->setN(1);

    }
    else{
        if(raiz->getN()==ordem-1){   //raiz esta cheia
            NoB* novo= new NoB(ordem,t);
            novo->setFolha(false);
            novo->setFilho(raiz,0);
            novo->divideFilho(raiz,0);
            int i = 0;
            /*if(t->getCidade(novo->getChave(0)) < codCidade ||
                (t->getCidade(novo->getChave(0))==codCidade && t->getData(novo->getChave(0)) < data) ) */
                if(t->getCidade(novo->getChave(0)) < codCidade)
                i++;
            novo->getFilho(i)->insereComEspaco(data,codCidade);
            raiz=novo;
    }
        else{
            raiz->insereComEspaco(data,codCidade);
        }

    }
}

void ArvoreB::imprime(ostream & o){
    if(raiz!=NULL)
        raiz->imprime(o);
}


void ArvoreB::imprime(){
    if(raiz!=NULL)
        raiz->imprime();
}
