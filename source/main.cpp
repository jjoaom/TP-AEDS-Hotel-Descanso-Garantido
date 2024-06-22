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


  const int MAX_CLIENTES = 100;
  cliente clientes[MAX_CLIENTES];

  const int MAX_FUNCIONARIOS = 50;
  funcionario funcionarios[MAX_FUNCIONARIOS];

  const int MAX_QUARTOS = 15;
  quarto quartos[MAX_QUARTOS];

  const int MAX_ESTADIAS = 300;
  estadia estadias[MAX_ESTADIAS];

  const int MAX_STRING = 256;

//seekp para ir a posição do arquivo antes de escrever
//seekg para ir a posição do arquivo antes de ler

//Limpar buffer de entrada
void limparBuffer()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//Função que verifica se o arquivo foi aberto com sucesso
void verificaArquivo(std::fstream arquivo)
{
  //função is_open semelhante a fopen do C
  if (!arquivo.is_open())
  {
    //tipo cerr é utilizado para retornar erros
    //endl é usado para quebra de linha, como \n
    std::cerr << "Erro ao abrir arquivo." << std::endl ;
    exit(1);
  }
}

//Função responsável por fazer a leitura do id no inicio do arquivo
//fstream permite o read e write no arquivo
int lerId(std::fstream &arquivo)
{
  int id;
  //seekg serve para buscar a posição dentro do arquivo
  //::beg indica o inicio do texto
  arquivo.seekg(0,std::ios::beg);
  //leitura e retorno do arquivo
  arquivo.read(reinterpret_cast<char*>(&id),sizeof(id));
  return id;
}

//Função responsável por salvar o id atualizado dentro do arquivo binario
//recebe arquivo e variavel do id
void salvarId(std::fstream &arquivo, int id)
{
  //acessa o inicio do arquivo e atualiza o id
  arquivo.seekp(0,std::ios::beg);
  arquivo.write(reinterpret_cast<const char*>(&id), sizeof(id));
}


//Função responsável por verificar se o arquivo está criado e caso não esteja 
//criado gera o arquivo com a linha de id no inicio
void iniciateFiles(const std::string nomeArquivo)
{
  std::fstream arq;
  arq.open(nomeArquivo,std::ios::binary);
  if (!arq)
  {
    arq.open(nomeArquivo,std::ios::in);
    
    int id = 0;
    arq.write(reinterpret_cast<char*>(&id),sizeof(id));
  }
  arq.close();
}
//Função cadastro de cliente
//Verificar possibilidade de inserir a função dentro da CLASSE Cliente
void cadastrarCliente()
{
  std::fstream arqCliente;
  arqCliente.open("Clientes.dat",std::ios::app);
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
    std::getline(std::cin, clientes[id].nomeCliente);

    std::cout << "Digite o endereço do cliente: ";
    std::getline(std::cin, clientes[id].endereco);

    std::cout << "Digite o telefone do cliente: ";
    std::getline(std::cin, clientes[id].telCliente);

    clientes[id].pontosFidelidade = 0;
    arqCliente.fseek(arqCliente, sizeof(id) + id * sizeof(cliente), SEEK_SET);
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

  int opcao;

  iniciateFiles("Clientes.dat");
  iniciateFiles("Funcionarios.dat");
  iniciateFiles("Estadias.dat");

  do
  {
    std::cout << "========================================" << std::endl;
    std::cout << "            SISTEMA DE HOTEL            " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1.  Cadastrar Cliente" << std::endl;
    std::cout << "2.  Cadastrar Funcionario" << std::endl;
    std::cout << "3.  Cadastrar Estadia" << std::endl;
    std::cout << "4.  Dar baixa em Estadia" << std::endl;
    std::cout << "5.  Pesquisar Cliente" << std::endl;
    std::cout << "6.  Pesquisar Funcionario" << std::endl;
    std::cout << "7.  Mostrar todas as estadias de um Cliente" << std::endl;
    std::cout << "8.  Calcular pontos de fidelidade de um Cliente" << std::endl;
    std::cout << "9.  Sair" << std::endl;
    std::cout << "========================================" << std::endl;
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
      std::cout << "Saindo do programa..." << std::endl;
      std::cout << "Programa criado por João Marcos e João Victor.";
      break;
    default:
      std::cout << "Opcao invalida! Tente novamente." << std::endl;
      getchar(); // Limpa o buffer
      getchar(); // Espera um enter para continuar
    }
  } while (opcao != 9);
}

int main()
{
  std::setlocale(LC_ALL, "Portuguese_Brazil.1252");

  menu();
  return 0;
}