#include "..\src\Voo.h"
#include "..\src\Aeronave.h"
#include "..\src\Passageiro.h"
#include "..\src\Piloto.h"
#include "..\src\Horario.h"

Voo::Voo(int cod,string orig,string dest,float dist,int lotacao,Aeronave aeronave,Horario hora,int nEscalas,float temp,Piloto piloto,Piloto piloto1){
    codigo = cod;
    origem = orig;
    destino = dest;
    distancia = dist;
    this->lotacao = lotacao;
    *aviao = aeronave;
    tempo = hora;
    numeroEscalas = nEscalas;
    tempodeVoo = temp;
    *comandante = piloto;
    *copiloto = piloto1;
}
Voo::~Voo(){
    for(Passageiro* p : passageiros){
        delete p;
    }
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

int Voo::getCod(){
    return codigo;
}

string Voo::getOrigem(){
    return origem;
}

string Voo::getDestino(){
    return destino;
}

float Voo::getDistancia(){
    return distancia;
}

int Voo::getEscalas(){
    return numeroEscalas;
}

float Voo::getDuracao(){
    return tempodeVoo;
}

void Voo::embarcarPassageiros(Voo *v, Passageiro *p){
    if(v->aviao->getCapacidade() < lotacao){
        v->passageiros.push_back(p);

    }
}

void Voo::exibirPassageiros(){
    for(Passageiro* p : passageiros){
        cout << p->getNome() << p->getCpf() << p->getNumbilhete();
    }
}

void Voo::exibirPilotos(){
    comandante->exibePiloto();
    copiloto->exibePiloto();
}

void Voo::mostrarVoo(Voo voo){
    cout << voo.codigo;
    voo.aviao->mostrarAeronave();
    voo.exibirPilotos();
    voo.exibirPassageiros();

}

Voo* Voo::criarVoo(/*tres listas uma de aeronave, outra de piloto, outra de passageiros*/){
    int cod, nEscalas;
    string orig, dest;
    float dist, temp;
    Aeronave aeronave;
    Horario hora;
    Piloto piloto, piloto1;
    Voo *tmp;
    cin >> cod;
    tmp->setCod(cod);
    cin >> orig >> dest;
    tmp->setOrigem(orig);
    tmp->setDestino(dest);
    cin >> dist;
    tmp->setDistancia(dist);
    

}