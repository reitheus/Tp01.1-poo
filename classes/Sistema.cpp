#include "..\src\Sistema.h"
#include "..\src\Piloto.h"
#include "..\src\Passageiro.h"
#include "..\src\Aeronave.h"
#include "..\src\Voo.h"
#include "..\src\Persistencia.h"

//Auxiliares
Aeronave* Sistema::encontrarAeronavePorCodigo(const string& codigo){
    for (auto& aeronave : aeronaves) {
        if (aeronave->getCodigo() == codigo) {
            return aeronave;
        }
    }
    return nullptr;
}

Voo* Sistema::encontrarVooPorCodigo(const int& codigo) {
    for (auto& voo : voos) {
        if (voo->getCod() == codigo) {
            return voo;
        }
    }
    return nullptr;
}

Pessoa* Sistema::encontrarPessoaPorMatricula(const string& nome) {
    for (auto& pessoa : pessoas) {
        if (pessoa->getNome() == nome) {
            return pessoa;
        }
    }
    return nullptr;
}

// Carrega os dados do sistema
void Sistema::carregarDados() {
    // Carrega aeronaves
    aeronaves = carregarAeronavesCSV("dados/aeronaves.csv");

    // Carrega pessoas
    pessoas = carregarPessoasCSV("dados/pessoas.csv");
    
    // Carrega voos
    voos = carregarVoosCSV("dados/voos.csv", aeronaves, pessoas);
}