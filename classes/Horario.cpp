#include "../src/Horario.h"

Horario::Horario(int saida,int chegada){
    horaSaida = saida;
    horaChegada = chegada;
}

int Horario::calcularEscalas(float distancia, float autonomia) {
    // Considerando que a escala é de 1 hora para cada 1000 km
    int escalas = distancia / autonomia;
    if (escalas < 0) {
        escalas = 0; // Não pode ter escalas negativas
    }
    return escalas;
}

void Horario::calculaDuracao(float distancia,float velocidadeMedia, int escala){
    int duracao = (distancia / velocidadeMedia) + (escala * 1); // Considerando que cada escala leva 1 hora
    if (duracao < 0) {
        duracao = 0; // Não pode ter hora de chegada negativa
    }
    setHorachegada(duracao + getHorasaida()); // Define a hora de chegada em minutos
}

void Horario::verificarHora(string hora){
    // Implementar lógica para verificar horário
    if (hora.length() != 5 || hora[2] != ':') {
        throw invalid_argument("Formato de hora inválido. Use HH:MM.");
    }
    int h = stoi(hora.substr(0, 2));
    int m = stoi(hora.substr(3, 2));
    if (h < 0 || h > 23 || m < 0 || m > 59) {
        throw invalid_argument("Horário inválido. Use HH:MM.");
    }
    int totalMinutos = h * 60 + m; // Converte para minutos
    setHorasaida(totalMinutos); // Define a hora de saída em minutos
}

void Horario::setHorasaida(int hora){
    horaSaida = hora;
}

void Horario::setHorachegada(int hora){
    horaChegada = hora;
}

int Horario::getHorasaida()const{
    return horaSaida;
}

int Horario::getHorachegada()const{
    return horaChegada;
}
