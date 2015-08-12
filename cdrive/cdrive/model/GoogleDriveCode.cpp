#include "GoogleDriveCode.h"

const std::string GoogleDriveCode::CLIENT_ID = "1033063813595-jjl34819c76cd5jll6hg52kvq9qr4tf2.apps.googleusercontent.com";
const std::string GoogleDriveCode::AUTH_URI = "https://accounts.google.com/o/oauth2/auth";
const std::string GoogleDriveCode::TOKEN_URI = "https://accounts.google.com/o/oauth2/token";
const std::string GoogleDriveCode::CLIENT_SECRET = "6VA4krRe6qj4waIz6HMbzbyV";
const std::string GoogleDriveCode::REDIRECT_URI = "urn:ietf:wg:oauth:2.0:oob";
const std::string GoogleDriveCode::DRIVE_URL = "https://www.googleapis.com/drive/v2";

GoogleDriveCode::GoogleDriveCode(){}

GoogleDriveCode::~GoogleDriveCode(){}



size_t GoogleDriveCode::getTokensJson(void *ptr, size_t size, size_t nmemb, void *userdata){
    std::string temp ((char*)ptr);
    std::ostringstream* out = (std::ostringstream*) userdata;
    out->write(temp.c_str(), temp.size());
    return size * nmemb;
}

size_t GoogleDriveCode::getUrlCode(void *ptr, size_t size, size_t nmemb, void *userdata){
    std::string temp ((char*)ptr);
    size_t s = temp.find("Location");
    if(s != std::string::npos){
        std::ostringstream* stream = (std::ostringstream*)userdata;
        temp.erase(0, strlen("Location: "));
        stream->write(temp.c_str(), temp.size()-2); //'-2' to remove \n\r
    }
    return size * nmemb;
}

std::string GoogleDriveCode::getCodeUrl() const{
    CURL* curl;
    CURLcode resCode;
    std::ostringstream urlstream;
    
    std::ostringstream postStream;
    /*
    postStream << "scope=email profile https://www.googleapis.com/auth/drive&redirect_uri="<< REDIRECT_URI <<"&response_type=code&client_id=" << CLIENT_ID;
*/
    postStream << "scope=email profile https://www.googleapis.com/auth/drive&redirect_uri="<< REDIRECT_URI <<"&response_type=code&client_id=" << CLIENT_ID;
    std::string postFields = postStream.str();
    
    curl = curl_easy_init();
    if(curl){
        /*
         * 'Launch' google popup
         */
        curl_easy_setopt(curl, CURLOPT_URL, AUTH_URI.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str() );
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getUrlCode);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urlstream);
        resCode = curl_easy_perform(curl); //couldn resolve host: code 6
        curl_easy_cleanup(curl);
        if (resCode!= CURLcode::CURLE_OK)
            throw 99;
        
    }else{
        throw 99;
    }
    
    return urlstream.str();
}


Credential GoogleDriveCode::requestCredential(const std::string& code){
    CURL* curl;
    CURLcode resCode;
    std::ostringstream outsream;
    /*
     * Get Tokens
     */
    std::ostringstream postStreamTokens;
    
    postStreamTokens << "client_id=" << CLIENT_ID << "&client_secret=" << CLIENT_SECRET << "&redirect_uri=urn:ietf:wg:oauth:2.0:oob&grant_type=authorization_code&code=" << code;
    
    std::string postFiledsToken = postStreamTokens.str();
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, TOKEN_URI.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFiledsToken.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getTokensJson);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outsream);
        resCode = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if (resCode!=CURLcode::CURLE_OK)
            throw resCode;        
        
        Credential c(outsream.str());
        return c;
    }else{
        throw 99;
    }
}

