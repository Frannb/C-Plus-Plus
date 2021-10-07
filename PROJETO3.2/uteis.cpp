#include "uteis.h"

using std::string;
using std::list;

void separa(const string& algo, char sep, list<string> & l) {
    //Função para separar a Lista_telefonica
    int p1 = 0, p2 = 0; string aux;
    while(true){
        p1 = algo.find_first_not_of(sep,p2); if(p1 == string::npos) break;
        p2 = algo.find_first_of(sep, p1);
        aux = algo.substr(p1, p2-p1);
        l.push_front(aux); if(p2 == string::npos) break;
    }
}