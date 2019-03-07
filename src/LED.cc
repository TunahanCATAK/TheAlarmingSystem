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
#include "LED.hh"

#include <dzn/locator.hh>
#include <dzn/runtime.hh>



LED::LED(const dzn::locator& dzn_locator)
: dzn_meta{"","LED",0,0,{},{},{[this]{iLed.check_bindings();}}}
, dzn_rt(dzn_locator.get<dzn::runtime>())
, dzn_locator(dzn_locator)
, state(::LED::LedState::Green)

, iLed({{"iLed",this,&dzn_meta},{"",0,0}})



{
  dzn_rt.performs_flush(this) = true;

  iLed.in.setGreen = [&](){return dzn::call_in(this,[=]{ return iLed_setGreen();}, this->iLed.meta, "setGreen");};
  iLed.in.setYellow = [&](){return dzn::call_in(this,[=]{ return iLed_setYellow();}, this->iLed.meta, "setYellow");};
  iLed.in.setRed = [&](){return dzn::call_in(this,[=]{ return iLed_setRed();}, this->iLed.meta, "setRed");};





}

void LED::iLed_setGreen()
{
  if (true) state = ::LED::LedState::Green;
  else if ((!(true) && true)) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void LED::iLed_setYellow()
{
  if (true) state = ::LED::LedState::Green;
  else if ((!(true) && true)) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void LED::iLed_setRed()
{
  if (true) state = ::LED::LedState::Green;
  else if ((!(true) && true)) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}


void LED::check_bindings() const
{
  dzn::check_bindings(&dzn_meta);
}
void LED::dump_tree(std::ostream& os) const
{
  dzn::dump_tree(os, &dzn_meta);
}




//version: 2.8.2