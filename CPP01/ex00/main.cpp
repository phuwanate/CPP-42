#include "Zombie.hpp"

int main(void)
{
    Zombie  new_guy("Freddy");
    Zombie  *new_guy2 = newZombie("Jonathan");
    
    if (new_guy2 == NULL)
    {
        std::cout << "Memory allocate failed..." << '\n';
        return (EXIT_FAILURE);
    }
    new_guy.announce();
    new_guy2->announce();   
    randomChump("Flank");
    delete new_guy2;
    
    return (EXIT_SUCCESS);
}