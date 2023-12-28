//
// Created by João Carvalho on 21/10/2023.
//

#include "Interface.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>

Interface::Interface(Terminal& terminal, GestorHabitacao* gestorHabitacao):terminal(terminal),
                                                                            gestorHabitacao(gestorHabitacao),
                                                                            windowInstante(0, 0, 2, 150, true),
                                                                             windowLogs(125, 0, 100, 100, true),
                                                                             windowHabitacao(0, 2, 100, 150, true),
                                                                             windowComandos(0, 45, 100, 100, true){

    for(int i=1; i<20; i++) {
        this->terminal.init_color(i, i, 0);
    }

    this->terminal << set_color(10) << "SISTEMA DE CONTROLO DE HABITACAO INICIADO" << move_to(125, 0);
    this->terminal << "LOGS:";
}

void Interface::menu() {

    string linha;

    do{
        if(gestorHabitacao->getHabitacao() != nullptr){
            printaHabitacao();
            windowInstante << move_to(0, 0) << set_color(0) << "Instantes: " << gestorHabitacao->getTempoDaHabitacao() << move_to(0, 1) << "# -> numero de componentes superior ao suportado pela grelha, zcomp <idZona> para detalhes";
        }

        this->terminal << move_to(0, 47) << set_color(11) << "[ COMANDOS ]" << set_color(0);
        windowComandos << move_to(0, 3) << "Insira um comando: ";
        //getline(cin, linha);
        windowComandos >> linha;

        if(gestorHabitacao->getHabitacao() == nullptr && linha.find("hnova") == std::string::npos && linha.find("exec") == std::string::npos) {
            windowLogs << set_color(1) << "[ ERRO ] O primeiro comando a ser inserido é o hnova para criar a habitacao ou exec para executar ficheiro de texto" << move_to(0, 2);
            windowComandos.clear();
            continue;
        }
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
    int incrementoY = 2;

    for(int i = 0; i <= gestorHabitacao->getHabitacao()->getMaxLinha(); i++){ // = para fazer a ultima linha de todas, ou seja, tem que printar a linha de asteriscos 5 vezes
        for(int j = 0; j < gestorHabitacao->getHabitacao()->getMaxColuna(); j++){
            windowHabitacao << move_to(j + incrementoX, i + incrementoY) << set_color(1) << "*******************";

            if(i != gestorHabitacao->getHabitacao()->getMaxLinha()) {
                for(int k = 1; k <= 5; k++)
                    windowHabitacao << move_to(j + incrementoX, i + incrementoY + k) << set_color(1) << "*";

                //printa a ZONA <ID>
                if(!gestorHabitacao->getHabitacao()->getZonas().empty())
                    if(gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i) != nullptr){
                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 1) << set_color(0) << "Zona " << gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getId();
                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 2) << set_color(0) << "A: ";

                        // printar aparelhos
                        if(!gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getAparelhos().empty()) {
                            if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getAparelhos().size() > 7) {
                                windowHabitacao << "#";
                            } else {
                                for (int a = 0; a < gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                      i)->getAparelhos().size(); a++) {
                                    if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getAparelhos()[a] !=
                                        nullptr)
                                        windowHabitacao << gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                             i)->getAparelhos()[a]->getNome();
                                }
                            }
                        }

                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 3) << set_color(0) << "S: ";

                        //printar sensores
                        if(!gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getSensores().empty()) {
                            if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getSensores().size() > 7) {
                                windowHabitacao << "#";
                            } else {
                                for (int a = 0; a < gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                      i)->getSensores().size(); a++) {
                                    if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getSensores()[a] !=
                                        nullptr)
                                        windowHabitacao << gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                             i)->getSensores()[a]->getNome();
                                }
                            }
                        }

                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 4) << set_color(0) << "P: ";

                        //printa processadores
                        if(!gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getProcessadores().empty()) {
                            if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j, i)->getProcessadores().size() >
                                7) {
                                windowHabitacao << "#";
                            } else {
                                for (int a = 0; a < gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                      i)->getProcessadores().size(); a++) {
                                    if (gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                          i)->getProcessadores()[a] !=
                                        nullptr)
                                        windowHabitacao << gestorHabitacao->getHabitacao()->getZonaByPosicao(j,
                                                                                                             i)->getProcessadores()[a]->getNome();
                                }
                            }
                        }

                        windowHabitacao << move_to(j + incrementoX + 1, i + incrementoY + 5) << set_color(2) << "( " << i + 1 << ", " << j + 1 << " )";
                    }
            }

            if(j == gestorHabitacao->getHabitacao()->getMaxColuna() - 1){
                if(i != gestorHabitacao->getHabitacao()->getMaxLinha())
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

    //TODO mandar os componentes que reagem ao tempo fazer as suas acoes
    gestorHabitacao->getHabitacao()->avancaTempo();
    windowLogs << set_color(11) << "[ PROX ] " << set_color(0) << "Avancou um instante" << move_to(0, 2);
    for(Zona* z: gestorHabitacao->getHabitacao()->getZonas()){
        for(int i = 0; i < z->getProcessadores().size(); i++){
            //TODO a cada instante o processador avalia as regras todas -> se forem todas verdadeiras ativa o comando configurado, ou seja, envia os comando aos aparelhos -> aparelhos ligam/desligam
            z->getProcessadores()[i]->avaliaRegras();
        }
    }
}

