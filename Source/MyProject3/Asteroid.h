// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class MYPROJECT3_API AAsteroid : public AActor
{
  GENERATED_BODY()
  
public:
  // Sets default values for this actor's properties
  AAsteroid();
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatingActor")
  float FloatSpeed = 20.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatingActor")
  float RotationSpeed = 20.0f;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatingActor")
  float MovementSpeed = 5.0f;
  
  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent* VisualMesh;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatingActor")
  int Iteration = 1;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatingActor")
  float TimeToSpawn = 1.0f;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

};
