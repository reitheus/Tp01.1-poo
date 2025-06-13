module Main (main) where

import Data.AEq ((~==))
import Run (runWithInput)
import System.IO (BufferMode (NoBuffering), hFlush, hSetBuffering, stdout)
import Test.Hspec
import Test.Hspec.QuickCheck
import Test.QuickCheck
import Text.Printf (printf)
import qualified MediaSequencia as T

-- Gerador para listas não vazias de Doubles
genNonEmptyListOfDoubles :: Gen [Double]
genNonEmptyListOfDoubles = listOf1 (choose (-1000, 1000))

main :: IO ()
main = hspec $ do
  describe "Função Pura: calculaMedia" $ do
    it "retorna 0.0 para uma lista vazia" $
      T.calculaMedia [] `shouldBe` 0.0

    it "calcula a média corretamente para uma lista simples" $
      T.calculaMedia [10, 20, 30] `shouldBe` 20.0

    it "calcula a média corretamente para uma lista com números negativos" $
      T.calculaMedia [-10, 0, 10, 20] `shouldBe` 5.0

    prop "é equivalente a sum/length para listas não vazias" $
      forAll genNonEmptyListOfDoubles $ \xs ->
        T.calculaMedia xs ~== sum xs / fromIntegral (length xs)

  describe "Ação de E/S: main" $ do
    -- Define os prompts para reutilização e clareza
    let promptQtde = "Quantidade de números a serem lidos: "
    let promptNum = "Digite um número: "

    it "calcula a média para 4 números" $ do
      let input = unlines ["4", "10.5", "20.0", "5.5", "4.0"]
      let saidaFinal = printf "A média dos números é: %.2f\n" (10.00 :: Double)
      let expectedOutput = promptQtde ++ 
                           promptNum ++ promptNum ++ promptNum ++ promptNum ++ 
                           saidaFinal
      out <- runWithInput T.main input
      out `shouldBe` expectedOutput

    it "calcula a média para 3 números (incluindo negativos)" $ do
      let input = unlines ["3", "-10", "10", "30"]
      let saidaFinal = printf "A média dos números é: %.2f\n" (10.00 :: Double)
      let expectedOutput = promptQtde ++ 
                           promptNum ++ promptNum ++ promptNum ++
                           saidaFinal
      out <- runWithInput T.main input
      out `shouldBe` expectedOutput

    it "retorna 0.0 para n = 0" $ do
      let input = unlines ["0"]
      let saidaFinal = printf "A média dos números é: %.2f\n" (0.00 :: Double)
      -- Quando n=0, nenhum prompt para "Digite um número" deve aparecer
      let expectedOutput = promptQtde ++ saidaFinal
      out <- runWithInput T.main input
      out `shouldBe` expectedOutput

    it "retorna 0.0 para n < 0" $ do
      let input = unlines ["-5"]
      let saidaFinal = printf "A média dos números é: %.2f\n" (0.00 :: Double)
      -- Quando n<0, nenhum prompt para "Digite um número" deve aparecer
      let expectedOutput = promptQtde ++ saidaFinal
      out <- runWithInput T.main input
      out `shouldBe` expectedOutput

    it "calcula a média para 1 número" $ do
      let input = unlines ["1", "99.5"]
      let saidaFinal = printf "A média dos números é: %.2f\n" (99.50 :: Double)
      let expectedOutput = promptQtde ++ promptNum ++ saidaFinal
      out <- runWithInput T.main input
      out `shouldBe` expectedOutput
