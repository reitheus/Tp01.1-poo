#ifndef VOO_H
#define VOO_H

#include "..\src\Aeronave.h"
#include "..\src\Piloto.h"
#include "..\src\Passageiro.h"
#include "..\src\Horario.h"
#include "..\src\Persistencia.h"

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Voo{
    int codigo;
    string origem;
    string destino;
    float distancia;
    int lotacao;
    Aeronave* aviao;
    Horario* tempo;
    int numeroEscalas;
    float tempodeVoo;
    Piloto* comandante;
    Piloto* copiloto;
    vector <Passageiro* > passageiros;

public:
    // Construtor
    Voo(int  = 0, string  = " ", string  = " ", float  = 0.0,int  = 0,Aeronave* = new Aeronave(), Horario* = new Horario(), float  = 0.0,Piloto* = new Piloto(), Piloto* = new Piloto());
    
    ~Voo();

    // setters e getters
    void setCod(int);
    void setEscalas(int);
    void setOrigem(string);
    void setDestino(string);
    void setDistancia(float);
    void setDuracao(float);
    void setLotacao(int);
    int getCod()const;
    string getOrigem()const;
    string getDestino()const;
    float getDistancia()const;
    int getEscalas()const;
    float getDuracao()const;
    int getLotacao() const;
    Aeronave* getAeronave() const;
    Piloto* getComandante() const;
    Piloto* getCopiloto() const;
    vector<Passageiro*> getPassageiros() const;

    // Métodos
    void salvarVoosCSV(const vector<Voo* >& voos, const string& caminho);
    vector<Voo* > carregarVoosCSV(const string& caminho,const vector<Aeronave* >& aeronaves, const vector<Piloto* >& pilotos, vector<Passageiro* >& passageiros);
    virtual string serializar() const;
    void adicionarPassageiro(Passageiro* passageiro);


};

#endif