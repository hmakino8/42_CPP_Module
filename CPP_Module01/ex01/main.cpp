#include "Zombie.hpp"

int main() {
  {
    int N = 8;
    std::cout << "[test1]: N = " << N << "\n";

    Zombie* zombie = zombieHorde(N, "zombie");
    for (int i = 0; i < N; ++i) { zombie->announce(); }
    delete[] zombie;
  }
  {
    int N = 0;
    std::cout << "[test2]: N = " << N << "\n";

    Zombie* zombie = zombieHorde(N, "zombie");
    for (int i = 0; i < N; ++i) { zombie->announce(); }
    delete[] zombie;
  }
  {
    int N = -1;
    std::cout << "[test3]: N = " << N << "\n";

    Zombie* zombie = zombieHorde(N, "zombie");
    for (int i = 0; i < N; ++i) { zombie->announce(); }
    delete[] zombie;
  }
  return 0;
}
