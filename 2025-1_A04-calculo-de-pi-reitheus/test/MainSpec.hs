module Main (main) where

import Control.Monad (when)
import Data.AEq ((~==)) -- Do pacote ieee754
import Test.Hspec
import Test.Hspec.QuickCheck
import Test.QuickCheck
import Test.QuickCheck.Modifiers
import Text.Printf (printf)

import Run (runWithInput) -- Assumindo Run.hs dos projetos anteriores
import qualified CalculoPi as T

-- Função "oráculo" não recursiva para verificar o resultado
-- Esta é a implementação de referência para os testes.
valorReferencia :: Integer -> Double
valorReferencia k
  | k <= 0    = 0.0
  | otherwise = 4 * sum [(-1) ^ i / (2 * fromIntegral i + 1) | i <- [0 .. k - 1]]

-- Gerador para pequenos inteiros não negativos, para evitar timeouts
genPequenoNaoNegativo :: Gen Integer
genPequenoNaoNegativo = choose (0, 2000)

main :: IO ()
main = hspec $ do
  describe "Teste da função pura: valorPi" $ do
    context "com casos específicos" $ do
      it "retorna 0.0 para k = 0" $
        T.valorPi 0 `shouldBe` 0.0

      it "retorna 0.0 para k < 0 (conforme requisito do README)" $
        T.valorPi (-5) `shouldBe` 0.0
      
      it "calcula corretamente para k = 1" $
        T.valorPi 1 `shouldSatisfy` (~== valorReferencia 1) -- 4.0

      it "calcula corretamente para k = 9" $
        T.valorPi 9 `shouldSatisfy` (~== valorReferencia 9) -- ~3.2523

    context "com propriedades (QuickCheck)" $ do
      prop "calcula o mesmo que a versão de referência para valores não negativos" $
        forAll genPequenoNaoNegativo $ \k ->
          T.valorPi k ~== valorReferencia k

  describe "Executando o programa principal (main)" $ do
    context "com entradas válidas (k >= 0)" $ do
      it "exibe o resultado correto para 0 termos" $ do
        let k = 0
        let input = show k ++ "\n"
        let prompt = "Digite o número de termos desejados na série: "
        -- Para k=0, o resultado é exato, então comparar strings é seguro
        let expectedOutput = prompt ++ "π: " ++ show (valorReferencia k) ++ "\n"
        
        out <- runWithInput T.main input
        out `shouldContain` expectedOutput

      -- ############ TESTE CORRIGIDO AQUI ############
      prop "exibe o resultado correto para um número de termos positivo" $
        forAll (getPositive <$> (arbitrary :: Gen (Positive Integer)) `suchThat` (\(Positive x) -> x < 2000)) $ \k -> do
          let input = show k ++ "\n"
          let expectedValue = valorReferencia k
          
          out <- runWithInput T.main input
          
          -- Extrai o valor numérico da string de saída para uma comparação robusta
          let outputLines = lines out
          let lastLine = if null outputLines then "" else last outputLines
          let parts = words lastLine
          let actualValueStr = if length parts > 1 then last parts else "NaN"
          let actualValue = read actualValueStr :: Double
          
          actualValue `shouldSatisfy` (~== expectedValue)

    context "com entradas inválidas (k < 0)" $ do
      it "exibe mensagem de erro para entrada -8" $ do
        let input = "-8\n"
        let prompt = "Digite o número de termos desejados na série: "
        let expectedOutput = prompt ++ "Número de termos deve ser não negativo.\n"
        out <- runWithInput T.main input
        out `shouldContain` expectedOutput

      prop "exibe mensagem de erro para qualquer entrada negativa" $
        forAll (getNegative <$> (arbitrary :: Gen (Negative Integer))) $ \kNegativo -> do
          when (kNegativo < 0) $ do
            let input = show kNegativo ++ "\n"
            let prompt = "Digite o número de termos desejados na série: "
            let expectedOutput = prompt ++ "Número de termos deve ser não negativo.\n"
            out <- runWithInput T.main input
            out `shouldContain` expectedOutput
