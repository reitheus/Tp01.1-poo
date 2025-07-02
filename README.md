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
- `Makefile` — (não testado)

## Como compilar

Recomenda-se compilar usando o `g++`:

```sh
g++ -c -Wall ./classes/Aeronave.cpp ./classes/Horario.cpp ./classes/Passageiro.cpp ./classes/Pessoa.cpp ./classes/Piloto.cpp ./classes/Voo.cpp
```

Ou, se preferir usar o `gcc`:

```sh
gcc -c -Wall ./classes/Aeronave.cpp ./classes/Horario.cpp ./classes/Passageiro.cpp ./classes/Pessoa.cpp ./classes/Piloto.cpp ./classes/Voo.cpp
```

> **Nota:** O Makefile está presente no projeto, mas não foi testado. Caso tenha problemas na compilação, prefira usar os comandos acima manualmente.

## Requisitos

- Compilador C++ (g++ recomendado)
- Sistema operacional compatível com Makefile (opcional)

## Observações

- O projeto está em desenvolvimento.
- Sinta-se à vontade para contribuir ou sugerir melhorias!

---