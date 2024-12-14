//
//  main.cpp
//  BoostTrial
//
//  Created by nasr on 07/12/2024.
//

// clang++ -std=c++17 -I boost -L timer  main.cpp -o test -lboost_system -lboost_filesystem -lboost_timer

#include "boost/date_time/local_time/local_time.hpp"
#include "iostream"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  time_zone_ptr tz{new posix_time_zone{"CET+1"}};
  ptime pt{date{2024, 12, 14}, time_duration{12, 0, 0}};
  local_date_time dt{pt, tz};
  std::cout << dt.utc_time() << '\n';
  std::cout << dt << '\n';
  std::cout << dt.local_time() << '\n';
  std::cout << dt.zone_name() << '\n';
}

