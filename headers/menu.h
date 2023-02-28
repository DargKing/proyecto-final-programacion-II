/* menu.c contiene las funciones que se usaran para manipular el menu con ayuda de las flechas del teclado */

/*
Todas las funciones de este archivo devuelve un entero (Exepto la funcion mostrar_carrito),
Este entero es para que el software sepa que opcion se a elegido.
La mitad de las funciones hacen uso de estructuras para mostrar sus datos (para saber mas de estas dirigirse a structuras.h),
Tambien hay que indicarles un header, este header es el texto que se mostrara antes de las opciones del menu,
por ultimo el parametro len, este parametro se refiere a la cantidad de opciones que se mostraran en pantalla
*/

#define ARROW_UP 72 // Flecha arriba del teclado
#define ARROW_DOWN 80 // Flecha abajo del teclado
#define ARROW_LEFT 75 // Flecha Izquierda del teclado
#define ARROW_RIGHT 77 // Flecha Derecha del teclado
#define ESC_KEY 27 // Tecla esc del teclado
#define ENTER_KEY 13 // Tecla Enter del teclado
#define PADDING_MENU 3 // Si se hace la siguiente operacion (PADDING_MENU * 2 + 1) nos da la cantidad de opciones que se muestran en el menu
#define MAX_LEN_QUESTION 128

#define TIEMPO_NUEVO_CLIENTE 4
#define TIEMPO_ALERTA 8
#define TIEMPO_MOVER_COLA 10

#define SECONDS_PER_MINUTES 60

// Una funcion que muestra un menu de seleccion multiple
int select_menu(char *header, STRUCTQUESTION *questions, int len);

// Muestra un menu donde salen los distintos productos
int select_product(char* header, STRUCTPRODUCTOS *products, int len);

// Funcion donde se puede aumentar y disminuir un numero usando las flechas arriba y abajo de teclado
int select_num(char *header, int min, int max, int initial);

// Este es un menu que muestra los datos de el argumento carrito_de_compras, pero que no devuelve ningun valor ya que
// esta diseñado simplemente para observar
int mostrar_carrito(STRUCTPRODUCTOVENTA *carrito_de_compras, int longitud_de_carrito);

void mostrar_factura(STRUCTPRODUCTOVENTA *carrito_de_compras, int longitud_de_carrito);

int mostrar_clientes(STRUCTCOLA *clientes, int len_cola);