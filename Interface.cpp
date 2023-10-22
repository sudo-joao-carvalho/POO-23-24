//
// Created by João Carvalho on 21/10/2023.
//

#include "Interface.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Interface::Interface() {
    cout << "Sistema de Controlo de Habitaçao Iniciado" << endl;
}

Interface::~Interface(){
    delete habitacao;
}

void Interface::menu() {

    string linha;

    do{
        cout << "[ COMANDOS ]" << endl;
        cout << "Insira um comando: " << endl;
        getline(cin, linha);

        if(!comandos(linha)){
            cout << "[ ERRO ] Comando nao existe." << endl;
            cout << "Insira um comando: " << endl;
            getline(cin, linha);
        }

    }while(linha != "sair");

}

bool Interface::comandos(const string& comando){

    string primeiro;
    istringstream iss(comando);
    iss >> primeiro;

    // TODO adaptar para as fases

    //tempo
    if(primeiro == "prox"){
        comandoProx();
        return true;
    }

    if(primeiro == "avanca"){
        comandoAvanca(iss);
        return true;
    }

    //gerir habitacao e zonas
    if(primeiro == "hnova"){
        comandoHnova(iss);
        return true;
    }

    if(primeiro == "hrem"){
        comandoHrem();
        return true;
    }

    if(primeiro == "znova"){
        comandoZnova(iss);
        return true;
    }

    if(primeiro == "zrem"){
        comandoZrem(iss);
        return true;
    }

    if(primeiro == "zlista"){
        comandoZlista();
        return true;
    }

    //gerir zonas e o seu conteudo
    if(primeiro == "zcomp"){
        comandoZcomp(iss);
        return true;
    }

    if(primeiro == "zprops"){
        comandoZprops(iss);
        return true;
    }

    if(primeiro == "pmod"){
        comandoPmod(iss);
        return true;
    }

    if(primeiro == "cnovo"){
        comandoCnovo(iss);
        return true;
    }

    if(primeiro == "crem"){
        comandoCrem(iss);
        return true;
    }

    //processador de regras
    if(primeiro == "rnova"){
        comandoRnova(iss);
        return true;
    }

    if(primeiro == "pmuda"){
        comandoPmuda(iss);
        return true;
    }

    if(primeiro == "rlista"){
        comandoRlista(iss);
        return true;
    }

    if(primeiro == "rrem"){
        comandoRrem(iss);
        return true;
    }

    if(primeiro == "asoc"){
        comandoAsoc(iss);
        return true;
    }

    if(primeiro == "ades"){
        comandoAdes(iss);
        return true;
    }

    if(primeiro == "acom"){
        comandoAcom(iss);
        return true;
    }

    //salvar/recuperar processador de regras
    if(primeiro == "psalva"){
        comandoPsalva(iss);
        return true;
    }

    if(primeiro == "prepoe"){
        comandoPrepoe(iss);
        return true;
    }

    if(primeiro == "prem"){
        comandoPrem(iss);
        return true;
    }

    if(primeiro == "plista"){
        comandoPlista();
        return true;
    }

    //gerais
    if(primeiro == "exec"){
        comandoExec(iss);
        return true;
    }

    if(primeiro == "sair"){
        comandoSair();
        return true;
    }

    return false;
}

void Interface::comandoProx() {
    cout << "Comando PROX em execucao" << endl;
}

void Interface::comandoAvanca(istringstream &iss) {

    int passos;
    iss >> passos;

    // TODO AVANCAR
    cout << "Avancou " << passos << " passos" << endl;

}

void Interface::comandoHnova(istringstream &iss) {

    int nLinhas, nColunas;
    iss >> nLinhas >> nColunas;

    if(nLinhas < 2 || nLinhas > 4){
        cout << "[ ERRO ] Numero de linhas tem que estar compreendido entre 2 e 4" << endl;
        return;
    }

    if(nColunas < 2 || nColunas > 4){
        cout << "[ ERRO ] Numero de colunas tem que estar compreendido entre 2 e 4" << endl;
        return;
    }

    // TODO fazer verificaçao se os numeros indicados esta disponivel para a grelha indicada pelo utilizador
    if(iss.fail()){
        cout << "[ ERRO ] Insira argumentos validos: hnova <num_linhas> <num_colunas>" << endl;
        return;
    }

    // Cria habitacao
    if(habitacao != nullptr) // esta verificaçao serve para o caso de ja existir uma habitacao e eu querer criar uma nova habitacao (talvez mudar para o codigo da classe habitacao)
        delete habitacao;
    else
        this->habitacao = new Habitacao(nLinhas, nColunas);

    if(this->habitacao != nullptr){
        cout << "[ HNOVA ] Comando executado com sucesso" << endl;
    }
}

void Interface::comandoHrem() {
    cout << "Comando HREM em execucao" << endl;
}

