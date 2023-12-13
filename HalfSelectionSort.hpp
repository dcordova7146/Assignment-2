#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 
int halfSelectionSort ( std::vector<int>& nums, int& duration ){
    //selection sort compares the the left most unsorted element with every element after it keeping track of the smallest in the list then at the end swapping ith the smallest in the list
    auto start = std::chrono::steady_clock::now();

    auto smallest = nums.begin();
    auto mid = nums.begin() + findMedianIndex(nums);
    
    for(auto it = nums.begin();it != mid+1;it++){
        smallest = it;
        for(auto next=it+1;next<nums.end();next++){
            if(*smallest > *next){ //dereference to check if a further element is smaller
                std::iter_swap(smallest,next); //swap the values while keeping the pointers in the same position
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    return *mid;

}