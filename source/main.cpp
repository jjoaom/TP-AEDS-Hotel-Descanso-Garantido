/*
Trabalho Prático - AEDS 1

Professor: Ivan Luiz Vieira de Araújo
Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

*/
// biblioteca com classes
#include "classes.h"

#include <locale>
#include <clocale>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

std::vector<cliente> clientes;
std::vector<funcionario> funcionarios;
std::vector<quarto> quartos;
std::vector<estadia> estadias;

// Função responsável por verificar se o arquivo está criado e caso não esteja
// criado gera o arquivo com a linha de id no inicio
void iniciarArquivos(const std::string &nomeArquivo)
{
  std::fstream arq;
  arq.open(nomeArquivo, std::ios::in | std::ios::binary);
  if (!arq)
  {
    arq.open(nomeArquivo, std::ios::in | std::ios::binary);
    int id = 0;
    arq.write(reinterpret_cast<char *>(&id), sizeof(id));
  }
  arq.close();
}

// Função que verifica se o arquivo foi aberto com sucesso
void verificaArquivo(std::fstream &arquivo)
{
  // função is_open semelhante a fopen do C
  if (!arquivo.is_open())
  {
    // tipo cerr é utilizado para retornar erros
    // endl é usado para quebra de linha, como 
    std::cerr << "Erro ao abrir arquivo." << std::endl;
    exit(1);
  }
}

// Função responsável por fazer a leitura do id no inicio do arquivo
// fstream permite o read e write no arquivo
int lerId(std::fstream &arquivo)
{
  int id;
  // seekg serve para buscar a posição dentro do arquivo
  //::beg indica o inicio do texto
  arquivo.seekg(0, std::ios::beg); // seekp para ir a posição do arquivo antes de escrever
  // leitura e retorno do arquivo
  arquivo.read(reinterpret_cast<char *>(&id), sizeof(id));
  return id;
}

// Função responsável por salvar o id atualizado dentro do arquivo binario
// recebe arquivo e variavel do id
void salvarId(std::fstream &arquivo, int id)
{
  // acessa o inicio do arquivo e atualiza o id
  arquivo.seekp(0, std::ios::beg); // seekg para ir a posição do arquivo antes de ler
  arquivo.write(reinterpret_cast<const char *>(&id), sizeof(id));
}

// Função cadastro de cliente
// Verificar possibilidade de inserir a função dentro da CLASSE Cliente
void cadastrarCliente(const cliente Cliente, std::string nomeArquivo)
{

  std::fstream arq("Clientes.dat", std::ios::in | std::ios::out | std::ios::binary);
  verificaArquivo(arq);
  int id = lerId(arq);

  cliente novoCliente;
  novoCliente.idCliente = id;
  novoCliente.createClient();

  arq.seekp(sizeof(id) + id * sizeof(cliente), std::ios::beg);
  arq.write(reinterpret_cast<const char *>(&novoCliente), sizeof(novoCliente));

  id++;
  salvarId(arq, id);
  arq.close();

  clientes.push_back(novoCliente);

  int status = 1;
  while (status)
  {
    std::cout << "Você quer registrar outro cliente?";
    std::cout << "1 - Sim";
    std::cout << "0 - Não";
    std::cin >> status;
    if (status == 1)
    {
      cadastrarCliente(Cliente, nomeArquivo);
    }
  }
}

void cadastrarFuncionario(const funcionario Funcionario, std::string nomeArquivo)
{
  std::fstream arq("Funcionarios.dat", std::ios::in | std::ios::out | std::ios::binary);
  verificaArquivo(arq);
  int id = lerId(arq);

  funcionario novoFuncionario;
  novoFuncionario.idFuncionario = id;
  novoFuncionario.createFuncionario();

  arq.seekp(sizeof(id) + id * sizeof(cliente), std::ios::beg);
  arq.write(reinterpret_cast<const char *>(&novoFuncionario), sizeof(novoFuncionario));

  id++;
  salvarId(arq, id);
  arq.close();

  funcionarios.push_back(novoFuncionario);

  int status = 1;
  while (status)
  {
    std::cout << "Você quer registrar outro cliente?";
    std::cout << "1 - Sim";
    std::cout << "0 - Não";
    std::cin >> status;
    if (status == 1)
    {
      cadastrarFuncionario(Funcionario, nomeArquivo);
    }
  }
}

void cadastrarEstadia(const estadia Estadia, std::string nomeArquivo)
{
  std::fstream arq("Estadias.dat", std::ios::in | std::ios::out | std::ios::binary);
  verificaArquivo(arq);
  int id = lerId(arq);

  estadia novaEstadia;
  novaEstadia.idEstadia = id;
  novaEstadia.cadastrarEstadia();

  arq.seekp(sizeof(id) + id * sizeof(cliente), std::ios::beg);
  arq.write(reinterpret_cast<const char *>(&novaEstadia), sizeof(novaEstadia));

  id++;
  salvarId(arq, id);
  arq.close();

  estadias.push_back(novaEstadia);

  int status = 1;
  while (status)
  {
    std::cout << "Você quer registrar outro cliente?";
    std::cout << "1 - Sim";
    std::cout << "0 - Não";
    std::cin >> status;
    if (status == 1)
    {
      cadastrarEstadia(Estadia, nomeArquivo);
    }
  }
}

void baixaEstadia()
{
}

