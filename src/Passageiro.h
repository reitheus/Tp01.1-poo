#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"

#include <iostream>
#include <string>
using namespace std;

class Passageiro : public Pessoa{
    string numeroBilhete;
    int numeroVoos;
public:
    Passageiro(string = " ", int = 0, string = " ", long = 0);
    void setNumbilhete(string num);
    void setNumvoo(int num);
    string getNumbilhete();
    int getNumvoo();
    Passageiro* criarPassagiro();
};

#endif