void Interface::comandoAvanca(istringstream &iss) {
    windowLogs.clear();

    int passos;
    iss >> passos;

    //TODO mandar os componentes que reagem ao tempo fazer as suas acoes
    //gestorHabitacao->getHabitacao()->avancaTempoNVezes(passos);
    windowLogs << set_color(11) << "[ AVANCA ] " << set_color(0) << "Avancou " << passos << " instantes" << move_to(0, 2);

    for(int j = 0; j < passos; j++){
        for(Zona* z: gestorHabitacao->getHabitacao()->getZonas()){
            for(int i = 0; i < z->getProcessadores().size(); i++){
                //TODO a cada instante o processador avalia as regras todas -> se forem todas verdadeiras ativa o comando configurado, ou seja, envia os comando aos aparelhos -> aparelhos ligam/desligam
                z->getProcessadores()[i]->avaliaRegras();
            }
        }

        sleep(1);
        gestorHabitacao->getHabitacao()->avancaTempo();
        windowInstante << move_to(0, 0) << set_color(0) << "Instantes: " << gestorHabitacao->getTempoDaHabitacao() << move_to(0, 1) << "# -> numero de componentes superior ao suportado pela grelha, zcomp <idZona> para detalhes";
    }

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
    if(gestorHabitacao->getHabitacao() != nullptr){ // esta verificaçao serve para o caso de ja existir uma habitacao e eu querer criar uma nova habitacao
        windowLogs.clear();
        windowHabitacao.clear();
        gestorHabitacao->destroiHabitacao();
    }

    gestorHabitacao->criaHabitacao(nLinhas, nColunas);

    if(gestorHabitacao->getHabitacao() != nullptr){
        windowLogs << set_color(11) << "[ HNOVA ] " << set_color(0) << "Habitacao criada com sucesso" << move_to(0, 2);
    }
}

void Interface::comandoHrem() {
    windowLogs.clear();

    // TODO adaptar o destrutor da classe habitacao para destruir tudo o que a habitaçao contem
    if (gestorHabitacao->getHabitacao() != nullptr) {
        gestorHabitacao->destroiHabitacao();

        windowLogs << set_color(11) << "[ HREM ] " << set_color(0) << "Habitação removida com sucesso" << move_to(0, 2);
        windowHabitacao.clear();
    } else {
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Não há habitação para remover" << move_to(0, 2);
    }

}

