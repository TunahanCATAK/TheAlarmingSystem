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
#ifndef ILED_HH
#define ILED_HH




struct ILED
{

  struct
  {
    std::function< void()> setGreen;
    std::function< void()> setYellow;
    std::function< void()> setRed;
  } in;

  struct
  {
  } out;

  dzn::port::meta meta;
  inline ILED(const dzn::port::meta& m) : meta(m) {}

  void check_bindings() const
  {
    if (! in.setGreen) throw dzn::binding_error(meta, "in.setGreen");
    if (! in.setYellow) throw dzn::binding_error(meta, "in.setYellow");
    if (! in.setRed) throw dzn::binding_error(meta, "in.setRed");


  }
};

inline void connect (ILED& provided, ILED& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}





#endif // ILED_HH

/********************************** INTERFACE *********************************/


//version: 2.8.2
