// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AnyPrintEditor : ModuleRules
{
	public AnyPrintEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		// Public include paths should point to actual directories
		PublicIncludePaths.AddRange(
			new string[] {
				System.IO.Path.Combine(ModuleDirectory, "../AnyPrint/Public")  // Reference AnyPrint's Public headers
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// Private include paths
			}
		);
			
		// Public Dependencies
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UMG",
				"AnyPrint"  // Move AnyPrint here if used in headers
			}
		);
		
		// Private Dependencies
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				"Blutility",
				"EditorStyle",
				"UnrealEd"
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}