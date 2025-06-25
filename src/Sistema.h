#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <sstream>
#include "Aeronave.h"
#include "Pessoa.h"
#include "Voo.h"
using namespace std;

class Sistema {

    vector<Aeronave*> aeronaves;
    vector<Pessoa*> pessoas;
    vector<Voo*> voos;

public:

    Pessoa* encontrarPessoaPorMatricula(const string& matricula);
    Aeronave* encontrarAeronavePorCodigo(const string& codigo);
    Voo* encontrarVooPorCodigo(const int& codigo);

    void executarOpcao(int opcao);
    
    void carregarDados();
    void salvarDados();
    
    void cadastrarAeronave();
    void cadastrarPiloto();
    void cadastrarPassageiro();
    void criarVoo();
    void embarcarPassageiro(const string& codigoVoo, Passageiro* passageiro);
    void listarVoos();
    void listarPassageirosDeVoo(const string& codigoVoo);
    void gerarRelatorios(); 

    void gerarRelatoriosExtra(); 
    void relatorioTotalVoos(); 
    void relatorioMediaPassageiros(); 
    void relatorioAeronavesMaisUsadas(); 
    void relatorioPassageirosFrequentes(); 
    void relatorioVoosCom90Porcento(); 
    void relatorioDistanciaPorAeronave();
    void salvarEmArquivo(const string& nomeArquivo, const string& conteudo);


};

#endif // SISTEMA_H