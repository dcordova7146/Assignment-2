#include <vector> 
#include <iterator>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int>::iterator iter; 
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