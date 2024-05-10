#include <iostream>
using namespace std;

struct patient {
    string name;
    int priority;
};

class PriorityQueue {
private:
    patient arr[100];
    int rear;

public:
    PriorityQueue() {
        rear = -1;
    }
    bool isEmpty() {
        return (rear == -1);
    }
    bool isFull() {
        return (rear == 99);
    }

    void enqueue(patient p) {
        if (isFull()) {
            cout << "Priority Queue is Full\n";
            return;
        }
        int i;
        for (i = rear; i >= 0; i--) {
            if (arr[i].priority > p.priority || (arr[i].priority == p.priority && i == 0)) {
                break;
            }
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = p;
        rear++;
    }

    patient dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty\n";
            return {"", -1};
        }
        patient fpatient = arr[rear];
        rear--;
        return fpatient;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1) Enter Patients\n";
        cout << "2) Display Patients\n";
        cout << "3) Release Patients\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of patients: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    patient p;
                    cout << "Enter patient " << i + 1 << " name: ";
                    cin >> p.name;
                    cout << "Enter priority (1 for Serious, 2 for Non-serious, 3 for General Check-Up): ";
                    cin >> p.priority;
                    pq.enqueue(p);
                }
                break;
            }
            case 2: {
                cout << "\nPatient list: ";
                patient patients[100];
                int index = 0;
                PriorityQueue temp = pq;
                while (!temp.isEmpty()) {
                    patients[index++] = temp.dequeue();
                }
                for (int i = 0; i < index; i++) {
                    patient p = patients[i];
                    cout << "\nName : " << p.name << "\tStatus: ";
                    if (p.priority == 1)
                        cout << "Serious";
                    else if (p.priority == 2)
                        cout << "Non-Serious";
                    else if (p.priority == 3)
                        cout << "Check-Up";
                }
                break;
            }
            case 3: {
                while (!pq.isEmpty()) {
                    patient p = pq.dequeue();
                    cout << "\nReleased Patient: " << p.name;
                    break;
                }
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
