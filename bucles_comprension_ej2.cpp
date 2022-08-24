#include <iostream>
using namespace std;

int main(){

    const double cero_abs = 0;
    double temperaturas, frecuencia;


    cout << "Introduzca las frecuencias seguida "
    "de las temperaturas" << endl;
    cin >> frecuencia;

    if(frecuencia >= 1){

        cin >> temperaturas;

        if(temperaturas == cero_abs){

           cout << "-300" << endl;

        } else {

            while(temperaturas > cero_abs && frecuencia > cero_abs){

                if(frecuencia >= 1){
                    for(int i = 0; i < frecuencia; i++){
                        cout <<  temperaturas << " ";
                    }
                } else {
                    cout << "Error inesperado, valor de la "
                "fecuencia sin sentido" << endl;
                temperaturas = cero_abs;
                }

                cin >> frecuencia;

                int n = frecuencia;
                if(frecuencia != n){
                    cout << "\nError ineperado, la "
                    "frecuencia debe ser un entero" << endl;
                    temperaturas = cero_abs;
                }

                if(frecuencia == 0){
                    cout << "-300" << endl;
                    temperaturas = cero_abs;
                }

                cin >> temperaturas;

                if(temperaturas == 0){
                    cout << "-300" << endl;
                    temperaturas = cero_abs;
                }

            }

        }

    } else {

        cout << "Error inesperado, valor de la "
        "fecuencia sin sentido" << endl;
    }

}
