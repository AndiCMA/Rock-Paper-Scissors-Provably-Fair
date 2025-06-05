#pragma once
#include <string>

class SeedManager {
private:
	std::string* serverSeed;
	std::string* clientSeed;

	static SeedManager* instance;
	SeedManager();
public:
	~SeedManager();
	static SeedManager* getInstance();

	void initServerSeed();
	void setClientSeed( const std::string& clientSeed );

	const std::string* getServerSeed() const;
	const std::string* getClientSeed() const;
};
