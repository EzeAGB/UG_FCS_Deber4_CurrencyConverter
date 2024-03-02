#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define INPUT_MAX_CHAR 8
#define CURRENCY_ISO_MAX_CHAR 3
#define USA_DOLLAR_ISO "USD"
#define GTM_QUETZAL_ISO "GTQ"
#define EU_EURO_ISO "EUR"
#define USD_TO_GTQ 0.127938917f
#define EUR_TO_GTQ 0.117887803f
#define USD_TO_EUR 1.085187190f

typedef enum {
    CURRENCY_ISO_USD = 0,
    CURRENCY_ISO_EUR = 1,
    CURRENCY_ISO_GTQ = 2,
    CURRENCY_ISO_MAX = 3
} CurrencyISO;

int32_t main()
{
    CurrencyISO currencyFromISO = CURRENCY_ISO_MAX;
    CurrencyISO currencyToISO = CURRENCY_ISO_MAX;
    float value = 0.0f;

    // Loop until we get a valid input.
    while (true)
    {
        // Get currencies ISO.
        printf("Write currencies ISO (format: ISO-ISO): ");
        char fromToCurrency[INPUT_MAX_CHAR];
        fgets(fromToCurrency, INPUT_MAX_CHAR, stdin);
        getchar();

        // Check if input might be invalid.
        if (fromToCurrency[3] != '-')
        {
            printf("Format must be ISO-ISO. Where ISO must be USD, EUR or GTQ.\n");
            continue;
        }

        // Convert strings to CurrencyISO enum. For easier usage.
        char currencyA[CURRENCY_ISO_MAX_CHAR + 1] = { fromToCurrency[0], fromToCurrency[1], fromToCurrency[2], '\0'};
        char currencyB[CURRENCY_ISO_MAX_CHAR + 1] = { fromToCurrency[4], fromToCurrency[5], fromToCurrency[6], '\0'};
        {
            if (strcmp(currencyA, USA_DOLLAR_ISO) == 0)
            {
                currencyFromISO = CURRENCY_ISO_USD;
            }
            else if (strcmp(currencyA, EU_EURO_ISO) == 0)
            {
                currencyFromISO = CURRENCY_ISO_EUR;
            }
            else if (strcmp(currencyA, GTM_QUETZAL_ISO) == 0)
            {
                currencyFromISO = CURRENCY_ISO_GTQ;
            }
            else
            {
                printf("Currency A ISO is invalid. Must be USD, EUR or GTQ.\n");
                continue;
            }

            if (strcmp(currencyB, USA_DOLLAR_ISO) == 0)
            {
                currencyToISO = CURRENCY_ISO_USD;
            }
            else if (strcmp(currencyB, EU_EURO_ISO) == 0)
            {
                currencyToISO = CURRENCY_ISO_EUR;
            }
            else if (strcmp(currencyB, GTM_QUETZAL_ISO) == 0)
            {
                currencyToISO = CURRENCY_ISO_GTQ;
            }
            else
            {
                printf("Currency B ISO is invalid. Must be USD, EUR or GTQ.\n");
                continue;
            }
        }

        // Get value.
        printf("Value (%c%c%c): ", currencyA[0], currencyA[1], currencyA[2]);
        scanf("%f", &value);
        getchar();

        // Check values are not negative.
        if (value < 0.0f)
        {
            printf("Value must be non negative.\n");
            continue;
        }

        break;
    }

    if (currencyFromISO == CURRENCY_ISO_USD && currencyToISO == CURRENCY_ISO_EUR)
    {
        printf("Conversion: %f", value / USD_TO_EUR);
    }
    else if (currencyFromISO == CURRENCY_ISO_USD && currencyToISO == CURRENCY_ISO_GTQ)
    {
        printf("Conversion: %f", value / USD_TO_GTQ);
    }
    else if (currencyFromISO == CURRENCY_ISO_EUR && currencyToISO == CURRENCY_ISO_GTQ)
    {
        printf("Conversion: %f", value / EUR_TO_GTQ);
    }
    else if (currencyFromISO == CURRENCY_ISO_EUR && currencyToISO == CURRENCY_ISO_USD)
    {
        printf("Conversion: %f", value * USD_TO_EUR);
    }
    else if (currencyFromISO == CURRENCY_ISO_GTQ && currencyToISO == CURRENCY_ISO_USD)
    {
        printf("Conversion: %f", value * USD_TO_GTQ);
    }
    else if (currencyFromISO == CURRENCY_ISO_GTQ && currencyToISO == CURRENCY_ISO_EUR)
    {
        printf("Conversion: %f", value * EUR_TO_GTQ);
    }
    else
    {
        printf("Conversion: %f", value);
    }

    return 0;
}