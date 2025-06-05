#include "..\src\Aeronave.h"

Aeronave::Aeronave(string codigo,string modelo,int cap,float velocidade,float autonomia){
    this->codigo = codigo;
    this->modelo = modelo;
    capacidade = cap;
    velocidadeMedia = velocidade;
    this->autonomia = autonomia;
}

void Aeronave::criaAeronave(){

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
