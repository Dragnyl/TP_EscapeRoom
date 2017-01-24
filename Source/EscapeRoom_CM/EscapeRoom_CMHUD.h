// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "EscapeRoom_CMHUD.generated.h"

UCLASS()
class AEscapeRoom_CMHUD : public AHUD
{
	GENERATED_BODY()

public:
	AEscapeRoom_CMHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

