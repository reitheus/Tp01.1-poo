#include "..\src\Passageiro.h"

Passageiro::Passageiro(string bilhete,int numVoo, string nome,long long cpf){
    numeroBilhete = bilhete;
    numeroVoos = numVoo;
    setNome(nome);
    setCpf(cpf);
}

Passageiro::~Passageiro(){
    
}

void Passageiro::setNumvoo(int num){
    numeroVoos = num;
}

void Passageiro::setNumbilhete(string num){
    numeroBilhete = num;
}

string Passageiro::getNumbilhete() const {
    return numeroBilhete;
}

int Passageiro::getNumvoo() const{
    return numeroVoos;
}

string Passageiro::serializar() const {
    return getNome() + "," + to_string(getCpf()) + "," + numeroBilhete + "," + to_string(numeroVoos) + "," + "Passageiro";
}

void Passageiro::salvarPassageirosCSV(const vector<Passageiro*>& passageiros, const string& caminho) {
    fstream arquivo(caminho, ios::out | ios::in | ios::ate); // Abre o arquivo em modo append
    string linha;

    while(getline(arquivo, linha)) {
        auto partes = split(linha, ',');
        if(partes.size() <= 4 && partes[4] == "Passageiro") {
            // Se já existir, atualizar o passageiro
            long long cpf = stoll(partes[1]);
            for (auto p : passageiros) {
                if (p->getCpf() == cpf) {
                    // Se já existir, atualizar o passageiro

                    arquivo << p->serializar() << "\n"; // Atualiza a linha do passageiro
                    arquivo.flush(); // Garante que as alterações sejam salvas
                    arquivo.close();
                    return; // Não salvar se já existir
                }
            }
        }
    }
    for (auto p : passageiros) {
        arquivo << p->serializar() << "\n";
    }
    arquivo.flush(); // Garante que as alterações sejam salvas
    arquivo.close();
}

vector<Passageiro*> Passageiro::carregarPassageirosCSV(const string& caminho) {
    vector<Passageiro*> passageiros;
    ifstream arquivo(caminho);
    string linha;

    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 4 && partes[4] == "Passageiro") {
            string bilhete = partes[2];
            long long cpf = stoll(partes[1]);
            string nome = partes[0];
            int numVoo = stoi(partes[3]);

            passageiros.push_back(new Passageiro(bilhete, numVoo, nome, cpf));
        }
    }

    return passageiros;
}

Passageiro* Passageiro::encontrarPassageiroPorBilhete(const vector<Passageiro*> passageiros, const string& bilhete) {
    for (const auto& p : passageiros) {
        if (p->getNumbilhete() == bilhete) {
            return p;
        }
    }
    return nullptr;
}