#ifndef DATA_H
#define DATA_H

// Bibliotecas
#include <stdbool.h>

// Macros
#define MAX_MES 12

// Globais
int meses[MAX_MES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Struct de data
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

bool VERIFICA_DATA(Data data)
{

    // Verifica se o ano é bissexto
    if ((data.ano % 4 == 0) && (data.ano % 100 != 0))
    {
        meses[1] = 29;
    }

    // Verifica se a data é valida
    for (int i = 0; i < MAX_MES; i++)
    {
        if (data.mes == i + 1)
        {
            if (data.dia > 0 && data.dia <= meses[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

#endif /*Verificador da biblioteca*/