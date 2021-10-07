#include "Interface.h"
#include "Processador.h"
#include "uteis.h"

void menu_principal(const string & s_menu){
    //Função para listar o MENU principal e pegar a opção desejada
    cout << endl << endl;
    cout << (("================ Agenda Telefônica ================")) << endl;
    cout << (("1 - Cadastrar novo contato")) << endl;
    cout << (("2 - Criar grupo")) << endl;
    cout << (("3 - Apagar grupo")) << endl;
    cout << (("4 - Pesquisar cadastro")) << endl;
    cout << (("5 - Lista todos os contatos por ordem alfabética")) << endl;
    cout << (("6 - Lista todos os contatos por grupo")) << endl;
    cout << (("7 - Lista todos os contatos por grupo específico")) << endl;
    cout << (("8 - Lista todos os contatos por ordem de popularida")) << endl;
    cout << (("9 - Alterar dados")) << endl;
    cout << (("0 - Sair")) << endl;
    cout << (("==================================================")) << endl;
}

void submenu_pes(const string & p_submenu, list<contact> & lista_de_contato){
    //Função para listar o SUBMENU da opção 3 e pegar a opção desejada
    cout << endl;
    int sop;

    cout << (("================ Agenda Telefônica ================")) << endl;
    cout << (("4 - Pesquisar cadastro")) << endl;
    cout << (("    1 - Pesquisar por nome")) << endl;
    cout << (("    2 - Pesquisar por telefone")) << endl;
    cout << (("    3 - Pesquisar por email")) << endl;
    cout << (("    0 - Voltar ao menu principal")) << endl;
    cout << (("==================================================")) << endl;

    cout << "Digite a Sub-opção desejada: ";
    //Guarda a opção em uma string.
    cin >> sop;
    cin.ignore();
    //Acrescenta a opção em outra função junto, ao arquivo lido no main.cpp
    pesquisar_contato(sop, lista_de_contato);
}

void submenu_alt(const string & a_submenu, list<string> & l_arquivo, list<contact> & lista_de_contato){
    //Função para listar o SUBMENU da opção 3 e pegar a opção desejada
    cout << endl;
    int sop;
    cout << (("================ Agenda Telefônica ================")) << endl;
    cout << (("9 - Alterar dados")) << endl;
    cout << (("    1 - Excluir contato")) << endl;
    cout << (("    2 - Editar contato")) << endl;
    cout << (("    0 - Voltar ao menu principal")) << endl;
    cout << (("==================================================")) << endl;

    cout << "Digite a Sub-opção desejada: ";
    //Guarda a opção em uma string.
    cin >> sop;
    cin.ignore();
    //Acrescenta a opção em outra função junto, ao arquivo lido no main.cpp
    alterar_contato(sop, l_arquivo, lista_de_contato);
}

int pesquisar_contato(const int & sop, list<contact> & lista_de_contato){
    cout << endl;
    string nome, sobrenome, telefone, email;
    switch (sop) {
        //Pesquisa por nome
        case 1: {
            cout << "Digite o nome: ";
            getline(cin, nome);
            pesquisa_nome(nome,lista_de_contato);
            break;
        }
            //Pesquisa por telefone
        case 2: {
            cout << "Digite o telefone: ";
            getline(cin, telefone);
            cout << endl;
            pesquisa_telefone(telefone,lista_de_contato);
            break;
        }
            //Pesquisa por email
        case 3: {
            cout << "Digite o e-mail: ";
            getline(cin, email);
            cout << endl;
            pesquisa_email(email,lista_de_contato);
            break;
        }
        case 0: return 0;
        default:
            cout << "Opção inválida!" << endl << endl;
            break;
    }
}

int alterar_contato(const int & sop, list<string> & l_arquivo, list<contact> & lista_de_contato){
    cout << endl;
    string nome,op;
    switch (sop) {
        //Exclui contato
        case 1: {
            cout << "Digite o nome do contato que deseja excluir: ";
            getline(cin, nome);
            excluir_contato(nome,l_arquivo, lista_de_contato);
            break;
        }
        //Edita o contato
        case 2: {
            cout << "Digite o nome do contato que deseja editar: ";
            getline(cin, nome);

            cout << "Digite o que deseja editar (nome, telefone ou email): ";
            getline(cin, op);
            editar_dados(nome,op,l_arquivo, lista_de_contato);
            break;
        }
        case 0: return 0;
        default:
            cout << "Opção inválida!" << endl << endl;
            break;
    }
}

void op_editar_dados(const string & op, string & N, string & T, string & E){

    //Substitui o nome
    if(op == "nome"){
        cout << "Digite o novo nome: ";
        getline(cin, N);
    }
    //Substitui o telefone
    if(op == "telefone"){
        cout << "Digite o novo telefone com DDD: ";
        getline(cin, T);
    }
    //Substitui o email
    if(op == "email"){
        cout << "Digite o novo e-mail: ";
        getline(cin, T);
    }
}

void cadastrar_contato() {
    contact contato[40];
    list<string> l_cadastro;
    int i = 0;
    bool op = true;
    string V;
    //Define um vetor de struct
    while (op){
        cout << endl;
        cout << "Na ausência de alguma opção digite 0" << endl;

        cout << "Digite o nome: ";
        cin >> contato[i].nome;

        cout << "Digite o sobrenome: ";
        cin >> contato[i].sobrenome;

        cout << "Digite o telefone com DDD (Ex: (48)99999-9999): ";
        cin >> contato[i].telefone;

        cout << "Digite o email: ";
        cin >> contato[i].email;

        cout << endl;
        cout << "Deseja digitar um outro contato? (Sim ou Não): ";
        cin >> V;

        if (V == "Sim") {
            i++;
            op = true;
        } else {
            for (int j = 0; j <= i; j++) {
                //Adiciona o contato em uma linha da lista
                l_cadastro.push_front(contato[j].nome + " "
                                       + contato[j].sobrenome + ";"
                                       + contato[j].telefone+ ";"
                                       + contato[j].email + "\n");
            }
            op = false;
            //Inverte para ficar na ordem cadastrada
            l_cadastro.reverse();
            //Escreve a linha no arquivo
            escrever_arquivo(arq_principal,l_cadastro);
        }
    }
}

//Ordem alfabética por nome
void listar_contato_ordem(list<contact> & lista_de_contato){
    lista_de_contato.sort();
    for (auto it = lista_de_contato.begin(); it != lista_de_contato.end(); it++) {
        cout << endl;
        cout << "Nome: " << it->nome << endl;
        cout << "Telefone: " << it->telefone << endl;
        cout << "Email: " << it->email << endl;
    }
}