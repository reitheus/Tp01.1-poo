#include "..\src\Aeronave.h"

Aeronave::Aeronave(string codigo,string modelo,int cap,float velocidade,float autonomia){
    this->codigo = codigo;
    this->modelo = modelo;
    capacidade = cap;
    velocidadeMedia = velocidade;
    this->autonomia = autonomia;
}

Aeronave* Aeronave::criaAeronave(){
    string codigo, modelo;
    int capacidade;
    float velocidadeMedia, autonomia;
    Aeronave *tmp = new Aeronave();
    cin >> codigo;
    tmp->setCodigo(codigo);
    cin >> modelo;
    tmp->setModelo(modelo);
    cin >> capacidade;
    tmp->setCapacidade(capacidade);
    cin >> velocidadeMedia;
    tmp->setVelocidadeM(velocidadeMedia);
    cin >> autonomia;
    tmp->setAutonomia(autonomia);
    return tmp;
}

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

string Aeronave::getCodigo(){
    return codigo;
}

string Aeronave::getModelo(){
    return modelo;
}

int Aeronave::getCapacidade(){
    return capacidade;
}

float Aeronave::getVelocidadeMedia(){
    return velocidadeMedia;
}

float Aeronave::getAutonomia(){
    return autonomia;
}

void Aeronave::mostrarAeronave(){
    cout << codigo << modelo << capacidade << autonomia << velocidadeMedia;
}