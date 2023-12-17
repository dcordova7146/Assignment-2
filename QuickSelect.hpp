#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 

int findMedianIndexQS(std::vector<int>& nums){
    int size = nums.size();
    int mid = 0;
    if(size %2 == 0){ //if even
        mid = (size-1)/2;
    }else{
        mid = size/2;
    }
    return mid;
}

iter medianof3(std::vector<int> arr, iter left, iter right){ 
    iter mid = left + (std::distance(left,right))/2;
    //edge case all 3 are equal use the left as the mid
    if(*left == *mid || *left == *right || *right == *mid) {
        std::iter_swap(left, right);
        return right;
    }
    //left is median
    if((*mid < *left && *left < *right) || (*right < *left && *left < *mid)){
        std::iter_swap(left,right);
        
    }//mid is the median
    else if((*left < *mid && *mid < *right) || (*right < *mid && *mid < *left)){
        std::iter_swap(mid,right);
        
    }
    return right; //right is implicitly the median of the three

}
// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
//Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    int pivot = *high; //in textbook high = j low =j
    auto j = high -1 ; //move j so that the pivot is always in last spot
    auto i = low;
    
    while(true){
        while(*i < pivot&& i<high){ //while the value at i is less than pivot move to next index and as long as the left pointer has not crossed right
            i++;
        }
        while(*j > pivot&& j>low){ // while the value at j is greater than pivot move down and as long as right pointer has not crossed left
            j--;
        }
        if(i>=j){ //if pointers have crossed
            std::swap(*i,*high);
            return i; // return pointer to pivot
        }
        std::swap(*i,*j);//value at i is greater than value at j so swap them 
        i++; j--;
    }
}   
void quickRecursion(std::vector<int>& nums,iter left,iter right,iter mid){    
   if(left + 10 <=right){
    auto pivot = hoarePartition(nums,left,medianof3(nums,left,right));

    //check where the pivot is in relation to the where the median should be and recurse only on that portion
    if(mid <= pivot){
        quickRecursion(nums,left,pivot-1,mid);
    }else if(mid >pivot + 1){
        quickRecursion(nums,pivot+1,right,mid);
    }
   }else{
    std::sort(left,right+1);
    return;
   }
}
//6) QuickSelect.hpp
int quickSelect ( std::vector<int>& nums, int& duration ){
    //start of warpper function
    auto start = std::chrono::steady_clock::now();
    // algorth goes here
    int fmid = findMedianIndexQS(nums);
    std::vector<int>::iterator middle = nums.begin() + fmid ;

    quickRecursion(nums,nums.begin(),nums.end()-1,middle); // end points to 1 over the last element in list

    auto end = std::chrono::steady_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    // return medain 
    
    return *middle;
}