#pragma once

#include "..\Material.h"
#include "..\..\..\..\..\Utils\Math\Vector2D.h"
#include "..\..\..\Renderer\Lights\Light.h"

template<size_t lightCount>
class LightMaterial : public Material {
private:
    Light lights[lightCount];

public:
    LightMaterial();

    RGBColor GetRGB(Vector3D position, Vector3D normal, Vector3D uvw) override;
};
