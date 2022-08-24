#include<iostream>

using namespace std;

int main(){

    const double cero_abs = -273.15;
    double temperaturas, nueva_temperatura;
    int f = 1;

    cin >> temperaturas;

    while(temperaturas > cero_abs){

        nueva_temperatura = temperaturas;

        cin >> temperaturas;

        if(nueva_temperatura == temperaturas){
            f++;
        }

        if(nueva_temperatura != temperaturas){
            cout << f << " " << nueva_temperatura << " ";
            f = 1;
        }

    }

    cout << "0" << endl;

}
