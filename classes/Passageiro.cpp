#include "..\src\Passageiro.h"

Passageiro::Passageiro(string bilhete,int numVoo, string nome,long cpf){
    numeroBilhete = bilhete;
    numeroVoos = numVoo;
    setNome(nome);
    setCpf(cpf);
}

void Passageiro::setNumvoo(int num){
    numeroVoos = num;
}

void Passageiro::setNumbilhete(string num){
    numeroBilhete = num;
}

string Passageiro::getNumbilhete(){
    return numeroBilhete;
}

int Passageiro::getNumvoo(){
    return numeroVoos;
}
void Passageiro::criarPassagiro(){

}