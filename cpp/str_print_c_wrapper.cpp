#include "str_print.h"
extern "C" {
void str_print(char* test) {
    StrPrint printer;
    std::string str = test;
    printer.print(str);
}
}