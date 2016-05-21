#include "Rules.hpp"

#include <numeric>

Rules Rules::filterBySupportWithRespectToTransactions(const Data& data, const double& threshold) {

  Rules r;
  size_t transactionCount = data.get().size();
  for (const auto& itemsAndOccurrence : data.get()) {

    const auto& items = itemsAndOccurrence.first;
    const auto& occurrenceCount = itemsAndOccurrence.second;

    double suppIndex = double(occurrenceCount) / double(transactionCount);
    unsigned itemNumber = std::accumulate(std::begin(items), std::end(items), 0u);

    // if pass threshold, then save:
    if (itemNumber > 1         // we interested in more than one-item transaction
	&& suppIndex >= threshold) { // threshold specified by user

      r.itemsWithSuppIndex.emplace_back(std::make_pair(items, suppIndex));
    }
  }

  return r;
}

std::ostream& operator<< (std::ostream& os, const Rules& rules) {
  for (const auto& itemsAndSupp : rules.itemsWithSuppIndex) {
    const auto& items = itemsAndSupp.first;
    const auto& suppIndex = itemsAndSupp.second;

    // I. little optimization for output sting to stream:
    std::string str;
    str.reserve(items.size() * 2);
    str.push_back('{');

    // symbol per bit:
    for (const auto& bit : items) { 
      str.push_back(bit ? '1' : '0');
      str.push_back(',');
    }
    str.back() = '}'; // change last comma to bracket

    // II. stream output:
    os << str
       << " "
       << suppIndex << '\n';
  }

  return os;
}
