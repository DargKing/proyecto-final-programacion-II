/* menu.c contiene las funciones que se usaran para manipular el menu con ayuda de las flechas del teclado */
#include "../headers/main_header.h"

/*
*****************************************************************
*                            select_menu
*****************************************************************
* Esta funcion muestra todas las opciones que se encuentren en  *
* la variable question. al seleccionar 1 de estas               *
* opciones devuelve un entero que le indica al software que     *
* opcion eligio.                                                *
*****************************************************************
*/
int select_menu(char *header, STRUCTQUESTION *questions, int len)
{
  int opcion = 0;

  // Inicia un bucle que no acaba hasta que elijan una opcione o el usuario presione la tecla ESC
  while (1)
  {
    system("cls"); // Limpia la pantalla
    puts(header);  // Muestra el texto que se encuentra en header

    // Inicia un for que mostrara en pantalla todas las opciones
    for (int i = 0; i < len; i++)
    {
      /* Si la opcion que estamos estamos seleccionando es igual a la opcion que se va a mostrar en pantalla.
      Entonces esta se mostrara en color morado y con una flecha señalandole, si no entonces se mostrara normal */
      if (opcion == i)
      {
        printf("   ");
        printf("\033[0;35m");
        printf_s(questions[i].texto);
        printf(" <--\n");
        printf("\033[0m");
      }
      else
      {
        puts(questions[i].texto);
      }
    }

    int key = getch(); // Cuando el usuario precione una tecla este guardara su valor en esta variable
    if (key == 0)      // Si el valor de key es 0 entonces indica que esta precionando una tecla
    {
      key = getch(); // Al volver a obtener el valor de la tecla esta vez si guarda el valor de la tecla
    }

    if (key == ARROW_UP && opcion > 0) // Si preciona la tecla de arriba retrocede una posicion en las opciones
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < len - 1) // Si preciona la tecla de abajo avanzaa una posicion en las opciones
    {
      opcion++;
    }
    else if (key == ESC_KEY) // Si preciona la tecla ESC, se toma como un escape forsozo y se cierra este menu
    {
      return -1;
    }
    else if (key == ENTER_KEY) // Al precionar ENTER devuelve la opcion que se ha seleccionado
    {
      return opcion;
    }
  }
}

int select_product(char *header, STRUCTPRODUCTOS *productos, int len)
{
  int opcion = 0;
  // Inicia un bucle que no acaba hasta que elijan una opcione o el usuario presione la tecla ESC
  while (1)
  {
    system("cls"); // Limpia la pantalla
    puts(header);  // Muestra el texto que se encuentra en header
    printf("\n");

    // Inicia un for que mostrara en pantalla todas las opciones
    for (int i = 0; i < len; i++)
    {
      /*
      Estos ifelse tienen la funcion de limitar la cantidad de opciones que se muestran en pantalla,
      estos solo muestran PADDING_MENU opciones por arriba y por debajo de la opcion seleccionada.
      Graficamente se veria de la siguiente manera, si tenemos en cuenta que es una lista de 10 productos

      PADDING_MENU = 3
      1. Opcion 1
      2. Opcion 2
      3. Opcion 3
      4. Opcion 4 <--
      5. Opcion 5
      6. Opcion 6
      7. Opcion 7

      PADDING_MENU = 2
      2. Opcion 2
      3. Opcion 3
      4. Opcion 4 <--
      5. Opcion 5
      6. Opcion 6

      En caso de que se encuentre en las ultimas opciones o en las primeras opciones de la lista se veria de la siguiente manera

      PADDING_MENU = 2
      1. Opcion 1
      2. Opcion 2 <--
      3. Opcion 3 
      4. Opcion 4
      5. Opcion 5

      PADDING_MENU = 2
      6. Opcion 6
      7. Opcion 7
      8. Opcion 8 
      9. Opcion 9
      10. Opcion 10 <--
      */
      /* Estas 3 condiciones se encargan de no mostrar los elementos que no esten en el rango de PADDING_MENU */
      if (opcion > PADDING_MENU && opcion < len - PADDING_MENU)
      {
        if (i < opcion - PADDING_MENU || i > opcion + PADDING_MENU)
        {
          continue;
        }
      }
      else if (opcion < PADDING_MENU * 2)
      {
        if (i > PADDING_MENU * 2)
        {
          continue;
        }
      }
      else if (opcion > len - (PADDING_MENU * 2))
      {
        if (i < len - ((PADDING_MENU * 2) + 1))
        {
          continue;
        }
      }

      /* Si la opcion que estamos estamos seleccionando es igual a la opcion que se va a mostrar en pantalla.
      Entonces esta se mostrara en color morado y con una flecha señalandole, si no entonces se mostrara normal */
      if (opcion == i)
      {
        printf("   ");
        printf("\033[0;35m");
        printf_s("%d- %s", i + 1, productos[i].nombre_producto);
        printf(" <--\n");
        printf("\033[0m");
      }
      else
      {
        printf("%d- %s\n", i + 1, productos[i].nombre_producto);
      }
    }

    int key = getch(); // Cuando el usuario precione una tecla este guardara su valor en esta variable
    if (key == 0)      // Si el valor de key es 0 entonces indica que esta precionando una tecla
    {
      key = getch(); // Al volver a obtener el valor de la tecla esta vez si guarda el valor de la tecla
    }

    if (key == ARROW_UP && opcion > 0) // Si preciona la tecla de arriba retrocede una posicion en las opciones
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < len - 1) // Si preciona la tecla de abajo avanzaa una posicion en las opciones
    {
      opcion++;
    }
    else if (key == ESC_KEY) // Si preciona la tecla ESC, se toma como un escape forsozo y se cierra este menu
    {
      return -1;
    }
    else if (key == ENTER_KEY) // Al precionar ENTER devuelve la opcion que se ha seleccionado
    {
      return opcion;
    }
  }
}

