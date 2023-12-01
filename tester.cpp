#include "sorts.hpp"



int main(){
    std::vector<int> unsorted;
    int duration =0;
    std::string txt = "input1.txt";
    std::ifstream inputFile(txt);

    std::string line;
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted.push_back(numb);
        }
    }
    inputFile.close();

    int i =0;
    for (const auto& storedWord : unsorted){
        while (i != 10)
        {
            std::cout << storedWord << " , ";
            i++;
        }
        i=0;
    }
    
    auto input1 = unsorted;
    std::vector<int> control = unsorted;
    std::cout << "Median: " << halfSelectionSort(input1,duration) << std::endl;
    std::sort(control.begin(), control.end());
    std::cout << "Median of control: " << control[findMedianIndex(control)] << std::endl;


    // std::vector<int> test = {2,6,1,0,7};
    // std::vector<int> sTest = {0,1,2,6,7};
    // std::cout << "Median: " << halfSelectionSort(test,duration) << std::endl;
    // std::sort(sTest.begin(), sTest.end());
    // std::cout << "Median of control: " << sTest[findMedianIndex(sTest)] << std::endl;
  

    // for (const auto& storedWord : test){
    //     std::cout << storedWord << " , ";
        
    // }

    // // Compare both vectors
    // if (input1 == control) {
    //     std::cout << "Your algorithm produces correct results.\n";
    // } else {
    //     std::cout << "Your algorithm produces incorrect results.\n";
    // }
    std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;


    return 0;
}
