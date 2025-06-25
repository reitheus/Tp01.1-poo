#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "..\src\Aeronave.h"
#include "..\src\Piloto.h"
#include "..\src\Passageiro.h"
#include "..\src\Voo.h"

using namespace std;

// Funções para salvar e carregar aeronaves
void salvarAeronavesCSV(const vector<Aeronave*>& aeronaves, const string& caminho);
vector<Aeronave*> carregarAeronavesCSV(const string& caminho);

// Funções para salvar e carregar pilotos
void salvarPilotosCSV(const vector<Piloto*>& pilotos, const string& caminho);
vector<Piloto*> carregarPilotosCSV(const string& caminho);

// Funções para salvar e carregar passageiros
void salvarPassageirosCSV(const vector<Passageiro*>& passageiros, const string& caminho);
vector<Passageiro*> carregarPassageirosCSV(const string& caminho);

// Funções para salvar e carregar voos
void salvarVoosCSV(const vector<Voo*>& voos, const string& caminho);
vector<Voo*> carregarVoosCSV(const string& caminho, const vector<Aeronave*>& aeronaves, const vector<Pessoa*>& pessoas);

// Função auxiliar para dividir strings
vector<string> split(const string& s, char delimiter);

#endif // PERSISTENCIA_H