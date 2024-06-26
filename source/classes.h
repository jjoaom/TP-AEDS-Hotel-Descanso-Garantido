#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

// Limpar buffer de entrada
void limparBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Função para ler o ultimo ID do arquivo
int pegarID(const string &filename)
{
    int ultimoId = 0;
    ifstream arquivo(filename);
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream iss(linha);
            int id;
            iss >> id;
            ultimoId = id;
        }
        arquivo.close();
    }
    return ultimoId;
}

// Classe para Endereço
class Endereco
{
public:
    string cep;
    string rua;
    string bairro;
    string cidade;
    string estado;
    int numero;

    Endereco(string cep = "", string r = "", string b = "", string city = "", string e = "", int num = 0)
        : cep(cep), rua(r), bairro(b), cidade(city), estado(e), numero(num) {}
    //Função responsável por pegar o endereço
    void createEndereco()
    {
        cout << "Digite o CEP: (apenas números): ";
        getline(cin, cep);

        while (cep.size() != 8 || !all_of(cep.begin(), cep.end(), ::isdigit))
        {
            cout << "CEP inválido. Digite novamente (apenas números): ";
            getline(cin, cep);
        }

        cout << "Insira a rua: ";
        getline(cin, rua);
        cout << "Insira o bairro: ";
        getline(cin, bairro);
        cout << "Insira a cidade: ";
        getline(cin, cidade);
        cout << "Insira o estado: ";
        getline(cin, estado);
        cout << "Nº da casa/apartamento: ";
        cin >> numero;
        limparBuffer();
    }
    //Leitura de endereço - função constante
    void readEndereco() const
    {
        cout << "Rua: " << rua << ", Número: " << numero << endl;
        cout << "Bairro: " << bairro << endl;
        cout << "Cidade: " << cidade << ", Estado: " << estado << endl;
        cout << "CEP: " << cep << endl;
    }
};

// Classe para Telefone
class Telefone
{
private:
    string pais;
    string ddd;
    string numero;

public:
    //Recebe o telefone
    void createTelefone()
    {
        cout << "Digite o código do país: ";
        getline(cin, pais);
        cout << "Digite o DDD: ";
        getline(cin, ddd);
        cout << "Digite o número: ";
        getline(cin, numero);
    }
    //leitura do número
    void readTelefone() const
    {
        cout << "+" << pais << " (" << ddd << ") " << numero << endl;
    }

    string getPais() const
    {
        return pais;
    }

    string getDDD() const
    {
        return ddd;
    }

    string getNumero() const
    {
        return numero;
    }
    void setTelefone(const string &p, const string &d, const string &n)
    {
        pais = p;
        ddd = d;
        numero = n;
    }
};

class Cliente
{
public:
    int idCliente;
    string nomeCliente;
    int pontosFidelidade;

private:
    Endereco endereco;
    Telefone telefone;

public:
    Cliente(int id = 0, string nome = "", Endereco end = Endereco(), Telefone tel = Telefone(), int pontos = 0)
        : idCliente(id), nomeCliente(nome), endereco(end), telefone(tel), pontosFidelidade(pontos) {}
    //Pega dados do cliente
    void createClient()
    {
        cout << "ID: " << idCliente << endl;
        cout << "Digite o nome do cliente: ";
        getline(cin, nomeCliente);
        if (nomeCliente.empty())
        {
            cerr << "Erro: nome do cliente não pode ser vazio!" << endl;
            return;
        }
        cout << "Digite o endereço do cliente: ";
        endereco.createEndereco();
        cout << "Digite o telefone do cliente: ";
        telefone.createTelefone();
    }
    //Leitura de cliente
    string readClient() const
    {
        //permite que uma classe seja operada por string
        ostringstream oss;
        oss << "ID Cliente: " << idCliente << "\n";
        oss << "Nome: " << nomeCliente << "\n";
        oss << "Endereço: " << endereco.rua << ", " << endereco.numero << ", " << endereco.bairro << ", " << endereco.cidade << ", " << endereco.estado << ", " << endereco.cep << "\n";
        oss << "Telefone: +" << telefone.getPais() << " (" << telefone.getDDD() << ") " << telefone.getNumero() << "\n";
        oss << "Total de pontos de fidelidade: " << pontosFidelidade << "\n";
        return oss.str();
    }
    //função constante para imprimir cliente
    void printClient() const
    {
        cout << readClient() << endl;
    }
    //constante pra retornar endereço privado
    const Endereco &getEndereco() const
    {
        return endereco;
    }

