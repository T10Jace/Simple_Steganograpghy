/**

 * Authors: Jace Riley and Jesse Doescher
 * Date: 09/20/2023
 * File: Steganography.h
 * Description: This file holds all of the private and public members to be used in the .cpp files.

**/

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>


class Steganography {

 private:
  
  string magicNumber; // P3 Value
  
  int width; // image width
  
  int height; // image height
  
  int maxColor; // Maximum color depth of the image
  
  vector<int> colorData; // 
  
  string cipherText; // Hidden data to encode/decode
  
  int getNthBit(char cipherChar, int n); // returns the nth bit from the character that is being encoded.


  
 public:

  void readImage(string fileName); // - Reads in the PPM image with the provided fileName, storing it in the member variables
      
  void printImage(string fileName); // - Writes the PPM image stored in member data to the provided fileName
      
  void readCipherText(string fileName);// - reads the plain text file (ciphertext) with the name fileName and stores it in the member data
      
  void printCipherText(string fileName); // - writes the plain text (ciphertext) to the file fileName
      
  void cleanImage()  // - Zeros out the least significant bigt of each color value in colorData
      
  void encipher()  // - stores the text from cipherText in the image colorData
      
  void decipher()  // - reads the ciphertext back from colorData and stores it in cipherText
      
};
#endif //STEGANOGRAPHY_H
