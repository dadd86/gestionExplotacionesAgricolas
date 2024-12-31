#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Definiciones de constantes para los tamaños máximos de los diferentes campos
#define MAX_LETRAS 20
#define MAX_EXPLOTACIONES 200
#define MAX_NIF 20
#define MAX_DENOMINACION 100
#define MAX_POBLACION 50
#define MAX_CODIGO_POSTAL 10
#define MAX_TELEFONO 15
#define MAX_DIRECCION 150
#define MAX_REFERENCIA_CATASTRAL 20

// Estructura para representar una fecha
typedef struct {
    int dia;        // Día de la fecha
    int mes;        // Mes de la fecha
    int anio;       // Año de la fecha
} fecha;

// Tipo palabra para almacenar textos con longitud controlada
typedef struct {
    char letras[MAX_LETRAS];   // Arreglo de caracteres para almacenar el texto
    int longitud;              // Longitud actual del texto
} palabra;

// Tipo para representar una explotación agrícola
typedef struct {
    char referenciaCatastral[MAX_REFERENCIA_CATASTRAL]; // Código de referencia catastral
    palabra denominacionColoquial;                      // Denominación coloquial de la explotación
    float superficieProductiva;                         // Superficie productiva en hectáreas
    float importeCompra;                                // Importe pagado por la explotación
    fecha fechaCompra;                                  // Fecha de compra de la explotación
    bool esRegadio;                                     // Indica si es un terreno de regadío
} tExplotacion;

// Tipo para representar una empresa agraria
typedef struct {
    char nif[MAX_NIF];                              // NIF de la empresa
    palabra denominacion;                           // Denominación de la empresa
    palabra poblacion;                              // Población donde se encuentra la empresa
    char codigoPostal[MAX_CODIGO_POSTAL];           // Código postal de la empresa
    char telefono[MAX_TELEFONO];                    // Teléfono de contacto de la empresa
    char direccion[MAX_DIRECCION];                  // Dirección de la empresa
    tExplotacion explotaciones[MAX_EXPLOTACIONES];  // Array de explotaciones agrícolas
    int numExplotaciones;                           // Número actual de explotaciones
} tEmpresaAgraria;

// Función para ingresar los datos de tExplotación agrícola
void ingresarExplotacion(tExplotacion *explotacion) {
    // Solicita y almacena datos de la explotación en la estructura apuntada por *explotacion
    // Solicita y almacena la referencia catastral
    printf("Introduce la referencia catastral: ");
    scanf("%s", explotacion->referenciaCatastral);
    // Solicita y almacena la denominación coloquial
    printf("Introduce la denominación coloquial: ");
    scanf("%s", explotacion->denominacionColoquial.letras);
    // Guarda la longitud de la cadena introducida
    explotacion->denominacionColoquial.longitud = strlen(explotacion->denominacionColoquial.letras); // La función strlen (que viene de la biblioteca estándar de C <string.h>)
                                                                                                     //calcula la longitud de la cadena de caracteres especificada
                                                                                                     // Este fragmento asigna el valor obtenido por strlen al campo longitud de la estructura denominacionColoquial.
                                                                                                     //Esto actualiza la estructura explotacion para reflejar la longitud real de la cadena almacenada en letras.
    // Solicita y almacena la superficie productiva
    printf("Introduce la superficie productiva: ");
    scanf("%f", &explotacion->superficieProductiva);
    // Solicita y almacena el importe de compra
    printf("Introduce el importe de compra: ");
    scanf("%f", &explotacion->importeCompra);
    // Solicita y almacena la fecha de compra
    printf("Introduce la fecha de compra (dd mm aaaa): ");
    scanf("%d %d %d", &explotacion->fechaCompra.dia, &explotacion->fechaCompra.mes, &explotacion->fechaCompra.anio);
     // Pregunta si la explotación es un terreno de regadío
    int respuestaRegadio;
    int validacion;
    do {
        printf("Es un terreno de regadío? (1 para Sí, 0 para No): ");
        validacion = scanf("%d", &respuestaRegadio);
        // Limpia el buffer de entrada
        while (getchar() != '\n');
        if (validacion != 1 || (respuestaRegadio != 0 && respuestaRegadio != 1)) {
            // Se muestra un mensaje de error si la entrada no es válida
            printf("Por favor, ingrese 1 para Sí o 0 para No.\n");
            // Se restablece la variable de validación
            validacion = 0;
        }
    } while (!validacion);
    explotacion->esRegadio = respuestaRegadio; // Asigna la respuesta al campo esRegadio
}

