#include "..\src\Persistencia.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// ======= Aeronaves =======
void salvarAeronavesCSV(const vector<Aeronave*>& aeronaves, const string& caminho) {
    ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar aeronaves.\n";
        return;
    }

    for (auto* a : aeronaves) {
        arquivo << a->serializar() << "\n";
    }

    arquivo.close();
}

vector<Aeronave*> carregarAeronavesCSV(const string& caminho) {
    vector<Aeronave*> aeronaves;
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Erro ao carregar aeronaves.\n";
        return aeronaves;
    }

    string linha;
    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 5) {
            string codigo = partes[0];
            string modelo = partes[1];
            int capacidade = stoi(partes[2]);
            float velocidade = stof(partes[3]);
            float autonomia = stof(partes[4]);

            aeronaves.push_back(new Aeronave(codigo, modelo, capacidade, velocidade, autonomia));
        } else {
            cerr << "Linha inválida no arquivo de aeronaves: " << linha << endl;
        }
    }

    arquivo.close();
    return aeronaves;
}

// ======= Pessoas =======
void salvarPessoasCSV(const vector<Pessoa*>& pessoas, const string& caminho) {
    ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar pessoas.\n";
        return;
    }

    for (auto* p : pessoas) {
        arquivo << p->serializar() << "\n";
    }

    arquivo.close();
}

vector<Pessoa*> carregarPessoasCSV(const string& caminho) {
    vector<Pessoa*> pessoas;
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Erro ao carregar pessoas.\n";
        return pessoas;
    }

    string linha;
    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 2) {
            string tipo = partes[0];
            if(partes.size() >= 6 && tipo == "Piloto") {
                string nome = partes[1];
                long cpf = stoll(partes[2]);
                int matricula = stoi(partes[3]);
                string breve = partes[4];
                float horasDeVoo = stof(partes[5]);
                pessoas.push_back(new Piloto(nome, cpf, matricula, breve, horasDeVoo));

            } else if(partes.size() == 4 && tipo == "Passageiro") {
                string nome = partes[1];
                long cpf = stoll(partes[2]);
                string bilhete = partes[3];
                int numeroVoos = partes.size() > 4 ? stoi(partes[4]) : 0; // opcional
                pessoas.push_back(new Passageiro(nome, cpf, bilhete, numeroVoos));

            } else {
                cerr << "Tipo de pessoa inválido ou dados insuficientes: " << linha << endl;
            }
        } else {
            cerr << "Linha inválida no arquivo de pessoas: " << linha << endl;
        }
    }

    return pessoas;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}