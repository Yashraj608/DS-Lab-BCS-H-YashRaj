#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrivalTime;
};

class MaxHeap {
    Patient heap[100];
    int size = 0;

    bool higherPriority(const Patient& a, const Patient& b) {
        if (a.severity != b.severity)
            return a.severity > b.severity;
        return a.arrivalTime < b.arrivalTime;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (higherPriority(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else
                break;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && higherPriority(heap[left], heap[largest]))
                largest = left;
            if (right < size && higherPriority(heap[right], heap[largest]))
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else
                break;
        }
    }

public:
    void addPatient(const string& name, int severity, int arrivalTime) {
        if (size >= 100) {
            cout << "Cannot add more patients. Queue is full." << endl;
            return;
        }
        heap[size] = {name, severity, arrivalTime};
        heapifyUp(size);
        size++;
        cout << "Patient " << name << " added with severity " << severity << endl;
    }

    void getNextPatient() {
        if (size == 0) {
            cout << "No patients are waiting at the moment." << endl;
            return;
        }
        cout << "Next patient to treat: " << heap[0].name << " (severity " << heap[0].severity << ")" << endl;
    }

    void treatNextPatient() {
        if (size == 0) {
            cout << "No patients to treat." << endl;
            return;
        }
        cout << "Treating patient: " << heap[0].name << " (severity " << heap[0].severity << ")" << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void updateSeverity(const string& name, int newSeverity) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (heap[i].name == name) {
                heap[i].severity = newSeverity;
                heapifyUp(i);
                heapifyDown(i);
                found = true;
                cout << "Updated severity of " << name << " to " << newSeverity << endl;
                break;
            }
        }
        if (!found)
            cout << "Patient " << name << " not found in the waiting list." << endl;
    }

    void displayAllPatients() {
        if (size == 0) {
            cout << "No patients are waiting at the moment." << endl;
            return;
        }

        Patient temp[100];
        int tempSize = size;
        for (int i = 0; i < size; i++)
            temp[i] = heap[i];

        cout << "Patients waiting in order of priority:" << endl;

        while (tempSize > 0) {
            Patient top = temp[0];
            cout << top.name << " (severity " << top.severity << ", arrival " << top.arrivalTime << ")" << endl;
            temp[0] = temp[tempSize - 1];
            tempSize--;

            int index = 0;
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;

                if (left < tempSize && higherPriority(temp[left], temp[largest]))
                    largest = left;
                if (right < tempSize && higherPriority(temp[right], temp[largest]))
                    largest = right;

                if (largest != index) {
                    swap(temp[index], temp[largest]);
                    index = largest;
                } else
                    break;
            }
        }
    }
};

int main() {
    MaxHeap hospital;
    int arrivalCounter = 0;

    hospital.addPatient("Yash", 8, arrivalCounter++);
    hospital.addPatient("Asad", 6, arrivalCounter++);
    hospital.addPatient("Jiyanshu", 9, arrivalCounter++);
    hospital.addPatient("Vivek", 7, arrivalCounter++);

    hospital.getNextPatient();
    hospital.treatNextPatient();
    hospital.getNextPatient();

    hospital.updateSeverity("Asad", 10);

    hospital.displayAllPatients();

    return 0;
}
