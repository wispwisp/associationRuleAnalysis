#include <iostream>
#include <fstream>

#include "Options/Options.hpp"
#include "Rules/Rules.hpp"
#include "Data/Data.hpp"

int main() {

  // Options opts(argc, argv);

  std::ifstream file("association_rules.data");//opts.fileName
  auto data = Data::parseUniqueDataFromStream(file);
  file.close();

  // https://en.wikipedia.org/wiki/Association_rule_learning#Support
  Rules rules = Rules::filterBySupportWithRespectToTransactions(data,
                                                                0.0001);
                                                                //opts.threshold);
  std::cout << rules << '\n';
}
