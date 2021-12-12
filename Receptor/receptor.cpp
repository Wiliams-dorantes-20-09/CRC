// Archivo de encabezado para funciones de entrada y salida
#include <iostream>

//using namespace std, es el de dar acceso al espacio de nombres
//(namespace) std, donde se encuentra encerrada
//toda la librería estándar
using namespace std;

// función principal -
// donde comienza la ejecución del programa
int main()
{

    std::cout << "Receptor" << endl; //pmandar un ensaje al usuario incicandole quien le pide los datos
    string crc, encoded = "";    //msg-> mensaje, crc-> redundancia ciclica, encoded-> codificado

    cout << "Ingresa el mensaje = "; //mandamos mensaje que nos arroja el remitente 
    getline(cin, encoded);               //getline() esta forma permite solo leer la cadena hasta el carácter que lo limita

    cout << "Ingresa el polinomio del generador crc = "; //mandamos mensaje para que dijite los binarios
    getline(cin, crc);  //getline() esta forma permite solo leer la cadena hasta el carácter que lo limita

    for(int i=0; i<=encoded.length()-crc.length(); ){
        for(int j=0; j<crc.length(); j++)
            encoded[i+j]= encoded[i+j]==crc[j]? '0':'1';//si ambos son iguales, sera 0 o 1
        for( ; i<encoded.length() && encoded[i]!='1'; i++);//doble condicion
    }

    for(char i: encoded.substr(encoded.length()-crc.length()+1))//nos decodifica la cadena 
        if (i!='0'){// si i es diferente de 0 significa que
            cout<<"Error en comunucacion....."; //hubo error en envio
            return 0;
        }
    cout<<"Sin errores informacion completa!!"; //nuestrop mensaje no tubo errores
    //return 0; Que viene a decir lo siguiente : La instrucción
    //return provoca que la ejecución abandone la función main (los objetos
    //que se salgan de ámbito serán eliminados).
    return 0;

    //codigo sin comentarios para mejor visializacion solo copiar y pegar si /**/
/*
#include<iostream>
using namespace std;

int main ()
{   
    std::cout << "Receptor!"<<endl;
    string crc, encoded;
    cout<<"ingresa el mensaje = ";
    getline(cin,encoded);
    cout<<"Ingrese el polinomio del generador crc= ";
    getline(cin,crc);

    for(int i=0; i<=encoded.length()-crc.length(); ){
        for(int j=0; j<crc.length(); j++)
            encoded[i+j]= encoded[i+j]==crc[j]? '0':'1';
        for( ; i<encoded.length() && encoded[i]!='1'; i++);
    }
    for(char i: encoded.substr(encoded.length()-crc.length()+1))
        if (i!='0'){
            cout<<"Error en comunucacion.....";
            return 0;
        }
    cout<<"Sin errores informacion completa!!";
    return 0;
}

*/
}
