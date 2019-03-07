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
#include "AlarmingSystem.hh"

#include <dzn/locator.hh>
#include <dzn/runtime.hh>


//SYSTEM

AlarmingSystem::AlarmingSystem(const dzn::locator& dzn_locator)
: dzn_meta{"","AlarmingSystem",0,0,{},{& controller.dzn_meta,& led.dzn_meta,& sensor.dzn_meta,& siren.dzn_meta,& timer.dzn_meta},{[this]{iController.check_bindings();}}}
, dzn_rt(dzn_locator.get<dzn::runtime>())
, dzn_locator(dzn_locator)


, controller(dzn_locator)
, led(dzn_locator)
, sensor(dzn_locator)
, siren(dzn_locator)
, timer(dzn_locator)

, iController(controller.iController)

{


  controller.dzn_meta.parent = &dzn_meta;
  controller.dzn_meta.name = "controller";
  led.dzn_meta.parent = &dzn_meta;
  led.dzn_meta.name = "led";
  sensor.dzn_meta.parent = &dzn_meta;
  sensor.dzn_meta.name = "sensor";
  siren.dzn_meta.parent = &dzn_meta;
  siren.dzn_meta.name = "siren";
  timer.dzn_meta.parent = &dzn_meta;
  timer.dzn_meta.name = "timer";


  connect(led.iLed, controller.iLed);
  connect(sensor.iSensor, controller.iSensor);
  connect(siren.iSiren, controller.iSiren);
  connect(timer.iTimer, controller.iTimer);

  dzn::rank(iController.meta.provides.meta, 0);

}

void AlarmingSystem::check_bindings() const
{
  dzn::check_bindings(&dzn_meta);
}
void AlarmingSystem::dump_tree(std::ostream& os) const
{
  dzn::dump_tree(os, &dzn_meta);
}

////////////////////////////////////////////////////////////////////////////////



//version: 2.8.2