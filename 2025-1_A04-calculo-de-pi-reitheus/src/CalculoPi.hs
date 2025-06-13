module CalculoPi
  ( valorPi,
    main,
  )
where

import System.IO (BufferMode (NoBuffering), hSetBuffering, stdout)

-- | Calcula o valor aproximado de Pi usando k termos da série de Leibniz.
-- Pré-condição: k deve ser um inteiro não negativo.
-- Se k = 0, o resultado é 0.0.
valorPi :: Integer -> Double
valorPi k = 

-- | Ação principal que interage com o usuário.
main :: IO ()
main = do 
  hSetBuffering stdout NoBuffering
  putStrLn "Cálculo aproximado de π por série"
  putStrLn "===================================="
  putStr "Digite o número de termos desejados na série: "
  num <- readLn
  if num > 0 then
    let pi = valorPi num
    putStr ("π: " ++ show pi)
    else putStrLn "Número de termos deve ser não negativo."
