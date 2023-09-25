#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include "Steganography.h"


int main()
{
    cout << "Welcome to the Secret Message Reader program!" << endl;
    
    Steganography a;

    string filename;

    cout << "Enter a file name " << endl;
    cin  >> filename;

    a.readImage(filename);
    a.readCipherText(filename);
    a.printCipherText(filename);
    //a.printImage(filename);
    a.encipher();
    a.decipher();
    a.printImage(filename);
    a.cleanImage();

    return 0;
}