#include <iostream>

const char *kNoise = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

std::string StringToUpperCase(std::string str) {
  for (int i = 0, len = str.length(); i < len; i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

std::string Megaphone(int argc, char *argv[])
{
  std::string s;

  for (int i = 1; i < argc; i++) {
    s += StringToUpperCase(argv[i]);
    if (i < argc - 1) s += " ";
  }
  return s;
}

int main(int argc, char *argv[]) {
  if (argc < 1) {
    return 1;
  }
  if (argc == 1) {
    std::cout << kNoise << std::endl;
  } else {
    std::cout << Megaphone(argc, argv) << std::endl;
  }
  return 0;
}
