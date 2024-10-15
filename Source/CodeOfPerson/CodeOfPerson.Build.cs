// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CodeOfPerson : ModuleRules
{
	public CodeOfPerson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", 
			"CombatAbilitiesSystem", "CombatEnemySystem", "MamontUI", "AnimGraphRuntime", "GameplayTags", "GameplayAbilities", "CommonInput", "Niagara", "NiagaraCore", "AIModule"});

		PrivateDependencyModuleNames.AddRange(new string[] { "ModularGameplay", "GameFeatures", "UMG" });
	}
}
