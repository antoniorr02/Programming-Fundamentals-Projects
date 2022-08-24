#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double g = 9.80665;
    const double PI = 3.141592;

    double posicionx; //posición inicial del cañon (abscisas)
    double posiciony; //posición inicial del cañon (ordenadas)
    double v; //Velocidad de lanzamiento
    double elevacion; //Ángulo de elevación
    double rota; //Rotación del cañon de entrada
    double rotacion; //Rotación correcta del cañon

    cout << "Introduzca la posición inicial del cañon:" << endl;
    cin >> posicionx >> posiciony;

    cout << "Introduzca la velocidad de lanzamiento (m/s): " << endl;
    cin >> v;

    if(v < 0){
        cout << "Error: la velocidad inicial debe ser positiva" << endl;
    } else {
        cout << "Introduzca el ángulo de elevación en grados: " << endl;
        cin >> elevacion;

        if(elevacion < 0 || elevacion > 90){
            cout << "El lanzamiento no es posible con esa elevacion" << endl;
        } else {
            cout << "Introduzca la rotación del cañon en grados: " << endl;
            cin >> rota;

            if(rota > 180.0 ){
                if(rota >= 360){
                    rotacion = rota - (360*(int(rota/360)));
                    cout << "Angulo rectificado: " << rotacion << "º" << endl;
                } else {
                    rotacion = rota - 360;
                    cout << "Angulo rectificado: " << rotacion << "º" << endl;
                }
            }

            if(rota < -180.0 ){
                if (rota <= -360){
                    rotacion = -(rota + 360*(int(rota/360)));
                    cout << "Angulo rectificado: " << rotacion << "º" << endl;
                } else {
                    rotacion = rota + 360;
                    cout << "Angulo rectificado: " << rotacion << "º" << endl;
                }
            }

            if(rota <= 180 && rota >= -180){
                rotacion = rota;
            }


            double radianes = (elevacion*PI)/180;
            double rad_rotacion = (rotacion*PI)/180;

            double t = ((2*v*sin(radianes))/g); //Tiempo de vuelo
            double y = ((pow(v*sin(radianes),2))/(2*g)); //Altura máxima
            double x = ((pow(v,2)*sin(2*radianes))/g); //Alcance
            double impactox = posicionx + x*sin(rad_rotacion); //Coordenada x del impacto
            double impactoy = posiciony + x*cos(rad_rotacion); //Coordenada y dle impacto

            cout << "----------Resultado del disparo----------" << endl;
            cout << "Tiempo de vuelo: " << t << "segundos" << endl;
            cout << "Altura máxima: " << y << "metros" << endl;
            cout << "Alcance: " << x << "metros" << endl;
            cout << "Impacto: " << impactox << "," << impactoy << endl;


            double objetivox; //Punto fijado(anscisas)
            double objetivoy; //Punto fijado (ordenadas)
            double distanciax; //Distancia grande
            double distanciay; //Distancia pequeña

            cout << "----------Comprobacion de objetivo------------" << endl;
            cout << "Introduzca la localizacion del objetivo:" << endl;
            cin >> objetivox >> objetivoy;
            cout << "Introduzca las distancias de impacto:" << endl;
            cin >> distanciax >> distanciay;

            double exito_disparo = sqrt((pow((impactox-objetivox),2))+(pow((impactoy-objetivoy),2))); //Distancia del punto de impacto



            if(distanciax < 0 || distanciay < 0){
                cout << "Error: las distancias de impacto deben de ser positivas" << endl;
            } else {
                if(distanciax > distanciay){
                    if(exito_disparo < distanciay){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto directo" << endl;
                    }
                    if (distanciax > exito_disparo && distanciay < exito_disparo){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto parcial" << endl;
                    }
                    if (distanciax < exito_disparo){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto fallido" << endl;
                    }
                }
                if(distanciax < distanciay){
                    if(exito_disparo < distanciax){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto directo" << endl;
                    }
                    if (distanciax < exito_disparo && distanciay > exito_disparo){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto parcial" << endl;
                    }
                    if (distanciay < exito_disparo){
                        cout << "Distancia al objetivo: " << exito_disparo << " -> Impacto fallido" << endl;
                    }
                }
            }
        }
    }
}
