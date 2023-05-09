#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int i, length;
char *endptr, *binaryConversion, *hexaConversion, *formatted;
unsigned long number, checked;

unsigned long checkBitsAndConvertDec(char *arg, int bits);
void inpDecOutBin(char *arg, int bits);
void inpDecOutHex(char *arg, int bits);
void inpBinOutDec(char *arg, int bits);
void inpBinOutHex(char *arg, int bits);
void inpHexOutDec(char *arg, int bits);
void inpHexOutBin(char *arg, int bits);
void inpHexOutHex(char *arg, int bits);
void inpDecOutDec(char *arg, int bits);
void inpBinOutBin(char *arg, int bits);
char *decToBinaryConversion(unsigned long number, int bits);
char *decToHexConversion(unsigned long number, int bits);
char *formatComma(unsigned long number, int bits);
void errorCheck(int number);
void printBinaryFormat(char *result, int bits);
void printHexaFormat(char *result, int bits);

int main(int argc, char *argv[]) {
    char *inputBits = argv[3];
    char *numStr = "";
    char *endptr;
    char *input;
    unsigned long bits;
    i = 0;
    while (inputBits[i] != '\0') {
        if (isdigit(inputBits[i])) {
            numStr = &inputBits[i];
            break;
        }
        i++;
    }
    if (argc < 5) {
        errorCheck(8);
        return -1;
    }
    bits = strtoul(numStr, &endptr, 10);
    if (strcmp(argv[1], "-inD") != 0 && strcmp(argv[1], "-inB") != 0 &&
        strcmp(argv[1], "-inH") != 0) {
        errorCheck(1);
        return -1;
    }
    else if (strcmp(argv[2], "-outD") != 0 && strcmp(argv[2], "-outB") != 0 &&
             strcmp(argv[2], "-outH") != 0) {
        errorCheck(2);
        return -1;
    }
    else if (strcmp(argv[3], "-8") != 0 && strcmp(argv[3], "-16") != 0 &&
             strcmp(argv[3], "-32") != 0 && strcmp(argv[3], "-64") != 0) {
        errorCheck(3);
        return -1;
    }
    if (strcmp(argv[1], "-inB") == 0) {
        input = argv[4];
        length = strlen(input);
        for (i = 0; i < length; i++) {
            if (input[i] != '1' && input[i] != '0') {
                errorCheck(4);
                return -1;
            }
        }
    }
    if (strcmp(argv[1], "-inD") == 0) {
        input = argv[4];
        length = strlen(input);
        for (i = 0; i < length; i++) {
            if (!isdigit(input[i])) {
                errorCheck(5);
                return -1;
            }
        }
    }
    if (strcmp(argv[1], "-inH") == 0) {
        input = argv[4];
        length = strlen(input);
        for (i = 0; i < length; i++) {
            if (!isdigit(input[i])) {
                {
                    if (!(input[i] == 'a') && !(input[i] == 'b') && !(input[i] == 'c') && !(input[i] == 'd') && !(input[i] == 'e') && !(input[i] == 'f')) {
    errorCheck(6);
    return -1;
}
if (strcmp(argv[1], "-inD") == 0 && strcmp(argv[2], "-outB") == 0) {
    inpDecOutBin(argv[4], bits);
} else if (strcmp(argv[1], "-inD") == 0 && strcmp(argv[2], "-outH") == 0) {
    inpDecOutHex(argv[4], bits);
} 
if (strcmp(argv[1], "-inB") == 0 && strcmp(argv[2], "-outD") == 0) {
    inpBinOutDec(argv[4], bits);
} else if (strcmp(argv[1], "-inB") == 0 && strcmp(argv[2], "-outH") == 0) {
    inpBinOutHex(argv[4], bits);
} 
if (strcmp(argv[1], "-inH") == 0 && strcmp(argv[2], "-outD") == 0) {
    inpHexOutDec(argv[4], bits);
} else if (strcmp(argv[1], "-inH") == 0 && strcmp(argv[2], "-outB") == 0) {
    inpHexOutBin(argv[4], bits);
} else if (strcmp(argv[1], "-inH") == 0 && strcmp(argv[2], "-outH") == 0) {
    inpHexOutHex(argv[4], bits);
} else if (strcmp(argv[1], "-inD") == 0 && strcmp(argv[2], "-outD") == 0) {
    inpDecOutDec(argv[4], bits);
} else if (strcmp(argv[1], "-inB") == 0 && strcmp(argv[2], "-outB") == 0) {
    inpBinOutBin(argv[4], bits);
}
return 1;

unsigned long checkBitsAndConvertDec(char *arg, int bits) {
    int eliminatedBit;
    char *result = malloc(bits);
    length = strlen(arg);
    if (length < bits) {
        number = strtoul(arg, &endptr, 2);
    } else {
        eliminatedBit = length - bits;
        for (i = 0; i < bits; i++) {
            result[i] = arg[i + eliminatedBit];
        }
        number = strtoul(result, &endptr, 2);
        free(result);
    }
    return number;
}

char *decToBinaryConversion(unsigned long number, int bits) {
    int i;
    char *result = malloc(bits);
    if (!result) {
        return NULL;
    }
    for (i = bits - 1; i >= 0; i--) {
        result[i] = (number & 1) + '0';
        number >>= 1;
    }
    result[bits] = '\0';
    return result;
}

char *decToHexConversion(unsigned long number, int bits) {
    char *result = malloc(bits);
    if (!result) {
        return NULL;
    }
    if (bits == 64) {
        sprintf(result, "%016lx", number);
    } else if (bits == 32) {
        sprintf(result, "%08lx", number);
    } else if (bits == 16) {
        sprintf(result, "%04lx", number);
    }
    else if (bits == 8)
    {
    sprintf(result, "%02lx", number);
    }
    return result;
    }
    char *formatComma(unsigned long number, int bits)
{
    int i, j, length, lengthOfSpace;
    char *digit = malloc(bits);
    sprintf(digit, "%lu", number);
    length = 0;
    while (number > 0)
    {
        length++;
        number /= 10;
    }
    i = length;
    j = i - 3;
    while (j > 0)
    {
        length++;
        i = length;
        while (i > j)
        {
            digit[i] = digit[i - 1];
            i--;
        }
        digit[j] = ',';
        j -= 3;
    }
    lengthOfSpace = length;
    if (bits == 8)
    {
        printf("%*s", 3 - lengthOfSpace, "");
    }
    else if (bits == 16)
    {
        printf("%*s", 6 - lengthOfSpace, "");
    }
    else if (bits == 32)
    {
        printf("%*s", 13 - lengthOfSpace, "");
    }
    else if (bits == 64)
    {
        printf("%*s", 26 - lengthOfSpace, "");
    }
    return digit;
}

void printBinaryFormat(char *result, int bits)
{
    int count = 0;
    for (i = 0; i < bits; i += 4)
    {
        printf("%.*s", 4, &binaryConversion[i]);
        count++;
        if (count < bits / 4)
            printf(" ");
    }
    printf("\n");
}

void printHexaFormat(char *result, int bits)
{
    int count = 0;
    for (i = 0; i < bits / 4; i += 2)
    {
        printf("%.*s", 2, &hexaConversion[i]);
        count++;
        if (count < bits / 8)
            printf(" ");
    }
    printf("\n");
}

void inpDecOutBin(char *arg, int bits)
{
    number = strtoul(arg, &endptr, 10);
    binaryConversion = decToBinaryConversion(number, bits);
    checked = checkBitsAndConvertDec(binaryConversion, bits);
    binaryConversion = decToBinaryConversion(checked, bits);
    printBinaryFormat(binaryConversion, bits);
}

void inpDecOutHex(char *arg, int bits)
{
    number = strtoul(arg, &endptr, 10);
    binaryConversion = decToBinaryConversion(number, bits);
    checked = checkBitsAndConvertDec(binaryConversion, bits);
    hexaConversion = decToHexConversion(checked, bits);
    printHexaFormat(hexaConversion, bits);
}

void inpBinOutDec(char *arg, int bits)
{
    checked = checkBitsAndConvertDec(arg, bits);
    formatted = formatComma(checked, bits);
    printf("%s\n", formatted);
}

void inpBinOutHex(char *arg, int bits)
{
    checked = checkBitsAndConvertDec(arg, bits);
    hexaConversion = decToHexConversion(checked, bits);
    printHexaFormat(hexaConversion, bits);
}

void inpHexOutDec(char *arg, int bits)
{
    number = strtoul(arg, &endptr, 16);
    binaryConversion = decToBinaryConversion(number, bits);
    checked = checkBitsAndConvertDec(binaryConversion, bits);
    formatted = formatComma(checked, bits);
    printf("%s\n", formatted);
}
void inpHexOutBin(char *arg, int bits)
{
number = strtoul(arg, &endptr, 16);
binaryConversion = decToBinaryConversion(number, bits);
checked = checkBitsAndConvertDec(binaryConversion,bits);
binaryConversion = decToBinaryConversion(checked, bits);
printBinaryFormat(binaryConversion,bits);
}
void inpHexOutHex(char *arg, int bits)
{
    number = strtoul(arg, &endptr, 16);
    binaryConversion = decToBinaryConversion(number, bits);
    inpBinOutHex(binaryConversion,bits);
}
void inpDecOutDec(char *arg, int bits)
{
number = strtoul(arg, &endptr, 10);
binaryConversion = decToBinaryConversion(number, bits);
inpBinOutDec(binaryConversion,bits);
}
void inpBinOutBin(char *arg, int bits)
{
checked =checkBitsAndConvertDec(arg, bits);
binaryConversion = decToBinaryConversion(checked, bits);
printBinaryFormat(binaryConversion,bits);
}
void errorCheck(int number)
{
if (number == 1)
printf("ERROR: argument 1 must be -inB | -inD | -inH\n");
if (number == 2)
printf("ERROR: argument 2 must be -outB | -outD | -outH\n");
if (number == 3)
printf("ERROR: argument 3 must be: -8 | -16 | -32 | -64\n");
if (number == 4)
printf("ERROR: argument 4 is not a binary integer\n");
if (number == 5)
printf("ERROR: argument 4 is not a decimal integer\n");
if (number == 6)
printf("ERROR: argument 4 is not a hexadecimal integer\n");
if (number == 8)
printf("ERROR: incorrect number of arguments\n");
printf("usage:\n");
printf("convert IN OUT SIZE NUMBER\n");
printf(" IN:\n -inB NUMBER is binary.\n -inD NUMBER is decimal.\n -
inH NUMBER is hexadecimal.\n\n");
printf(" OUT:\n -outB Output will be in binary.\n -outD Output will be in
decimal.\n -outH Output will be in hexadecimal.\n\n");
printf(" SIZE:\n -8 input is an unsigned 8-bit integer.\n -16 input
is an unsigned 16-bit integer.\n");
printf(" -32 input is an unsigned 32-bit integer.\n -64 input is an
unsigned 64-bit integer.\n\n");
printf(" NUMBER:\n number to be converted.\n\n");
}
