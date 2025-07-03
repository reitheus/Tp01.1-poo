#include "../src/Passageiro.h"

// Construtor da classe Passageiro
Passageiro::Passageiro(string nome,long long cpf, string bilhete,int numVoo){
    setNome(nome);
    setCpf(cpf);
    numeroBilhete = bilhete;
    numeroVoos = numVoo;
}

// Destrutor
Passageiro::~Passageiro(){
    
}

// Métodos de acesso (setters e getters)
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

// Método para serializar os dados do passageiro em formato CSV
string Passageiro::serializar() const {
    return getNome() + "," + to_string(getCpf()) + "," + getNumbilhete() + "," + to_string(getNumvoo()) + ",Passageiro";
}

// Método para salvar passageiros em um arquivo CSV
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
                if (partes.size() >= 5 && partes[4] == "Passageiro" && partes[0] == p->getNumbilhete()) {
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

// Método para carregar passageiros de um arquivo CSV
vector<Passageiro*> Passageiro::carregarPassageirosCSV(string caminho) {
    vector<Passageiro*> passageiros;
    ifstream arquivo(caminho);
    string linha;

    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        // Verifica se é um passageiro (último campo == "Passageiro")
        if (partes.size() >= 5 && partes.back() == "Passageiro") {
            try {
                string nome = partes[0];
                long long cpf = stoll(partes[1]);
                string bilhete = partes[2];
                int numVoo = stoi(partes[3]);

                passageiros.push_back(new Passageiro(nome, cpf, bilhete, numVoo));
                cout << "Passageiro carregado: " << nome << endl;
            } catch (const std::exception& e) {
                cerr << "Erro ao carregar passageiro (linha: '" << linha << "'): " << e.what() << endl;
            }
        }
    }

    return passageiros;
}

// Método para encontrar um passageiro pelo número do bilhete
Passageiro* Passageiro::encontrarPassageiroPorBilhete(vector<Passageiro*> passageiros, string bilhete) {
    for (const auto& p : passageiros) {
        if (p->getNumbilhete() == bilhete) {
            return p;
        }
    }
    return nullptr;
}