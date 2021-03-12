#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <iostream>

#include "hash.h"

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
int HashTable::getIndice(string data, int cod) {
    bool equals;
    int j = 0, i=0;

    do {
        i = funct(data, cod, j++);
        equals = tabela[i]->equals(data, cod);

         } while (tabela[i] != NULL && !equals && j < tam);
    if (tabela[i] == NULL)
        return -1.;
return i;
   
}
NodeHT* HashTable::busca(string data, int cod){
    int i = getIndice(data, cod);
    if (i!=-1)
        return tabela[i];
    else return NULL;

}
void HashTable::insereaux(NodeHT *item){

    int i; int j = 0;
    do{
        i=funct(item->data,item->codcidade,j++);
       

    }
    while(tabela[i]!=NULL);
    std::cout << i;

    tabela[i]=&(*item);

    tabela[i];
}

void HashTable::print(std::ostream &o){

    o<<"TABELA HASH TAMANHO "<<tam<<" LOTACAO"<<std::endl;
    for(int i=0;i<tam;i++)
    {
        if(tabela[i]!=NULL){
            string aux = tabela[i]->toString();
           (o) << i <<"" <<aux << std::endl;

        }
}
}

