#define LEN_PRODUCTOS 30         // Longitud de la lista de productos
#define MAX_CANTIDAD_PRODUCTOS 5 // Cantidad maxima de productos de un mismo tipo que se pueden comprar

void start_venta(STRUCTPRODUCTOS *lista_de_productos, STRUCTPRODUCTOVENTA *producto_mas_vendido, int *cantidad_iniciar_compras,
                 int *cantidad_compras);
void set_productos(STRUCTPRODUCTOS *lista_de_productos, STRUCTPRODUCTOVENTA *producto_mas_vendido);