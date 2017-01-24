// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoorRoom3.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_CM_API UOpenDoorRoom3 : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float OpenAngle;

	FString combinaison;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate3 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate4 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlateReset = nullptr;


	UPROPERTY(EditAnywhere)
		APointLight *PointLight1 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLight2 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLight3 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLight4 = nullptr;
	UPROPERTY(EditAnywhere)
		APointLight *PointLightReset = nullptr;

	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;
	float increment;

	bool CheckProjectile(ATriggerVolume *Pressure);

public:	
	// Sets default values for this component's properties
	UOpenDoorRoom3();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	void CloseDoor();
	
	void Reset();
};
