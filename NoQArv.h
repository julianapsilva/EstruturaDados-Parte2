#ifndef NOQARV_H_INCLUDED
#define NOQARV_H_INCLUDED
#include "Coordenada.h"

class NoQArv
{
  public:
    void setNe(NoQArv *p) { ne = p; };
    void setSe(NoQArv *p) { se = p; };
    void setSw(NoQArv *p) { sw = p; };
    void setNw(NoQArv *p) { nw = p; };
     NoQArv() {};
    ~NoQArv() {};
    NoQArv* getNe()       { return ne; };
    NoQArv* getSe()       { return se; };
    NoQArv* getSw()       { return sw; };
    NoQArv* getNw()       { return nw; };
    coord getCoord()         { return coordenadas; };
    void setCoord(coord val) { coordenadas = val; };
    void setFator(int val) { fator = val; };
    int getFator()        { return fator; };
    int getInfo(){return info;};
    void setInfo(int p){info=p;}
    private:
    int info;
    coord coordenadas;
    int fator;
    NoQArv* ne=NULL,*se=NULL,*nw=NULL,*sw=NULL; 
};


#endif // NOQARV_H_INCLUDED
