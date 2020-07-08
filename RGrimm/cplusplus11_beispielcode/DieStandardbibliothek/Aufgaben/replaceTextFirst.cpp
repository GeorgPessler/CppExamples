#include <regex>

#include <iostream>
#include <string>


int main(){

  std::cout << std::endl;

  // regular expression holder for number
  std::regex rgx("(\\d+)");

  // std::string
  std::smatch smatch;

  std::string inputText("We happily announce to you the draw of the Euro - Afro Asian Sweepstake Lottery International programs held on the first of May 2004 in Dakar Senegal.Your e-mail address attached to ticket number: 564-75600545-188with Serial number 5388/02 drew the lucky numbers: 31-6-26-13-35-7, which subsequently won you the lottery in the 2nd category.\n\nCONGRATULATIONS!!!");

  std::cout << std::regex_replace(inputText,rgx,std::string("2012"),boost::regex_constants::format_first_only);

  std::cout << std::endl;

}
