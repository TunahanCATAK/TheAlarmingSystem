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
#ifndef ISENSOR_HH
#define ISENSOR_HH




struct ISensor
{
#ifndef ENUM_ISensor_State
#define ENUM_ISensor_State 1


  struct State
  {
    enum type
    {
      On,Off
    };
  };


#endif // ENUM_ISensor_State

  struct
  {
    std::function< void()> turnOn;
    std::function< void()> turnOff;
  } in;

  struct
  {
    std::function< void()> triggered;
  } out;

  dzn::port::meta meta;
  inline ISensor(const dzn::port::meta& m) : meta(m) {}

  void check_bindings() const
  {
    if (! in.turnOn) throw dzn::binding_error(meta, "in.turnOn");
    if (! in.turnOff) throw dzn::binding_error(meta, "in.turnOff");

    if (! out.triggered) throw dzn::binding_error(meta, "out.triggered");

  }
};

inline void connect (ISensor& provided, ISensor& required)
{
  provided.out = required.out;
  required.in = provided.in;
  provided.meta.requires = required.meta.requires;
  required.meta.provides = provided.meta.provides;
}


#ifndef ENUM_TO_STRING_ISensor_State
#define ENUM_TO_STRING_ISensor_State 1
inline std::string to_string(::ISensor::State::type v)
{
  switch(v)
  {
    case ::ISensor::State::On: return "State_On";
    case ::ISensor::State::Off: return "State_Off";

  }
  return "";
}
#endif // ENUM_TO_STRING_ISensor_State

#ifndef STRING_TO_ENUM_ISensor_State
#define STRING_TO_ENUM_ISensor_State 1
inline ::ISensor::State::type to_ISensor_State(std::string s)
{
  static std::map<std::string, ::ISensor::State::type> m = {
    {"State_On", ::ISensor::State::On},
    {"State_Off", ::ISensor::State::Off},
  };
  return m.at(s);
}
#endif // STRING_TO_ENUM_ISensor_State


#endif // ISENSOR_HH

/********************************** INTERFACE *********************************/


//version: 2.8.2
