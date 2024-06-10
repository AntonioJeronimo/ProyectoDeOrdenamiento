#include <iostream>
using namespace std;
void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << arr[i] << "]\t";
    }
    cout << endl;
}
bool validarNumeroRepetido(int arr[], int n, int numero) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == numero) {
            return true;
        }
    }
    return false;
}
void metodoSeleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
        cout << "Vueltas: " << i + 1 << " - ";
        mostrarArreglo(arr, n);
    }
}
void metodoInsercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "Vueltas: " << i << " - ";
        mostrarArreglo(arr, n);
    }
}
void metodoBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambiado = true;
            }
        }
        if (!intercambiado) {
            break;
        }
        cout << "Vueltas: " << i + 1 << " - ";
        mostrarArreglo(arr, n);
    }
}
int main(){
    int n;
    int arregloOriginal[20];
    int arr[20];
    do {
        cout << "Ingrese la cantidad de elementos del arreglo (entre 2 y 20): ";
        cin >> n;
        if (n < 2 || n > 20) {
            cout << "El numero ingresado no esta dentro del rango permitido. Intente nuevamente." << endl;
        }
    } while (n < 2 || n > 20);
    for (int i = 0; i < n; i++) {
        int numero;
        bool repetido;
        do {
            cout << "Ingrese el elemento " << i + 1 << ": ";
            cin >> numero;
            repetido = validarNumeroRepetido(arr , i, numero);
            if (repetido) {
                cout << "El numero ingresado ya existe en el arreglo. Intente nuevamente." << endl;
            } else {
            	arregloOriginal[i] = numero;
                arr[i] = numero;
            }
        } while (repetido);
        mostrarArreglo(arr, i + 1);
    }
    system("cls");
    cout << "Arreglo inicial: ";
    
    int opcion;
    do {
    	
    	for (int i = 0; i < n ; i++) {
            arr[i] = arregloOriginal[i];
    	}
		mostrarArreglo(arr, n);
    	cout << "---------------------------------------" << endl;
        cout << "|Seleccione el metodo de ordenamiento:|" << endl;
		cout << "|-------------------------------------|" << endl;
        cout << "|1. Metodo de seleccion               |" << endl;
        cout << "|2. Metodo de insercion               |" << endl;
        cout << "|3. Metodo de burbuja                 |" << endl;
        cout << "|4. Salir                             |" << endl;
        cout << "|-------------------------------------|" << endl;
        cout << "|Opcion:                              |" << endl;
        cout << "---------------------------------------" << endl;
        cin >> opcion;
        system ("cls");
        switch (opcion) {
            case 1:
            	system("cls");
            	mostrarArreglo(arr, n);
                cout << "Metodo de seleccion:" << endl;
                metodoSeleccion(arr, n);
                cout << "Arreglo ordenado: ";
                mostrarArreglo(arr, n);
                break;
            case 2:
                cout << "Metodo de insercion:" << endl;
                metodoInsercion(arr, n);
                cout << "Arreglo ordenado: ";
                mostrarArreglo(arr, n);
                break;
            case 3:
                cout << "Metodo de burbuja:" << endl;
                metodoBurbuja(arr, n);
                cout << "Arreglo ordenado: ";
                mostrarArreglo(arr, n);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
            	system("cls");
            	cout << "---------------------------------------" << endl;
                cout << "|Opcion invalida. Intente nuevamente. |" << endl;
                cout << "---------------------------------------" << endl;
        }
        cout << endl;
    } while (opcion != 4);
	return 0;
}
