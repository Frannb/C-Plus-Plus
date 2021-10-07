#ifndef PROJETO2_PROJ2_H
#define PROJETO2_PROJ2_H

#include "prglib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using prglib::lista;
using namespace std;

//criado uma estrutura para o filme ano, e uma lista de atores
struct estrutura{
    string filme;
    int ano;
    lista<string> atores;
};
//criado uma estrutura para ator, e quantidade de filmes
struct numAtor{
    string ator;
    int filmes;
};

class Proj2 {
private:
    estrutura dados;
    lista<estrutura> arq;
public:

    Proj2();

    lista<string> filmesDeUmAtor(const string& ator);

    lista<string> atoresDeUmFilme(const string& filme);

    lista<string> atoresAtuaramComAtor(const string& ator);

    lista<string> atoresPorNumDeFilmes();

    lista<string> atoresPorNumDeFilmesComAtor(const string& ator);

};

#endif //PROJETO2_PROJ2_H