    void setEndereco(const Endereco &end)
    {
        endereco = end;
    }

    const Telefone &getTelefone() const
    {
        return telefone;
    }

    void setTelefone(const Telefone &tel)
    {
        telefone = tel;
    }
};

vector<Cliente> clientes;

// Função para carregar clientes do arquivo
void carregarClientes()
{
    ifstream arquivoCliente("Clientes.txt");
    if (arquivoCliente.is_open())
    {
        string linha;
        while (getline(arquivoCliente, linha))
        {
            istringstream iss(linha);
            Cliente c;
            string enderecoRua, enderecoBairro, enderecoCidade, enderecoEstado;
            string telPais, telDDD, telNumero;
            Endereco end;
            Telefone tel;

            iss >> c.idCliente >> c.nomeCliente >> end.cep >> enderecoRua >> enderecoBairro >> enderecoCidade >> enderecoEstado >> end.numero >> telPais >> telDDD >> telNumero >> c.pontosFidelidade;
            end.rua = enderecoRua;
            end.bairro = enderecoBairro;
            end.cidade = enderecoCidade;
            end.estado = enderecoEstado;
            tel.setTelefone(telPais, telDDD, telNumero);
            c.setEndereco(end);
            c.setTelefone(tel);
            clientes.push_back(c);
        }
        arquivoCliente.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo Clientes.txt\n";
    }
}

void cadastrarCliente()
{
    int ultimoId = pegarID("Clientes.txt"); // Itera o arquivo e busca o ultimo id
    Cliente novoCliente;
    novoCliente.idCliente = ultimoId + 1; // define o novo id a ser osado
    novoCliente.createClient();
    //declaração de arquivo para adicionar
    ofstream arquivoCliente("Clientes.txt", ios_base::app);
    if (arquivoCliente.is_open())
    {   
        //le o cliente e insere no arquivo
        arquivoCliente << novoCliente.readClient();
        arquivoCliente << ",\n";
        arquivoCliente.close();
        cout << "Cliente registrado com sucesso!\n";
    }
    else
    {
        cerr << "Erro ao abrir o arquivo Clientes.txt\n";
    }

    clientes.push_back(novoCliente);
}
//Pesquisa dentro do arquivo se tem um cliente com o ID ou NOME correspondente
void pesquisarCliente()
{
    int opcao;
    cout << "Pesquisar Cliente:" << endl;
    cout << "1 - Pesquisar por ID:" << endl;
    cout << "2 - Pesquisar por nome:" << endl;
    cin >> opcao;
    limparBuffer();

    if (opcao == 1)
    {
        int idBusca;
        cout << "Digite o ID do cliente que deseja pesquisar: ";
        cin >> idBusca;

        bool idCEncontrado = false;
        for (const auto &cli : clientes)
        {
            if (cli.idCliente == idBusca)
            {
                cli.printClient();
                idCEncontrado = true;
                break;
            }
        }

        if (!idCEncontrado)
        {
            cout << "Cliente não encontrado.\n";
        }
    }
    else if (opcao == 2)
    {
        string nome;
        cout << "Digite o nome do cliente que deseja pesquisar: ";
        getline(cin, nome);

        bool nomeCEncontrado = false;
        for (const auto &cli : clientes)
        {
            if (cli.nomeCliente == nome)
            {
                cli.printClient();
                nomeCEncontrado = true;
                break;
            }
        }

        if (!nomeCEncontrado)
        {
            cout << "Cliente não encontrado.\n";
        }
    }
    else
    {
        cout << "Opção inválida.\n";
    }
}
//Função busca com o ID do cliente e calcula seus pontos de fidelidade
void calcularPontosFidelidade()
{
    int idCliente;
    bool encontrado = false;

    std::cout << "Digite o ID do cliente para calcular os pontos de fidelidade: ";
    std::cin >> idCliente;
    limparBuffer(); // Limpar o buffer após a leitura de entrada

    for (auto &cliente : clientes)
    {
        if (cliente.idCliente == idCliente)
        {
            cliente.pontosFidelidade += 10; // Exemplo: adiciona 10 pontos para cada cliente encontrado com o ID fornecido
            encontrado = true;
            break;
        }
    }

    if (encontrado)
    {
        std::cout << "Pontos de fidelidade calculados e adicionados ao cliente com ID " << idCliente << "." << std::endl;
    }
    else
    {
        std::cout << "Cliente com ID " << idCliente << " não encontrado. Nenhum ponto de fidelidade foi adicionado." << std::endl;
    }
}

