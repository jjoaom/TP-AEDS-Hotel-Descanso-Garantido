#ifndef HOSPEDE_H_INCLUDED // Verifica se a biblioteca foi definida
#define HOSPEDE_H_INCLUDED

//Bibliotecas
#include "pessoa.h"
#include "data.h"

typedef struct {
    int numeroRes;
    std::string rua;
    std::string bairro;
    std::string cidade;
    std::string estado;
} Endereco;

class Hospede : public Pessoa
{
private:
    int pontosFidelidade;
    Endereco endereco;
    Data dataEntrada;
    Data dataSaida;
public:

    //Declaracao construtor
    Hospede(std::string nome, int numRes, std::string rua, std::string bairro, std::string cidade, std::string estado);
};

Hospede::Hospede(std::string nome, int numRes, std::string rua, std::string bairro, std::string cidade, std::string estado)
    : Pessoa(nome), pontosFidelidade(0), endereco{numRes, rua, bairro, cidade, estado} {
}

#endif // Biblioteca definida