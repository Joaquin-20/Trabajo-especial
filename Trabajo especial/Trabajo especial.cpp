#include <iostream>
#include "rogueutil.h"

void showItem(int col, int row, const char* text);

enum opciones {
    BORRAR_LIENZO = 0,
    VER_LISTA = 1,
    AGREGAR_NUEVA_FIGURA = 2,
    ELIMINAR_FIGURA = 3,
    GUARDAR_Y_SALIR = 4,
    SALIR = 5
};

int main()
{
    int op = SALIR;
    do
    {
        // Imprimir menu
        showItem(40, 10, "Borrar lienzo");
        showItem(40, 11, "Ver lista");
        showItem(40, 12, "Agregar nueva figura");
        showItem(40, 11, "Eliminar figura");
        showItem(40, 11, "guardar y salir");
        showItem(40, 11, "salir");

        int key = rogueutil::getkey();
        std::cout << key;
        rogueutil::anykey();
    } while (op != GUARDAR_Y_SALIR || op != SALIR);
    
}

void showItem(int col, int row, const char* text)
{
    rogueutil::locate(col, row);
    std::cout << text << '\n';
}