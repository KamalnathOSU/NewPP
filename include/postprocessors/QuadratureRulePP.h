#pragma once

#include "ElementPostprocessor.h"
#include "libmesh/quadrature.h"

class QuadratureRulePP : public ElementPostprocessor
{
public:
  static InputParameters validParams();

  QuadratureRulePP(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual void finalize() override;
  virtual Real getValue() override;

  void threadJoin(const UserObject & y) override;

protected:

  /// _type of extremum to be calculated
  MooseEnum _type;

  /// value held by postprocessor
  Real  _extreme_value;
};
