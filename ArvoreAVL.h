#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED
#include "NoArv.h"

class ArvoreAVL
{
public:
    ArvoreAVL();
    bool busca(int val);
    void insere(int val);
    void imprime();
    int calculaAltura(NoArv *p);

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* rotSimplesEsq(NoArv* p);
    NoArv* rotSimplesDir(NoArv* p);
    NoArv* verificaBalanceamento(NoArv *p);
};

#endif // ARVOREAVL_H_INCLUDED
