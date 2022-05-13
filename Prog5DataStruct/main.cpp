#include <iostream>
#include <list>
#include <chrono>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
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

void heap_sort(vector<int> myVector);
void merge_sort(vector<int> myVector);
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

   for (int i = 0; i < MAX_NUM; i++) {
      myList.push_back(rand());
      myStack.push(rand());
      myQueue.push(rand());
      myDeque.push_back(rand());
      myVector.push_back(rand());
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

   cout << "QUICK SORT:\n";

   start = chrono::high_resolution_clock::now();
   int size = myVector.size();
   quick_sort(myVector, 0, size - 1);
   finish = chrono::high_resolution_clock::now();
   elapsed = finish - start;
   cout << fixed << elapsed.count() * 1000 << " ms; ";

   //for (int i = 0; i < size; i++) {
   //   cout << myVector[i] << " ";
   //}

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

//void heap_sort(vector<int> myVector) {
//   int leftChild, rightChild, maxIndex;
//   for (int i = myVector.size() / 2 - 1; i >= 0; i--) {
//      leftChild = myVector[2 * 0 + 1];
//      rightChild = myVector[2 * 0 + 2];
//      maxIndex = max_element(myVector[i], leftChild, rightChild);
//      if (i != maxIndex)
//         swap(myVector[i], myVector[maxIndex]);
//   }
//   for (int i = 0; i < myVector.size(); i++) {
//      cout << myVector[i];
//   }
//}

void merge_sort(vector<int> myVector) {

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