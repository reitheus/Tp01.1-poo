#include "../src/Piloto.h"

Piloto::Piloto(string nome, long long cpf,int mat, string breve,int tempo){
    matricula = mat;
    this->breve = breve;
    horasdevoo = tempo;
    setNome(nome);
    setCpf(cpf);
}

Piloto::~Piloto() {
    // Destrutor vazio, pois não há alocação dinâmica de recursos adicionais
}

void Piloto::setMatricula(int mat){
    matricula = mat;
}

void Piloto::setBreve(string cat){
    breve = cat;
}

void Piloto::setHorasdevoo(int num){
    horasdevoo = num;

}

int Piloto::getMatricula()const{
    return matricula;
}

string Piloto::getBreve()const{
    return breve;
}

int Piloto::getHorasdevoo() const {
    return horasdevoo;
}

string Piloto::serializar() const {
    return getNome() + "," + to_string(getCpf()) + "," + to_string(matricula) + "," + breve + "," + to_string(horasdevoo) + "," + "Piloto";
}

void Piloto::exibePiloto(){
    cout << getNome() << getCpf() << matricula << breve << horasdevoo << endl;
}

vector<Piloto*> Piloto::carregarPilotosCSV(const string& caminho) {
    vector<Piloto*> pilotos;
    ifstream arquivo(caminho);
    string linha;

    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 5 && partes[5] == "Piloto") {
            string nome = partes[0];
            long long cpf = stoll(partes[1]);
            int matricula = stoi(partes[2]);
            string breve = partes[3];
            int horasdevoo = stof(partes[4]);

            pilotos.push_back(new Piloto(nome, cpf, matricula, breve, horasdevoo));
            cout << "Piloto carregado: " << pilotos.back()->getNome() << endl;
        }

    }

    return pilotos;
}

void Piloto::salvarPilotosCSV(const vector<Piloto*>& pilotos, const string& caminho) {
    // Ler todas as linhas existentes
    ifstream arquivoLeitura(caminho);
    vector<string> linhas;
    string linha;
    while (getline(arquivoLeitura, linha)) {
        linhas.push_back(linha);
    }
    arquivoLeitura.close();

    // Atualizar ou adicionar pilotos
    for (auto p : pilotos) {
        if (p) {
            bool existe = false;
            for (size_t i = 0; i < linhas.size(); ++i) {
                auto partes = split(linhas[i], ',');
                // Verifica se é Piloto e compara pela matrícula
                if (partes.size() >= 6 && partes[5] == "Piloto" && partes[2] == to_string(p->getMatricula())) {
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

    // Remover duplicatas de matrícula
    unordered_set<string> matriculasUnicas;
    vector<string> linhasFiltradas;
    for (auto it = linhas.rbegin(); it != linhas.rend(); ++it) {
        auto partes = split(*it, ',');
        if (partes.size() >= 3) {
            if (matriculasUnicas.find(partes[2]) == matriculasUnicas.end() && partes[5] == "Piloto") {
                linhasFiltradas.push_back(*it);
                matriculasUnicas.insert(partes[2]);
            }
        }
    }
    reverse(linhasFiltradas.begin(), linhasFiltradas.end());

    // Escrever tudo de volta
    ofstream arquivoEscrita(caminho, ios::trunc);
    if (!arquivoEscrita.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os pilotos." << endl;
        return;
    }
    for (const auto& l : linhasFiltradas) {
        arquivoEscrita << l << "\n";
    }
    arquivoEscrita.close();
}

Piloto* Piloto::encontrarPilotoPorMatricula(const vector<Piloto*> pilotos, const int matricula) {
    for (const auto& piloto : pilotos) {
        if (piloto->getMatricula() == matricula) {
            cout << "Piloto encontrado: " << piloto->getNome() << endl;
            return piloto;
        }
    }
    return nullptr;
}