// Este aarchivo es un header que enlaza todos los headers necesarios para el proyecto

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "structuras.h"
#include "menu.h"
#include "reportes.h"
#include "compras.h"

void agregar_cliente_a_cola();
void eliminar_cliente_de_cola();
void regenerar_relog_start_t();
clock_t obtener_tiempo_cliente();
clock_t obtener_tiempo_start_t();
STRUCTCOLA *obtener_cola_clientes();
void mover_a_ultimo();