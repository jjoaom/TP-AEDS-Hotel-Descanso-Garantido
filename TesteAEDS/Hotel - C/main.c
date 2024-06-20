// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Bibliotecas Nativas
#include "data.h"
#include "endereco.h"
#include "estruturas.h"

// Macros
#define SUCESSO 0
#define MAX_QUARTOS 5

//Funcao de inicializacao do ponteiro de quartos
Quarto* INICIALIZA_QUARTOS(){
    // Alocando o espaço para quartos
    Quarto* Quartos = (Quarto*) malloc (sizeof(Quarto) * MAX_QUARTOS);

    for(int i = 0; i < MAX_QUARTOS; i++){
        Quartos[i].numQuarto =  i;
        Quartos[i].quantHospedes = 0;
        Quartos[i].status = false;

        if(Quartos[i].numQuarto > (MAX_QUARTOS/ 2)){
            Quartos[i].valorDiaria = 799.9;
        } else {
            Quartos[i].valorDiaria = 599.9;
        }
    }

    return Quartos;
}

//Lista quartos do hotel
void LISTA_QUARTOS(Quarto* Quartos){
    printf("\n----||Lista de quartos disponiveis||----\n");

    for(int i = 0; i < MAX_QUARTOS; i++){
        printf("NUMERO DO QUARTO: %i \n", Quartos[i].numQuarto);

        if (Quartos[i].status == false)
        {
            printf("SITUACAO: Desocupado \n");
        } else if (Quartos[i].status == true){
            printf("SITUACAO: Ocupado \n");
        }
        
    }
}

void CADASTRA_HOSPEDE(Hospede* hospede){
    hospede = (Hospede*) malloc (sizeof(Hospede));
    
    printf("Infome o nome do hospede:");
    fgets(hospede->nome,MAX_STRING,stdin);
}

void DATA_ENTRADA(Data dataEntrada)
{
    if (VERIFICA_DATA(dataEntrada) == false)
    {
        printf("Data invalida!\n");
    }
    else
    {
       // codigo
    }
}

int main(void)
{
    // Variáveis
    Hospede* hospede; 
    CADASTRA_HOSPEDE(hospede);
    //Inicializa a lista de quartos
    Quarto* Quartos =  INICIALIZA_QUARTOS();
    LISTA_QUARTOS(Quartos);
    return SUCESSO;
}