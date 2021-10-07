///////////////////////////////////////////////////////
//   Criado por: Francin Barcelos e Guilherme Jose   //
//   Data: 22/09/2020                                //
//   Disciplina: Programação II                      //
///////////////////////////////////////////////////////

#include "proj3.h"

int main() {
   // sort ip_localizacao2.txt  > x;
    string ip;
    auto arvore_ip = *le_arquivo(ip_Localizacao2);

    //for (;;) {
      while (true){
        cout << ("=================================================") << endl;
        cout << ("                 Geo-Localizador                 ") << endl;
        cout << ("=================================================") << endl;
        cout << ("Digite o IP a ser localizado: ");
        cin >> ip;
        //cin.ignore();
        if (ip.empty()) break;
        cout << endl;

        //função para transformar o IP que o usuário digitou de string para geoname_ip
        geoname_ip dado = transforma_ip_em_geoname_ip(ip);

        //obtem x que vai ser o nodo da árvore contendo o geoname_ip procurado pelo usuário
        try {
            auto &x = arvore_ip.obtem(dado);
            cout << "Local do IP digitado: " << x.local << endl;
        } catch (...) {
            cout << "IP não localizado!!!" << endl;
        }
        cout << endl;
    }
}
