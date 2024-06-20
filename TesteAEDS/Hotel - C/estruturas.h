#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

//Bibliotecas
#include "data.h"
#include "endereco.h"
#include <stdbool.h>

//Macros
#define MAX_STRING 256

//Estrutura de Quarto
typedef struct {
    int numQuarto;
    float valorDiaria;
    int quantHospedes;
    bool status;
}Quarto;

//Estrutura de Hospede
typedef struct 
{
    int id;
    int numQuartoOcupado;
    char nome[MAX_STRING];
    int pontosFidelidade;
    Endereco Endereco;
    Data dataEntrada;
    Data dataSaida;
} Hospede;

// Estrutura de Funcionario
typedef struct
{
    int id;
    char Cargo[MAX_STRING];
    char nome[MAX_STRING];
} Funcionario;

//Estrutura de Estadia
typedef struct
{
    int codEstadia;
    int codigoHospede;
    int numQuarto;
    double diarias;
    Data dataEntrada;
    Data dataSaida;
} Estadia;


#endif