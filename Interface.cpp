//
// Created by João Carvalho on 21/10/2023.
//

#include "Interface.h"

#include <iostream>
#include <sstream>

Interface::Interface(Habitacao* habitacao): habitacao(habitacao) {
    cout << "Sistema de Controlo de Habitaçao Iniciado" << endl;
}

void Interface::menu() {

    string linha;

    do{
        cout << "[ COMANDOS ]" << endl;
        cout << "Insira um comando: " << endl;
        getline(cin, linha);

        if(comandos(linha) == false){
            cout << "[ ERRO ] Comando nao existe." << endl;
            break;
        }

    }while(linha != "sair");

}

bool Interface::comandos(const string& comando){

    string primeiro;
    istringstream iss(comando);
    iss >> primeiro;

    //if(primeiro == "")

    return false;
}

void Interface::comandoProx() {

}

void Interface::comandoAvanca(istringstream &iss) {

}

void Interface::comandoHnova(istringstream &iss) {

}

void Interface::comandoHrem() {

}

void Interface::comandoZnova(istringstream &iss) {

}

void Interface::comandoZrem(istringstream &iss) {

}

void Interface::comandoZlista() {

}

void Interface::comandoZcomp(istringstream &iss) {

}

void Interface::comandoZprops(istringstream &iss) {

}

void Interface::comandoPmod(istringstream &iss) {

}

void Interface::comandoCnovo(istringstream &iss) {

}

void Interface::comandoCrem(istringstream &iss) {

}

void Interface::comandoRnova(istringstream &iss) {

}

void Interface::comandoPmuda(istringstream &iss) {

}

void Interface::comandoRlista(istringstream &iss) {

}

void Interface::comandoRrem(istringstream &iss) {

}

void Interface::comandoAsoc(istringstream &iss) {

}

void Interface::comandoAdes(istringstream &iss) {

}

void Interface::comandoAcom(istringstream &iss) {

}

void Interface::comandoPsalva(istringstream &iss) {

}

void Interface::comandoPrepoe(istringstream &iss) {

}

void Interface::comandoPrem(istringstream &iss) {

}

void Interface::comandoPlista() {

}

void Interface::comandoExec(istringstream &iss) {

}

void Interface::comandoSair() {

}
