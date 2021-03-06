#ifndef _GRAPHICS_
#define _GRAPHICS_

#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#include <windows.h>
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

#include "readStage.hpp"
#include "character.hpp"

#ifndef _UTILITY_
#define _UTILITY_
#include <utility>
#endif

#ifndef _ALGORITHM_
#define _ALGORITHM_
#include <algorithm>
#endif

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include <iostream>
#endif

#ifndef _FUTURE_
#define _FUTURE_
#include <future>
#endif

#ifndef _FUNCTIONAL_
#define _FUNCTIONAL_
#include <functional>
#endif

#ifndef _IOMANIP_
#define _IOMANIP_
#include <iomanip>
#endif

using coord = std::pair<int, int>;

HANDLE hOut;
HANDLE hIn;
void clear();
std::vector<std::vector<std::string>> stageToGraphic(stage stage);
void graphic(stage stage, std::shared_ptr<Character::Character> mario, coord charCoord);
void startMenu();
BOOL SetConsoleSize(HANDLE hOut, int W, int H);
void showStageCount(int in);
void showGameOver();
void showGameClear(std::shared_ptr<Character::Character> mario);

#include "graphics.cpp"
#endif