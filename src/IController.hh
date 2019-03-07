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

/********************************** INTERFACE *********************************/
#ifndef ICONTROLLER_HH
#define ICONTROLLER_HH




struct IController
{

  struct
  {
    std::function< void()> validPinCode;
  } in;

  struct
  {
  } out;

  dzn::port::meta meta;
  inline IController(const dzn::port::meta& m) : meta(m) {}

  void check_bindings() const
  {
    if (! in.validPinCode) throw dzn::binding_error(meta, "in.validPinCode");


  }
};

inline void connect (IController& provided, IController& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}





#endif // ICONTROLLER_HH

/********************************** INTERFACE *********************************/


//version: 2.8.2
