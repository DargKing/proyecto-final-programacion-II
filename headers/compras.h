typedef struct {
  int id;
  char nombre_producto[124];
  float precio_unitario;
} STRUCTPRODUCTOS;

typedef struct {
  STRUCTPRODUCTOS producto;
  int cantidad;
} STRUCTPRODUCTOVENTA;

#define MAX_LEN_CARRO_PRODUCTOS 10
#define LEN_PRODUCTOS 30
#define MAX_CANTIDAD_PRODUCTOS 5

void start_venta();
void set_productos();