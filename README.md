# Tp01.1-poo

Trabalho prático de Programação Orientada a Objetos sobre um sistema básico de aeroporto.

## Descrição

Este projeto implementa um sistema simples de gerenciamento de aeroporto utilizando C++. O sistema conta com classes como Aeronave, Horário, Passageiro, Pessoa, Piloto e Voo, simulando as operações básicas de um aeroporto.

## Estrutura do Projeto

- `classes/` — Contém todas as classes principais do sistema:
  - `Aeronave.cpp`
  - `Horario.cpp`
  - `Passageiro.cpp`
  - `Pessoa.cpp`
  - `Piloto.cpp`
  - `Voo.cpp`
  - `Sistema.cpp`
  - `Persistencia.cpp`
- `Makefile`

## Como compilar

Recomenda-se compilar usando o `make` :

Se estiver em um ambiente que suporte `make` (Linux, WSL ou Git Bash no Windows), basta executar:

```sh
make
./programa
```

Ou, se preferir compilar usando o `g++`:

```sh
g++ -c -Wall ./classes/Aeronave.cpp ./classes/Horario.cpp ./classes/Passageiro.cpp ./classes/Pessoa.cpp ./classes/Piloto.cpp ./classes/Voo.cpp ./classes/Sistema.cpp ./classes/Persistencia.cpp
```

Ou, se preferir usar o `gcc`:

```sh
gcc -c -Wall ./classes/Aeronave.cpp ./classes/Horario.cpp ./classes/Passageiro.cpp ./classes/Pessoa.cpp ./classes/Piloto.cpp ./classes/Voo.cpp ./classes/Sistema.cpp ./classes/Persistencia.cpp
```

## Requisitos

- Compilador C++ (g++ recomendado)
- Sistema operacional compatível com Makefile (opcional)

## Observações

- O projeto está em desenvolvimento.
- Sinta-se à vontade para contribuir ou sugerir melhorias!

---
