module MediaSequencia
  ( calculaMedia,
    lerNumeros,
    main,
  )
where

import System.IO (BufferMode (NoBuffering), hFlush, hSetBuffering, stdout)
import Text.Printf (printf)
import Text.Read (readMaybe)

-- | Calcula a média de uma lista de Doubles.
-- Retorna 0.0 para uma lista vazia.
calculaMedia :: [Double] -> Double
calculaMedia xs | xs == null = 0.0
                | otherwise = do let soma = sum xs
                                 let tam = length xs
                                 num <- fromInteger tam
                                 let media = sum / num
                                 return media

-- | Lê n Doubles da entrada padrão e os retorna em uma lista.
-- Retorna uma lista vazia se n <= 0.
lerNumeros :: Int -> IO [Double]
lerNumeros n | n <= 0 = return []
             | otherwise = do putStr "Digite um número: "
                              x <- readLn
                              xs <- lerNumeros (n-1)
                              return (x:xs)

-- | Ação principal que orquestra o programa.
main :: IO ()
main = do
    hSetBuffering stdout NoBuffering
    putStr "Quantidade de números a serem lidos: "
    num <- readLn
    nums <- lerNumeros num
    let media = calculaMedia nums
    printf "A média dos números é: %2.f" media

