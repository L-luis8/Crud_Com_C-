#include <iostream>
#include <locale.h>
#include <stdlib.h>

#define MAX 2 ///Número total de Pessoas/cadastros

using namespace std;

typedef struct{
    string nome;
    string cpf;
    int idade = 0;
    string cargo;
}Pessoa;

void cadastrarClientes(Pessoa cliente[MAX]){

    cout << "Cadastro de Pessoas!\n-----------\n";
    for(int i = 0; i < MAX; i++){
        cout << "\nDigite o nome: ";
        cin >> cliente[i].nome;
        cout << "Digite o CPF: ";
        cin >> cliente[i].cpf;
        cout << "Idade: ";
        cin >> cliente[i].idade;
        cout << "Cargo na Empresa: ";
        cin >> cliente[i].cargo;
    }
    system("cls");
    cout << "\nCadastrado com Sucesso" << endl;
    system("pause");
    system("cls");
}

void listarClientes(Pessoa cliente[MAX]){

    cout << "Listagem de Clientes!\n-----------\n";
    for(int i = 0; i < MAX; i++){
        cout << "\nNome: " << cliente[i].nome;
        cout << "\nCPF: " << cliente[i].cpf;
        cout << "\nIdade: " << cliente[i].idade;
        cout << "\nCargo: " << cliente[i].cargo << endl;
        cout << "\n";
    }
}

bool pesquisarClientes(Pessoa cliente[MAX]){
    string pesquisa;

    cout << "Digite o CPF da pessoa que deseja pesquisar: ";
    cin >> pesquisa;
    for(int i = 0; i < MAX; i++){
        if(pesquisa == cliente[i].cpf){
            cout << "CPF encontrado!\n---------\n";
            cout << "\nNome: " << cliente[i].nome;
            cout << "\nCPF: " << cliente[i].cpf;
            cout << "\nIdade: " << cliente[i].idade;
            cout << "\nCargo: "  << cliente[i].cargo;
            cout << "\n";
            return true;
        }
    }

    cout << "O CPF " << pesquisa << " nao foi encontrado!" << endl;
    return false;
}

bool atualizarDados(Pessoa cliente[MAX]){
    string pesquisa;

    cout << "Digite o CPF da pessoa que deseja atualizar: ";
    cin >> pesquisa;
    for(int i = 0; i <MAX; i++){
        if(pesquisa == cliente[i].cpf){
            cout << "Digite os novos dados\n-----------\n\n";
            cout << "Novo nome: ";
            cin >> cliente[i].nome;
            cout << "Novo CPF: ";
            cin >> cliente[i].cpf;
            cout << "Idade: ";
            cin >> cliente[i].idade;
            cout << "Cargo: ";
            cin >> cliente[i].cargo;
            return true;
        }
    }

    cout << "O CPF " << pesquisa << " nao foi encontrado!" << endl;
    return false;
}

bool removerCliente(Pessoa cliente[MAX]){
    string pesquisa;

    cout << "Digite o CPF da pessoa que deseja remover: ";
    cin >> pesquisa;

    for(int i = 0; i <MAX; i++){
        if(pesquisa == cliente[i].cpf){
            cliente[i].nome = "CLIENTE REMOVIDO";
            cliente[i].idade = 0;
            cliente[i].cpf = " CLIENTE REMOVIDO";
            cliente[i].cargo = "CLIENTE REMOVIDO";
            cout << "\nRemovido com sucesso\n";
            return true;
        }
    }

    cout << "O CPF " << pesquisa << " não foi encontrado!" << endl;
    return false;
}

void escolha(){

    Pessoa cliente[MAX];

    cout << "Escolha qual opcao deseja!\n-----------\n";
    int opcao = 0;
    do{
        cout << "\n1 - Cadastrar;";
        cout << "\n2 - Listar;";
        cout << "\n3 - Pesquisar;";
        cout << "\n4 - Atualizar Dados;";
        cout << "\n5 - Remover;";
        cout << "\n0 - Encerrar Sessao.\n";
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                cadastrarClientes(cliente);
            break;

            case 2:
                system("cls");
                listarClientes(cliente);
                system("pause");
                system("cls");
            break;

            case 3:
                system("cls");
                pesquisarClientes(cliente);
                system("pause");
                system("cls");
            break;

            case 4:
                system("cls");
                atualizarDados(cliente);
                system("pause");
                system("cls");
            break;

            case 5:
                system("cls");
                removerCliente(cliente);
                system("pause");
                system("cls");
            break;

            case 0:
                system("cls");
                cout << "Thank you!\n";
                system("pause");
            break;

            default:
                system("cls");
                cout << "Opção Inválida!\n";
                system("pause");
            break;
        }

    }while(opcao != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    escolha();
}
