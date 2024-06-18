#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_QUARTOS 15
#define MAX_ESTADIAS 300

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
  int cargo[4];
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