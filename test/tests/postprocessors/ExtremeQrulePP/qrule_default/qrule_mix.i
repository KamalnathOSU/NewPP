[Mesh]
        [gmg1]
            type = GeneratedMeshGenerator
            dim = 2
            nx = 4
            ny = 4
            elem_type = QUAD9
            xmin = 0
            ymin = 0
            xmax = 1
            ymax = 1
        []

        [gmg2]
            type = GeneratedMeshGenerator
            dim = 2
            nx = 4
            ny = 4
            elem_type = QUAD9
            xmin = 2
            ymin = 0
            xmax = 3
            ymax = 1
        []

        [finalmesh]
                type = CombinerGenerator
                inputs = 'gmg1 gmg2'
        []

        [spilt1]
                type = SubdomainBoundingBoxGenerator
                bottom_left = '-0.1 -0.1 0'
                top_right = '1.1 1.1 0'
                input = 'finalmesh'
                block_id = 1
                location = OUTSIDE
        []
[]

[Variables]
        [u1]
            order = FIRST
            family = LAGRANGE
            block = 0
        []
        [u2]
            order = SECOND
            family = LAGRANGE
            block = 1
        []
[]

[Kernels]
        [diffusion1]
                type = Diffusion
                variable = u1
        []
        [diffusion2]
                type = Diffusion
                variable = u2
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
                type = ExtremeQrulePP
                value_type = min
        []
        [qrule_max]
                type = ExtremeQrulePP
                value_type = max
        []
[]
