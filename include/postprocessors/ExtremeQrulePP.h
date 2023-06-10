#pragma once

#include "ElementPostprocessor.h"
#include "libmesh/quadrature.h"

class ExtremeQrulePP : public ElementPostprocessor
{
public:
  static InputParameters validParams();

  ExtremeQrulePP(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual void finalize() override;
  virtual Real getValue() override;

  void threadJoin(const UserObject & y) override;

protected:
  /// value held by postprocessor
  Real  _extreme_value;
};
