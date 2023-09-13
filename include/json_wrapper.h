#ifndef JSON_WRAPPER_H
#define JSON_WRAPPER_H

#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>



using Json = nlohmann::json;

std::string curl_http_get(const std::string &url);

class JSON_API_object {
    public:
        JSON_API_object(std::string url_input) : url(url_input) {
            data = Json::parse(curl_http_get(url_input));
        };

        // Updates json data
        void update_data() {
            data = Json::parse(curl_http_get(url));
        }

        // Returns json data
        Json get_data() {
            return data;
        }
    private:
        Json data;
        std::string url;
};


#endif

