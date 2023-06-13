#include <algorithm>
#include <array>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <string>
#include <time.h>
#include <vector>

class Learning
{
  public:
    Learning();

    void BeforStudy();
    void UpdataWordsList();
    static int ToNumber(std::string num);

    int NumberForStudy;
    std::string path;
    struct MyLearn
    {
        std::string en;
        std::string ch;
        int val_stu;
        int val_test;
    };
    std::vector<MyLearn> AllInPad;
    std::vector<MyLearn> ThisLearn;

    ~Learning();
};
