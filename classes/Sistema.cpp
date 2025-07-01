#include "../src/Sistema.h"

// Construtor: inicializa o objeto Sistema e carrega os dados do sistema
Sistema::Sistema() {
    // Carrega os dados ao iniciar o sistema
    carregarDados();
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

    cout << "Digite o código da aeronave: ";
    cin >> codigo;

    if(tmp.encontrarAeronavePorCodigo(aeronaves, codigo) != nullptr) {
        cout << "Já existe uma aeronave com este código." << endl;
        return;
    }

    cout << "Digite o modelo da aeronave: ";
    getline(cin, modelo);
    cin.ignore();  
    cout << "Digite a capacidade da aeronave: ";
    cin >> capacidade;
    cout << "Digite a velocidade média da aeronave: ";
    cin >> velocidadeMedia;
    cout << "Digite a autonomia da aeronave: ";
    cin >> autonomia;

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

    cout << "Digite o nome do piloto: ";
    cin.ignore();
    getline(cin, nome);
    
    cout << "Digite o CPF do piloto: ";
    cin >> cpf;
    try {
        tmp.verificarCpf(cpf);
    } catch (const invalid_argument& e) {
        cerr << "Erro ao verificar CPF: " << e.what() << endl;
        system("pause");
        return; // Pula este cadastro se houver erro no CPF
    }
    
    cout << "Digite a matrícula do piloto: ";
    cin >> matricula;
    if (matricula <= 0 || cin.fail()) {
        cout << "Matrícula inválida. Deve ser um número positivo." << endl;
        system("pause");
        return;
    }
    
    cout << "Digite a breve do piloto: ";
    cin >> breve;
    
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

    cout << "Digite o nome do passageiro: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite o CPF do passageiro: ";
    cin >> cpf;
    try{
        tmp.verificarCpf(cpf);
    }catch (const invalid_argument& e) {
        cerr << "Erro ao verificar CPF: " << e.what() << endl;
        system("pause");
        return; // Pula este cadastro se houver erro no CPF
    }
    
    cout << "Digite o bilhete do passageiro: ";
    cin >> bilhete;

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

    cout << "Digite o código do voo: ";
    cin >> codigo;

    cout << "Digite a origem do voo: ";
    cin.ignore();
    getline(cin, origem);
    
    cout << "Digite o destino do voo: ";
    getline(cin, destino);
    
    cout << "Digite a hora de saída do voo: ";
    getline(cin, dataSaida);
        
    cout << "Digite o código da aeronave: ";
    getline(cin, codAeronave);
    
    cout << "Digite a distância do voo: ";
    cin >> distancia;
    
    cout << "Digite a matrícula do piloto: ";
    cin >> matriculaPiloto;
    
    cout << "Digite a matrícula do copiloto: ";
    cin >> matriculaCopiloto;
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
    Horario* hora = new Horario();
    try{
        hora->verificarHora(dataSaida);

    }catch (const invalid_argument& e) {
        cerr << "Erro ao definir horário: " << e.what() << endl;
        system("pause");
        return; // Pula este voo se houver erro no horário
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
    cout << "Código do voo: ";
    cin >> codigoVoo;
    
    Voo* voo = nullptr;
    for (auto v : voos) {
        if (v->getCod() == codigoVoo) {
            voo = v;
            break;
        }
    }
    if (voo == nullptr) {
        cout << "Voo não encontrado." << endl;
        system("pause");
        return;
    }

    if (voo->getLotacao() >= voo->getAeronave()->getCapacidade()) {
        cout << "Capacidade máxima atingida para o voo " << codigoVoo << endl;
        system("pause");
        return;
    }
    
    cout << "Bilhete do passageiro: ";
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

// Função para listar todos os voos cadastrados
void Sistema::listarVoos() {
    limparTela();
    cout << "Lista de Voos" << endl;

    for (const auto& voo : voos) {
        if (voo) {
            cout << "Código: " << voo->getCod()
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
    system("pause");

}

// Função para listar todos os passageiros de um voo
void Sistema::listarPassageirosDeVoo() {
    limparTela();
    int codigoVoo;
    cout << "Digite o código do voo: ";
    cin >> codigoVoo;

    limparTela();
    cout << "Lista de Passageiros do Voo " << codigoVoo << endl;

    Voo* voo = nullptr;
    for (const auto& v : voos) {
        if (v->getCod() == codigoVoo) {
            voo = v;
            break;
        }
    }

    if (!voo) {
        cout << "Voo não encontrado." << endl;
        system("pause");
        return;
    }

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
    system("pause");
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
            listarVoos();
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

// Função para salvar os dados dos pilotos e passageiros em arquivo
void Sistema::salvarEmArquivo(string nomeArquivo, vector<Piloto*> pilotos,vector<Passageiro*> passageiros) {
    Piloto tmp;
    Passageiro tmp1;
    tmp.salvarPilotosCSV(pilotos, nomeArquivo);
    tmp1.salvarPassageirosCSV(passageiros, nomeArquivo);

}

// Função para salvar todos os dados do sistema em arquivos
void Sistema::salvarDados() {
    // Salvar dados em arquivos CSV
    Aeronave tmp;
    Voo tmp1;
    limparTela();
    cout << "Salvando dados..." << endl;
    salvarEmArquivo("pessoas.csv", pilot, passag);
    tmp.salvarAeronavesCSV(aeronaves, "aeronaves.csv");
    tmp1.salvarVoosCSV(voos, "voos.csv");
    cout << "Dados salvos com sucesso!" << endl;
}

// Função para carregar todos os dados do sistema a partir dos arquivos
void Sistema::carregarDados() {
    limparTela();
    cout << "Carregando dados..." << endl;
    // Carregar dados de arquivos CSV
    ifstream arquivoAeronaves("aeronaves.csv", ios::in | ios::app);
    ifstream arquivoPessoas("pessoas.csv", ios::in | ios::app);
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
    pilot = tmp1.carregarPilotosCSV("pessoas.csv");
    if (pilot.empty()) {
        cout << "Nenhum piloto encontrado no arquivo." << endl;
    } else {
        cout << "Pilotos carregados com sucesso!" << endl;
    }
    passag = tmp2.carregarPassageirosCSV("pessoas.csv");
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
    arquivoPessoas.close();
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
            case 7:
                relatorios.salvarDadosEstatisticas();
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 7);
}

