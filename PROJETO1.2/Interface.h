#ifndef PROJETO1_INTERFACE_H
#define PROJETO1_INTERFACE_H

#include <iostream>
#include <list>
#include <string>
#include <stack>
#include "Processador.h"

using namespace std;

void menu_principal(const string &s_menu);

void submenu_pes(const string &p_submenu, list<contact> & lista_de_contato);

void submenu_alt(const string &a_submenu, list<string> & l_arquivo, list<contact> & lista_de_contato);

int pesquisar_contato(const int & sop, list<contact> & lista_de_contato);

int alterar_contato(const int & sop, list<string> & l_arquivo, list<contact> & lista_de_contato);

void op_editar_dados(const string & op, string & N, string & T, string & E);

void cadastrar_contato();

void listar_contato_ordem(list<contact> & lista_de_contato);

#endif