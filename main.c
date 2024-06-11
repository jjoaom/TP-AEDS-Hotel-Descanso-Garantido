/*
Trabalho Prático - AEDS 1

Professor: Ivan Luiz Vieira de Araújo
Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct para Data
typedef struct {
  int ano;
  int mes;
  int dia;
} Data;

// Struct para clientes
typedef struct {
  int idCliente;
  char nomeCliente[50];
  char endereco[100];
  char telCliente[15];
  int pontosFidelidade;
} cliente;

// Struct para funcionarios
typedef struct {
  int idFuncionario;
  char nomeFuncionario[50];
  char cargo[50];
  char telFuncionario[15];
  float salario;
} funcionario;

// Struct para estadias
typedef struct {
  int idEstadia;
  Data dataEntrada;
  Data dataSaida;
  int qntDiarias;
  int idCliente;
  int numQuarto;
} estadia;

// Struct para quartos
typedef struct {
  int numQuarto;
  int qtdHospedes;
  float valorDiaria;
  bool status;
} quarto;

void cadastrarCliente() {
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  if (!arqCliente) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void cadastrarFuncionario() {
  FILE *arqFuncionario;
  arqFuncionario = fopen("Funcionarios.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  if (!arqFuncionario) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void cadastrarEstadia() {
  FILE *arqEstadia;
    arqEstadia = fopen("Estadia.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  if (!arqEstadia) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void baixaEstadia() {
  FILE *arqEstadia;
    arqEstadia = fopen("Estadia.dat", "rb+"); //rb+ para editar arquivo
  if (!arqEstadia) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void pesquisarCliente() {
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb"); //rb para ler arquivo
  if (!arqCliente) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void pesquisarFuncionario() {
  FILE *arqFuncionario;
  arqFuncionario = fopen("Funcionarios.dat", "rb"); //rb para ler arquivo
  if (!arqFuncionario) {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }
}

void mostrarEstadiasCliente() {
  FILE *arqCliente,*arqEstadia;
  arqCliente = fopen("Clientes.dat", "rb"); //rb para ler arquivo
  arqEstadia = fopen("Estadia.dat", "rb"); //rb para ler arquivo
  if (!arqCliente && !arqEstadia) {
    printf("Erro ao abrir arquivos");
    exit(1);
  }
}

void calcularPontosFidelidade(){
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb");
  if(!arqCliente){
    printf("Erro ao abrir arquivos");
    exit(1);
  }
  
}

void menu() {
  int opcao;

  do {
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

    switch (opcao) {
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

int main(void) {
  printf("Hello World\n");
  return 0;
}
