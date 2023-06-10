#include "NewppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
NewppApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

NewppApp::NewppApp(InputParameters parameters) : MooseApp(parameters)
{
  NewppApp::registerAll(_factory, _action_factory, _syntax);
}

NewppApp::~NewppApp() {}

void 
NewppApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<NewppApp>(f, af, s);
  Registry::registerObjectsTo(f, {"NewppApp"});
  Registry::registerActionsTo(af, {"NewppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
NewppApp::registerApps()
{
  registerApp(NewppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
NewppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  NewppApp::registerAll(f, af, s);
}
extern "C" void
NewppApp__registerApps()
{
  NewppApp::registerApps();
}
