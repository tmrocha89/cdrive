#include "Credential.h"

Credential::Credential(){}

Credential::Credential(std::string webpage){
    rapidjson::Document document;
    document.Parse(webpage.c_str());
    rapidjson::Document* doc = &document;
    pullToken(*doc);
    pullExpires(*doc);
    pullRefreshToken(*doc);
    pullTokenID(*doc);
    pullTokenType(*doc);
}

Credential::Credential(const std::string& accessToken, const std::string& tokenType,
                       const std::string& expiresIn, const std::string& idToken,
                       const std::string& refreshToken):credentials(){
    
    credentials.insert(std::make_pair(CredentialType::ACCESS_TOKEN, accessToken));
    credentials.insert(std::make_pair(CredentialType::TOKEN_TYPE, tokenType));
    credentials.insert(std::make_pair(CredentialType::EXPIRES_IN, expiresIn));
    credentials.insert(std::make_pair(CredentialType::ID_TOKEN, idToken));
    credentials.insert(std::make_pair(CredentialType::REFRESH_TOKEN, refreshToken));
    
}

Credential::Credential(const Credential& cre){
    for(std::map<CredentialType, std::string>::const_iterator cit = cre.credentials.cbegin();
        cit != cre.credentials.cend(); cit++){
        this->credentials.insert(std::make_pair(cit->first, cit->second));
    }
}

Credential::~Credential(){}

std::string Credential::getToken()const{
    std::map<CredentialType,std::string>::const_iterator it = credentials.find(CredentialType::ACCESS_TOKEN);
    
    if (it == credentials.end()) {
        throw 99;
    }
    
    return it->second;
}


const std::string Credential::getRefreshToken() const{
    std::map<CredentialType,std::string>::const_iterator it = credentials.find(CredentialType::REFRESH_TOKEN);

    if (it == credentials.end()) {
        throw 99;
    }
    
    return it->second;
}


const std::string Credential::getTokenID()const{
    std::map<CredentialType,std::string>::const_iterator it = credentials.find(CredentialType::ID_TOKEN);
    
    if (it == credentials.end()) {
        throw 99;
    }
    
    return it->second;
}


void Credential::pullToken(rapidjson::Document &doc){
    rapidjson::Value &accToken = doc[credentialTypesName[CredentialType::ACCESS_TOKEN]];
    credentials.insert(std::make_pair(CredentialType::ACCESS_TOKEN, accToken.GetString()));
}

void Credential::pullTokenType(rapidjson::Document &doc){
    rapidjson::Value &tokType = doc[credentialTypesName[CredentialType::TOKEN_TYPE]];
    credentials.insert(std::make_pair(CredentialType::TOKEN_TYPE, tokType.GetString()));
}

void Credential::pullExpires(rapidjson::Document &doc){
    rapidjson::Value &tokExpire = doc[credentialTypesName[CredentialType::EXPIRES_IN]];
    std::string tokenExpireStr(""+tokExpire.GetInt());
    credentials.insert(std::make_pair(CredentialType::EXPIRES_IN, tokenExpireStr));
}

void Credential::pullTokenID(rapidjson::Document &doc){
    rapidjson::Value &tokID = doc[credentialTypesName[CredentialType::ID_TOKEN]];
    credentials.insert(std::make_pair(CredentialType::ID_TOKEN, tokID.GetString()));
}

void Credential::pullRefreshToken(rapidjson::Document &doc){
    rapidjson::Value &refToken = doc[credentialTypesName[CredentialType::REFRESH_TOKEN]];
    credentials.insert(std::make_pair(CredentialType::REFRESH_TOKEN, refToken.GetString()));
}


bool operator==(const Credential &c1, const Credential& c2){
    std::string c1AccToken = c1.credentials.at(Credential::CredentialType::ACCESS_TOKEN);
    std::string c2AccToken = c2.credentials.at(Credential::CredentialType::ACCESS_TOKEN);
    if (c1AccToken != c2AccToken) return false;
    
    std::string c1TokenType = c1.credentials.at(Credential::CredentialType::TOKEN_TYPE);
    std::string c2TokenType = c2.credentials.at(Credential::CredentialType::TOKEN_TYPE);
    if (c1TokenType != c2TokenType) return false;
    
    std::string c1Expires = c1.credentials.at(Credential::CredentialType::EXPIRES_IN);
    std::string c2Expires = c2.credentials.at(Credential::CredentialType::EXPIRES_IN);
    if (c1Expires != c2Expires) return false;
    
    std::string c1ID = c1.credentials.at(Credential::CredentialType::ID_TOKEN);
    std::string c2ID = c2.credentials.at(Credential::CredentialType::ID_TOKEN);
    if (c1ID != c2ID)   return false;
    
    std::string c1Refresh = c1.credentials.at(Credential::CredentialType::REFRESH_TOKEN);
    std::string c2Refresh = c2.credentials.at(Credential::CredentialType::REFRESH_TOKEN);
    if (c1Refresh != c2Refresh) return false;
    
    return true;
}