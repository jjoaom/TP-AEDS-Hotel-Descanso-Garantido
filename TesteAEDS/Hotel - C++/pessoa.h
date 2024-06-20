#ifndef PESSOA_H_INCLUDED //Verifica se a classe esta sendo incluida
#define PESSOA_H_INCLUDED


class Pessoa
{
private:
    int id;
    std::string nome;
    
public:
    //Declaracao Construtor
    Pessoa(std::string nome);

    //Declaracao Getters
    std::string getNome();

    //Declaracao Setters
    void setNome(std::string nome);
};

// Construtor
Pessoa::Pessoa(std::string nome)
{
    this->nome = nome;
}

// Getters
std::string Pessoa::getNome()
{
    return this->nome;
}

//Setters
void Pessoa::setNome(std::string nome)
{
    this->nome = nome;
}

#endif //Classe incluida