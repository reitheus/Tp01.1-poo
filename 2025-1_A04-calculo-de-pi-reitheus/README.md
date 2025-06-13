[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/kHHeJ3Jw)
# Tarefa: Cálculo Aproximado de Pi

## Descrição

Nesta tarefa, você implementará um programa em Haskell que calcula um valor aproximado para a constante $\pi$ (Pi) utilizando a série de Gregory-Leibniz.

A aproximação é calculada somando um número $k$ de termos da série. A fórmula que relaciona a série ao número de termos $k$ é:
```math
\pi \approx 4 \sum_{i=0}^{k-1}{\frac{(-1)^i}{2i+1}} = 4 \times (1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \ldots)
```
O programa deverá interagir com o usuário para obter o número de termos ($k$) a serem usados no somatório e, em seguida, exibir o valor aproximado de $\pi$ calculado.

---

## Funções e Ações a Implementar

Você precisará separar a lógica pura do cálculo da interação com o usuário. As definições devem ser feitas nos arquivos de origem (`src/*.hs`).

1.  **`valorPi :: Integer -> Double`**
    * Esta é uma **função pura** que recebe o **número de termos** $k$ (um `Integer`) a serem utilizados no cálculo.
    * **Pré-condição:** Você pode assumir que esta função sempre receberá um `Integer` **não negativo** ($k \ge 0$).
    * Ela deve calcular e resultar no valor aproximado de $\pi$ usando os $k$ termos da série. Se $k=0$, o resultado deve ser 0.0. Se $k > 0$, o somatório deve ir de $i=0$ até $k-1$.
    * **Dica 1:** É altamente recomendado que `valorPi` utilize uma função auxiliar recursiva para calcular o somatório.
    * **Dica 2:** Use a função `fromIntegral :: (Integral a, Num b) => a -> b` para converter valores `Integer` para `Double` nos cálculos.

2.  **`main :: IO ()`**
    * Esta é a **ação de E/S** principal que implementará a interação com o usuário.
    * Ela deve solicitar ao usuário para digitar o número de termos ($k$) desejados na série.
    * **Requisito de Validação:** A ação `main` deve verificar se o número lido do usuário é **não negativo ($k \ge 0$)**.
        * Se o número for válido, `main` deve chamar a função `valorPi` e exibir o resultado.
        * Se o número for inválido (negativo), `main` deve exibir a mensagem: `Número de termos deve ser não negativo.`
    * **Lembrete:** Configure o buffering da saída para garantir que os prompts apareçam corretamente.

---

## Exemplos de Execução

```shellsession
Cálculo aproximado de π por série
====================================
Digite o número de termos desejados na série: -8
Número de termos deve ser não negativo.
```

```shellsession
Cálculo aproximado de π por série
====================================
Digite o número de termos desejados na série: 0
π: 0.0
```

```shellsession
Cálculo aproximado de π por série
====================================
Digite o número de termos desejados na série: 1
π: 4.0
```

```shellsession
Cálculo aproximado de π por série
====================================
Digite o número de termos desejados na série: 9
π: 3.252365934718876
```

```shellsession
Cálculo aproximado de π por série
====================================
Digite o número de termos desejados na série: 2000
π: 3.1410926536210435
```

---

Complete as definições nos arquivos `src/*.hs` para resolver o problema proposto. O seu projeto deve passar em todos os testes fornecidos.

Você pode editar os arquivos fonte em um editor de texto e testá-lo diretamente no ambiente interativo ou com a ferramenta _cabal_ em um terminal:

```shellsession
$ cabal build                 # compila o projeto
$ cabal repl calculo-de-pi    # carrega o projeto no ambiente interativo
$ cabal run calculo-de-pi     # executa o programa
$ cabal test                  # executa os testes
```