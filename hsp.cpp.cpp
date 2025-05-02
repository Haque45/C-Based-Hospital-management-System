#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor {
private:
    string name;
    string specialty;
public:
    Doctor(string _name, string _specialty) : name(_name), specialty(_specialty) {}

    string getName() const {
        return name;
    }

    string getSpecialty() const {
        return specialty;
    }
};

class Patient {
private:
    string name;
    int age;
    string gender;
public:
    Patient(string _name, int _age, string _gender) : name(_name), age(_age), gender(_gender) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getGender() const {
        return gender;
    }

    void setName(const string& _name) {
        name = _name;
    }

    void setAge(int _age) {
        age = _age;
    }

    void setGender(const string& _gender) {
        gender = _gender;
    }
};

class Hospital {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;
public:
    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void displayDoctors() const {
        cout << "Doctors in the hospital:" << endl;
        for (const auto& doctor : doctors) {
            cout << "Name: " << doctor.getName() << ", Specialty: " << doctor.getSpecialty() << endl;
        }
        cout << endl;
    }

    void displayPatients() const {
        cout << "Patients in the hospital:" << endl;
        for (const auto& patient : patients) {
            cout << "Name: " << patient.getName() << ", Age: " << patient.getAge() << ", Gender: " << patient.getGender() << endl;
        }
        cout << endl;
    }

    void updatePatientInfo(const string& patientName, int age, const string& gender) {
        for (auto& patient : patients) {
            if (patient.getName() == patientName) {
                patient.setAge(age);
                patient.setGender(gender);
                cout << "Patient information updated successfully." << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }
};

int main() {
    Hospital hospital;

    // Adding doctors
    Doctor doctor1("Dr. Smith", "Cardiologist");
    Doctor doctor2("Dr. Johnson", "Pediatrician");
    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);

    // Adding patients
    Patient patient1("Alice", 25, "Female");
    Patient patient2("Bob", 40, "Male");
    hospital.addPatient(patient1);
    hospital.addPatient(patient2);

    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Display doctors" << endl;
    cout << "2. Display patients" << endl;
    cout << "3. Update patient information" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            hospital.displayDoctors();
            break;
        case 2:
            hospital.displayPatients();
            break;
        case 3:
            {
                string name;
                int age;
                string gender;
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter patient's age: ";
                cin >> age;
                cout << "Enter patient's gender: ";
                cin >> gender;
                hospital.updatePatientInfo(name, age, gender);
                hospital.displayPatients();
                break;
            }
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}