// Función para ingresar los datos de varias explotaciones agrícolas
void ingresarExplotaciones(tEmpresaAgraria *empresa) {
    char respuesta[3];
    empresa->numExplotaciones = 0; //->: Es un operador en C que se utiliza para acceder a los miembros (campos) de una estructura a través de un puntero
    do {
        if (empresa->numExplotaciones >= MAX_EXPLOTACIONES) {
            // Comprueba si se alcanzó el número máximo de explotaciones
            printf("Se ha alcanzado el número máximo de explotaciones.\n");
            break;
        }
        // Solicita y almacena datos de una nueva explotación
        printf("Ingresando datos de la explotación número %d:\n", empresa->numExplotaciones + 1);
        ingresarExplotacion(&empresa->explotaciones[empresa->numExplotaciones]);
        empresa->numExplotaciones++;// Incrementa el contador de explotaciones
        // Pregunta si se desea ingresar otra explotación
            // Bucle para asegurar una respuesta válida
        do {
            printf("¿Desea ingresar otra explotación? (S/N): ");
            scanf("%2s", respuesta); // Lee hasta dos caracteres más el caracter nulo
            // Limpia el buffer de entrada
            while (getchar() != '\n');
        } while (respuesta[0] != 'S' && respuesta[0] != 's' && respuesta[0] != 'N' && respuesta[0] != 'n');

        // Sale del bucle principal si la respuesta es 'N' o 'n'
        if (respuesta[0] == 'N' || respuesta[0] == 'n') {
            break;
        }

    } while (true); // Bucle infinito, se sale explícitamente
}

// Función para calcular la mejor ratio superficie/precio de compra
float mejorRatio(tEmpresaAgraria empresa) {
    float mejorRatio = 0.0; // Inicializamos el mejor ratio a 0
    float ratioActual;      // Para almacenar el ratio de la explotación actual
    for (int i = 0; i < empresa.numExplotaciones; i++) {
        // Aseguramos que el importe de compra no sea cero para evitar división por cero
        if (empresa.explotaciones[i].importeCompra > 0) {
            // Calcula el ratio de superficie a precio para la explotación actual
            ratioActual = empresa.explotaciones[i].superficieProductiva / empresa.explotaciones[i].importeCompra;
            // Actualizamos el mejor ratio si el actual es mejor
            if (ratioActual > mejorRatio) {
                mejorRatio = ratioActual;
            }
        }
    }
    return mejorRatio;// Devolvemos el mejor ratio encontrado
}

// Función para contar las explotaciones con una superficie mayor a la dada
int contarExplotacionesPorSuperficie(tEmpresaAgraria empresa, float superficieDada) {
    int contador = 0; // Contador para las explotaciones que cumplen la condición
    // Recorre todas las explotaciones de la empresa
    for (int i = 0; i < empresa.numExplotaciones; i++) {
        // Comprueba si la superficie productiva es mayor que la superficie dada
        if (empresa.explotaciones[i].superficieProductiva > superficieDada) {
            contador++; // Incrementa el contador si se cumple la condición
        }
    }
    return contador; // Devuelve el número de explotaciones que cumplen la condición
}

int main() {
    tEmpresaAgraria miEmpresa;          // Declara una variable de tipo tEmpresaAgraria
    ingresarExplotaciones(&miEmpresa);  // Llama a la función para ingresar datos de explotaciones
    float superficieDada = 50.0;        // Superficie para comparar, por ejemplo, 50 hectáreas
    //genero la variable y hago la llamada a la funcion mejorRatio
    float ratio = mejorRatio(miEmpresa);
    printf("\nEl mejor ratio superficie/precio es: %.2f\n", ratio);
    //genero la variable y hago la llamada a la funcion contarExplotacionesPorSuperficie
    int cantidad = contarExplotacionesPorSuperficie(miEmpresa, superficieDada);
    printf("Cantidad de explotaciones con superficie mayor a %.2f: %d\n", superficieDada, cantidad);
    return 0;
}
