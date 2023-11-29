#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>

//1) HalfSelectionSort.hpp
int halfSelectionSort ( std::vector<int>& nums, int& duration ){
    //selection sort compares the the left most unsorted element with every element after it keeping track of the smallest in the list then at the end swapping ith the smallest in the list
    int length = nums.length();
    int middle = 0;

    if(length %2 !0){ //if length is odd
        middle = (length+1)/2;
    }else{
        middle = length/2;
    }

    int temp;
    int smallest; // index to smallest num in list
    for(int i=0;i < middle +1;i++){ //outer loop keeps track of the index of the smallest num in the list
        smallest = i;
        for(int j=i+1;j < length;j++){ //inner loop compares the value at smallest with every item in the list to find the smallest in the list
            if(nums[smallest] > nums[j]){
                smallest = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[smallest];
        nums[smallest] = temp;
    }
    
    return nums[middle]; //return middle element
}

//2) StandardSort.hpp
int standardSort ( std::vector<int>& nums, int& duration ){
    int length = nums.length();
    int middle =0;
    if(length %2 !0){ //if length is odd
        middle = (length+1)/2;
    }else{
        middle = length/2;
    }

    std::sort(nums.begin(),nums.end());
    return nums[middle]; //return middle element

}

//3) MergeSort.hpp
int mergeSort ( std::vector<int>& nums, int& duration ){
    //chrono time 
    mergeS(nums);
    int length = nums.length();
    int middle =0;
    if(length %2 !0){ //if length is odd
        return middle = (length+1)/2;
    }else{
        return middle = length/2;
    }

}

void mergeS(std::vector<int>& nums){
    std::vector<int> leftHalf;
    std::vector<int> rightHalf;
    int length = nums.length();

    if(length <= 1){ //base case
        return;
    }

    int j =0; //index for right half array

    for(auto it = nums.begin();it < nums.length();it++){
        if(i < floor(nums.length/2)){
            leftHalf[it] = nums[it];
        }else{
            rightHalf[j] = nums[it];
            j++
        }
        
    }
    
    int middle =0;
    if(length %2 !0){ //if length is odd
        middle = (length+1)/2;
    }else{
        middle = length/2;
    }
    
    // Create left and right halves
    std::vector<int> leftHalf(nums.begin(), nums.begin() + middle);
    std::vector<int> rightHalf(nums.begin() + middle, nums.end());

    // Recursively sort the two halves
    mergeS(leftHalf);
    mergeS(rightHalf);

    
}

//4) InPlaceMergeSort.hpp
int inPlaceMergeSort ( std::vector<int>& nums, int& duration ){

}

//5) HalfHeapSort.hpp
// should be min heap to delete all values lower than median
int halfHeapSort ( std::vector<int>& nums, int& duration ){

    for( int i = nums.size( ) / 2 - 1; i >= 0; --i ){ /* buildHeap */
        percDown( nums, i, nums.size( ) );
        for( int j = nums.size( ) - 1; j > 0; --j ){
            std::swap( nums[ 0 ], nums[ j ] ); /* deleteMax */
            percDown( nums, 0, j );
        }
    }
}

16 /**
17 * Internal method for heapsort.
18 * i is the index of an item in the heap.
19 * Returns the index of the left child.
20 */
 inline int leftChild( int i )
 {
 return 2 * i + 1;
 }



// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown ( std::vector<int>& heap, std::vector<int>::size_type hole ){

 int child;
 int tmp;

 for( tmp = std::move( heap[ i ] ); leftChild( i ) < n; i = child )
 {
 child = leftChild( i );
 if( child != n - 1 && heap[ child ] < heap[ child +1])
 ++child;
 if( tmp < heap[ child ] )
heap[ i ] = std::move( heap[ child ] );
    else
    break;
    }
    heap[ i ] = std::move( tmp );
}

void buildHeap ( std::vector<int>& heap){

}

//6) QuickSelect.hpp
int quickSelect ( std::vector<int>& nums, int& duration ){

}
// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
//Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){

}

//7) WorstCaseQuickSelect.hpp
// worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning. The input it generates must be of length 20,000, and contain each number from 1-20000 once.
std::vector<int> worstCaseQuickSelect (void){

}

//8) MedianOfMediansMethod.hpp
//Update: Median of medians will be hand-graded and your vector after the algorithm finishes does not need to exactly match my end result, but in order for your submission to qualify for grading, you must meet the following requirements:
// - You completed QuickSelect
// - Your median of medians runs on the autograder and returns the correct median.
// - Your time for median of medians is within the expected range (which will be very broad).

int medianOfMediansMethod ( std::vector<int>& nums, int& duration ){

}
// returns the median of medians of all elements contained between high and low, inclusive.
// For maximum points, must also have a function called "medianOfFive" that calculates the median of 5 numbers in 6 comparisons, as we went over in class.
// Note that median of medians is a pivot selection method. For partitioning, you'll use Hoare's partition again.
int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){

}
