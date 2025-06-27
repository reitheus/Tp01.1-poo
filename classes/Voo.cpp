#include "..\src\Voo.h"

Voo::Voo(int cod, string orig, string dest, float dist, int lotacao, Aeronave* aeronave, Horario* hora, float temp, Piloto* piloto, Piloto* copiloto){
    codigo = cod;
    origem = orig;
    destino = dest;
    distancia = dist;
    lotacao = lotacao;
    aviao = aeronave;
    tempo = hora;
    tempodeVoo = temp;
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

void Voo::setDuracao(float num){
    tempodeVoo = num;
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

float Voo::getDuracao()const{
    return tempodeVoo;
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
    if (passageiro && passageiros.size() < size_t(lotacao) ){
        passageiros.push_back(passageiro);
    } else {
        cerr << "Não foi possível adicionar o passageiro. Lotação máxima atingida ou passageiro inválido.\n";
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
            string origem = partes[1];
            string destino = partes[2];
            string codigoAeronave = partes[3];
            int matriculaPiloto = stoi(partes[4]);
            int matriculaCopiloto = stoi(partes[5]);
            int dataSaida = stoi(partes[6]);
            int dataChegada = stoi(partes[7]);
            float distancia = stof(partes[8]);
            float duracao = stof(partes[9]);
            int lotacao = stoi(partes[10]);

            Aeronave* aeronave = tmp.encontrarAeronavePorCodigo(aeronaves, codigoAeronave);

            // NOVO: Buscar por matrícula, não por nome
            Piloto* piloto = nullptr;
            Piloto* copiloto = nullptr;

            for (const auto& p : pilotos) {
                if (p->getMatricula() == matriculaPiloto) piloto = p;
                if (p->getMatricula() == matriculaCopiloto) copiloto = p;
            }

            Horario *tempoAeronave = new Horario();
            tempoAeronave->setHorasaida(dataSaida);
            tempoAeronave->setHorachegada(dataChegada);
            
            Voo* voo = new Voo(codigoVoo, origem, destino, distancia, lotacao,aeronave, tempoAeronave, duracao, piloto, copiloto);

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
    ss << codigo << "," 
       << origem << "," 
       << destino << "," 
       << aviao->getCodigo() << "," 
       << comandante->getMatricula() << "," 
       << copiloto->getMatricula() << "," 
       << tempo->getHorasaida() << "," 
       << tempo->getHorachegada() << "," 
       << distancia << "," 
       << tempodeVoo << "," 
       << lotacao;
    
    for (const auto& p : passageiros) {
        ss << "," << p->getNumbilhete();
    }
    
    return ss.str();
}