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
#include "Sensor.hh"

#include <dzn/locator.hh>
#include <dzn/runtime.hh>



Sensor::Sensor(const dzn::locator& dzn_locator)
: dzn_meta{"","Sensor",0,0,{},{},{[this]{iSensor.check_bindings();}}}
, dzn_rt(dzn_locator.get<dzn::runtime>())
, dzn_locator(dzn_locator)


, iSensor({{"iSensor",this,&dzn_meta},{"",0,0}})



{
  dzn_rt.performs_flush(this) = true;

  iSensor.in.turnOn = [&](){return dzn::call_in(this,[=]{ return iSensor_turnOn();}, this->iSensor.meta, "turnOn");};
  iSensor.in.turnOff = [&](){return dzn::call_in(this,[=]{ return iSensor_turnOff();}, this->iSensor.meta, "turnOff");};





}

void Sensor::iSensor_turnOn()
{
  if (true) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void Sensor::iSensor_turnOff()
{
  if (true) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}


void Sensor::check_bindings() const
{
  dzn::check_bindings(&dzn_meta);
}
void Sensor::dump_tree(std::ostream& os) const
{
  dzn::dump_tree(os, &dzn_meta);
}




//version: 2.8.2