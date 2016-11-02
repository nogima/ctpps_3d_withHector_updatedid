#ifndef CTPPS_TRACKERDIGICOLLECTION_H
#define CTPPS_TRACKERDIGICOLLECTION_H

#include "DataFormats/CTPPSDigi/interface/CTPPSTrackerDigi.h"
#include <vector>
#include <map>
#include <utility>

class RPixDigiCollection {

 public:

  typedef std::vector<RPixDigi>::const_iterator ContainerIterator;
  typedef std::pair<ContainerIterator, ContainerIterator> Range;
  typedef std::pair<unsigned int, unsigned int> IndexRange;
  typedef std::map<unsigned int, IndexRange> Registry;
  typedef std::map<unsigned int, IndexRange>::const_iterator RegistryIterator;

  RPixDigiCollection() {}
  
  void put(Range input, unsigned int detID);
  const Range get(unsigned int detID) const;
  const std::vector<unsigned int> detIDs() const;
  
 private:
  std::vector<RPixDigi> container_;
  Registry map_;

};

#endif 
