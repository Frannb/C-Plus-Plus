#ifndef PROJETO1_UTEIS_H
#define PROJETO1_UTEIS_H

#include <string>
#include <unordered_map>
#include "Processador.h"

using namespace std;

void escrever_arquivo(string arq, unordered_map<string, string> tab_armazena);

void substitui_arquivo_tab(const string& arq, unordered_set<contact*> tab_armazena);

void substitui_arquivo_lista(const string& arq, list<contact*> & l_armazena);

void separa_lista(const string& algo, char sep, list<string> & l);

//void escrever_arquivo_grupo(list<string> & l_armazena_grupo);

bool compara_contatos(const contact * c1, const contact * c2);

#endif //PROJETO1_UTEIS_H
