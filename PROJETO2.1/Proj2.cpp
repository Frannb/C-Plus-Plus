////////////////////////////////////////////
//      Criado por: Francin Barcelos      //
//      Disciplina: Programação II        //
////////////////////////////////////////////

#include "Proj2.h"

Proj2::Proj2(){

    string line;
    int i;
    // abri o arquivo
    ifstream myfile("../projeto2_20192.txt");

    if (myfile.is_open())
    {

        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line);

            // procura o primeiro ';' para pegar o filme
            i = line.find_first_of(';');
            dados.filme = line.substr(0, i);
            //apaga ate depois do primeiro ';'
            line.erase(0, i+1);
            //pega o segundo dado ';' para pegar o ano
            i = line.find_first_of(';');
            try {
                dados.ano = std::stoi(line.substr(0, i));
            }catch (...){
                dados.ano = 0;
            }


            //apaga ate depois do segundo ';'
            line.erase(0, i + 1);
            dados.atores.esvazia();

            while(line.size()>0){
                // busca a primeira ',' da string e armazena o ator
                i = line.find_first_of(',');
                // se não tem mais ',', anexa o restante da string
                if(i==string::npos){
                    dados.atores.anexa(line);
                    break;
                }else {
                    dados.atores.anexa(line.substr(0, i));
                    line.erase(0, i + 1);
                }
            }
            arq.anexa(dados);
        }
        myfile.close();

    }
}

// Opção 1 - Busca filmes do ator
lista<string> Proj2::filmesDeUmAtor(const string& ator) {
    lista<estrutura> filmes;
    lista<string> retornaFilmes;

    arq.inicia();
    //Vai pegando o proximo ator até o fim
    while (!arq.fim()) {
        string verificaAtor;
        dados = arq.proximo();

        try{
            verificaAtor = dados.atores.procura(ator);
        }catch(...){}
        //Se o ator for igual ao ator verificado, percorre a lista e anexa os filmes.
        if (ator == verificaAtor) {

            int j = filmes.comprimento();

            for (int i = 0; i <= j; ++i) {

                if(i == filmes.comprimento()){
                    filmes.anexa(dados);

                //Caso contrário pega o proximo, compara o ano e insere na lista.
                } else {
                    estrutura verificaAno = filmes.obtem(i);
                    if (verificaAno.ano < dados.ano) {
                        filmes.insere(dados, i);
                        break;
                    }

                }

            }

        }

    }
    // Pega os 10 primeiros filmes
    filmes.inicia();
    while(!filmes.fim()){
        estrutura filme = filmes.proximo();
        retornaFilmes.anexa(filme.filme);
    }
    return retornaFilmes;
}

//Opção 2 - Busca atores de um filme
lista<string> Proj2::atoresDeUmFilme(const string& filme){

    lista<string> retornaAtores;

    arq.inicia();
    while(!arq.fim()){
        dados = arq.proximo();

        //Se o filme for o filme buscado, retorna os atores do filme
        if(dados.filme == filme){
            retornaAtores = dados.atores;
            break;
        }

    }

    retornaAtores.ordena();

    return retornaAtores;

}

//Opção 3 - Busca atores que atuaram com um determinado ator
lista<string> Proj2::atoresAtuaramComAtor(const string& ator){

    lista<string> retornaAtores;
    arq.inicia();
    while(!arq.fim()){
        dados = arq.proximo();

        string verificaAtor;
        try{
            //Procura o ator na lista de atores da estrutura
            verificaAtor = dados.atores.procura(ator);
        }catch(...){}
        //Se ator procurado for ator, inicia a interação
        if(verificaAtor == ator){

            dados.atores.inicia();

            while(!dados.atores.fim()){
                string outroAtor = dados.atores.proximo();

                // Se o proximo ator for diferente do ator, procura o outro ator na lista
                if(outroAtor != ator){
                    string verificaOutroAtor;
                    try{
                        verificaOutroAtor = retornaAtores.procura(outroAtor);
                    }catch(...){}

                    if(outroAtor != verificaOutroAtor) {
                        retornaAtores.anexa(outroAtor);
                    }

                }

            }

        }

    }

    retornaAtores.ordena();

    return retornaAtores;

}

