#include <iostream>

#include "str_print.h"
void StrPrint::print(const std::string& text) { std::cout << text << std::endl; }
StrPrint::StrPrint() { std::cout << "构造了一个StrPrint的实例" << std::endl; }
