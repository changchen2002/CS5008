/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/single-threaded-cpu/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Task structure
typedef struct {
    int enqueueTime;
    int processingTime;
    int index;
} Task;

// Compare functions
int compareTasksByEnqueueTime(const void* a, const void* b) {
    Task* t1 = (Task*)a;
    Task* t2 = (Task*)b;
    if (t1->enqueueTime == t2->enqueueTime)
        return t1->index - t2->index;
    return t1->enqueueTime - t2->enqueueTime;
}

int compareTasksByProcessingTime(const void* a, const void* b) {
    Task* t1 = (Task*)a;
    Task* t2 = (Task*)b;
    if (t1->processingTime == t2->processingTime)
        return t1->index - t2->index;
    return t1->processingTime - t2->processingTime;
}

// Heap operations
void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void pushHeap(Task* heap, int* size, Task newTask) {
    int i = (*size)++;
    heap[i] = newTask;
    
    // Bubble up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (compareTasksByProcessingTime(&heap[parent], &heap[i]) <= 0) break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Task popHeap(Task* heap, int* size) {
    Task result = heap[0];
    heap[0] = heap[--(*size)];
    
    // Bubble down
    int i = 0;
    while (2 * i + 1 < *size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < *size && compareTasksByProcessingTime(&heap[right], &heap[left]) < 0)
            smallest = right;
        if (compareTasksByProcessingTime(&heap[i], &heap[smallest]) <= 0) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    
    return result;
}

// Main function
int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize) {
    // Create and initialize task list
    Task* taskList = (Task*)malloc(sizeof(Task) * tasksSize);
    for (int i = 0; i < tasksSize; i++) {
        taskList[i].enqueueTime = tasks[i][0];
        taskList[i].processingTime = tasks[i][1];
        taskList[i].index = i;
    }
    
    // Sort by enqueue time
    qsort(taskList, tasksSize, sizeof(Task), compareTasksByEnqueueTime);
    
    int* result = (int*)malloc(sizeof(int) * tasksSize);
    *returnSize = 0;
    
    Task* minHeap = (Task*)malloc(sizeof(Task) * tasksSize);
    int heapSize = 0;
    long long currentTime = 0;
    int taskIndex = 0;
    
    while (taskIndex < tasksSize || heapSize > 0) {
        // Add available tasks to heap
        while (taskIndex < tasksSize && taskList[taskIndex].enqueueTime <= currentTime) {
            pushHeap(minHeap, &heapSize, taskList[taskIndex++]); 
        }
        
        if (heapSize == 0) {
            // CPU idle, jump to next task time
            currentTime = (long long)taskList[taskIndex].enqueueTime;
        } else {
            // Process next task
            Task nextTask = popHeap(minHeap, &heapSize);
            result[(*returnSize)++] = nextTask.index;
            currentTime += nextTask.processingTime;
        }
    }
    
    free(taskList);
    free(minHeap);
    return result;
}


/*
A min-heap is used to store tasks that are ready to be processed, prioritizing tasks with the smallest processingTime.
By maintaining the heap, the task with the shortest processingTime is always at the root.

Time Complexity:

The time complexity of the algorithm can be broken down into several parts:
	1.	Sorting the tasks: The qsort function is used to sort the tasks based on their enqueue time. Sorting has a time complexity of O(N log N), where N is the number of tasks (tasksSize).
	2.	Heap operations (inserting and removing tasks):
	•	Each task is inserted into the heap once, and each insertion operation takes O(log K) time, where K is the number of tasks currently in the heap. In the worst case, this is O(log N) because at any point, the heap can contain up to N tasks.
	•	For each task, the heap is either updated by adding a task (pushHeap) or removing a task (popHeap). Each heap operation (insertion or removal) takes O(log N) time.
Therefore, the total time complexity for heap operations over all tasks is O(N log N).
	3.	Total Time Complexity:
	•	Sorting the tasks: O(N log N)
	•	Heap operations (for all tasks): O(N log N)
Thus, the total time complexity is O(N log N).

Space Complexity:
	1.	Task list (taskList):
	•	We create an array of tasks to store all the tasks, which takes O(N) space.
	2.	Min Heap (minHeap):
	•	The heap is used to store tasks that are ready to be processed. In the worst case, the heap can store all N tasks simultaneously, so it requires O(N) space.
	3.	Result array (result):
	•	The result array stores the order of task indices, so it also requires O(N) space.
	4.	Total Space Complexity:
	•	The space complexity is the sum of the space required for the task list, the heap, and the result array. Therefore, the total space complexity is O(N).

Edge Cases:
	1.	No tasks: If tasksSize == 0, the algorithm should return an empty result array. The algorithm handles this case correctly because there are no tasks to process, and the loop will not run.
	2.	Tasks with identical enqueue times: If multiple tasks have the same enqueueTime, the algorithm will use the index as a tie-breaker (in the compareTasksByEnqueueTime function). This ensures that tasks with the same enqueue time are processed in the correct order of their index.
	3.	All tasks have zero processing time: If all tasks have processingTime == 0, the algorithm should still return the correct order of task indices because the CPU will process them instantly. The loop will still work, and tasks will be processed based on their enqueue time.
	4.	Tasks with large processing times: The algorithm correctly handles tasks with large processingTime values, and there are no issues with overflow since long long is used for currentTime.
	5.	CPU idle time: If the CPU becomes idle (i.e., no tasks are available to process at the current time), the algorithm jumps to the next available task’s enqueueTime. This case is handled by checking heapSize == 0 and setting currentTime to the enqueueTime of the next task.
	6.	All tasks arrive at the same time: If all tasks arrive at the same enqueueTime, the tasks will be sorted by processingTime, and the CPU will process them in ascending order of their processingTime.
	7.	Tasks with very large enqueueTime values: If the tasks have large enqueueTime values, the algorithm will still handle them correctly as long as the enqueueTime values are within the bounds of the data type used (int or long long).

*/