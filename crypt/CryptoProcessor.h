#pragma once


#include "IAlgorithm.h"



class CryptoProcessor
{
private:
	Crypto::IAlgorithm& algorithm;

public:
	CryptoProcessor(Crypto::IAlgorithm& algo) : algorithm(algo) {}

	std::string encryptData(const std::string& data) {
		return algorithm.encrypt(data);
	}

	std::string decryptData(const std::string& data) {
		return algorithm.decrypt(data);
	}
};

