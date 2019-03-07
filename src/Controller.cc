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
#include "Controller.hh"

#include <dzn/locator.hh>
#include <dzn/runtime.hh>



Controller::Controller(const dzn::locator& dzn_locator)
: dzn_meta{"","Controller",0,0,{& iLed.meta,& iSensor.meta,& iSiren.meta,& iTimer.meta},{},{[this]{iController.check_bindings();},[this]{iLed.check_bindings();},[this]{iSensor.check_bindings();},[this]{iSiren.check_bindings();},[this]{iTimer.check_bindings();}}}
, dzn_rt(dzn_locator.get<dzn::runtime>())
, dzn_locator(dzn_locator)
, state(::Controller::State::Unarmed)

, iController({{"iController",this,&dzn_meta},{"",0,0}})

, iLed({{"",0,0},{"iLed",this,&dzn_meta}})
, iSensor({{"",0,0},{"iSensor",this,&dzn_meta}})
, iSiren({{"",0,0},{"iSiren",this,&dzn_meta}})
, iTimer({{"",0,0},{"iTimer",this,&dzn_meta}})


{
  dzn_rt.performs_flush(this) = true;

  iController.in.validPinCode = [&](){return dzn::call_in(this,[=]{ return iController_validPinCode();}, this->iController.meta, "validPinCode");};
  iSensor.out.triggered = [&](){return dzn::call_out(this,[=]{ return iSensor_triggered();}, this->iSensor.meta, "triggered");};
  iTimer.out.timeout = [&](){return dzn::call_out(this,[=]{ return iTimer_timeout();}, this->iTimer.meta, "timeout");};





}

void Controller::iController_validPinCode()
{
  if ((state == ::Controller::State::Unarmed && true)) 
  {
    state = ::Controller::State::Armed;
    this->iLed.in.setYellow();
    this->iSensor.in.turnOn();
  }
  else if ((state == ::Controller::State::Armed && true)) 
  {
    this->iSensor.in.turnOff();
    state = ::Controller::State::Unarmed;
    this->iLed.in.setGreen();
  }
  else if ((state == ::Controller::State::Alarming && true)) 
  {
    this->iSensor.in.turnOn();
    state = ::Controller::State::Armed;
    this->iLed.in.setYellow();
    this->iTimer.in.cancel();
    this->iSiren.in.turnOff();
  }
  else if ((!((state == ::Controller::State::Alarming && true)) && (!((state == ::Controller::State::Armed && true)) && (!((state == ::Controller::State::Unarmed && true)) && true)))) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void Controller::iSensor_triggered()
{
  if ((state == ::Controller::State::Armed && true)) 
  {
    this->iSensor.in.turnOff();
    state = ::Controller::State::Alarming;
    this->iLed.in.setRed();
    this->iTimer.in.start(30000);
  }
  else if ((state == ::Controller::State::Alarming && true)) dzn_locator.get<dzn::illegal_handler>().illegal();
  else if ((!((state == ::Controller::State::Alarming && true)) && (!((state == ::Controller::State::Armed && true)) && true))) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}
void Controller::iTimer_timeout()
{
  if ((state == ::Controller::State::Alarming && true)) 
  {
    this->iSiren.in.turnOn();
  }
  else if ((!((state == ::Controller::State::Alarming && true)) && true)) dzn_locator.get<dzn::illegal_handler>().illegal();
  else dzn_locator.get<dzn::illegal_handler>().illegal();

  return;

}


void Controller::check_bindings() const
{
  dzn::check_bindings(&dzn_meta);
}
void Controller::dump_tree(std::ostream& os) const
{
  dzn::dump_tree(os, &dzn_meta);
}




//version: 2.8.2