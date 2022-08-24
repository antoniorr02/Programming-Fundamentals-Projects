#include <iostream>

using namespace std;

int main()
{
    const int MAX_LEN=100; const double CERO_ABS=-273.15; const int N=5;
    double temperatura[MAX_LEN]; double recuperar[MAX_LEN]; int cant_usada=0; double mediana;

    cout << "Introduce las temperaturas: ";  //introducimos las temperaturas
    cin >> temperatura[cant_usada];
    while (temperatura[cant_usada] > CERO_ABS){
        cant_usada++;
        cin >> temperatura[cant_usada];
    }

     for(int i=0; i<cant_usada; i++)
        recuperar[i] = temperatura[i];

    double minimo; int pos_minimo; double intercambiado;

    for(int i=0; i<cant_usada-(N-1); i++){
        for(int izda=0; izda<N; izda++){       //ordenamos las N temperaturas seleccionadas mediante el metodo de selección.
            minimo = temperatura[izda];
            pos_minimo = izda;
            for(int j=izda+1; j<N; j++){
                if(temperatura[j] < minimo){
                    minimo = temperatura[j];
                    pos_minimo = j;
                }
            }
            intercambiado = temperatura[izda];
            temperatura[izda] = temperatura[pos_minimo];
            temperatura[pos_minimo] = intercambiado;
        }
        for(int i=0; i<N; i++)
            mediana = temperatura[(N-1)/2];
        cout << mediana << " ";  //mostramos la mediana calculamos


        for(int i=0; i<cant_usada; i++)
            temperatura[i] = recuperar[i]; //Recuperamos el vector inicial.

        for(int i=0; i<cant_usada; i++){
            temperatura[i] = temperatura[i+1]; //desplazamos todos los datos una posicion a la izquierda para que sea mediana movil
            recuperar[i] = temperatura[i];
        }
    }

    cout << CERO_ABS;
}


