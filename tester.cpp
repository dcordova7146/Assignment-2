#include "StandardSort.hpp"
#include "HalfSelectionSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"

int main(){
    // inputs 1-3 = 1k items
    // inputs 4-6 = 31k items
    // inputs 7-9 1m items
    std::vector<int> unsorted1;
    std::vector<int> unsorted2;
    std::vector<int> unsorted3;
    std::vector<int> unsorted4;
    std::vector<int> unsorted5;
    std::vector<int> unsorted6;
    std::vector<int> unsorted7;
    std::vector<int> unsorted8;
    std::vector<int> unsorted9;
    int duration =0;

    std::string txt = "input1.txt";
    std::ifstream inputFile(txt);
    std::string line;
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted1.push_back(numb);
        }
    }
    inputFile.close();
    inputFile.open("input2.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted2.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input3.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted3.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input4.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted4.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input5.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted5.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input6.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted6.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input7.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted7.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input8.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted8.push_back(numb);
        }
    }   
    inputFile.close();
    inputFile.open("input9.txt");
    while (std::getline(inputFile, line)){
        // Use a stringstream to tokenize the line into words
        std::istringstream iss(line);
        int numb;
        while (iss >> numb){
            unsorted9.push_back(numb);
        }
    }   

    //make 9 copies for all 9 sorts for input 
    auto copy1 = unsorted1;
    auto copy2 = unsorted2;
    auto copy3 = unsorted3;
    auto copy4 = unsorted4;
    auto copy5 = unsorted5;
    auto copy6 = unsorted6;
    auto copy7 = unsorted7;
    auto copy8 = unsorted8;
    auto copy9 = unsorted9;
    //control times
    std::cout << std::endl << "|Control: std::Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    standardSort(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    standardSort(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    standardSort(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    standardSort(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    standardSort(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    standardSort(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    standardSort(copy7,duration);
    std::cout << "Input 7 :" << duration << " Micro seconds| ";
    standardSort(copy8,duration);
    std::cout << "Input 8 :" << duration << " Micro seconds| ";
    standardSort(copy9,duration);
    std::cout << "Input 9 :" << duration << " Micro seconds| " << std::endl;
    //reset
    copy1 = unsorted1;
    copy2 = unsorted2;
    copy3 = unsorted3;
    copy4 = unsorted4;
    copy5 = unsorted5;
    copy6 = unsorted6;
    copy7 = unsorted7;
    copy8 = unsorted8;
    copy9 = unsorted9;
    std::cout << std::endl << "|Merge Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    mergeSort(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    mergeSort(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    mergeSort(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    mergeSort(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    mergeSort(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    mergeSort(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    mergeSort(copy7,duration);
    std::cout << "Input 7 :" << duration << " Micro seconds| ";
    mergeSort(copy8,duration);
    std::cout << "Input 8 :" << duration << " Micro seconds| ";
    mergeSort(copy9,duration);
    std::cout << "Input 9 :" << duration << " Micro seconds| " << std::endl;
    //reset
    copy1 = unsorted1;
    copy2 = unsorted2;
    copy3 = unsorted3;
    copy4 = unsorted4;
    copy5 = unsorted5;
    copy6 = unsorted6;
    copy7 = unsorted7;
    copy8 = unsorted8;
    copy9 = unsorted9;
    std::cout << std::endl << "|In-Place Merge Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    inPlaceMergeSort(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    inPlaceMergeSort(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    inPlaceMergeSort(copy7,duration);
    std::cout << "Input 7 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy8,duration);
    std::cout << "Input 8 :" << duration << " Micro seconds| ";
    inPlaceMergeSort(copy9,duration);
    std::cout << "Input 9 :" << duration << " Micro seconds| " << std::endl;
    //reset
    copy1 = unsorted1;
    copy2 = unsorted2;
    copy3 = unsorted3;
    copy4 = unsorted4;
    copy5 = unsorted5;
    copy6 = unsorted6;
    copy7 = unsorted7;
    copy8 = unsorted8;
    copy9 = unsorted9;
    std::cout << std::endl << "|Half Heap Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    halfHeapSort(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    halfHeapSort(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    halfHeapSort(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    halfHeapSort(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    halfHeapSort(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    halfHeapSort(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    halfHeapSort(copy7,duration);
    std::cout << "Input 7 :" << duration << " Micro seconds| ";
    halfHeapSort(copy8,duration);
    std::cout << "Input 8 :" << duration << " Micro seconds| ";
    halfHeapSort(copy9,duration);
    std::cout << "Input 9 :" << duration << " Micro seconds| " << std::endl;
    //reset
    copy1 = unsorted1;
    copy2 = unsorted2;
    copy3 = unsorted3;
    copy4 = unsorted4;
    copy5 = unsorted5;
    copy6 = unsorted6;
    copy7 = unsorted7;
    copy8 = unsorted8;
    copy9 = unsorted9;
    std::cout << std::endl << "|Half selection Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    halfSelectionSort(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    halfSelectionSort(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    halfSelectionSort(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    halfSelectionSort(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    halfSelectionSort(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    halfSelectionSort(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    //halfSelectionSort(copy7,duration);
    std::cout << "Input 7 :" << " Input too large for this sort| ";
    //halfSelectionSort(copy8,duration);
    std::cout << "Input 8 :" << " Input too large for this sort| ";
    //halfSelectionSort(copy9,duration);
    std::cout << "Input 9 :" << " Input too large for this sort| " << std::endl;
    //reset
    copy1 = unsorted1;
    copy2 = unsorted2;
    copy3 = unsorted3;
    copy4 = unsorted4;
    copy5 = unsorted5;
    copy6 = unsorted6;
    copy7 = unsorted7;
    copy8 = unsorted8;
    copy9 = unsorted9;
    std::cout << std::endl << "|Quick Selection Sort|" << std::endl;
    std::cout << "-1k items-"<< std::endl;
    quickSelect(copy1,duration);
    std::cout << "| Input 1 :" << duration << " Micro seconds| ";
    quickSelect(copy2,duration);
    std::cout << "Input 2 :" << duration << " Micro seconds| ";
    quickSelect(copy3,duration);
    std::cout << "Input 3 :" << duration << " Micro seconds| " <<std::endl;
    std::cout << "-31k items-"<< std::endl;
    quickSelect(copy4,duration);
    std::cout << "Input 4 :" << duration << " Micro seconds| ";
    quickSelect(copy5,duration);
    std::cout << "Input 5 :" << duration << " Micro seconds| ";
    quickSelect(copy6,duration);
    std::cout << "Input 6 :" << duration << " Micro seconds| " <<std::endl ;
    std::cout << "-1M items-"<< std::endl;
    quickSelect(copy7,duration);
    std::cout << "Input 7 :" << duration << " Micro seconds| ";
    quickSelect(copy8,duration);
    std::cout << "Input 8 :" << duration << " Micro seconds| ";
    quickSelect(copy9,duration);
    std::cout << "Input 9 :" << duration << " Micro seconds| " << std::endl;
    





    // // gather data on the control std::sort on a copy of the input1 vector
    // auto cstart = std::chrono::steady_clock::now();
    // std::sort(control.begin(), control.end());
    // auto cend = std::chrono::steady_clock::now();
    // auto cdiff = std::chrono::duration_cast<std::chrono::microseconds>(cend-cstart);
    // int controlduration = cdiff.count();


    // //print all data on the control sort
    // std::cout << "Median: " << control[findMedianIndex(control)] << std::endl;
    // std::cout << "Duration: " << controlduration << " Micro Seconds" << std::endl;

    // std::cout << std::endl << "-half selection sort-" << std::endl;
    // std::cout << "||1000 ITEMS||"
    // std::cout << "Median: " << halfSelectionSort(copy1,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;
    // std::cout << "||1000 ITEMS||"
    // std::cout << "Median: " << halfSelectionSort(copy2,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;

    // std::cout << std::endl << "-standard sort-" << std::endl;
    // std::cout << "Median: " << standardSort(copy2,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    // std::cout << std::endl << "-Merge sort-" << std::endl;
    // std::cout << "Median: " << mergeSort(copy3,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    // std::cout << std::endl << "-in place merge sort-" << std::endl;
    // std::cout << "Median: " << inPlaceMergeSort(copy4,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    // std::cout << std::endl << "-half heap sort-" << std::endl;
    // std::cout << "Median: " << halfHeapSort(copy5,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    // std::cout << std::endl << "-Quick Select sort-" << std::endl;
    // std::cout << "Median: " << quickSelect(copy6,duration) << std::endl;
    // std::cout << "Duration: " << duration << " Micro seconds" <<std::endl;
    // duration = 0;

    //std::vector<int> test = {5,3,1,8,9,6,3};
    //std::vector<int> sTest = {6,8,9};
    // std::cout<< "real median: " << hheap1[0] << std::endl;
    // std::cout<< "size of output: " << hheap1.size() << std::endl;
     // for (const auto& storedWord : test){
    //     std::cout << storedWord << " , ";
        
    //print vector
    //test quickselect
    // std::cout<< std::endl;
    // for(int i =0;i<copy6.size();i++){
    //     std::cout << "Pos: " << i << " | mysort: " << copy6[i] << " | justins: " << quickselected[i] << " |"; 
    //     if(copy6[i] == 50492874){
    //         std::cout<< "JBLBFKLAJNFKASNFKLANSFKLJNASKLFNLAK";
    //     }
    //     if(copy6[i] == quickselected[i]){
    //         std::cout << " match " << std::endl;
    //     }else{
    //         std:: cout<< " no match" << std::endl;
    //     }
        
        
    // }
    //test merge sort
    // std::cout<< std::endl;
    // for(int i =0;i<copy4.size();i++){
    //     std::cout << "Pos: " << i << " | mysort: " << copy4[i] << " | justins: " << copy2[i] << " |"; 
    //     if(copy4[i] == copy2[i]){
    //         std::cout << " match " << std::endl;
    //     }else{
    //         std:: cout<< " no match" << std::endl;
    //     }
        
        
    // }
    // int i =0;
    // for (const auto& storedWord : copy6){
    //     if(i != 20)
    //     {
    //         std::cout << storedWord << " ";
    //         i++;
    //     }
    //     i=0;
    // }
    //Compare both vectors
    // if (copy1 == quickselected) {
    //     std::cout << "Your Quick Select algorithm produces correct results.\n";
    // } else {
    //     std::cout << "Your Quick Select algorithm produces incorrect results.\n";
    // }
    // if (copy5 == hheap1) {
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
