#include<iostream>
#include<string>

void reverse_string(std::string& s){
    std::cout << "String reversed: ";
    for(auto it = s.end(); it != s.begin()-1; it--){
        std::cout << *it;
    }
}
int main()
{   std::string s{};
    std::cout << "Enter a string: ";
    std::cin >> s;
    reverse_string(s);
    std::cout << "\n";
 return 0;
}