#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void bin_to_oct(char *binary) {
    printf("Converting Binary to Octal:\n");
    printf("First draw a table with 3 columns and list the index of 4, 2, 1.\n");
    printf("2 1 | 4 2 1 | 4 2 1\n");
    printf("Fill in the table with the binary number.\n");
    printf("2 1 | 4 2 1 | 4 2 1\n");
    printf("%c %c | %c %c %c | %c %c %c\n", binary[0], binary[1], binary[2], binary[3], binary[4], binary[5], binary[6], binary[7]);
    printf("Convert each row to octal.\n");
    char *first_col = malloc(sizeof(char) * 3);
    char *second_col = malloc(sizeof(char) * 3);
    char *third_col = malloc(sizeof(char) * 3);
    strncpy(first_col, binary, 3);
    first_col[2] = '\0';
    strncpy(second_col, binary + 2, 3);
    second_col[3] = '\0';
    strncpy(third_col, binary + 5, 3);
    third_col[3] = '\0';
    printf("%o %o %o\n", (unsigned int) strtol(first_col, NULL, 2), (unsigned int) strtol(second_col, NULL, 2), (unsigned int) strtol(third_col, NULL, 2));
    printf("Then, combine the octal numbers.\n");
    printf("%o\n", (unsigned int) strtol(binary, NULL, 2));
}

void bin_to_dec(char *binary) {
    printf("Converting Binary to Decimal:\n");
    printf("List the Binary numbers out:\n");
    printf("128 64 32 16 8 4 2 1\n");
    printf("List the binary number.\n");
    printf("128 64 32 16 8 4 2 1\n");
    printf("%c   %c  %c  %c  %c %c %c %c\n", binary[0], binary[1], binary[2], binary[3], binary[4], binary[5], binary[6], binary[7]);
    printf("Add the columns with 1.\n");
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            printf("%d", 1 << (7 - i));
            if (i < 7 ){
                for (int j = i; j < 7; j++) {
                    // if all bits at the right are 0, don't print + sign
                    if (binary[j + 1] == '1') {
                        printf(" + ");
                        break;
                    }
                }
            }
        }
    }
    printf(" = \n%d\n", (unsigned int) strtol(binary, NULL, 2));
}

void bin_to_hex(char *binary) {
    printf("Converting Binary to Hexadecimal:\n");
    printf("Split all bits into nibbles.\n");
    printf("8 4 2 1 | 8 4 2 1\n");
    printf("%c %c %c %c | %c %c %c %c\n", binary[0], binary[1], binary[2], binary[3], binary[4], binary[5], binary[6], binary[7]);
    char *nibble1 = malloc(sizeof(char) * 5);
    char *nibble2 = malloc(sizeof(char) * 5);
    strncpy(nibble1, binary, 4);
    nibble1[4] = '\0';
    strncpy(nibble2, binary + 4, 4);
    nibble2[4] = '\0';
    printf("Convert each nibble to hexadecimal.\n");
    printf("%X %X\n", (unsigned int) strtol(nibble1, NULL, 2), (unsigned int) strtol(nibble2, NULL, 2));
    printf("Then, combine the hexadecimal numbers.\n");
    printf("%X\n", (unsigned int) strtol(binary, NULL, 2));
}

char* oct_to_bin(char *octal) {
    char *octal_copy = malloc(sizeof(char) * 4);
    strncpy(octal_copy, octal, 3);
    octal_copy[3] = '\0';
    int octal_copy2[3];
    for (int i = 0; i < 3; i++) {
        octal_copy2[i] = octal[i] - '0';
    }
    char res[9];
    printf("Converting Octal to Binary:\n");
    printf("First draw a table with 3 columns and list the index of 4, 2, 1.\n");
    printf("2 1 | 4 2 1 | 4 2 1\n");
    printf("For each octal digit, convert it to binary by substracting the index.\n");
    printf("For first octal digit:\n");
    printf("%c -> ", octal[0]);
    int rows[3] = { 4, 2, 1 };
    for (int i = 1; i < 3; i++) {
        if (octal_copy2[0] - rows[i] >= 0) {
            printf("1");
            res[i - 1] = '1';
            octal_copy2[0] -= rows[i];
        } else {
            printf("0");
            res[i - 1] = '0';
        }
    }
    printf("\nFor second octal digit:\n");
    printf("%c -> ", octal[1]);
    for (int i = 0; i < 3; i++) {
        if (octal_copy2[1] - rows[i] >= 0) {
            printf("1");
            res[i + 2] = '1';
            octal_copy2[1] -= rows[i];
        } else {
            printf("0");
            res[i + 2] = '0';
        }
    }
    printf("\nFor third octal digit:\n");
    printf("%c -> ", octal[2]);
    for (int i = 0; i < 3; i++) {
        if (octal_copy2[2] - rows[i] >= 0) {
            printf("1");
            res[i + 5] = '1';
            octal_copy2[2] -= rows[i];
        } else {
            printf("0");
            res[i + 5] = '0';
        }
    }
    printf("\nThen, combine the binary numbers.\n");
    res[8] = '\0';
    printf("%s\n", res);
    char *result = malloc(sizeof(char) * 9);
    strncpy(result, res, 8);
    result[8] = '\0';
    return result;
}

