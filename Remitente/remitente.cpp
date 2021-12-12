// Archivo de encabezado para funciones de entrada y salida
#include<iostream>

//using namespace std, es el de dar acceso al espacio de nombres 
//(namespace) std, donde se encuentra encerrada 
//toda la librería estándar
using namespace std;

// función principal -
// donde comienza la ejecución del programa
int main()
{
    
    std::cout <<"Remitente"<<endl;//pmandar un ensaje al usuario incicandole quien le pide los datos
    string msg, crc, encoded="";//msg-> mensaje, crc-> redundancia ciclica, encoded-> codificado

    cout<<"Ingresa el mensaje = ";//mandamos mensaje para que dijite los binarios
    getline(cin, msg);//getline() esta forma permite solo leer la cadena hasta el carácter que lo limita

    cout<<"Ingresa el polinomio del generador crc = ";//mandamos mensaje para que dijite los binarios
    getline(cin, crc);//getline() esta forma permite solo leer la cadena hasta el carácter que lo limita

    //La función LENGTH se utiliza para manipular series de caracteres de todos los tipos de datos
    //de serie de caracteres (BIT, BLOB y CHARACTER) y devuelve un valor 
    //de entero que proporciona el número de elemento de source_string.
    int m=msg.length(), n=crc.length();

    encoded+=msg;//era mas o igual a msg(mensaje)

    for (int i=1; i<n; i++)//despues de nuestro segundo digito pide las condiciones
        encoded+='0';//por cada recorrido que se le haga se le agregaria un 0
    for (int i=0; i<=encoded.length()-n; )//for para recorrer en los datos de codificado
    {
        for(int j=0; j<n; j++)//for para ir revisando los datos
            //dependiendo de la respues de si es 0 o es uno
            encoded[i+j]= encoded[i+j]==crc[j]? '0':'1';

        for( ; i<encoded.length() && encoded[i]!='1'; i++);//el buble terminara hasta que i sea mayor al arreglo encoded
            //y encoded[i] sea diferente de 1
    }
    cout<<msg+encoded.substr(encoded.length()-n+1);//mostrar el mensaje mas la sub cadena de encoded
    
//return 0; Que viene a decir lo siguiente : La instrucción 
//return provoca que la ejecución abandone la función main (los objetos 
//que se salgan de ámbito serán eliminados). 
	return 0;

     //codigo sin comentarios para mejor visializacion solo copiar y pegar si /**/
/*
#include <iostream>
using namespace std;
int main()
{
    std::cout << "Remitente"<<endl;
    string msg, crc, encoded="";
    cout<<"ingresa el mensaje= ";
    getline(cin,msg);
    cout<<"Ingrese el polinomio del generador crc= ";
    getline(cin,crc);
    int m=msg.length(), n=crc.length();
    encoded+=msg;

    for (int i=1; i<n; i++)
        encoded+='0';
    for(int i=0; i<=encoded.length()-n; ){
        for(int j=0; j<n; j++)
            encoded[i+j]= encoded[i+j]==crc[j]? '0':'1';
        for( ; i<encoded.length() && encoded[i]!='1'; i++);

    }
    cout<<msg+encoded.substr(encoded.length()-n+1);

    return 0;
}

*/
}
