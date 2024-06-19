/*
Trabalho Prático - AEDS 1

Professor: Ivan Luiz Vieira de Araújo
Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

*/
#include "estruturas.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_QUARTOS 15
#define MAX_ESTADIAS 300
#define MAX_STRING 256

void limparBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void verificaArquivo(FILE *arquivo)
{
  if (!arquivo)
  {
    printf("Erro ao abrir arquivo.\n");
    exit(1);
  }
}

int lerId(FILE *arquivo){
  int id;
  fseek(arquivo, 0, SEEK_SET);
  fread(&id,sizeof(id),1, arquivo);
  return id;
}

void salvarId(FILE *arquivo, int id){
  fseek(arquivo, 0, SEEK_SET);
  fwrite(&id, sizeof(id), 1, arquivo);

}

void iniciateFiles(const char nomeArquivo){
  FILE *arq = fopen(nomeArquivo,"rb+");
  if(!arq){
    arq = fopen(nomeArquivo, "wb+");
    verificaArquivo(arq);
    int id = 0;
    fwrite(&id,sizeof(id),1,arq);
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
    printf("ID: %d\n", clientes[id].idCliente);
    printf("Digite o nome do cliente: ");
    limparBuffer();
    if (fgets(clientes[id].nomeCliente, 50, stdin) != NULL)
    {
      // Remove o caractere de nova linha do final da string
      clientes[id].nomeCliente[strcspn(clientes[id].nomeCliente, "\n")] = '\0';
    }

    printf("Digite o endereço do cliente: ");
    if (fgets(clientes[id].endereco, 100, stdin) != NULL)
    {
      clientes[id].endereco[strcspn(clientes[id].endereco, "\n")] = '\0';
    }

    printf("Digite o telefone do cliente: ");
    if (fgets(clientes[id].telCliente, 15, stdin) != NULL)
    {
      clientes[id].telCliente[strcspn(clientes[id].telCliente, "\n")] = '\0';
    }
    clientes[id].pontosFidelidade = 0;

    fseek(arqCliente,sizeof(id) + id * sizeof(cliente),SEEK_SET);
    fwrite(&clientes[id], sizeof(cliente), 1, arqCliente);
    id++;
    salvarId(arqCliente,id);

    printf("Você quer registrar outro cliente?\n");
    printf("1 - Sim\n");
    printf("0 - Não\n");
    scanf("%d", &status);
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
    printf("ID: %d\n", funcionarios[id].idFuncionario);
    printf("Digite o nome do funcionário: ");
    limparBuffer();
    if (fgets(funcionarios[id].nomeFuncionario, 50, stdin) != NULL)
    {
      funcionarios[id]
          .nomeFuncionario[strcspn(funcionarios[id].nomeFuncionario, "\n")] =
          '\0';
    }
    int cargo;
    printf("Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n");
    scanf("%d", &cargo);
    limparBuffer();
    while (cargo < RECEPCIONISTA || cargo > GERENTE)
    {
      printf("Opção inválida. Digite o cargo do funcionário:\n1 - Recepcionista\n2 - Auxiliar de limpeza\n3 - Garçom\n4 - Gerente\n");
      scanf("%d", &cargo);
      limparBuffer();
    }
    funcionarios[id].cargo = cargo;
    printf("Digite o telefone do funcionário: ");
    if (fgets(funcionarios[id].telFuncionario, 15, stdin) != NULL)
    {
      funcionarios[id]
          .telFuncionario[strcspn(funcionarios[id].telFuncionario, "\n")] =
          '\0';
    }
    printf("Qual o salário do funcionário: ");
    scanf("%f", &funcionarios[id].salario);

    fseek(arqFuncionario,sizeof(id) + id * sizeof(funcionario),SEEK_SET);
    fwrite(&funcionarios[id], sizeof(funcionario), 1, arqFuncionario);
    id++;
    salvarId(arqFuncionario,id);

    printf("Você quer registrar outro cliente?\n");
    printf("1 - Sim\n");
    printf("0 - Não\n");
    scanf("%d", &status);
  }

  fclose(arqFuncionario);
}