void oct_to_dec(char *octal) {
    printf("Converting Octal to Decimal:\n");
    printf("In order to convert octal to decimal, we need to convert octal to binary first.\n");
    char *res = oct_to_bin(octal);
    bin_to_dec(res);
}

void oct_to_hex(char *octal) {
    printf("Converting Octal to Hexadecimal:\n");
    printf("In order to convert octal to hexadecimal, we need to convert octal to binary first.\n");
    char *res = oct_to_bin(octal);
    bin_to_hex(res);
}

char *dec_to_bin(char *decimal) {
    printf("Converting Decimal to Binary:\n");
    printf("List the Binary numbers out:\n");
    printf("128 64 32 16 8 4 2 1\n");
    printf("One by one from left to right, subtract the number with the binary number if it is big enough to do so. If it is able to subtract, subtract it and place 1 in the table, else place 0\n");
    int dec = atoi(decimal);
    int dec_copy = dec;
    printf("\n%d", dec_copy);
    for (int i = 0; i < 8; i++) {
        if (dec_copy - (1 << (7 - i)) >= 0) {
            printf(" - %d", 1 << (7 - i));
            dec_copy -= (1 << (7 - i));
        }
    }
    printf(" = 0\n");
    char res[9];
    printf("128 64  32  16  8   4   2   1\n");
    for (int i = 0; i < 8; i++) {
        if (dec - (1 << (7 - i)) >= 0) {
            printf("1   ");
            res[i] = '1';
            dec -= (1 << (7 - i));
        } else {
            printf("0   ");
            res[i] = '0';
        }
    }
    printf("\nAfter the subtraction, the binary number is: %s\n", res);
    char *res_copy = malloc(sizeof(char) * 9);
    strncpy(res_copy, res, 8);
    res_copy[8] = '\0';
    return res_copy;
}

void dec_to_oct(char *decimal) {
    printf("Converting Decimal to Octal:\n");
    printf("In order to convert decimal to octal, we need to convert decimal to binary first.\n");
    char *res = dec_to_bin(decimal);
    printf("Then, convert the binary number to octal.\n");
    bin_to_oct(res);
}

void dec_to_hex(char *decimal) {
    printf("Converting Decimal to Hexadecimal:\n");
    printf("Divide the decimal number by 16 take the quotient to be first digit of the hexadecimal number.\n");
    printf("Take the remainder to be the second digit of the hexadecimal number.\n");
    int dec = atoi(decimal);
    printf("%d / 16 = %d remainder %d\n", dec, dec / 16, dec % 16);
    printf("Then, convert the quotient and remainder to hexadecimal.\n");
    printf("%d -> %X\n", dec / 16, dec / 16);
    printf("%d -> %X\n", dec % 16, dec % 16);
    printf("Then, combine the hexadecimal numbers.\n");
    printf("%X%X\n", dec / 16, dec % 16);
}

char *hex_to_bin(char *hexadecimal) {
    printf("Converting Hexadecimal to Binary:\n");
    printf("Split the hexadecimal number into 2 characters.\n");
    int char1 = hexadecimal[0] - '0';
    int char2 = hexadecimal[1] - '0';
    hexadecimal[0] = toupper(hexadecimal[0]);
    hexadecimal[1] = toupper(hexadecimal[1]);
    if (hexadecimal[0] >= 'A' && hexadecimal[0] <= 'F') {
        char1 = hexadecimal[0] - 'A' + 10;    
    }
    if (hexadecimal[1] >= 'A' && hexadecimal[1] <= 'F') {
        char2 = hexadecimal[1] - 'A' + 10;    
    }
    printf("%X %X\n", char1, char2);
    printf("Convert each character to nibble.\n");
    printf("For each character, subtract the number with the binary number if it is big enough to do so. If it is able to subtract, subtract it and place 1 in the table, else place 0.\n");
    printf("List the Binary numbers out:\n");
    printf("8 4 2 1 | 8 4 2 1\n");
    char *res = malloc(sizeof(char) * 9);
    printf("\nFirst character (%X):\n", char1);
    printf("%X", char1);
    int char1_copy = char1;
    for (int i = 0; i < 4; i++) {
        if (char1 - (1 << (3 - i)) >= 0) {
            printf(" - %d", 1 << (3 - i));
            char1 -= (1 << (3 - i));
        }
    }
    printf(" = 0\n");
    printf("8 4 2 1\n");
    for (int i = 0; i < 4; i++) {
        if (char1_copy - (1 << (3 - i)) >= 0) {
            printf("1 ");
            res[i] = '1';
            char1_copy -= (1 << (3 - i));
        } else {
            printf("0 ");
            res[i] = '0';
        }
    }
    printf("\nSecond character (%X):\n", char2);
    printf("%X", char2);
    int char2_copy = char2;
    for (int i = 0; i < 4; i++) {
        if (char2 - (1 << (3 - i)) >= 0) {
            printf(" - %d", 1 << (3 - i));
            char2 -= (1 << (3 - i));
        }
    }
    printf(" = 0\n");
    printf("8 4 2 1\n");
    for (int i = 0; i < 4; i++) {
        if (char2_copy - (1 << (3 - i)) >= 0) {
            printf("1 ");
            res[i + 4] = '1';
            char2_copy -= (1 << (3 - i));
        } else {
            printf("0 ");
            res[i + 4] = '0';
        }
    }
    res[8] = '\0';
    printf("\nCombine the binary numbers.\n");
    printf("%s\n", res);
    return res;
}

