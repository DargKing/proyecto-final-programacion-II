/* Este header define todas las estructuras a usar en el programa */

#define MAX_LEN_QUESTION 128

/* Esta estructura se usa para poder insertar cadenas largas de caracteres y pasarlas a funciones */
typedef struct
{
  char texto[MAX_LEN_QUESTION];
} STRUCTQUESTION;


/* Esta estructura es usada para almacenar los datos de los productos,
Consta de un identificador (id), el nombre del producto y su precio */
typedef struct {
  int id;
  char nombre_producto[124];
  float precio_unitario;
} STRUCTPRODUCTOS;


/* Esta estructura guarda dentro de ella un producto y la cantidad que se va a comprar */
typedef struct {
  STRUCTPRODUCTOS producto;
  int cantidad;
} STRUCTPRODUCTOVENTA;