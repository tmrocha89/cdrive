#include "WebDriver.h"


WebDriver::WebDriver(const Credential& cr):credential(cr){}

WebDriver::~WebDriver(){}

void WebDriver::listFiles(){
    
    CURL* curl;
    CURLcode resCode;
    struct curl_slist *headers = NULL;
    std::ostringstream authHeader;
    const std::string URL = "https://www.googleapis.com/drive/v2/files";
    
    authHeader << "Authorization: Bearer "<<credential.getToken();
    curl = curl_easy_init();
    if(curl){
        headers = curl_slist_append(headers, "Content-length: 0");
        headers = curl_slist_append(headers, authHeader.str().c_str());
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
#ifdef DEBUG
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
#endif
        resCode = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if (resCode!=CURLcode::CURLE_OK)
            std::cout << resCode << std::endl;
    }
}