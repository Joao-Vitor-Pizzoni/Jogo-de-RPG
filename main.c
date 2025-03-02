#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "O_jogo.h"
#include "O_jogo.c"

int processInput(Mapa *jogo)
{
    if((jogo->coroa == 0)&&jogo->localizacao==jogo->reino)
    {
             printf("\n Ao chegar no reino, você entrega a coroa ao rei e seu jornada se encerra");
             return 0;
    }
    printf("\n> ");
    char ch = getchar();
    getchar();


    switch(ch)
    {
        case 'q':
        {
            printf("Já que não aceita missão do rei, morra\n");
            return 0;
        }
        break;

        case 'w':
        {
            mapaMover(jogo, FRENTE);
        }
        break;

        case 's':
        {
            mapaMover(jogo, ATRAS);
        }
        break;

        case 'a':
        {
            mapaMover(jogo, ESQUERDA);
        }
        break;

        case 'd':
        {
            mapaMover(jogo, DIREITA);
        }
        break;

        case 'z':
        {
            printf("\a");
            switch(mapaAtaque(jogo))
            {
                case 2:
                {
                    jogo->jogador->dano = 20;
                    printf("Você acha uma espada, ficando com 20 dano");
                    return 1;

                }break;

                case 3:
                {
                    printf("Duck morreu");
                    return 0;

                }break;
                case 4:
                  {
                           printf("Achou a coroa do rei");
                           return 1;
                  }
            }
        }
        break;

        case 'v':
        {
            printf("Você está em %s\n", jogo->localizacao->descricao);
            printf("S ou N?\n");
            printf("Você pode ir para:\n");
            if(jogo->localizacao->frente) printf("FRENTE\n");
            if(jogo->localizacao->atras) printf("ATRAS\n");
            if(jogo->localizacao->esquerda) printf("ESQUERDA\n");
            if(jogo->localizacao->direita) printf("DIREITA\n");
        }
        break;
        case 'y':
        {
           enum Frases
         {
           frase0,
           frase1,
           frase2,
           frase3,
           frase4,
           frase5,
           frase6,
           frase7,
         };

         const char *frasesString(enum Frases frases)
         {
                  switch(frases)
                  {
                           case 0: return"Saco mucho não para em pé";break;
                           case 1: return"Pessoas são fortes com espadas";break;
                           case 2: return"O único planeta do Sistema Solar que não tem nome de um deus, é o nosso";break;
                           case 3: return"Greninja é forte, mas tem ferrementas bem utilizaveis";break;
                           case 4: return"Cerca de 2/3 dos habitantes da Terra nunca viram neve na vida";break;
                           case 5: return"A clareira é um execelente lugar de busca";break;
                           case 6: return"Coincidência ou não, a maior parte dos ataques cardíacos acontecem às segundas-feira";break;
                           case 7: return"A caverna pode ser resposta";break;
                           default: return"ERRO";
                  }
         }
                           if(jogo->reino==jogo->localizacao)
                           {
                                    printf("Sir Luiz diz:\n");
                                    printf("%s \n", frasesString(rand () % 8));
                           }
                           else if(jogo->vila==jogo->localizacao)
                           {
                                    printf("Gabriel Cervejeiro diz:\n");
                                    printf("%s \n", frasesString(rand () % 8));
                           }
                           else if(jogo->floresta==jogo->localizacao)
                           {
                                    printf("Caçador Thony diz:\n");
                                    printf("%s \n", frasesString(rand () % 8));
                           }
                           else if(jogo->clareira == jogo->localizacao)
                           {
                                    printf("Ninja João diz:\n");
                                    printf("%s \n", frasesString(rand () % 8));
                           }
        }
        break;
        default:
            printf("Hein?: \n", ch);
            break;
    }

    return 1;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    printf("João Vitor Pizzoni\nGabriel Wenningkamp\nAnthony Gonçalves\nLuiz Henrique Dutra\n\nnome do jogo: The Duck");
    sleep(4);
    system("cls");
    nomejogo();
    sleep(4);
    system("cls");
    apresentahistoria();
    sleep(4);
    system("cls");
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    srand(time(NULL));
    printf("Utilize um dos seguintes comandos:\n v - Olhar local\n w - Anda para frente\n s - Anda para atras\n a - Anda para esquerda\n d - Anda para direita\n y - Sim\n q - Não aceito missão\n\n z - Ataca\n");


    Mapa *jogo = mapaInit();


    do
    {
        printf("\nO herói %s está com %d de vida\n", jogo->jogador->nome, jogo->jogador->vida);
    }while(processInput(jogo));


    getchar();

    return 0;
}
