#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 

iter medianof3(std::vector<int> arr, iter left, iter right){ 
    iter mid = left + (std::distance(left,right))/2;
    //std::cout  << "\n Left: " << *left << "   Mid: " << *mid << "   right: " << *right;
    iter temp = right;
    if(*left < *right && *left > *mid){
        std::iter_swap(left,right);
    }else if(*right < *left && *right > *mid){
        std::iter_swap(right,right);
    }else{
        std::iter_swap(mid,right);
    }

    return right-1;
    // if(*mid < *left){//sort the 3 elements
    //     std::iter_swap(left,mid);
    // }
    // if(*right < *left){
    //     std::iter_swap(left,right);
    // }
    // if(*right < *mid){
    //     std::iter_swap(mid,right);
    // }
    // std::iter_swap(mid,right-1);//place the median of the 3 at the end of the vector
    // //std::cout << "   Median of 3: " << *(right-1) << std::endl;
    // return right-1; //return iterator to the pivot
}

// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
//Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    auto pivot = high; //in textbook high = j low =j
    high--; //move j so that the pivot is always in last spot
    low++;
    for(;;){
        while(*low < *pivot){
            low++;}
        while(*high > *pivot){  
            high--;}
        if(low < high){
            std::iter_swap(low,high);
        }
        else
            break;
    }

    std::iter_swap(low,pivot);//swap pivot textbook implementation increments regardless of tru comparison my version only on true thus i dont need to subrtact from pivot
    return low;//new position of pivot
}   

void quickRecursion(std::vector<int>& nums,iter left,iter right,iter mid){    
    if(std::distance(left,right) <= 10){//base case
        std::sort(left,right);
        return;
    }
    auto pivot = hoarePartition(nums,left,medianof3(nums,left,right));

    //check where the pivot is in relation to the where the median should be and recurse only on that portion
    if(mid <= pivot){
        quickRecursion(nums,left,pivot-1,mid);
    }else if(mid > pivot + 1){
        quickRecursion(nums,pivot+1,right,mid);
    }

}
//6) QuickSelect.hpp
int quickSelect ( std::vector<int>& nums, int& duration ){
    //start of warpper function
    auto start = std::chrono::steady_clock::now();
    // algorth goes here
    iter middle = nums.begin() + (std::distance(nums.begin(),nums.end()-2))/2;
    //int mid = findMedianIndex(nums);
    quickRecursion(nums,nums.begin(),nums.end()-1,middle); // end points to 1 over the last element in list
    
    // std::cout << "\nMid index: " << mid << std::endl;
    // std::cout << "\nMid iterator index: " << std::distance(nums.begin(),middle) << std::endl;
    //once median is found
    auto end = std::chrono::steady_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    // return medain 
    
    return *middle;
}