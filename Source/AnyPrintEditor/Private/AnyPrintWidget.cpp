// Copyright 2025 G3N7AX. Licensed under the MIT License.

#include "AnyPrintWidget.h"
#include "AnyPrintLibrary/Public/AnyPrintFunctionLibrary.h"

// ====================================
// Declare Variables
// ====================================

TArray<FLogEntry> LogEntries;
bool bShowTimeStamps;
float FTargetTextSize = 12.f;

// ====================================
// Overriden Functions
// ====================================

/* Called once when the widget is instantiated */
void UAnyPrintWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

/* Called every time the widget is recompiled */
void UAnyPrintWidget::NativePreConstruct()
{
	/* Run the parent code before ours */
	Super::NativePreConstruct();

	/* Convert float FTargetTextSize to FText TTargetTextSize because the Editable Text Field only sends out FText */
	FText TTargetTextSize = FText::AsNumber(FTargetTextSize);
	
	/* Update the LogEntries */
	PrintLogEntries();
}

/* Called every time the widget is run */
void UAnyPrintWidget::NativeConstruct()
{
	/* Run the parent code before ours */
	Super::NativeConstruct();

	/* Binds the listeners */
	UAnyPrintFunctionLibrary::OnLogUpdated.AddDynamic(this, &UAnyPrintWidget::OnLogUpdatedHandler);
	UAnyPrintFunctionLibrary::OnEmptyLog.AddDynamic(this, &UAnyPrintWidget::OnEmptyLogHandler);
}

// ====================================
// Listener Functions
// ====================================

/* This is the listener for OnLogUpdated.Broadcast */
void UAnyPrintWidget::OnLogUpdatedHandler()
{
	/* Get the LogEntries from the AnyPrintLibrary when the listener gets a log */
	LogEntries = UAnyPrintFunctionLibrary::GetLogEntries();

	/* Print the logs when the listener gets a log */
	PrintLogEntries();
}

/* This is the listener for OnEmptyLog.Broadcast */
void UAnyPrintWidget::OnEmptyLogHandler()
{
	/* Clear the PrintLog Widget of all LogEntryTextBlocks */
	LogScrollBox->ClearChildren();
}

// ====================================
// Private Functions
// ====================================

/* Sets the Text Size of the LogEntryTextBlock by converting FText to a Float */
void UAnyPrintWidget::SetTextSize(FText TextSize)
{
	/* Convert FText TextSize to a String and then to a Float for the FontInfo */
	FTargetTextSize = FCString::Atof(*TextSize.ToString());

	/* Update the LogEntries */
	PrintLogEntries();
}

// ====================================
// Public Functions
// ====================================

/* This is the primary function for printing the logs in the PrintLog Widget */
void UAnyPrintWidget::PrintLogEntries()
{
	/* Check if LogScrollBox exists */
	if (!LogScrollBox)
	{
		/* If LogScrollBox does not exist, log that it doesn't exist and break out of the functions */
		UE_LOG(LogTemp, Error, TEXT("LogScrollBox is does not exist"));
		return;
	}

	/* Clear all the previous children (the LogEntryTextBlocks */
	LogScrollBox->ClearChildren();

	/* For Loop for each LogEntry in LogEntries */
	for (const FLogEntry& LogEntry : LogEntries)
	{
		/* Create a new instance of the LogEntryTextBlock */
		LogEntryTextBlock = NewObject<UTextBlock>(this);

		/* if the LogEntryTextBlock is valid */
		if (LogEntryTextBlock)
		{
			/* Set the text size */
			FontInfo = LogEntryTextBlock->GetFont();
			FontInfo.Size = FTargetTextSize;
			LogEntryTextBlock->SetFont(FontInfo);

			/* Set the Log Text to the LogEntry or the Sliced LogEntry given the value of bShowTimestamps in AnyPrintSettings */
			FString LogEntryText = bShowTimeStamps ? LogEntry.LogEntry : LogEntry.LogEntry.RightChop(10);

			/* Set the Text of the LogEntryTextBlock to the FString converted to FText */
			LogEntryTextBlock->SetText(FText::FromString(LogEntryText));

			/* Set log text color using the FLogEntry Structure */
			LogEntryTextBlock->SetColorAndOpacity(FSlateColor(LogEntry.LogColor));

			/* Add it to the LogScrollBox to be displayed */
			LogScrollBox->AddChild(LogEntryTextBlock);
		}
	}

	/* Scroll to the bottom of the LogScrollBox */
	LogScrollBox->ScrollToEnd();
}

/* Used for the UMG Checkbox to show / hide the timestamps by changing the value in the ini file */
void UAnyPrintWidget::SetShowTimestamps(bool ShowTimestampsValue)
{
	/* Changes bShowTimestamps to the ShowTimestampsValue (the value of the CheckBox) */
	bShowTimeStamps = ShowTimestampsValue;

	/* Update the LogEntries */
	PrintLogEntries();
}
