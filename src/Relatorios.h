#if !defined(RELATORIOS_H)
#define RELATORIOS_H

#pragma once
#include "../src/Sistema.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

class Relatorios {
    int totalVoos;
    float mediaPassageiros;
    Aeronave* aeronaveMaisUsada;
    Passageiro* passageiroFrequente;
    vector<Voo*> voosCom90Porcento;
    vector<pair<Aeronave*, float>> distanciaPorAeronave;
    
public:

    // Construtor
    Relatorios(int = 0,float = 0.0, Aeronave* = nullptr, Passageiro* = nullptr,vector<Voo*> = {}, vector<pair<Aeronave*, float>> = {});

    // Métodos
    void relatorioTotalVoos(vector<Voo*> voos); 
    void relatorioMediaPassageiros(vector<Voo*> voos); 
    void relatorioAeronavesMaisUsadas(vector<Voo*> voos); 
    void relatorioPassageirosFrequentes(vector<Voo*> voos, vector<Passageiro*> passageiros); 
    void relatorioVoosCom90Porcento(vector<Voo*> voos); 
    void relatorioDistanciaPorAeronave(vector<Voo*> voos);
    float taxaoDeOcupacao(Voo* voo);
    void salvarDadosEstatisticas();

};

#endif // !defined(RELATORIOS_H)