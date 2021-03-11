#include <iostream>
#include "ArvBinBusca.h"
#include "hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>

using namespace std;
int leArqProcessado(HashTable* ht, string endr){
    ifstream arq(endr);
    if(!arq.is_open())
        return -1;
    string str;
    int i=0;
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
        if(i++>10000)
            break;
    }

}

int main()
{

    HashTable ht(200000069);
    leArqProcessado(&ht,"processado.csv");
    ht.print();
    return 0;
}
