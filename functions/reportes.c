#include "../headers/main_header.h"

void start_menu_reportes()
{
  STRUCTQUESTION menu_reportes[5];
  strcpy(menu_reportes[0].texto, "1- Cantidad de clientes que se han presentado");
  strcpy(menu_reportes[1].texto, "2- Cantidad de clientes que han comprado");
  strcpy(menu_reportes[2].texto, "3- Producto mas vendido");
  strcpy(menu_reportes[3].texto, "4- Total de ventas");
  strcpy(menu_reportes[4].texto, "5- Volver");

  while (1)
  {
    int menu_reportes_opcion = select_menu("Elija la accion que quiere hacer", menu_reportes, sizeof(menu_reportes) / sizeof(STRUCTQUESTION));

    if (menu_reportes_opcion == 0)
    {
    }
    else if (menu_reportes_opcion == 1)
    {
    }
    else if (menu_reportes_opcion == 2)
    {
    }
    else if (menu_reportes_opcion == 3)
    {
    }
    else if (menu_reportes_opcion == 4)
    {
      break;
    }
  }
}