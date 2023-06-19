#include "learning.hpp"

class MyWord : public Learning
{
  public:
    MyWord(std::string pwd);
    void Mune();
    void Study();
    void Test();
    ~MyWord();
};
