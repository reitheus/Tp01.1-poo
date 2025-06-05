#include "..\src\Horario.h"

Horario::Horario(int saida,int chegada){
    horaSaida = saida;
    horaChegada = chegada;
}

void Horario::setHorachegada(int hora){
    horaChegada = hora;
}

void Horario::setHorasaida(int hora){
    horaSaida = hora;
}

int Horario::getHorachegada(){
    return horaChegada;
}

int Horario::getHorasaida(){
    return horaSaida;
}