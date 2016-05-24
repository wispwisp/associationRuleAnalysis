#ifndef MY_RULES
#define MY_RULES

#include <vector>
#include <utility>
#include <ostream>

#include "Data/Data.hpp"

class Rules {
public:
  using ItemsWithSupportIndex = std::vector<std::pair<Data::BitsType, double>>;

  Rules(const Data&, const double& threshold);
  friend std::ostream& operator<< (std::ostream&, const Rules&);

private:
  ItemsWithSupportIndex itemsWithSuppIndex;
};

#endif // MY_RULES
