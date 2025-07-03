<<<<<<< Updated upstream
/* HUGO AUGUSTO SILVA DE FARIA 
   JULIANA APARECIDA BORGES
   LOURRANE LINDSAY ALVES EVARISTO
   MATHEUS MOTA GOMES
   SAMARA PALOMA LOPES AUGUSTO RIBEIRO 
*/

#include "../src/Sistema.h"
=======
/* HUGO AUGUSTO SILVA DE FARIA 
   JULIANA APARECIDA BORGES
   LOURRANE LINDSAY ALVES EVARISTO
   MATHEUS MOTA GOMES
   SAMARA PALOMA LOPES AUGUSTO RIBEIRO 
*/
>>>>>>> Stashed changes

#include "../src/Sistema.h"

int main(){
    Sistema sistema;
    int opcao;

    // Carregar dados dos arquivos CSV ao iniciar o sistema
    sistema.carregarDados();
    cout << "Bem-vindo ao Sistema de Gerenciamento de Voos" << endl;

    // Loop principal do menu
    do{
        limparTela();
        cout << "=========== SISTEMA DE CONTROLE DE VOOS ============\n";
        cout << "1. Cadastrar aeronave\n";
        cout << "2. Cadastrar piloto\n";
        cout << "3. Cadastrar passageiro\n";
        cout << "4. Criar voo\n";
        cout << "5. Embarcar passageiro em voo\n";
        cout << "6. Listar voos\n";
        cout << "7. Listar passageiros de um voo\n";
        cout << "8. Gerar relatórios e estatísticas\n";
        cout << "9. Salvar dados e sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        // Executar a opção escolhida
        sistema.executarOpcao(opcao);
    }while(opcao != 9);

    // Salvar dados antes de sair
    sistema.salvarDados();
    return 0;
}
