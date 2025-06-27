#include "../src/Sistema.h"

Sistema::Sistema() {
    // Carrega os dados ao iniciar o sistema
    carregarDados();
}

Sistema::~Sistema() {

}

void Sistema::setAeronaves(const vector<Aeronave*>& a) {
    aeronaves = a;
}

void Sistema::setVoos(const vector<Voo*>& v) {
    voos = v;
}

void Sistema::setPassageiros(const vector<Passageiro*>& p) {
    passag = p;
}

void Sistema::setPilotos(const vector<Piloto*>& pi) {
    pilot = pi;
}

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
    cin >> modelo;
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

void Sistema::cadastrarPiloto() {
    string nome, breve;
    long long cpf;
    int matricula;
    int horasDeVoo;
    Piloto tmp;

    limparTela();
    cout << "Cadastro de Piloto" << endl;

    cout << "Digite o nome do piloto: ";
    cin >> nome;
    
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
    
    cout << "Digite a breve do piloto: ";
    cin >> breve;
    
    cout << "Digite as horas de voo do piloto: ";
    cin >> horasDeVoo;


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

void Sistema::cadastrarPassageiro() {
    string nome, bilhete;
    long long cpf;

    limparTela();
    cout << "Cadastro de Passageiro" << endl;

    cout << "Digite o nome do passageiro: ";
    getline(cin, nome);
    
    cout << "Digite o CPF do passageiro: ";
    cin >> cpf;
    
    cout << "Digite o bilhete do passageiro: ";
    cin >> bilhete;

    for(Passageiro* p : passag) {
        if (p->getNumbilhete() == bilhete) {
            cout << "Já existe um passageiro com este bilhete." << endl;
            return;
        }
        if (p->getCpf() == cpf) {
            cout << "Já existe um passageiro com este CPF." << endl;
            return;
        }
    }

    Passageiro* novoPassageiro = new Passageiro(nome,0 , bilhete, cpf);
    passag.push_back(novoPassageiro);

    cout << "Passageiro cadastrado com sucesso!" << endl;
    system("pause");

}

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
    Voo* voo = new Voo(stoi(codigo), origem, destino, distancia, escalas,aeronave, hora, hora->getHorachegada(), piloto, copiloto);
    voos.push_back(voo);

    cout << "Voo criado com sucesso!" << endl;
    system("pause");

}

void Sistema::embarcarPassageiro() {
    string bilhetePassageiro;
    int codigoVoo;
    limparTela();
    cout << "Embarque de Passageiro" << endl;
    cout << "Código do voo: ";
    cin >> codigoVoo;
    cout << "Bilhete do passageiro: ";
    cin >> bilhetePassageiro;

    Voo* voo = nullptr;
    for (Voo* v : voos) {
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
    Passageiro tmp;
    Passageiro* passageiro = tmp.encontrarPassageiroPorBilhete(passag, bilhetePassageiro);

    if (!passageiro) {
        cout << "Passageiro não encontrado." << endl;
        system("pause");
        return;
    }

    if (voo->getLotacao() >= voo->getAeronave()->getCapacidade()) {
        cout << "Capacidade máxima atingida para o voo " << codigoVoo << endl;
        system("pause");
        return;
    }

    voo->adicionarPassageiro(passageiro);
    voo->setLotacao(voo->getLotacao() + 1);
    passageiro->setNumvoo(codigoVoo);
    cout << "Passageiro embarcado com sucesso no voo " << codigoVoo << endl;
    system("pause");

}

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

void Sistema::salvarEmArquivo(const string& nomeArquivo, const vector<Piloto*>& pilotos,const vector<Passageiro*>& passageiros) {
    ofstream arquivo(nomeArquivo, ios::out); // Abre o arquivo em modo append

    // Escreve os dados dos pilotos e passageiros no arquivo
    for (const auto& piloto : pilotos) {

        arquivo << piloto->serializar() << "\n";
    }

    for (const auto& passageiro : passageiros) {
        arquivo << passageiro->serializar() << "\n";
    }

    arquivo.close();
}

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

