#include "..\src\Piloto.h"

Piloto::Piloto(int mat, string breve,float tempo,string nome,long cpf){
    matricula = mat;
    this->breve = breve;
    horasdevoo = tempo;
    setNome(nome);
    setCpf(cpf);
}

void Piloto::setMatricula(int mat){
    matricula = mat;
}

void Piloto::setBreve(string cat){
    breve = cat;
}

void Piloto::setHorasdevoo(float num){
    horasdevoo = num;
}

int Piloto::getMatricula(){
    return matricula;
}

string Piloto::getBreve(){
    return breve;
}

float Piloto::getHorasdevoo(){
    return horasdevoo;
}

void Piloto::criarPiloto(){

}

void Piloto::exibePiloto(){
    cout << getNome() << getCpf() << matricula << breve << horasdevoo << endl;
}