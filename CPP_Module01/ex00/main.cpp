#include "Zombie.hpp"

int main() {
  std::cout << "------------------------------------\n";
  //heap
  Zombie* heap_zombie = newZombie("HEAP ZOMBIE");
  heap_zombie->announce();
  delete heap_zombie;
  std::cout << "------------------------------------\n";
  //stack
  randomChump("STACK ZOMBIE");
  std::cout << "------------------------------------\n";
  return 0;
}
