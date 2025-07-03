#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set> 
using namespace std;

class Passageiro : public Pessoa{
    string numeroBilhete;
    int numeroVoos;
public:
    // Construtor
    Passageiro(string = " ",long long = 0 , string = " ", int = 0);
    ~Passageiro();

    // Setters e Getters
    void setNumbilhete(string num);
    void setNumvoo(int num);
    string getNumbilhete()const;
    int getNumvoo()const;

    // Métodos
    virtual string serializar() const;
    void salvarPassageirosCSV(vector<Passageiro*> passageiros, string caminho);
    vector<Passageiro*> carregarPassageirosCSV(string caminho);
    Passageiro* encontrarPassageiroPorBilhete(vector<Passageiro*> passageiros, string bilhete);
};

#endif