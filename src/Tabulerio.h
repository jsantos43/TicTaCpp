#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>

class Tabuleiro {
  private:
    char valores[3][3];
    char ganhador;
  public:
    Tabuleiro();
    void imprimir();
    void imprimir_jogo();
    void limpar_tela();
    bool verificar_ganho();
    bool registrar_jogada(int, char);
    char get_ganhador();
};

#endif