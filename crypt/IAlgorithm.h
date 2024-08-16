#pragma once
#include <string>

namespace Crypto {
    class IAlgorithm
    {

    public:
        virtual std::string encrypt(const std::string& data) = 0;
        virtual std::string decrypt(const std::string& data) = 0;
        virtual ~IAlgorithm() = default;

    };






}