#include "./headers/main_header.h"

STRUCTPRODUCTOS lista_de_productos[LEN_PRODUCTOS];       // Declara el array que contendra la lista de productos
STRUCTPRODUCTOVENTA producto_mas_vendido[LEN_PRODUCTOS]; // Declara el array que contendra el carrito de compras
int cantidad_iniciar_compras = 0;
int cantidad_de_compras = 0;
STRUCTCOLA *cola_clientes;
int longitud_cola = 1;
clock_t start_t;
clock_t tiempo_cliente;

int generar_ID()
{
  clock_t tiempo;
  tiempo = clock();
  return (int)tiempo;
}

clock_t obtener_tiempo_cliente()
{
  return tiempo_cliente;
}

clock_t obtener_tiempo_start_t()
{
  return start_t;
}

STRUCTCOLA *obtener_cola_clientes()
{
  return cola_clientes;
}

void regenerar_relog_start_t()
{
  start_t = clock();
}

void regenerar_tiempo_cliente()
{
  tiempo_cliente = clock();
}

void agregar_cliente_a_cola()
{
  cola_clientes = (STRUCTCOLA *)realloc(cola_clientes, (longitud_cola + 1) * sizeof(STRUCTCOLA));
  cola_clientes[longitud_cola].ID_cliente = generar_ID();
  regenerar_tiempo_cliente();
  longitud_cola++;
}

void eliminar_cliente_de_cola()
{
  if (longitud_cola == 1)
  {
    agregar_cliente_a_cola();
    eliminar_cliente_de_cola();
  }
  else
  {
    STRUCTCOLA *temp = (STRUCTCOLA *)malloc((longitud_cola - 1) * sizeof(STRUCTCOLA));
    for (int i = 1; i < longitud_cola; i++)
    {
      temp[i - 1] = cola_clientes[i];
    }

    longitud_cola--;
    cola_clientes = (STRUCTCOLA *)realloc(NULL, longitud_cola * sizeof(STRUCTCOLA));

    for (int i = 0; i < longitud_cola; i++)
    {
      cola_clientes[i] = temp[i];
    }
    free(temp);
  }
}

void mover_a_ultimo()
{
  if (longitud_cola > 1)
  {
    for (int i = 0; i < longitud_cola - 1; i++)
    {
      STRUCTCOLA temp = cola_clientes[i];
      cola_clientes[i] = cola_clientes[i + 1];
      cola_clientes[i + 1] = temp;
    }
  }
}

/*
Funcion principal, esta funcion se encarga de arrancar el programa
*/
int main(int argc, char **argv)
{
  cola_clientes = (STRUCTCOLA *)malloc(sizeof(STRUCTCOLA));
  cola_clientes[0].ID_cliente = generar_ID();

  set_productos(lista_de_productos, producto_mas_vendido);
  STRUCTQUESTION menu_main[4];
  strcpy(menu_main[0].texto, "1- Realizar Compra");
  strcpy(menu_main[1].texto, "2- Reportes");
  strcpy(menu_main[2].texto, "3- Mostrar Clientes");
  strcpy(menu_main[3].texto, "4- Salir del programa");

  start_t = clock();

  while (1) // Inicia un bucle que se acaba cuando seleccionar 3- Salir del programa o presionan la tecla ESC
  {
    int menu_main_opcion = select_menu("Elija la accion que quiere hacer", menu_main, sizeof(menu_main) / sizeof(STRUCTQUESTION));

    // Muestra el menu de compras
    if (menu_main_opcion == 0)
    {
      start_venta(lista_de_productos, producto_mas_vendido, &cantidad_iniciar_compras, &cantidad_de_compras);
    }
    // Muestra el menu de reportes
    else if (menu_main_opcion == 1)
    {
      start_menu_reportes(cantidad_iniciar_compras, cantidad_de_compras, producto_mas_vendido);
    }
    else if (menu_main_opcion == 2)
    {
      int res = mostrar_clientes(cola_clientes, longitud_cola);
      if (res == -2)
      {
        mover_a_ultimo();
      }
    }
    // Acaba la ejecucion del programa
    else if (menu_main_opcion == 3 || menu_main_opcion == -1)
    {
      system("cls");
      puts("Vuelva Pronto ;)");
      return 0;
    }
    else if (menu_main_opcion == -2)
    {
      mover_a_ultimo();
    }
  }
  return 0;
}