class Funcionario
{
public:
    int idFuncionario;
    string nomeFuncionario;
    string cargo;
    float salario;

    Funcionario(int id = 0, string nome = "", string c = "", float s = 0.0)
        : idFuncionario(id), nomeFuncionario(nome), cargo(c), salario(s) {}

    void createFuncionario()
    {
        cout << "Digite o nome do funcionário: ";
        getline(cin, nomeFuncionario);
        cout << "Digite o cargo do funcionário: (Recepcionista,Auxiliar de limpeza,Garçom,Gerente)";
        getline(cin, cargo);
        cout << "Digite o salário do funcionário: ";
        cin >> salario;
        limparBuffer();
    }

    void printFuncionario() const
    {
        cout << "ID Funcionário: " << idFuncionario << "\n";
        cout << "Nome: " << nomeFuncionario << "\n";
        cout << "Cargo: " << cargo << "\n";
        cout << "Salário: " << salario << "\n";
    }
};

vector<Funcionario> funcionarios;

// Função para carregar funcionários do arquivo
void carregarFuncionarios()
{
    ifstream arquivoFuncionario("Funcionarios.txt");
    if (arquivoFuncionario.is_open())
    {
        string linha;
        while (getline(arquivoFuncionario, linha))
        {
            istringstream iss(linha);
            Funcionario f;
            iss >> f.idFuncionario >> f.nomeFuncionario >> f.cargo >> f.salario;
            funcionarios.push_back(f);
        }
        arquivoFuncionario.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo Funcionarios.txt\n";
    }
}
//Recebe o ultimoID do arquivo de funcionario e cria um novo funcionario no final dele
void cadastrarFuncionario()
{
    Funcionario novoFuncionario;
    int ultimoId = pegarID("Funcionarios.txt"); // Get the last ID from the file
    novoFuncionario.idFuncionario = ultimoId + 1; // Set the new ID
    novoFuncionario.createFuncionario();

    ofstream arquivoFuncionario("Funcionarios.txt", ios_base::app);
    if (arquivoFuncionario.is_open())
    {
        arquivoFuncionario << novoFuncionario.idFuncionario << " " << novoFuncionario.nomeFuncionario << " "
                           << novoFuncionario.cargo << " " << novoFuncionario.salario << "\n";
        arquivoFuncionario.close();
        cout << "Funcionário registrado com sucesso!\n";
    }
    else
    {
        cerr << "Erro ao abrir o arquivo Funcionarios.txt\n";
    }

    funcionarios.push_back(novoFuncionario);
}
//Pesquisa funcionario no arquivo de acordo com ID e nome
void pesquisarFuncionario()
{
    int opcao;
    cout << "Pesquisar Funcionario:" << endl;
    cout << "1 - Pesquisar por ID:" << endl;
    cout << "2 - Pesquisar por nome:" << endl;
    cin >> opcao;
    limparBuffer();

    if (opcao == 1)
    {
        int idBusca;
        cout << "Digite o ID do funcionário que deseja pesquisar: ";
        cin >> idBusca;

        bool idFEncontrado = false;
        for (const auto &func : funcionarios)
        {
            if (func.idFuncionario == idBusca)
            {
                func.printFuncionario();
                idFEncontrado = true;
                break;
            }
        }

        if (!idFEncontrado)
        {
            cout << "Funcionário não encontrado.\n";
        }
    }
    else if (opcao == 2)
    {
        string nome;
        cout << "Digite o nome do funcionário que deseja pesquisar: ";
        getline(cin, nome);

        bool nomeFEncontrado = false;
        for (const auto &func : funcionarios)
        {
            if (func.nomeFuncionario == nome)
            {
                func.printFuncionario();
                nomeFEncontrado = true;
                break;
            }
        }

        if (!nomeFEncontrado)
        {
            cout << "Funcionário não encontrado.\n";
        }
    }
    else
    {
        cout << "Opção inválida.\n";
    }
}

