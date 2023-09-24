#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>


void Steganography::readImage(string fileName)
{
  
}

void Steganography::printImage(string fileName)
{
  int i = 0;
  int j = 0;
  while (i < height)
  {
    while (j < width)
	  { 
	    //Cout << Image_Pixel;
	    j++;
	  }
    //Cout << endl;
    i++;
  }
}

void Steganography::readCipherText(string filename)
{

}

void Steganography::printCipherText(string fileName)
{
  //Initializer Vocabulary
  ifstream file;
  string junk;

  cout << endl << endl;
  file.open(fileName.c_str());

  getline(file, junk);  
  getline(file, junk);
  getline(file, junk);

  //Read-In Vocabulary
  int i = 0;
  int tempvar;
  int iteration = 0;
  string holdbits;
  char alpha;

  //Read-in Loop
  while(!file.eof())
  {
    file >> tempvar;
    if(iteration % 9 != 8)
    {
      holdbits += to_string(tempvar % 2); //Adds bits to a string
    }
    else
    {
      alpha = stoi(holdbits, nullptr, 2); //Converts the Bit-string to a Char and couts it.
      cout << holdbits << " " << alpha << endl;
      iteration = -1;                     //Resets the Bit-string & loop
      holdbits.clear();
    }
    i++;
    iteration++;
  }
  file.close();
}

void Steganography::cleanImage()
{

}

void Steganography::encipher()
{

}

void Steganography::decipher()
{

}