// Opção 4 - Lista de atores pela quantidade de filmes
lista<string> Proj2::atoresPorNumDeFilmes(){
    lista<string> atoresArq;
    lista<string> separaAtores;
    lista<numAtor> atores;
    lista<numAtor> ordenaAtores;
    lista<string> retornaAtores;
    numAtor atorStruct;

    arq.inicia();
    while(!arq.fim()) {
        dados = arq.proximo();

        dados.atores.inicia();
        while (!dados.atores.fim()) {
            string ator = dados.atores.proximo();

            atoresArq.anexa(ator);
        }
    }

    //Enquanto lista não for vazia, pega o ator da primeira posição e coloca na struct ator
    while(!atoresArq.vazia()){
        atorStruct.ator = atoresArq.obtem(0);
        atoresArq.procuraMuitos(atorStruct.ator, separaAtores);
        //O comprimento da lista, será a quantidade de filmes do ator
        atorStruct.filmes = separaAtores.comprimento();
        //Remove os atores da lista. E depois insere na lista de struct para ordenar
        atoresArq.retira(atorStruct.ator);
        atores.insere(atorStruct);
    }

    //Verifica a quantidade de filmes, para  ordenador do maior ao menor
    for (int k = 0; k < atores.comprimento(); ++k) {
        numAtor filmes = atores.obtem(k);

        int j = ordenaAtores.comprimento();
        for (int l = 0; l <= j; ++l) {
            if(l==ordenaAtores.comprimento()) {
                ordenaAtores.anexa(filmes);
            }else {
                //Verifica se as struct anteriores da lista tem menos filmes
                numAtor verificaFilmes = atores.obtem(l);

                if (verificaFilmes.filmes < filmes.filmes) {
                    ordenaAtores.insere(filmes, l);
                    break;
                }

            }

        }

    }


    ordenaAtores.inicia();
    for(int i=0; i<10; i++) {
        atorStruct = ordenaAtores.proximo();
        //Lista o número de filmes e o ator
        cout << atorStruct.filmes << " - " << atorStruct.ator << endl;
        retornaAtores.anexa(atorStruct.ator);
    }

    return retornaAtores;
}

//Opção 5 - Lista de atores pela quantidade de filmes com determinado ator
lista<string> Proj2::atoresPorNumDeFilmesComAtor(const string& ator){

    lista<numAtor> atores;
    lista<numAtor> ordenaAtores;
    lista<string> retornaAtores;
    numAtor atorStruct;

    arq.inicia();
    while(!arq.fim()){
        dados = arq.proximo();

        string verificaAtor;
        try {
            verificaAtor = dados.atores.procura(ator);
        }catch (...){}

        // Se ator verificado for igual ator, inicia a interação
        if (verificaAtor == ator) {
            dados.atores.inicia();

            while(!dados.atores.fim()) {
                string outroAtor = dados.atores.proximo();

                //Se o outroAtor for diferente do ator, e o comprimeto da lista for 0, anexa struct na lista
                if(outroAtor != ator) {
                    if (atores.comprimento() == 0) {
                        atorStruct.ator = outroAtor;
                        atorStruct.filmes = 1;
                        atores.anexa(atorStruct);
                        // Caso contrario percorre a lista para ver se o ator já está nela
                    } else {
                        atores.inicia();
                        int k = 0;
                        int j = 0;
                        while (!atores.fim()) {

                            atorStruct = atores.proximo();

                            j++;

                            if (outroAtor == atorStruct.ator) {
                                atores.remove(j-1);
                                j--;
                                atorStruct.filmes = atorStruct.filmes + 1;
                                atores.anexa(atorStruct);
                                k++;
                            }

                        }
                        // Se o ator não estiver na lista, k = 0 e anexa
                        if (k == 0) {
                            atorStruct.ator = outroAtor;
                            atorStruct.filmes = 1;
                            atores.anexa(atorStruct);
                        }

                    }

                }

            }

        }

    }
    //Verifica a quantidade de filmes, para  ordenador do maior ao menor
    for (int k = 0; k < atores.comprimento(); ++k) {
        numAtor filmes = atores.obtem(k);

        int j = ordenaAtores.comprimento();
        //
        for (int l = 0; l <= j; ++l) {
            if(l==ordenaAtores.comprimento()) {
                ordenaAtores.anexa(filmes);
            }else {
                //Verifica se as struct anteriores da lista tem menos filmes
                numAtor verificaFilmes = atores.obtem(l);

                if (verificaFilmes.filmes < filmes.filmes) {
                    ordenaAtores.insere(filmes, l);
                    break;
                }

            }

        }

    }


    ordenaAtores.inicia();
    for(int i=0; i<10; i++) {
        atorStruct = ordenaAtores.proximo();
        //Lista o número de filmes e o ator
        //cout << atorStruct.filmes << " - " << atorStruct.ator << endl;
        retornaAtores.anexa(atorStruct.ator);
    }
    return retornaAtores;
}