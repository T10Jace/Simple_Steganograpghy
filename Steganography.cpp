#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

Steganography::Steganography() {
    // Initialize member variables to default values
    magicNumber = "P3"; // Default magic number for P3 format
    width = 0;
    height = 0;
    maxColor = 255; // Default maximum color depth
    colorData.clear(); // Initialize colorData as an empty vector
    cipherText = ""; // Initialize cipherText as an empty string
}

int Steganography::getNthBit(char cipherChar, int n) {
  int parr[8] = {128, 64, 32, 16, 8, 4, 2, 1};

  int holdint = cipherChar
  int j = 0;
  string boolstring;
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
  return boolstring[n] - 48;
}


void Steganography::readImage(string fileName){

    // Open the file for reading
    std::ifstream inputFile(fileName);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open the image file." << std::endl;
        exit(1);
    }

    // Read the PPM header information
    inputFile >> magicNumber;
    inputFile >> width;
    inputFile >> height;
    inputFile >> maxColor;

    // Resize the colorData vector to accommodate the image data
    colorData.resize(width * height * 3); // Assuming 3 color values per pixel (RGB)

    // Read the image data into the colorData vector
    for (int i = 0; i < width * height * 3; ++i) {
        inputFile >> colorData[i]; // using the shift operator again to shift bits to the right
    }

    // Close the file
    inputFile.close();
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
  string buffer;
  string formatcomp = magicNumber + "\n";
  int holdint;
  int counter;

  ifstream file;                
  file.open(fileName.c_str()); // Opens file requested by user

  getline(file, buffer)     
  if (buffer != formatcomp)
  {
    cout << "Error! Are you using the right file type?" << endl;
    return 1;
  }
  //Note: The following code assumes there are no #Notes in the PPM File. This code
  //      may need to be updated should there be those #Notes
  while(!eof)

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
      cout << alpha;
      iteration = -1;                     //Resets the Bit-string & loop
      holdbits.clear();
    }

    i++;
    iteration++;

  }
  
  file.close();
}

void Steganography::printCipherText(const std::string& fileName) {
    // Open the file for writing
    std::ofstream outputFile(fileName);

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return;
    }

    // Write the cipherText to the file
    outputFile << cipherText;

    // Close the file
    outputFile.close();
}


void Steganography::cleanImage()
{
for (int i = 0; i < colorData.size(); ++i) {
        // Mask the least significant bit by performing a bitwise AND operation with 254 (11111110 in binary)
        colorData[i] = colorData[i] & 254;
    }
}

void Steganography::encipher() {
    // Ensure that the cipherText can be fully embedded in the image
    if (cipherText.size() * 8 > colorData.size()) {
        std::cout << "Error: Not enough space in the image to encipher the text." << std::endl;
        exit(1);
    }

    // Iterate over each character in the cipherText
    for (size_t i = 0; i < cipherText.size(); ++i) {
        char currentChar = cipherText[i];
        
        // Iterate over each bit in the current character
        for (int j = 0; j < 8; ++j) {
            // Get the current bit from the character
            int currentBit = getNthBit(currentChar, j);
            
            // Modify the least significant bit of the current color value
            int& colorValue = colorData[i * 8 + j];
            if (currentBit == 0) {
                // Set the least significant bit to 0
                colorValue &= 254; // 254 is 11111110 in binary
            } else {
                // Set the least significant bit to 1
                colorValue |= 1; // I found this "|" biwise OR character online which is awesome to know
            }
        }
    }
}


void Steganography::decipher() {
    // Calculate the number of characters that can be retrieved
    size_t numCharacters = colorData.size() / 8;
    
    // Resize the cipherText string to accommodate the retrieved characters
    cipherText.resize(numCharacters);
    
    // Iterate over each character
    for (size_t i = 0; i < numCharacters; ++i) {
        char currentChar = 0; // Initialize the current character
        
        // Iterate over each bit in the character
        for (int j = 0; j < 8; ++j) {
            // Extract the least significant bit from the current color value
            int currentBit = colorData[i * 8 + j] & 1; // Get the rightmost bit
            
            // Shift and combine the current bit into the current character
            currentChar |= (currentBit << j); // I also found that using "<<" can be used to shift the bits!!
        }
        
        // Store the extracted character in the cipherText
        cipherText[i] = currentChar;
    }
}
