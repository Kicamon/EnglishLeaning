#include "word.hpp"

Word::Word()
{
    this->path = "/home/KicamonIce/Documents/project/cpp/English study";
    this->BeforStudy();
}

void Word::BeforStudy() // 学习开始前的准备阶段
{
    std::string wordpad = this->path + "/MyWords.txt";
    std::ifstream fin(wordpad, std::ios::in); // 读取存储数据的文件
    std::string data;
    while (fin >> data) // 将所有的单词读入
    {
        int pos = -1;
        int start = 0;
        std::array<std::string, 3> v;
        for (int i = 0; i < 3; ++i)
        {
            pos = data.find(".", start);

            if (pos == -1)
                break;
            v[i] = data.substr(start, pos - start);
            start = pos + 1;
        }
        this->AllWords.push_back(v);
    }
    // for (int i = 0; i < this->AllWords.size(); ++i)
    //{
    // for (int j = 0; j < 3; ++j)
    // std::cout << this->AllWords[i][j] << ' ';
    // std::cout << std::endl;
    //}
    std::sort(this->AllWords.begin(), this->AllWords.end(), /*按照熟练度对单词进行排序*/
              [&](std::array<std::string, 3> worda, std::array<std::string, 3> wordb) {
                  int t1 = 0;
                  bool f = worda[2][0] == '-';
                  for (int i = f; i < (int)worda[2].size(); ++i)
                      t1 = t1 * 10 + (worda[2][i] - '0');
                  if (f)
                      t1 = -t1;
                  int t2 = 0;
                  f = worda[2][0] == '-';
                  for (int i = f; i < (int)worda[2].size(); ++i)
                      t2 = t2 * 10 + (worda[2][i] - '0');
                  if (f)
                      t2 = -t2;
                  return t1 < t2;
              });
}

void Word::Menu() // 开始菜单
{
    std::cout << "<========>" << std::endl;
    std::cout << "There are " << this->AllWords.size() << " words in the wordspad" << std::endl;
    std::cout << "<========>" << std::endl;
    std::cout << "Input the number for this study: " << std::endl;
    std::cin >> this->NumberForStudy; // 选择这次要学习的单词的数量
    if (this->NumberForStudy > (int)this->AllWords.size())
    {
        std::system("clear");
        std::cout << "Please enter a number less then the number of words in your wordpad" << std::endl;
        this->Menu();
        return;
    }
    std::cout << "============== Star =============" << std::endl;
    std::system("clear");
}

void Word::Study() // 正式学习
{
    std::vector<std::array<std::string, 3>> WordsThisStudy;
    for (int i = 0; i < this->NumberForStudy; ++i) // 读入这次要学习的单词
    {
        WordsThisStudy.push_back(this->AllWords[i]);
    }
    this->AllWords.erase(this->AllWords.begin(), this->AllWords.begin() + this->NumberForStudy);
    std::vector<int> num(this->NumberForStudy);
    std::iota(num.begin(), num.end(), 0);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(num.begin(), num.end(), std::default_random_engine(seed)); // 对单词进行随机打乱
    // for (int i = 0; i < this->NumberForStudy; ++i)
    //{
    // std::cout << num[i] << ' ';
    //}
    // std::cout << std::endl;
    std::queue<std::array<std::string, 3>> WordQueue;
    for (auto thisword : WordsThisStudy)
        WordQueue.push(thisword);
    std::vector<std::array<std::string, 3>> LeaningOutcomes;
    while (!WordQueue.empty()) // 输出这次学习的单词
    {
        auto temp = WordQueue.front();
        WordQueue.pop();
        std::cout << "Do you knowe the word?\n\n" << temp[0] << std::endl << std::endl;
        std::cout << "y[yes]/n[no]" << std::endl;
        char choose;
        std::cin >> choose;
        std::cout << std::endl;
        std::cout << "anwser: " << temp[1] << std::endl;
        if (choose == 'y')
        {
            std::cout << "Are you right?" << std::endl;
            std::cout << "y[yes]/n[no]" << std::endl;
            std::cin >> choose;
            if (choose == 'y')
            {
                std::cout << "Good!" << std::endl << std::endl;
                int t = 0;
                bool f = temp[2][0] == '-';
                for (int i = f; i < (int)temp[2].size(); ++i)
                    t = t * 10 + (temp[2][i] - '0');
                if (f)
                    t = -t;
                t++;
                temp[2] = std::to_string(t);
                LeaningOutcomes.push_back(temp);
            }
        }
        if (choose != 'y')
        {
            std::cout << "Please remember this word" << std::endl;
            int t = 0;
            bool f = temp[2][0] == '-';
            for (int i = f; i < (int)temp[2].size(); ++i)
                t = t * 10 + (temp[2][i] - '0');
            if (f)
                t = -t;
            t--;
            temp[2] = std::to_string(t);
            WordQueue.push(temp);
            std::cin.get();
            std::cin.get();
        }
        std::system("clear");
    }
    std::cout << "You had leaning " << this->NumberForStudy << " words this time!" << std::endl;
    std::cout << "Let's see what words has leaned: " << std::endl << std::endl;
    int number = 1;
    for (auto wordsleaned : LeaningOutcomes)
    {
        std::cout << number++ << "、" << wordsleaned[0] << ' ' << wordsleaned[1] << std::endl;
        if (wordsleaned[2][0] == '-' || wordsleaned[2][0] == '0')
            wordsleaned[2] = "1";
        else if (wordsleaned[2].size() > 1)
            wordsleaned[2] = "10";
        this->AllWords.push_back(wordsleaned);
    }
    std::cout << std::endl;
    std::cout << "=============== End =============" << std::endl;
}

void Word::UpdataWordsList() // 更新单词列表
{
    std::string wordpad = this->path + "/MyWords.txt";
    std::ofstream fout;
    fout.open(wordpad);
    for (auto InputWords : this->AllWords)
        fout << InputWords[0] << '.' << InputWords[1] << '.' << InputWords[2] << '.' << std::endl;
}

Word::~Word()
{
    UpdataWordsList();
}
