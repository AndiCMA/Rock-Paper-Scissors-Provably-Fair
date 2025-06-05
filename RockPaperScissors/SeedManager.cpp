#include "SeedManager.h"

SeedManager* SeedManager::instance = nullptr;

SeedManager::SeedManager() {
	serverSeed = new std::string();
	clientSeed = new std::string();
}

SeedManager::~SeedManager() {
	delete serverSeed;
	delete clientSeed;
}

SeedManager* SeedManager::getInstance() {
	if (instance == nullptr) {
		instance = new SeedManager();
	}
	return instance;
}

void SeedManager::initServerSeed() {
	*serverSeed = "ABCDEGabcedf123ABCDEGabced";
}

void SeedManager::setClientSeed(const std::string& seed) {
	clientSeed = new std::string(seed);
}

const std::string* SeedManager::getServerSeed() const {
	return serverSeed;
}

const std::string* SeedManager::getClientSeed() const {
	return clientSeed;
}
