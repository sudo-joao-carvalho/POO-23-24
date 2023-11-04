//
// Created by João Carvalho on 21/10/2023.
//

#include "Interface.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Interface::Interface(Terminal& terminal):terminal(terminal),
                                         windowLogs(135, 0, 100, 100, true),
                                         windowHabitacao(0, 2, 85, 150, true),
                                         windowComandos(0, 45, 100, 100, true){
    habitacao = nullptr;

    for(int i=1; i<20; i++) {
        this->terminal.init_color(i, i, 0);
    }

    this->terminal << set_color(10) << "SISTEMA DE CONTROLO DE HABITACAO INICIADO" << move_to(0, 1);
    windowLogs << "LOGS:" << move_to(0, 1);
}

Interface::~Interface(){
    if(habitacao != nullptr)
        delete habitacao;
}

void Interface::menu() {

    string linha;

    do{
        if(habitacao != nullptr){
            printaHabitacao();
        }

        windowComandos << move_to(0, 1) << "\t\tNumero de instantes: " << "0";

        windowComandos << move_to(0, 2) << "[ COMANDOS ]";
        windowComandos << move_to(0, 3) << "Insira um comando: ";
        //getline(cin, linha);
        windowComandos >> linha;
        windowComandos.clear();

        if(!comandos(linha)){
            windowLogs << set_color(1) << "[ ERRO ] Comando nao existe." << move_to(0, 2);
            /*cout << "Insira um comando: " << endl;
            getline(cin, linha);*/
            continue;
        }


    }while(linha != "sair");

}

void Interface::printaHabitacao() {

    windowHabitacao.clear();

    int incrementoX = 0;
    int incrementoY = 0;

    for(int i = 0; i <= habitacao->getMaxLinha(); i++){ // = para fazer a ultima linha de todas, ou seja, tem que printar a linha de asteriscos 5 vezes
        for(int j = 0; j < habitacao->getMaxColuna(); j++){
            windowHabitacao << move_to(j + incrementoX, i + incrementoY) << set_color(1) << "*******************";

            if(i != habitacao->getMaxLinha()) {
                for(int k = 1; k <= 5; k++)
                    windowHabitacao << move_to(j + incrementoX, i + incrementoY + k) << set_color(1) << "*";

                //printa a ZONA <ID>
                if(!habitacao->getZonas().empty())
                    if(habitacao->getZonaByPosicao(j, i) != nullptr){
                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 1) << set_color(0) << "Zona " << habitacao->getZonaByPosicao(j, i)->getId();
                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 2) << set_color(0) << "A: ";

                        // printar aparelhos
                        if(!habitacao->getZonaByPosicao(j, i)->getAparelhos().empty())
                            for(int a = 0; a < habitacao->getZonaByPosicao(j, i)->getAparelhos().size(); a++){
                                if(habitacao->getZonaByPosicao(j, i)->getAparelhos()[a] != nullptr)
                                    windowHabitacao << habitacao->getZonaByPosicao(j, i)->getAparelhos()[a]->getAbreviacao();
                            }

                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 3) << set_color(0) << "S: ";

                        //printar sensores
                        if(!habitacao->getZonaByPosicao(j, i)->getSensores().empty())
                            for(int a = 0; a < habitacao->getZonaByPosicao(j, i)->getSensores().size(); a++){
                                if(habitacao->getZonaByPosicao(j, i)->getSensores()[a] != nullptr)
                                    windowHabitacao << habitacao->getZonaByPosicao(j, i)->getSensores()[a]->getAbreviacao();
                            }
                    }
            }

            if(j == habitacao->getMaxColuna() - 1){
                if(i != habitacao->getMaxLinha())
                    for(int k = 1; k <= 5; k++)
                        windowHabitacao << move_to(j + incrementoX + 18, i + incrementoY + k) << set_color(1) << "*"; //printar a ultima linha vertical
            }

            incrementoX += 18;
        }

        incrementoY += 5;
        incrementoX = 0;


    }
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
    windowLogs.clear();
    //cout << "Comando PROX em execucao" << endl;
    windowLogs << "Comando PROX em execucao" << move_to(0, 2);
}

void Interface::comandoAvanca(istringstream &iss) {
    windowLogs.clear();

    int passos;
    iss >> passos;

    // TODO AVANCAR
    windowLogs << "Avancou " << passos << " passos" << move_to(0, 2);

}

