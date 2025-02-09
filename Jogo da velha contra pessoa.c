
#include <stdio.h>

int main(void) {
  int jogador = 1, a, b, vic = 0, casas;
  char m[3][3];

  // preparação da matriz
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      m[j][i] = '-';
    }
  }
  // jogo
  while (vic == 0) {

    casas = 0;
    
    printf("Jogador %d\n", jogador);
    printf("# 1  2  3\n");
    for (int i = 0; i <= 2; i++) {
      printf("%d", i + 1);
      for (int j = 0; j <= 2; j++) {
        printf("[%c]", m[j][i]);
      }
      printf("\n");
    }
    printf("jogador %d escolha onde deseja jogar:\n", jogador);
    printf("coluna:\n");
    scanf("%d", &a);
    a = a - 1;
    if (a != 0 && a != 1 && a != 2) {
      printf("escolha de novo:");
      scanf("%d", &a);
      a = a - 1;
    }
    printf("linha:");
    scanf("%d", &b);
    b = b - 1;
    if (a != 0 && a != 1 && a != 2) {
      printf("escolha de novo:");
      scanf("%d", &b);
      b = b - 1;
    }
    // se o espaço já foi escolhido
    if (m[a][b] != '-') {
      printf("escolha de novo:");

      printf("coluna:\n");
      scanf("%d", &a);
      a = a - 1;
      if (a != 0 && a != 1 && a != 2) {
        printf("escolha de novo:");
        scanf("%d", &a);
        a = a - 1;
      }
      printf("linha:");
      scanf("%d", &b);
      b = b - 1;
      if (a != 0 && a != 1 && a != 2) {
        printf("escolha de novo:");
        scanf("%d", &b);
        b = b - 1;
      }
    }
    // troca de jogador
    switch (jogador) {

    case 1:
      m[a][b] = 'X';
      jogador = 2;
      break;
    case 2:
      m[a][b] = 'O';
      jogador = 1;
      break;
    }

    // verificar a vitória na rodada

    // horizontal
    for (int j = 0; j <= 1; j++) {
      if (m[j][0] == m[j][1] && m[j][1] == m[j][2] && m[j][0] != '-') {
        vic = 1;
      }
    }
    // vertical
    for (int j = 0; j <= 2; j++) {
      if (m[0][j] == m[1][j] && m[1][j] == m[2][j] && m[0][j] != '-') {
        vic = 1;
      }
    }

    // diagonais
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != '-' ||
        m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[2][0] != '-') {
      vic = 1;
    }

    for(int i=0; i<=2; i++){
      for( int j=0; j<=2; j++){
        if(m[i][j] == '-'){
          casas++;
        }

      }
    }

    if(casas == 0){
      break;
    }
  }

  printf("# 1  2  3\n");
  for (int i = 0; i <= 2; i++) {
    printf("%d", i + 1);
    for (int j = 0; j <= 2; j++) {
      printf("[%c]", m[j][i]);
    }
    printf("\n");
  }

  switch (jogador) {

  case 1:
    jogador = 2;
    break;
  case 2:
    jogador = 1;
    break;
  }
  if(vic == 0){
    printf("Ninguém ganhou, deu velha.");
  }
  else{
    printf("Parabéns! O jogador %d venceu a partida!", jogador);
  }
}
