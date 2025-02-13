// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Ch3_2_Task : ModuleRules
{
	public NBC_Ch3_2_Task(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
	}
}
