#include "..\src\Piloto.h"

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
    fstream arquivo(caminho, ios::out | ios::in | ios::ate);
    string linha;
    //verificar se o piloto ja existe
    while(getline(arquivo, linha)) {
        auto partes = split(linha, ',');
        if (partes.size() >= 5 && partes[5] == "Piloto") {
            int matricula = stoi(partes[2]);
            for (const auto& piloto : pilotos) {
                if (piloto->getMatricula() == matricula) {
                    // Se já existir, atualizar o piloto

                    arquivo << piloto->serializar() << "\n"; // Atualiza a linha do piloto
                    arquivo.close();
                    return; //atualiza o piloto se já existir
                }
            }
        }
    }
    // Se não existir, salvar os pilotos
    for (const auto& piloto : pilotos) {
        arquivo << piloto->serializar() << "\n";
    }
    arquivo.close();
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