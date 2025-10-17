#include <iostream>
#include <string>
using namespace std;

int main() {
    string name[5], guardian[5], disease[5];
    int age[5], room[5];
    int patientCount = 0;
    int choice;

    do 
     {
        cout << "\nHOSPITAL MANAGEMENT SYSTEM";
        cout << "\n1. Add New Patient";
        cout << "\n2. Show Patient Details by Number";
        cout << "\n3. Show All Patients";
        cout << "\n4. View Room by Patient Name";
        cout << "\n5. Show Total Bill";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (patientCount >= 5)
                cout << "\nAll rooms are full.\n";
            else {
                cout << "\nPatient Name: ";
                cin >> name[patientCount];
                cout << "Guardian Name: ";
                cin >> guardian[patientCount];
                cout << "Age: ";
                cin >> age[patientCount];
                cout << "Disease: ";
                cin >> disease[patientCount];

                room[patientCount] = patientCount + 1;
                cout << "Assigned Room No: " << room[patientCount] << endl;

                patientCount++;
            }
        }
        else if (choice == 2) {
            if (patientCount == 0)
                cout << "\nNo patients yet.\n";
            else {
                int pid;
                cout << "\nEnter Patient Number: ";
                cin >> pid;

                if (pid < 1 || pid > patientCount)
                    cout << "\nInvalid Number!\n";
                else {
                    cout << "\nPatient " << pid << " Details:\n";
                    cout << "Name: " << name[pid-1] << endl;
                    cout << "Guardian: " << guardian[pid-1] << endl;
                    cout << "Age: " << age[pid-1] << endl;
                    cout << "Disease: " << disease[pid-1] << endl;
                    cout << "Room No: " << room[pid-1] << endl;
                }
            }
        }
        else if (choice == 3) {
            if (patientCount == 0)
                cout << "\nNo patients yet.\n";
            else {
                for (int i = 0; i < patientCount; i++) {
                    cout << "\nPatient " << i+1 << ":\n";
                    cout << "Name: " << name[i] << endl;
                    cout << "Guardian: " << guardian[i] << endl;
                    cout << "Age: " << age[i] << endl;
                    cout << "Disease: " << disease[i] << endl;
                    cout << "Room No: " << room[i] << endl;
                }
            }
        }
        else if (choice == 4) {
            if (patientCount == 0)
                cout << "\nNo patients yet.\n";
            else {
                string search;
                cout << "\nEnter Patient Name: ";
                cin >> search;

                bool found = false;
                for (int i = 0; i < patientCount; i++) {
                    if (name[i] == search) {
                        cout << "Room No: " << room[i] << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Patient not found.\n";
            }
        }
        else if (choice == 5) {
            if (patientCount == 0)
                cout << "\nNo patients yet.\n";
            else {
                int pid, days;
                cout << "\nEnter Patient Number: ";
                cin >> pid;

                if (pid < 1 || pid > patientCount)
                    cout << "\nInvalid Number!\n";
                else {
                    cout << "Days stayed: ";
                    cin >> days;

                    int roomCharge = days * 5000;
                    int doctorCharge = 1500;
                    int total = roomCharge + doctorCharge;

                    cout << "\nName: " << name[pid-1] << endl;
                    cout << "Disease: " << disease[pid-1] << endl;
                    cout << "Room Charge: " << roomCharge << endl;
                    cout << "Doctor Charge: " << doctorCharge << endl;
                    cout << "Total Bill: " << total << endl;
                }
            }
        }
        else if (choice == 6)
            cout << "\nExiting...\n";
        else
            cout << "\nInvalid choice!\n";

    } while (choice != 6);

    return 0;
}
