#include "DataFormats/CTPPSDigi/interface/CTPPSPixelDigiCollection.h"
#include <iostream>
#include <algorithm>

void RPixDigiCollection::put(Range input, unsigned int detID) {
  // put in Digis of detID

  // store size of vector before put
  IndexRange inputRange;

  // put in RPixDigis from input
  bool first = true;

  // fill input in temporary vector for sorting
  std::vector<RPixDigi> temporary;
  RPixDigiCollection::ContainerIterator sort_begin = input.first;
  RPixDigiCollection::ContainerIterator sort_end = input.second;
  for ( ;sort_begin != sort_end; ++sort_begin ) {
    temporary.push_back(*sort_begin);
  }
  std::sort(temporary.begin(),temporary.end());

  // iterators over input
  RPixDigiCollection::ContainerIterator begin = temporary.begin();
  RPixDigiCollection::ContainerIterator end = temporary.end();
  for ( ;begin != end; ++begin ) {
    container_.push_back(*begin);
    if ( first ) {
      inputRange.first = container_.size()-1;
      first = false;
    }
  }
  inputRange.second = container_.size()-1;
  
  // fill map
  map_[detID] = inputRange;

}

const RPixDigiCollection::Range RPixDigiCollection::get(unsigned int detID) const {
  // get Digis of detID

  auto found = map_.find(detID);
  RPixDigiCollection::IndexRange returnIndexRange{};
  if(found != map_.end()) {
    returnIndexRange = found->second;
  }

  RPixDigiCollection::Range returnRange;
  returnRange.first  = container_.begin()+returnIndexRange.first;
  returnRange.second = container_.begin()+returnIndexRange.second+1;

  return returnRange;
}

const std::vector<unsigned int> RPixDigiCollection::detIDs() const {
  // returns vector of detIDs in map

  RPixDigiCollection::RegistryIterator begin = map_.begin();
  RPixDigiCollection::RegistryIterator end   = map_.end();

  std::vector<unsigned int> output;

  for (; begin != end; ++begin) {
    output.push_back(begin->first);
  }

  return output;

}
