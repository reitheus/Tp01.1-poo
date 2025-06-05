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

Piloto* Piloto::criarPiloto(){
    int mat;
    string nome, breve;
    float tempo;
    long cpf;
    Piloto *tmp;
    cin >> nome;
    tmp->setNome(nome);
    cin >> cpf;
    tmp->setCpf(cpf); 
    cin >> breve;
    tmp->setBreve(breve);
    cin >> mat;
    tmp->setMatricula(mat);
    cin >> tempo;
    tmp->setHorasdevoo(tempo); 
    return tmp;
}

void Piloto::exibePiloto(){
    cout << getNome() << getCpf() << matricula << breve << horasdevoo << endl;
}