class Estadia
{
public:
    int idEstadia;
    int idCliente;
    int idQuarto;
    string dataCheckin;
    string dataCheckout;

    Estadia(int idE = 0, int idC = 0, int idQ = 0, string checkin = "", string checkout = "")
        : idEstadia(idE), idCliente(idC), idQuarto(idQ), dataCheckin(checkin), dataCheckout(checkout) {}

    void createEstadia()
    {
        cout << "Digite o ID do cliente: ";
        cin >> idCliente;
        cout << "Digite o ID do quarto: ";
        cin >> idQuarto;
        limparBuffer();
        cout << "Digite a data de check-in (DD/MM/AAAA): ";
        getline(cin, dataCheckin);
        cout << "Digite a data de check-out (DD/MM/AAAA): ";
        getline(cin, dataCheckout);
    }

    void printEstadia() const
    {
        cout << "ID Estadia: " << idEstadia << "\n";
        cout << "ID Cliente: " << idCliente << "\n";
        cout << "ID Quarto: " << idQuarto << "\n";
        cout << "Data Check-in: " << dataCheckin << "\n";
        cout << "Data Check-out: " << dataCheckout << "\n";
    }
};

vector<Estadia> estadias;


// Declaração das classes
class Quarto {
public:
    int idQuarto;
    string tipoQuarto;
    float valorDiaria;
    bool ocupado;

    Quarto(int id = 0, string tipo = "", float valor = 0.0, bool oc = false)
        : idQuarto(id), tipoQuarto(tipo), valorDiaria(valor), ocupado(oc) {}
};

// Função para carregar estadias do arquivo
void carregarEstadias()
{
    ifstream arquivoEstadia("Estadias.txt");
    if (arquivoEstadia.is_open())
    {
        string linha;
        while (getline(arquivoEstadia, linha))
        {
            istringstream iss(linha);
            Estadia e;
            iss >> e.idEstadia >> e.idCliente >> e.idQuarto >> e.dataCheckin >> e.dataCheckout;
            estadias.push_back(e);
        }
        arquivoEstadia.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo Estadias.txt\n";
    }
}


vector<Quarto> quartos; // Definição do vetor quartos

// Função para carregar quartos do arquivo
void carregarQuartos() {
    ifstream arquivoQuarto("Quartos.txt");
    if (arquivoQuarto.is_open()) {
        string linha;
        while (getline(arquivoQuarto, linha)) {
            istringstream iss(linha);
            Quarto q;
            iss >> q.idQuarto >> q.tipoQuarto >> q.valorDiaria >> q.ocupado;
            quartos.push_back(q);
        }
        arquivoQuarto.close();
    } else {
        cerr << "Erro ao abrir o arquivo Quartos.txt\n";
    }
}

// Função para atualizar o arquivo de quartos
void atualizarArquivoQuartos() {
    ofstream arquivoQuarto("Quartos.txt");
    if (arquivoQuarto.is_open()) {
        for (const auto &q : quartos) {
            arquivoQuarto << q.idQuarto << " " << q.tipoQuarto << " " << q.valorDiaria << " " << q.ocupado << "\n";
        }
        arquivoQuarto.close();
    } else {
        cerr << "Erro ao abrir o arquivo Quartos.txt\n";
    }
}

