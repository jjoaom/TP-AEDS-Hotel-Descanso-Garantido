#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

//Bibliotecas
#include <stdbool.h>

//Macros
#define MAX_MESES 12

//Globais
int DIAS_MESES[MAX_MESES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Estrutura de data
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
        DIAS_MESES[1] = 29;
    }

    // Verifica se a data é valida
    for (int i = 0; i < MAX_MESES; i++)
    {
        if (data.mes == i + 1)
        {
            if (data.dia > 0 && data.dia <= DIAS_MESES[i])
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

#endif