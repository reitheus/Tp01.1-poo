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
    // Construtor
    Passageiro(string = " ", int = 0, string = " ", long long = 0);
    ~Passageiro();

    // Setters e Getters
    void setNumbilhete(string num);
    void setNumvoo(int num);
    string getNumbilhete()const;
    int getNumvoo()const;

    // Métodos
    virtual string serializar() const;
    void salvarPassageirosCSV(const vector<Passageiro*>& passageiros, const string& caminho);
    vector<Passageiro*> carregarPassageirosCSV(const string& caminho);
    Passageiro* encontrarPassageiroPorBilhete(const vector<Passageiro*> passageiros, const string& bilhete);
};

#endif