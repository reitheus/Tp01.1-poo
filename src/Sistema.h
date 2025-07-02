#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "../src/Piloto.h"
#include "../src/Passageiro.h"
#include "../src/Aeronave.h"
#include "../src/Voo.h"
#include "../src/Persistencia.h"
#include "../src/Pessoa.h"
#include "../src/Relatorios.h"
using namespace std;

class Sistema {

    vector<Aeronave*> aeronaves;
    vector<Voo*> voos;
    vector<Passageiro*> passag;
    vector<Piloto*> pilot;

public:

    // Construtor e Destrutor
    Sistema();
    ~Sistema();

    //setters e getters
    void setAeronaves(const vector<Aeronave*>& a);
    void setVoos(const vector<Voo*>& v);
    void setPassageiros(const vector<Passageiro*>& p);
    void setPilotos(const vector<Piloto*>& pi);

    // Funções principais
    void executarOpcao(int opcao);
    void menu();
    void carregarDados();
    void salvarDados();
    void salvarDadosEstatisticas();
    void salvarEmArquivo(string nomeArquivo, vector<Piloto*> pilotos, vector<Passageiro*> passageiros);

    // Funções auxiliares
    void cadastrarAeronave();
    void cadastrarPiloto();
    void cadastrarPassageiro();
    void criarVoo();
    float taxaoDeOcupacao(Voo* voo);

    // Funções de gerenciamento de voo
    void embarcarPassageiro();
    void listarVoos();
    void listarPassageirosDeVoo();
    void listarAeronaves();
    void listarPilotos();
    void listarPassageiros();

    //Funções de relatórios
    void gerarRelatorios(); 


};

#endif // SISTEMA_H