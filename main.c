#include "./headers/main_header.h"

int main(int argc, char **argv)
{
  set_productos();
  STRUCTQUESTION menu_main[3];
  strcpy(menu_main[0].texto, "1- Realizar Compra");
  strcpy(menu_main[1].texto, "2- Reportes");
  strcpy(menu_main[2].texto, "3- Salir del programa");

  while (1)
  {
    int menu_main_opcion = select_menu("Elija la accion que quiere hacer", menu_main, sizeof(menu_main) / sizeof(STRUCTQUESTION));

    if (menu_main_opcion == 0)
    {
      start_venta();
    }
    else if (menu_main_opcion == 1)
    {
      start_menu_reportes();
    }
    else if (menu_main_opcion == 2 || menu_main_opcion == -1)
    {
      system("cls");
      puts("Vuelva Pronto ;)");
      return 0;
    }
  }
  return 0;
}