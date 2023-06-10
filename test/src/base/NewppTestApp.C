//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "NewppTestApp.h"
#include "NewppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
NewppTestApp::validParams()
{
  InputParameters params = NewppApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

NewppTestApp::NewppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  NewppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

NewppTestApp::~NewppTestApp() {}

void
NewppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  NewppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"NewppTestApp"});
    Registry::registerActionsTo(af, {"NewppTestApp"});
  }
}

void
NewppTestApp::registerApps()
{
  registerApp(NewppApp);
  registerApp(NewppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
NewppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  NewppTestApp::registerAll(f, af, s);
}
extern "C" void
NewppTestApp__registerApps()
{
  NewppTestApp::registerApps();
}
