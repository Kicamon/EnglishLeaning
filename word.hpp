#include <algorithm>
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <string>
#include <time.h>
#include <vector>

class Word
{
  public:
    Word();
    void BeforStudy();
    void Menu();
    void Study();
    void UpdataWordsList();

    int NumberForStudy;
    std::vector<std::array<std::string, 3>> AllWords;
    ~Word();
};
