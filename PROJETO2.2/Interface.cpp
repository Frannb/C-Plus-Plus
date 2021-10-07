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

void submenu_pesquisa(unordered_map <string,contact*>& tab_contatos){
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
    menu_pesquisar_contato(sop,tab_contatos);
}

int submenu_alterar_contato(unordered_map <string,contact*>& tab_contatos){
    //Função para listar o SUBMENU da opção 9 e pegar a opção desejada
    cout << endl;
    int sub_opcao;
    cout << (("================ Agenda Telefônica ================")) << endl;
    cout << (("9 - Alterar dados")) << endl;
    cout << (("    1 - Excluir contato")) << endl;
    cout << (("    2 - Editar contato")) << endl;
    cout << (("    0 - Voltar ao menu principal")) << endl;
    cout << (("==================================================")) << endl;

    cout << "Digite a Sub-opção desejada: ";
    //Guarda a opção em uma string.
    cin >> sub_opcao;
    cout << endl;
    cin.ignore();
    //Acrescenta a opção em outra função junto, ao arquivo lido no main.cpp

    string nome,opcao_case;
    switch (sub_opcao) {
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
            cout << endl;
            cout << "Digite o que deseja editar (nome, telefone ou email): ";
            getline(cin, opcao_case);
            editar_dados(nome,opcao_case,tab_contatos);
            break;
        }
        case 0: return 0;
        default:
            cout << "Opção inválida!" << endl << endl;
            break;
    }
}

