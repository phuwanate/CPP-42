#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include "DataStructure.hpp"

class Serialization{

    private:
                    Serialization(void);
    public:
                    Serialization(Serialization const &inst);
                    ~Serialization(void);
                    Serialization &operator=(Serialization const &inst);   

            static  uintptr_t serialize(Data* ptr);
            static  Data* deserialize(uintptr_t raw);
};

#endif