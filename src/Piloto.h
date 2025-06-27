#ifndef PILOTO_H
#define PILOTO_H

#include "..\src\Pessoa.h"

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Piloto : public Pessoa{
    int matricula;
    string breve;
    int horasdevoo;
public:
    // Construtor
    Piloto(string = "", long long = 0, int = 0, string = "", int = 0);
    ~Piloto();
    // Setters e Getters
    void setMatricula(int);
    void setBreve(string);
    void setHorasdevoo(int);
    int getMatricula()const;
    string getBreve()const;
    int getHorasdevoo() const;

    // Métodos
    void exibePiloto();
    void salvarPilotosCSV(const vector<Piloto*>& pilotos, const string& caminho);
    vector<Piloto*> carregarPilotosCSV(const string& caminho);
    virtual string serializar() const;
    Piloto* encontrarPilotoPorMatricula(const vector<Piloto*> pilotos, const int matricula);

};

#endif