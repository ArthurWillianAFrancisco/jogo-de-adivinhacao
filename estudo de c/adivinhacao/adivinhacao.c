#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprimindo cabecalho bonito do jogo
      printf("\n\n");
    printf("          P  /_\\  P                                         \n");
    printf("         /_\\_|_|_/_\\                                       \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao                \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!            \n");
    printf("    |\" \"  |  |_|  |\"  \" |                                \n");
    printf("    |_____| ' _ ' |_____|                                    \n");
    printf("          \\__|_|__/        Por:ArtWill\u00A9                \n");
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numero_secreto = numerogrande % 100;
  

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1)-Fácil (2)-Médio (3)-Difícil (4)-Estou com sorte");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerosdetentativas;

    switch (nivel) {
        case 1:
            numerosdetentativas = 20;
            break;
        case 2:
            numerosdetentativas = 15;
            break;
        case 3:
        numerosdetentativas = 10;
            break;
        case 4:
            numerosdetentativas = 1;
            break;    
        default:
            printf("Vou entender que você está com sorte\n");
            numerosdetentativas = 1;
            break;
    }


    for(int i = 1; i <= numerosdetentativas; i++) {

        printf("Tentativa %d\n", tentativas);

        printf("Qual é o seu chute?");
        scanf("%d", &chute);

        printf("Seu chute foi %d \n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numero_secreto);
        int maior = chute > numero_secreto;

        if(acertou){
            break;
        }

        else if(maior) {
            printf("Seu número foi maior\n");
        }

        else {
            printf("Seu número foi menor\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numero_secreto) / (double) 2;
        
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de jogo\n");
    printf("O numero secreto era %d\n", numero_secreto);

    if(acertou){
        
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");

        printf("\nVocê ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total do pontos: %.2f\n", pontos);
    }else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nVocê perdeu! Tente novamente.\n");
    }



}