#ifndef AERONAVE_H
#define AERONAVE_H

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "../src/Persistencia.h"
using namespace std;

class Aeronave{
    string codigo;
    string modelo;
    int capacidade;
    float velocidadeMedia;
    float autonomia;

public:

    // Construtor

    Aeronave(string = " ", string = " ", int = 0, float = 0, float = 0);
    ~Aeronave();

    // Setters e Getters
    void setCodigo(string);
    void setModelo(string);
    void setCapacidade(int);
    void setVelocidadeM(float);
    void setAutonomia(float);
    string getCodigo()const;
    string getModelo()const;
    int getCapacidade()const;
    float getVelocidadeMedia()const;
    float getAutonomia()const;

    // Métodos
    void mostrarAeronave();
    virtual string serializar() const;
    void salvarAeronavesCSV(const vector<Aeronave*>& aeronaves, const string& caminho);
    vector<Aeronave*> carregarAeronavesCSV(const string& caminho);
    Aeronave* encontrarAeronavePorCodigo(const vector<Aeronave*> aeronaves, const string& codigo);

};

#endif