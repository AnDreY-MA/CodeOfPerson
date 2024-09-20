#pragma once

#include "CoreMinimal.h"
#include "CombatSystemAssetManager.h"
#include "CodePersonAssetManager.generated.h"


UCLASS()
class CODEOFPERSON_API UCodePersonAssetManager : public UCombatSystemAssetManager
{
	GENERATED_BODY()

public:
	static UCodePersonAssetManager& Get();

};