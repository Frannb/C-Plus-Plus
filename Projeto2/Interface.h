#ifndef PROJETO1_INTERFACE_H
#define PROJETO1_INTERFACE_H

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include "Processador.h"

using namespace std;

void menu_principal();

void submenu_pes(unordered_map <string,contact*>& tab_contatos);

void submenu_alt(unordered_map <string,contact*>& tab_contatos);

void pesquisar_contato(int sop, unordered_map <string,contact*> & tab_contatos);

int alterar_contato(const int & sop, unordered_map <string,contact*>& tab_contatos);

void op_editar_dados(const string & op, string & N, string & T, string & E);

void cadastrar_contato();

void exibir_contato_ordem(unordered_map<string, contact*> & tab_contatos);

void le_contatos(const string & arquivo, unordered_map<string, contact*> & tab_contatos);

#endif