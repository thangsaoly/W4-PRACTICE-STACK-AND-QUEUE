#include "queue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    // Simple bank teller line simulation using the provided Queue class
    Queue q;

    cout << "Bank teller simulation\n";

    // Enqueue some customers
    q.enqueue("Saoly", 1);
    q.enqueue("Ey", 2);
    q.enqueue("Bolen", 3);
    q.enqueue("Chet", 4);

    cout << "\nServing customers:\n";

    // Serve customers until the queue is empty
    while(!q.isEmpty()){
        Customer next = q.peek();
        cout << "Next in line: " << next.name << " (" << next.numberOrder << ")\n";

        Customer served = q.dequeue();
        cout << "Serving: " << served.name << " (" << served.numberOrder << ")\n\n";
    }

    cout << "All customers served.\n";

    return 0;
}
    