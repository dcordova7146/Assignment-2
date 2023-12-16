#include "StandardSort.hpp"
#include "HalfSelectionSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"


int main(){
    std::vector<int> unsorted;
    std::vector<int> halfHeaped;
    std::vector<int> quickselected;
    std::vector<int> selectsorted;
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

    inputFile.open("heapsort1.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            halfHeaped.push_back(numb);
        }
    }   
    inputFile.close();

    inputFile.open("quickselect1.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            quickselected.push_back(numb);
        }
    }   
    inputFile.close();

    inputFile.open("selectionsort1.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            selectsorted.push_back(numb);
        }
    }   
    inputFile.close();



    //print vector
    // int i =0;
    // for (const auto& storedWord : unsorted){
    //     while (i != 10)
    //     {
    //         std::cout << storedWord << " , ";
    //         i++;
    //     }
    //     i=0;
    // }

    //make 7 copies for all 7 sorts
    auto copy1 = unsorted;
    auto copy2 = unsorted;
    auto copy3 = unsorted;
    auto copy4 = unsorted;
    auto copy5 = unsorted;
    auto copy6 = unsorted;

    auto control = unsorted;


    // gather data on the control std::sort on a copy of the input1 vector
    auto cstart = std::chrono::steady_clock::now();
    std::sort(control.begin(), control.end());
    auto cend = std::chrono::steady_clock::now();
    auto cdiff = std::chrono::duration_cast<std::chrono::microseconds>(cend-cstart);
    int controlduration = cdiff.count();
    //print all data on the control sort
    std::cout << std::endl << "-Control-" << std::endl;
    std::cout << "Median: " << control[findMedianIndex(control)] << std::endl;
    std::cout << "Duration: " << controlduration << " Micro Seconds" << std::endl;

    std::cout << std::endl << "-half selection sort-" << std::endl;
    std::cout << "Median: " << halfSelectionSort(copy1,duration) << std::endl;
    std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    duration = 0;

    std::cout << std::endl << "-standard sort-" << std::endl;
    std::cout << "Median: " << standardSort(copy2,duration) << std::endl;
    std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    duration = 0;

    std::cout << std::endl << "-Merge sort-" << std::endl;
    std::cout << "Median: " << mergeSort(copy3,duration) << std::endl;
    std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    duration = 0;

    // std::cout << std::endl << "-in place merge sort-" << std::endl;
    // std::cout << "Median: " << inPlaceMergeSort(copy4,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    std::cout << std::endl << "-half heap sort-" << std::endl;
    std::cout << "Median: " << halfHeapSort(copy5,duration) << std::endl;
    std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    duration = 0;

    // std::cout << std::endl << "-Quick Select sort-" << std::endl;
    // std::cout << "Median: " << quickSelect(copy6,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    //std::vector<int> test = {5,3,1,8,9,6,3};
    //std::vector<int> sTest = {6,8,9};
    // std::cout<< "real median: " << halfHeaped[0] << std::endl;
    // std::cout<< "size of output: " << halfHeaped.size() << std::endl;
     // for (const auto& storedWord : test){
    //     std::cout << storedWord << " , ";
        
    //print vector
    std::cout<< std::endl;
    for(int i =0;i<copy5.size();i++){
        std::cout << "Pos: " << i << " | mysort: " << copy5[i] << " | justins: " << halfHeaped[i] << " |"; 
        if(copy5[i] == halfHeaped[i-1]){
            std::cout << " match " << std::endl;
        }else{
            std:: cout<< " no match" << std::endl;
        }
        
        
    }
    // int i =0;
    // for (const auto& storedWord : copy6){
    //     if(i != 20)
    //     {
    //         std::cout << storedWord << " ";
    //         i++;
    //     }
    //     i=0;
    // }
    std::cout<< std::endl;
    //Compare both vectors
    // if (copy1 == quickselected) {
    //     std::cout << "Your Quick Select algorithm produces correct results.\n";
    // } else {
    //     std::cout << "Your Quick Select algorithm produces incorrect results.\n";
    // }
    // if (copy5 == halfHeaped) {
    //     std::cout << "Your HeapSort algorithm produces correct results.\n";
    // } else {
    //     std::cout << "Your HeapSort algorithm produces incorrect results.\n";
    // }
    // if (copy6 == quickselected) {
    //     std::cout << "Your Quick Select algorithm produces correct results.\n";
    // } else {
    //     std::cout << "Your Quick Select algorithm produces incorrect results.\n";
    // }



    return 0;
}
