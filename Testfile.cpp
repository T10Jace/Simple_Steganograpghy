#include <iostream>
using namespace std;
#include <fstream>
#include <string>

int main()
{
    string flnm;
    ifstream file;
    string junk;

    cout << "Welcome to the mock-up PPM Reader" << endl;
    cout << "Please enter the name of the file you wish to read" << endl;
    cin >> flnm;
    cout << endl << endl;

    file.open(flnm.c_str());
    getline(file, junk);
    getline(file, junk);
    getline(file, junk);

    int i = 0;
    int tempvar;
    int iteration = 0;
    string holdbits;
    char alpha;
 
    while(!file.eof())
    {
        file >> tempvar;

        if(iteration % 9 != 8)
        {
            holdbits += to_string(tempvar % 2);
        }
        else
        {
            alpha = stoi(holdbits, nullptr, 2);
            cout << alpha << endl;
            iteration = -1;
            holdbits.clear();
        }
        i++;
        iteration++;
    }
    file.close();
}