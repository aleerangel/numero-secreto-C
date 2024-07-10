#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("****************************************\n");
    printf("*Bem vindo ao nosso jogo de adivinhação*\n");
    printf("****************************************\n");
    int semente = time(0);
    srand(semente);
    int numerosecreto = rand() % 100;
    int chute;
    int tentativas = 1;
    double pontuacao = 1000;
    while(1) {
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        if(chute < 0) {
            printf("Insira um número válido!\n");
            continue;
        }
        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
        if(acertou) {
            break;
        }
        else if(maior) {
            printf("O número secreto é menor que %d\n", chute);
        }
        else {
            printf("O número secreto é maior que %d\n", chute);
        }
        tentativas++;
        pontuacao = pontuacao - (abs(chute - numerosecreto) / (double)2);
    } 
    printf("Parabéns! Você acertou o número secreto %d com %d tentativas!\n", numerosecreto, tentativas);
    printf("Fim de jogo!\n");
    printf("Pontuação: %.1f\n", pontuacao);
}