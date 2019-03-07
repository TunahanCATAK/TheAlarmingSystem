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
#include "Timer.hh"

#include <dzn/locator.hh>
#include <dzn/runtime.hh>



Timer::Timer(const dzn::locator& dzn_locator)
: dzn_meta{"","Timer",0,0,{},{},{[this]{iTimer.check_bindings();}}}
, dzn_rt(dzn_locator.get<dzn::runtime>())
, dzn_locator(dzn_locator)


, iTimer({{"iTimer",this,&dzn_meta},{"",0,0}})



{
  dzn_rt.performs_flush(this) = true;

  iTimer.in.start = [&](long milliseconds){return dzn::call_in(this,[=]{ return iTimer_start(milliseconds);}, this->iTimer.meta, "start");};
  iTimer.in.cancel = [&](){return dzn::call_in(this,[=]{ return iTimer_cancel();}, this->iTimer.meta, "cancel");};





}

void Timer::iTimer_start(long milliseconds)
{
  if (true) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void Timer::iTimer_cancel()
{
  if (true) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}


void Timer::check_bindings() const
{
  dzn::check_bindings(&dzn_meta);
}
void Timer::dump_tree(std::ostream& os) const
{
  dzn::dump_tree(os, &dzn_meta);
}




//version: 2.8.2