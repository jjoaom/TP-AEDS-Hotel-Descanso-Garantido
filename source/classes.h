#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include "data.h"

//Operador ternario: condição ? valor_se_verdadeiro : valor_se_falso


// Struct para Data
class Data
{
public:
  int ano;
  int mes;
  int dia;

  Data(int ano = 0, int mes = 0, int dia = 0) : ano(ano), mes(mes), dia(dia) {}
  void readData(){
    char barra;
    std::cout << "Insira a data: ";
    std::cin >> dia >> barra >> mes >> barra >> ano;
  }
  void printData(){
  //o operador ternario verifica se o numero é menor que 10 pra imprimir um zero antes dele
    std::cout << (dia < 10 ? "0" : "") << dia << "/" << (mes < 10 ? "0" : "") <<  mes << "/" << ano << std::endl;
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
  

  endereco(std::string c = "", std::string r = "", std::string b = "", std::string c = "", std::string e = "", int num = 0) : rua(r), bairro(b), cidade(c), estado(e), numero(num) {}
  void createEndereco(){

    //necessário adicionar a lógica para tratar o cep corretamente
    std::cout << "Digite o cep: ";
    std::getline(std::cin,cep); 
    while(cep.size() != 8){
      std::cout << "CEP inválido. Digite novamente: ";
      std::cin >> cep;
    }

    limparBuffer();
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
  void readEndereco(){
    std::cout << "R. " << rua << numero << "-" << bairro << "," << cidade << "-" << estado << "," << cep;
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
  std::string telCliente;

public:
  cliente(int id = 0, std::string nome = "", std::string end = "", std::string tel = "", int pontos = 0)
      : idCliente(id), nomeCliente(nome), endereco.Endereco(end), telCliente(tel), pontosFidelidade(pontos) {}

  void createClient(){
    clientes[idCliente].idCliente = idCliente;
    std::cout << "ID: " << idCliente;

    std::cout << "Digite o nome do cliente: ";
    std::getline(std::cin, nomeCliente);

    //necessario corrigir a herança de Endereço
    std::cout << "Digite o endereço do cliente: ";
    std::getline(std::cin, endereco.Endereco);

    std::cout << "Digite o telefone do cliente: ";
    std::getline(std::cin, telCliente);

    
  }
  void readClient(){
    std::cout << "ID Cliente: " << idCliente;
    std::cout << "Nome" << nomeCliente;
    //corrigir herança endereço
    readEndereco();
    //acredito que seria interessante criar um tipo para o telefone ou alguma lógica para imprimir com código de país e de área
    std::cout << "Telefone: " << telCliente;
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
  std::string telFuncionario;
  float salario;

public:
  funcionario(int id = 0, std::string nome = "", int c = 0, std::string tel = "", float sal = 0.0) : idFuncionario(id), nomeFuncionario(nome), cargo(c), telFuncionario(tel), salario(sal) {}
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
    std::getline(std::cin, funcionarios[idFuncionario].telFuncionario);

    std::cout << "Qual o salário do funcionário: ";
    std::cin >> funcionarios[idFuncionario].salario;
  }
  void readFuncionario(){
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
    std::cout << "Telefone:" << telFuncionario;
    std::cout << "Remuneração: R$" << salario;
  }
};

// Struct para estadias
class estadia
{
public:
  int idEstadia;
  Data dataEntrada;
  Data dataSaida;
  int qntDiarias;
  int idCliente;
  int numQuarto;
  estadia(int id = 0, Data entrada = Data(), Data saida = Data(), int diarias = 0, int cliente = 0, int quarto = 0) : idEstadia(id), dataEntrada(entrada), dataSaida(saida), qntDiarias(diarias), idCliente(cliente), numQuarto(quarto) {}
  void cadastrarEstadia();
};

// Struct para quartos
class quarto
{
  public:
  int numQuarto;
  int qtdHospedes;
  float valorDiaria;
  bool status;
  quarto(int num = 0, int hospede = 0, float diaria = 0.0, bool quartoVago = false): numQuarto(num),qtdHospedes(hospede),valorDiaria(diaria),status(quartoVago) {}
};

#endif /* CLASSES_H*/