/*
* Hw6: Figuras en 3D
* Ryan Rolón Rosa
* 801-24-1373
*
* Colaboraciones:
* - Lillian González
* - https://github.com/CCOM3033-002/hw6-ryanrolon0
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Prototipo de las funciones de volumen
double volumen(double);
double volumen(double, double);
double volumen(double, double, double);

// Prototipo de las funciones de area
double area(double);
double area(double, double);
double area(double, double, double);

// La variable constante de pi
const double PI = 3.14159;

int main() {
    // Variables del programa
    char figura = 'a', opcion = 'a';
    double radio_largo, altura, ancho, resultado;

    // Proposito del programa
    cout << "Este programa calcula el volumen y el área de la supercicie de tres figuras.\n\n";

    // Pide que escoja
    cout << "Escoja una figura:\n";

    // Primer menu: figuras
    switch (figura) {
        case 'a':
        cout << "  a. Cilindro\n";

        case 'b':
        cout << "  b. Esfera\n";

        case 'c':
        cout << "  c. Prisma Rectangular\n";
    }

    // Input de la figura
    cout << "Selección: ";
    cin >> figura;
    // Input validation del input anterior
    while (figura < 97 || figura > 99) {
        cout << "Debes elegir una de las opciones del menú.\n\n";

        cout << "Selección: ";
        cin >> figura;
    }

    // Pide que escoja
    cout << "\nEscoga entre los siguientes opciones:\n";

    // Segundo menu: Volumen o area
    switch (opcion) {
        case 'a':
        cout << "  a. Volumen\n";

        case 'b':
        cout << "  b. Area de la superficie\n";
    }

    // Input de las opciones
    cout << "Selección: ";
    cin >> opcion;
    // Input validation del input anterior
    while (opcion < 97 || opcion > 98) {
        cout << "Debes elegir una de las opciones del menú.\n\n";

        cout << "Selección: ";
        cin >> opcion;
    }

    // Obliga que el resultado tenga dos espacios decimales
    cout << setprecision(2) << fixed;

    // Si el usuario escogió el cilindro
    if (figura == 'a') {
        // Pide input de las medidas
        cout << "Entre el radio del cilindro: ";
        cin >> radio_largo;

        cout << "Entre la altura del cilindro: ";
        cin >> altura;

        // Input validation
        while (radio_largo <= 0 || altura <= 0) {
            cout << "Los numeros no pueden ser negativos.\n";

            cout << "Entre el radio del cilindro: ";
            cin >> radio_largo;

            cout << "Entre la altura del cilindro: ";
            cin >> altura;
        }

        // Si el usuario escogió volumen
        if (opcion == 'a') {
            // Calcula el volumen
            resultado = volumen(radio_largo, altura);
            // Despliega el resultado 
            cout << "El volumen del cilindro es: " << resultado << endl;
        }
        // Si el usuario escogió area
        else {
            // Calcula el area
            resultado = area(radio_largo, altura);
            // Despliega el resultado
            cout << "El area del cilindro es: " << resultado << endl;
        }
    }
    // Si el usuario escogió la esfera
    else if (figura == 'b') {
        // Pide input de las medidas
        cout << "Entre el radio de la esfera: ";
        cin >> radio_largo;

        // Input validation
        while (radio_largo <= 0) {
            cout << "Los numeros no pueden ser negativos.\n";

            cout << "Entre el radio de la esfera: ";
            cin >> radio_largo;
        }

        // Si el usuario escogió volumen
        if (opcion == 'a') {
            // Calcula el area
            resultado = volumen(radio_largo);
            // Despliega el resultado
            cout << "El volumen de la esfera es: " << resultado << endl;
        }
        // Si el usuario escogió area
        else {
            resultado = area(radio_largo);
            // Despliega el resultado
            cout << "El area de la esfera es: " << resultado << endl;
        }
    }
    // Si el usuario escogió la prima rectangular
    else {
        cout << "Entre el largo de la prisma rectangular: ";
        cin >> radio_largo;

        cout << "Entre el ancho de la prisma rectangular: ";
        cin >> ancho;

        cout << "Entre la altura de la prisma rectangular: ";
        cin >> altura;

        // Input validation
        while (radio_largo <= 0 || altura <= 0 || ancho <= 0) {
            cout << "Los numeros no pueden ser negativos.\n";

            cout << "Entre el largo de la prisma rectangular: ";
            cin >> radio_largo;

            cout << "Entre el ancho de la prisma rectangular: ";
            cin >> ancho;

            cout << "Entre la altura de la prisma rectangular: ";
            cin >> altura;
        }

        // Si el usuario escogió volumen
        if (opcion == 'a') {
            // Calcula el area
            resultado = volumen(radio_largo, ancho, altura);
            // Despliega el resultado
            cout << "El volumen del prisma rectangular es: " << resultado << endl;
        }
        // Si el usuario escogió area
        else {
            resultado = area(radio_largo, ancho, altura);
            // Despliega el resultado
            cout << "El area del prisma rectangular es: " << resultado << endl;
        }
    }
    return 0;
}

/* Input: radio esfera
*  Output: volumen esfera
*/
double volumen(double radio) {
    return (4.0/3.0) * PI * pow(radio, 3);
}

/* Input: radio cilindro
*  Output: volumen cilindro
*/
double volumen(double radio, double altura) {
    return PI * pow(radio, 2) * altura;
}

/* Input: radio prismo rectangular
*  Output: volumen prismo rectangular
*/
double volumen(double largo, double ancho, double altura) {
    return largo * ancho * altura;
}

/* Input: radio esfera
*  Output: area esfera
*/
double area(double radio) {
    return 4 * PI * pow(radio, 2);
}

/* Input: radio cilindro
*  Output: area cilindro
*/
double area(double radio, double altura) {
    return 2 * PI * radio * (radio + altura);
}

/* Input: radio prismo rectangular
*  Output: area prismo rectangular
*/
double area(double largo, double ancho, double altura) {
    return 2 * (ancho * largo + altura * largo + altura * ancho);
}
