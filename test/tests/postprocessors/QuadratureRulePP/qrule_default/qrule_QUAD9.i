[Mesh]
        [gmg]
            type = GeneratedMeshGenerator
            dim = 2
            nx = 4
            ny = 4
            elem_type = QUAD9
        []
[]

[Variables/u]
        order = FIRST
        family = LAGRANGE
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
        [qrule]
                type = QuadratureRulePP
        []
[]
