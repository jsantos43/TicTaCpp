#include <iostream>
#include "src/Tabulerio.h"
#include "src/Arvore.h"
using namespace std;

int main(void) {
  Tabuleiro jogo;

  bool fim {false};
  bool jogada_valida;
  bool jogar_dois {false};
  int pos;


  char resposta;
  cout << "Você deseja jogar de dois[S/N]";
  cin >> resposta;
  if (resposta == 'S' || resposta == 's') {
    jogar_dois = true;
  }

  while(!fim) {
    jogo.imprimir_jogo();
    
    // Pedir jogada do X
    jogada_valida = false;
    while (!jogada_valida) {
      cout << "Jogador X, digite uma posicao valida: ";
      cin >> pos;

      jogada_valida = jogo.registrar_jogada(pos, 'X');
    }

    fim = jogo.verificar_fim();

    if (fim) continue;

    jogo.imprimir_jogo();

    // Pedir jogada do O

    if (jogar_dois) {
      jogada_valida = false;
      while (!jogada_valida) {
        cout << "Jogador O, digite uma posicao valida: ";
        cin >> pos;

        jogada_valida = jogo.registrar_jogada(pos, 'O');
      }
    } else {
      // Implementar a inteligência
    }


    fim = jogo.verificar_fim();
  }

  jogo.imprimir_jogo();

  if (jogo.get_ganhador() == '-') {
    cout << "Empate!" << endl;
  } else {
    cout << "Ganhador: " << jogo.get_ganhador() << endl;
  }
  
  return 0;
}