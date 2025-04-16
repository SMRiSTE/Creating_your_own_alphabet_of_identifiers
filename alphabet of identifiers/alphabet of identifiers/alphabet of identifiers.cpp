#include <iostream>
#include <string>
#include "ident.h"

std::string GenerateNextIdentifier(const std::string& identifier) {
    std::unique_ptr<ident> id = std::make_unique<ident>();
    return id->Summery(identifier);
}

int main()
{
    setlocale(LC_ALL, "RU");
    std::string str;
    std::cin >> str;

    std::cout << GenerateNextIdentifier(str);
}