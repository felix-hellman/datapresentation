#ifndef GOOGLEPARSER_H
#define GOOGLEPARSER_H

#include <string>
#include <vector>
#include <curl/curl.h>
#include <fstream>

class GoogleParser
{
		
	private:
	std::vector<double> data;
	std::string lastSearchWord;
	
	public:
	GoogleParser();
	~GoogleParser();
	bool doSearch(std::string searchWord);
    void saveToFile(std::string targetFilePath) const;
};
#endif
