#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 

void inPlaceMerge(std::vector<int> array,std::vector<int>::iterator left, std::vector<int>::iterator right){
    //make sure to create left and right arrays this below should be in place
    if(std::distance(left,right) >1){
        iter mid = left + (std::distance(left,right)/2);

        inPlaceMerge(array,left,mid);
        inPlaceMerge(array,mid,right);


        std::inplace_merge(left,mid,right);
    }

    
}
//4) InPlaceMergeSort.hpp
int inPlaceMergeSort ( std::vector<int>& nums, int& duration ){
    //start of warpper function
    auto start = std::chrono::steady_clock::now();
    // algorth goes here
    inPlaceMerge(nums,nums.begin(),nums.end());
    //once median is found
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();

    // return medain 
    return nums[findMedianIndex(nums)];

}