#include "json_wrapper.h"
#include <iostream>

int main() {

    JSON_API_object suomi_object ("https://restcountries.com/v3.1/name/suomi");
    
    std::cout << "Common Name: " << suomi_object.get_data()[0]["name"]["common"] << "\n";
    std::cout << "Official Name: " << suomi_object.get_data()[0]["name"]["common"] << "\n";
    std::cout << "Capital: " << suomi_object.get_data()[0]["capital"][0] << "\n";
    std::cout << "Population: " << suomi_object.get_data()[0]["population"] << "\n";

    return 0;
}
