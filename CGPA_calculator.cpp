/*The user’s input is used to compute the CGPA, which includes information like the number of courses taken and the grades earned in each one. 
The program also shows each student’s overall course grade. CGPA Calculator calculates a student’s Cumulative Grade Point Average (CGPA) from the
 given exam results. The program can show the individual grades of each course, calculate total credits and total grade points achieved, determine 
 the GPA for the semester, and based on all the data, it can generate and present the CGPA of the student.
 Features:
Takes the number of courses as input.
Accepts course grades and credit values.
Calculates the Semester GPA and Cumulative GPA (CGPA).
Displays individual course grades and total credit information.*/
#include <iostream>
#include <vector>
using namespace std;

float SGPA() {
    int n;
    cout << "\n-------------------------------------------\n";
    cout << "Enter the number of courses: ";
    cin >> n;
    
    vector<string> sub(n);
    vector<char> g(n);
    vector<float> c(n), cp(n);

    for (int i = 0; i < n; i++) {
        cout << "➡ Enter Subject Name, Grade (O/E/A/B/C/D/F), and Credit: ";
        cin >> sub[i] >> g[i] >> c[i];
    }

    for (int i = 0; i < n; i++) {
        if (g[i] == 'O') cp[i] = c[i] * 10;
        else if (g[i] == 'E') cp[i] = c[i] * 9;
        else if (g[i] == 'A') cp[i] = c[i] * 8;
        else if (g[i] == 'B') cp[i] = c[i] * 7;
        else if (g[i] == 'C') cp[i] = c[i] * 6;
        else if (g[i] == 'D') cp[i] = c[i] * 5;
        else cp[i] = c[i] * 2;
    }

    float sumc = 0, sumcp = 0;
    for (int i = 0; i < n; i++) {
        sumc += c[i];   
        sumcp += cp[i]; 
    }

    float sgpa = sumcp / sumc;
    cout << "SGPA: " << sgpa << "\n";
    return sgpa;
}

int main() {
    cout << "==========================================\n";
    cout << " WELCOME TO THE CGPA CALCULATOR\n";
    cout << "==========================================\n";

    cout << "\n1st Semester Details:";
    float sem1 = SGPA();

    cout << "\n2nd Semester Details:";
    float sem2 = SGPA();

    float cgpa = (sem1 + sem2) / 2.0;
    cout << "\n==========================================\n";
    cout << "Your final CGPA for the year: " << cgpa << "\n";
    cout << "==========================================\n";

    return 0;
}
