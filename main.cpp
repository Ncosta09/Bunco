#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


using namespace std;

#include "UnJugador.h"
#include "AnalisisDados.h"
#include "GotoXY.h"
#include "MayorPuntaje.h"
#include "ModoSimulado.h"
#include "DosJugadores.h"
#include "FuncionesDados_Menu.h"

void ShowMenu(){

int opcion;
char Jugador[20];
char Jugador1[20];
char Jugador2[20];
char Jugador3[20];
char GANADOR[20];
char MaxJugador[20]={0};
char MaxJugador2[20]={0};
int Max[3]={0};
int PuntajeObtenido[3]={0};

do{
system ("cls");


    ///LADO HORIZONTAL
    for(int i=25; i<90; i++){
        gotoxy(i,3);printf("%c",205);
        gotoxy(i,23);printf("%c",205);
    }
    ///LADO VERICAL
    for(int i=4; i<23; i++){
     gotoxy(25,i); printf("%c", 186);
     gotoxy(90,i); printf("%c",186);
    }
    ///ESQUINAS
     gotoxy(25,3); printf("%c", 201);
     gotoxy(25,23); printf("%c", 200);
     gotoxy(90,3); printf("%c",187);
     gotoxy(90,23); printf("%c",188);

    gotoxy(35,8);printf ("                 *** BUNCO ***               ");
    gotoxy(35,9);printf ("=============================================");
    gotoxy(35,10);printf("                   - MENU -                  ");
    gotoxy(35,11);printf("=============================================");
    gotoxy(35,12);printf("1 - Un jugador");
    gotoxy(35,13);printf("2 - Dos jugadores");
    gotoxy(35,14);printf("3 - Mayor puntuacion");
    gotoxy(35,15);printf("4 - Modo simulado");
    gotoxy(35,16);printf("0 - Salir del juego");
    gotoxy(35,17);printf("=============================================");
    gotoxy(35,18);printf("Opcion: ");

    cin >> opcion;
    system("cls");

        switch(opcion){
        case 1:
            UnJugador(Jugador, PuntajeObtenido); /// LA OPCION 1 LLAMA A LA FUNCION UNJUGADOR QUE CONTIENE JUGADOR1(NOMBRE DEL JUGADOR) Y DEVUELVE EL PUNTAJEOBTENIDO PARA USAR EN EL MAYOR PUNTAJE
            break;
        case 2:
            DosJugadores(Jugador1, Jugador2, PuntajeObtenido, GANADOR);/// LA OPCION 2 LLAMA A LA FUNCION DOSJUGADORES QUE CONTIENE JUGADOR1 Y JUGADOR2(NOMBRES DE LOS JUGADORES) Y DEVUELVE EL PUNTAJEOBTENIDO PARA USAR EN EL MAYOR PUNTAJE
            break;
       case 3:
           MayorPuntuacion(Jugador, Jugador1, Jugador2, PuntajeObtenido, Max, GANADOR, MaxJugador, MaxJugador2);///ESTA FUNCION RECIBE LOS PUNTAJES Y LOS NOMBRES DE LOS JUGADORES Y NOS DA EL MAYOR
            break;
        case 4:
            ModoSimulado(Jugador3);///LO MISMO QUE UN JUGADOR PERO INGRESANDO LOS VALORES DE LOS DADOS MANUALMENTE
            break;

    default:
        break;
        }

}while(opcion != 0);///CUANDO LA OPCION SEA 0 SALE DEL MENU/JUEGO

}

int main(){

/// MENU ----
ShowMenu();

return 0;
 }
