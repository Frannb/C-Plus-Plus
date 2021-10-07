#ifndef PROJETO1_PROCESSADOR_H
#define PROJETO1_PROCESSADOR_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const string arq_principal = "../Arquivo/Lista_telefonica.txt";
//const string arq_grupo = "../Arquivo/Lista_de_Grupos.txt";

struct contact {
    string nome, sobrenome, telefone, email;
    int cont;

    contact(){
        cont = 0;
    }
    contact(const string & name, int counter){
        cont = counter;
        nome = name;
    }
    bool operator<(const contact & c){
        if (cont == c.cont){
            return nome > c.nome;
        }
        return cont > c.cont;
    }
};

struct group{
    string nome_grupo;
    list<contact> lcstruct_grupo;
};

void cadastrar_contato();

void listar_grupo(list<string> &l_grupo, list<group> &lista_de_grupo);

void listar_todos_grupos(list<string> & l_grupo, list<group> & lista_de_grupo);

void listar_popularidade(list<contact> & lista_de_contato);

void pesquisa_nome(const string & nome, list<contact> & lista_de_contato);

void pesquisa_telefone(const string & telefone, list<contact> & lista_de_contato);

void pesquisa_email(const string & email, list<contact> & lista_de_contato);

void excluir_contato(const string & nome, list<string> & l_arquivo, list<contact> & lista_de_contato);

void editar_dados(const string & nome, string & op,list<string> & l_arquivo, list<contact> & lista_de_contato);

void cria_grupo(list<string> & l_cgrupo, list<group> & lista_de_grupo);

void apaga_grupo(list<string> & l_cgrupo, list<group> & lista_de_grupo);

void transforma_lista_string_em_lista_grupo(list<string> &l_a_transformar, list<group> & lista_de_grupo);

void buscar_contato(list<string> & l_cgrupo, const string & nome, contact & contato, list<contact> & l_contatos, list<string> &l_escrita);

#endif //PROJETO1_PROCESSADOR_H
