#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_
#endif

#ifndef _GRAPHICS_
#define _GRAPHICS_
#include "graphics.hpp"
#endif

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
};

std::vector<std::string> stageToGraphic(stage stage) {
    std::vector<std::string> result(size(stage));
    std::transform(stage.begin(), stage.end(), result.begin(), [](auto line) {
        std::string res;
        std::transform(line.begin(), line.end(), res.begin(), [](auto nodeptr) {
            return nodeptr->getSymbol();
        });
        return res;
    });
    return result;
};

void graphic(stage stage, Character::charSymbol symbol, coord charCoord){
    std::vector<std::string> graphicStageV = stageToGraphic(stage);
    int x = charCoord.first;
    int y = charCoord.second;

    for (auto [e, i] = std::tuple{symbol.rbegin(), y}; e != symbol.rend(); ++e, ++i) {
        graphicStageV[i].replace(x, x + size(*e) - 1, *e);
    };

    clear();
    for (auto e: graphicStageV) {
        std::cout << e << std::endl;
    };
}