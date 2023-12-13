#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 
void merge(std::vector<int> array,std::vector<int>::iterator left, std::vector<int>::iterator right){
    //make sure to create left and right arrays this below should be in place
    if(std::distance(left,right) >1){
        std::vector<int>::iterator mid = left + (std::distance(left,right)/2);

        merge(array,left,mid);
        merge(array,mid,right);

        std::vector<int> leftHalf(left,mid);
        std::vector<int> rightHalf(mid,right);


        std::merge(leftHalf.begin(),leftHalf.end(),rightHalf.begin(),rightHalf.end(),left);
    }

    
}
//3) MergeSort.hpp
int mergeSort ( std::vector<int>& nums, int& duration ){
    //start of warpper function
    auto start = std::chrono::steady_clock::now();
    // algorth goes here
    merge(nums,nums.begin(),nums.end());
    //once median is found
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();

    // return medain 
    return nums[findMedianIndex(nums)];
}