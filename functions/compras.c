#include "../headers/main_header.h"

STRUCTPRODUCTOS lista_de_productos[30];
STRUCTPRODUCTOVENTA carrito_de_compras[MAX_LEN_CARRO_PRODUCTOS];
int longitud_de_carrito = 0;

int buscar_producto_en_carro(int id)
{
  for (int i = 0; i < MAX_LEN_CARRO_PRODUCTOS; i++)
  {
    if (id == carrito_de_compras[i].producto.id)
    {
      return i;
    }
  }
  return -1;
}

void set_productos()
{
  // 1
  lista_de_productos[0].id = 1;
  strcpy(lista_de_productos[0].nombre_producto, "Doritos");
  lista_de_productos[0].precio_unitario = 28;

  // 2
  lista_de_productos[1].id = 2;
  strcpy(lista_de_productos[1].nombre_producto, "Platanito");
  lista_de_productos[1].precio_unitario = 30;

  // 3
  lista_de_productos[2].id = 3;
  strcpy(lista_de_productos[2].nombre_producto, "Cheeztres");
  lista_de_productos[2].precio_unitario = 25;

  // 4
  lista_de_productos[3].id = 4;
  strcpy(lista_de_productos[3].nombre_producto, "Oreo (EMPAQUE S)");
  lista_de_productos[3].precio_unitario = 50;

  // 5
  lista_de_productos[4].id = 5;
  strcpy(lista_de_productos[4].nombre_producto, "Oreo (EMPAQUE XL)");
  lista_de_productos[4].precio_unitario = 28;

  // 6
  lista_de_productos[5].id = 6;
  strcpy(lista_de_productos[5].nombre_producto, "Galleta Maria");
  lista_de_productos[5].precio_unitario = 40.5;

  // 7
  lista_de_productos[6].id = 7;
  strcpy(lista_de_productos[6].nombre_producto, "Ovomaltina");
  lista_de_productos[6].precio_unitario = 25.5;

  // 8
  lista_de_productos[7].id = 8;
  strcpy(lista_de_productos[7].nombre_producto, "Nucita");
  lista_de_productos[7].precio_unitario = 40;

  // 9
  lista_de_productos[8].id = 9;
  strcpy(lista_de_productos[8].nombre_producto, "Nutela");
  lista_de_productos[8].precio_unitario = 100.20;

  // 10
  lista_de_productos[9].id = 10;
  strcpy(lista_de_productos[9].nombre_producto, "Cocosete mini");
  lista_de_productos[9].precio_unitario = 70.3;

  // 11
  lista_de_productos[10].id = 11;
  strcpy(lista_de_productos[10].nombre_producto, "Cocosete");
  lista_de_productos[10].precio_unitario = 100;

  // 12
  lista_de_productos[11].id = 12;
  strcpy(lista_de_productos[11].nombre_producto, "Samba");
  lista_de_productos[11].precio_unitario = 80;

  // 13
  lista_de_productos[12].id = 13;
  strcpy(lista_de_productos[12].nombre_producto, "Pepito");
  lista_de_productos[12].precio_unitario = 40;

  // 14
  lista_de_productos[13].id = 14;
  strcpy(lista_de_productos[13].nombre_producto, "Pepito XL");
  lista_de_productos[13].precio_unitario = 60;

  // 15
  lista_de_productos[14].id = 15;
  strcpy(lista_de_productos[14].nombre_producto, "Doritos XL");
  lista_de_productos[14].precio_unitario = 80;

  // 16
  lista_de_productos[15].id = 16;
  strcpy(lista_de_productos[15].nombre_producto, "Choquito");
  lista_de_productos[15].precio_unitario = 10.3;

  // 17
  lista_de_productos[16].id = 17;
  strcpy(lista_de_productos[16].nombre_producto, "Pinguinos");
  lista_de_productos[16].precio_unitario = 100;

  // 18
  lista_de_productos[17].id = 18;
  strcpy(lista_de_productos[17].nombre_producto, "M&M's mini");
  lista_de_productos[17].precio_unitario = 30;

  // 19
  lista_de_productos[18].id = 19;
  strcpy(lista_de_productos[18].nombre_producto, "M&M's Big");
  lista_de_productos[18].precio_unitario = 80.9;

  // 20
  lista_de_productos[19].id = 20;
  strcpy(lista_de_productos[19].nombre_producto, "Ferrero Rocher");
  lista_de_productos[19].precio_unitario = 1001.99;

  // 21
  lista_de_productos[20].id = 21;
  strcpy(lista_de_productos[20].nombre_producto, "Toronto");
  lista_de_productos[20].precio_unitario = 30;

  // 22
  lista_de_productos[21].id = 22;
  strcpy(lista_de_productos[21].nombre_producto, "Dandy Dandy");
  lista_de_productos[21].precio_unitario = 45.3;

  // 23
  lista_de_productos[22].id = 23;
  strcpy(lista_de_productos[22].nombre_producto, "Palitos");
  lista_de_productos[22].precio_unitario = 23;

  // 24
  lista_de_productos[23].id = 24;
  strcpy(lista_de_productos[23].nombre_producto, "Ovomaltina Maxi");
  lista_de_productos[23].precio_unitario = 70;

  // 25
  lista_de_productos[24].id = 25;
  strcpy(lista_de_productos[24].nombre_producto, "Rufles");
  lista_de_productos[24].precio_unitario = 30;

  // 26
  lista_de_productos[25].id = 26;
  strcpy(lista_de_productos[25].nombre_producto, "Rufles de queso");
  lista_de_productos[25].precio_unitario = 35;

  // 27
  lista_de_productos[26].id = 27;
  strcpy(lista_de_productos[26].nombre_producto, "Chupeta Bumblebu");
  lista_de_productos[26].precio_unitario = 10;

  // 28
  lista_de_productos[27].id = 28;
  strcpy(lista_de_productos[27].nombre_producto, "Caramelos Chao");
  lista_de_productos[27].precio_unitario = 1;

  // 29
  lista_de_productos[28].id = 29;
  strcpy(lista_de_productos[28].nombre_producto, "Dulce de leche");
  lista_de_productos[28].precio_unitario = 5;

  // 30
  lista_de_productos[29].id = 30;
  strcpy(lista_de_productos[29].nombre_producto, "Canelitas");
  lista_de_productos[29].precio_unitario = 40;
}

