#include <string>
#include <sstream>
#include <iostream>

std::string hex( unsigned int c )
{
    std::ostringstream stm ;
    stm << std::hex << std::uppercase << c ;
    return stm.str() ;
}

std::string url_encode( const std::string& str )
{
    static const std::string unreserved = "0123456789"
                                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                            "abcdefghijklmnopqrstuvwxyz"
                                            "-_.~" ;
    std::string result ;

    for( unsigned char c : str )
    {
        if( unreserved.find(c) != std::string::npos ) result += c ;
        else result += hex(c) ;
    }

    return result ;
}

int main()
{
    std::string mystr;
    std::cin >> mystr;
    //std::cout << sizeof(mystr);
    std::string test = mystr ;
    std::cout << test << '\t'
               << url_encode(test) << std::endl ;
}