void pesquisarCliente()
{
  std::fstream arq("Clientes.dat", std::ios::in | std::ios::binary);
  verificaArquivo(arq);
  // calcula o tamanho da estrutura Cliente
  std::streamsize tamanhoCliente = sizeof(cliente);

  // posiciona a leitura para o inicio do arquivo
  arq.seekg(0, std::ios::beg);

  cliente Cliente;

  int opcao;
  bool validOption = false;
  while (!validOption)
  {
    std::cout << "Pesquisar Cliente:";
    std::cout << "1-Pesquisar por ID:";
    std::cout << "2-Pesquisar por nome:";

    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
      validOption = true;
      int idBusca;
      std::cin >> idBusca;
      while (arq.read(reinterpret_cast<char *>(&Cliente), tamanhoCliente))
      {
        if (Cliente.idCliente == idBusca)
        {
          Cliente.readClient();
        }
      }
      break;
    case 2:
      std::string nomeBusca;
      std::getline(std::cin, nomeBusca);
      while (arq.read(reinterpret_cast<char *>(&Cliente), tamanhoCliente))
      {
        if (Cliente.nomeCliente == nomeBusca)
        {
          Cliente.readClient();
        }
        validOption = true;
        break;
      default:
        std::cout << "Opção incorreta. Tente novamente.";
        break;
      }
    }
  }
}

void pesquisarFuncionario()
{
  std::fstream arq("Funcionarios.dat", std::ios::in | std::ios::binary);
  verificaArquivo(arq);
  // calcula o tamanho da estrutura
  std::streamsize tamanhoFuncionario = sizeof(funcionario);

  // posiciona a leitura para o inicio do arquivo
  arq.seekg(0, std::ios::beg);

  funcionario Funcionario;

  int opcao;
  bool validOption = false;
  while (!validOption)
  {
    std::cout << "Pesquisar Funcionário:";
    std::cout << "1-Pesquisar por ID:";
    std::cout << "2-Pesquisar por nome:";
    std::cout << "3-Pesquisar por cargo:";

    std::cin >> opcao;
    limparBuffer();
    switch (opcao)
    {
    case 1:
      validOption = true;
      int idBusca;
      std::cin >> idBusca;
      while (arq.read(reinterpret_cast<char *>(&Funcionario), tamanhoFuncionario))
      {
        if (Funcionario.idFuncionario == idBusca)
        {
          Funcionario.readFuncionario();
        }
      }
      break;
    case 2:
      validOption = true;
      std::string nomeBusca;
      std::getline(std::cin, nomeBusca);
      while (arq.read(reinterpret_cast<char *>(&Funcionario), tamanhoFuncionario))
      {
        if (Funcionario.nomeFuncionario == nomeBusca)
        {
          Funcionario.readFuncionario();
        }

        break;
      case 3:
        validOption = true;
        int cargo;
        std::cin >> cargo;
        while (arq.read(reinterpret_cast<char *>(&Funcionario), tamanhoFuncionario))
        {
          if (Funcionario.cargo == cargo)
          {
            Funcionario.readFuncionario();
          }
          break;
        default:
          std::cout << "Opção incorreta";
          break;
        }
      }
    }
  }
  }
  void mostrarEstadiasCliente()
  {
    int id;
    std::cout << "Insira o ID do cliente: ";
    std::cin >> id;
    std::fstream arq("Estadias.dat", std::ios::in | std::ios::binary);
    verificaArquivo(arq);
    // calcula o tamanho da estrutura
    std::streamsize tamanhoEstadia = sizeof(estadia);

    // posiciona a leitura para o inicio do arquivo
    arq.seekg(0, std::ios::beg);

    estadia Estadia;

     while (arq.read(reinterpret_cast<char *>(&Estadia), tamanhoEstadia))
        {
          if (Estadia.idCliente == id)
          {
            Estadia.lerEstadia();
          }
        }
  }

  void calcularPontosFidelidade()
  {
    std::fstream arq("Clientes.dat", std::ios::in | std::ios::binary);
  verificaArquivo(arq);
  // calcula o tamanho da estrutura Cliente
  std::streamsize tamanhoCliente = sizeof(cliente);

  // posiciona a leitura para o inicio do arquivo
  arq.seekg(0, std::ios::beg);

  cliente Cliente;
  std::cout << "Digite o ID do cliente:";
  int idBusca;
  std::cin >> idBusca;
      while (arq.read(reinterpret_cast<char *>(&Cliente), tamanhoCliente))
      {
        if (Cliente.idCliente == idBusca)
        {
          int totalPontos = 0;
          totalPontos = Cliente.pontosFidelidade * 10;
          std::cout << "O cliente" << Cliente.nomeCliente << "tem " << totalPontos << "disponíveis";
          std::cout << "Opções de resgate: " << std::endl << "50 pontos - A próxima diária sai pela metade do preço" << std::endl << "100 pontos - Ganhe uma diária extra grátis a cada 100 pontos";
        }
      }
      break;
    case 2:
      std::string nomeBusca;
      std::getline(std::cin, nomeBusca);
      while (arq.read(reinterpret_cast<char *>(&Cliente), tamanhoCliente))
      {
        if (Cliente.nomeCliente == nomeBusca)
        {
          Cliente.readClient();
        }
        validOption = true;
        break;
      default:
        std::cout << "Opção incorreta. Tente novamente.";
        break;
      }
    }
  }
  }

  void menu()
  {

    int opcao;

    iniciarArquivos("Clientes.dat");
    iniciarArquivos("Funcionarios.dat");
    iniciarArquivos("Estadias.dat");

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
      std::cout << "Escolha uma opcao: ";
      std::cin >> opcao;
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