#include <stdio.h>

#define LONG_NOMBRE 30
#define CANT_DANIOS 3
#define CANT_PODERES 3

typedef struct{
    char nombre[LONG_NOMBRE];
    int puntos;
}atributos_t;

typedef struct{
    char nombre[LONG_NOMBRE];
    int vida;
    atributos_t danios[CANT_DANIOS];
    atributos_t poderes[CANT_PODERES];
}monster_t;

int pelea(monster_t monsters [] ,int monster1,int monster2){
    int ataque1, defensa1, puntaje1;
    int ataque2, defensa2, puntaje2;
    int ganador;

    printf("Elige un ataque:\n");
    for(int i=0; i<CANT_DANIOS; i++){
        printf("Escribe %d para %s - ", (i+1), monsters[monster1].danios[i].nombre);
    }
    printf("\n");
    scanf("%d", &ataque1);

    printf("Elige una defensa:");
    for(int i=0; i<CANT_PODERES; i++){
        printf("Escribe %d para %s - ", (i+1), monsters[monster1].poderes[i].nombre);
    }
    printf("\n");
    scanf("%d", defensa1);

    puntaje1=monsters[monster1].danios[ataque1].puntos;
    puntaje1*=(100-monsters[monster2].poderes[defensa2].puntos)/100;
    puntaje2=monsters[monster2].danios[ataque2].puntos;
    puntaje2*=(100-monsters[monster1].poderes[defensa1].puntos)/100;

    if(puntaje1>puntaje2){
        monsters[monster2].vida -=puntaje1;
        ganador=monster1;
    }else{
        monsters[monster1].vida -=puntaje2;
        ganador=monster2;
    }
    return ganador;
}
