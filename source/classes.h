#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>


// Limpar buffer de entrada
void limparBuffer()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Operador ternario: condição ? valor_se_verdadeiro : valor_se_falso

// Struct para Data
class Data
{
public:
  int ano;
  int mes;
  int dia;

  Data(int ano = 0, int mes = 0, int dia = 0) : ano(ano), mes(mes), dia(dia) {}
  void readData()
  {
    char barra;
    std::cout << "Insira a data: ";
    std::cin >> dia >> barra >> mes >> barra >> ano;
  }
  void printData()
  {
    // o operador ternario verifica se o numero é menor que 10 pra imprimir um zero antes dele
    std::cout << (dia < 10 ? "0" : "") << dia << "/" << (mes < 10 ? "0" : "") << mes << "/" << ano << std::endl;
  }
};

// Struct para endereço

class endereco
{
public:
  std::string cep;
  std::string rua;
  std::string bairro;
  std::string cidade;
  std::string estado;
  int numero;

  endereco(std::string cep = "", std::string r = "", std::string b = "", std::string city = "", std::string e = "", int num = 0) : cep(cep), rua(r), bairro(b), cidade(city), estado(e), numero(num) {}
  void createEndereco()
  {

    // necessário adicionar a lógica para tratar o cep corretamente
    std::cout << "Digite o cep: (apenas números)";
    std::getline(std::cin, cep);
    // enquanto cep for diferente de 8 digitos
    while (cep.size() != 8 || !std::all_of(cep.begin(), cep.end(), ::isdigit))
    {
      std::cout << "CEP inválido. Digite novamente(apenas números): ";
      std::getline(std::cin, cep);
    }

    std::cout << "Insira a rua: ";
    std::getline(std::cin, rua);
    std::cout << "Insira o bairro: ";
    std::getline(std::cin, bairro);
    std::cout << "Insira a cidade: ";
    std::getline(std::cin, cidade);
    std::cout << "Insira o estado: ";
    std::getline(std::cin, estado);
    limparBuffer();
    std::cout << "Nº da rua: ";
    std::cin >> rua;
  }
  void readEndereco()
  {
    std::cout << "R. " << rua << numero << "-" << bairro << "," << cidade << "-" << estado << "," << cep;
  }
};

// struct Telefone

class telefone
{
private:
  int cod_pais;
  int cod_area;
  int tel;

public:
  telefone(int pais = 0, int area = 0, int phone = 0) : cod_pais(pais), cod_area(area), tel(phone) {}
  void createTelefone()
  {
    std::cout << "Insira o código do país do telefone: ";
    std::cin >> cod_pais;
    std::cout << "Insira o código de área do telefone: ";
    std::cin >> cod_area;
    std::cout << "Insira o telefone: ";
    std::cin >> tel;
  }
  void readTelefone()
  {
    std::cout << "+" << cod_pais << "(" << cod_area << ")" << tel;
  }
};

// Struct para clientes
class cliente
{
public:
  int idCliente;
  std::string nomeCliente;
  int pontosFidelidade;

private:
  endereco Endereco;
  telefone telCliente;

public:
  cliente(int id = 0, std::string nome = "", endereco end = endereco(), telefone tel = telefone(), int pontos = 0)
      : idCliente(id), nomeCliente(nome), Endereco(end), telCliente(tel), pontosFidelidade(pontos) {}

  void createClient()
  {
    clientes[idCliente].idCliente = idCliente;
    std::cout << "ID: " << idCliente;

    std::cout << "Digite o nome do cliente: ";
    std::getline(std::cin, nomeCliente);

    // necessario corrigir a herança de Endereço
    std::cout << "Digite o endereço do cliente: ";
    Endereco.createEndereco();

    std::cout << "Digite o telefone do cliente: ";
    telCliente.createTelefone();
  }
  void readClient()
  {
    std::cout << "ID Cliente: " << idCliente;
    std::cout << "Nome" << nomeCliente;
    Endereco.readEndereco();
    // acredito que seria interessante criar um tipo para o telefone ou alguma lógica para imprimir com código de país e de área
    telCliente.readTelefone();
    std::cout << "Total de pontos de fidelidade: " << pontosFidelidade;
  }
  
};

