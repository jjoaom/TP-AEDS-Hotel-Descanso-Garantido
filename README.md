# Projeto de Algoritmos e Estruturas de Dados I

## Hotel Descanso Garantido

### Professor: Ivan Luiz Vieira de Araújo
### Alunos: João Marcos de Aquino Gonçalves e João Victor dos Santos Nogueira

## Descrição do Projeto
O Hotel Descanso Garantido, localizado no centro de Itacaré – BA, busca modernizar seus processos de gerenciamento de estadias, clientes e funcionários, que atualmente são feitos em planilhas do Excel e cadernos. Este projeto visa desenvolver um sistema específico para melhorar a organização do hotel e evitar problemas como a reserva dupla de quartos.

## Funcionalidades do Sistema
O sistema permitirá:

1. **Cadastro de Clientes**
   - Código, nome, endereço, telefone

2. **Cadastro de Funcionários**
   - Código, nome, telefone, cargo, salário

3. **Cadastro de Estadias**
   - Código da estadia, data de entrada, data de saída, quantidade de diárias, código do cliente, número do quarto
   - Verificação de disponibilidade do quarto com base no status e capacidade
   - Cálculo automático da quantidade de diárias

4. **Baixa de Estadias**
   - Alteração do status do quarto para desocupado
   - Cálculo e exibição do valor total a ser pago pelo cliente

5. **Pesquisa de Clientes e Funcionários**
   - Pesquisa por nome ou código
   - Exibição das informações cadastradas

6. **Visualização de Estadias de um Cliente**
   - Exibição de todas as estadias de um cliente específico

7. **Cálculo de Pontos de Fidelidade**
   - Acúmulo de pontos de fidelidade (10 pontos por diária)
   - Suporte para múltiplas estadias por cliente

## Requisitos Técnicos
- Linguagem de Programação: C
- Armazenamento dos dados em arquivos binários
- Utilização de bibliotecas em C para modularização do código
- Interface de usuário em modo texto (terminal)
- Persistência dos dados entre execuções do programa

## Instruções de Execução
1. Compile o código utilizando um compilador C (por exemplo, `gcc`).
2. Execute o programa principal.
3. Utilize o menu interativo para testar as funcionalidades do sistema.



```mermaid
erDiagram
    CLIENTE {
        int codigo
        string nome
        string endereco
        string telefone
        int pontos_fidelidade

    }

    FUNCIONARIO {
        int codigo
        string nome
        string telefone
        string cargo
        float salario
    }

    ESTADIA {
        int codigo
        date data_entrada
        date data_saida
        int qtd_diarias
        int codigo_cliente
        int numero_quarto
    }

    QUARTO {
        int numero
        int qtd_hospedes
        float valor_diaria
        string status
    }

    CLIENTE ||--o{ ESTADIA : "faz"
    QUARTO ||--o{ ESTADIA : "é reservada para"
    FUNCIONARIO ||..o{ CLIENTE : "atende"
