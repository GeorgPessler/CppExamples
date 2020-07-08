
// replace #include <boost/tr1/regex.hpp> with
//         #include <regex>
// and
// std::tr1:: with std:: in the source code

#include <boost/tr1/regex.hpp>

#include <iostream>
#include <string>
#include <vector>

int main(){

  std::cout << std::endl;

  // a few books
  std::string text{"Pete Becker,The C++ Standard Library Extensions,2006:Nicolai Josuttis,The C++ Standard Library,1999:Andrei Alexandrescu,Modern C++ Design,2001"};

  // regular expression for a book
  std::tr1::regex regBook(R"((\w+)\s(\w+),([\w\s\+]*),(\d{4}))");

  // get all books from text
  std::tr1::sregex_token_iterator bookItBegin(text.begin(),text.end(),regBook);
  const std::tr1::sregex_token_iterator bookItEnd;

  std::cout << "##### std::match_results ######" << "\n\n";
  while ( bookItBegin != bookItEnd){
    std::cout << *bookItBegin++ << std::endl;
  }

  std::cout << "\n\n" << "##### last name, date of publication ######" << "\n\n";

  // get all last name and date of publication for the entries
  std::tr1::sregex_token_iterator bookItNameIssueBegin(text.begin(),text.end(),regBook,{{2,4}});
  const std::tr1::sregex_token_iterator bookItNameIssueEnd;
  while ( bookItNameIssueBegin != bookItNameIssueEnd){
      std::cout << *bookItNameIssueBegin++ << ", ";
      std::cout << *bookItNameIssueBegin++ << std::endl;
  }

  // regular expression for a book, using negativ search
  std::tr1::regex regBookNeg(":");

  std::cout << "\n\n" << "##### get each entry, using negativ search  ######" << "\n\n";

  // get all entries, only using ":" as regular expression
  std::tr1::sregex_token_iterator bookItNegBegin(text.begin(),text.end(),regBookNeg,-1);
  const std::tr1::sregex_token_iterator bookItNegEnd;
   while ( bookItNegBegin != bookItNegEnd){
       std::cout << *bookItNegBegin++ << std::endl;
   }


  std::cout << std::endl;

}