void Interface::comandoZnova(istringstream &iss) {
    windowLogs.clear();

    int linha, coluna;
    iss >> linha >> coluna;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira argumentos validos: znova <linha> <coluna>" << move_to(0, 2);
        return;
    }

    //cria zona e adiciona ao vector de zonas
    if(gestorHabitacao->getHabitacao()->getZonas().size() < gestorHabitacao->getHabitacao()->getMaxLinha() * gestorHabitacao->getHabitacao()->getMaxColuna()){
        if(linha >= 1 && linha <= gestorHabitacao->getHabitacao()->getMaxLinha()){
            if(coluna >= 1 && coluna <= gestorHabitacao->getHabitacao()->getMaxColuna()){

                for(Zona* zona: gestorHabitacao->getHabitacao()->getZonas()){
                    if(zona->getPosicao()[0] == coluna && zona->getPosicao()[1] == linha){
                        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Ja existe uma zona nessa posicao" << move_to(0, 2);
                        return;
                    }
                }

                gestorHabitacao->getHabitacao()->adicionaZona(linha, coluna);
                windowLogs << set_color(11) << "[ ZNOVA ] " << set_color(0) << "Zona nova criada com sucesso na posicao " << linha << " " << coluna << move_to(0, 2);
            }
        }else
            windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira uma linha e coluna correta: " << move_to(0, 2)
                       << "linha < 1 , " << gestorHabitacao->getHabitacao()->getMaxLinha() << " >" << move_to(0, 3)
                       << "coluna < 1 , " << gestorHabitacao->getHabitacao()->getMaxColuna() << " >" << move_to(0, 4);
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

    if(gestorHabitacao->getHabitacao()->getZonas().empty()) {
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Nao existem zonas a eliminar" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->removeZonaById(idZona))
        windowLogs << set_color(11) << "[ ZREM ] " << set_color(0) << "Zona com id " << idZona << " removida com sucesso" << move_to(0, 2);
    else
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Não existe nenhuma zona com o id " << idZona << move_to(0, 2);

}

void Interface::comandoZlista() {
    windowLogs.clear();

    if(gestorHabitacao->getHabitacao()->getZonas().empty())
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Nao existe nenhuma zona" << move_to(0, 2);
    windowLogs << set_color(11) << "[ ZLISTA ] " << set_color(0) << move_to(0, 2) << gestorHabitacao->getHabitacao()->listaZonas();

}

void Interface::comandoZcomp(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira um id de zona existente: zcomp <IDzona>" << move_to(0, 2);
        return;
    }

    windowLogs << set_color(11) << "[ ZCOMP ]" << set_color(0) << move_to(2, 2) << gestorHabitacao->getHabitacao()->listaEquipamentoZona(idZona) << move_to(0, 2);
}

void Interface::comandoZprops(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira um id de zona existente: zprops <IDzona>" << move_to(0, 2);
        return;
    }

    windowLogs << set_color(11) << "[ ZPROPS ] " << set_color(0) << gestorHabitacao->getHabitacao()->listaPropriedadesZona(idZona) << move_to(0, 2);
}

