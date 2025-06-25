#ifndef PILOTO_H
#define PILOTO_H

#include "Pessoa.h"

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Piloto : public Pessoa{
    int matricula;
    string breve;
    float horasdevoo;
public:
    Piloto(string = "", long = 0, int = 0, string = "", float = 0.0);
    void setMatricula(int);
    void setBreve(string);
    void setHorasdevoo(float);
    int getMatricula();
    string getBreve();
    float getHorasdevoo();
    Piloto* criarPiloto();
    void exibePiloto();
};

#endif