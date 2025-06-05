#include "../src/Pessoa.h"

Pessoa::Pessoa(string nome, long cpf){
    this->nome = nome;
    this->cpf = cpf;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

string Pessoa::getNome(){
    return nome;
}

void Pessoa::setCpf(long cpf){
    this->cpf = cpf;
}

long Pessoa::getCpf(){
    return cpf;
}