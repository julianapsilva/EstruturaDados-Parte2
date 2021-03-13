#include <iostream>
#include "ArvoreAVL.h"
#include "NodeHT.h"

using namespace std;

ArvoreAVL::ArvoreAVL(HashTable *t)
{
    raiz = NULL;
    this->h=t;
}

void ArvoreAVL::insere(string data, int codCidade)
{
    raiz = auxInsere(raiz,data, codCidade);
}

NoArv* ArvoreAVL::auxInsere(NoArv *p, string data, int codCidade)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(h->getIndice(data,codCidade));   cout<< "gerado pela has " << h->getIndice(data,codCidade) << endl;
        p->setEsq(NULL);
        p->setDir(NULL);
        p->setFator(0);
    }
    else if(codCidade< h->getCidade(p->getInfo()))
         p->setEsq(auxInsere(p->getEsq(),data,codCidade));

        else if(codCidade == h->getCidade(p->getInfo())){
            if(data < h->getData(p->getInfo()))
                p->setEsq(auxInsere(p->getEsq(),data,codCidade));
            else
                p->setDir(auxInsere(p->getDir(),data,codCidade));
        }
    else
        p->setDir(auxInsere(p->getDir(),data,codCidade));

    p->setFator(calculaAltura(p->getDir()) - calculaAltura(p->getEsq()));
    return verificaBalanceamento(p);
}

NoArv* ArvoreAVL::rotSimplesEsq(NoArv* p)
{
    NoArv *q = p->getDir();
    p->setDir(q->getEsq());
    q->setEsq(p);
    p->setFator(calculaAltura(p->getDir()) - calculaAltura(p->getEsq()) );
    q->setFator(calculaAltura(q->getDir()) - calculaAltura(q->getEsq()) );
    return q;
}

NoArv* ArvoreAVL::rotSimplesDir(NoArv* p)
{
    NoArv *q = p->getEsq();
    p->setEsq(q->getDir());
    q->setDir(p);
    p->setFator(calculaAltura(p->getDir()) - calculaAltura(p->getEsq()) );
    q->setFator(calculaAltura(q->getDir()) - calculaAltura(q->getEsq()) );
    return q;
}

NoArv* ArvoreAVL::verificaBalanceamento(NoArv *p)
{
    if(p->getFator() >= 2){
        if(p->getDir()->getFator() == 1 || p->getDir()->getFator() == 0){
            return rotSimplesEsq(p);
        }
        else if(p->getDir()->getFator() == -1){
            // rotacao dupla a esquerda
            p->setDir(rotSimplesDir(p->getDir()));
            return rotSimplesEsq(p);
        }
    }
    else if(p->getFator() ==-2){
        if(p->getEsq()->getFator() == -1 || p->getEsq()->getFator() == 0 ){
            // simples a direita
            return rotSimplesDir(p);
        }
        else if(p->getEsq()->getFator() == 1){
            //rotacao dupla a direita
             p->setEsq(rotSimplesEsq(p->getEsq()));
            return rotSimplesDir(p);
        }
    }
    return p;
}

int ArvoreAVL::calculaAltura(NoArv *p)  // calcula altura do no
{
    int i, j;
    if(p==NULL)
        return -1;

    i= calculaAltura(p->getDir());
    j= calculaAltura(p->getEsq());
    return i>j ? i+1 : j+1;
}


int ArvoreAVL::busca(int val)
{
    return auxBusca(raiz, val);
}

int  ArvoreAVL::auxBusca(NoArv *p, int val)
{
    int casos=0;
    if(p == NULL)
        return 0;
    else if(h->getCidade(p->getInfo()) == val){
        casos+=h->getCasos(p->getInfo());
    }
    else if(val < h->getCidade(p->getInfo()))
        casos= auxBusca(p->getEsq(), val);
    else
        casos= auxBusca(p->getDir(), val);
        return casos;
}
/*
void ArvoreAVL::imprime(std::ostream& o)
{
    imprimePorNivel(raiz, 0,o);
}

void ArvoreAVL::imprimePorNivel(NoArv *p, int nivel,std::ostream &o)
{
    if(p != NULL)
    {
        o << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            o << "--";
        o << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1,o);
        imprimePorNivel(p->getDir(), nivel+1,o);
    }
}*/


void ArvoreAVL::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvoreAVL::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
       // cout << p->getInfo() << endl;
        cout<< "data " << h->getData(p->getInfo()) << " codcidade " << h->getCidade(p->getInfo()) << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}














