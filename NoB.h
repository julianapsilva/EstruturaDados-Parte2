#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include <iostream>
#include "NodeHT.h"
#include "hash.h"
using namespace std;
class NoB
{
    private:
        int* chaves;
        NoB** filhos;
        int n;
        int ordem;
        bool folha;
        HashTable* h;

    public:
        NoB(int ordem);
        NoB(int ordem, HashTable *t);

        int busca(int val);
        void divideFilho(NoB* p,int i);
        void insereComEspaco(string data, int codCidade);
        int comparaChaves(int ch1, int ch2);
        void imprime(ostream &o);
        void imprime();

        NoB* getFilho(int i) { return filhos[i]; }
        void setFilho(NoB* val, int i) { filhos[i] = val; }

        int getN() { return n; }
        void setN(int val) { n = val; }

        bool eFolha() { return folha; }
        void setFolha(bool val) { folha = val; }

        int getChave(int i) { return chaves[i]; }
        void setChave(int val, int i) { chaves[i] = val; }
};





#endif // NOB_H_INCLUDED
