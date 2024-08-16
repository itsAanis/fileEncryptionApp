#pragma once
#include <string>
#include "IAlgorithm.h" 


namespace Crypto {

	class CaesarCipher : public IAlgorithm {
	private:
		int key;

	public:
		CaesarCipher(int k) : key(k) {}

		std::string encrypt(const std::string& data) override{
		
			std::string encrypted;
			for (char ch : data) {
				if (std::isalpha(ch)) {  
					char base = std::isupper(ch) ? 'A' : 'a';
					ch = (ch - base + key) % 26 + base;  
				}
				encrypted += ch;
			}
			return encrypted;
		
		
		}

		std::string decrypt(const std::string& data) override {
		
			std::string decrypted;
			for (char ch : data) {
				if (std::isalpha(ch)) {  
					char base = std::isupper(ch) ? 'A' : 'a';
					ch = (ch - base - key + 26) % 26 + base;  
				}
				decrypted += ch;
			}
			return decrypted;
		
		}


	};



}