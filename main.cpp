#include <iostream>
#include <fstream>

#include "Options/Options.hpp"
#include "Rules/Rules.hpp"
#include "Data/Data.hpp"

int main(int argc, char** argv) {

  // todo - remove when Options class will be ready:

  // Options opts(argc, argv);
  if (argc < 4) {
    std::cout << "Usage: " << argv[0] << " <file name> <threshold> <sort-type> <number of rules to show>\n";
    return -1;
  }

  struct Opts {
    std::string fileName;
    double threshold;
    Opts(const char* fn, const char* th) : fileName(fn), threshold(std::stod(th)) {}
  };
  Opts opts(argv[1], argv[2]);

  // ****




  std::ifstream file(opts.fileName);
  auto data = Data::parseUniqueDataFromStream(file);
  file.close();

  Rules rules(data, opts.threshold);
  std::cout << rules << '\n';
}
