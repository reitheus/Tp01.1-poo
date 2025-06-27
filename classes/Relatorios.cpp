#include "..\src\Relatorios.h"

// Construtor da classe Relatorios, inicializa os membros com os parâmetros recebidos
Relatorios::Relatorios(int totalVoos, float mediaPassageiros, Aeronave* aeronaveMaisUsada, Passageiro* passageiroFrequente, vector<Voo*> voosCom90Porcento, vector<pair<Aeronave*, float>> distanciaPorAeronave){
    this->totalVoos = totalVoos;
    this->mediaPassageiros = mediaPassageiros;
    this->aeronaveMaisUsada = aeronaveMaisUsada;
    this->passageiroFrequente = passageiroFrequente;
    this->voosCom90Porcento = voosCom90Porcento;
    this->distanciaPorAeronave = distanciaPorAeronave;
}

// Exibe o total de voos cadastrados
void Relatorios::relatorioTotalVoos(vector<Voo*> voos) {
    limparTela();
    cout << "Total de voos: " << voos.size() << endl;
    system("pause");
}

// Calcula e exibe a média de passageiros por voo
void Relatorios::relatorioMediaPassageiros(vector<Voo*> voos) {
    limparTela();
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        int totalPassageiros = 0;
        for (const auto& voo : voos) {
            totalPassageiros += voo->getPassageiros().size();
        }
        cout << "Média de passageiros por voo: " << static_cast<float>(totalPassageiros) / voos.size() << endl;
    }
    system("pause");
}

// Identifica e exibe a aeronave mais utilizada nos voos
void Relatorios::relatorioAeronavesMaisUsadas(vector<Voo*> voos) {
    limparTela();
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        map<Aeronave*, int> contagem;
        for (const auto& voo : voos) {
            contagem[voo->getAeronave()]++;
        }
        auto it = max_element(contagem.begin(), contagem.end(),
            [](const pair<Aeronave*, int>& a, const pair<Aeronave*, int>& b) {
                return a.second < b.second;
            });
        if (it != contagem.end()) {
            cout << "Aeronave mais utilizada: " << it->first->getModelo() << " (" << it->second << " voos)" << endl;
        }
    }
    system("pause");
}

// Identifica e exibe o passageiro mais frequente entre todos os voos
void Relatorios::relatorioPassageirosFrequentes(vector<Voo*> voos, vector<Passageiro*> passag) {
    limparTela();
    if (passag.empty()) {
        cout << "Nenhum passageiro cadastrado." << endl;
    } else {
        map<Passageiro*, int> contagem;
        for (const auto& voo : voos) {
            for (const auto& passageiro : voo->getPassageiros()) {
                contagem[passageiro]++;
            }
        }
        auto it = max_element(contagem.begin(), contagem.end(),
            [](const pair<Passageiro*, int>& a, const pair<Passageiro*, int>& b) {
                return a.second < b.second;
            });
        if (it != contagem.end()) {
            cout << "Passageiro mais frequente: " << it->first->getNome() << " (" << it->second << " voos)" << endl;
        }
    }
    system("pause");
}

// Exibe os voos que têm 90% ou mais de ocupação
void Relatorios::relatorioVoosCom90Porcento(vector<Voo*> voos) {
    limparTela();
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        for (const auto& voo : voos) {
            if (taxaoDeOcupacao(voo) >= 90.0) {
                cout << "Voo com 90% ou mais de ocupação: " << voo->getCod() << endl;
            }
        }
    }
    system("pause");
}

// Exibe a distância total percorrida por cada aeronave
void Relatorios::relatorioDistanciaPorAeronave(vector<Voo*> voos) {
    limparTela();
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        map<Aeronave*, float> distancias;
        for (const auto& voo : voos) {
            distancias[voo->getAeronave()] += voo->getDistancia();
        }
        for (const auto& [aeronave, distancia] : distancias) {
            cout << "Distância total percorrida pela aeronave " << aeronave->getModelo() << ": " << distancia << " km" << endl;
        }
    }
    system("pause");
}

// Calcula a taxa de ocupação de um voo (em porcentagem)
float Relatorios::taxaoDeOcupacao(Voo* voo) {
    if (voo->getAeronave()->getCapacidade() == 0) {
        return 0.0f; // Evita divisão por zero
    }
    return (static_cast<float>(voo->getLotacao()) / voo->getAeronave()->getCapacidade()) * 100.0;
}

// Salva os dados estatísticos em um arquivo de texto
void Relatorios::salvarDadosEstatisticas() {
    ofstream arquivo("estatisticas.txt", ios::out | ios::app);
    limparTela();
    cout << "Salvando dados e estatísticas..." << endl;

    if (arquivo.is_open()) {
        arquivo << "Total de voos: " << totalVoos << endl;
        arquivo << "Média de passageiros por voo: " << mediaPassageiros << endl;
        if (aeronaveMaisUsada) {
            arquivo << "Aeronave mais utilizada: " << aeronaveMaisUsada->getModelo() << endl;
        }
        if (passageiroFrequente) {
            arquivo << "Passageiro mais frequente: " << passageiroFrequente->getNome() << endl;
        }
        arquivo << "Voos com 90% ou mais de ocupação: " << endl;
        for (const auto& voo : voosCom90Porcento) {
            arquivo << " - " << voo->getCod() << endl;
        }
        arquivo << "Distância total por aeronave: " << endl;
        for (const auto& [aeronave, distancia] : distanciaPorAeronave) {
            arquivo << " - " << aeronave->getModelo() << ": " << distancia << " km" << endl;
        }
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }
    arquivo.close();
    cout << "Dados e estatísticas salvos com sucesso!" << endl;
    system("pause");
}