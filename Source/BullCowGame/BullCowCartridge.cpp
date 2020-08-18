// Fill out your copyright notice in the Description page of Project Settingss.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
    PrintLine(TEXT("Hidden Word là: %s"), *HiddenWord); //Debug line
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Won!"));
            EndGame();
        }
        else
        {
            --Lives;
            PrintLine(TEXT("Mat 1 mang!"));
            PrintLine(TEXT("%i"), Lives);
            if (Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Ban da doan sai, hay thu lai lan nua! Ban con %i mang!"), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("Het mang roi! Ban da thua roi!"));
                EndGame();
            }
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Chao mung toi game Trau Bo Dai Chien"));

    HiddenWord = "cakes";
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Doan %i ki tu"), HiddenWord.Len());
    PrintLine(TEXT("Nhap vao tu ban doan va nhan Enter de tiep tuc..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again!"));
}