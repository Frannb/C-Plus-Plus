#ifndef PROJETO1_PROJ3_H
#define PROJETO1_PROJ3_H

#include "prglib.h"
#include <string>
#include "uteis.h"
#include "iostream"
#include "fstream"
#include <arpa/inet.h>

using prglib::arvore;
using namespace std;

const string ip_Localizacao = "../Arquivo/ip_localizacao.txt";
const string ip_Localizacao2 = "../Arquivo/ip_localizacao2.txt";

struct geoname_ip {
    //inteiro unsigned
    uint32_t primeiro, ultimo;
    string local;
    //uint32_t mascara;


    //geoname_ip() {

    //}
    // aqui você extrai os valores da linha
    // e calcula o primeiro e ultimo endereço deste bloco
    //geoname_ip(const string & linha, arvore<geoname_ip> *arvore_ip) {
    //}
    bool operator==(const geoname_ip & outro) const {
    // retorna true se primeiro endereço do outro bloco for maior ou igual
    // ao primeiro endereço deste bloco E se ultimo endereço do outro bloco
    // for menor ou igual ao primeiro endereço deste bloco
    // OU vice-versa !!!
//        if ((outro.primeiro >= primeiro && outro.ultimo <= ultimo) ||( primeiro >= outro.primeiro && ultimo <= outro.ultimo)){
//            return true;
//        }

          return (outro.primeiro >= primeiro && outro.ultimo <= ultimo) || (primeiro >= outro.primeiro && ultimo <= outro.ultimo);

       // }
//       if (outro.primeiro >= primeiro && outro.ultimo <= primeiro){
//           return true;
//       }
    }

    bool operator<(const geoname_ip & outro) const {
        // retorna true se ultimo endereço deste bloco for menor que
        // primeiro endereço do outro bloco

            return ultimo < outro.primeiro;
    }   // exemplo de uso

};

arvore<geoname_ip> *le_arquivo(const string & nome_arquivo);

geoname_ip cria_geoname_ip(const string & linha);

string verifica_ip_arvore(const string & ip);

uint32_t getip(const string & ip);

geoname_ip transforma_ip_em_geoname_ip(const string & ip);

#endif //PROJETO1_PROJ3_H
