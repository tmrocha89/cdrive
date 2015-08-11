#ifndef __cdrive__IGetGoogleCode__
#define __cdrive__IGetGoogleCode__

#include <iostream>
#include "Credential.h"

/**
 * @file IGetGoogleCode.h
 *
 * @brief This class will create and do the
 * **HTTP POST** needed to get the url for
 * user can go to the web page and accept
 * the permissions for this app and get the code.
 *
 * This class also contains all the google credentials
 * needed by this application.
 *
 * @author TmRocha
 */
class IGetGoogleCode{
    
public:
    /**
        This method returns the url for user can
        access it and get your access code needed
        for getting the access tokens
     
        @return A string, a url for getting the code
     */
    virtual std::string getCodeUrl() const=0;
    
    /**
        This method will get the code and will request
        the access token
     
        @param[in]  code is the code that user get from google
     
     */
    virtual Credential requestCredential(const std::string& code) =0;
};


#endif /* defined(__cdrive__IGetGoogleCode__) */
