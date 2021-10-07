#ifndef PROJETO1_PROCESSADOR_H
#define PROJETO1_PROCESSADOR_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const string arq_principal = "../Arquivo/Lista_telefonica.txt";
//const string arq_grupo = "../Arquivo/Lista_de_Grupos.txt";

struct contact : public error_code {
    string nome, telefone, email;
    int cont;

};
/*
struct group{
    string nome_grupo;
    list<contact> lcstruct_grupo;
};*/

//void listar_grupo(list<string> &l_grupo, list<group> &lista_de_grupo);

//void listar_todos_grupos(list<string> & l_grupo, list<group> & lista_de_grupo);

void exibir_popularidade(unordered_map <string,contact*> & tab_contatos);

void pesquisa_nome(const string & nome, unordered_map <string,contact*> tab_contatos);

void pesquisa_telefone(const string & telefone, unordered_map <string,contact*> tab_contatos);

void pesquisa_email(const string & email, unordered_map <string,contact*> tab_contatos);

void excluir_contato(const string & nome, unordered_map <string,contact*> & tab_contatos);

void editar_dados(const string & nome, string & op, unordered_map <string,contact*> & tab_contatos);

//void cria_grupo(unordered_map <string,group> & tab_cgrupo, unordered_map <string,group> & tab_de_grupo);

//void apaga_grupo(list<string> & l_cgrupo, list<group> & lista_de_grupo);

//void transforma_lista_string_em_lista_grupo(list<string> &l_a_transformar, list<group> & lista_de_grupo);

//void buscar_contato(list<string> & l_cgrupo, const string & nome, contact & contato, list<contact> & l_contatos, list<string> &l_escrita);


#endif //PROJETO1_PROCESSADOR_H
