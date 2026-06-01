*Este proyecto ha sido creado como parte del currículo de 42 por pabfajar.*

### **DESCRIPCIÓN**

El proyecto get_next_line tiene como objetivo implementar una función en C capaz de leer un archivo línea a línea, devolviendo una línea completa en cada llamada, independientemente del tamaño del archivo o del tamaño del buffer utilizado en las lecturas.

La función debe gestionar correctamente:

- Lecturas parciales
- Líneas de cualquier longitud
- Memoria dinámica y almacenamiento intermedio entre llamadas

Este proyecto introduce al estudiante en el manejo avanzado de sistemas de archivos, gestión de memoria, lecturas con read(), y control de estados persistentes mediante variables estáticas.

```
┌──────────────────────────────────────────────────────────────┐
│                LÓGICA DE FUNCIONAMIENTO DE GNL               │
└──────────────────────────────────────────────────────────────┘
                │
                ▼
        Leer N bytes con read()
                │
                ▼
     ¿read devuelve > 0 bytes?
        │                 │
        │                 └───────────────┐
        ▼                                 ▼
   Añadir lo leído al store        EOF o error → devolver la línea
                │
                ▼
     ¿Hay algún salto de línea en store?
        │                 │
        Sí                No ────────────────────────┐
        │                                            ▼
        ▼                                   Leer N bytes de nuevo
   Separar la línea completa             (acumular hasta encontrar '\n'
                │                               o llegar a EOF)
                ▼
   Guardar el sobrante en store
                │
                ▼
   Devolver la línea al usuario
                │
                ▼
   (En la siguiente llamada, repetir proceso)

```

### **INSTRUCCIONES**

Para compilar este proyecto basta con incluir todos los archivos .c existentes y usar el siguiente comando.
```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c get_next_line.h
```
**Ejemplo de programa para probar `get_next_line`**

A continuación se muestra un pequeño programa de ejemplo que permite abrir un archivo,
leerlo línea a línea utilizando `get_next_line`, imprimir cada línea y liberar la memoria
correspondiente:

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
    char	*line;

	if (argc != 2)
	{
		printf("Uso: %s <archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
### **RECURSOS**

A lo largo del desarrollo de este proyecto se han consultado diversas fuentes para comprender mejor la gestión de memoria en C y la lógica en general de `get_next_line`.

**Guías y documentación técnica**

- Recursos sobre gestión de memoria en C (malloc, leaks).
- Explicaciones sobre los concepto de memoria dinámica, lectura parcial, buffer y descriptor de archivo.
- Repositorios y guías píblicas en github para ver distintos enfoques con los que abordar el proyecto.

**Otras herramientas**

- Se ha hecho uso del tester paco para realizar diversas pruebas de funcionamiento del código con casos extremos.
- Archivos propios creados con el fin de validar el correcto funcionamiento del código.

**Asistencia con IA**

- Consultas a la ia para localizar errores y propuesta de ejemplos de funcionamiento.
- Genración explicaciones de conceptos y esquemas de la lógica del programa.

### **TEXTO DE EJEMPLO**
```
UNA TERTULIA INESPERADA

En un agujero en el suelo, vivía un hobbit. No un agujero húmedo, sucio, repugnante,
con restos de gusanos y olor a fango, ni tampoco un agujero seco, desnudo y arenoso,
sin nada en que sentarse o que comer: era un agujero-hobbit, y eso significa comodidad.

Tenía una puerta redonda, perfecta como un ojo de buey, pintada de verde, con una
manilla de bronce dorada y brillante, justo en el medio. La puerta se abría a un vestíbulo
cilíndrico, como un túnel: un túnel muy cómodo, sin humos, con paredes revestidas de
madera y suelos enlosados y alfombrados, provisto de sillas barnizadas, y montones y
montones de perchas para sombreros y abrigos; el hobbit era aficionado a las visitas.











 El túnel se extendía serpeando, y penetraba bastante, pero no directamente, en la ladera de la colina —La Colina, como la llamaba toda la gente de muchas millas alrededor—, y muchas puertecitas redondas se abrían en él, primero a un lado y luego al otro.
 
 Nada de subir escaleras para el hobbit: dormitorios, cuartos de baño, bodegas, despensas
(muchas), armarios (habitaciones enteras dedicadas a ropa), cocinas. Comedores, se
encontraban en la misma planta, y en verdad en el mismo pasillo. Las mejores
habitaciones estaban todas a la izquierda de la puerta principal, pues eran las únicas
que tenían ventanas, ventanas redondas, profundamente excavadas, que miraban al 
jardín y los prados de más allá, camino del río. Este hobbit era un hobbit acomodado, y
se apellidaba Bolsón. Los Bolsón habían vivido en las cercanías de La Colina desde
hacía muchísimo tiempo, y la gente los consideraba muy respetables, no sólo porque
casi todos eran ricos, sino también porque nunca tenían ninguna aventura ni hacían algo
inesperado: uno podía saber lo que diría un Bolsón acerca de cualquier asunto sin
necesidad de preguntárselo. Esta es la historia de cómo un Bolsón tuvo una aventura, y
se encontró a sí mismo haciendo y diciendo cosas por completo inesperadas. Podría
haber perdido el respeto de los vecinos, pero ganó... Bueno, ya veréis si al final ganó
algo. 
```