#include <iostream>
#include <string>
#include <cstdlib> // incluye rand
#include <ctime> // incluye time

using namespace std;

const int TAMANIO = 100;

class Bolsa{
private:
    string vector_privado[TAMANIO] = {
         "caballero",  "Dulcinea",   "historia",   "escudero",
         "rocinante",  "adelante",   "gobernador", "andantes",
         "voluntad",   "capitulo",   "menester",   "doncella",
         "caballeria", "castillo",   "Fernando",   "finalmente",
         "aventura",   "hermosura",  "palabras",   "gobierno",
         "intencion",  "cardenio",   "pensamientos", "Luscinda",
         "lagrimas",   "aposento",   "aventuras",  "quisiera",
         "libertad",   "desgracia",  "entendimiento", "pensamiento",
         "licencia",   "Mercedes",   "semejantes", "silencio",
         "valeroso",   "doncellas",  "labrador",   "caballerias",
         "cristiano",  "cristianos", "discreto",   "hicieron",
         "llegaron",   "quisiere",   "espaldas",   "muestras",
         "escuderos",  "discurso",   "grandeza",   "altisidora",
         "princesa",   "haciendo",   "renegado",   "provecho",
         "quedaron",   "resolucion", "presente",   "encantadores",
         "enamorado",  "valiente",   "encantado",  "molino",
         "licenciado", "necesidad",  "responder",  "discrecion",
         "ejercicio",  "hacienda",   "posadero",   "Rocinante",
         "presencia",  "historias",  "presentes",  "verdadero"};

public:

    int Numero(){
        srand(time(0));
        int n = rand()%77;
        return n;
    }

    string PalabraAleatoria(){
        string palabra_aleatoria = vector_privado[Numero()];
        return palabra_aleatoria;
    }

};


class Ahorcado{

private:

    Bolsa objeto;
    string palabra = objeto.PalabraAleatoria();
    int fallos;
    string abecedario;

public:

    Ahorcado()
      :fallos(0),
      abecedario("a b c d e f g h i j k l m n o p q r s t u v w x y z") {
   }

   string PalabraAdivinar(){

        palabra[0] = tolower(palabra[0]); // Hace el cambio para palabras con mayúsculas en bolsa.
        return palabra;

   }

    char CambiaMinuscula(char letra){

        letra = tolower(letra);
        return letra;

    }

    string DibujaLinea(){
        string line;
        for (int i=0; i<palabra.size(); i++)
            line.push_back('-');
        return line;
    }


    bool LetraEquivocada(char letra){
        bool dice_fallo;
        if(letra > 'z' || letra < 'a')
            dice_fallo = true;
        else
            dice_fallo = false;
        return dice_fallo;
    }


    string CambiarLineaPorLetra(char letra, string linea){
        for(int i=0; i<palabra.size(); i++){
            if (letra == palabra[i])
                linea[i] = letra;
        }
        return linea;
    }


    string EliminaLetra(char letra){
        for (int i=0; i<abecedario.size(); i++){
            if(letra == abecedario[i])
                abecedario[i] = '-';
        }
        return abecedario;
    }


    void SumaFallo(){
        fallos++;
    }


    int MuestraFallos(){
        return fallos;
    }


    void DibujaFallo0(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "        |\n"
            "        |\n"
            "        |\n"
            "        |\n"
            "=========" << endl;
    }
    void DibujaFallo1(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "    O   |\n"
            "        |\n"
            "        |\n"
            "        |\n"
            "========="  << endl;
    }
    void DibujaFallo2(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "    O   |\n"
            "   /|   |\n"
            "        |\n"
            "        |\n"
            "=========" << endl;
    }
    void DibujaFallo3(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "    O   |\n"
            "   /|\\  |\n"
            "        |\n"
            "        |\n"
            "========="  << endl;
    }
    void DibujaFallo4(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "    O   |\n"
            "   /|\\  |\n"
            "   /    |\n"
            "        |\n"
            "========="   << endl;
    }
    void DibujaFallo5(){
        cout <<
            "    +___+\n"
            "    |   |\n"
            "    O   |\n"
            "   /|\\  |\n"
            "   / \\  |\n"
            "        |\n"
            "========="  << endl;
    }
    void DibujaFallo(){
        if(fallos==0)
            DibujaFallo0();
        else if(fallos==1)
            DibujaFallo1();
        else if(fallos==2)
            DibujaFallo2();
        else if(fallos==3)
            DibujaFallo3();
        else if(fallos==4)
            DibujaFallo4();
        else
            DibujaFallo5();
    }

};


int main(){

    char repetir = 'y';

    while(repetir == 'y'){

        Ahorcado juego1;

        char letra; string linea_palabra; string abc;
        cout << "Bienvenidos al juego del ahorcado donde tiene que intentar "
        "adivinar la palabra secreta. Recuerda! Solo puedes fallar 5 veces" << endl;
        linea_palabra = juego1.DibujaLinea();

        cout << linea_palabra << endl;
        while (linea_palabra != juego1.PalabraAdivinar() && juego1.MuestraFallos() < 5){

            cout << "Introduce una letra: ";
            cin >> letra;
            letra = juego1.CambiaMinuscula(letra);

            if(juego1.LetraEquivocada(letra) == true)
                cout << "Debes introducir una LETRA obligatoriamente" << endl;


            else{
                cout << juego1.CambiarLineaPorLetra(letra, linea_palabra) <<  endl;

                if (linea_palabra == juego1.CambiarLineaPorLetra(letra, linea_palabra)){
                    juego1.SumaFallo();
                    cout << "Te has EQUIVOCADO, llevas: " << juego1.MuestraFallos() << " fallos" << endl;
                    juego1.DibujaFallo();
                }
                else{
                    linea_palabra = juego1.CambiarLineaPorLetra(letra, linea_palabra);
                    juego1.DibujaFallo();
                }
                cout << juego1.EliminaLetra(letra) << endl;
            }
        }

        if(linea_palabra == juego1.PalabraAdivinar()){
            cout << "ENHORABUENA, HAS COMPLETADO EL PANEL" << endl;
            cout << "Lo has terminado con: " << juego1.MuestraFallos() << " fallos" << endl;
        }
        else{
            cout << "Lo sentimos, ha alcanzado el tope de 5 fallos y ha PERDIDO" << endl;
            juego1.DibujaFallo();
        }

        cout << "Quiere jugar de nuevo?? y/n" << endl;
        cin >> repetir;
        if(repetir != 'y' || repetir != 'n'){
            while(repetir != 'y' && repetir != 'n'){
                cin >> repetir;
            }
        } // Obliga al usuario a decir si quiere volver a jugar mediante y/n.
    }

}