void menu_pesquisar_contato(int sub_opcao, unordered_map <string,contact*>& tab_contatos) {
    cout << endl;
    string nome, telefone, email;
    switch (sub_opcao) {
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

void opcoes_editar_dados(const string & opcao, string & N, string & T, string & E){

    //Substitui o nome
    if(opcao == "nome"){
        cout << "Digite o novo nome: ";
        getline(cin, N);
    }
    //Substitui o telefone
    if(opcao == "telefone"){
        cout << "Digite o novo telefone com DDD: ";
        getline(cin, T);
    }
    //Substitui o email
    if(opcao == "email"){
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
            cout << "\e[1mContatos salvos!!!\e[0m" << endl;
            //cout << "\e[1mTEXTO\e[0m" << endl;
        }
    }
}

void cria_grupo(const string & arquivo, unordered_map <string, grupo*> &tab_grupos, unordered_map <string,contact*> &tab_contatos, unordered_map <string, string> &tab_grupos_str){
    string str_nome_grupo;
    string dado; //dado do contato que vai ser colocado no grupo. Ex: telefone, email ou nome
    string copia; // string para auxiliar na tab_escrita
    string copia2;
    string copia_tab_string; //copia especifica para auxiliar a tab_grupos_string
    string copia_tab_string2;
    string nome_grupo_str;
    int i = 0;
    bool op = true;
    unordered_map <string, string> tab_escrita; //tabela feita exclusivamente para escrever no arquivo

    /*Vai pedir pro usuário digitar o nome do grupo que ele deseja criar, se o usuário digitar um grupo que ja está
    cadastrado, o programa pedirá outro nome para o grupo*/
    cout << "Digite o nome do grupo que deseja criar ou 'q' para cancelar:" << endl;
    while (op == true) {
        getline(cin,str_nome_grupo);
        if(str_nome_grupo == "q"){
            str_nome_grupo.clear();
            return ;
        }
        if (tab_grupos.count(str_nome_grupo) > 0) {
            cout << "Grupo já existente, digite um outro nome que ainda não foi utilizado: " << endl;
        } else op = false;
    }

    grupo *grupo_novo = new grupo;
    grupo_novo->nome_grupo = str_nome_grupo;

    cout << "Se desejar parar de adicionar contatos ao grupo, digite 'q' " << endl;
    cout << "Se desejar cancelar a criação do grupo, digite 'c'" << endl;
    cout << "Digite o nome, número, ou email do contato que deseja adicionar ao grupo"<< endl;

    while (dado != "q") {
        getline(cin, dado);
        if (dado == "q") break; //opção para parar de adicionar contatos
        else if (dado == "c" ) return; //opção para cancelar a criação de grupos
        else if (tab_contatos.count(dado) <= 0) { //verifica se existe o contato na tabela de contatos
            cout<< "Contato não existente, por favor voltar ao menu principal e ir na opção 1 para cadastrar o contato primeiro"<< endl;
        }else {
            contact *contato_novo = new contact;

            contato_novo = tab_contatos[dado]; //copia todo o contato da tabela para contato novo

            //adiciona o contato_novo na tabela de contatos do grupo novo
            grupo_novo->tab_contatos_struct[contato_novo->nome] = contato_novo;
            grupo_novo->tab_contatos_struct[contato_novo->telefone] = contato_novo;
            grupo_novo->tab_contatos_struct[contato_novo->email] = contato_novo;

            cout << "Contato adicionado ao grupo com sucesso!" << endl;
            //a tab_escrita foi criada para facilitar na hora de escrever no arquivo, pois é uma tabela que encaixa na função escrever_arquivo contida em uteis.cpp
            if (i == 0) {
                //essa condição foi necessária criar devido a necessidade de ter somente o nome_grupo na primeira copia
                copia_tab_string = contato_novo->nome + "; " + contato_novo->telefone + "; " + contato_novo->email + "\n";
                copia = grupo_novo->nome_grupo + "\n" + contato_novo->nome + "; " + contato_novo->telefone + "; " + contato_novo->email + "\n";
                tab_escrita[grupo_novo->nome_grupo] = copia;
                copia2 = copia;
                copia_tab_string2 = copia_tab_string;
                i++;
            } else{
                copia2 = copia2 + contato_novo->nome + "; " + contato_novo->telefone + "; " + contato_novo->email + "\n";
                tab_escrita[grupo_novo->nome_grupo] = copia2 + contato_novo->nome + "; " + contato_novo->telefone + "; " + contato_novo->email;
                copia_tab_string2 = copia_tab_string2 + contato_novo->nome + "; " + contato_novo->telefone + "; " + contato_novo->email + "\n";
            }
        }
    }
    tab_grupos[grupo_novo->nome_grupo] = grupo_novo;
    tab_escrita[grupo_novo->nome_grupo] = copia2 + "-";
    tab_grupos_str[grupo_novo->nome_grupo] = copia_tab_string2 + "-" + "\n"; //tabela feita para ser lida nas opções 6 e 7 da lista telefonica
    escrever_arquivo(arq_grupo,tab_escrita);

}

void apaga_grupo(const string & arquivo, unordered_map <string, string>& tab_grupos_str, unordered_map <string, grupo*> &tab_grupos){
    string nome_grupo_str;
    bool op = true;
    cout << "Digite o nome do grupo que deseja apagar, ou 'c' para cancelar: " << endl;

    while (op == true) {
        getline(cin,nome_grupo_str);
        if (nome_grupo_str == "c") return; //opção para cancelar o apagamento
        else if (tab_grupos.count(nome_grupo_str) <= 0) { //Se o grupo não existe, pede ao usuário para digitar um nome de grupo válido para apagar
            cout << "Grupo não existente, digite um nome de grupo válido: " << endl;
        } else op = false;
    }

//loop para achar o grupo requisitado pelo usuário para ser apagado
    for (auto & par: tab_grupos_str) {
        if (par.first == nome_grupo_str){
            tab_grupos_str[nome_grupo_str].clear();
        }
    }

   substitui_arquivo_grupo(arquivo, tab_grupos_str);

}

void listar_todos_grupos(const string & arquivo, unordered_map <string, string> &tab_grupos_str){
    cout << "\n"<< "----------------------" << "\n" << "Grupos" << "\n" << "----------------------" << endl;
    for (auto & x: tab_grupos_str) {
        cout << "|" << x.first << "|" << endl;
        cout << x.second;
    }
}

void listar_grupo_especifico(const string & arquivo, unordered_map <string, string> &tab_grupos_str){
    string nome_grupo_str;
    bool op = true;

    cout << "Digite o nome do grupo que deseja visualizar" << endl;

    while (op == true) {
        getline(cin,nome_grupo_str);
        if (tab_grupos_str.count(nome_grupo_str) <= 0) {
            cout << "Grupo não existente, digite um nome de grupo válido: " << endl;
        } else op = false;
    }

    for (auto & x: tab_grupos_str) {
        if(x.first == nome_grupo_str){
            cout << "\n" << "|" << x.first << "|" << endl;
            cout << x.second;
        }
    }

}


void le_grupos(const string & arquivo,unordered_map <string, grupo*> &tab_grupos) {
    //Função para abrir a Lista_telefonica
    string line;
    ifstream myfile (arquivo);
    list<string> l;
    unordered_map <string,contact*> tab_contatos;


    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //separa todos os elementos de Lista_de_grupo.txt
            separa_lista(line, ';', l);
        }

        //inverter a lista para ela ser lida normalmente
        l.reverse();

        for (auto it = l.begin(); it != l.end(); it++) {
            // cria um grupo dinamicamente
            grupo *grupo_novo = new grupo;

            //auto it = l.begin();
            grupo_novo->nome_grupo = *it;

            it++;

            while (*it != "-") {

                // cria um contato dinamicamente
                contact *tab_dados = new contact;


                tab_dados->nome = *it;
                it++;
                tab_dados->telefone = *it;
                it++;
                tab_dados->email = *it;
                it++;

                // acrescenta o contato à tabela
                tab_contatos[tab_dados->telefone] = tab_dados;
                tab_contatos[tab_dados->email] = tab_dados;
                tab_contatos[tab_dados->nome] = tab_dados;

                grupo_novo->tab_contatos_struct[tab_dados->telefone] = tab_dados;
                grupo_novo->tab_contatos_struct[tab_dados->email] = tab_dados;
                grupo_novo->tab_contatos_struct[tab_dados->nome] = tab_dados;
            }
            tab_grupos[grupo_novo->nome_grupo] = grupo_novo;
                if (*it == l.back()) {
                    // break;
                } 
            }


    }
    myfile.close();
}

void ordena_contato(list<contact*> lista_contatos){
    lista_contatos.sort(compara_nomes);
    lista_contatos.reverse();

    for (auto & x: lista_contatos){
        cout << endl;
        cout << "Nome: " << x->nome << endl;
        cout << "Telefone: " << x->telefone << endl;
        cout << "Email: " << x->email << endl;
    }
}
