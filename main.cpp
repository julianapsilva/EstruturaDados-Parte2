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
#include "Arquivo.h"
#include "ArvoreB.h"
#include <time.h>       /* time */

#include <random>

using namespace std;

int j=0;
bool Existe(int valores[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(valores[i]==valor)
            return true;
    }
    return false;
}

void GeraAleatorios(int numeros[],int quantNumeros,int Limite){
    srand(time(NULL));

    int v;
    for(int i=0;i<quantNumeros;i++){
        v = rand() % Limite;
        while(Existe(numeros,i,v)){
            v = rand() % Limite;
        }
        numeros[i] = v;
    }

}

/*

int random(int min, int max) {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distribution(min, max);

    //generating a random integer:
   // int x = distribution(gen);

     unsigned long x;
    x = rand();
    x <<= 15;
    x ^= rand();
    x %= max;

    return x;
}*/

NodeHT* getRandomValue(HashTable* ht){
    srand(time(NULL)); int random[10000];
    GeraAleatorios(random,10000,10000);   cout<< "gerou " << endl;

    int i = 0, max = ht->getTam();
    do{ i=random[j++];  cout<< "do " << endl;
        //i = random(0, max);
       // i=rand() % 32000;
       //  cout<< "valor de i " << i << endl;

    } while(ht->operator[](i)==NULL);

    NodeHT* n= ht->operator[](i);   cout<< "valor de i FINAL " << i << endl;
    return n;
}

/*
void teste(int n,int op,HashTable* dados,ArvBinBusca*loc){

    ofstream filestream("filename.txt");
    //  loc->imprime(filestream);
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
        ArvoreAVL arv(dados);

        for (int i = 0; i < n; i++) {
            NodeHT* m; int k;
            do {
                k = hashAleatorio(dados);
                m = (dados)->operator[](k);
            } while (arv.busca(k) || m==NULL );
            arv.insere(k);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }

    case 3: {
        ArvBinBusca arv;
        for (int i = 0; i < n; i++) {

            NodeHT* m;
            NoQArv* na;
            do {
                m = (getRandomValue(dados));
               na = loc->busca(m->codcidade);
            } while (arv.busca(m->codcidade)!=NULL || na==nullptr);


            arv.insere(na);
        }


        arv.imprime((n < 20) ? cout : filestream);

        break;
    }


    case 4: {
        ArvoreB arv(4,dados);

        for (int i = 0; i < n; i++) {


            NodeHT* m; int k;
            do {
                k = hashAleatorio(dados);
                m = (dados)->operator[](k);
            } while (arv.busca(k)!=-1 || m == NULL);

            arv.insere(m->codcidade);
        }
        arv.imprime((n < 20) ? cout : filestream);

        break;
    }
    }


}*/
void analiseBusca(int n, HashTable* h, int codCidade) {  cout<< "chamoiu busca " << endl;
ofstream filestream("filename.txt");
    ArvoreAVL avl(h); ArvoreB bMenor(5, h); ArvoreB bMaior(200, h); NodeHT *m;

    //for (int t = 0; t < 5; t++) {   // 5 diferentes conjuntos
        for (int i = 0; i < n; i++) {   cout<< "for index  "<<  i  << endl;
          cout<< "indo gerar aleatorio " << endl;
          m=getRandomValue(h);
           // avl.insere(m->data,m->codcidade);    cout<< "INSERIU " << endl;

          //  m=getRandomValue(h);
            bMenor.insere(m->data,m->codcidade);
            bMenor.imprime();
        /*    m=getRandomValue(h);
            bMaior.insere(m->data,m->codcidade);*/
        }



        //BUSCA S1
       /* cout << avl.busca(codCidade);
        cout << bMenor.busca(codCidade);
        cout << bMenor.busca(codCidade);*/

        //FALTA BUSCAS2

   // }

    avl.imprime();

}

int main()
{

    Arquivo arq;
    HashTable* ht = new HashTable(2000069);
    ArvBinBusca* Q = new ArvBinBusca();
    arq.leArqProcessado(ht, "processado.csv", 100000);
    arq.leArqCord(Q, "coordenadas.csv", -1);

  analiseBusca(50, ht, 509786);

//   teste(50, 1, ht, Q);
  // teste(50, 2, ht, Q);
 //  teste(50,3,ht,Q);
  // teste(50, 4, ht, Q);
  cout<< "-------- TERMINOU -------" << endl;

    return 0;
}




