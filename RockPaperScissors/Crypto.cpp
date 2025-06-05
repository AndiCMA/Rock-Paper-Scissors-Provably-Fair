#include "Crypto.h"
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <sstream>
#include <iomanip>

std::string Crypto::hmac_sha256(const std::string& key, const std::string& message) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int len = 0;

    HMAC(EVP_sha256(),
        key.c_str(), static_cast<int>(key.size()),
        reinterpret_cast<const unsigned char*>(message.c_str()), message.size(),
        hash, &len);

    std::ostringstream oss;
    for (unsigned int i = 0; i < len; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);

    return oss.str();
}

std::string Crypto::randomHex(size_t length) {
    unsigned char* buffer = new unsigned char[length];
    RAND_bytes(buffer, static_cast<int>(length));

    std::ostringstream oss;
    for (size_t i = 0; i < length; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer[i]);

    delete[] buffer;
    return oss.str();
}
