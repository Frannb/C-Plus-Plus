#include "Processador.h"
#include "Interface.h"
#include "uteis.h"

using namespace std;

void exibir_popularidade(unordered_map <string,contact*> & tab_contatos){
    cout << endl;
    unordered_set<contact*> conjunto_de_contatos;
    list<contact*> lista_de_contato;

    //Percorre a tabela e adiciona em outra tabela (unordered_set)
    for (auto & par: tab_contatos) {
        conjunto_de_contatos.insert(par.second);
    }
    //Percorre e adiciona em uma lista
    for (auto & x: conjunto_de_contatos) {
        lista_de_contato.push_back(x);
    }
    lista_de_contato.sort(compara_contatos);

    for (auto & it: lista_de_contato) {
        cout << it->nome << ": " << it->cont << endl;
    }
}

void pesquisa_nome(const string & nome, unordered_map <string,contact*> tab_contatos) {
    //Percorre a tabela de contatos para achar o telefone pesquisado
    try {
        auto & dados = tab_contatos.at(nome);
        cout << endl;
        cout << "Nome: " << dados->nome << endl;
        cout << "Telefone: " << dados->telefone << endl;
        cout << "Email: " << dados->email << endl;
        dados->cont++;
    } catch (...) {
        // contato não existe
        //cout << "Erro! Contato Inválido!";
    }
}

void pesquisa_telefone(const string & telefone, unordered_map <string,contact*> tab_contatos){
    //Percorre a tabela de contatos para achar o telefone pesquisado
    try {
        auto & dados = tab_contatos.at(telefone);
        cout << endl;
        cout << "Nome: " << dados->nome << endl;
        cout << "Telefone: " << dados->telefone << endl;
        cout << "Email: " << dados->email << endl;
        dados->cont++;
    } catch (...) {
        // contato não existe
    }
}

void pesquisa_email(const string & email, unordered_map <string,contact*> tab_contatos){
    //Percorre a tabela de contatos para achar o telefone pesquisado
    try {
        auto & dados = tab_contatos.at(email);
        cout << endl;
        cout << "Nome: " << dados->nome << endl;
        cout << "Telefone: " << dados->telefone << endl;
        cout << "Email: " << dados->email << endl;
        dados->cont++;
    } catch (...) {
        // contato não existe
    }
}

void excluir_contato(const string & nome, unordered_map <string,contact*>& tab_contatos){
    contact dados;
    //Recebe o nome do contato a ser excluido e exibe na tela
    pesquisa_nome(nome, tab_contatos);
    cout << endl;

    try {
       auto & dados = tab_contatos.at(nome);
       tab_contatos.erase(nome);
        tab_contatos.erase(dados->email);
        tab_contatos.erase(dados->telefone);
        
        delete dados; // libera a memŕoia usada pelo contato
    } catch (...) {
        // contato não existe
    }

    unordered_set<contact*> conjunto_de_contatos;
    for (auto & par: tab_contatos) {
        conjunto_de_contatos.insert(par.second);
    }
    //Adiciona ao arquivo.txt
    substitui_arquivo_tab(arq_principal, conjunto_de_contatos);
    cout << "\e[1mContato deletado!!!\e[0m" << endl;
}

void editar_dados(const string & nome,string & op, unordered_map <string,contact*> & tab_contatos){
    //Recebe o nome do contato a ser editado e exibe na tela
    pesquisa_nome(nome, tab_contatos);
    cout << endl;
    try {
        auto & dados = tab_contatos[nome];
        opcoes_editar_dados(op, dados->nome, dados->telefone, dados->email);
        tab_contatos[dados->nome] = dados;
    } catch (...) {
        // contato não existe
    }
    //Percorre a tabela de contatos e adiciona em outra tabela
    unordered_set<contact*> conjunto_de_contatos;
    for (auto & par: tab_contatos) {
        conjunto_de_contatos.insert(par.second);
    }
    //Adiciona ao arquivo.txt
    substitui_arquivo_tab(arq_principal, conjunto_de_contatos);

    cout << "\e[1mContatos editado!!!\e[0m" << endl;
}

void le_grupos_string(const string & arquivo, unordered_map <string, string> &tab_grupos_str){
    string line;
    ifstream myfile (arquivo);
    list<string> l;
    unordered_map <string,contact*> tab_contatos;
    string nome_grupo_str;


    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //separa todos os elementos de Lista_de_grupo.txt
            separa_lista(line, ';', l);
        }

        //inverter a lista para ela ser lida normalmente
        l.reverse();

        for (auto it = l.begin(); it != l.end(); it++) {
            nome_grupo_str = *it;

            it++;

            while (*it != "-") {
                tab_grupos_str[nome_grupo_str] += *it + ";";//nome
                it++;
                tab_grupos_str[nome_grupo_str] += *it + ";";//telefone
                it++;
                tab_grupos_str[nome_grupo_str] += *it + "\n";//email
                it++;
            }
            tab_grupos_str[nome_grupo_str] += "-\n";
        }
    }
    myfile.close();
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

//Ordem alfabética por nome
void exibir_contato_ordem(unordered_map<string, contact*> & tab_contatos){

    unordered_set<contact*> conjunto_de_contatos;
    list<contact*> lista_contatos;
    contact dados;
    //Adiciona a tabela na lista
    for (auto & par: tab_contatos){
        conjunto_de_contatos.insert(par.second);
    }
    //Adiciona a tabela na lista
    for (auto & t: conjunto_de_contatos){
        lista_contatos.push_back(t);
    }
    ordena_contato(lista_contatos);
}
