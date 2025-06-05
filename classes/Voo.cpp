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

void Voo::embarcarPassageiros(){

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

Voo* Voo::criarVoo(){
    int cod, nEscalas;
    string orig, dest;
    float dist, temp;
    Aeronave aeronave;
    Horario hora;
    Piloto piloto, piloto1;
    Voo *tmp;
    cin >> cod;
    
}