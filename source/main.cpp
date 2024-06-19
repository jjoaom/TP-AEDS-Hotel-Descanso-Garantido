/*
Trabalho Prático - AEDS 1

Professor: Ivan Luiz Vieira de Araújo
Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

*/
//biblioteca com classes
#include "classes.h"

#include <locale>
#include <clocale>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <string>


void limparBuffer()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void verificaArquivo(FILE *arquivo)
{
  if (!arquivo)
  {
    std::cout << "Erro ao abrir arquivo.\n";
    exit(1);
  }
}

int lerId(FILE *arquivo)
{
  int id;
  fseek(arquivo, 0, SEEK_SET);
  fread(&id, sizeof(id), 1, arquivo);
  return id;
}

void salvarId(FILE *arquivo, int id)
{
  fseek(arquivo, 0, SEEK_SET);
  fwrite(&id, sizeof(id), 1, arquivo);
}

void iniciateFiles(const char nomeArquivo)
{
  FILE *arq = fopen(nomeArquivo, "rb+");
  if (!arq)
  {
    arq = fopen(nomeArquivo, "wb+");
    verificaArquivo(arq);
    int id = 0;
    fwrite(&id, sizeof(id), 1, arq);
  }
  fclose(arq);
}

void cadastrarCliente()
{
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb+");
  verificaArquivo(arqCliente);

  int id = lerId(arqCliente);

  cliente clientes[MAX_CLIENTES];

  int status = 1;
  while (status)
  {
    clientes[id].idCliente = id;
    std::cout << "ID: " << clientes[id].idCliente << "\n";
    std::cout << "Digite o nome do cliente: ";
    limparBuffer();
    std::getline(std::cin, clientes[id].nomeCliente, 50);

    std::cout << "Digite o endereço do cliente: ";
    std::getline(std::cin, clientes[id].endereco, 100);

    std::cout << "Digite o telefone do cliente: ";
    std::getline(std::cin, clientes[id].telCliente);

    clientes[id].pontosFidelidade = 0;

    fseek(arqCliente, sizeof(id) + id * sizeof(cliente), SEEK_SET);
    fwrite(&clientes[id], sizeof(cliente), 1, arqCliente);
    id++;
    salvarId(arqCliente, id);

    std::cout << "Você quer registrar outro cliente?\n";
    std::cout << "1 - Sim\n";
    std::cout << "0 - Não\n";
    std::cin >> status;
  }

  fclose(arqCliente);
}

void cadastrarFuncionario()
{
  FILE *arqFuncionario;
  arqFuncionario =
      fopen("Funcionarios.dat", "rb+");
  verificaArquivo(arqFuncionario);

  int id = lerId(arqFuncionario);

  funcionario funcionarios[MAX_FUNCIONARIOS];

  int status = 1;
  while (status)
  {
    funcionarios[id].idFuncionario = id;
    std::cout << "ID: %d\n", funcionarios[id].idFuncionario;
    std::cout << "Digite o nome do funcionário: ";
    limparBuffer();
    std::getline(std::cin, funcionarios[id].nomeFuncionario);

    int cargo;
    std::cout << "Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n";
    std::cin >> cargo;
    limparBuffer();
    while (cargo < DESVINCULADO || cargo > GERENTE)
    {
      std::cout << "Opção inválida. Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n";
      std::cin >> cargo;
      limparBuffer();
    }
    funcionarios[id].cargo = cargo;
    std::cout << "Digite o telefone do funcionário: ";
    std::getline(std::cin, funcionarios[id].telFuncionario);

    std::cout << "Qual o salário do funcionário: ";
    std::cin >> funcionarios[id].salario;

    fseek(arqFuncionario, sizeof(id) + id * sizeof(funcionario), SEEK_SET);
    fwrite(&funcionarios[id], sizeof(funcionario), 1, arqFuncionario);
    id++;
    salvarId(arqFuncionario, id);

    std::cout << "Você quer registrar outro cliente?\n";
    std::cout << "1 - Sim\n";
    std::cout << "0 - Não\n";
    std::cin >> status;
  }

  fclose(arqFuncionario);
}

void cadastrarEstadia()
{
  FILE *arqEstadia;
  arqEstadia = fopen("Estadia.dat", "rb+");
  verificaArquivo(arqEstadia);

  int id = lerId(arqEstadia);

  estadia estadias[MAX_ESTADIAS];

  estadias[id].idEstadia = id;
  std::cout << "ID: %d\n", estadias[id].idEstadia;
  std::cout << "Digite a data de entrada do cliente: ";
  std::cin >> estadias[id].dataEntrada.dia >>
      estadias[id].dataEntrada.mes >> estadias[id].dataEntrada.ano;
  std::cout << "Digite a data de saída do cliente: ";
  std::cin >> estadias[id].dataSaida.dia >> estadias[id].dataSaida.mes >> estadias[id].dataSaida.ano;
  std::cout << "Digite a quantidade de diárias do cliente: ";
  std::cin >> estadias[id].qntDiarias;
  std::cout << "Digite o ID do cliente: ";
  std::cin >> estadias[id].idCliente;
  std::cout << "Digite o número do quarto: ";
  std::cin >> estadias[id].numQuarto;

  fseek(arqEstadia, sizeof(id) + id * sizeof(estadia), SEEK_SET);
  fwrite(&estadias[id], sizeof(estadia), 1, arqEstadia);
  id++;
  salvarId(arqEstadia, id);

  fclose(arqEstadia);
}

