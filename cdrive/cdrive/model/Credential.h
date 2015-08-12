/**
 * @file Credential.h
 *
 * @brief This class handles with credentials.
 *
 *  **This class is simple a bag. Must be remove.**
 *
 */
#ifndef __cdrive__Credential__
#define __cdrive__Credential__

#include <iostream>
#include <map>
#include "/Users/tmr/Documents/development/cdrive/cdrive/cdrive/libs/rapidjson/document.h"

#define MAX_ELEMENTS 5

class Credential{
    
private:
    Credential();
    
    void pullToken(rapidjson::Document &doc);
    void pullRefreshToken(rapidjson::Document &doc);
    void pullTokenID(rapidjson::Document &doc);
    void pullExpires(rapidjson::Document &doc);
    void pullTokenType(rapidjson::Document &doc);
    
public:
    
    /// This enum contains all the data type
    /// in json file requested at google
    enum CredentialType{
        /// Access token
        ACCESS_TOKEN,
        /// Token type
        TOKEN_TYPE,
        /// Time in milliseconds that token will expire
        EXPIRES_IN,
        /// Token id
        ID_TOKEN,
        /// Refresh Token
        REFRESH_TOKEN
    };
    
    /// Names to parse the json file to get data from it.
    const char* credentialTypesName[MAX_ELEMENTS]={"access_token", "token_type", "expires_in", "id_token", "refresh_token"};

private:
    std::map< CredentialType, std::string > credentials;

    
public:
    /**
        Constructor that receives the string with
        webpage and will extract the data.
     
        @param[in]  webpage String that contains webpage source code.
     */
    Credential(std::string webpage);
    
    /**
        Complete Constructor
     
        @param[in] accessToken Access Token
        @param[in] tokenType    Token Type, generally 'Bearer'
        @param[in] expiresIn    Time when token will expire
        @param[in] idToken      Token's ID
        @param[in] refreshToken Refresh Token
     */
    Credential(const std::string& accessToken, const std::string& tokenType,
               const std::string& expiresIn, const std::string& idToken,
               const std::string& refreshToken);
    
    
    Credential(const Credential&);
    
    /**
        Destructor
     */
    ~Credential();
    
    /**
        This method returns the token
     
        @return A string with access token
     */
    std::string getToken() const;
    
    /**
        This method returns the refresh token
     
        @return A string with refresh token
     */
    const std::string getRefreshToken() const;
    
    /**
        This method returns the token id
     
        @return A string with token's id
     */
    const std::string getTokenID() const;
    
    friend bool operator==(const Credential& c1, const Credential& c2);

};


#endif /* defined(__cdrive__Credential__) */
