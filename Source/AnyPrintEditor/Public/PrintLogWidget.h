// Copyright 2025 G3N7AX. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Fonts/SlateFontInfo.h"
#include "EditorUtilityWidget.h"
#include "PrintLogWidget.generated.h"

/**
 * This is the base Editor Utility Widget that displays each log made
 */

UCLASS()
class ANYPRINTEDITOR_API UPrintLogWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

	// ====================================
	// Function Overrides
	// ====================================
	
	virtual void NativeConstruct() override;
	
	// ====================================
	// Private UProperty Variables
	// ====================================

	UPROPERTY()
	UTextBlock* LogEntryText;

	UPROPERTY()
	FSlateFontInfo FontInfo;
	
	// ====================================
	// Private Functions
	// ====================================

	static float GetTextSize();
	void UpdateLog();

	// ====================================
	// Private UFunctions
	// ====================================

	UFUNCTION()
	void OnLogUpdatedHandler();


protected:
	
	// ====================================
	// Protected UProperty Variables
	// ====================================

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category="UMG")
	UScrollBox* LogScrollBox;

	/* This is here to implement the TextSize OnCommitted in the future */
	// UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category="UMG")
	// UEditableTextBox* TextSizeInput;

	// ====================================
	// Protected UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category="UMG")
	void SetTextSize(const FString& TextSizeIn);
	
};