void Interface::comandoHnova(istringstream &iss) {
    windowLogs.clear();

    int nLinhas, nColunas;
    iss >> nLinhas >> nColunas;

    if(nLinhas < 2 || nLinhas > 4){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Numero de linhas tem que estar compreendido entre 2 e 4" << move_to(0, 2);
        return;
    }

    if(nColunas < 2 || nColunas > 4){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Numero de colunas tem que estar compreendido entre 2 e 4" << move_to(0, 2);
        return;
    }

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira argumentos validos: hnova <num_linhas> <num_colunas>" << move_to(0, 2);
        return;
    }

    // Cria habitacao
    if(habitacao != nullptr){ // esta verificaçao serve para o caso de ja existir uma habitacao e eu querer criar uma nova habitacao (talvez mudar para o codigo da classe habitacao)
        windowLogs.clear();
        windowHabitacao.clear();
        delete habitacao;
    }


    habitacao = new Habitacao(nLinhas, nColunas);

    if(habitacao != nullptr){
        windowLogs << set_color(11) << "[ HNOVA ] " << set_color(0) << "Habitacao criada com sucesso" << move_to(0, 2);
    }
}

void Interface::comandoHrem() {
    windowLogs.clear();

    windowLogs << set_color(11) << "[ HREM ] " << set_color(0) << "Comando HREM em execucao" << move_to(0, 2);

    // TODO adaptar o destrutor da classe habitacao para destruir tudo o que a habitaçao contem
    if (habitacao != nullptr) {
        delete habitacao;
        habitacao = nullptr; // Define o ponteiro como nullptr após a desalocação
        windowLogs << set_color(11) << "[ HREM ] " << set_color(0) << "Habitação removida com sucesso" << move_to(0, 2);
    } else {
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Não há habitação para remover" << move_to(0, 2);
    }

}

void Interface::comandoZnova(istringstream &iss) {
    windowLogs.clear();

    int linha, coluna;
    iss >> linha >> coluna;

    // TODO fazer verificaçao se os numeros indicados esta disponivel para a grelha indicada pelo utilizador
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira argumentos validos: znova <linha> <coluna>" << move_to(0, 2);
        return;
    }

    //cria zona e adiciona ao vector de zonas
    if(habitacao->getZonas().size() < habitacao->getMaxLinha() * habitacao->getMaxColuna()){
        if(linha >= 1 && linha <= habitacao->getMaxLinha()){
            if(coluna >= 1 && coluna <= habitacao->getMaxColuna()){

                for(Zona* zona: habitacao->getZonas()){
                    if(zona->getPosicao()[0] == coluna && zona->getPosicao()[1] == linha){
                        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Ja existe uma zona nessa posicao" << move_to(0, 2);
                        return;
                    }
                }

                habitacao->adicionaZona(linha, coluna);
                windowLogs << set_color(11) << "[ ZNOVA ] " << set_color(0) << "Zona nova criada com sucesso na posicao " << linha << " " << coluna << move_to(0, 2);
            }
        }else
            windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira uma linha e coluna correta: " << move_to(0, 2)
                       << "linha < 1 , " << habitacao->getMaxLinha() << " >" << move_to(0, 3)
                       << "coluna < 1 , " << habitacao->getMaxColuna() << " >" << move_to(0, 4);
    }else{
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Habitacao cheia de zonas" << move_to(0, 2);
    }

}

void Interface::comandoZrem(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira um id de zona: zrem <IDzona>" << move_to(0, 2);
        return;
    }

    if(habitacao->getZonas().empty()) {
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Nao existem zonas a eliminar" << move_to(0, 2);
        return;
    }

    if(habitacao->removeZonaById(idZona))
        windowLogs << set_color(11) << "[ ZREM ] " << set_color(0) << "Zona com id " << idZona << " removida com sucesso" << move_to(0, 2);
    else
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Não existe nenhuma zona com o id " << idZona << move_to(0, 2);

}

void Interface::comandoZlista() {
    windowLogs.clear();

    if(habitacao->getZonas().empty())
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Nao existe nenhuma zona" << move_to(0, 2);
    windowLogs << set_color(11) << "[ ZLISTA ] " << set_color(0) << move_to(0, 2) << habitacao->listaZonas();

}

void Interface::comandoZcomp(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira um id de zona existente: zcomp <IDzona>" << move_to(0, 2);
        return;
    }

    windowLogs << set_color(11) << "[ ZCOMP ]" << set_color(0) << move_to(2, 2) << habitacao->listaEquipamentoZona(idZona) << move_to(0, 2);
}

void Interface::comandoZprops(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;

    // TODO verificar se o id da zona existe
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira um id de zona existente: zprops <IDzona>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando ZPROPS em execucao" << move_to(0, 2);
}

void Interface::comandoPmod(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;
    string nome;
    iss >> nome;
    int valor;
    iss >> valor;

    // TODO verificar argumentos
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: pmod <IDzona> <nome> <valor>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando PMOD em execucao" << move_to(0, 2);

}

