#ifndef COLORS_H
#define COLORS_H

#ifdef _WIN32
  #include <windows.h>
  #include <iostream>

  enum Color { RESET = 7, CYAN = 11, GREEN = 10, YELLOW = 14, MAGENTA = 13, RED = 12, BOLD_ON = 15 };

  inline void setColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (color == RESET) {
      SetConsoleTextAttribute(hConsole, 7);
    } else {
      SetConsoleTextAttribute(hConsole, color);
    }
  }

  #define COLOR_CYAN setColor(CYAN)
  #define COLOR_GREEN setColor(GREEN)
  #define COLOR_YELLOW setColor(YELLOW)
  #define COLOR_MAGENTA setColor(MAGENTA)
  #define COLOR_RED setColor(RED)
  #define COLOR_RESET setColor(RESET)

#else
  #define COLOR_CYAN std::cout << "\033[36m"
  #define COLOR_GREEN std::cout << "\033[32m"
  #define COLOR_YELLOW std::cout << "\033[33m"
  #define COLOR_MAGENTA std::cout << "\033[35m"
  #define COLOR_RED std::cout << "\033[31m"
  #define COLOR_RESET std::cout << "\033[0m"
#endif

#endif
