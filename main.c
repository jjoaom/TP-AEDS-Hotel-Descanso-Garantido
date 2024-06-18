/*
Trabalho Prático - AEDS 1

Professor: Ivan Luiz Vieira de Araújo
Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

*/
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estruturas.h"





void arquivosVazio(FILE *arquivo){
  
  
}

void verificaArquivo(FILE *arquivo){
  if(!arquivo){
    printf("Erro ao abrir arquivo.\n");
    exit(1);
  }
}

void cadastrarCliente(int id,cliente clientes[]) {  
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  verificaArquivo(arqCliente);
  
  clientes[id].idCliente = id;
  printf("ID: %d\n", clientes[id].idCliente);
  printf("Digite o nome do cliente: ");
  fgets(clientes[id].nomeCliente, 50, stdin);
  printf("Digite o endereço do cliente: ");
  fgets(clientes[id].endereco, 100, stdin);
  printf("Digite o telefone do cliente: ");
  fgets(clientes[id].telCliente, 15, stdin);
  clientes[id].pontosFidelidade = 0;
  
  fwrite(&clientes[id], sizeof(cliente), 1, arqCliente);
  id++;
  
  printf("Você quer registrar outro cliente?\n");
  printf("1 - Sim\n");
  printf("2 - Não\n");
  
  
}

void cadastrarFuncionario(int id,funcionario funcionarios[]) {
  FILE *arqFuncionario;
  arqFuncionario = fopen("Funcionarios.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  verificaArquivo(arqFuncionario);


  funcionarios[id].idFuncionario = id;
  printf("ID: %d\n", funcionarios[id].idFuncionario);
  printf("Digite o nome do funcionário: \n");
  fgets(funcionarios[id].nomeFuncionario, 50, stdin);
  printf("Digite o cargo do funcionário:\n1-Recepcionista\n2-Auxiliar de limpeza\n3-Garçom\n4-Gerente \n");
  scanf("%d", funcionarios[id].cargo);
  printf("Digite o telefone do funcionário: \n");
  fgets(funcionarios[id].telFuncionario, 15, stdin);
  printf("Qual o salário do funcionário: \n");
  scanf("%f", &funcionarios[id].salario);
  fwrite(&funcionarios[id], sizeof(funcionario), 1, arqFuncionario);
  id++;
  
}

void cadastrarEstadia(int id,estadia estadias[]) {
  FILE *arqEstadia;
    arqEstadia = fopen("Estadia.dat", "ab+"); //ab+ para adicionar dados ao arquivo
  verificaArquivo(arqEstadia);

  

}

void baixaEstadia() {
  FILE *arqEstadia;
    arqEstadia = fopen("Estadia.dat", "rb+"); //rb+ para editar arquivo
    verificaArquivo(arqEstadia);

}

void pesquisarCliente() {
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb"); //rb para ler arquivo
  verificaArquivo(arqCliente);

}

void pesquisarFuncionario() {
  FILE *arqFuncionario;
  arqFuncionario = fopen("Funcionarios.dat", "rb"); //rb para ler arquivo
  verificaArquivo(arqFuncionario);

}

void mostrarEstadiasCliente() {
  FILE *arqCliente,*arqEstadia;
  arqCliente = fopen("Clientes.dat", "rb"); //rb para ler arquivo
  verificaArquivo(arqCliente);
  arqEstadia = fopen("Estadia.dat", "rb"); //rb para ler arquivo
  verificaArquivo(arqEstadia);
}

void calcularPontosFidelidade(){
  FILE *arqCliente;
  arqCliente = fopen("Clientes.dat", "rb");
  verificaArquivo(arqCliente);

  
}


void menu() {
  setlocale(LC_ALL, "Portuguese");
  struct cliente *clientes[MAX_CLIENTES];
  struct funcionario *funcionarios[MAX_FUNCIONARIOS];
  struct quarto *quartos[MAX_QUARTOS];
  struct estadia *estadias[MAX_ESTADIAS];
  int opcao;
  int idCliente = 0, idFuncionario = 0, idEstadia = 0;

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
      cadastrarCliente(idCliente,clientes);
      break;
    case 2:
      cadastrarFuncionario(idFuncionario,funcionarios);
      break;
    case 3:
      cadastrarEstadia(idEstadia,estadias);
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

int main() {
  menu();
  return 0;
}