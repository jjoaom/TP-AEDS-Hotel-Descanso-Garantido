#include <iostream>
#include <fstream>
#include <locale>
#include "classes.h"

using namespace std;

//Função para verificar a existencia de arquivos e carregar os arquivos criados
void verificarCriarArquivos() {
    ifstream arquivoClientes("Clientes.txt");
    ifstream arquivoFuncionarios("Funcionarios.txt");
    ifstream arquivoEstadias("Estadias.txt");
    ifstream arquivoQuartos("Quartos.txt");

    if (!arquivoClientes) {
        ofstream novoArquivo("Clientes.txt");
        novoArquivo.close();
    }

    if (!arquivoFuncionarios) {
        ofstream novoArquivo("Funcionarios.txt");
        novoArquivo.close();
    }

    if (!arquivoEstadias) {
        ofstream novoArquivo("Estadias.txt");
        novoArquivo.close();
    }

    if (!arquivoQuartos) {
        ofstream novoArquivo("Quartos.txt");
        novoArquivo.close();
    }

    carregarQuartos();
    carregarClientes();
    carregarFuncionarios();
    carregarEstadias();
}

void menu() {
    bool loopMenu = true;
    while (loopMenu) {
        int opcaoMenu;
        cout << "Hotel Dream's Palace" << endl;
        cout << "1 - Cadastro de clientes" << endl;
        cout << "2 - Cadastro de funcionarios" << endl;
        cout << "3 - Cadastro de estadia" << endl;
        cout << "4 - Pesquisa de clientes" << endl;
        cout << "5 - Pesquisa de funcionarios" << endl;
        cout << "6 - Dar baixa na estadia" << endl;
        cout << "7 - Mostrar Estadias por cliente" << endl;
        cout << "8 - Calcular pontos fidelidade" << endl;
        cout << "9 - Salvar e Sair" << endl;
        cout << "Digite sua escolha: ";
        cin >> opcaoMenu;
        limparBuffer();

        switch (opcaoMenu) {
            case 1:
                cadastrarCliente();
                getchar();
                system("cls");
                break;
            case 2:
                cadastrarFuncionario();
                getchar();
                system("cls");
                break;
            case 3:
                cadastrarEstadia();
                getchar();
                system("cls");
                break;
            case 4:
                pesquisarCliente();
                getchar();
                system("cls");
                break;
            case 5:
                pesquisarFuncionario();
                getchar();
                system("cls");
                break;
            case 6:
                baixaEstadia();
                getchar();
                system("cls");
                break;
            case 7:
                mostrarEstadiasCliente();
                getchar();
                system("cls");
                break;
            case 8:
                calcularPontosFidelidade();
                break;
            case 9:
                loopMenu = false;
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção incorreta. Tente novamente." << endl;
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    verificarCriarArquivos();
    menu();

    return 0;
}
