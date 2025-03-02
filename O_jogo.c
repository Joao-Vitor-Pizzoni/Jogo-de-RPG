#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "O_jogo.h"

Caracteristicas * caracterInit(const char *nome, int vida, int dano)
{
    Caracteristicas *c = calloc(1, sizeof(Caracteristicas));
    c->dano = dano;
    c->vida = vida;
    c->nome = nome;
    return c;
}

Partes * partesInit(const char * descricao)
{
    Partes *partes = calloc(1, sizeof(Partes));
    partes->descricao = descricao;
    return partes;
}

Mapa * mapaInit()
{
    Mapa *map = calloc(1, sizeof(Mapa));


    map->reino = partesInit("Reino\nGostaria de falar com Sir Luiz?");
    map->vila = partesInit("A vila\nGostaria de falar com Cervejeiro Gabriel?");
    map->floresta = partesInit("A floresta\nGostaria de falar com o Caçador Thony?");
    map->caverna = partesInit("A caverna, com o Zabuza");
    map->clareira = partesInit("A clareira, com o Greninja\nGostaria de falar com o Ninja João?");
    map->coroa = 1;

    map->zabuza = caracterInit("Zabuza momochi, o demônio do gás oculto", 10, 10);

    map->greninja = caracterInit("Greninja, o sapo ninja", 10, 10);


    map->jogador = caracterInit("Duck", 50, 4);


    map->reino->frente = map->vila;

    map->vila->frente= map->floresta;
    map->vila->atras = map->reino;

    map->floresta->esquerda = map->caverna;
    map->floresta->direita = map->clareira;
    map->floresta->atras = map->vila;

    map->caverna->direita = map->floresta;
    map->caverna->zabuza = map->zabuza;

    map->clareira->esquerda = map->floresta;
    map->clareira->greninja = map->greninja;

    map->localizacao = map->reino;

    return map;
}

void mapaDestroi(Mapa *map)
{
    free(map->reino);
    free(map->floresta);
    free(map->caverna);
    free(map->clareira);
    free(map->vila);

    free(map->greninja);
    free(map->zabuza);
    free(map->jogador);
}

Partes *mapaMover(Mapa *map, Direcao direcao)
{
    Partes *localizacao = map->localizacao;
    Partes *proximo = NULL;

    proximo = partesMover(localizacao, direcao);

    if(proximo)
    {
        map->localizacao = proximo;
    }

    return proximo;
}

int mapaAtaque(Mapa *map)
{
    Partes *localizacao = map->localizacao;
    if(localizacao->zabuza)
    {
        if(!caracterAtaque(map->jogador, map->zabuza))
        {
            if(caracterAtaque(map->zabuza, map->jogador))
                {
                     return 3;
                }
        }
        else
        {
            if(map->coroa==1)
            {
                  map->coroa = 0;
                  return 4;
            }

        }
        return 1;
    }
    else if(localizacao->greninja)
    {
             if(!caracterAtaque(map->jogador,map->greninja))
             {
                      if(caracterAtaque(map->greninja, map->jogador))
                           {
                             return 3;
                           }

             }
             else
             {
                           if(map->jogador->dano<10)
                           {
                                    return 2;
                           }
             }
             return 0;
    }
    else
    {
        printf("Você espeta o ar. Nada acontece.\n");
        return 0;
    }
}
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
Partes *partesMover(Partes *partes, Direcao direcao)
{
    Partes *proximo = NULL;

    if(direcao == FRENTE && partes->frente)
    {
        printf("Você vai para frente, em:");
        proximo = partes->frente;
    }
    else if(direcao == ATRAS && partes->atras)
    {
        printf("Você vai para atrás, em:");
        proximo = partes->atras;
    }
    else if(direcao == DIREITA && partes->direita)
    {
        printf("Você vai para direita, em:");
        proximo = partes->direita;
    }
    else if(direcao == ESQUERDA && partes->esquerda)
    {
        printf("Você vai para esquerda, em:");
        proximo = partes->esquerda;
    }
    else
    {
        printf("Você não pode ir nesta direção.");
        proximo = NULL;
    }

    if(proximo)
        printf(" %s\n", proximo->descricao);

    return proximo;
}

int caracterAtaque(Caracteristicas *si, Caracteristicas *outro)
{

    int ataque = rand() % si->dano;
    outro->vida -= ataque;



    if(outro->vida > 0)
    {
        printf("%s ataca %s com %d de dano!\n", si->nome, outro->nome, ataque);
        printf("%s ainda está vivo.\n", outro->nome);
        return 0;
    }
    else
    {
        printf("%s morreu!\n", outro->nome);
        return 1;
    }

}
char nomejogo()
{
 //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("                                         ____                             _    __              \n");
printf("                    ________    _    _  |  __|     __              ___   | |  |  |             \n");
printf("                   |__    __|  | |  | | | |__     |  |   ||  ||   | __|  | |_|  |                \n");
printf("                      |  |     | |__| | |  __|    |   |  ||  ||  | |     |     |                  \n");
printf("                      |  |     |  __  | | |__     |   |  ||__||  | |__   | || |               \n");
printf("                      |__|     |_|  |_| |____|    |__|   |____|   |___|  |_| |_|                   \n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
}
char apresentahistoria()
{
printf("Em um reino muito distante, havia um rei com uma coroa cheia de diamantes\n");sleep(2);
printf("Porém sua coroa foi roubada por um ladrão chamado Zabuza\n");sleep(2);
printf("Então surge um herói chamado Duck \n");sleep(2);
printf("O rei pede para Duck ir buscar a coroa\n");sleep(2);
printf("Você aceita a missão do rei?\n");sleep(2);



}

