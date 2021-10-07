#include "Interface.h"
#include "Processador.h"
#include "uteis.h"

void menu_principal(){
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

void submenu_pes(unordered_map <string,contact*>& tab_contatos){
    //Função para listar o SUBMENU da opção 4 e pegar a opção desejada
    cout << endl;
    int sop;

    cout << (("================ Agenda Telefônica ================")) << endl;
    cout << (("4 - Buscar cadastro")) << endl;
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
    pesquisar_contato(sop,tab_contatos);
}

void submenu_alt(unordered_map <string,contact*>& tab_contatos){
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
    alterar_contato(sop, tab_contatos);
}

void pesquisar_contato(int sop, unordered_map <string,contact*>& tab_contatos) {
    cout << endl;
    string nome, telefone, email;
    switch (sop) {
        //Pesquisa por nome
        case 1: {
            cout << "Digite o nome: ";
            getline(cin, nome);
            pesquisa_nome(nome,tab_contatos);
            break;
        }
            //Pesquisa por telefone
        case 2: {
            cout << "Digite o telefone: ";
            getline(cin, telefone);
            cout << endl;
            pesquisa_telefone(telefone,tab_contatos);
            break;
        }
            //Pesquisa por email
        case 3: {
            cout << "Digite o e-mail: ";
            getline(cin, email);
            cout << endl;
            pesquisa_email(email,tab_contatos);
            break;
        }
        case 0:
            break;
        default:
            cout << "Opção inválida!" << endl << endl;
            break;
    }
}

int alterar_contato(const int & sop, unordered_map <string,contact*>& tab_contatos){
    cout << endl;
    string nome,op;
    switch (sop) {
        //Exclui contato
        case 1: {
            cout << "Digite o nome do contato que deseja excluir: ";
            getline(cin, nome);
            excluir_contato(nome,tab_contatos);
            break;
        }
        //Edita o contato
        case 2: {
            cout << "Digite o nome do contato que deseja editar: ";
            getline(cin, nome);

            cout << "Digite o que deseja editar (nome, telefone ou email): ";
            getline(cin, op);
            editar_dados(nome,op,tab_contatos);
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
    contact dados_cadastro[40];
    unordered_map<string, string> tab_cadastro;
    string contatos[40];
    int i = 0;
    bool op = true;
    string V;
    //Define um vetor de struct
    while (op){
        cout << endl;
        cout << "Na ausência de alguma opção digite 0" << endl;

        cout << "Digite o nome: ";
        cin >> dados_cadastro[i].nome;

        cout << "Digite o telefone com DDD (Ex: (48)99999-9999): ";
        cin >> dados_cadastro[i].telefone;

        cout << "Digite o email: ";
        cin >> dados_cadastro[i].email;

        cout << endl;
        cout << "Deseja digitar um outro contato? (Sim ou Não): ";
        cin >> V;

        if (V == "Sim") {
            i++;
            op = true;
        } else {
            for (int j = 0; j <= i; j++) {
                //Adiciona o contato em uma linha da lista
                contatos[j] = dados_cadastro[j].nome + ";"
                                       + dados_cadastro[j].telefone+ ";"
                                       + dados_cadastro[j].email;
                tab_cadastro[contatos[j]] = contatos[j];
            }
            op = false;
            //Escreve a linha no arquivo
            escrever_arquivo(arq_principal,tab_cadastro);
            cout << "\e[1mContatos salvos!!! \e[0m" << endl;
            //cout << "\e[1mTEXTO\e[0m" << endl;
        }
    }
}

//Ordem alfabética por nome
void exibir_contato_ordem(unordered_map<string, contact*> & tab_contatos){

    unordered_set<contact*> conjunto_de_contatos;
    list<contact> lista_contatos;
    contact dados;
    //Adiciona a tabela na lista
    for (auto & par: tab_contatos){
        conjunto_de_contatos.insert(par.second);
    }
    //Adiciona a tabela na lista
    for (auto & t: conjunto_de_contatos){
        dados.nome = t->nome;
        dados.telefone = t->telefone;
        dados.email = t->email;
        lista_contatos.push_back(dados);
    }
    //Ordena
    lista_contatos.sort();
    lista_contatos.reverse();

    for (auto & x: lista_contatos){
        cout << endl;
        cout << "Nome: " << x.nome << endl;
        cout << "Telefone: " << x.telefone << endl;
        cout << "Email: " << x.email << endl;
    }
}

void le_contatos(const string & arquivo, unordered_map<string, contact*> & tab_contatos) {
    //Função para abrir a Lista_telefonica
    string line;
    ifstream myfile (arquivo);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            list<string> l;
            separa_lista(line, ';', l);

            // cria um contato dinamicamente
            contact *tab_dados = new contact;

            // uso um iterador para acessar as strings na lista
            // mais simples e eficiente que retirar o primeiro dado da lista !
            auto it = l.begin();
            tab_dados->email = *it;
            it++;
            tab_dados->telefone = *it;
            it++;
            tab_dados->nome = *it;

            // acrescenta o contato à tabela
            tab_contatos[tab_dados->nome] = tab_dados;
            tab_contatos[tab_dados->email] = tab_dados;
            tab_contatos[tab_dados->telefone] = tab_dados;
        }
        myfile.close();
    }
}