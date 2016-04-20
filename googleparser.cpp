#include "googleparser.h"

GoogleParser::GoogleParser()
{
	this->lastSearchWord = "";
	this->data.clear();
}
GoogleParser::~GoogleParser()
{

}
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
bool GoogleParser::doSearch(std::string searchWord)
{
	bool isSpam = true;
	int index = 0, count = 0;
	std::string startURL = "http://google.com/trends/fetchComponent?q=";
	std::string endURL = "&cid=TIMESERIES_GRAPH_0&export=3";
	
	std::string readbuffer;

	std::string completeUrl = startURL + searchWord + endURL;

	if(this->lastSearchWord != searchWord)
	{
		isSpam = false;	
		CURL *curl;
        CURLcode res;
		curl = curl_easy_init();
		if(curl)
		{
			curl_easy_setopt(curl,CURLOPT_URL,completeUrl.c_str());
			curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,true);
			curl_easy_setopt(curl,CURLOPT_WRITEDATA, &readbuffer);
            res = curl_easy_perform(curl);
			curl_easy_cleanup(curl); 
		}
		if(readbuffer.find("quota") == std::string::npos)
		{
			bool counting = true;
			while(counting)
			{
				index = readbuffer.find("\"v\":",index+1);
                if(index == std::string::npos)
					counting = false;
				if(counting)
				{
					index = readbuffer.find("\"v\":",index+1);
					count++;
				}
				if(index == std::string::npos)
					counting = false;
			}	
			int inputInt = 0;
            this->data.clear();
			for(int i = 0; i < count; i++)
			{
				index = readbuffer.find("\"v\":",index+1);
				index = readbuffer.find("\"v\":",index+1);
				/*cout << readbuffer[index+4];
				cout << readbuffer[index+5];
				cout << endl;*/
				inputInt = (readbuffer[index+4]-0x30)*10;
				inputInt += readbuffer[index+5]-0x30;
				this->data.push_back(inputInt);	
			}
		}
		else
			isSpam = true;
	}
	this->lastSearchWord = searchWord;
	return isSpam;
}
void GoogleParser::saveToFile(std::string targetFilePath) const
{
	std::ofstream out;
	out.open(targetFilePath.c_str());
    out << this->lastSearchWord << std::endl;
	out << this->data.size();
	out << std::endl;
    for(unsigned int i = 0; i < this->data.size(); i++)
	{
		out << data[i];
		out << std::endl;
	}
	out.close();
}
