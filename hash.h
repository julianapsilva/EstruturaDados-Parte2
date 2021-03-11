#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string>
#include "NodeHT.h"
typedef std::string string;
class HashTable
{
public:
    bool busca(int val);
    void imprime();
    HashTable(int tam);
    void insere(int codcidade, string data, string cidade, string estado, int casos, int mortes) {
        NodeHT *n= new NodeHT(codcidade, data, cidade, estado, casos, mortes);
        insere(n);
    };
    void print();
    NodeHT* operator[](int i){
    return tabela[i];
}
   NodeHT* busca(string data ,int codcidade);

private:
    int tam;
    NodeHT **tabela;
    void insere(NodeHT*);
    int funct(string,int,int);
    int getTam(){return tam;};


};



#endif // HASH_H_INCLUDED