void start_venta()
{
  STRUCTQUESTION menu_compras[4];
  strcpy(menu_compras[0].texto, "1- Agregar Producto al carrito");
  strcpy(menu_compras[1].texto, "2- Eliminar ultimo producto del carrito");
  strcpy(menu_compras[2].texto, "3- Mostrar carrito");
  strcpy(menu_compras[3].texto, "4- Cancelar proceso");

  while (1)
  {
    int menu_compras_opcion = select_menu("Seleccione la accion a realizar", menu_compras, sizeof(menu_compras) / sizeof(STRUCTQUESTION));
    if (menu_compras_opcion == 0)
    {
      if (longitud_de_carrito == MAX_LEN_CARRO_PRODUCTOS)
      {
        system("cls");
        puts("El carro de productos esta lleno, ya no se pueden insertar articulos");
        getchar();
        continue;
      }
      int index_producto = select_product("Elige tu producto", lista_de_productos, LEN_PRODUCTOS);
      if (index_producto == -1)
      {
        continue;
      }

      int cantidad = select_num("Inserte la cantidad de articulos a comprar (Use las flechas del teclado para aumentar o disminuir, MAXIMO 5 articulos)",
                                1, MAX_CANTIDAD_PRODUCTOS, 1);

      if (cantidad == -1)
      {
        continue;
      }

      int existe = buscar_producto_en_carro(lista_de_productos[index_producto].id);

      if (existe == -1)
      {
        carrito_de_compras[longitud_de_carrito].producto = lista_de_productos[index_producto];
        carrito_de_compras[longitud_de_carrito].cantidad = cantidad;

        longitud_de_carrito++;
        continue;
      }

      if (carrito_de_compras[existe].cantidad + cantidad <= 5)
      {
        carrito_de_compras[existe].cantidad += cantidad;
      }
      else
      {
        system("cls");
        puts("Este articulo no se puede agregar por que supera la cantidad permitida");
        getchar();
        continue;
      }
    }
    else if (menu_compras_opcion == 1)
    {
      if (longitud_de_carrito <= 0)
      {
        system("cls");
        puts("Esta accion no se puede realizar a causa de que el carrito de compras esta vacio");
        getchar();
      }
      else
      {
        system("cls");
        printf("\nSe ha eliminado con exito el producto %s del carrito", carrito_de_compras[longitud_de_carrito].producto.nombre_producto);
        longitud_de_carrito--;
        getchar();
      }
    }
    else if (menu_compras_opcion == 2)
    {
      if (longitud_de_carrito == 0)
      {
        system("cls");
        puts("El carrito esta vacio, llenelo");
        getchar();
      }
      else
      {
        mostrar_carrito(carrito_de_compras, longitud_de_carrito);
      }
    }
    else if (menu_compras_opcion == 3)
    {
      STRUCTQUESTION pregunta_antes_de_salir[2];
      strcpy(pregunta_antes_de_salir[0].texto, "Si");
      strcpy(pregunta_antes_de_salir[1].texto, "No");

      int pregunta_antes_de_salir_opcion = select_menu("Seguro que quieres salir?", pregunta_antes_de_salir, 2);
      if (pregunta_antes_de_salir_opcion == 0)
      {
        longitud_de_carrito = 0;
        break;
      }
    }
    else if (menu_compras_opcion == -1)
    {
      longitud_de_carrito = 0;
      break;
    }
  }
}