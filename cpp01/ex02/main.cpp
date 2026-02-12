# include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Adress of str " << &string << std::endl;
    std::cout << "Adress of strptr " << stringPTR << std::endl;
    std::cout << "Adress of strREF " << stringREF << std::endl;

    std::cout << "value of str " << string << std::endl;
    std::cout << "value of strptr " << &string << std::endl;
    std::cout << "value of strREF " << stringREF << std::endl;
    return 0;
}