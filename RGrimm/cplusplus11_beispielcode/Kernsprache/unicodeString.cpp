#include <string>

int main(){

  // initialize std::string with the UTF-8 literal
  const char* u8= u8"I'm a UTF-8 literal including a codepoint \u2620";
  std::string s1{u8};

  // initialize std::wstring with the wide literal
  const wchar_t* w= L"I'm a wide literal including a codepoint \u2620";
  std::wstring s2{w};

  // initialize std::u16string with the UTF-16 literal
  const char16_t* u16= u"I'm a UTF-16 literal including a codepoint \u2620";
  std::u16string u16string{u16};

  // initialize std::u32string with the UTF-32 literal
  const char32_t* u32= U"I'm a UTF-32 literal including a codepoint\u2620";
  std::u32string u32string{u32};

  // combine unicode and raw String literale
  const char* u8R= u8R"XXX(I'm a "raw UTF-8" literal.)XXX";
  const char16_t* uR16= uR"*(This is a "raw UTF-16" literal.)*";
  const char32_t* uR32= UR"(This is a "raw UTF-32" literal.)";

}
