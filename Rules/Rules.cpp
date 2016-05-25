#include "Rules.hpp"

#include <functional>
#include <numeric>
#include <iostream>

namespace Tools {
  bool isSubset(const Data::BitsType& source, const Data::BitsType& rhs) {
    // We interseted only in appeared items, so if we have 1 in one set we 
    // should have 1 in another. We do not care for '0'
    for (size_t i = 0; i < source.size(); ++i) {
      if (source[i]) {
	if (not rhs[i]) return false;
      }
    }

    return true;
  }
}

Rules::Rules(const Data& data, const double& threshold) {

  std::function<void(size_t, Data::BitsType)>
    generateAndCheck = [&](size_t i, Data::BitsType candidate) {

    if (i == candidate.size())
      return; // stop recursion progression

    // ..11[0]...
    Data::BitsType withHole = candidate;

    // ..11[1]...
    candidate[i] = 1;

    size_t appearPerTransaction = 0;
    for (const auto& transaction : data.get()) {

      const Data::BitsType& itemSet = transaction.first;
      const size_t uniqueCount = transaction.second;

      if (Tools::isSubset(candidate, itemSet))
	appearPerTransaction += uniqueCount;
    }

    double support = double(appearPerTransaction) / double(data.transactionsCount());
    if (support >= threshold) {
      itemsWithSuppIndex.emplace_back(std::make_pair(candidate, support));
      generateAndCheck(i + 1, std::move(candidate));
    }

    // try with holes: (ex.) 001010 ("Try next item")
    generateAndCheck(i + 1, std::move(withHole));
  };

  // start check candidates:
  generateAndCheck(0, Data::BitsType(data.transactionSize()));
}

std::ostream& operator<< (std::ostream& os, const Rules& rules) {
  for (const auto& itemsAndSupp : rules.itemsWithSuppIndex) {
    const auto& items = itemsAndSupp.first;
    const auto& suppIndex = itemsAndSupp.second;

    std::string str;
    for (size_t i=0; i< items.size(); ++i) {
      if (items[i])
	str += "{" + std::to_string(i+1) + "} ";
    }
    str += "-> ";

    os << str
       << suppIndex << '\n';
  }

  return os;
}
