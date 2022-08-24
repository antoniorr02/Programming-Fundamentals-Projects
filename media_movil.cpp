/**
  * @file media_movil.cpp
  * @brief Calcula la media movil de una secuencia de temperaturas
  *
  * @author Antonio Rodríguez Rodríguez
  *         José Manuel ...
  * @date Diciembre-2020
  *
  * Escriba un programa que procesa una secuencia de valores de temperatura hasta que
  * se introduce una temperatura menor que el cero absoluto  (-273.15 grados).
  *
  * Como resultado, escribira una secuencia de datos que corresponde a la media movil
  * con tamano N. Cada valor de la secuencia de esta media movil corresponde a:
  *
  *    - La media de los primeros N datos desde el 0 al N-1,
  *    - la media de los N siguientes desde el 1 al N,
  *    - la media de los N siguientes desde el 2 al N+1,
  *    - etc.
  *
  * Por tanto, si hay D datos, la secuencia resultado tendra D-(N-1) valores. Esta
  * secuencia, ademas, estara tambien terminada con un valor centinela.
  *
  * El problema se puede resolver cargando toda la secuencia de datos y luego
  * calculando la media movil para cada N datos, aunque tambien se podra limitar el
  * tamano de la memoria ocupada evitando tener toda la secuencia, pues si lo es
  * necesario almacenar los ultimos N valores.
  *
  * Nota: En el problema, puede suponer que N es fijo y tiene un valor
  * predeterminado. Asi, evita tener que introducirlo; tanto la entrada como la
  * salida seran una simple secuencia.
  *
  * Un ejemplo de ejecucioqn, con N valiendo 5, es:
  *     1 2 3 4 5 6 7 8 9 -300
  *     3 4 5 6 7 -300
  * donde la primera linea es la entrada y la segunda la salida.
  *
  * Otra ejemplo, ahora con N valiendo 3, es:
  *     -0.04 -0.05 -0.09 -0.06 -0.07 -0.01 0.09 0.07 0.02 0.12 0.15 -300
  *     -0.06 -0.0666667 -0.0733333 -0.0466667 0.00333333 0.05 0.06 0.07 0.0966667 -300
  *
  */
#include<iostream>

using namespace std;

int main(){

    const double cero_abs = -273.15;
    const int n = 5;
    int t_max = 10000;
    double temperaturas[t_max];
    int i = 0;

    cin >> temperaturas[i];

    while(temperaturas[i] > cero_abs){
        i++;
        cin >> temperaturas[i];
    }

    double suma = 0;
    double media = 0;

    int d = 0;
    for(int c = 0; c < (i-(n-1));c++){

        for(int b = 0; b < n; b++){

            suma = suma + temperaturas[b];
            media = suma/n;
        }

        cout << media << " ";
        suma = 0;

        for(int t = 0; t < i; t++){
            temperaturas[t] = temperaturas[t+1];
        }

    }
    cout << cero_abs << endl;

}
