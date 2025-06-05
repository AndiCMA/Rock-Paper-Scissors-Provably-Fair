#pragma once
#include <string>

class Crypto {
public:
    static std::string hmac_sha256(const std::string& key, const std::string& message);
    static std::string randomHex(size_t length);
};
