#include "../src/Pessoa.h"

Pessoa::Pessoa(string nome, long long cpf){
    this->nome = nome;
    this->cpf = cpf;
}

Pessoa::~Pessoa() {
    // Destrutor vazio, pois não há alocação dinâmica de recursos adicionais
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

string Pessoa::getNome()const{
    return nome;
}

void Pessoa::setCpf(long long cpf){
    this->cpf = cpf;
}

long long Pessoa::getCpf()const{
    return cpf;
}

string Pessoa::serializar() const {
    return "Pessoa," + nome + "," + to_string(cpf);
}

void Pessoa::verificarCpf(long long cpf) {
    if (cpf < 0) {
        throw invalid_argument("CPF inválido. O CPF não pode ser negativo.");
    }
    if (to_string(cpf).length() != 11) {
        throw invalid_argument("CPF inválido. O CPF deve ter 11 dígitos.");
    }
    // Verifica se o CPF contém apenas dígitos
    string cpfStr = to_string(cpf);
    for (char c : cpfStr) {
        if (!isdigit(c)) {
            throw invalid_argument("CPF inválido. O CPF deve conter apenas dígitos.");
        }
    }
    // Se todas as verificações passarem, o CPF é considerado válido
    this->cpf = cpf;
}