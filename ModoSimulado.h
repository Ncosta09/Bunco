#ifndef MODOSIMULADO_H_INCLUDED
#define MODOSIMULADO_H_INCLUDED

#include "FuncionesDados.h"
#include "FuncionesDados_Menu.h"
#include "AnalisisDados.h"
#include "MayorPuntaje.h"
#include "GotoXY.h"

int ModoSimulado(char Jugador3[])        ///IGUAL AL MODO UNJUGADOR, SOLO CAMBIA EL INGRESO DE LOS DADOS!
{

    int Tiros;
    int Rondas=0;
    int Busqueda = 0;
    int Resta_Puntaje = 0;
    int C_Bunco = 0;
    int T_Fallo = 0;
    int PuntosAcumulados=0;
    const int TAM=3;
    int Dados[TAM];


    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "BIENVENIDO AL MODO DE UN JUGADOR" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "INGRESA TU NOMBRE, JUGADOR 1: ";
    cin >> Jugador3;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;

    for(int i=1; i<=6; i++)
    {

        Rondas = i;
        Tiros=0;
        int Puntos_Ronda=0;

        while(Puntos_Ronda<21)
        {

            Tiros++;
            system("cls");
            TirarDadosManual(Dados,TAM);
            system("cls");

            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "PARA EL JUGADOR: " << Jugador3 << " | RONDA N: "  << Rondas << " | TIRO N: " << Tiros << "|" << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;

            MostrarDados(Dados,TAM);
            AnalizarDados(Dados, TAM, Rondas, Busqueda, C_Bunco, Resta_Puntaje, T_Fallo);
            PuntosAcumulados+=Busqueda;
            Puntos_Ronda += Busqueda;


            cout << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "PUNTAJE RONDA: " << Busqueda << " | PUNTAJE TOTAL ACUMULADO: "  << PuntosAcumulados << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "PUNTAJE ACUMULADO POR RONDA: " << Puntos_Ronda << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "VECES QUE OBTUVO BUNCO: " << C_Bunco << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "VECES QUE OBTUVO TIRADA FALLIDA: "<< T_Fallo << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            system("pause");

        }///WHILE

        system("cls");

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

        gotoxy(35,10);
        printf("=============================================");
        gotoxy(35,11);
        printf("RONDA N: ");
        cout << Rondas << endl;
        gotoxy(35,12);
        printf("=============================================");
        gotoxy(35,13);
        printf("PUNTAJE DEL JUGADOR ");
        cout << Jugador3 << ":" << PuntosAcumulados << endl;
        gotoxy(35,14);
        printf("VECES QUE OBTUVO BUNCO: ");
        cout << C_Bunco << endl;
        gotoxy(35,15);
        printf("TIRADAS FALIIDAS: ");
        cout << T_Fallo << endl;
        gotoxy(35,16);
        printf("TIRO N: ");
        cout << Tiros << endl;
        gotoxy(35,17);
        printf("=============================================");

        gotoxy(35,19);
        system("pause");

    }///FOR

    system("cls");
    PuntosAcumulados = PuntosAcumulados - Resta_Puntaje;

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

    gotoxy(35,11);
    printf("=============================================");
    gotoxy(35,12);
    printf("             FIN DE LA PARTIDA!              ");
    gotoxy(35,13);
    printf("=============================================");
    gotoxy(35,14);
    printf("          PUNTAJE FINAL DE ");
    cout << Jugador3 << ":" << PuntosAcumulados << " PUNTOS" << endl;
    gotoxy(35,15);
    printf("=============================================");

    gotoxy(35,17);
    system("pause");
    return 0; //RETORNO AL MENU (?
}

#endif // MODOSIMULADO_H_INCLUDED
