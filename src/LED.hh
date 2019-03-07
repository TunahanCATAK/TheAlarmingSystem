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

/********************************** COMPONENT *********************************/
#ifndef LED_HH
#define LED_HH

#include "ILED.hh"



struct LED
{
  dzn::meta dzn_meta;
  dzn::runtime& dzn_rt;
  dzn::locator const& dzn_locator;
#ifndef ENUM_LED_LedState
#define ENUM_LED_LedState 1


  struct LedState
  {
    enum type
    {
      Yellow,Green,Red
    };
  };


#endif // ENUM_LED_LedState

  ::LED::LedState::type state;


  std::function<void ()> out_iLed;

  ::ILED iLed;



  LED(const dzn::locator&);
  void check_bindings() const;
  void dump_tree(std::ostream& os) const;
  friend std::ostream& operator << (std::ostream& os, const LED& m)  {
    (void)m;
    return os << "[" << m.state <<"]" ;
  }
  private:
  void iLed_setGreen();
  void iLed_setYellow();
  void iLed_setRed();

};

#endif // LED_HH

/********************************** COMPONENT *********************************/


//version: 2.8.2
