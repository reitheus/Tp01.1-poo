#ifndef PESSOA_H
#define PESSOA_H

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pessoa{
    string nome;
    long cpf;
public:

    Pessoa(string = " ", long = 0);
    void setNome(string );
    void setCpf(long );
    string getNome();
    long getCpf();

};

#endif