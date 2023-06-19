#include "myword.hpp"

MyWord::MyWord(std::string pwd)
{
    this->path += pwd;
    this->BeforStudy();
}

void MyWord::Mune()
{
    std::cout << "There are " << this->NumberForStudy << " words in the pad" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Study Test or End" << std::endl;
    std::cout << "1. Study" << std::endl;
    std::cout << "2. Test" << std::endl;
    std::cout << "0. End" << std::endl;
    std::cout << "===============================" << std::endl;
    int op;
    std::cin >> op;
    if (op == 1)
        this->Study();
    else if (op == 2)
        this->Test();
    else
        return;
}

void MyWord::Study()
{
    std::cout << "Number for this study: ";
    std::cin >> this->NumberForStudy;
    std::cin.get();

    for (int i = 0; i < this->NumberForStudy;)
    {
        for (int j = 0; j < 5 && i < this->NumberForStudy; ++j, ++i)
        {
            std::cout << this->AllInPad[i].en << std::endl;
            std::cout << this->AllInPad[i].ch << std::endl << std::endl;
            this->AllInPad[i].val_stu++;
        }
        if (i < this->NumberForStudy)
            std::cout << "Enter to continue" << std::endl;
        else
            std::cout << "Enter to end" << std::endl;
        std::cin.get();
    }
}

void MyWord::Test()
{
    std::cout << "Number for this test: ";
    std::cin >> this->NumberForStudy;
    std::vector<int> num(this->NumberForStudy);
    std::iota(num.begin(), num.end(), 0);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(num.begin(), num.end(), std::default_random_engine(seed)); // 对单词进行随机打乱
    for (int idx : num)
        this->ThisLearn.push_back(this->AllInPad[idx]);
    this->AllInPad.erase(this->AllInPad.begin(), this->AllInPad.begin() + this->NumberForStudy);
    std::system("clear");
    std::vector<MyLearn> &tmp1 = this->ThisLearn, tmp2;
    std::vector<MyLearn> res = this->ThisLearn;
    while (true)
    {
        for (auto &cnt : tmp1)
        {
            std::cout << cnt.en << std::endl << std::endl;
            std::cout << "Do you know it?" << std::endl;
            std::cout << "y[yes]/n[no]" << std::endl;
            char op = 'y';
            std::cin >> op;
            std::cout << "Answer: " << std::endl;
            std::cout << cnt.ch << std::endl << std::endl;
            if (op == 'y')
            {
                std::cout << "Are you right?" << std::endl;
                std::cout << "y[yes]/n[no]" << std::endl;
                std::cin >> op;
                if (op == 'y')
                    std::cout << "Congratulate!" << std::endl;
                cnt.val_test++;
                std::cin.get();
                std::system("clear");
            }
            if (op == 'n')
            {
                std::cout << "Please remember it" << std::endl;
                tmp2.push_back(cnt);
                cnt.val_test--;
                std::cin.get();
                std::system("clear");
            }
        }
        if (!tmp2.empty())
        {
            std::shuffle(tmp2.begin(), tmp2.end(), std::default_random_engine(seed)); // 对单词进行随机打乱
            tmp1 = tmp2;
            tmp2.clear();
        }
        else
            break;
    };
    for (auto cnt : this->ThisLearn)
    {
        this->AllInPad.push_back(cnt);
    }

    std::cout << "You had test " << this->NumberForStudy << " words this time" << std::endl;
    std::cout << "Let's see it: " << std::endl;
    int Num = 1;
    for (auto out : res)
    {
        std::cout << Num++ << "、" << std::endl << out.en << std::endl << out.ch << std::endl << std::endl;
    }
}

MyWord::~MyWord()
{
}
