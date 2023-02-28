#include "../headers/main_header.h"

void start_menu_reportes(int cantidad_de_clientes, int cantidad_de_compras, STRUCTPRODUCTOVENTA *producto_mas_vendido)
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
      system("cls");
      printf("Se han presentado %d clientes a comprar", cantidad_de_clientes);
      getchar();
    }
    else if (menu_reportes_opcion == 1)
    {
      system("cls");
      printf("Se han realizado %d compras", cantidad_de_compras);
      getchar();
    }
    else if (menu_reportes_opcion == 2)
    {
      system("cls");
      if (cantidad_de_compras > 0)
      {

        STRUCTPRODUCTOVENTA mas_vendido = producto_mas_vendido[0];
        STRUCTPRODUCTOVENTA segundo_mas_vendido = producto_mas_vendido[0];
        STRUCTPRODUCTOVENTA tercero_mas_vendido = producto_mas_vendido[0];

        mas_vendido.cantidad = 0;
        segundo_mas_vendido.cantidad = 0;
        tercero_mas_vendido.cantidad = 0;

        int len = 0;

        for (int i = 0; i < LEN_PRODUCTOS; i++)
        {
          if (producto_mas_vendido[i].cantidad > 0)
          {
            len++;
          }
        }

        puts("Productos Mas Vendidos:\n");

        for (int i = 0; i < LEN_PRODUCTOS; i++)
        {
          if (producto_mas_vendido[i].cantidad > mas_vendido.cantidad)
          {
            mas_vendido = producto_mas_vendido[i];
          }
        }

        printf("1- Nombre: %s | Cantidad de Veces Vendida: %d\n", mas_vendido.producto.nombre_producto, mas_vendido.cantidad);

        if (len >= 2)
        {
          for (int i = 0; i < LEN_PRODUCTOS; i++)
          {
            if (producto_mas_vendido[i].cantidad > segundo_mas_vendido.cantidad && producto_mas_vendido[i].producto.id != mas_vendido.producto.id)
            {
              segundo_mas_vendido = producto_mas_vendido[i];
            }
          }
          printf("2- Nombre: %s | Cantidad de Veces Vendida: %d\n", segundo_mas_vendido.producto.nombre_producto, segundo_mas_vendido.cantidad);
        }

        if (len >= 3)
        {
          for (int i = 0; i < LEN_PRODUCTOS; i++)
          {
            if (producto_mas_vendido[i].cantidad > tercero_mas_vendido.cantidad &&
                producto_mas_vendido[i].producto.id != mas_vendido.producto.id &&
                producto_mas_vendido[i].producto.id != segundo_mas_vendido.producto.id)
            {
              tercero_mas_vendido = producto_mas_vendido[i];
            }
          }
          printf("3- Nombre: %s | Cantidad de Veces Vendida: %d\n", tercero_mas_vendido.producto.nombre_producto, tercero_mas_vendido.cantidad);
        }

        getchar();
      }
      else
      {
        puts("Aun no se ha realizado ninguna compra...");
        getchar();
      }
    }
    else if (menu_reportes_opcion == 3)
    {
      system("cls");
      if (cantidad_de_compras > 0)
      {
        float total = 0;
        for (int i = 0; i < LEN_PRODUCTOS; i++)
        {
          total += producto_mas_vendido[i].producto.precio_unitario * producto_mas_vendido[i].cantidad;
        }
        printf("Se han realizado %d compras, lo que da un total de %.2f Bs recolectados", cantidad_de_compras, total);
        getchar();
      }
      else
      {
        puts("Aun no se ha realizado ninguna compra...");
        getchar();
      }
    }
    else if (menu_reportes_opcion == 4 || menu_reportes_opcion == -1)
    {
      break;
    }
    else if (menu_reportes_opcion == -2)
    {
      mover_a_ultimo();
      break;
    }
  }
}