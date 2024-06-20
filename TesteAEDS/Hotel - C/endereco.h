#ifndef ENDERECO_H
#define ENDERECO_H

#define MAX_STRING 256

// Estrututa endereco
typedef struct
{
    int numero;
    char rua[MAX_STRING];
    char bairro[MAX_STRING];
    char cidade[MAX_STRING];
    char estado[2];
} Endereco;

#endif