#include "./headers/main_header.h"

/*
Funcion principal, esta funcion se encarga de arrancar el programa
*/

int main(int argc, char **argv)
{
  set_productos();
  STRUCTQUESTION menu_main[3];
  strcpy(menu_main[0].texto, "1- Realizar Compra");
  strcpy(menu_main[1].texto, "2- Reportes");
  strcpy(menu_main[2].texto, "3- Salir del programa");

  while (1) // Inicia un bucle que se acaba cuando seleccionar 3- Salir del programa o presionan la tecla ESC
  {
    int menu_main_opcion = select_menu("Elija la accion que quiere hacer", menu_main, sizeof(menu_main) / sizeof(STRUCTQUESTION));

    // Muestra el menu de compras
    if (menu_main_opcion == 0)
    {
      start_venta();
    }
    // Muestra el menu de reportes
    else if (menu_main_opcion == 1)
    {
      start_menu_reportes();
    }
    // Acaba la ejecucion del programa
    else if (menu_main_opcion == 2 || menu_main_opcion == -1)
    {
      system("cls");
      puts("Vuelva Pronto ;)");
      return 0;
    }
  }
  return 0;
}