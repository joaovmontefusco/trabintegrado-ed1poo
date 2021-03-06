#include "corretor.h"
#include <string>

using namespace std;

Corretor::~Corretor(){
// o que colocar aqui?
}

void Corretor::verificarTexto(){
    list<Palavra> :: iterator temp;
    temp = text.getPrimeiro();
    while(!text.ultimo(temp)){
        if(!dic.consulta(text.getPalavra(temp))){
            erros.push_front(text.getPalavra(temp));
        }
        advance(temp, 1);
    }
}

bool Corretor::getErros(){
    return (!erros.empty());
}

void Corretor::exibeErros(){
    list<Palavra> :: iterator temp;
    for(temp = erros.begin(); temp != erros.end(); temp++){
        cout << temp->getWord() << endl;
    }
}

void Corretor::corrigirPalavra(string a, Palavra b){
    Palavra nova(a);
    text.alterarPalavra(a, b);
}

Palavra Corretor::erroAtual(){
    return *it;
}

void Corretor::adicionarEx(Palavra a){
    dic.inserirPalavra(a);
}

bool Corretor::errosFim(){
    if(it == erros.end())
        return true;
    else
        return false;
}

void Corretor::errosProx(){
    advance(it, 1);
}
