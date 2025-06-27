#include "..\src\Voo.h"

Voo::Voo(int cod, string orig, string dest, float dist, int lotacao, Aeronave* aeronave, Horario* hora,int escala, Piloto* piloto, Piloto* copiloto){
    codigo = cod;
    origem = orig;
    destino = dest;
    distancia = dist;
    this->lotacao = lotacao;
    aviao = aeronave;
    tempo = hora;
    numeroEscalas = escala;
    comandante = piloto;
    this->copiloto = copiloto;
}

Voo::~Voo(){

}

void Voo::setCod(int num){
    codigo = num;
}

void Voo::setEscalas(int num){
    numeroEscalas = num;
}

void Voo::setOrigem(string nome){
    origem = nome;
}

void Voo::setDestino(string nome){
    destino = nome;
}

void Voo::setDistancia(float num){
    distancia = num;
}

void Voo::setLotacao(int num) {
    lotacao = num;
}

int Voo::getCod()const{
    return codigo;
}

string Voo::getOrigem()const{
    return origem;
}

string Voo::getDestino()const{
    return destino;
}

float Voo::getDistancia()const{
    return distancia;
}

int Voo::getEscalas()const{
    return numeroEscalas;
}

int Voo::getLotacao() const {
    return lotacao;
}

Aeronave* Voo::getAeronave() const {
    return aviao;
}

Piloto* Voo::getComandante() const {
    return comandante;
}

Piloto* Voo::getCopiloto()const{
    return copiloto;
}

vector<Passageiro* > Voo::getPassageiros() const {
    return passageiros;
}

void Voo::adicionarPassageiro(Passageiro* passageiro) {
    if (passageiro) {
        passageiros.push_back(passageiro);
        lotacao++;
    } else {
        cerr << "Passageiro inválido." << endl;
    }
}

void Voo::salvarVoosCSV(const vector<Voo*>& voos, const string& caminho) {
    ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para salvar os voos.\n";
        return;
    }

    for (const auto& voo : voos) {
        if (voo) {
            arquivo << voo->serializar() << endl;
        }
    }

    arquivo.close();
}

vector<Voo* > Voo::carregarVoosCSV(const string& caminho,const vector<Aeronave* >& aeronaves, const vector<Piloto* >& pilotos, vector<Passageiro* >& passageiros) {

    vector<Voo*> voos;
    ifstream arquivo(caminho);
    string linha;
    Aeronave tmp;

    while (getline(arquivo, linha)) {
        auto partes = split(linha, ',');

        if (partes.size() >= 11) {
            int codigoVoo = stoi(partes[0]);
            string orig = partes[1];
            string dest = partes[2];
            float dist = stof(partes[3]);
            int lot = stoi(partes[4]);
            string codigoAeronave = partes[5];
            int dataSaida = stoi(partes[6]);
            int dataChegada = stoi(partes[7]);
            int escalas = stoi(partes[8]);
            int matriculaPiloto = stoi(partes[9]);
            int matriculaCopiloto = stoi(partes[10]);

            Aeronave* aeronave = tmp.encontrarAeronavePorCodigo(aeronaves, codigoAeronave);

            // NOVO: Buscar por matrícula, não por nome
            Piloto* piloto = nullptr;
            Piloto* piloto2 = nullptr;

            for (const auto& p : pilotos) {
                if (p->getMatricula() == matriculaPiloto) piloto = p;
                if (p->getMatricula() == matriculaCopiloto) piloto2 = p;
            }

            Horario *tempoAeronave = new Horario();
            tempoAeronave->setHorasaida(dataSaida);
            tempoAeronave->setHorachegada(dataChegada);
            
            Voo* voo = new Voo(codigoVoo, orig, dest, dist,lot ,aeronave, tempoAeronave, escalas, piloto, piloto2);

            for(size_t i = 11; i < partes.size(); ++i) {
                string bilhete = partes[i];
                Passageiro* passa = nullptr;
                for (const auto& p : passageiros) {
                    if (p->getNumbilhete() == bilhete) {
                        passa = p;
                        break;
                    }
                }
                if (passa) {
                    voo->adicionarPassageiro(passa);
                }
            }


            voos.push_back(voo);
        }
    }

    return voos;
}

string Voo::serializar() const {
    stringstream ss;
    ss << to_string(codigo) << "," 
       << origem << "," 
       << destino << "," 
       << to_string(distancia) << "," 
       << to_string(lotacao) << ","
       << aviao->getCodigo() << "," 
       << to_string(tempo->getHorasaida()) << "," 
       << to_string(tempo->getHorachegada()) << ","
       << to_string(numeroEscalas) << ","
       << to_string(comandante->getMatricula()) << ","
       << to_string(copiloto->getMatricula());

    for (const auto& passageiro : passageiros) {
        ss << "," << passageiro->getNumbilhete();
    }
    return ss.str();
}