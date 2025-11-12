#include <iostream>
using namespace std;

// Structure to represent a customer
struct Customer{
    string name;      // Customer's name
    int numberOrder;          // Customer's numberOrder
    Customer* next;   // Pointer to the next customer in the queue
};

// Queue implemented using a linked list
class Queue {
private:
    Customer* front;  // Pointer to the front (first) element of the queue
    Customer* rear;   // Pointer to the rear (last) element of the queue

public:
    // Constructor initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Add a new customer to the rear of the queue
    void enqueue(string name, int numberOrder){
        Customer* newCustomer = new Customer;  // Allocate memory for new customer
        newCustomer->name = name;
        newCustomer->numberOrder = numberOrder;
        newCustomer->next = nullptr;

        // If the queue is empty, front and rear both point to the new customer
        if(rear == nullptr){
            front = rear = newCustomer;
            cout << name << " (" << numberOrder << ") enqueued to queue" << endl;
            return;
        }

        // Otherwise, link the new customer at the end and update rear
        rear->next = newCustomer;
        rear = newCustomer;

        cout << name << " (" << numberOrder << ") enqueued to queue" << endl;
    }

    // Remove and return the customer at the front of the queue
    Customer dequeue(){
        if(front == nullptr){  // Queue is empty
            cout << "Queue Underflow" << endl;
            return Customer(); // Return a default customer
        }

        Customer* temp = front;    // Store the node to be deleted
        front = front->next;       // Move front to the next element

        // If queue becomes empty after dequeue, update rear as well
        if(front == nullptr){
            rear = nullptr;
        }

        Customer data = *temp;     // Copy customer data
        delete temp;               // Free memory of dequeued node
        return data;               // Return the dequeued customer
    }

    // Return (peek) the customer at the front without removing
    Customer peek(){
        if(front == nullptr){      // Queue is empty
            cout << "Queue is empty" << endl;
            return Customer();     // Return default customer
        }
        return *front;             // Return copy of front customer
    }

    // Check if the queue is empty
    bool isEmpty(){
        return front == nullptr;   // True if no elements
    }

    // Check if the queue is full
    bool isFull(){
        return false;              // Linked list queue can grow dynamically
    }
};