// Struct para funcionarios
class funcionario
{
public:
  int idFuncionario;
  std::string nomeFuncionario;
  int cargo;

private:
  telefone telFuncionario;
  float salario;

public:
  funcionario(int id = 0, std::string nome = "", int c = 0, telefone tel = telefone(), float sal = 0.0) : idFuncionario(id), nomeFuncionario(nome), cargo(c), telFuncionario(tel), salario(sal) {}
  void createFuncionario()
  {
    funcionarios[idFuncionario].idFuncionario = idFuncionario;
    std::cout << "ID: " << idFuncionario << std::endl;

    std::cout << "Digite o nome do funcionário: ";
    std::getline(std::cin, nomeFuncionario);
    limparBuffer();
    int cargo;
    std::cout << "Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n";
    std::cin >> cargo;
    limparBuffer();
    while (cargo < 1 || cargo > 4)
    {
      std::cout << "Opção inválida. Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n";
      std::cin >> cargo;
      limparBuffer();
    }
    funcionarios[idFuncionario].cargo = cargo;

    // necessario corrigir a herança de Endereço
    std::cout << "Digite o telefone do funcionário: ";
    telFuncionario.createTelefone();

    std::cout << "Qual o salário do funcionário: ";
    std::cin >> funcionarios[idFuncionario].salario;
  }
  void readFuncionario()
  {
    std::cout << "ID Funcionário: " << idFuncionario << std::endl;
    std::cout << "Nome" << nomeFuncionario << std::endl;
    switch (cargo)
    {
    case 1:
      std::cout << "Recepcionista.";
      break;
    case 2:
      std::cout << "Auxiliar de limpeza.";
      break;
    case 3:
      std::cout << "Garçom";
      break;
    case 4:
      std::cout << "Gerente";
    default:
      break;
    }
    telFuncionario.readTelefone();
    std::cout << "Remuneração: R$" << salario;
  }
};

// Struct para quartos
class quarto
{
private:
  int numQuarto;
  int qtdHospedes;
  float valorDiaria;
  bool status;
  //status de disponibilidade do quarto
  //false = ocupado
  //true = livre

public:
  quarto(int num = 0, int hospede = 0, float diaria = 0.0, bool quartoVago = false) : numQuarto(num), qtdHospedes(hospede), valorDiaria(diaria), status(quartoVago) {}
  void quartoOcupado(){
    std::cout << "Insira o número do quarto: ";
    std::cin >> numQuarto;

    status = false;
  }
  void quartoVago(){
    std::cout << "Insira o número do quarto: ";
    std::cin >> numQuarto;

    status = true;
  }
};

// Struct para estadias
class estadia : public quarto
{
public:
  int idEstadia;
  Data dataEntrada;
  Data dataSaida;
  int qntDiarias;
  int idCliente;
  quarto quartoEstadia;
  estadia(int id = 0, Data entrada = Data(), Data saida = Data(), int diarias = 0, int cliente = 0, quarto quartoHospedado = quarto()) : idEstadia(id), dataEntrada(entrada), dataSaida(saida), qntDiarias(diarias), idCliente(cliente), quartoEstadia(quartoHospedado) {}
  void cadastrarEstadia()
  {
    std::cout << "Cadastro de Estadia";
    std::cout << "Insira a data de entrada: ";
    dataEntrada.readData();
    std::cout << "Insira a data de saida: ";
    dataSaida.readData();
    std::cout << "Quantos dias o cliente vai ficar hospedado? ";
    std::cin >> qntDiarias;
    std::cout << "Insira o id do Cliente: ";
    std::cin >> idCliente;
    
    
  }
  void lerEstadia()
  {
    std::cout << "Id: " << idEstadia;
    dataEntrada.readData();
    dataSaida.readData();
    std::cout << "Quantidade de diárias: " << qntDiarias;
    // futuramente podemos substituir um método para ler o idCliente e imprimir o nome do cliente
    std::cout << idCliente;
    
  }
  void baixarEstadia(){

  }
};



#endif /* CLASSES_H */