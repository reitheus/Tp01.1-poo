#ifndef PESSOA_H
#define PESSOA_H

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../src/Persistencia.h"
using namespace std;

class Pessoa{
    string nome;
    long long cpf;
public:

    // Construtor 
    Pessoa(string = " ", long long = 0);
    ~Pessoa();

    // Setters e Getters
    void setNome(string );
    void setCpf(long long );
    string getNome() const;
    long long getCpf() const;

    // Métodos
    virtual string serializar() const;
    void verificarCpf(long long cpf);
};

#endif