#include <app.h>

int main() {
    App* menu = new App(AppType::menu);
    menu->Launch();
    if (menu->GetAppChoice() == AppType::none) return 0;
    App* game = new App(menu->GetAppChoice());
    game->Launch();
}
// писькадрол
/*
уходи дверь закрой, 
у меня есть мефедрон
и не нужен больше твой
кокаинчик дорогой!!!  
ты ушел, а он пришел
*/
