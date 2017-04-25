/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

// the intersection function is based on Sphere Cone intersection test described in Geometric tools 
// by Philip J. Schneider and David H. Eberly, 
// The Morgan Kaufmann Series in Computer Graphics and Geometric Modeling
// http://www.geometrictools.com/Documentation/IntersectionSphereCone.pdf


#include "DXUT.h"
BOOL SphereConeTest ( D3DXVECTOR3 sphereCenter, float radius, float fov, D3DXVECTOR3 eyePt, D3DXVECTOR3 lookAt)
{
	float fSin = sinf(fov);
	float fCos = cosf(fov);
	float fInvSin = 1.0f/fSin;
	float fCosSqr = fCos*fCos;
	float fSinSqr = fSin*fSin;
	D3DXVECTOR3 vAxis = lookAt - eyePt;

	D3DXVECTOR3 vCmV =  sphereCenter - eyePt;
	D3DXVECTOR3 vD = vCmV + (radius*fInvSin)*vAxis;
	float fDSqrLen = D3DXVec3Dot(&vD, &vD);
	float fE = D3DXVec3Dot(&vD,&vAxis);
	if (fE > 0.0f && fE*fE >= fDSqrLen*fCosSqr)
	{
		fDSqrLen = D3DXVec3Dot(&vCmV, &vCmV);
		fE = -D3DXVec3Dot(&vCmV, &vAxis);
		if (fE > 0.0f && fE*fE >= fDSqrLen*fSinSqr)
		{
			float fRSqr = radius*radius;
			return fDSqrLen <= fRSqr;
		}
		return TRUE;
	}
	return FALSE;
}
