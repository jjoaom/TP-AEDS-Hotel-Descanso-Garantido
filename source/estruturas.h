#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <stdbool.h>


// Enum para cargos
typedef enum{
  RECEPCIONISTA = 1,
  AUXILIAR_DE_LIMPEZA = 2,
  GARCOM = 3,
  GERENTE = 4
} Cargo;

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
  Cargo cargo;
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

#endif /* ESTRUTURAS_H*/