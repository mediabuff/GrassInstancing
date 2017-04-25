/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "DXUT.h"


class camera{
public:
	camera();
	camera(const camera *src);
	camera(D3DXVECTOR3 pos, float rotx, float roty, float rotz, float fov, float aspect, float nearz, float farz);
	~camera();
	void update();
	void update_lookat();
	void debugger();
	D3DXVECTOR3* GetEyePt(){ return &position; }; // for compatibility with DXCamera Classes 
	D3DXVECTOR3* GetLookAtPt() { lookAt = position+forward; return &lookAt; };  // for compatibility with DXCamera Classes 
	D3DXVECTOR3 position;
	D3DXVECTOR3 forward,up,right, lookAt;
	float fov, aspect,znear, zfar, rotx, roty, rotz;
	D3DXMATRIXA16 view, invview, proj, invproj, viewproj, invviewproj;
};