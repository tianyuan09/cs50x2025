#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index (round())
    int grade = round(0.0588 * (float) letters / (float) words * 100.0 -
                      0.296 * (float) sentences / (float) words * 100.0 - 15.8);
    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 16)
    {
        printf("Grade %d\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // check if a character is a letter (either uppercase or lowercase)
        // and exclude digits, symbols, or whitespace.
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    // Return the number of letters in text
    return count;
}

int count_words(string text)
{
    // first letter not space in a sentence.
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        // check if a character is a space.
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // Return the number of words in text
    return count;
}

// a sentence will contain at least one word; will not start or end with a space ...
int count_sentences(string text)
{
    // split by .
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // check if a character is a space.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    // Return the number of sentences in text
    return count;
}
