#include <iostream>
#include <list>
#include <chrono>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

void list_push_front(list<int> myList);
void list_push_back(list<int> myList);
void list_delete_front(list<int> myList);
void list_delete_back(list<int> myList);
void stack_push(stack<int> myStack);
void stack_pop(stack<int> myStack);
void queue_push(queue<int> myQueue);
void queue_pop(queue<int> myQueue);
void deque_push_front(deque<int> myDeque);
void deque_push_back(deque<int> myDeque);
void deque_pop_front(deque<int> myDeque);
void deque_pop_back(deque<int> myDeque);

void heapify(vector<int> &myVector, int size, int i);
void heap_sort(vector<int> &myVector);
void merge(vector<int> &myVector, int low, int mid, int high);
void merge_sort(vector<int> &myVector, int low, int high);
void quick_sort(vector<int> &myVector, int low, int high);
int partition(vector<int> &myVector, int low, int high);
void swap(int* a, int* b);


int main() {
   auto start = chrono::high_resolution_clock::now();
   const int MAX_NUM = 990000;
   list<int> myList;
   stack<int> myStack;
   queue<int> myQueue;
   deque<int> myDeque;
   vector<int> myVector;
   vector<int> origVector; // copy of vector
   set<int> mySet;
   unordered_set<int> myUnorderedSet;
   

   for (int i = 0; i < MAX_NUM; i++) {
      myList.push_back(rand());
      myStack.push(rand());
      myQueue.push(rand());
      myDeque.push_back(rand());
      myVector.push_back(rand());
      mySet.insert(rand());
      myUnorderedSet.insert(rand());
   }

   for (int i = 0; i < myVector.size(); i++) {
      origVector.push_back(myVector[i]);
   }

   cout << "LIST:\n";
   list_push_front(myList);
   list_push_back(myList);
   list_delete_front(myList);
   list_delete_back(myList);

   cout << "STACK:\n";
   stack_push(myStack);
   stack_pop(myStack);
   cout << "Items cannot be added or deleted from the front of a stack.\n\n";

   cout << "QUEUE:\n";
   queue_push(myQueue);
   queue_pop(myQueue);
   cout << "Items cannot be added to the front of a queue or removed from the back of a queue.\n\n";

   cout << "DEQUE:\n";
   deque_push_front(myDeque);
   deque_push_back(myDeque);
   deque_pop_front(myDeque);
   deque_pop_back(myDeque);
   auto finish = chrono::high_resolution_clock::now();
   chrono::duration<double> elapsed = finish - start;
   cout << fixed << elapsed.count() << " s; ";
   cout << endl << endl;

   int size = myVector.size();

   cout << "QUICK SORT:\n";
   start = chrono::high_resolution_clock::now();
   quick_sort(myVector, 0, size - 1);
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl; 
   // replace the vector with its original contents
   for (int i = 0; i < myVector.size(); i++) {
      myVector[i] = origVector[i];
   }

   cout << "MERGE SORT:\n";
   start = chrono::high_resolution_clock::now();
   merge_sort(myVector, 0, size - 1);
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;
   // replace the vector with its original contents
   for (int i = 0; i < myVector.size(); i++) {
      myVector[i] = origVector[i];
   }

   cout << "HEAP SORT:\n";
   start = chrono::high_resolution_clock::now();
   heap_sort(myVector);
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;
   // replace the vector with its original contents
   for (int i = 0; i < myVector.size(); i++) {
      myVector[i] = origVector[i];
   }

   cout << "SEARCH IN VECTOR:\n";
   start = chrono::high_resolution_clock::now();
   if (find(myVector.begin(), myVector.end(), 12883) != myVector.end())
      cout << "Found\n";
   else cout << "Not found\n";
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;

   cout << "SEARCH IN LIST: \n";
   start = chrono::high_resolution_clock::now();
   if (find(myList.begin(), myList.end(), 12883) != myList.end())
      cout << "Found\n";
   else cout << "Not found\n";
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;

   cout << "SEARCH IN SET: \n";
   start = chrono::high_resolution_clock::now();
   if (find(mySet.begin(), mySet.end(), 12883) != mySet.end())
      cout << "Found\n";
   else cout << "Not found\n";
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;

   cout << "SEARCH IN UNORDERED SET: \n";
   start = chrono::high_resolution_clock::now();
   if (find(myUnorderedSet.begin(), myUnorderedSet.end(), 12883) != myUnorderedSet.end())
      cout << "Found\n";
   else cout << "Not found\n";
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";
   cout << endl << endl;

   return 0;
}


void list_push_front(list<int> myList) {
   double total = 0;
   double avg;
   cout << "Insert an element at the front: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myList.push_front(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms; " << endl << endl;
}

