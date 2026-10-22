#include "Tabulerio.h"

Tabuleiro::Tabuleiro() {
  int count {0};

  for (int i {0}; i < 3; i++) {
    for (int j {0}; j < 3; j++) {
      count++;
      valores[i][j] = count + '0';
    }
  }
}

void Tabuleiro::imprimir() {  
  for (int l = 0; l < 3; l++) {
    for (int c = 0; c < 3; c++) {
      std::cout << "[" << valores[l][c] << "]";
    }

    std::cout << std::endl;
  }
}

void Tabuleiro::imprimir_jogo() {
  std::cout << "=================" << std::endl;
  std::cout << "  Jogo da Velha  " << std::endl;
  std::cout << "=================" << std::endl << std::endl;

  imprimir();
}

void Tabuleiro::limpar_tela() {
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}

bool Tabuleiro::verificar_ganho(){
  int vezes_O, vezes_X { 0 };
  
  //Verifica se ganhou por coluna
  for (int l = 0;l < 3;l++){
    for (int c = 0;c < 3;c++) {
      if (valores[l][c] == 'X'){
        vezes_X++;
      }

      if (valores[l][c] == 'O'){
        vezes_O++;
      }

      if (vezes_O >= 3) {
        ganhador = 'O';
        return true;
      } else if (vezes_X >= 3) {
        ganhador = 'X';
        return true;
      }

    }
    // Zerar
    vezes_X = 0;
    vezes_O = 0;
  }

  // Verifica se ganhou por linha
  for (int c = 0; c < 3; c++){
    for (int l = 0; l < 3; l++) {
      if (valores[l][c] == 'X'){
        vezes_X++;
      }

      if (valores[l][c] == 'O'){
        vezes_O++;
      }

      if (vezes_O >= 3) {
        ganhador = 'O';
        return true;
      } else if (vezes_X >= 3) {
        ganhador = 'X';
        return true;
      }

    }

    // Zerar
    vezes_X = 0;
    vezes_O = 0;
  }

  for (int i {0}; i < 3; i++) {
    if (valores[i][i] == 'O') {
      vezes_O++;
    } else if (valores[i][i] == 'X') {
      vezes_X++;
    }
  }

  if (vezes_O >= 3) {
    ganhador = 'O';
    return true;
  } else if (vezes_X >= 3) {
    ganhador = 'X';
    return true;
  }

  if (valores[2][0] == 'O' && valores[1][1] == 'O' && valores[0][2] == 'O') {
    ganhador = 'O';
    return true;
  } else if (valores[2][0] == 'X' && valores[1][1] == 'X' && valores[0][2] == 'X') {
    ganhador = 'X';
    return true;
  }

  ganhador = '-';
  return false;
}

bool Tabuleiro::registrar_jogada(int pos, char player) {
  // Verifica se posição é um número aceito
  if (pos < 0 || pos > 9) {
    return false;
  }

  for (int l {0}; l < 3; l++) {
    for (int c {0}; c < 3; c++) {
      if (valores[l][c] == pos + '0') {
        valores[l][c] = player;

        return true;
      }
    }
  }
}

char Tabuleiro::get_ganhador() {
  return ganhador;
}