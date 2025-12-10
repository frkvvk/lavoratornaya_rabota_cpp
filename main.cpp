#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct shaurma
{
    int kalorii;
    double ves;
    wstring sous;
    wstring meat;
};

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    //функция 1:
    wifstream inFile("ababa.txt");
    vector<shaurma> vse_shaurmy;
    while(!inFile.eof())
    {
        shaurma vid;
        inFile >> vid.kalorii;
        inFile >> vid.ves;
        inFile >> vid.sous;
        inFile >> vid.meat;
        vse_shaurmy.push_back(vid);
    }
    //функция 2:
    wstringstream ss;
    int k = 12;
    ss << left << setw(k) << "Соус" << setw(k) << "Вес" << setw(k) << "Мясо" << setw(k) << "Килокалории" << endl;
    for(const auto &vid : vse_shaurmy)
    {
        ss << endl;
        ss << left << setw(k) << vid.sous << setw(k) << vid.ves << setw(k) << vid.meat << setw(k) << vid.kalorii << endl;
    }
    wcout << ss.str();
    //функция 3:
    ofstream out("out.bin", ios::binary);
    for(const auto &vid : vse_shaurmy)
    {
        out.write(reinterpret_cast<const char*>(&vid), sizeof(shaurma));
    }

    return 0;
}
