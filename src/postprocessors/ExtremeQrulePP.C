//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ExtremeQrulePP.h"

registerMooseObject("NewppApp", ExtremeQrulePP);

InputParameters
ExtremeQrulePP::validParams()
{
  InputParameters params = GeneralPostprocessor::validParams();
  params.addParam<Real>("value", 0, "The value");
  params.declareControllable("value");

  params.addClassDescription("Postprocessor that holds a constant value");
  return params;
}

ExtremeQrulePP::ExtremeQrulePP(const InputParameters & params)
  : GeneralPostprocessor(params), _value(getParam<Real>("value"))
{
}

Real
ExtremeQrulePP::getValue()
{
  return _value;
}
