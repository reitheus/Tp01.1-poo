[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/zGuGA5vL)
# Tarefa: Média de uma Sequência de Números

## Descrição

Nesta tarefa, você implementará um programa interativo em Haskell que calcula a média aritmética de uma sequência de números.

O programa deve primeiro solicitar ao usuário um número inteiro, $n$, que representa a quantidade de números que serão lidos a seguir. Depois, o programa deve ler os $n$ números (que podem ser de ponto flutuante) e, ao final, exibir a média aritmética calculada.

---

## Funções e Ações a Implementar

É fortemente recomendado que você separe a lógica pura do cálculo da interação com o usuário. As definições devem ser feitas nos arquivos de origem (`src/*.hs`).

1.  **`calculaMedia :: [Double] -> Double`** (Sugestão de Função Pura)
    * Esta é uma **função pura** que recebe uma lista de números (`[Double]`) e resulta na sua média aritmética.
    * **Requisito de Validação:** Se a lista for vazia (o que acontecerá se o usuário digitar $n \le 0$), a função deve retornar `0.0`. Caso contrário, deve calcular `soma dos elementos / quantidade de elementos`.
    * **Dica:** Você pode usar as funções `sum` e `length` do `Prelude`. Lembre-se de converter o resultado de `length` (que é um `Int`) para `Double` usando `fromIntegral` antes da divisão.

2.  **`lerNumeros :: Int -> IO [Double]`** (Sugestão de Ação de E/S Auxiliar)
    * Esta é uma **ação de E/S recursiva** que recebe a quantidade de números a serem lidos, $n$.
    * Ela deve ler $n$ números do teclado e retorná-los em uma lista, `[Double]`.
    * Se $n \le 0$, a ação deve simplesmente retornar uma lista vazia (`[]`).

3.  **`main :: IO ()`**
    * Esta é a **ação de E/S** principal que orquestra todo o processo:
        * Configura o buffering da saída para que os prompts apareçam corretamente.
        * Solicita e lê a quantidade de números, $n$.
        * Chama a ação `lerNumeros` para obter a lista de números.
        * Passa a lista obtida para a função pura `calculaMedia`.
        * Exibe o resultado final formatado.

---

## Formatação da Saída Numérica

Para garantir consistência, a média final deve ser exibida com exatamente **duas casas decimais**. Utilize a função `printf` do módulo `Text.Printf`.

* **Exemplo de Uso:** `printf "A média dos números é: %.2f\n" valorDaMedia`

---

## Exemplos de Execução

```shellsession
Quantidade de números a serem lidos: 4
Digite um número: 10.5
Digite um número: 20.0
Digite um número: 5.5
Digite um número: 4.0
A média dos números é: 10.00
```

```shellsession
Quantidade de números a serem lidos: 3
Digite um número: -10
Digite um número: 10
Digite um número: 30
A média dos números é: 10.00
```

```shellsession
Quantidade de números a serem lidos: 1
Digite um número: 99.5
A média dos números é: 99.50
```

```shellsession
Quantidade de números a serem lidos: 3
Digite um número: 1
Digite um número: 2
Digite um número: 2
A média dos números é: 1.67
```

```shellsession
Quantidade de números a serem lidos: 0
A média dos números é: 0.00
```

```shellsession
Quantidade de números a serem lidos: -5
A média dos números é: 0.00
```

---

## Desenvolvimento e Testes

Complete as definições em `src/*.hs`. O seu projeto deve passar em todos os testes fornecidos.

Você pode editar os arquivos fonte e testá-los localmente com a ferramenta _cabal_ em um terminal:

```shellsession
$ cabal build                 # Compila o projeto
$ cabal repl media-sequencia  # Carrega o projeto no REPL (use o nome do seu pacote)
$ cabal run media-sequencia   # Executa o programa
$ cabal test                  # Executa os testes de verificação automática
```
