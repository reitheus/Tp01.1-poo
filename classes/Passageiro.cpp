#include "../src/Passageiro.h"

Passageiro::Passageiro(string nome,long long cpf, string bilhete,int numVoo){
    setNome(nome);
    setCpf(cpf);
    numeroBilhete = bilhete;
    numeroVoos = numVoo;
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

    return getNome() + "," + to_string(getCpf()) + "," + getNumbilhete() + "," + to_string(getNumvoo());
}

void Passageiro::salvarPassageirosCSV(vector<Passageiro*> passageiros, string caminho) {
    // Ler todas as linhas existentes
    ifstream arquivoLeitura(caminho);
    vector<string> linhas;
    string linha;
    while (getline(arquivoLeitura, linha)) {
        linhas.push_back(linha);
    }
    arquivoLeitura.close();

    // Atualizar ou adicionar passageiros
    for (auto p : passageiros) {
        if (p) {
            bool existe = false;
            for (size_t i = 0; i < linhas.size(); ++i) {
                auto partes = split(linhas[i], ',');
                // Verifica se é Passageiro e compara pelo número do bilhete
                if (partes.size() >= 4 && partes[0] == p->getNumbilhete()) {
                    linhas[i] = p->serializar();
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                linhas.push_back(p->serializar());
            }
        }
    }

    // Remover duplicatas de bilhetes
    unordered_set<string> bilhetesUnicos;
    vector<string> linhasFiltradas;
    for (auto it = linhas.rbegin(); it != linhas.rend(); ++it) {
        auto partes = split(*it, ',');
        if (partes.size() >= 1) {
            if (bilhetesUnicos.find(partes[0]) == bilhetesUnicos.end()) {
                linhasFiltradas.push_back(*it);
                bilhetesUnicos.insert(partes[0]);
            }
        }
    }
    reverse(linhasFiltradas.begin(), linhasFiltradas.end());

    // Escrever tudo de volta
    ofstream arquivoEscrita(caminho, ios::trunc);
    if (!arquivoEscrita.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os passageiros." << endl;
        return;
    }
    for (const auto& l : linhasFiltradas) {
        arquivoEscrita << l << "\n";
    }
    arquivoEscrita.close();
}

vector<Passageiro*> Passageiro::carregarPassageirosCSV(string caminho) {
    vector<Passageiro*> passageiros;
    ifstream arquivo(caminho);
    string linha;

    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 4) {  // Verifica se há pelo menos 4 campos
            string nome = partes[0];
            long long cpf = stoll(partes[1]);
            string bilhete = partes[2];
            int numVoo = stoi(partes[3]);

            passageiros.push_back(new Passageiro(nome, cpf, bilhete, numVoo));
            cout << "Passageiro carregado: " << nome << endl;
        }
    }

    return passageiros;
}

Passageiro* Passageiro::encontrarPassageiroPorBilhete(vector<Passageiro*> passageiros, string bilhete) {
    for (const auto& p : passageiros) {
        if (p->getNumbilhete() == bilhete) {
            return p;
        }
    }
    return nullptr;
}