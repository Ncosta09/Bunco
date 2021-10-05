#ifndef MAYORPUNTAJE_H_INCLUDED
#define MAYORPUNTAJE_H_INCLUDED

#include "GotoXY.h"

int MayorPuntuacion(char Jugador[], char Jugador1[], char Jugador2[], int PuntajeObtenido[], int Max[], char GANADOR[], char MaxJugador[], char MaxJugador2[])
{

    ///LADO HORIZONTAL
    for(int i=25; i<90; i++)
    {
        gotoxy(i,3);
        printf("%c",205);
        gotoxy(i,23);
        printf("%c",205);
    }
    ///LADO VERICAL
    for(int i=4; i<23; i++)
    {
        gotoxy(25,i);
        printf("%c", 186);
        gotoxy(90,i);
        printf("%c",186);
    }
    ///ESQUINAS
    gotoxy(25,3);
    printf("%c", 201);
    gotoxy(25,23);
    printf("%c", 200);
    gotoxy(90,3);
    printf("%c",187);
    gotoxy(90,23);
    printf("%c",188);

    if (PuntajeObtenido[0]>Max[0])
    {
        Max[0]=PuntajeObtenido[0];
        strcpy(MaxJugador,Jugador);
    }

    if (PuntajeObtenido[1]>Max[1])
    {
        Max[1]=PuntajeObtenido[1];
        strcpy(MaxJugador2,GANADOR);
    }

    else if (PuntajeObtenido[2]>Max[1])
    {
        Max[1]=PuntajeObtenido[2];
        strcpy(MaxJugador2,GANADOR);
    }


    if(Max[1]!=0 && Max[0]!=0)
    {
        gotoxy(35,11);
        printf("=============================================");
        gotoxy(35,12);
        printf("             MAXIMA PUNTUACION:              ");
        gotoxy(35,13);
        printf("=============================================");
        gotoxy(35,14);
        printf("       MODO UN JUGADOR   :  ");
        cout << MaxJugador << ", " << Max[0] << " PUNTOS" << endl;
        gotoxy(35,15);
        printf("       MODO DOS JUGADORES:  ");
        cout << MaxJugador2 << ", " << Max[1] << " PUNTOS" << endl;
        gotoxy(35,16);
        printf("=============================================");
        gotoxy(35,17);
        system("pause");
    }

    else
    {
        if (Max[1]!=0)
        {
            gotoxy(35,11);
            printf("=============================================");
            gotoxy(35,12);
            printf("             MAXIMA PUNTUACION:              ");
            gotoxy(35,13);
            printf("=============================================");
            gotoxy(35,14);
            printf("      MODO UN JUGADOR   :  ");
            cout << "SIN PUNTUACION" << endl;
            gotoxy(35,15);
            printf("      MODO DOS JUGADORES:  ");
            cout << MaxJugador2 << ", " << Max[1] << " PUNTOS" << endl;
            gotoxy(35,16);
            printf("=============================================");
            gotoxy(35,17);
            system("pause");
        }

        else
        {
            if (Max[0]!=0)
            {
                gotoxy(35,11);
                printf("=============================================");
                gotoxy(35,12);
                printf("             MAXIMA PUNTUACION:              ");
                gotoxy(35,13);
                printf("=============================================");
                gotoxy(35,14);
                printf("       MODO UN JUGADOR   :    ");
                cout << MaxJugador << ":" << Max[0] << " PUNTOS" << endl;
                gotoxy(35,15);
                printf("       MODO DOS JUGADORES:    ");
                cout << "SIN PUNTUACION" << endl;
                gotoxy(35,16);
                printf("=============================================");
                gotoxy(35,17);
                system("pause");
            }

            else
            {
                gotoxy(35,11);
                printf("=============================================");
                gotoxy(35,12);
                printf("             MAXIMA PUNTUACION:              ");
                gotoxy(35,13);
                printf("=============================================");
                gotoxy(35,14);
                printf("       MODO UN JUGADOR   : ");
                cout << " SIN PUNTUACION" << endl;
                gotoxy(35,15);
                printf("       MODO DOS JUGADORES: ");
                cout << " SIN PUNTUACION" << endl;
                gotoxy(35,16);
                printf("=============================================");
                gotoxy(35,17);
                system("pause");
            }
        }
    }

    return 0;
}

#endif // MAYORPUNTAJE_H_INCLUDED
