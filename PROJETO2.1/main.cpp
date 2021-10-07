////////////////////////////////////////////
//      Criado por: Francin Barcelos      //
//      Disciplina: Programação II        //
////////////////////////////////////////////

#include <iostream>
#include "Proj2.h"
#include "prglib.h"

using namespace::std;
using prglib::lista;

int main() {

    char opcao;
    Proj2 proj2;

    for(;;){
        lista<string> resposta;
        cout << endl << endl
             << "Escolha uma opção: " << endl << endl
             << "1 - Filmes em que um ator atuou" << endl
             << "2 - Atores que atuaram em um determinado filme" << endl
             << "3 - Atores que trabalharam com um determinado ator" << endl
             << "4 - Lista de atores pela quantidade de filmes" << endl
             << "5 - Lista de atores pela quantidade de filmes com determinado ator" << endl
             << "0 - Sair" << endl;


        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao){

            case '1':{
                string ator;
                cout << "Digite o ator: ";
                getline(cin, ator);
                resposta = proj2.filmesDeUmAtor(ator);
                if(resposta.comprimento()>0) {
                    resposta.escrevaSe(cout, ",");
                }else {
                    cout << "Ator não está presente!";
                }
            }
                break;
            case '2':{
                string filme;
                cout << "Digite o filme: ";
                getline(cin,filme);
                resposta = proj2.atoresDeUmFilme(filme);
                if(resposta.comprimento()>0) {
                    resposta.escrevaSe(cout, ",");
                }else {
                    cout << "Filme não está presente!";
                }
            }
                break;
            case '3':{
                string ator;
                cout << "Digite o ator: ";
                getline(cin, ator);
                resposta = proj2.atoresAtuaramComAtor(ator);
                if(resposta.comprimento()>0) {
                    resposta.escrevaSe(cout, ",");
                }else {
                    cout << "Ator não está presente!";
                }
            }
                break;
            case '4':{
                resposta = proj2.atoresPorNumDeFilmes();
                resposta.escrevaSe(cout,",");
            }
                break;
            case '5':{
                string ator;
                cout << "Digite o ator: ";
                getline(cin, ator);
                resposta = proj2.atoresPorNumDeFilmesComAtor(ator);
                if(resposta.comprimento()>0) {
                    resposta.escrevaSe(cout, ",");
                }else {
                    cout << "Ator não está presente!";
                }
            }
                break;
            case '0':
                return 0;
            default:
                cout << "Opção inválida!" << endl << endl;
                break;
        }

    }
}
