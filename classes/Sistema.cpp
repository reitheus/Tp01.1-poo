#include "../src/Sistema.h"

// Construtor: inicializa o objeto Sistema
Sistema::Sistema() {
}

// Destrutor padrão
Sistema::~Sistema() {
    // Liberação de recursos, se necessário
}

// Define o vetor de aeronaves
void Sistema::setAeronaves(const vector<Aeronave*>& a) {
    aeronaves = a;
}

// Define o vetor de voos
void Sistema::setVoos(const vector<Voo*>& v) {
    voos = v;
}

// Define o vetor de passageiros
void Sistema::setPassageiros(const vector<Passageiro*>& p) {
    passag = p;
}

// Define o vetor de pilotos
void Sistema::setPilotos(const vector<Piloto*>& pi) {
    pilot = pi;
}

// Função para cadastrar uma nova aeronave
void Sistema::cadastrarAeronave(){
    string codigo, modelo;
    int capacidade;
    float velocidadeMedia, autonomia;
    Aeronave tmp;
    limparTela();
    cout << "Cadastro de Aeronave" << endl;

    // Verifica se já existe uma aeronave com o mesmo código
    cout << "Digite o código da aeronave: ";
    cin >> codigo;
    if(tmp.encontrarAeronavePorCodigo(aeronaves, codigo) != nullptr) {
        cout << "Já existe uma aeronave com este código." << endl;
        return;
    }

    // Verifica se o modelo é válido
    cout << "Digite o modelo da aeronave: ";
    cin.ignore(); // Limpa o buffer do cin
    getline(cin, modelo); 
    if (modelo.empty()) {
        cout << "Modelo inválido." << endl;
        system("pause");
        return;
    }

    // Verifica se a capacidade, velocidade média e autonomia são válidas
    cout << "Digite a capacidade da aeronave: ";
    cin >> capacidade;
    if (capacidade <= 0 || cin.fail()) {
        cout << "Capacidade inválida." << endl;
        system("pause");
        return;
    }
    cout << "Digite a velocidade média da aeronave em milhas/h: ";
    cin >> velocidadeMedia;
    if (velocidadeMedia <= 0 || cin.fail()) {
        cout << "Velocidade média inválida. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }
    cout << "Digite a autonomia da aeronave em milhas: ";
    cin >> autonomia;
    if (autonomia <= 0 || cin.fail()) {
        cout << "Autonomia inválida. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }

    Aeronave* novaAeronave = new Aeronave(codigo, modelo, capacidade, velocidadeMedia, autonomia);
    aeronaves.push_back(novaAeronave);

    cout << "Aeronave cadastrada com sucesso!" << endl;
    system("pause");

}

// Função para cadastrar um novo piloto
void Sistema::cadastrarPiloto() {
    string nome, breve;
    long long cpf;
    int matricula;
    int horasDeVoo;
    Piloto tmp;

    limparTela();
    cout << "Cadastro de Piloto" << endl;

    // Verifica se já existe um piloto com a mesma matrícula ou CPF
    cout << "Digite o nome do piloto: ";
    getline(cin, nome);
    if (nome.empty()) {
        cout << "Nome inválido." << endl;
        system("pause");
        return;
    }
    
    // Verifica se o CPF é válido
    cout << "Digite o CPF do piloto(apenas numeros): ";
    cin >> cpf;
    try {
        tmp.verificarCpf(cpf);
    } catch (const invalid_argument& e) {
        cerr << "Erro ao verificar CPF: " << e.what() << endl;
        system("pause");
        return; // Pula este cadastro se houver erro no CPF
    }
    
    // Verifica se a matrícula é válida
    cout << "Digite a matrícula do piloto: ";
    cin >> matricula;
    if (matricula <= 0 || cin.fail()) {
        cout << "Matrícula inválida. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }
    
    // Verifica se a breve é válida
    cout << "Digite a breve do piloto: ";
    cin >> breve;
    if (breve.empty()) {
        cout << "Breve inválida." << endl;
        system("pause");
        return;
    }
    
    // Verifica se as horas de voo são válidas
    cout << "Digite as horas de voo do piloto: ";
    cin >> horasDeVoo;
    if (horasDeVoo < 0 || cin.fail()) {
        cout << "Horas de voo inválidas. Deve ser um número não negativo." << endl;
        system("pause");
        return;
    }


    for(Piloto* p : pilot) {
        // Verifica se já existe um piloto com a mesma matrícula ou CPF
        if (p->getMatricula() == matricula) {
            cout << "Já existe um piloto com esta matrícula." << endl;
            return;
        }
        if (p->getCpf() == cpf) {
            cout << "Já existe um piloto com este CPF." << endl;
            return;
        }
    }

    Piloto* novoPiloto = new Piloto(nome, cpf, matricula, breve, horasDeVoo);
    pilot.push_back(novoPiloto);
    // Salvar pilotos em arquivo CSV
    cout << "Piloto cadastrado com sucesso!" << endl;
    system("pause");

}

// Função para cadastrar um novo passageiro
void Sistema::cadastrarPassageiro() {
    string nome, bilhete;
    long long cpf;
    Passageiro tmp;

    limparTela();
    cout << "Cadastro de Passageiro" << endl;

    // Verifica se o nome é válido
    cout << "Digite o nome do passageiro: ";
    getline(cin, nome);
    if (nome.empty()) {
        cout << "Nome inválido." << endl;
        system("pause");
        return;
    }

    // Verifica se o CPF é válido
    cout << "Digite o CPF do passageiro(apenas numeros): ";
    cin >> cpf;
    try{
        tmp.verificarCpf(cpf);
    }catch (const invalid_argument& e) {
        cerr << "Erro ao verificar CPF: " << e.what() << endl;
        system("pause");
        return; // Pula este cadastro se houver erro no CPF
    }
    
    // Verifica se o bilhete é válido
    cout << "Digite o bilhete do passageiro: ";
    cin >> bilhete;
    if (bilhete.empty()) {
        cout << "Bilhete inválido." << endl;
        system("pause");
        return;
    }

    // Verifica se já existe um passageiro com o mesmo CPF ou bilhete
    for(Passageiro* p : passag) {
        if(p->getCpf() == cpf){
            cout << "Já existe um passageiro com este CPF." << endl;
            return;
        }
        if(p->getNumbilhete() == bilhete){
            cout << "Já existe um passageiro com este bilhete." << endl;
            return;
        }
    }

    Passageiro* novoPassageiro = new Passageiro(nome, cpf, bilhete, 0);
    passag.push_back(novoPassageiro);

    cout << "Passageiro cadastrado com sucesso!" << endl;
    system("pause");

}

// Função para criar um novo voo
void Sistema::criarVoo() {
    string codigo, origem, destino, codAeronave, matriculaPiloto, matriculaCopiloto, dataSaida, dataChegada;
    float distancia;

    limparTela();
    cout << "Criação de Voo" << endl;

    // Verifica se o código do voo é válido
    cout << "Digite o código do voo: ";
    cin >> codigo;
    if (codigo.empty()) {
        cout << "Código inválido. Deve ser uma string não vazia." << endl;
        system("pause");
        return;
    }

    // Verifica se a origem e o destino são válidos
    cout << "Digite a origem do voo: ";
    cin.ignore();
    getline(cin, origem);
    if (origem.empty()) {
        cout << "Origem inválida." << endl;
        system("pause");
        return;
    }

    // Verifica se o destino é válido
    cout << "Digite o destino do voo: ";
    getline(cin, destino);
    if (destino.empty()) {
        cout << "Destino inválido." << endl;
        system("pause");
        return;
    }

    // Verifica se a data de saída é válida
    cout << "Digite a hora de saída do voo (hh:mm): ";
    getline(cin, dataSaida);
    Horario* hora = new Horario();
    try{
        hora->verificarHora(dataSaida);

    }catch (const invalid_argument& e) {
        cerr << "Erro ao definir horário: " << e.what() << endl;
        system("pause");
        return; // Pula este voo se houver erro no horário
    }

    // Verifica se a aeronave é válida
    if(aeronaves.size() < 1) {
        cout << "Nenhuma aeronave cadastrada. Cadastre uma aeronave primeiro." << endl;
        system("pause");
        return;
    }
    cout << "Lista de aeronaves disponíveis:" << endl;
    listarAeronaves();
    cout << "Digite o código da aeronave: ";
    cin >> codAeronave;
    if (codAeronave.empty()) {
        cout << "Código da aeronave não pode ser vazio." << endl;
        system("pause");
        return;
    }
    
    // Verifica se a distância do voo é válida
    cout << "Digite a distância do voo em km: ";
    cin >> distancia;
    if (distancia <= 0 || cin.fail()) {
        cout << "Distância inválida. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }
    
    // Verifica se há pelo menos dois pilotos cadastrados
    if(pilot.size() < 2){
        cout << "Não há pilotos suficientes cadastrados. Cadastre pelo menos dois pilotos." << endl;
        system("pause");
        return;
    }
    // Verifica se o piloto e copiloto são válidos
    cout << "Lista de pilotos disponíveis:" << endl;
    listarPilotos();
    cout << "Digite a matrícula do piloto: ";
    cin >> matriculaPiloto;
    
    cout << "Escolha o copiloto do voo: " << endl;
    cout << "Digite a matrícula do copiloto: ";
    listarPilotos();
    cin >> matriculaCopiloto;
    if (matriculaPiloto.empty() || matriculaCopiloto.empty()) {
        cout << "Matrícula do piloto ou copiloto não pode ser vazia." << endl;
        system("pause");
        return;
    }
    // Verifica se o piloto e copiloto existem
    Aeronave tmp;
    Piloto tmp1;
    Aeronave* aeronave = tmp.encontrarAeronavePorCodigo(aeronaves, codAeronave);
    Piloto* piloto = tmp1.encontrarPilotoPorMatricula(pilot, stoi(matriculaPiloto));
    Piloto* copiloto = tmp1.encontrarPilotoPorMatricula(pilot, stoi(matriculaCopiloto));

    if (!aeronave || !piloto || !copiloto) {
        cout << "Dados inválidos. Verifique os códigos e matrículas fornecidos." << endl;
        system("pause");
        return;
    }

    hora->calculaDuracao(distancia, aeronave->getVelocidadeMedia(), hora->calcularEscalas(distancia, aeronave->getAutonomia()));
    int escalas = hora->calcularEscalas(distancia, aeronave->getAutonomia());
    
    piloto->setHorasdevoo(piloto->getHorasdevoo() + hora->getHorachegada());
    copiloto->setHorasdevoo(copiloto->getHorasdevoo() + hora->getHorachegada());
    Voo* voo = new Voo(stoi(codigo), origem, destino, distancia, 0,aeronave, hora,escalas, piloto, copiloto);
    voos.push_back(voo);

    cout << "Voo criado com sucesso!" << endl;
    system("pause");

}

// Função para embarcar um passageiro em um voo
void Sistema::embarcarPassageiro() {
    string bilhetePassageiro;
    int codigoVoo;
    limparTela();
    cout << "Embarque de Passageiro" << endl;
    cout << "Lista de voos disponíveis:" << endl;
    listarVoos();
    cout << "Digite o Código do voo: ";
    cin >> codigoVoo;
    
    Voo* voo = nullptr;
    for (auto v : voos) {
        if (v->getCod() == codigoVoo) {
            voo = v;
            break;
        }
    }
    // Verifica se o voo existe
    if (voo == nullptr) {
        cout << "Voo não encontrado." << endl;
        system("pause");
        return;
    }
    // Verifica se o voo já atingiu a capacidade máxima
    if (voo->getLotacao() >= voo->getAeronave()->getCapacidade()) {
        cout << "Capacidade máxima atingida para o voo " << codigoVoo << endl;
        system("pause");
        return;
    }
    
    // Verifica se há passageiros cadastrados
    cout << "Lista de Passageiros cadastrados:" << endl;
    listarPassageiros();
    cout << "Digite o bilhete do passageiro que deseja embarcar: ";
    cin >> bilhetePassageiro;

    Passageiro tmp;
    Passageiro* passageiro = tmp.encontrarPassageiroPorBilhete(passag, bilhetePassageiro);

    if (passageiro == nullptr) {
        cout << "Passageiro não encontrado." << endl;
        system("pause");
        return;
    }

    voo->adicionarPassageiro(passageiro);
    voo->setLotacao(voo->getLotacao() + 1);
    passageiro->setNumvoo(passageiro->getNumvoo() + 1);
    cout << "Passageiro embarcado com sucesso no voo " << codigoVoo << endl;
    system("pause");

}

// Função para listar todos os passageiros de um voo
void Sistema::listarPassageirosDeVoo() {
    limparTela();
    int codigoVoo;
    cout << "Listagem de Passageiros por Voo" << endl;
    // Verifica se há voos cadastrados
    if (voos.empty()) {
        cout << "Nenhum voo cadastrado." << endl;
        system("pause");
        return;
    }
    // Solicita o código do voo
    cout << "Lista de voos disponíveis:" << endl;
    listarVoos();
    cout << "Digite o código do voo: ";
    cin >> codigoVoo;
    // Verifica se o código do voo é válido
    if (codigoVoo <= 0 || cin.fail()) {
        cout << "Código inválido. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }

    limparTela();
    cout << "Lista de Passageiros do Voo " << codigoVoo << endl;
    // Verifica se o voo existe
    Voo* voo = nullptr;
    for (const auto& v : voos) {
        if (v->getCod() == codigoVoo) {
            voo = v;
            break;
        }
    }

    // Se o voo não for encontrado, exibe mensagem de erro
    if (!voo) {
        cout << "Voo não encontrado." << endl;
        system("pause");
        return;
    }
    // Se o voo não tiver passageiros, exibe mensagem de aviso
    const auto& passageiros = voo->getPassageiros();
    if (passageiros.empty()) {
        cout << "Nenhum passageiro embarcado neste voo." << endl;
        system("pause");
        return;
    }

    for (const auto& p : passageiros) {
        cout << "Nome: " << p->getNome() 
             << ", Bilhete: " << p->getNumbilhete() 
             << ", CPF: " << p->getCpf() 
             << endl;
    }
    // system("pause");
     // Adicionar esta parte para esperar o usuário
    cout << "\nPressione Enter para voltar ao menu...\n";
    cin.ignore();  // Limpa qualquer entrada anterior
    cin.get();     // Espera o Enter
}

// Executa a opção escolhida pelo usuário no menu principal
void Sistema::executarOpcao(int op){
    switch (op) {
        case 1:
            cadastrarAeronave();
            break;
        case 2:
            cadastrarPiloto();
            break;
        case 3:
            cadastrarPassageiro();
            break;
        case 4:
            criarVoo();
            break;
        case 5:
            embarcarPassageiro();
            break;
        case 6:
            limparTela();
            listarVoos();
            // system("pause");
            cout << "\nPressione Enter para voltar ao menu...\n";
            cin.ignore();  // Limpa qualquer entrada anterior
            cin.get();     // Espera o Enter
            break;
        case 7: {
            listarPassageirosDeVoo();
            break;
        }
        case 8:
            gerarRelatorios();
            break;
        case 9:
            salvarDados();
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }

}

// Função para salvar todos os dados do sistema em arquivos
void Sistema::salvarDados() {
    // Salvar dados em arquivos CSV
    Aeronave tmp;
    Voo tmp1;
    Piloto tmpPiloto;
    Passageiro tmpPassageiro;

    limparTela();
    cout << "Salvando dados..." << endl;

    tmp.salvarAeronavesCSV(aeronaves, "aeronaves.csv");    
    tmpPiloto.salvarPilotosCSV(pilot, "pilotos.csv");  // Novo arquivo
    tmpPassageiro.salvarPassageirosCSV(passag, "passageiros.csv");  // Novo arquivo
    tmp1.salvarVoosCSV(voos, "voos.csv");

    cout << "Dados salvos com sucesso!" << endl;
}

// Função para carregar todos os dados do sistema a partir dos arquivos
void Sistema::carregarDados() {
    limparTela();
    cout << "Carregando dados..." << endl;
    // Carregar dados de arquivos CSV
    ifstream arquivoAeronaves("aeronaves.csv", ios::in | ios::app);
    ifstream arquivoPilotos("pilotos.csv", ios::in | ios::app);
    ifstream arquivoPassageiros("passageiros.csv", ios::in | ios::app);
    ifstream arquivoVoos("voos.csv", ios::in | ios::app);
    Aeronave tmp;
    Piloto tmp1;
    Passageiro tmp2;
    Voo tmp3;


    aeronaves = tmp.carregarAeronavesCSV("aeronaves.csv");
    if (aeronaves.empty()) {
        cout << "Nenhuma aeronave encontrada no arquivo." << endl;
    } else {
        cout << "Aeronaves carregadas com sucesso!" << endl;
    }
    pilot = tmp1.carregarPilotosCSV("pilotos.csv");
    if (pilot.empty()) {
        cout << "Nenhum piloto encontrado no arquivo." << endl;
    } else {
        cout << "Pilotos carregados com sucesso!" << endl;
    }
    passag = tmp2.carregarPassageirosCSV("passageiros.csv");
    if (passag.empty()) {
        cout << "Nenhum passageiro encontrado no arquivo." << endl;
    } else {
        cout << "Passageiros carregados com sucesso!" << endl;
    }
    voos = tmp3.carregarVoosCSV("voos.csv", aeronaves, pilot, passag);
    if (voos.empty()) {
        cout << "Nenhum voo encontrado no arquivo." << endl;
    } else {
        cout << "Voos carregados com sucesso!" << endl;
    }
    arquivoPilotos.close();
    arquivoPassageiros.close();
    arquivoVoos.close();
    arquivoAeronaves.close();
    cout << "Dados carregados com sucesso!" << endl;
}

// Função para gerar relatórios e estatísticas
void Sistema::gerarRelatorios() {
    int opcao;
    Relatorios relatorios;
    limparTela();
    do{
        cout << "=========== RELATÓRIOS E ESTATÍSTICA ============\n";
        cout << "1. Número total de voos\n";
        cout << "2. Média de passageiros por voo\n";
        cout << "3. Aeronaves mais utilizadas\n";
        cout << "4. Passageiros frequentes\n";
        cout << "5. Voos com 90% de ocupação\n";
        cout << "6. Distancia total percorrida por aeronave\n";
        cout << "7. Salvar dados e sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();
        switch (opcao) {
            case 1:
                relatorios.relatorioTotalVoos(voos);
                break;
            case 2:
                relatorios.relatorioMediaPassageiros(voos);
                break;
            case 3:
                relatorios.relatorioAeronavesMaisUsadas(voos);
                break;
            case 4:
                relatorios.relatorioPassageirosFrequentes(voos, passag);
                break;
            case 5:
                relatorios.relatorioVoosCom90Porcento(voos);
                break;
            case 6:
                relatorios.relatorioDistanciaPorAeronave(voos);
                break;
            case 7: {
                // Coleta estatísticas
                int totalVoos = voos.size();

                // Média de passageiros
                int somaPassageiros = 0;
                for (auto& v : voos)
                    somaPassageiros += v->getPassageiros().size();
                float mediaPassageiros = (totalVoos > 0) ? (float)somaPassageiros / totalVoos : 0;

                // Aeronave mais usada
                Aeronave* aeronaveMaisUsada = nullptr;
                map<Aeronave*, int> uso;
                for (auto& v : voos) uso[v->getAeronave()]++;
                if (!uso.empty()) {
                    aeronaveMaisUsada = max_element(uso.begin(), uso.end(),
                        [](auto& a, auto& b) { return a.second < b.second; })->first;
                }

                // Passageiro mais frequente
                Passageiro* passageiroFrequente = nullptr;
                map<Passageiro*, int> freq;
                for (auto& v : voos)
                    for (auto& p : v->getPassageiros())
                        freq[p]++;
                if (!freq.empty()) {
                    passageiroFrequente = max_element(freq.begin(), freq.end(),
                        [](auto& a, auto& b) { return a.second < b.second; })->first;
                }

                // Voos com 90% ou mais de ocupação
                vector<Voo*> voos90;
                for (auto& v : voos) {
                    float taxa = (v->getAeronave()->getCapacidade() == 0) ? 0 :
                                ((float)v->getLotacao() / v->getAeronave()->getCapacidade()) * 100;
                    if (taxa >= 90.0f)
                        voos90.push_back(v);
                }

                // Distância por aeronave
                map<Aeronave*, float> distancias;
                for (auto& v : voos)
                    distancias[v->getAeronave()] += v->getDistancia();

                vector<pair<Aeronave*, float>> distVector(distancias.begin(), distancias.end());

                // Cria objeto preenchido
                Relatorios relatorios(totalVoos, mediaPassageiros, aeronaveMaisUsada,
                            passageiroFrequente, voos90, distVector);
                relatorios.salvarDadosEstatisticas();
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 7);
}

void Sistema::listarAeronaves() {
    cout << "Lista de Aeronaves" << endl;

    for (const auto& aeronave : aeronaves) {
        if (aeronave) {
            cout << "Código: " << aeronave->getCodigo()
                 << ", Modelo: " << aeronave->getModelo()
                 << ", Capacidade: " << aeronave->getCapacidade()
                 << ", Velocidade Média: " << aeronave->getVelocidadeMedia()
                 << ", Autonomia: " << aeronave->getAutonomia()
                 << endl;
        }
    }
}

void Sistema::listarPilotos() {
    cout << "Lista de Pilotos" << endl;
    int contador = 0;
    for (const auto& piloto : pilot) {
        if (piloto) {
            cout << "Piloto " << ++contador << ": "
                 << ", Matricula: " << piloto->getMatricula()
                 << ", Nome: " << piloto->getNome()
                 << ", CPF: " << piloto->getCpf()
                 << ", Breve: " << piloto->getBreve()
                 << ", Horas de Voo: " << piloto->getHorasdevoo()
                 << endl;
        }
    }
}

void Sistema::listarPassageiros() {
    cout << "Lista de Passageiros" << endl;
    int contador = 0;
    for (const auto& passageiro : passag) {
        if (passageiro) {
            cout << "Passageiro " << ++contador << ": "
                 << ", Bilhete: " << passageiro->getNumbilhete()
                 << ", Nome: " << passageiro->getNome()
                 << ", CPF: " << passageiro->getCpf()
                 << ", Número de Voos: " << passageiro->getNumvoo()
                 << endl;
        }
    }
}

void Sistema::listarVoos() {
    cout << "Lista de Voos" << endl;
    int contador = 0;
    for (const auto& voo : voos) {
        if (voo) {
            cout << "Voo " << ++contador << ": "
                 << ", Código: " << voo->getCod()
                 << ", Origem: " << voo->getOrigem()
                 << ", Destino: " << voo->getDestino()
                 << ", Distância: " << voo->getDistancia()
                 << ", Lotação: " << voo->getLotacao()
                 << ", Aeronave: " << voo->getAeronave()->getCodigo()
                 << ", Comandante: " << voo->getComandante()->getNome()
                 << ", Copiloto: " << voo->getCopiloto()->getNome()
                 << endl;
        }
    }

     // Adicionar esta parte para esperar o usuário
    // cout << "\nPressione Enter para continuar...";
    // cin.ignore();  // Limpa qualquer entrada anterior
    // cin.get();     // Espera o Enter
}