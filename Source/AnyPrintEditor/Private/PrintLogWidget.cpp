// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintLogWidget.h"
#include "DebugFunctionLibrary.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

TArray<FString> LogEntries;
TArray<UTextBlock> LogEntryWidgets;
float TextSize = 12.f;

void UPrintLogWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/* Bind the Caller and the Listener */
	UDebugFunctionLibrary::OnLogUpdated.AddDynamic(this, &UPrintLogWidget::OnLogUpdatedHandler);
}

// ====================================
// Event Dispatcher Listener
// ====================================

void UPrintLogWidget::OnLogUpdatedHandler()
{
	/* Get the LogEntries from the FunctionLibrary */
	LogEntries = UDebugFunctionLibrary::GetLogEntries();

	/* Clear all the logs from the LogScrollBox to update them */
	LogScrollBox->ClearChildren();

	/* Loop through each LogEntry in the LogEntries[] */
	for (const FString LogEntry : LogEntries)
	{
		/* Create a TextBlock in the LogScrollBox for each LogEntry */
		LogEntryText = NewObject<UTextBlock>(this);

		/* Set the TextSize */
		FontInfo = LogEntryText->GetFont();
		FontInfo.Size = GetTextSize();
		LogEntryText->SetFont(FontInfo);

		if (LogEntryText)
		{
			/* Add the widgets to the LogScrollBox */
			LogEntryText->SetText(FText::FromString(LogEntry));
			LogScrollBox->AddChild(LogEntryText);

			/* Scroll to the end (The eliminates some issues when there are a lot of logs) */
			LogScrollBox->ScrollToEnd();
		}
	}
}

// ====================================
// Helper Functions
// ====================================

/* Getter function for the TextSize */
float UPrintLogWidget::GetTextSize()
{
	return TextSize;
}

/* Setter function for the TextSize */
void UPrintLogWidget::SetTextSize(FString TextSizeIn)
{
	/* Check if the input from the EditableTextBox is a number */
	if (TextSizeIn.IsNumeric())
	{
		/* If it is, convert it to a float and assign it to the TextSize */
		TextSize = FCString::Atof(*TextSizeIn);

		/* Check if the LogEntries[] is empty */
		if (LogEntries.IsEmpty())
		{
			/* If it is, just update the FontInfo so that the logs are set to the correct size in the future */
			LogEntryText->SetFont(FontInfo);
		}
		
		else
		{
			/* If it isn't, update the log with the new TextSize */
			UpdateLog();
		}
	}
}

void UPrintLogWidget::UpdateLog()
{
	/* Call the listener to reset the log */
	UDebugFunctionLibrary::OnLogUpdated.Broadcast();
}