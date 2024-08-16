// crypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "file.h"
#include "CaesarCipher.h"
#include "CryptoProcessor.h"

int main()
{

	File fh;
	Crypto::CaesarCipher cipher(2);

	CryptoProcessor proc(cipher);

	std::string inputFilePath;
	int choice;

	std::cout << "1. Encrypt File\n";
	std::cout << "2. Decrypt File\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	std::cout << "Enter input file path: ";
	std::cin >> inputFilePath;
	
	if (choice == 1)
	{
		std::string data{ fh.readFile(inputFilePath) };
		if (data.empty()) {
			std::cerr << "Failed to read from file or file is empty.\n";
			return 1;  
		}
		std::string encrypted{ proc.encryptData(data) };
		fh.writeFile(inputFilePath,encrypted);
		std::cout << "File encrypted successfully.\n";
	}

	else if (choice ==2)
	{
		std::string data{ fh.readFile(inputFilePath) };
		if (data.empty()) {
			std::cerr << "Failed to read from file or file is empty.\n";
			return 1;  
		}

		std::string decrypted{ proc.decryptData(data)};
		fh.writeFile(inputFilePath, decrypted);
		std::cout << "File decrypted successfully.\n";
	}
	else {
		std::cerr << "Invalid choice entered.\n";
		return 1;  
	}

	return 0;
}



