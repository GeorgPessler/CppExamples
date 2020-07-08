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
        // for(int i = 0; i < m_Size  + 1; i++){ // ok, but theres sth better
        //     m_Buffer[i] = string[i];
        // }
        memcpy(m_Buffer,string,m_Size); // shorter
        m_Buffer[m_Size] = 0; // this is to ensure to have a 0 termination after string
        // just for the case that string had no terminating 0 
    }

    ~String(){
        delete[] m_Buffer;
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

int main(){
    String string = "Schorsch";
    String second = string; // shallow copy! just the pointer is copied
    
    second[3] = 'a'; // now both are changed because they point to same buffer

    std::cout << string << std::endl;
    std::cout << second << std::endl;

    std::cin.get();
} // after leaving scope string destructor is called and deletes buffer
// when second destructor is called and tries to delete buffer an error occurs!

// shallow copies copy objects with their variables and pointers, but they don't go to the values of the pointer to copy them
// a deep copy copies everything. a new object will be created with its own memory and the values from the old object will be copied

// cpp provides a copy constructor, but it does a shallow copy 