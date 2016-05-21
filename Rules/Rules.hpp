#ifndef MY_RULES
#define MY_RULES

#include <vector>
#include <utility>
#include <ostream>

#include "Data/Data.hpp"

class Rules {
  using ItemsWithSupportIndex = std::vector<std::pair<BitsType, double>>;
  ItemsWithSupportIndex itemsWithSuppIndex;
public:
  static Rules filterBySupportWithRespectToTransactions(const Data&, const double& threshold);
  /* TODO
     static Rules filterByConfidence(const Data&) { return Rules(); }
     static Rules filterByConfidence(const Rules&) { return Rules(); }
  */

  friend std::ostream& operator<< (std::ostream&, const Rules&);
};

#endif // MY_RULES
