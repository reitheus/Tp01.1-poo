#include "../src/Aeronave.h"

//Construtor da classe Aeronave
Aeronave::Aeronave(string codigo,string modelo,int cap,float velocidade,float autonomia){
    this->codigo = codigo;
    this->modelo = modelo;
    capacidade = cap;
    velocidadeMedia = velocidade;
    this->autonomia = autonomia;
}

// Destrutor 
Aeronave::~Aeronave() {
    // Destrutor vazio, pois não há alocação dinâmica de recursos adicionais
}

// Método para salvar aeronaves em um arquivo CSV
void Aeronave::salvarAeronavesCSV(const vector<Aeronave*>& aeronaves, const string& caminho) {
    ofstream arquivo(caminho, ios::out | ios::trunc); // Abre o arquivo em modo truncar
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar aeronaves." << endl;
        return;
    }

    for (const auto& aeronave : aeronaves) {
        arquivo << aeronave->serializar() << "\n";
    }

    arquivo.close();
}

// Método para carregar aeronaves de um arquivo CSV
vector<Aeronave*> Aeronave::carregarAeronavesCSV(const string& caminho) {
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

    return aeronaves;
}

// Método para serializar os dados da aeronave em formato CSV
string Aeronave::serializar() const {
    return codigo + "," + modelo + "," + to_string(capacidade) + "," +
           to_string(velocidadeMedia) + "," + to_string(autonomia);
}

// Método para encontrar uma aeronave pelo código
Aeronave* Aeronave::encontrarAeronavePorCodigo(const vector<Aeronave*> aeronaves, const string& codigo) {
    for (auto* a : aeronaves) {
        if (a->getCodigo().compare(codigo)==0) {
            cout << "Aeronave encontrada: " << a->getCodigo() << endl;
            return a;
        }
    }
    return nullptr; // Retorna nullptr se não encontrar
}

// Métodos de acesso (getters e setters)
void Aeronave::setCodigo(string cod){
    codigo = cod;
}

void Aeronave::setModelo(string mod){
    modelo = mod;
}

void Aeronave::setCapacidade(int cap){
    capacidade = cap;
}

void Aeronave::setVelocidadeM(float velo){
    velocidadeMedia = velo;
}

void Aeronave::setAutonomia(float autonomia){
    this->autonomia = autonomia;
}

string Aeronave::getCodigo()const{
    return codigo;
}

string Aeronave::getModelo()const{
    return modelo;
}

int Aeronave::getCapacidade()const{
    return capacidade;
}

float Aeronave::getVelocidadeMedia()const{
    return velocidadeMedia;
}

float Aeronave::getAutonomia()const{
    return autonomia;
}
