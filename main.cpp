#include <iostream>
#include "calc.hpp"
#include "Wifi.hpp"
#include "defaultconfig.h"

int main()
{

#ifdef DEBUGINFO
    std::cout << DEBUGINFO << std::endl;
#endif
    std::cout << "Software Version is" << HELLOAPP_VERSION_MAJOR << "." << HELLOAPP_VERSION_MINOR<<std::endl;
    std::cout << sum(3,4);
    WIFI_Init();
    std::cout << "ProductType is" << ProductType << std::endl;
    std::cout << "PRODUCT_YEAR is" << PRODUCT_YEAR << std::endl;
    //std::cout << STD_CXX << std::endl;
    return 0;
}