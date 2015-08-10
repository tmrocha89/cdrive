#include "Credential.h"

Credential::Credential(){}

Credential::Credential(std::string webpage){
    Credential::Credential();
    rapidjson::Document document;
    document.Parse(webpage.c_str());
    rapidjson::Document* doc = &document;
    pullToken(*doc);
    pullExpires(*doc);
    pullRefreshToken(*doc);
    pullTokenID(*doc);
    pullTokenType(*doc);
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