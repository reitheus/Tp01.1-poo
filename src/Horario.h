#ifndef HORARIO_H
#define HORARIO_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Horario{
    int horaSaida;
    int horaChegada;
public:

    // Construtor
    Horario(int = 0,int = 0);

    //setters e getters 
    void setHorasaida(int );
    void setHorachegada(int );
    int getHorasaida()const;
    int getHorachegada()const;

    // Métodos
    void calculaDuracao(float ,float ,int );
    int calcularEscalas(float , float);
    void verificarHora(string );

};

#endif