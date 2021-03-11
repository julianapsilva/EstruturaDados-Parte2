#include "hash.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>


HashTable::HashTable(int tam){
    this->tam=tam;
    tabela= (NodeHT**) malloc(sizeof(NodeHT*)*tam);
    for(int i=0;i<tam;i++)
    {
        tabela[i]=NULL;
    }

}
int HashTable::funct(string data, int cod,int j){
    strtok((char*)data.c_str(), "-");
    int mes = atoi(strtok(NULL, "-"));
    int dia = atoi(strtok(NULL, "-"));

    int cidade=(cod%10)%1000;
    int estado=(cod/1000);

    double key= ((cidade*dia + mes*estado)+j*j)%tam;

        return key;
}
NodeHT* HashTable::busca(string data, int cod){
    bool equals;
    int j=0,i;
    do{
        i=funct(data,cod,j++);
        equals=tabela[i]->equals(data,cod);
    }
    while(tabela[i]!=NULL && !equals && j<tam);
    if(j<tam && equals)
    return tabela[i];
    else return NULL;
}
void HashTable::insere(NodeHT *item){

    int i; int j = 0;
    do{
        i=funct(item->data,item->codcidade,j++);
        if(j>100)
            std::cout<<j<<std::endl;
    }
    while(tabela[i]!=NULL);
    tabela[i]=&(*item);
    tabela[i];
}

void HashTable::print(){
    for(int i=0;i<1000;i++)
    {
        if(tabela[i]!=NULL){
            string aux = tabela[i]->toString();
            std::cout<<aux;

        }
        }
}

