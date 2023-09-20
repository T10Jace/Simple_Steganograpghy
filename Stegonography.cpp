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

void Steganography::readCipherText(string fileName)
{
  string buffer;                //Vocabulary 
  string formatcomp = magicNumber + "\n";
  int holdint;
  int counter;

  ifstream file;                //File activator
  file.open(fileName.c_str());

  getline(file, buffer)         //Checking & Skipping the format
  if (buffer != formatcomp)
  {
    cout << "Error! Are you using the right file type?" << endl;
    return 1;
  }
  //Note: The following code assumes there are no #Notes in the PPM File. This code
  //      may need to be updated should there be those #Notes
  while(!eof)
  {
    cin >> buffer;
    if (buffer != "\n")
    {
      holdint = stoi(buffer);
      if (holdint % 2 == 1)
        cout << "X"
      else
        cout << " "
    }
    counter++;
    if (counter % width == 0)
      cout << endl;
  }
  cout << endl;
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
