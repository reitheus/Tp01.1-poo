#ifndef VOO_H
#define VOO_H

#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Horario.h"

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Voo{
    int codigo;
    string origem;
    string destino;
    float distancia;
    int lotacao;
    Aeronave *aviao;
    Horario tempo;
    int numeroEscalas;
    float tempodeVoo;
    Piloto *comandante;
    Piloto *copiloto;
    vector <Passageiro*> passageiros;

public:
    Voo(int = 0,string = "",string = "",float = 0.0,int = 0,Aeronave = Aeronave(),Horario = Horario(),int = 0,float = 0,Piloto = Piloto(),Piloto = Piloto());
    ~Voo();
    void setCod(int);
    void setEscalas(int);
    void setOrigem(string);
    void setDestino(string);
    void setDistancia(float);
    void setDuracao(float);
    int getCod();
    string getOrigem();
    string getDestino();
    float getDistancia();
    int getEscalas();
    float getDuracao();


};

#endif