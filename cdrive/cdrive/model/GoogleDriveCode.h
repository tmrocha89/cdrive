/**
 * @file GoogleDriveCode.h
 *
 * @brief
 *
 * @author TmRocha
 */
#ifndef __cdrive__GoogleDriveCode__
#define __cdrive__GoogleDriveCode__

#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include "IGetGoogleCode.h"
#include "Credential.h"

class GoogleDriveCode : public IGetGoogleCode{
    
private:
    
    const static std::string CLIENT_ID;
    const static std::string AUTH_URI;
    const static std::string TOKEN_URI;
    const static std::string CLIENT_SECRET;
    const static std::string REDIRECT_URI;
    const static std::string DRIVE_URL;
    
    static size_t getUrlCode(void *ptr, size_t size, size_t nmemb, void *userdata);
    static size_t getTokensJson(void *ptr, size_t size, size_t nmemb, void *userdata);
public:
    
    GoogleDriveCode();
    ~GoogleDriveCode();
    
    std::string getCodeUrl() const;
    
    Credential requestCredential(const std::string& code);
    
    
};


#endif /* defined(__cdrive__GoogleDriveCode__) */
