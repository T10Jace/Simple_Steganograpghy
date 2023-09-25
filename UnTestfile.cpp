#include <iostream>
using namespace std;
#include <fstream>
#include <string>


int main()
{
  string inflnm;
  ofstream outfile;
  string message;
  string junk;
  string notes;
  int holdnum;
  int row;
  int col;

  //This bit is the setup bit (Getting stuff like the message, file name, and dimensions_)

  cout << "Welcome to the secret message creator!" << endl
       << "Firstly, please enter the name of the file you would like to hide it in:" << endl;
  cin >> inflnm;
  cout << endl << endl;

  cout << "Very cool. Next, please enter the message you would like to encode: " << endl;
  getline(cin,junk);
  getline(cin,message);
  cout << endl;

  cout << "Your message was: " << message << endl;
  
  holdnum = message.length();

  cout << "Your message is " << holdnum << " characters long, and thus, its color array will"
       << " need to be ";
  holdnum *= 3;
  cout << holdnum << " total RGP Pixels" << endl;

  //This is the math to find the dimensions of the pixel array
  int i = 0;
  if (holdnum % 9 == 0)
  {
    col = holdnum/9;
    row = 9;
  }
  else if (holdnum % 6 == 0)
  {
    col = holdnum/6;
    row = 6;
  }
  else 
  {
    col = holdnum/3;
    row = 3;
  }

  cout << "The message must contain " << row << " rows and " << col << " cols" << endl << endl;
  cout << "Is there any notes you want to add to the file?" << endl;
  getline(cin,notes);

  cout << "Confirmed, creating the file." << endl;

  outfile.open(inflnm.c_str());
  outfile << "P3\n";
  outfile << "# " << notes << "\n";
  outfile << row << " " << col << "\n";

  cout << "Initial file creation complete." << endl;

  //This bit converts the message into Binary

  int holdint;
  i = 0;
  int j = 0;
  int mlength = message.length();
  string boolstring;
  int parr[8] = {128, 64, 32, 16, 8, 4, 2, 1};

  while (i < mlength)
  {
    holdint = message[i];
    j = 0;
    while (j < 8)
    {

      if (holdint >= parr[j])
      {
        boolstring += '1';
        holdint -= parr[j];
      }
      else
      {
        boolstring += '0';
      }
      j++;
    }
    i++;
  }

  cout << "Message successfully converted to BOOL." << endl;
  
  //This bit encodes the thing into an RGB Value

  int debugint;
  int desired;
  i = 0;
  j = 0;

  while (i < holdnum * 3)
  {
    if (i % 9 != 8)
    {
      desired = boolstring[j] - 48;
      debugint = rand() % 255;
      if (debugint % 2 != desired)
        debugint -= 1;
      if (debugint == -1)
        debugint = 255;
      outfile << debugint;
      j++;
    }
    else
    {
      debugint = rand() % 255;
      cout << debugint;
      outfile << debugint;
    } 

    if (i % 3 == 2)
    {
      outfile << "\n";
    }
    else
    {
      outfile << " ";
    }  

    i++;
  }

  cout << "File creation successful. Thank you for using the program." << endl;
}

