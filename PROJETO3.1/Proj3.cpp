////////////////////////////////////////////
//      Criado por: Francin Barcelos      //
//      Disciplina: Programação II        //
////////////////////////////////////////////

#include "Proj3.h"

Proj3::Proj3() :arq(997) {

    string line, filme;
    string arquivo;
    int i;
    cout << "Digite o caminho do arquivo .txt: " << endl;
    cin >> arquivo;

    // abri o arquivo
    ifstream myfile(arquivo);

    //ifstream myfile("../projeto3_20192.txt");

    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            estrutura dados;
            //cout << line << endl;

            i = line.find_first_of(';');
            filme = line.substr(0, i);
            line.erase(0, i+1);
            i = line.find_first_of(';');
            try {
                //stoi converte string para inteiro
                dados.ano = stoi(line.substr(0, i));
            }catch (...){
                dados.ano = 0;
            }
            line.erase(0, i + 1);

            while(line.size()>0){
                // busca a primeira , e percorre armazenando os atores
                i = line.find_first_of(',');
                if(i==string::npos){
                    dados.atores.anexa(line);
                    break;
                }else {
                    dados.atores.anexa(line.substr(0, i));
                    line.erase(0, i + 1);
                }
            }
            dados.atores.ordena();
            arq.adiciona(filme, dados);
        }
        myfile.close();
    }
}
//opção 1 - busca filmes do ator
lista<string> Proj3::filmesDeUmAtor(const string& ator) {

    //lista de ponteiro para as chaves do arquivo
    auto filmes = arq.chaves();
    lista<anoFilme> filmesDoAtor;
    anoFilme filmeLista;
    lista<string> retornaFilmes;

    filmes->inicia();
    //Obtem o proximo filme
    while(!filmes->fim()) {
        string verificaAtor;
        string proxFilme = filmes->proximo(); //proximo não quer retornar string, e sim lista de char
        //Obtem os atores do filme
        estrutura dados = arq.obtem(proxFilme);

        //Verifica os atores do filme para ver se tem o ator
        try {
            verificaAtor = dados.atores.procura(ator);
        } catch (...){}

        //Se tem o ator, anexa o filme a lista dos filmes do ator
        if (ator == verificaAtor) {
            filmeLista.ano = dados.ano;
            filmeLista.filme = proxFilme;
            int j = filmesDoAtor.comprimento();

            for (int i = 0; i <= j; ++i) {

                if(i == filmesDoAtor.comprimento()){
                    filmesDoAtor.anexa(filmeLista);

                    //Caso contrário pega o proximo, compara o ano e insere na lista.
                } else {
                    anoFilme verificaAno = filmesDoAtor.obtem(i);
                    if (verificaAno.ano < filmeLista.ano) {
                        filmesDoAtor.insere(filmeLista, i);
                        break;
                    }
                }
            }
        }
    }

    filmesDoAtor.inicia();
    while(!filmesDoAtor.fim()){
        anoFilme filme = filmesDoAtor.proximo();
        retornaFilmes.anexa(filme.filme);
    }
    return retornaFilmes;
}

//opção 2 - busca atores de um filme
lista<string> Proj3::atoresDeUmFilme(const string& filme){
    estrutura dados;

    //Verifica se o filmes está no arquivo, se estiver obtem a lista de atores do filme em ordem alfabetica
    if(arq.existe(filme)){
        dados = arq.obtem(filme);
    }

    return dados.atores;

}

//opção 3 - busca atores que atuaram com um determinado ator
lista<string> Proj3::atoresAtuaramComAtor(const string& ator){
    estrutura dados;
    lista<string> retornaAtores;
    auto filmes = arq.chaves();

    filmes->inicia();
    while(!filmes->fim()){
        dados = arq.obtem(filmes->proximo());

        //verifica se ator está na lista dos atores do filme
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
//opção 4 - Lista de atores pela quantidade de filmes
lista<string> Proj3::atoresPorNumDeFilmes(){
    estrutura dados;
    thash<int> atoresArq(97);
    lista<string> retornaAtores;
    auto filmes = arq.chaves();

    filmes->inicia();
    // Pega o proximo filme
    while(!filmes->fim()) {
        dados = arq.obtem(filmes->proximo());

        dados.atores.inicia();
        // pega os atores da estrutura, verifica se tem na tabela, caso não tenha adiciona na tabela
        while (!dados.atores.fim()) {
            string ator = dados.atores.proximo();

            if(atoresArq.existe(ator)){
                atoresArq[ator]++;
            }
            else{
                atoresArq.adiciona(ator, 1);
            }
        }
    }

    auto atores = atoresArq.chaves();

    atores->inicia();
    //Enquanto não chegar ao fim da tabela de atores
    while(!atores->fim()) {
        string ator = atores->proximo();
        int j = retornaAtores.comprimento();

        for (int i=0; i <= j; i++) {
           //Cria uma lista de atores e ordena pela quantidade de filme
            if(i==retornaAtores.comprimento()){
                retornaAtores.anexa(ator);
            }else {
                string verificaAtor = retornaAtores.obtem(i);

                if (atoresArq.obtem(ator) > atoresArq.obtem(verificaAtor)) {
                    retornaAtores.insere(ator, i);
                    break;
                }

            }

        }

    }

    return retornaAtores;

}


//opção 5 - Lista de atores pela quantidade de filmes com determinado ator
lista<string> Proj3::atoresPorNumDeFilmesComAtor(const string& ator){

    estrutura dados;
    thash<int> atoresArq(97);
    lista<string> retornaAtores;
    auto filmes = arq.chaves();

    filmes->inicia();
    while(!filmes->fim()) {
        dados = arq.obtem(filmes->proximo());
        string verificaAtor;

        try{
            verificaAtor = dados.atores.procura(ator);
        }catch(...){}

        if(verificaAtor == ator){
            dados.atores.inicia();
            // pega os atores da estrutura, verifica se tem na tabela, caso não tenha adiciona na tabela
            while (!dados.atores.fim()) {
                string outroAtor = dados.atores.proximo();

                if(outroAtor != ator){
                    if(atoresArq.existe(ator)){
                        atoresArq[outroAtor]++;
                    }
                    else{
                        atoresArq.adiciona(outroAtor, 1);
                    }
                }
            }
        }
    }

    auto atores = atoresArq.chaves();

    atores->inicia();
    while(!atores->fim()) {
        string ordenaAtor = atores->proximo();
        int j = retornaAtores.comprimento();

        for (int i=0; i <= j; i++) {
            //Cria uma lista de atores e ordena pela quantidade de filme
            if(i==retornaAtores.comprimento()){
                retornaAtores.anexa(ordenaAtor);
            }else {
                string verificaAtor = retornaAtores.obtem(i);

                if (atoresArq.obtem(ordenaAtor) > atoresArq.obtem(verificaAtor)) {
                    retornaAtores.insere(ordenaAtor, i);
                    break;
                }

            }

        }

    }
    return retornaAtores;

}