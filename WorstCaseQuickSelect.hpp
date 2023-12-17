#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::vector<int> worstCaseQuickSelect (void){
    std::vector<int> worstCase;
    for(int i = 20000;i >= 1;--i){
        worstCase.push_back(i);
    }
    return worstCase;
}
