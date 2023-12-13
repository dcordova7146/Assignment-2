#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 

int findMedianIndex(std::vector<int>& nums){
    int size = nums.size();
    int mid = 0;
    if(size %2 == 0){ //if even
        mid = (size-1)/2;
    }else{
        mid = size/2;
    }
    return mid;
}

int standardSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::steady_clock::now();

    std::sort(nums.begin(),nums.end());
    int mid = findMedianIndex(nums);

    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    return nums[mid];
    // return medain 


}