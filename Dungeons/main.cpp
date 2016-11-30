#include "Menu.h"
#include "Display.h"

int main() {

    Menu * main = new Menu();
    cout << "Game initialized" << endl;
    main->mainMenu();
    cout << "Thank you for playing" << endl;

    return 0;
}