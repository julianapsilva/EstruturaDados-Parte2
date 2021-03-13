#include "NoB.h"
#include "hash.h"
#include "NodeHT.h"
#include <iostream>
using namespace std;

NoB::NoB(int ordem, HashTable *t){
    this->ordem=ordem;
    this->chaves = new int[this->ordem-1];
    this->filhos= new NoB*[this->ordem];
    this->n=0;
    folha=true;
    this->h=t;
}

int NoB::busca(int val){
    int i = 0; int casos=0;
  /*  while(i<n && h->comparaChaves(val,h->getCidade(chaves[i]))==1)
        i++;
    if(h->getCidade(chaves[i])==val){
        casos+=h->getCasos(chaves[i]);
    }

    if(folha==true)
        return 0;

    casos=filhos[i]->busca(val); */
    return casos;
}

void NoB::insereComEspaco(string data, int codCidade)
{
    int i=n;
    if(folha){
        while(i>0 && (h->getCidade(chaves[i-1]) > codCidade ||
            (h->getCidade(chaves[i-1])==codCidade && h->getData(chaves[i-1])> data))){
            chaves[i]= chaves[i-1];
            i--;
        }
        chaves[i]=h->getIndice(data,codCidade);
        n++; }

    else{
        while(i>0 && (h->getCidade(chaves[i-1]) > codCidade ||
            (h->getCidade(chaves[i-1])==codCidade && h->getData(chaves[i-1])> data)))
            i--;

        if(filhos[i]->n==ordem-1){
            divideFilho(filhos[i],i);

        if(codCidade > h->getCidade(chaves[i]) ||
        ( codCidade== h->getCidade(chaves[i]) && data > h->getData(chaves[i])))
            i++; }

        filhos[i]->insereComEspaco(data,codCidade);
    }
}

void NoB::divideFilho(NoB* p,int i)
{
    int meio=(ordem+1)/2;
    NoB* aux= new NoB(ordem,h);
    aux->folha=p->folha;
    aux->n=meio;

    for(int j=0; j<meio-1;j++){
        aux->chaves[j]=p->chaves[j+meio];
    }

    if(!p->folha){
        for(int j=0;j<meio;j++){
            aux->filhos[j]=p->filhos[j+meio];
        }
    }
    p->n=meio;

    for(int j=p->n;j>=i+1;j--){
        p->filhos[j+1]=p->filhos[j];
    }
    p->filhos[i+1]=aux;

    for(int j=p->n-1;j>=i;j--){
        chaves[j+1]= chaves[j];
    }

    chaves[i]= p->chaves[meio-1];
    n++;
}

void NoB::imprime(ostream& o){
 int i;
  for (i = 0; i < n-1; i++) {
    if (folha == false){
        n=filhos[i]->n;
        filhos[i]->imprime(o);
    }
    o << chaves[i] << " " ;
  }

  if (folha == false)
    filhos[i]->imprime(o);
}


void NoB::imprime(){
 int i;
  for (i = 0; i < n-1; i++) {
    if (folha == false){
        n=filhos[i]->n;
        filhos[i]->imprime();
    }
    cout << chaves[i] << " " ;
    cout<< " codCity " << h->getCidade(chaves[i]) << " data " << h->getData(chaves[i])  << endl;
  }

  if (folha == false)
    filhos[i]->imprime();
}



