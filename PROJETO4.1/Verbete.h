//
// Created by fran on 10/10/2019.
//

#ifndef PROJ4_VERBETE_H
#define PROJ4_VERBETE_H

#include <fstream>
#include <string>
#include "prglib.h"

using std::ifstream;
using std::string;
using prglib::lista;

struct Verbete {
    string palavra;
    string classe_gramatical;
    lista<string> significado;
};

Verbete cria_verbete(ifstream & arq);

#endif //PROJ4_VERBETE_H
