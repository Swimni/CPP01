#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Adresse de str      : " << &str << std::endl;
    std::cout << "Adresse pointeur    : " << stringPTR << std::endl;
    std::cout << "Adresse référence   : " << &stringREF << std::endl;

    std::cout << "Valeur de str       : " << str << std::endl;
    std::cout << "Valeur pointeur     : " << *stringPTR << std::endl;
    std::cout << "Valeur référence    : " << stringREF << std::endl;

    return 0;
}
