/*
  Copyright 2013 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef TIMEMAP_HPP_
#define TIMEMAP_HPP_

#include <boost/date_time.hpp>

namespace Opm {

    class TimeMap {
    public:
        TimeMap(boost::gregorian::date startDate);
        void addDate(boost::gregorian::date newDate);
        void addTStep(boost::posix_time::time_duration step);
        size_t size() const;

    private:
        boost::gregorian::date m_startDate;
        std::vector<boost::posix_time::ptime> m_timeList;
    };

}



#endif /* TIMEMAP_HPP_ */
