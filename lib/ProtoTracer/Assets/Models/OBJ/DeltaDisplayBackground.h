#pragma once

#include "..\..\..\Scene\Materials\Static\SimpleMaterial.h"
#include "..\..\..\Scene\Objects\Object3D.h"

class DeltaDisplayBackground{
private:
	Vector3D basisVertices[4] = {Vector3D(290.0000f,-20.0000f,500.0000f),Vector3D(290.0000f,100.0000f,500.0000f),Vector3D(200.0000f,100.0000f,500.0000f),Vector3D(200.0000f,-20.0000f,500.0000f)};
	IndexGroup basisIndexes[2] = {IndexGroup(0, 1, 2), IndexGroup(0, 2, 3)};
	TriangleGroup triangleGroup = TriangleGroup(&basisVertices[0], &basisIndexes[0], 4, 2);
	SimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));
	Object3D basisObj = Object3D(&triangleGroup, &simpleMaterial);

public:
	DeltaDisplayBackground(){}

	Object3D* GetObject(){
		return &basisObj;
	}

    void Reset(){
        basisObj.ResetVertices();
    }
};
