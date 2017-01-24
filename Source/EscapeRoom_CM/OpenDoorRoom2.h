// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoorRoom2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_CM_API UOpenDoorRoom2 : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		float OpenAngle;

	bool trigger1;
	bool trigger2;
	bool trigger3;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate3 = nullptr;

	UPROPERTY(EditAnywhere)
		APointLight *PointLight1 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLight2 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLight3 = nullptr;

	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;

	float GetTotalMassOfActors(ATriggerVolume *Pressure);

public:	
	// Sets default values for this component's properties
	UOpenDoorRoom2();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	void CloseDoor();
	
};
