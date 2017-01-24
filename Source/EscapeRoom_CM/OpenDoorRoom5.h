// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoorRoom5.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_CM_API UOpenDoorRoom5 : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		float OpenAngle;

	bool trigger1;
	bool trigger2;
	bool trigger3;
	bool trigger4;
	bool trigger5;
	bool trigger6;
	bool trigger7;

	UPROPERTY(EditAnywhere)
		AActor *Plate1 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate2 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate3 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate4 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate5 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate6 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate7 = nullptr;

	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight1 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight2 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight3 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight4 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight5 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight6 = nullptr;
	UPROPERTY(EditAnywhere)
		ASpotLight *SpotLight7 = nullptr;

	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;

	float GetTotalMassOfActors(AActor *Pressure);

public:	
	// Sets default values for this component's properties
	UOpenDoorRoom5();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

	void CloseDoor();
	
};
