#ifndef AERONAVE_H
#define AERONAVE_H

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Aeronave
{
    string codigo;
    string modelo;
    int capacidade;
    float velocidadeMedia;
    float autonomia;

public:
    Aeronave(string = " ", string = " ", int = 0, float = 0, float = 0);
    void setCodigo(string);
    void setModelo(string);
    void setCapacidade(int);
    void setVelocidadeM(float);
    void setAutonomia(float);
    string getCodigo();
    string getModelo();
    int getCapacidade();
    float getVelocidadeMedia();
    float getAutonomia();
    Aeronave* criaAeronave();
    void mostrarAeronave();

};

#endif