#ifndef HORARIO_H
#define HORARIO_H

#pragma once
#include <iostream>
#include <string>

class Horario{
    int horaSaida;
    int horaChegada;
public:
    Horario(int = 0,int = 0);
    void setHorasaida(int);
    void setHorachegada(int);
    int getHorasaida();
    int getHorachegada();
};

#endif