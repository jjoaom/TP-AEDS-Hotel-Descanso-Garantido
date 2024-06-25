#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <stdbool.h>
#include "data.h"

#define MAX_STRING 256
#define MAX_TEL 20


// Enum para cargos
typedef enum{
  RECEPCIONISTA = 1,
  AUXILIAR_DE_LIMPEZA = 2,
  GARCOM = 3,
  GERENTE = 4
} Cargo;

// Struct para clientes
typedef struct {
  int idCliente;
  char nomeCliente[MAX_STRING];
  char endereco[MAX_STRING];
  char telCliente[MAX_TEL];
  int pontosFidelidade;
} cliente;

// Struct para endereço

typedef struct {
    char rua[MAX_STRING];
    char numero[10];
    char bairro[MAX_STRING];
    char cidade[MAX_STRING];
    char estado[3];
    char cep[9];
} Endereco;


// Struct para funcionarios
typedef struct {
  int idFuncionario;
  char nomeFuncionario[MAX_STRING];
  Cargo cargo;
  char telFuncionario[MAX_TEL];
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