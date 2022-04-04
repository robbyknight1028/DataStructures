#include "btree.h"



int main()
{
    int answer;
    int randoNum;
    int answer2;
    BTree t(5);
    std::cout << "Enter a number larger than 50";
    std::cin >> answer;
    answer2 = answer * 3;
    for (int i = 0; i < answer; i++) {

        randoNum = rand() % answer2;
        t.insert(randoNum);
    }
   
    t.search();
    


    return 0;
}