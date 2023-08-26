/*Desafio: Jogo de Adivinhação

Descrição:
Você deve criar um jogo de adivinhação em que o computador escolhe um número aleatório e o jogador tenta adivinhar esse número. O jogo deve fornecer feedback ao jogador sobre se o número que ele adivinhou é maior ou menor que o número escolhido pelo computador. O jogo deve continuar até que o jogador adivinhe corretamente o número ou decida sair do jogo.

Regras do Jogo:

O computador deve escolher um número aleatório entre 1 e 100.
O jogador tem um número limitado de tentativas para adivinhar o número correto.
Após cada tentativa do jogador, o jogo deve informar se o número correto é maior ou menor que o número que o jogador adivinhou.
Se o jogador adivinhar corretamente, o jogo deve exibir uma mensagem de parabéns e informar o número de tentativas que o jogador levou.
Se o jogador exceder o número máximo de tentativas sem adivinhar corretamente, o jogo deve informar que o jogador perdeu e mostrar o número correto.
Requisitos:

O jogo deve ser implementado em C.
O código deve ser bem organizado e comentado.
O jogo deve incluir uma função principal (main) e, pelo menos, uma função adicional para melhorar a modularidade do código.
Dicas:

Use a função rand() da biblioteca stdlib.h para gerar o número aleatório.
Use a função printf() para exibir mensagens ao jogador.
Use a função scanf() para capturar a entrada do jogador.
Lembre-se de criar um arquivo chamado "jogo_adivinhacao.c" (ou outro nome de sua escolha) e incluir o código-fonte do jogo nele. Não se esqueça de compilar e executar o programa para testá-lo.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void continuar(int *opcao){
    printf("Deseja continuar jogando?\n");
    printf("1- Sim\n");
    printf("2- Não\n");
    printf("Digite a opção desejada: ");
    scanf("%d", opcao);
}

void dificil(){
    int numero, tentativas_usadas = 0, tentativas_maximas = 20, opcao;
    int resposta_correta = rand() % 100 + 1;
    do {
        printf("Digite um número entre 1 e 100: ");
        scanf("%d", &numero);
        if (numero < resposta_correta) {
            printf("O número correto é maior!\n");
        } else if (numero > resposta_correta) {
            printf("O número correto é menor!\n");
        }
        tentativas_usadas++;
        continuar(&opcao);
        if (opcao != 1) {
            break;
        }
    } while (numero != resposta_correta && tentativas_usadas < tentativas_maximas);

    if(numero == resposta_correta){
        printf("Parabéns, você acertou!\n");
        printf("Você usou %d tentativas\n", tentativas_usadas);
    }
    else{
        printf("Você perdeu! O numero correto era %d\n", resposta_correta);
        printf("Você usou %d tentativas\n", tentativas_usadas);
        return;
    }
}

void medio(){
    int numero, tentativas_usadas = 0, tentativas_maximas = 20, opcao;
    int resposta_correta = rand() % 30 + 1;
    do {
        printf("Digite um número entre 1 e 30: ");
        scanf("%d", &numero);
        if (numero < resposta_correta) {
            printf("O número correto é maior!\n");
        } else if (numero > resposta_correta) {
            printf("O número correto é menor!\n");
        }
        tentativas_usadas++;
        continuar(&opcao);
        if (opcao != 1) {
            break;
        }
    } while (numero != resposta_correta && tentativas_usadas < tentativas_maximas);

    if(numero == resposta_correta){
        printf("Parabéns, você acertou!\n");
        printf("Você usou %d tentativas\n", tentativas_usadas);
    }
    else{
        printf("Você perdeu! O numero correto era %d\n", resposta_correta);
        printf("Você usou %d tentativas\n", tentativas_usadas);
    }
}

void facil(){
    int numero, tentativas_usadas = 0, tentativas_maximas = 10, opcao, continuar2;
    int resposta_correta = rand() % 10 + 1;
    do {
        printf("Digite um número entre 1 e 10: ");
        scanf("%d", &numero);
        if (numero < resposta_correta) {
            printf("O número correto é maior!\n");
            continuar2 = 1;
        } else if (numero > resposta_correta) {
            printf("O número correto é menor!\n");
            continuar2 = 1;
        }
        else{
            continuar2 = 0;
        }

        tentativas_usadas++;
        if (continuar2 == 1)
        {
            continuar(&opcao);
            if (opcao != 1) {
                break;
            }
        }else {
            break;
        }      
        
    } while (numero != resposta_correta && tentativas_usadas < tentativas_maximas);

    if(numero == resposta_correta){
        printf("Parabéns, você acertou!\n");
        printf("Você usou %d tentativas\n", tentativas_usadas);
    }
    else{
        printf("Você perdeu! O numero correto era %d\n", resposta_correta);
        printf("Você usou %d tentativas\n", tentativas_usadas); 
    }
}

void jogar(int *op){
    printf("Dificuldade\n");
    printf("1- Fácil\n");
    printf("2- Médio\n");
    printf("3- Difícil\n");
    printf("0- Sair\n");
    printf("Escolha o nível de dificuldade:\n");
    scanf("%d", op);
}

void menu(int *opcao){
    printf("Jogo da Memoria\n");
    printf("1- Jogar\n");
    printf("2- Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", opcao);
}

int main(){
    srand(time(NULL));
    int opcao, op;
    inicio:
    while (1)
    {
        menu(&opcao);    
        switch(opcao){
            case 1:
                jogar(&op);
                    switch(op){
                        case 1:
                            facil();
                            break;
                        case 2:
                            medio();
                            break;
                        case 3:
                            dificil();
                            break;
                        case 0:
                            goto inicio;
                        default:
                            printf("Opcao invalida\n");
                            break;
                    }    
                break;
            case 2:
                printf("Saindo do jogo...\n");
                exit(0);
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    return 0;
}