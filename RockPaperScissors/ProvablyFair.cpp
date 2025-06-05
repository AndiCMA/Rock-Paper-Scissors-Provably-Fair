#include <string>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include "Crypto.h"
#include "ProvablyFair.h"
#include "SeedManager.h"


int ProvablyFair::generate(const int* nonce) {
    SeedManager* manager = SeedManager::getInstance();
    const std::string* clientSeed = manager->getClientSeed();
    const std::string* serverSeed = manager->getServerSeed();

    if (!clientSeed || !serverSeed || !nonce) return -1;

    std::string message = *clientSeed + "-" + std::to_string(*nonce);
    std::string hash = Crypto::hmac_sha256(*serverSeed, message);
    std::string hexPart = hash.substr(0, 8);

    unsigned int result = std::stoul(hexPart, nullptr, 16);
    return result % 3;
}
