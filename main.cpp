//
//  main.cpp
//  SlotMachineMathematician
//
//  Created by Lucas on 3/6/24.
//

#include <iostream>
#include <vector>
#include <map>


int main()
{
    std::vector<int> L { 1, 1, 2, 4, 5, 2, 2, 3, 4, 2, 2, 5, 3, 5, 3, 4, 2, 1, 2, 5, 4, 3 };
    std::vector<int> C { 3, 1, 2, 2, 3, 5, 4, 4, 2, 3, 3, 2, 1, 5, 4, 3, 3, 2, 1, 5, 4, 1 };
    std::vector<int> R { 2, 3, 5, 4, 4, 3, 1, 1, 2, 2, 3, 5, 4, 3, 2, 1, 2, 5, 5, 1, 3, 4 };
    
    std::map<int, int> winners = 
    { {111, 2}, {222, 7}, {333, 10}, {331, 2},{332, 2}, {334, 3},
        {335, 4}, {444, 15}, {441, 5}, {442, 5}, {443, 2}, {445, 6},
        {123, 2}, {551, 2}, {555, 70} };
    
    int spins = 0;
    int wins = 0;
    
    
    for(int a : L)
    {
        for (int b : C)
        {
            for (int c : R)
            {
                std::map<int, int>::iterator found = winners.find(a*100 + b*10 + c);
                if (found != winners.end())
                {
                    wins += found->second;
                }
                ++spins;
            }
        }
    }
    
    
    std::cout << spins << std::endl;
    std::cout << wins << std::endl;
    std::cout << wins / static_cast<double>(spins) * 100 << std::endl;
    
    return 0;
}
