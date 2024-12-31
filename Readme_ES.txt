Proyecto de Gestión de Explotaciones Agrícolas
Este proyecto está diseñado para gestionar explotaciones agrícolas dentro de una empresa agraria. Permite registrar y gestionar explotaciones con información detallada como la referencia catastral, denominación, superficie, importe de compra, fecha de compra y tipo de regadío. También incluye funciones para calcular la mejor relación entre superficie y precio, así como contar el número de explotaciones que superan una superficie determinada.

Descripción del Proyecto:
El programa permite a un usuario registrar varias explotaciones agrícolas dentro de una empresa agraria, especificando los detalles de cada explotación y luego calcular algunas métricas útiles, como la mejor relación de superficie/precio y contar las explotaciones que superan una superficie dada. Además, la información de cada explotación está organizada y almacenada de forma eficiente.

Estructuras de Datos:
Fecha: Representa una fecha con tres campos: dia, mes y anio.
Palabra: Tipo personalizado para almacenar textos con longitud controlada. Incluye un arreglo de caracteres (letras) y un campo para almacenar la longitud actual del texto (longitud).

tExplotacion: Representa una explotación agrícola, con:
	referenciaCatastral: Código de referencia catastral.
	denominacionColoquial: Denominación coloquial de la explotación.
	superficieProductiva: Superficie de la explotación en hectáreas.
	importeCompra: Importe pagado por la explotación.
	fechaCompra: Fecha de compra de la explotación.
	esRegadio: Booleano que indica si es un terreno de regadío.

tEmpresaAgraria: Representa una empresa agraria, con:
	nif: NIF de la empresa.
	denominacion: Nombre de la empresa.
	poblacion: Población de la empresa.
	codigoPostal: Código postal.
	telefono: Teléfono de contacto.
	direccion: Dirección de la empresa.
	explotaciones: Array de explotaciones agrícolas.
	numExplotaciones: Número de explotaciones registradas.

Funcionalidades:
1. Ingresar Explotación: Permite ingresar los detalles de una explotación agrícola (referencia catastral, denominación, superficie, precio, fecha de compra y si es regadío).
2. Ingresar Explotaciones: Permite ingresar múltiples explotaciones agrícolas a la vez, limitadas por el número máximo definido.
3. Calcular la Mejor Relación Superficie/Precio: Calcula y devuelve la mejor relación de superficie a precio de compra entre todas las explotaciones.
4. Contar Explotaciones por Superficie: Cuenta cuántas explotaciones tienen una superficie mayor que una superficie dada.

Menú de Opciones:

El programa no tiene un menú de opciones interactivo, ya que está diseñado para ingresar explotaciones y calcular métricas directamente desde el main. El flujo principal es el siguiente:
1. El usuario ingresa datos de las explotaciones agrícolas.
2. Se calcula el mejor ratio entre superficie y precio de compra.
3. Se cuenta cuántas explotaciones tienen una superficie mayor a un valor dado (por ejemplo, 50 hectáreas).
4. Se muestra el resultado en consola.

Requisitos:
Compilador: Se requiere un compilador de C compatible con el estándar C99 o superior.
Sistema Operativo: Funciona en sistemas operativos como Windows, Linux y macOS.

Instrucciones de Uso:
Compilación y Ejecución:

Para compilar el proyecto, utiliza un compilador de C (por ejemplo, GCC) con el siguiente comando:

gcc -o gestion_explotaciones gestion_explotaciones.c

Para ejecutar el programa, utiliza el siguiente comando:

./gestion_explotaciones

Interacción:

El programa solicita los datos de cada explotación a través de la entrada estándar (consola).
Después de ingresar los datos de todas las explotaciones, el programa calcula la mejor relación de superficie a precio y 
muestra cuántas explotaciones tienen una superficie mayor a la especificada.

Ejemplo de Uso:
Ingresar Explotación:

1. El usuario ingresará información como la referencia catastral, denominación, superficie (en hectáreas), importe de compra, fecha de compra y si es regadío o no.
Calcular Mejor Relación Superficie/Precio:
2. Una vez ingresadas las explotaciones, el programa calculará cuál tiene la mejor relación entre la superficie y el precio de compra.
Contar Explotaciones por Superficie:
3. El programa contará cuántas explotaciones tienen una superficie mayor a la que el usuario ingresa (por ejemplo, 50 hectáreas).

Contribuciones
Las contribuciones al proyecto son bienvenidas. Si deseas mejorar el código, agregar nuevas funcionalidades o corregir errores, por favor sigue estos pasos:

Haz un fork del repositorio.
Crea una nueva rama para tu cambio (git checkout -b feature/nueva-funcionalidad).
Realiza tus cambios y haz commit (git commit -am 'Añadir nueva funcionalidad').
Haz push a la rama (git push origin feature/nueva-funcionalidad).
Crea un pull request describiendo los cambios realizados.