void Interface::comandoPmod(istringstream &iss) {
    windowLogs.clear();

    int idZona;
    iss >> idZona;
    string nome;
    iss >> nome;
    double valor;
    iss >> valor;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: pmod <IDzona> <nome> <valor>" << move_to(0, 2);
        return;
    }

    windowLogs << set_color(11) << "[ PMOD ] " << set_color(0) << "Comando PMOD em execucao" << move_to(0, 2);

    if(!gestorHabitacao->getHabitacao()->alteraPropriedade(idZona, nome, valor, 'n')){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Propriedade " << nome << " nao foi alterada" << move_to(0, 2);
        return;
    }

    windowLogs << "Propriedade " << nome << " alterada com sucesso para " << valor << move_to(0, 2);

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
        int id = gestorHabitacao->getHabitacao()->adicionaProcessadorAZona(idZona, comando);

        windowLogs << set_color(11) << "[ CNOVO ] " << set_color(0) << "Processador id: " << id << " adicionado com sucesso" << move_to(0, 2);
    }else if(equipamento == 'a'){
        int id = gestorHabitacao->getHabitacao()->adicionaAparelhoAZona(idZona, tipo);
        if(id != -1)
            windowLogs << set_color(11) << "[ CNOVO ] " << set_color(0) << "Aparelho id: " << id << " adicionado com sucesso" << move_to(0, 2);
        else
            windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Aparelho nao foi adicionado" << move_to(0, 2);
    }else if(equipamento == 's'){
        int id = gestorHabitacao->getHabitacao()->adicionaSensorAZona(idZona, tipo);
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

    if(gestorHabitacao->getHabitacao()->removeEquipamentoByID(idZona, equipamento, idComponente)) //TODO devia receber o objeto removido para dizer qual o id e a zona onde ele estava
        windowLogs << set_color(11) << "[ CREM ] " << set_color(0) << "Equipamento removido com sucesso" << move_to(0, 2);
    else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Equipamento nao foi removido com sucesso" << move_to(0, 2);
}

void Interface::comandoRnova(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idSensor;
    string tipoRegra;
    vector<int> params;

    iss >> idZona >> idProcRegra >> tipoRegra >> idSensor;

    if (idZona < 0 || idProcRegra < 0 || idSensor < 0) {
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "IDs devem ser não negativos." << move_to(0, 2);
        return;
    }

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rnova <IDzona> <ID proc. regras> <regra> <IDsensor> [param1] [param2]" << move_to(0, 2);
        return;
    }

    int aux;
    while(iss >> aux){
        params.push_back(aux);
    }

    int idRegraCriada = gestorHabitacao->getHabitacao()->criaNovaRegraNoProcessadorDaZona(idZona, idProcRegra, tipoRegra, idSensor, params);

    if(idRegraCriada == -1){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Nao foi possivel criar a regra" << move_to(0, 2);
    }else if(idRegraCriada == -2){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Id do Sensor invalido" << move_to(0, 2);
    }else{
        windowLogs << set_color(11) << "[ RNOVA ]" << set_color(0) << " Comando executado com sucesso" << move_to(0, 2);
    }

}

void Interface::comandoPmuda(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    string novoComando;
    iss >> idZona >> idProcRegra >> novoComando;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: pmuda <IDzona> <ID proc. regras> <novo comando>" << move_to(0, 2);
        return;
    }

    string ultimoComando = gestorHabitacao->getHabitacao()->getZonaById(idZona)->getProcessadorById(idProcRegra)->getComandoOutput();
    int result = gestorHabitacao->getHabitacao()->mudaComandoProcessadorNaZona(idZona, idProcRegra, novoComando);

    if(result == -1) windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Zona nao existe" << move_to(0, 2);
    if(result == -2) windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Processador nao existe" << move_to(0, 2);
    if(result == 0) windowLogs << set_color(11) << "[ PMUDA ] " << set_color(0) << "Comando do Processador " << idProcRegra << " da Zona " << idZona << " mudado de " << ultimoComando << " para " << novoComando << move_to(0, 2);
}

void Interface::comandoRlista(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    iss >> idZona >> idProcRegra;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rlista <IDzona> <ID proc. regras>" << move_to(0, 2);
        return;
    }

    windowLogs << set_color(11) << "[ RLISTA ] " << set_color(0) << gestorHabitacao->getHabitacao()->listaRegrasNoProcessador(idZona, idProcRegra) << move_to(0,2);
}

