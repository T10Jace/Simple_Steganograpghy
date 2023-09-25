#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "Steganography.h";

int main()
{
    cout << "Welcome to the Secret Message Reader program!" << endl;
    Steganography a;

    string filename;

    cout << "Enter a file name " << endl;
    cin >> filename;

    a.printCipherText(filename);

    return 0;
}