#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include "data.h"

// Struct para Data
class Data
{
public:
  int ano;
  int mes;
  int dia;

  Data(int ano = 0, int mes = 0, int dia = 0) : ano(ano), mes(mes), dia(dia) {}
};

// Enum para cargos
enum Cargo
{
  DESVINCULADO,
  RECEPCIONISTA,
  AUXILIAR_DE_LIMPEZA,
  GARCOM,
  GERENTE
};

// Struct para clientes
class cliente
{
public:
  int idCliente;
  std::string nomeCliente;
  int pontosFidelidade;

private:
  std::string endereco;
  std::string telCliente;

public:

  cadastrarCliente();
  pesquisarCliente();
  cliente(int id = 0, std::string nome = "", std::string end = "", std::string tel = "", int pontos = 0)
      : idCliente(id), nomeCliente(nome), endereco(end), telCliente(tel), pontosFidelidade(pontos) {}
};



// Struct para endereço

class endereco
{
public:
  std::string rua;
  std::string bairro;
  std::string cidade;
  std::string estado;
  int numero;
  int cep;

  endereco(std::string r = "", std::string b = "", std::string c = "", std::string e = "", int num = 0, int Cep = 0) : rua(r), bairro(b), cidade(c), estado(e), numero(num), cep(Cep) {}
};

// Struct para funcionarios
class funcionario
{
public:
  int idFuncionario;
  std::string nomeFuncionario;
  Cargo cargo;

private:
  std::string telFuncionario;
  float salario;

public: 
  funcionario(int id = 0, std::string nome = "", Cargo c = DESVINCULADO, std::string tel = "", float sal = 0.0) : idFuncionario(id), nomeFuncionario(nome), cargo(c), telFuncionario(tel), salario(sal) {}
  void cadastrarFuncionario();
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