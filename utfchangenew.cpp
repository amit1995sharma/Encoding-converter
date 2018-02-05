#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>

std::string hex_char_to_bin(char c) {
  switch (toupper(c)) {
  case '0':
    return "0000";
  case '1':
    return "0001";
  case '2':
    return "0010";
  case '3':
    return "0011";
  case '4':
    return "0100";
  case '5':
    return "0101";
  case '6':
    return "0110";
  case '7':
    return "0111";
  case '8':
    return "1000";
  case '9':
    return "1001";
  case 'A':
    return "1010";
  case 'B':
    return "1011";
  case 'C':
    return "1100";
  case 'D':
    return "1101";
  case 'E':
    return "1110";
  case 'F':
    return "1111";
  }
  return "";
}

std::string hex(unsigned int c) {
  std::ostringstream stm;
  stm << std::hex << std::uppercase << c;
  std::cout << std::endl << stm.str() << "\t" << c << std::endl;
  return stm.str();
}

std::string url_encode(const std::string &str) {
  static const std::string unreserved = "0123456789"
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "-_.~";
  std::string result;

  int len = str.length();
  std::cout << str << " has a length \t" << len << std::endl;
  for (unsigned char c : str) {
    std::cout << std::endl << (int)c << "\tint val" << std::endl;
    if (unreserved.find(c) != std::string::npos)
      result += c;
    else
      result += hex(c);
  }

  return result;
}
// using new technique works for range U+0000 to U+07FF
std::string new_url_encode(const std::string &str) {

  int len = str.length();
  std::cout << str << " has a length \t" << len << std::endl;
  if (len < 1) {
    return "no input found";
  }
  unsigned char str0 = str[0];
  if (str0 >= 0 && str0 <= 127) {

    return std::to_string(str0);
  }
  if (str0 >= 192 && str0 <= 223) {
    std::string result;
    for (unsigned char c : str) {

      result += hex(c);
    }
    return result;
  }
  return "working";
}

std::string Hex_to_binary_conversion(const std::string &ban) {
  std::string miniresult;
  std::string output;
  if (ban.length() == 1) {
    miniresult += hex_char_to_bin(ban[0]);
  }
  if (ban.length() == 3) {
    std::string tempminiresult;
    for (unsigned char c : ban) {
      tempminiresult += hex_char_to_bin(c);
    }
    std::cout << tempminiresult << "\n";
    std::cout << tempminiresult.substr(1, 5) << "\t\t"
              << tempminiresult.substr(6, 11) << std::endl;
    miniresult = "110" + tempminiresult.substr(1, 5) + "10" +
                 tempminiresult.substr(6, 11);
    std::cout << miniresult << "\n";
  }
  if (ban.length() == 2) {
    if (isdigit(ban[0]) && ((int)ban[0] - 48) <= 7) {
      for (unsigned char c : ban) {
        miniresult += hex_char_to_bin(c);
      }

    } else {
      std::string tempminiresult;
      tempminiresult += "000";
      for (unsigned char c : ban) {
        tempminiresult += hex_char_to_bin(c);
      }
      std::cout << tempminiresult << "\n";
      std::cout << tempminiresult.substr(0, 5) << "\t\t"
                << tempminiresult.substr(5, 11) << std::endl;
      miniresult = "110" + tempminiresult.substr(0, 5) + "10" +
                   tempminiresult.substr(5, 11);
      std::cout << miniresult << "\n";
    }
  }
  int i = std::stoi(miniresult, nullptr, 2);
  output = hex(i);
  return output;
}

int main() {
  std::string mystr;
  std::cin >> mystr;
  std::cout << sizeof(mystr);
  std::cout << std::endl
            << "---------------------------------------------------"
            << std::endl;
  std::cout << std::endl
            << Hex_to_binary_conversion(mystr) << "\tend" << std::endl;
}