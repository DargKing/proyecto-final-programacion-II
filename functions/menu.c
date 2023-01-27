#include "../headers/main_header.h"

#define PADDING_MENU 3

int select_menu(char *header, STRUCTQUESTION *questions, int len)
{
  int opcion = 0;
  while (1)
  {
    system("cls");
    puts(header);
    for (int i = 0; i < len; i++)
    {
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

    int key = getch();
    if (key == 0)
    {
      key = getch();
    }

    if (key == ARROW_UP && opcion > 0)
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < len - 1)
    {
      opcion++;
    }
    else if (key == ESC_KEY)
    {
      return -1;
    }
    else if (key == ENTER_KEY)
    {
      return opcion;
    }
  }
}

int select_product(char *header, STRUCTPRODUCTOS *productos, int len)
{
  int opcion = 0;
  while (1)
  {
    system("cls");
    puts(header);
    printf("\n");
    for (int i = 0; i < len; i++)
    {
      if (opcion > PADDING_MENU && opcion < len - PADDING_MENU)
      {
        if (i < opcion - PADDING_MENU || i > opcion + PADDING_MENU)
        {
          continue;
        }
      } else if (opcion < PADDING_MENU * 2) {
        if (i > PADDING_MENU * 2)
        {
          continue;
        }
      } else if (opcion > len - (PADDING_MENU * 2)){
        if (i < len - ((PADDING_MENU * 2) + 1))
        {
          continue;
        }
      }


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

    int key = getch();
    if (key == 0)
    {
      key = getch();
    }

    if (key == ARROW_UP && opcion > 0)
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < len - 1)
    {
      opcion++;
    }
    else if (key == ESC_KEY)
    {
      return -1;
    }
    else if (key == ENTER_KEY)
    {
      return opcion;
    }
  }
}

int select_num(char *header, int min, int max, int initial)
{
  int num = initial;
  while (1)
  {
    system("cls");
    puts(header);
    printf("\n");

    printf("%d <--", num);

    int key = getch();
    if (key == 0)
    {
      key = getch();
    }

    if (key == ARROW_UP && num < max)
    {
      num++;
    }
    else if (key == ARROW_DOWN && num > min)
    {
      num--;
    }
    else if (key == ESC_KEY)
    {
      return -1;
    }
    else if (key == ENTER_KEY)
    {
      return num;
    }
  }
}

void mostrar_carrito(STRUCTPRODUCTOVENTA *carrito_de_compras, int longitud_de_carrito)
{
  int opcion = 0;
  while (1)
  {

    system("cls");
    puts("**************************");
    for (int i = 0; i < longitud_de_carrito; i++)
    {
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

    int key = getch();
    if (key == 0)
    {
      key = getch();
    }

    if (key == ARROW_UP && opcion > 0)
    {
      opcion--;
    }
    else if (key == ARROW_DOWN && opcion < longitud_de_carrito - 1)
    {
      opcion++;
    }
    else if (key == ESC_KEY)
    {
      return -1;
    }
    else if (key == ENTER_KEY)
    {
      return opcion;
    }
  }
}
