#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef enum tagDirecao
{
    FRENTE, ATRAS, ESQUERDA, DIREITA
} Direcao;

typedef struct tagGreninja
{
    int dano;
    int vida;
}Greninja;

typedef struct tagZabuza
{
    int dano;
    int vida;
} Zabuza;

typedef struct tagCaracteristicas
{
    int dano;
    int vida;
    const char *nome;
} Caracteristicas;

typedef struct tagPartes
{
    Zabuza *zabuza;
    Greninja *greninja;

    const char *descricao;

    struct tagPartes *frente;
    struct tagPartes *atras;
    struct tagPartes *esquerda;
    struct tagPartes *direita;
} Partes;

typedef struct tagMapa
{
    Partes *localizacao;

    int coroa;

    Partes *reino;
    Partes *vila;
    Partes *floresta;
    Partes *caverna;
    Partes *clareira;

    Caracteristicas *greninja;
    Caracteristicas *zabuza;
    Caracteristicas *jogador;
} Mapa;



Caracteristicas * caracterInit(const char *nome, int dano, int vida);
int caracterAtaque(Caracteristicas *si, Caracteristicas *outro);

Partes * partesInit(const char * descricao);
Partes *partesMover(Partes *partes,Direcao direcao);

char apresentahistoria();
char nomejogo();

Mapa * mapaInit();
void mapaDestroi(Mapa *map);
Partes *mapaMover(Mapa *map, Direcao direcao);
int mapaAtaque(Mapa *map);


#endif
