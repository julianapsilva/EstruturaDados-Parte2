#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoQArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);

private:
    NoQArv* raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoQArv* auxInsere(NoArv *p, int val);
    NoQArv* auxRemove(NoArv *p, int val);
    NoQArv* menorSubArvDireita(NoArv *p);
    NoQArv* removeFolha(NoArv *p);
    NoQArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoQArv* libera(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
