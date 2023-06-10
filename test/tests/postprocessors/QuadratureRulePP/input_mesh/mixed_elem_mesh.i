[Mesh]
    [fmg]
    type = FileMeshGenerator
    file = 'mixed_elem_mesh.e'
    []
    [extrude]
    type = AdvancedExtruderGenerator
    input = fmg
    heights = '3 3'
    num_layers = '3 3'
    direction = '0 0 1'
    []
[]

[Variables/u]
[]

[Kernels]
        [diffusion]
                type = Diffusion
                variable = u
        []
[]

[Executioner]
        type = Steady
[]

[Outputs]
        exodus = true
[]

[Postprocessors]
        [qrule_min]
                type = QuadratureRulePP
                value_type = min
        []
        [qrule_max]
                type = QuadratureRulePP
                value_type = max
        []
[]
