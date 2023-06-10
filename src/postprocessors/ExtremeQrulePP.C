
#include "ExtremeQrulePP.h"

registerMooseObject("NewppApp", ExtremeQrulePP);

InputParameters
ExtremeQrulePP::validParams()
{
  InputParameters params = ElementPostprocessor::validParams();
  params.addParam<Real>("value", 0, "The value");

  params.addClassDescription("Postprocessor that holds a constant value");
  return params;
}

ExtremeQrulePP::ExtremeQrulePP(const InputParameters & params)
  : ElementPostprocessor(params)
{
}

void
ExtremeQrulePP::initialize()
{
	_extreme_value = 0;
}

void
ExtremeQrulePP::execute()
{
	if( _extreme_value < _qrule->n_points() )
		_extreme_value = (double)_qrule->n_points() ;
}

void
ExtremeQrulePP::finalize()
{
	gatherMax(_extreme_value);
}

void
ExtremeQrulePP::threadJoin(const UserObject & y)
{
	const ExtremeQrulePP & pps = static_cast<const ExtremeQrulePP &>(y);
	if(_extreme_value < pps._extreme_value)
			_extreme_value = pps._extreme_value;
}

Real
ExtremeQrulePP::getValue()
{
  return _extreme_value;
}