void hex_to_oct(char *hexadecimal) {
    printf("Converting Hexadecimal to Octal:\n");
    printf("In order to convert hexadecimal to octal, we need to convert hexadecimal to binary first.\n");
    char *res = hex_to_bin(hexadecimal);
    printf("Then, convert the binary number to octal.\n");
    bin_to_oct(res);
}

void hex_to_dec(char *hexadecimal) {
    printf("Converting Hexadecimal to Decimal:\n");
    printf("In order to convert hexadecimal to decimal, we need to convert hexadecimal to binary first.\n");
    char *res = hex_to_bin(hexadecimal);
    printf("Then, convert the binary number to decimal.\n");
    bin_to_dec(res);
}

void usage(char **argv) {
    printf("Usage: ./based -f [from] -t [to] -n [number]\n");
}

void validate_input(char **argv, char *choices[4]) {
    if (strncmp(argv[1], "-f", 2) || strncmp(argv[3], "-t", 2) || strncmp(argv[5], "-n", 2)) {
        // option not in right place
        usage(argv);
    }
    // input validation
    for (int i = 2; i < 6; i += 2) {
        int found = 0;
        for (int j = 0; j < 4; j++) {
            if (strcmp(argv[i], choices[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("based: Unknown base -> %s\n", argv[i]);
            usage(argv);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 7) {
        if (argc == 2 && strncmp(argv[1], "-h", 2) == 0) {
            usage(argv);
            printf("based is a command line tool to help A level students to revise base conversion.\n");
            printf("Options:\n");
            printf("    -f [bin|oct|dec|hex]    The base to convert from\n");
            printf("    -t [bin|oct|dec|hex]    The base to convert to\n");
            printf("    -n [number]             The number to convert (must be representable by 8 bits)\n");
            printf("                            When from base is binary, the number must have 8 characters\n");
            printf("                            When from base is octal, the number must have at most 3 characters\n");
            printf("                            When from base is hexadecimal, the number must have 2 characters\n");
            printf("                            When from base is decimal, the number must be a bigger than 0 and smaller than 256\n");
            return 0;
        }
        usage(argv);
        return 1;
    }
    char *choices[4] = { "bin", "oct", "dec", "hex" };
    validate_input(argv, choices);

    char *from_base = argv[2];
    char *to_base = argv[4];
    char *number = argv[6];

    if (!strcmp(from_base, to_base)) {
        printf("based: Cannot convert from same bases.\n");
        return 1;
    }

    if (strncmp(from_base, "bin", 3) == 0) {
        if (strlen(number) != 8) {
            printf("based: Binary number must be 8 bits. If it is a 7 bits number, add a 0 first.\n");
            return 1;
        }
        if (strncmp(to_base, "oct", 3) == 0) {
            bin_to_oct(number);
        } else if (strncmp(to_base, "dec", 3) == 0) {
            bin_to_dec(number);
        } else if (strncmp(to_base, "hex", 3) == 0) {
            bin_to_hex(number);
        }
    } else if (strncmp(from_base, "oct", 3) == 0) {
        if (strlen(number) > 3) {
            printf("based: Octal number must be 3 or less than 3 digits");
            return 1;
        }
        if (strncmp(to_base, "bin", 3) == 0) {
            oct_to_bin(number);
        } else if (strncmp(to_base, "dec", 3) == 0) {
            oct_to_dec(number);
        } else if (strncmp(to_base, "hex", 3) == 0) {
            oct_to_hex(number);
        }
    } else if (strncmp(from_base, "dec", 3) == 0) {
        if (strlen(number) > 3 || atoi(number) > 255 || atoi(number) < 0) {
            printf("based: Decimal number must be 3 or less than 3 digits and must be between 0 and 255.\n");
            return 1;
        }
        if (strncmp(to_base, "bin", 3) == 0) {
            dec_to_bin(number);
        } else if (strncmp(to_base, "oct", 3) == 0) {
            dec_to_oct(number);
        } else if (strncmp(to_base, "hex", 3) == 0) {
            dec_to_hex(number);
        }
    } else if (strncmp(from_base, "hex", 3) == 0) {
        if (strlen(number) != 2) {
            printf("based: Hexadecimal number must be 2 digits.\n");
            return 1;
        }
        if (strncmp(to_base, "bin", 3) == 0) {
            hex_to_bin(number);
        } else if (strncmp(to_base, "oct", 3) == 0) {
            hex_to_oct(number);
        } else if (strncmp(to_base, "dec", 3) == 0) {
            hex_to_dec(number);
        }
    }
     return 0;
}
