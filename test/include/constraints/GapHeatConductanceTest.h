//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADMortarConstraint.h"

template <ComputeStage compute_stage>
class GapHeatConductanceTest : public ADMortarConstraint<compute_stage>
{
public:
  static InputParameters validParams();

  GapHeatConductanceTest(const InputParameters & parameters);

protected:
  ADReal computeQpResidual(Moose::MortarType mortar_type) final;

  const ADMaterialProperty(Real) & _slave_gap_conductance;
  const ADMaterialProperty(Real) & _master_gap_conductance;

  usingMortarConstraintMembers;
};