int select_num(char *header, int min, int max, int initial)
{
  int num = initial; // El numero inicial es igual al valor pasado en initial
  // Inicia un bucle que no acaba hasta que se elija un numero o el usuario presione la tecla ESC
  while (1)
  {
    system("cls"); // Limpia la pantalla
    puts(header);  // Muestra el texto que se encuentra en header
    printf("\n");

    printf("%d <--", num); // Muestra en pantalla el numero actual

    int key = getch(); // Cuando el usuario precione una tecla este guardara su valor en esta variable
    if (key == 0)      // Si el valor de key es 0 entonces indica que esta precionando una tecla
    {
      key = getch(); // Al volver a obtener el valor de la tecla esta vez si guarda el valor de la tecla
    }

    if (key == ARROW_UP && num < max) // Si se preciona la flecha arriba aumenta un numero hasta llegar al max
    {
      num++;
    }
    else if (key == ARROW_DOWN && num > min) // Si se preciona la flecha abajo disminuye un numero hasta llegar al min
    {
      num--;
    }
    else if (key == ESC_KEY) // Si preciona la tecla ESC, se toma como un escape forsozo y se cierra este menu
    {
      return -1;
    }
    else if (key == ENTER_KEY) // Devuelve el numero seleccionado
    {
      return num;
    }
  }
}

void mostrar_carrito(STRUCTPRODUCTOVENTA *carrito_de_compras, int longitud_de_carrito)
{
  int opcion = 0;
  while (1) // Se inicia el bucle hasta que se precione ENTER o ESC
  {
    // Se limpia la pantalla
    system("cls");
    puts("**************************");
    for (int i = 0; i < longitud_de_carrito; i++)
    {
      /*
      Elimina todas las opciones que no esten 1 espacio por delante del seleccionado
      */
      if (opcion != longitud_de_carrito - 1)
      {
        if (i < opcion || i > opcion + 1)
        {
          continue;
        }
      }
      else
      {
        if (i < opcion - 1)
        {
          continue;
        }
      }

      // Si el seleccionado es igual al que se imprimira en pantalla se pondra el texto en morado, si no, se mostrara el texto normal
      if (i == opcion)
      {
        printf("\033[0;35m");
        printf("  Producto numero %d\n", i + 1);
        printf("  Nombre de Producto: %s\n", carrito_de_compras[i].producto.nombre_producto);
        printf("  Cantidad: %d\n", carrito_de_compras[i].cantidad);
        printf("  Precio Unitario: %.2f\n", carrito_de_compras[i].producto.precio_unitario);
        printf("  Precio Total: %.2f\n", carrito_de_compras[i].producto.precio_unitario * carrito_de_compras[i].cantidad);
        printf("\033[0m");
        puts("**************************");
      }
      else
      {
        printf("Producto numero %d\n", i + 1);
        printf("Nombre de Producto: %s\n", carrito_de_compras[i].producto.nombre_producto);
        printf("Cantidad: %d\n", carrito_de_compras[i].cantidad);
        printf("Precio Unitario: %.2f\n", carrito_de_compras[i].producto.precio_unitario);
        printf("Precio Total: %.2f\n", carrito_de_compras[i].producto.precio_unitario * carrito_de_compras[i].cantidad);
        puts("**************************");
      }
    }

    int key = getch(); // Cuando el usuario precione una tecla este guardara su valor en esta variable
    if (key == 0)      // Si el valor de key es 0 entonces indica que esta precionando una tecla
    {
      key = getch(); // Al volver a obtener el valor de la tecla esta vez si guarda el valor de la tecla
    }

    if (key == ARROW_UP && opcion > 0) // Si preciona la tecla de arriba retrocede una posicion en las opciones
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < longitud_de_carrito - 1) // Si preciona la tecla de abajo avanza una posicion en las opciones
    {
      opcion++;
    }
    else if (key == ESC_KEY) // Si preciona la tecla ESC, se toma como un escape forsozo y se cierra este menu
    {
      return -1;
    }
    else if (key == ENTER_KEY) // Al precionar ENTER devuelve la opcion que se ha seleccionado
    {
      return opcion;
    }
  }
}