int cadastrarEstadia(int id, estadia estadias[])
{
  FILE *arqEstadia;
  arqEstadia = fopen("Estadia.dat", "rb+"); 
  verificaArquivo(arqEstadia);

  int id = lerId(arqEstadia);

  estadia estadias[MAX_ESTADIAS];

  estadias[id].idEstadia = id;
  printf("ID: %d\n", estadias[id].idEstadia);
  printf("Digite a data de entrada do cliente: ");
  scanf("%d/%d/%d", &estadias[id].dataEntrada.dia,
        &estadias[id].dataEntrada.mes, &estadias[id].dataEntrada.ano);
  printf("Digite a data de saída do cliente: ");
  scanf("%d/%d/%d", &estadias[id].dataSaida.dia, &estadias[id].dataSaida.mes,
        &estadias[id].dataSaida.ano);
  printf("Digite a quantidade de diárias do cliente: ");
  scanf("%d", &estadias[id].qntDiarias);
  printf("Digite o ID do cliente: ");
  scanf("%d", &estadias[id].idCliente);
  printf("Digite o número do quarto: ");
  scanf("%d", &estadias[id].numQuarto);

  fseek(arqEstadia,sizeof(id) + id * sizeof(estadia),SEEK_SET);
  fwrite(&estadias[id], sizeof(estadia), 1, arqEstadia);
  id++;
  salvarId(arqEstadia,id);

  fclose(arqEstadia);
}

void baixaEstadia(estadia estadias[])
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
    printf("Pesquisar Cliente:\n");
    printf("1-Pesquisar por ID:\n");
    printf("2-Pesquisar por nome:\n");

    scanf("%d", &opcao);
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
      printf("Opção incorreta. Tente novamente.\n");
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
  printf("Pesquisar Funcionário:\n");
  printf("1-Pesquisar por ID:\n");
  printf("2-Pesquisar por nome:\n");
  printf("3-Pesquisar por cargo:\n");

  scanf("%d", &opcao);
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
    printf("Opção incorreta.\n");
    break;
  }
}

void mostrarEstadiasCliente(estadia estadias[], cliente clientes[])
{
  FILE *arqCliente, *arqEstadia;
  arqCliente = fopen("Clientes.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqCliente);
  arqEstadia = fopen("Estadia.dat", "rb"); // rb para ler arquivo
  verificaArquivo(arqEstadia);
}

void calcularPontosFidelidade(clientes)
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
    printf("========================================\n");
    printf("            SISTEMA DE HOTEL            \n");
    printf("========================================\n");
    printf("1.  Cadastrar Cliente\n");
    printf("2.  Cadastrar Funcionario\n");
    printf("3.  Cadastrar Estadia\n");
    printf("4.  Dar baixa em Estadia\n");
    printf("5.  Pesquisar Cliente\n");
    printf("6.  Pesquisar Funcionario\n");
    printf("7.  Mostrar todas as estadias de um Cliente\n");
    printf("8.  Calcular pontos de fidelidade de um Cliente\n");
    printf("9.  Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
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
      baixaEstadia(estadias);
      break;
    case 5:
      pesquisarCliente(clientes);
      break;
    case 6:
      pesquisarFuncionario(funcionarios);
      break;
    case 7:
      mostrarEstadiasCliente(estadias, clientes);
      break;
    case 8:
      calcularPontosFidelidade(clientes);
      break;
    case 9:
      printf("Saindo do programa...\n");
      printf("Programa criado por João Marcos e João Victor.");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
      getchar(); // Limpa o buffer
      getchar(); // Espera um enter para continuar
    }
  } while (opcao != 9);
}

int main()
{
  setlocale(LC_ALL, "pt_BR");
  menu();
  return 0;
}