void Interface::comandoCnovo(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;
    char equipamento;
    iss >> equipamento;
    string comando;
    char tipo;

    if(equipamento == 'p'){
        iss >> comando;
    }else{
        iss >> tipo;
    }

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: cnovo <IDzona> < s | p | a > < tipo | comando >" << move_to(0, 2);
        return;
    }

    if(equipamento == 'p'){
        //habitacao->adicionaProcessadorAZona(idZona, equipamento, comando);
    }else if(equipamento == 'a'){
        int id = habitacao->adicionaAparelhoAZona(idZona, tipo);
        if(id != -1)
            windowLogs << set_color(11) << "[ CNOVO ] " << set_color(0) << "Aparelho id: " << id << " adicionado com sucesso" << move_to(0, 2);
        else
            windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Aparelho nao foi adicionado" << move_to(0, 2);
    }else if(equipamento == 's'){
        int id = habitacao->adicionaSensorAZona(idZona, tipo);
        if(id != -1)
            windowLogs << set_color(11) << "[ CNOVO ] " << set_color(0) << "Sensor id: " << id << " adicionado com sucesso" << move_to(0, 2);
        else
            windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Sensor nao foi adicionado" << move_to(0, 2);
    }

}

void Interface::comandoCrem(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;
    char equipamento;
    iss >> equipamento;
    int idComponente;
    iss >> idComponente;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: crem <IDzona> < s | p | a > < IDcomponente >" << move_to(0, 2);
        return;
    }

    if(habitacao->removeEquipamentoByID(idZona, equipamento, idComponente)) //TODOdevia receber o objeto removido para dizer qual o id e a zona onde ele estava
        windowLogs << set_color(11) << "[ CREM ] " << set_color(0) << "Equipamento removido com sucesso" << move_to(0, 2);
    else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Equipamento nao foi removido com sucesso" << move_to(0, 2);
}

void Interface::comandoRnova(istringstream &iss) {
    windowLogs.clear();

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
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rnova <IDzona> <ID proc. regras> <regra> <IDsensor> [param1] [param2]" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando RNOVA em execucao" << move_to(0, 2);

}

void Interface::comandoPmuda(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    string novoComando;
    iss >> idZona >> idProcRegra >> novoComando;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: pmuda <IDzona> <ID proc. regras> <novo comando>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando PMUDA em execucao" << move_to(0, 2);
}

void Interface::comandoRlista(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    iss >> idZona >> idProcRegra;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rlista <IDzona> <ID proc. regras>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando RLISTA em execucao" << move_to(0, 2);
}

void Interface::comandoRrem(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idRegra;
    iss >> idZona >> idProcRegra >> idRegra;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rrem <IDzona> <ID proc. regras> <ID regra>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando RREM em execucao" << move_to(0, 2);
}

void Interface::comandoAsoc(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: asoc <IDzona> <ID proc. regras> <ID aparelho>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando ASOC em execucao" << move_to(0, 2);

}

void Interface::comandoAdes(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: ades <IDzona> <ID proc. regras> <ID aparelho>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando ADES em execucao" << move_to(0, 2);

}

void Interface::comandoAcom(istringstream &iss) {
    windowLogs.clear();

    int idZona, idAparelho;
    string comando;
    iss >> idZona >> idAparelho >> comando;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: acom <IDzona> <ID aparelho> <comando>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando ACOM em execucao" << move_to(0, 2);

}

void Interface::comandoPsalva(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    string nome;
    iss >> idZona >> idProcRegra >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: acom <IDzona> <ID proc. regra> <nome>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando PSALVA em execucao" << move_to(0, 2);
}

void Interface::comandoPrepoe(istringstream &iss) {
    windowLogs.clear();

    string nome;
    iss >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: prepoe <nome>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando PREPOE em execucao" << move_to(0, 2);
}

void Interface::comandoPrem(istringstream &iss) {
    windowLogs.clear();

    string nome;
    iss >> nome;

    // TODO verificar se parametros existem
    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: prem <nome>" << move_to(0, 2);
        return;
    }

    // TODO fazer o que o comando pede
    windowLogs << "Comando PREM em execucao" << move_to(0, 2);

}

void Interface::comandoPlista() {
    windowLogs.clear();
    windowLogs << "Comando PLISTA em execuçao" << move_to(0, 2);
}

void Interface::comandoExec(istringstream &iss) {
    windowLogs.clear();

    string nomeFicheiro;
    iss >> nomeFicheiro;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: exec <nome_ficheiro>" << move_to(0, 2);
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
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Ficheiro nao encontrado" << move_to(0, 2);
        return;
    }

    ficheiro.close();

}

void Interface::comandoSair() {
    windowLogs.clear();
    windowLogs << "Desligando Sistema..." << move_to(0, 2);
    return;
}