void baixaEstadia()
{
  FILE *arqEstadia;
  arqEstadia = fopen("Estadia.dat", "rb+"); // rb+ para editar arquivo
  verificaArquivo(arqEstadia);
}

void pesquisarCliente(cliente clientes[])
{
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqCliente);

  int opcao;
  bool validOption = false;
  while (!validOption)
  {
    std::cout << "Pesquisar Cliente:\n";
    std::cout << "1-Pesquisar por ID:\n";
    std::cout << "2-Pesquisar por nome:\n";

    std::cin >> opcao;
    limparBuffer();
    switch (opcao)
    {
    case 1:
      validOption = true;
      break;
    case 2:
      validOption = true;
      break;
    default:
      std::cout << "Opção incorreta. Tente novamente.\n";
      break;
    }
  }
}

void pesquisarFuncionario(funcionario funcionarios[])
{
  FILE *arqFuncionario;
  arqFuncionario = fopen("Funcionarios.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqFuncionario);

  int opcao;
  std::cout << "Pesquisar Funcionário:\n";
  std::cout << "1-Pesquisar por ID:\n";
  std::cout << "2-Pesquisar por nome:\n";
  std::cout << "3-Pesquisar por cargo:\n";

  std::cin >> opcao;
  limparBuffer();
  switch (opcao)
  {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    std::cout << "Opção incorreta.\n";
    break;
  }
}

void mostrarEstadiasCliente()
{
  FILE *arqCliente, *arqEstadia;
  arqCliente = fopen("Clientes.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqCliente);
  arqEstadia = fopen("Estadia.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqEstadia);
}

void calcularPontosFidelidade()
{
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb");
  verificaArquivo(arqCliente);
}

void menu()
{

  cliente clientes[MAX_CLIENTES];
  funcionario funcionarios[MAX_FUNCIONARIOS];
  quarto quartos[MAX_QUARTOS];
  estadia estadias[MAX_ESTADIAS];
  int opcao;

  iniciateFiles("Clientes.dat");
  iniciateFiles("Funcionarios.dat");
  iniciateFiles("Estadias.dat");

  do
  {
    std::cout << "========================================\n";
    std::cout << "            SISTEMA DE HOTEL            \n";
    std::cout << "========================================\n";
    std::cout << "1.  Cadastrar Cliente\n";
    std::cout << "2.  Cadastrar Funcionario\n";
    std::cout << "3.  Cadastrar Estadia\n";
    std::cout << "4.  Dar baixa em Estadia\n";
    std::cout << "5.  Pesquisar Cliente\n";
    std::cout << "6.  Pesquisar Funcionario\n";
    std::cout << "7.  Mostrar todas as estadias de um Cliente\n";
    std::cout << "8.  Calcular pontos de fidelidade de um Cliente\n";
    std::cout << "9.  Sair\n";
    std::cout << "========================================\n";
    std::cout <<"Escolha uma opcao: ";
    std::cin  >> opcao;
    limparBuffer();

    switch (opcao)
    {
    case 1:
      cadastrarCliente();
      break;
    case 2:
      cadastrarFuncionario();
      break;
    case 3:
      cadastrarEstadia();
      break;
    case 4:
      baixaEstadia();
      break;
    case 5:
      pesquisarCliente();
      break;
    case 6:
      pesquisarFuncionario();
      break;
    case 7:
      mostrarEstadiasCliente();
      break;
    case 8:
      calcularPontosFidelidade();
      break;
    case 9:
      std::cout << "Saindo do programa...\n";
      std::cout << "Programa criado por João Marcos e João Victor.";
      break;
    default:
      std::cout << "Opcao invalida! Tente novamente.\n";
      getchar(); // Limpa o buffer
      getchar(); // Espera um enter para continuar
    }
  } while (opcao != 9);
}

int main()
{
  std::setlocale(LC_ALL, "Portuguese_Brazil.1252");
  const int MAX_CLIENTES = 100;
  const int MAX_FUNCIONARIOS = 50;
  const int MAX_QUARTOS = 15;
  const int MAX_ESTADIAS = 300;
  const int MAX_STRING = 256;

  menu();
  return 0;
}