void Interface::comandoRrem(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idRegra;
    iss >> idZona >> idProcRegra >> idRegra;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: rrem <IDzona> <ID proc. regras> <ID regra>" << move_to(0, 2);
        return;
    }

    ostringstream oss;

    oss << (gestorHabitacao->getHabitacao()->removeRegraDoProcessadorDaZona(idZona, idProcRegra, idRegra) ?
            "Regra " + to_string(idRegra) + " removida com sucesso do Processador " + to_string(idProcRegra) + " da Zona " + to_string(idZona) :
            "Falha ao remover Regra " + to_string(idRegra) + " do Processador " + to_string(idProcRegra) + " da Zona " + to_string(idZona));

    string result = oss.str();

    windowLogs << set_color(11) << "[ RREM ]" << set_color(0) << result << move_to(0, 2);
}

void Interface::comandoAsoc(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: asoc <IDzona> <ID proc. regras> <ID aparelho>" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->associaProcessadorDaZonaAparelho(idZona, idProcRegra, idAparelho)){
        windowLogs << set_color(11) << "[ ASOC ]" << set_color(0) << " Aparelho associado com sucesso" << move_to(0, 2);
    }else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Erro ao associar aparelho ao sensor" << move_to(0, 2);

}

void Interface::comandoAdes(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra, idAparelho;
    iss >> idZona >> idProcRegra >> idAparelho;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: ades <IDzona> <ID proc. regras> <ID aparelho>" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->desassociaProcessadorDaZonaAparelho(idZona, idProcRegra, idAparelho)){
        windowLogs << set_color(11) << "[ ADES ]" << set_color(0) << " Aparelho desassociado com sucesso" << move_to(0, 2);
    }else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Erro ao desassociar aparelho ao sensor" << move_to(0, 2);

}

void Interface::comandoAcom(istringstream &iss) {
    windowLogs.clear();

    int idZona, idAparelho;
    string comando;
    iss >> idZona >> idAparelho >> comando;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: acom <IDzona> <ID aparelho> <comando>" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->mudaComandoAparelhoNaZona(idZona, idAparelho, comando)){
        windowLogs << set_color(11) << "[ ACOM ]" << set_color(0) << " Comando mudando com sucesso" << move_to(0, 2);
    }else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Nao foi possivel mudar o comando" << move_to(0, 2);


}

void Interface::comandoPsalva(istringstream &iss) {
    windowLogs.clear();

    int idZona, idProcRegra;
    string nome;
    iss >> idZona >> idProcRegra >> nome;

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: psalva <IDzona> <ID proc. regra> <nome>" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->verificaSeGravacaoExiste(nome)){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Já existe uma gravacao com esse nome" << move_to(0, 2);
        return;
    }

    if(gestorHabitacao->getHabitacao()->salvaProcessadorDaZona(idZona, idProcRegra, nome)){
        windowLogs << set_color(11) << "[ PSALVA ]" << set_color(0) << " Processador de regras salvo com sucesso" << move_to(0, 2);
    }else windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Nao foi possivel salvar o processador de regras" << move_to(0, 2);

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

    if(iss.fail()){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << "Insira os argumentos corretos: prem <nome>" << move_to(0, 2);
        return;
    }

    if(!gestorHabitacao->getHabitacao()->verificaSeGravacaoExiste(nome)){
        windowLogs << set_color(1) << "[ ERRO ] " << set_color(0) << " Nao existe uma gravacao com esse nome" << move_to(0, 2);
        return;
    }

    gestorHabitacao->getHabitacao()->removeGravacaoProcessador(nome);
    windowLogs << set_color(11) << "[ PREM ] " << set_color(0) << "Processador guardado foi removido com sucesso" << move_to(0, 2);

}

void Interface::comandoPlista() {
    windowLogs.clear();
    windowLogs << set_color(11) << "[ PLISTA ]" << set_color(0) << move(0, 3);
    windowLogs << gestorHabitacao->getHabitacao()->listaGravacoes();
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
                sleep(1);
                comandos(comando);
                printaHabitacao();
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
    sleep(3); //espera 3 segundos antes de encerrar o sistema
}
