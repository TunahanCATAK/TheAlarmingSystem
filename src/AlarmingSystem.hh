// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <dzn/meta.hh>

namespace dzn {
  struct locator;
  struct runtime;
}



#include <iostream>
#include <map>

/***********************************  SYSTEM  ***********************************/
#ifndef ALARMINGSYSTEM_HH
#define ALARMINGSYSTEM_HH


#include <dzn/locator.hh>

#include "Controller.hh"
#include "LED.hh"
#include "Sensor.hh"
#include "Siren.hh"
#include "Timer.hh"



struct AlarmingSystem
{
  dzn::meta dzn_meta;
  dzn::runtime& dzn_rt;
  dzn::locator const& dzn_locator;


  ::Controller controller;
  ::LED led;
  ::Sensor sensor;
  ::Siren siren;
  ::Timer timer;

  ::IController& iController;


  AlarmingSystem(const dzn::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os=std::clog) const;
};

#endif // ALARMINGSYSTEM_HH

/***********************************  SYSTEM  ***********************************/


//version: 2.8.2
