#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 13

int select_menu(char *header, STRUCTQUESTION *questions, int len);
int select_product(char* header, STRUCTPRODUCTOS *products, int len);
int select_num(char *header, int min, int max, int initial);
void mostrar_carrito(STRUCTPRODUCTOVENTA *carrito_de_compras, int longitud_de_carrito);