void Interface::comandoZnova(istringstream &iss) {

    int linha, coluna;
    iss >> linha >> coluna;

    // TODO fazer verificaçao se os numeros indicados esta disponivel para a grelha indicada pelo utilizador
    if(iss.fail()){
        cout << "[ ERRO ] Insira argumentos validos: znova <linhas> <coluna>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ZNOVA em execucao" << endl;
}

void Interface::comandoZrem(istringstream &iss) {

    int idZona;
    iss >> idZona;

    // TODO verificar se o id da zona existe
    if(cin.fail()){
        cout << "[ ERRO ] Insira um id de zona existente: zrem <IDzona>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ZREM em execucao" << endl;

}

void Interface::comandoZlista() {
    cout << "Comando ZLISTA em execucao" << endl;
}

void Interface::comandoZcomp(istringstream &iss) {

    int idZona;
    iss >> idZona;

    // TODO verificar se o id da zona existe
    if(cin.fail()){
        cout << "[ ERRO ] Insira um id de zona existente: zcomp <IDzona>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ZCOMP em execucao" << endl;
}

void Interface::comandoZprops(istringstream &iss) {

    int idZona;
    iss >> idZona;

    // TODO verificar se o id da zona existe
    if(cin.fail()){
        cout << "[ ERRO ] Insira um id de zona existente: zprops <IDzona>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ZPROPS em execucao" << endl;
}

void Interface::comandoPmod(istringstream &iss) {

    int idZona;
    iss >> idZona;
    string nome;
    iss >> nome;
    int valor;
    iss >> valor;

    // TODO verificar argumentos
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: pmod <IDzona> <nome> <valor>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando PMOD em execucao" << endl;

}

void Interface::comandoCnovo(istringstream &iss) {

    int idZona;
    iss >> idZona;
    char instrumento;
    iss >> instrumento;
    string tipoOuComando;
    iss >> tipoOuComando;

    // TODO verificar argumentos
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: cnovo <IDzona> < s | p | a > < tipo | comando >" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando CNOVO em execucao" << endl;
}

void Interface::comandoCrem(istringstream &iss) {

    int idZona;
    iss >> idZona;
    char instrumento;
    iss >> instrumento;
    int idComponente;
    iss >> idComponente;

    // TODO verificar argumentos
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: crem <IDzona> < s | p | a > < IDcomponente >" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando CREM em execucao" << endl;

}

void Interface::comandoRnova(istringstream &iss) {

    int idZona, idProcRegra, idSensor;
    string regra;
    vector<int> params;

    iss >> idZona >> idProcRegra >> regra >> idSensor;

    int aux;
    while(iss >> aux){
        params.push_back(aux);
    }

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: rnova <IDzona> <ID proc. regras> <regra> <IDsensor> [param1] [param2]" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando RNOVA em execucao" << endl;

}

void Interface::comandoPmuda(istringstream &iss) {

    int idZona, idProcRegra;
    string novoComando;
    iss >> idZona >> idProcRegra >> novoComando;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: pmuda <IDzona> <ID proc. regras> <novo comando>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando PMUDA em execucao" << endl;
}

void Interface::comandoRlista(istringstream &iss) {

    int idZona, idProcRegra;
    iss >> idZona >> idProcRegra;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: rlista <IDzona> <ID proc. regras>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando RLISTA em execucao" << endl;
}

void Interface::comandoRrem(istringstream &iss) {

    int idZona, idProcRegra, idRegra;
    iss >> idZona >> idProcRegra >> idRegra;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: rrem <IDzona> <ID proc. regras> <ID regra>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando RREM em execucao" << endl;
}

void Interface::comandoAsoc(istringstream &iss) {

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: asoc <IDzona> <ID proc. regras> <ID aparelho>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ASOC em execucao" << endl;

}

void Interface::comandoAdes(istringstream &iss) {

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: ades <IDzona> <ID proc. regras> <ID aparelho>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ADES em execucao" << endl;

}

void Interface::comandoAcom(istringstream &iss) {

    int idZona, idAparelho;
    string comando;
    iss >> idZona >> idAparelho >> comando;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: acom <IDzona> <ID aparelho> <comando>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando ACOM em execucao" << endl;

}

void Interface::comandoPsalva(istringstream &iss) {

    int idZona, idProcRegra;
    string nome;
    iss >> idZona >> idProcRegra >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: acom <IDzona> <ID proc. regra> <nome>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando PSALVA em execucao" << endl;
}

void Interface::comandoPrepoe(istringstream &iss) {

    string nome;
    iss >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: prepoe <nome>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando PREPOE em execucao" << endl;
}

void Interface::comandoPrem(istringstream &iss) {

    string nome;
    iss >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: prem <nome>" << endl;
        return;
    }

    // TODO fazer o que o comando pede
    cout << "Comando PREM em execucao" << endl;

}

void Interface::comandoPlista() {
    cout << "Comando PLISTA em execuçao" << endl;
}

void Interface::comandoExec(istringstream &iss) {

    string nomeFicheiro;
    iss >> nomeFicheiro;

    if(iss.fail()){
        cout << "[ ERRO ] Insira os argumentos corretos: exec <nome_ficheiro>" << endl;
        return;
    }

    //abrir ficheiro
    ifstream ficheiro(nomeFicheiro);
    if(ficheiro.is_open()){
        if(ficheiro.good()){

            string comando;
            string primeiro;
            while(getline(ficheiro, comando)){
                comandos(comando);
            }
        }
    }else{
        cout << "[ ERRO ] Ficheiro nao encontrado" << endl;
        return;
    }

}

void Interface::comandoSair() {
    cout << "Desligando Sistema..." << endl;
}
