#include "myword.hpp"
#include <iostream>

int main()
{
    std::cout << "===============================" << std::endl;
    std::cout << "Choose what you want to study: " << std::endl;
    std::cout << "1. My words" << std::endl;
    std::cout << "2. Word pad" << std::endl;
    std::cout << "0. End" << std::endl;
    std::cout << "===============================" << std::endl;
    int op;
    std::cin >> op;
    std::system("clear");
    if (op == 1)
    {
        MyWord study("MyWords.txt");
        study.Mune();
    }
    else if (op == 2)
    {
        MyWord study("PubMed.txt");
        study.Mune();
    }
    return 0;
}
