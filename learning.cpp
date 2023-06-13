#include "learning.hpp"
#include <string>

Learning::Learning()
{
    this->path = "/home/KicamonIce/Documents/study/Note/English/";
}

int Learning::ToNumber(std::string num)
{
    int cnt = 0;
    bool f = num[0] == '-';
    for (int i = f; i < (int)num.size(); ++i)
    {
        cnt = cnt * 10 + (num[i] - '0');
    }
    if (f)
        cnt = -cnt;
    return cnt;
}

void Learning::BeforStudy()
{
    std::ifstream fin(this->path, std::ios::in);
    std::string data;
    while (std::getline(fin, data))
    {
        MyLearn cnt;
        int start = 0, pos = -1;
        pos = data.find("|", start);
        cnt.en = data.substr(start, pos - start);
        start = pos + 1;
        pos = data.find("|", start);
        cnt.ch = data.substr(start, pos - start);
        start = pos + 1;
        pos = data.find("|", start);
        cnt.val_stu = ToNumber(data.substr(start, pos - start));
        start = pos + 1;
        pos = data.find("|", start);
        cnt.val_test = ToNumber(data.substr(start, pos - start));
        this->AllInPad.push_back(cnt);
    }
    // std::cout << data << std::endl;
    sort(this->AllInPad.begin(), this->AllInPad.end(), [&](MyLearn a, MyLearn b) {
        if (a.val_test != b.val_test)
            return a.val_test < b.val_test;
        return a.val_stu < b.val_stu;
    });
    this->NumberForStudy = (int)this->AllInPad.size();
}

void Learning::UpdataWordsList()
{
    std::ofstream fout(this->path);
    for (auto idx : AllInPad)
        fout << idx.en << '|' << idx.ch << '|' << std::to_string(idx.val_stu) << '|' << std::to_string(idx.val_test)
             << '|' << std::endl;
    std::cout << "==================== End ===================" << std::endl;
}

Learning::~Learning()
{
    this->UpdataWordsList();
}
