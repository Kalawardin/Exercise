#include <iostream>

using namespace std;
int main() {

    float basic;
    float netsalary;
    float percentAllow;
    float percentDeduct;

    cout << "Enter Basic Salary: ";
    cin >> basic;

    cout << "Enter percentage of Allowances: ";
    cin >> percentAllow;

    cout << "Enter percentage of Deductions: ";
    cin >> percentDeduct;

    netsalary=basic+basic*percentAllow/100-basic*percentDeduct/100;
    cout << "Net Salary is:" << netsalary << endl;

    return 0;

}