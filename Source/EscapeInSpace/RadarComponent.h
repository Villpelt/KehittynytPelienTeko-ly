// copyright anssi.grohn@karelia.fi 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RadarComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEINSPACE_API URadarComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URadarComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		TArray<FVector2D> GetPointsOnPlane();

	UFUNCTION(BlueprintCallable)
		void UpdateTrackedObjects();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> trackedObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxRadarDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> RealDistanceToTrackedObjects;

	UFUNCTION(BlueprintCallable)
		float GetRealDistanceToTrackeObjects(int32 index);
};
