#include "..\src\Voo.h"
#include "..\src\Aeronave.h"
#include "..\src\Passageiro.h"
#include "..\src\Piloto.h"
#include "..\src\Horario.h"

Voo::Voo(int cod,string orig,string dest,float dist,Aeronave aeronave,Horario hora,int nEscalas,float temp,Piloto piloto,Piloto piloto1){
    codigo = cod;
    origem = orig;
    destino = dest;
    distancia = dist;
    aviao = aeronave;
    tempo = hora;
    numeroEscalas = nEscalas;
    tempodeVoo = temp;
    comandante = piloto;
    copiloto = piloto1;
}
Voo::~Voo(){
    for(Passageiro* p : passageiros){
        delete p;
    }
}

void Voo::embarcarPassageiros(){

}

void Voo::exibirAeronave(){
    cout << aviao.getCodigo() << aviao.getModelo() << aviao.getCapacidade() << aviao.getAutonomia() << aviao.getVelocidadeMedia();
}

void Voo::exibirPassageiros(){
    for(Passageiro* p : passageiros){
        cout << p->getNome() << p->getCpf() << p->getNumbilhete();
    }
}

void Voo::exibirPilotos(){
    comandante.exibePiloto();
    copiloto.exibePiloto();
}

void Voo::mostrarVoo(){
    cout << codigo << origem << destino << distancia << tempodeVoo << numeroEscalas;
    exibirAeronave();
    exibirPilotos();
    exibirPassageiros();

}