// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoorRoom1.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_CM_API UOpenDoorRoom1 : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	float OpenAngle;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	APointLight *PointLight = nullptr;

	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
	float Delay = 1.0f;

	float LastDoorOpenTime;

	float GetTotalMassOfActors();

public:	
	// Sets default values for this component's properties
	UOpenDoorRoom1();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	void CloseDoor();
	
	
};
