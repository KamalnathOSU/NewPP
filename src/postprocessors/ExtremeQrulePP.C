
#include "ExtremeQrulePP.h"

registerMooseObject("NewppApp", ExtremeQrulePP);

InputParameters
ExtremeQrulePP::validParams()
{
  InputParameters params = ElementPostprocessor::validParams();
  MooseEnum extremum_type("min max","max");
  params.addParam<MooseEnum>("value_type", extremum_type,
                             "Type of extreme value to return. 'max' "
                             "returns the maximum value. 'min' returns "
                             "the minimum value.");
  params.addClassDescription("Postprocessor that calculate the Extremum (max or min) value of the Quadrature rule in the mesh/block.");
  return params;
}

ExtremeQrulePP::ExtremeQrulePP(const InputParameters & params)
  : ElementPostprocessor(params),
	_type(getParam<MooseEnum>("value_type"))
{
}

void
ExtremeQrulePP::initialize()
{
	if(_type == "max")
		_extreme_value = 0;
	else if (_type == "min")
		_extreme_value = 10000; // Extremely unlikely to have elements with 10,000 quadrature points !
	else
		_extreme_value = -1; // Program should never reach here
}

void
ExtremeQrulePP::execute()
{
	if( _type == "max" )
	{
		if( _extreme_value < _qrule->n_points() )
			_extreme_value = (double)_qrule->n_points() ;
	}
	else if ( _type == "min" )
	{
		if( _extreme_value > _qrule->n_points() )
			_extreme_value = (double)_qrule->n_points() ;
	}
}

void
ExtremeQrulePP::finalize()
{
	if( _type == "max" )
		gatherMax(_extreme_value);
	else if( _type == "min" )
		gatherMin(_extreme_value);
}

void
ExtremeQrulePP::threadJoin(const UserObject & y)
{
	const ExtremeQrulePP & pps = static_cast<const ExtremeQrulePP &>(y);
	if( _type == "max" && _extreme_value < pps._extreme_value)
			_extreme_value = pps._extreme_value;
	if( _type == "min" && _extreme_value > pps._extreme_value)
			_extreme_value = pps._extreme_value;
}

Real
ExtremeQrulePP::getValue()
{
  return _extreme_value;
}

