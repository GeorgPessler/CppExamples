#include <iostream>
#include <cstring>

class String{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string){
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer,string,m_Size); 
        m_Buffer[m_Size] = 0; 
    }

    ~String(){
        delete[] m_Buffer;
    }

    // String(const String& other) = delete; // this would forbid copying 
    // String(const String& other):m_Buffer(other.m_Buffer),m_Size(other.m_Size){} // basically the default copy constructor (shallow)
    // String(const String& other){memcpy(this, &other,sizeof(String));} // also basically the default copy constructor (shallow)

    String(const String& other):m_Size(other.m_Size){
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        std::cout << "Copied" << std::endl;
    }

    char& operator[](unsigned int index){
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
}

// void PrintString(String string){ // this would cause two more copies!
void PrintString(const String& string){ // now just a reference is passed
    // String copy = string; // we could do this if we would like to have a copy
    std::cout << string << std::endl;
}

// ALWAYS pass your objects by const & 

int main(){
    String string = "Schorsch";
    String second = string; 
    
    second[3] = 'a'; 

    PrintString(string);
    PrintString(second);

    std::cin.get();
} 