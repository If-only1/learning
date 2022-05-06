#include <exception>
#include <iostream>
#include <sstream>
class RangeException : public std::exception {
   private:
    int dim;
    int index;
    std::string s;

   public:
    RangeException(){};
    RangeException(int dim, int index) {
        this->dim = dim;
        this->index = index;
        std::stringstream ss;
        ss << "out of range"
           << "index: " << index << " dim: " << dim;
        // std::cout << ss.str() << std::endl;
        s = ss.str();
    }
    const char* what() const noexcept override { return s.c_str(); }
};