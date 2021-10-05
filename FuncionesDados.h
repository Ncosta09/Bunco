#ifndef FUNCIONESDADOS_H_INCLUDED
#define FUNCIONESDADOS_H_INCLUDED

/// -- FUNCIONES DADOS
void TirarDados(int VecDados[], int TAM)        ///BUSCA ALEATORIAMENTE 3(CANTIDAD DE DADOS) NUMEROS
{

    int i;
    srand(time(NULL));
    for(i=0; i<TAM; i++)
    {
        VecDados[i]=(rand()%6)+1;
    }
}

///FUNCIONES DE DADOS MANUALES ------------------------------------------------------------------------------------------

/// -- FUNCIONES DADOS
void TirarDadosManual(int VecDados[], int TAM)
{

    cout << "CARGAR LOS DADOS: " << endl;

    for(int i=0; i<TAM; i++)                            ///RECORRE EL VECTOR PARA CARGARLO
    {

        cout<<"INGRESAR DADO "<< i+1 << ":";            ///INGRESAR LOS NUMEROS DE LOS DADOS
        cin>>VecDados[i];                               ///LOS CARGA EN EL VECTOR SEGUN EL NUMERO DEL VECTOR (POR EL INDICE)
    }
    cout << endl;
    cout << endl;

}

#endif // FUNCIONESDADOS_H_INCLUDED