void list_push_back(list<int> myList) {
   double total = 0;
   double avg;
   cout << "Insert an element at the back: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myList.push_front(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms; " << endl << endl;
}

void list_delete_front(list<int> myList) {
   double total = 0;
   double avg;
   cout << "Delete an element at the front: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myList.pop_front();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms; " << endl << endl;
}

void list_delete_back(list<int> myList) {
   double total = 0;
   double avg;
   cout << "Delete an element at the back: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myList.pop_back();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms; " << endl << endl;
}

void stack_push(stack<int> myStack) {
   double total = 0;
   double avg;
   cout << "Push an element to the stack: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myStack.push(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms; " << endl << endl;
}

void stack_pop(stack<int> myStack) {
   double total = 0;
   double avg;
   cout << "Pop an element off the stack: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myStack.pop();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void queue_push(queue<int> myQueue) {
   double total = 0;
   double avg;
   cout << "Push an element to the back of the queue: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myQueue.push(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void queue_pop(queue<int> myQueue) {
   double total = 0;
   double avg;
   cout << "Pop an element from the front of the queue: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myQueue.pop();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void deque_push_front(deque<int> myDeque) {
   double total = 0;
   double avg;
   cout << "Push an element to the front of the deque: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myDeque.push_front(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void deque_push_back(deque<int> myDeque) {
   double total = 0;
   double avg;
   cout << "Push an element to the back of the deque: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myDeque.push_back(rand());
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void deque_pop_front(deque<int> myDeque) {
   double total = 0;
   double avg;
   cout << "Pop an element from the front of the deque: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myDeque.pop_front();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void deque_pop_back(deque<int> myDeque) {
   double total = 0;
   double avg;
   cout << "Pop an element from the back of the deque: " << endl;
   for (int i = 0; i < 5; i++) {
      auto start = chrono::high_resolution_clock::now();
      myDeque.pop_back();
      auto finish = chrono::high_resolution_clock::now();
      chrono::duration<double> elapsed = finish - start;
      cout << fixed << elapsed.count() * 1000 << " ms; ";
      total += elapsed.count();
   }
   cout << fixed << "\nTotal: " << total * 1000 << " ms" << endl;
   avg = total / 5;
   cout << fixed << "Average: " << avg * 1000 << " ms" << endl << endl;
}

void heapify(vector<int>& myVector, int i, int size) {
   int largest = i;
   int left = (2 * i) + 1;
   int right = left + 1;

   if (left < size && myVector[left] > myVector[i]) {
      largest = left;
   }
   else {
      largest = i;
   }

   if (right < size && myVector[right] > myVector[largest])
      largest = right;

   if (largest != i) {
      swap(myVector[i], myVector[largest]);
      heapify(myVector, largest, size);
   }


}

void build_max_heap(std::vector<int> &myVector)
{
   for (int i = (myVector.size() / 2); i >= 0; i--)
      heapify(myVector, i, myVector.size());
}

void heap_sort(vector<int> &myVector) {
   build_max_heap(myVector);
   int size = myVector.size();
   int tmpSize = size;
   for (int i = size - 1; i > 0; i--) {
      swap(myVector[0], myVector[i]);
      tmpSize--;
      heapify(myVector, 0, tmpSize);
   }
}

void merge(vector<int> &myVector, int low, int mid, int high) {
   vector<int> temp;
   int i, j;
   i = low;
   j = mid + 1;

   while (i <= mid && j <= high) {
      if (myVector[i] <= myVector[j]) {
         temp.push_back(myVector[i]);
         ++i;
      }
      else {
         temp.push_back(myVector[j]);
         ++j;
      }
   }
   while (i <= mid) {
      temp.push_back(myVector[i]);
      ++i;
   }
   while (j <= high) {
      temp.push_back(myVector[j]);
      ++j;
   }
   for (int i = low; i <= high; ++i) {
      myVector[i] = temp[i - low];
   }


}

void merge_sort(vector<int> &myVector, int low, int high) {
   if (low < high) {
      int mid = (low + high) / 2;
      merge_sort(myVector, low, mid);
      merge_sort(myVector, mid + 1, high);
      merge(myVector, low, mid, high);
   }
}
void quick_sort(vector<int> &myVector, int low, int high) {
   if (low < high) {
      int index = partition(myVector, low, high);

      quick_sort(myVector, low, index - 1);
      quick_sort(myVector, index + 1, high);
   }
}

int partition(vector<int> &myVector, int low, int high) {
   int pivot = myVector[high];
   int i = (low - 1);
   for (int j = low; j < high; j++) {
      if (myVector[j] <= pivot) {
         i++;
         swap(&myVector[i], &myVector[j]);
      }

   }
   swap(&myVector[i + 1], &myVector[high]);
   return (i + 1);
}

void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}