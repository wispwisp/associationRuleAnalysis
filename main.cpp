#include <iostream>
#include <fstream>

#include "Options/Options.hpp"
#include "Rules/Rules.hpp"
#include "Data/Data.hpp"

int main(int argc, char** argv) {
  try {
    Options opts(argc, argv);

    std::ifstream file(opts.getFileName());
    auto data = Data::parseUniqueDataFromStream(file);
    file.close();

    Rules rules(data, opts.getThreshold());
    std::cout << rules << '\n';
  }
  catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
    return -1;
  }

  return 0;
}
