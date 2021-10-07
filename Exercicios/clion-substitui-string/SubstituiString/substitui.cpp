// Escrito por: Francin Barcelos
// Data: 08/08/19

// Escreva uma função que procure uma substring dentro de uma string, e a substitua por outra string (projeto CLion).
// Por exemplo, se a string for correr, e a substring a ser procurada for rre for subsituída por pia,
// o resultado deve ser copiar. Essa função deve ser declarada assim:

#include "substitui.h"

string substitui(string texto, string sub, string outra) {
    int pos;
    pos = texto.find(sub);
    if (pos == string::npos)
        return texto;

    return texto.replace(pos, sub.size(), outra);



}