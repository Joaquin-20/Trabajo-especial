#include <iostream>
#include "rogueutil.h"



void showItem(int col, int row, const char* text, bool selected);

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
    int y = 0;
    rogueutil::hidecursor();
    do
    {
        // Imprimir menu
        rogueutil::setBackgroundColor(rogueutil::BLACK);

        showItem(40, 10, "     Borrar lienzo    ", y == BORRAR_LIENZO);
        showItem(40, 11, "       Ver lista      ", y == VER_LISTA);
        showItem(40, 12, " Agregar nueva figura ", y == AGREGAR_NUEVA_FIGURA);
        showItem(40, 13, "    Eliminar figura   ", y == ELIMINAR_FIGURA);
        showItem(40, 14, "    guardar y salir   ", y == GUARDAR_Y_SALIR);
        showItem(40, 15, "         salir        ", y == SALIR);

        switch (rogueutil::getkey())
        {
        case rogueutil::KEY_DOWN:
            y++;
            if (y > 5)
                y = 5;
            break;
        case rogueutil::KEY_UP:
            y--;
            if (y < 0)
                y = 0;
            break;
        case rogueutil::KEY_ENTER:
            op = y;
            break;
        default:
            break;
        }
    } while (op != GUARDAR_Y_SALIR || op != SALIR);

}

void showItem(int col, int row, const char* text, bool selected)
{
    if (selected)
        rogueutil::setBackgroundColor(rogueutil::BLUE);
    else
        rogueutil::setBackgroundColor(rogueutil::BLACK);
    rogueutil::locate(col, row);
    std::cout << text << '\n';
}