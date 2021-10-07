////////////////////////////////////////////
//      Criado por: Francin Barcelos      //
//      Disciplina: Programação II        //
////////////////////////////////////////////

#ifndef PROJ3_PROJ3_H
#define	PROJ3_PROJ3_H

#include "prglib.h"
#include <iostream>
#include <fstream>
#include <string>

using prglib::lista;
using prglib::thash;
using namespace std;

struct estrutura{
    int ano;
    lista<string> atores;
};

struct anoFilme{
    string filme;
    int ano;
};

class Proj3 {
private:

    thash<estrutura> arq;
public:

    Proj3();

    lista<string> filmesDeUmAtor(const string& ator);

    lista<string> atoresDeUmFilme(const string& filme);

    lista<string> atoresAtuaramComAtor(const string& ator);

    lista<string> atoresPorNumDeFilmes();

    lista<string> atoresPorNumDeFilmesComAtor(const string& ator);
};

#endif //PROJ3_PROJ3_H