// Função para cadastrar uma estadia
void cadastrarEstadia() {
    // Exibir quartos disponíveis
    cout << "Quartos Disponíveis:\n";
    for (const auto &quarto : quartos) {
        if (!quarto.ocupado) {
            cout << "ID: " << quarto.idQuarto << ", Tipo: " << quarto.tipoQuarto << ", Valor Diária: " << quarto.valorDiaria << "\n";
        }
    }

    // Selecionar um quarto
    int idQuarto;
    cout << "\nDigite o ID do quarto desejado para a estadia: ";
    cin >> idQuarto;
    cin.ignore(); // Limpar o buffer do teclado

    // Verificar se o quarto está disponível
    auto it = find_if(quartos.begin(), quartos.end(), [idQuarto](const Quarto &q) {
        return q.idQuarto == idQuarto && !q.ocupado;
    });

    if (it != quartos.end()) {
        Estadia novaEstadia;
        int ultimoId = pegarID("Estadias.txt"); // Supondo que pegarID esteja implementada corretamente
        novaEstadia.idEstadia = ultimoId + 1; // Set the new ID
        novaEstadia.idQuarto = idQuarto;
        novaEstadia.createEstadia(); // Implementação para criar uma estadia

        ofstream arquivoEstadia("Estadias.txt", ios_base::app);
        if (arquivoEstadia.is_open()) {
            arquivoEstadia << novaEstadia.idEstadia << " " << novaEstadia.idCliente << " "
                           << novaEstadia.idQuarto << " " << novaEstadia.dataCheckin << " " << novaEstadia.dataCheckout << "\n";
            arquivoEstadia.close();
            cout << "Estadia registrada com sucesso!\n";
        } else {
            cerr << "Erro ao abrir o arquivo Estadias.txt\n";
        }

        // Atualizar status de ocupação do quarto no vetor e no arquivo
        it->ocupado = true;
        atualizarArquivoQuartos();

        estadias.push_back(novaEstadia);
    } else {
        cout << "Quarto selecionado não está disponível ou não existe.\n";
    }
}

// Função para dar baixa em uma estadia
void baixaEstadia() {
    int idEstadia;
    cout << "Digite o ID da estadia que deseja dar baixa: ";
    cin >> idEstadia;
    cin.ignore(); // Limpar o buffer do teclado

    auto it = find_if(estadias.begin(), estadias.end(), [idEstadia](const Estadia &e) {
        return e.idEstadia == idEstadia;
    });

    if (it != estadias.end()) {
        estadias.erase(it);
        cout << "Estadia com ID " << idEstadia << " foi dada baixa com sucesso.\n";

        ofstream arquivoEstadia("Estadias.txt");
        if (arquivoEstadia.is_open()) {
            for (const auto &e : estadias) {
                arquivoEstadia << e.idEstadia << " " << e.idCliente << " "
                               << e.idQuarto << " " << e.dataCheckin << " " << e.dataCheckout << "\n";
            }
            arquivoEstadia.close();
        } else {
            cerr << "Erro ao abrir o arquivo Estadias.txt\n";
        }
    } else {
        cout << "Estadia não encontrada.\n";
    }
}

// Função para mostrar todas as estadias de um cliente
void mostrarEstadiasCliente() {
    int idCliente;
    cout << "Digite o ID do cliente: ";
    cin >> idCliente;
    cin.ignore(); // Limpar o buffer do teclado

    bool estadiaEncontrada = false;
    for (const auto &e : estadias) {
        if (e.idCliente == idCliente) {
            e.printEstadia(); // Implementação para imprimir os detalhes da estadia
            estadiaEncontrada = true;
        }
    }

    if (!estadiaEncontrada) {
        cout << "Nenhuma estadia encontrada para o cliente com ID " << idCliente << ".\n";
    }
}