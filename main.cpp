#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include "ArvBinBusca.h"
#include "hash.h"
#include <sstream>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include "ArvoreB.h"


using namespace std;
int leArqProcessado(HashTable* ht, string endr,int n){
    ifstream arq(endr);
    if(!arq.is_open())
        return -1;
    string str;
    int i=0;
    getline(arq, str);
    while(getline(arq,str))
    {

      char *subdado;
      subdado = strtok( &str[0], ",");
      string data=subdado;
      subdado = strtok( NULL, ",");
      string estado= subdado;
      subdado = strtok( NULL, ",");
      string cidade= subdado;
      subdado = strtok( NULL, ",");
      int cod= atoi(subdado);
      subdado = strtok( NULL, ",");
      int casos= atoi(subdado);
      subdado = strtok( NULL, ",");
      int  mortes= atoi(subdado);
      ht->insere(cod,data,cidade,estado,casos,mortes);
        if(i++>n && n!=-1)
            break;
    }
    return 0;

}
int leArqCord(ArvBinBusca* ht, string endr, int n) {
    ifstream arq(endr);
    if (!arq.is_open())
        return -1;
    string str;
    int i = 0;
    getline(arq, str);

    while (getline(arq, str))
    {

        char* subdado;
        subdado = strtok(&str[0], ",");
        int estado = atoi(subdado);
        subdado = strtok(NULL, ",");
        int cidade = atoi(subdado)/10;
        subdado = strtok(NULL, ",");
        string nome = subdado;
        subdado = strtok(NULL, ",");
        int x = atoi(subdado);
        subdado = strtok(NULL, ",");
        int  y = atoi(subdado);
        subdado = strtok(NULL, ",");
        int  cap = atoi(subdado);
        ht->insere(estado,  cidade,nome, x,y,cap);
        if (i++ > n && n != -1)
            break;
    }
    return 0;

}
int random(int min, int max) {
    return rand() % (max + 1 - min) + min;

}
NodeHT* getRandomValue(HashTable* ht){
    int i=0;
    do
        i=random(0,ht->getTam());
    while(ht->operator[](i)==NULL);

    NodeHT* n= ht->operator[](i);
    return n;
}
void teste(int n,int op,HashTable* dados,ArvBinBusca*loc){

    ofstream filestream("filename.txt");

    loc->imprime(filestream);
    switch (op) {
    case 1: {
        HashTable h(n + n / 20);

        for (int i = 0; i < n; i++) {

            NodeHT* m = (getRandomValue(dados));
            h.insere(m);
        }
        h.print((n < 20) ? cout : filestream);
        break;
    }

    case 2: {
        ArvoreAVL arv;

        for (int i = 0; i < n; i++) {

            NodeHT* m = (getRandomValue(dados));
            arv.insere(m->codcidade);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }

    case 3: {
        ArvBinBusca arv;
        for (int i = 0; i < n; i++) {

            NodeHT* m = (getRandomValue(dados));
            NoQArv* na = loc->busca(m->codcidade);
            if (na == NULL)
                std::cout << "asdad";
            arv.insere(na);
        }


        arv.imprime((n < 20) ? cout : filestream);

        break;
    }


    case 4: {
        ArvoreB arv(4);

        for (int i = 0; i < n; i++) {

            NodeHT* m = (getRandomValue(dados));
            arv.insere(m->codcidade);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }
    }


}
int main()
{

    HashTable* ht=new HashTable(2000069);
    ArvBinBusca* Q=new ArvBinBusca ();
    leArqProcessado(ht,"processado.csv",1000);
    leArqCord(Q, "coordenadas.csv", -1);
    ht->print(cout);
    teste(50,4,ht,Q);
    return 0;
}
