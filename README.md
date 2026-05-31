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

A lo largo del desarrollo de este proyecto he consultado diferentes fuentes para comprender mejor el funcionamiento de `read()`, la gestión de memoria en C y la lógica necesaria para implementar `get_next_line`. Entre ellas:
- Documentación oficial de `read()`.