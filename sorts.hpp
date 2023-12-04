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

//1) HalfSelectionSort.hpp
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

//2) StandardSort.hpp
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

inline int leftChild(int i){
    return 2 * i + 1; //left child = 2*parent +1 to account for 0 index
}
void percDown (std::vector<int>& heap, std::vector<int>::size_type hole){
    int child;
    int tmp;

    for(tmp = std::move(heap[hole]); leftChild(hole) < heap.size(); hole = child) //textbook implementation
    {
        child = leftChild(hole);
        if(child != heap.size() - 1 && heap[child] > heap[child +1])
            ++child;
        if(tmp > heap[child])
            heap[hole] = std::move(heap[child]);
        else
        break;
    }
    heap[hole] = std::move(tmp);
}
void buildHeap ( std::vector<int>& heap){
    for(int i = heap.size()/2-1; i >= 0; --i) /* buildHeap */
        percDown(heap, i);
}

 int halfHeapSort (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();
    //move first element to the back of the vector
    nums.push_back(nums[0]);
    buildHeap(nums);
    int middle = nums.size()/2;
    for(int j = nums.size()-1; j> middle+1; j--)
    {
        std::swap(nums[0], nums[j]); //precondition of percolate
        nums.pop_back(); //literally delete min
        percDown( nums, 0);
    }
    //once median is found which should be the root at index 1
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    // return medain 
    return nums[1];
 }

iter medianof3(std::vector<int> arr, iter left, iter right){ 
    iter mid = left + (std::distance(left,right))/2;
    std::cout  << "\n Left: " << *left << "   Mid: " << *mid << "   right: " << *right;
    if(*mid < *left){//sort the 3 elements
        std::iter_swap(left,mid);
    }
    if(*right < *left){
        std::iter_swap(left,right);
    }
    if(*right < *mid){
        std::iter_swap(mid,right);
    }
    std::iter_swap(mid,right-1);//place the median of the 3 at the end of the vector
    std::cout << "   Median of 3: " << *(right-1) << std::endl;
    return right-1; //return iterator to the pivot
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

    std::iter_swap(low,pivot);//swap pivot and i  -1 ruins?
    return low;//new position of pivot
}   

void quickRecursion(std::vector<int>& nums,iter left,iter right,iter mid){
    ; 
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
    int mid = findMedianIndex(nums);
    quickRecursion(nums,nums.begin(),nums.end()-1,middle); // end points to 1 over the last element in list
    
    std::cout << "\nMid index: " << mid << std::endl;
    //once median is found
    auto end = std::chrono::steady_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    duration = diff.count();
    // return medain 
    std::cout<< std::distance(nums.begin(),middle) << std::endl;
    return *middle;
}


// //7) WorstCaseQuickSelect.hpp
// // worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
// std::vector<int> worstCaseQuickSelect (void){

// }

// //8) MedianOfMediansMethod.hpp
// //Update: Median of medians will be hand-graded and your vector after the algorithm finishes does not need to exactly match my end result, but in order for your submission to qualify for grading, you must meet the following requirements:
// // - You completed QuickSelect
// // - Your median of medians runs on the autograder and returns the correct median.
// // - Your time for median of medians is within the expected range (which will be very broad).

// int medianOfMediansMethod ( std::vector<int>& nums, int& duration ){

// }
// // returns the median of medians of all elements contained between high and low, inclusive.
// // For maximum points, must also have a function called "medianOfFive" that calculates the median of 5 numbers in 6 comparisons, as we went over in class.
// // Note that median of medians is a pivot selection method. For partitioning, you'll use Hoare's partition again.
// int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){

// }

    // //start of warpper function
    // auto start = std::chrono::steady_clock::now();
    // // algorth goes here
    
    // //once median is found
    // auto end = std::chrono::steady_clock::now();

    // auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    // duration = diff.count();
    // // return medain 
    // return nums[mid];
