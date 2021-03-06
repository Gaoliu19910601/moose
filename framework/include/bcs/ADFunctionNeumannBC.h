//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADIntegratedBC.h"

template <ComputeStage>
class ADFunctionNeumannBC;
class Function;

declareADValidParams(ADFunctionNeumannBC);

/**
 * Boundary condition of a Neumann style whose value is computed by a user-defined function
 */
template <ComputeStage compute_stage>
class ADFunctionNeumannBC : public ADIntegratedBC<compute_stage>
{
public:
  static InputParameters validParams();

  ADFunctionNeumannBC(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;

  /// The function being used for setting the value
  const Function & _func;

  usingIntegratedBCMembers;
};
