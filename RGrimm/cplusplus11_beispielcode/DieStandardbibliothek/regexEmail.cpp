#include <regex>

#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string emailDescription="Email addresses, such as rainer@grimm-jaud.de, have two parts.";

  // regular expression for the email address
  std::string regExprStr(R"(([\w.%+-]+)@([\w.-]+\.[a-zA-Z]{2,4}))");

  // regular expression holder
  std::regex rgx(regExprStr);

  // search result holder
  std::smatch smatch;

  // looking for a partial match
  if (std::regex_search(emailDescription,smatch,rgx)){

    std::cout << "Text: " << emailDescription << std::endl;

    std::cout << std::endl;

    std::cout << "Email address: " << smatch[0] << std::endl;
    std::cout << "Local part: " << smatch[1] << std::endl;
    std::cout << "Domain name: " << smatch[2] << std::endl;

    std::cout << std::endl;

    std::cout << "Text before the email address: "  << smatch.prefix() << std::endl;
    std::cout << "Text after the email address: "  << smatch.suffix() << std::endl;

  }

  std::cout << std::endl;

}
