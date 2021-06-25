#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char binaryNumber[100];
char Hex[50];
typedef struct record myStruct;

//struct created for the xml values
struct record
{
    char name[64];    //utf16
    char surname[32]; //utf8
    char gender;
    char email[32];
    char phone_number[16];
    char address[32];
    char level_of_education[8];
    unsigned int income_level; // given little-endian
    unsigned int expenditure;  // given big-endian
    char currency_unit[16];
    char currentMood[32];
    float height;
    unsigned int weight;
};

//struct created for the xml tag
struct tag
{
    char name[5];    //utf16
    char surname[8]; //utf8
    char gender[7];
    char email[6];
    char phone_number[16];
    char address[32];
    char level_of_education[32];
    char income_level[16]; 
    char expenditure[16];  
    char currency_unit[16];
    char currentMood[16];
    char height[16];
    char weight[16];
};

//together with the incoming char and len the value of that digit
long hex2Dec(char c, int len)
{
    long n = 0;
    if (c >= '0' && c <= '9')
        n = (c - '0');
    else if (c == 'A')
        n = (10);
    else if (c == 'B')
        n = (11);
    else if (c == 'C')
        n = (12);
    else if (c == 'D')
        n = (13);
    else if (c == 'E')
        n = (14);
    else if (c == 'F')
        n = (15);
    else
    {
        printf("Error:Your number Is Not Valid!");
        return -1;
    }
    long pow = 1;
    //exponential function is received
    for (size_t i = 0; i < len; i++)
    {
        pow *= 16;
    }
    long result = pow * n;
    return result;
}

//decimal is converted to hexadecimal
long decimal2hex(int decimalNumber)
{
    int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];
    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;
        //To convert integer into character
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    //hexadecimal completes to 8 bits
    for (size_t k = i - 1; k < 8; k++)
    {
        temp = 48;
        hexadecimalNumber[i++] = temp;
    }
    int m = 1;
    long n = 0;
    //converts to hexadecimal decimal
    while (m != 9)
    {
        int len = i - m - 1;
        n += hex2Dec(hexadecimalNumber[m + 1], len);
        len = i - m - 2;
        n += hex2Dec(hexadecimalNumber[m], len);
        m += 2;
    }

    return n;
}

//2's compement of hexadecimal computed
long hex2dec(char c, long n)
{
    if (c >= '0' && c <= '9')
        return n * 16 + (c - '0');
    else if (c == 'A')
        return n * 16 + (10);
    else if (c == 'B')
        return n * 16 + (11);
    else if (c == 'C')
        return n * 16 + (12);
    else if (c == 'D')
        return n * 16 + (13);
    else if (c == 'E')
        return n * 16 + (14);
    else if (c == 'F')
        return n * 16 + (15);
    else
    {
        printf("Error:Your number Is Not Valid!");
        return -1;
    }
}

//it is converted to decimal by taking the inverse of hexadecimal that comes as little endian
long hexadecimal2decimal()
{
    int i = 7;
    long n = 0;
    while (i != -1)
    {
        n = hex2dec(Hex[i - 1], n);
        n = hex2dec(Hex[i], n);
        i -= 2;
    }
    return n;
}

//converts a publicly generated binary number to hexadecimal
long binary2hexadecimal()
{
    long long num = 0;
    int i = 0;
    strcpy(Hex, ""); //if not empited every time, a diffrent number will appear than it should be on the other lines
    for (size_t j = 1; j <= 33; j += 4)
    {
        int a = (int)binaryNumber[j] - 48;
        if (a == 0)
        {
            a = (int)binaryNumber[j + 1] - 48;
            if (a == 0)
            {
                a = (int)binaryNumber[j + 2] - 48;
                if (a == 0)
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "0");
                    }
                    else
                    {
                        strcat(Hex, "1");
                    }
                }
                else
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "2");
                    }
                    else
                    {
                        strcat(Hex, "3");
                    }
                }
            }
            else
            {
                a = (int)binaryNumber[j + 2] - 48;
                if (a == 0)
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "4");
                    }
                    else
                    {
                        strcat(Hex, "5");
                    }
                }
                else
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "6");
                    }
                    else
                    {
                        strcat(Hex, "7");
                    }
                }
            }
        }
        else
        {
            a = (int)binaryNumber[j + 1] - 48;
            if (a == 0)
            {
                a = (int)binaryNumber[j + 2] - 48;
                if (a == 0)
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "8");
                    }
                    else
                    {
                        strcat(Hex, "9");
                    }
                }
                else
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "A");
                    }
                    else
                    {
                        strcat(Hex, "B");
                    }
                }
            }
            else
            {
                a = (int)binaryNumber[j + 2] - 48;
                if (a == 0)
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "C");
                    }
                    else
                    {
                        strcat(Hex, "D");
                    }
                }
                else
                {
                    a = (int)binaryNumber[j + 3] - 48;
                    if (a == 0)
                    {
                        strcat(Hex, "E");
                    }
                    else
                    {
                        strcat(Hex, "F");
                    }
                }
            }
        }
        i++;
    }
    char hex[50];
    return hexadecimal2decimal();
}

//converts the number read with little endian to big endian
long LittleEndian2BigEndian(long decimalNumber)
{
    int remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];
    quotient = decimalNumber;
    int c, k;
    char *c1 = "1";
    char *c0 = "0";
    //returns the incoming number to its inverted binary
    for (c = 31; c >= 0; c--)
    {
        k = decimalNumber >> c;
        if (k & 1)
        {
            binaryNumber[i++] = *c1;
        }
        else
            binaryNumber[i++] = *c0;
    }
    return binary2hexadecimal();
}

//write two opened files to an xml file with a given name
void create_XML_file(FILE *fn, FILE *fp, char *createFileName,char *readFileName)
{
    FILE *fxml = fopen(createFileName, "w"); //file is opened for writing
    myStruct rItem;                          //create struct to get variables other than names separately
    myStruct nItem;                          //create struct to get names separately
    struct tag body;                         //create a separate struct for tag
    char *token = strtok(readFileName, ".");
    //Reads data from file as much as struct structure
    fread(&rItem, sizeof(myStruct), 1, fp);
    fread(&nItem, sizeof(myStruct), 1, fn);
    //Assigns values properly to the tag struct
    strcpy(body.name, nItem.name);
    strcpy(body.surname, rItem.surname);
    strcpy(body.gender, "gender");
    strcpy(body.email, rItem.email);
    strcpy(body.phone_number, rItem.phone_number);
    strcpy(body.address, rItem.address);
    strcpy(body.level_of_education, "level_of_education");
    strcpy(body.income_level, "income_level");
    strcpy(body.expenditure, "expenditure");
    strcpy(body.currency_unit, rItem.currency_unit);
    strcpy(body.currentMood, rItem.currentMood);
    strcpy(body.height, "height");
    strcpy(body.weight, "weight");
    fprintf(fxml, "<%s>\n", token);
    int id = 1;
    while (1 == 1)
    {
        fread(&rItem, sizeof(myStruct), 1, fp);
        fread(&nItem, sizeof(myStruct), 1, fn);
        if (strlen(rItem.name) == 0) //If the first value is empty,it is understood to be at the last value and exit for
            break;
        int ItemEx = rItem.expenditure;    //The wrong amount of expenditure is received
        int ex = LittleEndian2BigEndian(ItemEx);  //converted to the correct value
        long Bex = decimal2hex(ex);        //converts the number converted to big end, not 2s compement, differently converting hexadecimal to decimal
        int ItemIn = rItem.income_level;   //this assign the income_level we read to a value
        long in = LittleEndian2BigEndian(ItemIn); //converts the incoming number to big endian
        //fills the generated xml with the read values
        fprintf(fxml, "\t<row id=\"%d\">\n", id++);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.name, nItem.name, body.name);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.surname, rItem.surname, body.surname);
        fprintf(fxml, "\t\t<%s>%c</%s>\n", body.gender, rItem.gender, body.gender);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.email, rItem.email, body.email);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.phone_number, rItem.phone_number, body.phone_number);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.address, rItem.address, body.address);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.level_of_education, rItem.level_of_education, body.level_of_education);
        fprintf(fxml, "\t\t<%s bigEnd=\"%ld\">%d</%s>\n", body.income_level, in, rItem.income_level, body.income_level);
        fprintf(fxml, "\t\t<%s bigEnd=\"%ld\">%d</%s>\n", body.expenditure, Bex, ex, body.expenditure);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.currency_unit, rItem.currency_unit, body.currency_unit);
        fprintf(fxml, "\t\t<%s>%s</%s>\n", body.currentMood, rItem.currentMood, body.currentMood);
        fprintf(fxml, "\t\t<%s>%.2f</%s>\n", body.height, rItem.height, body.height);
        fprintf(fxml, "\t\t<%s>%d</%s>\n", body.weight, rItem.weight, body.weight);
        fprintf(fxml, "\t</row>\n");
    }

    fprintf(fxml, "</%s>", token);
    fclose(fxml);
}

//reads the file with name sent
void read_file(char *readFileName, char *createFileName)
{
    FILE *fp;                                    //file is created to read variables other than names in utf8
    FILE *fn;                                    //file is created to read the name in utf16
    fp = fopen(readFileName, "rb");              //reads the file in utf8 format
    fn = fopen(readFileName, "rb, ccs=UTF16LE"); //reads the file in utf16 format
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    create_XML_file(fn, fp, createFileName,readFileName);
    fclose(fp);
}

int main(int argc, char *argv[])
{
    //if the file name to be created and the file name read is missing, an error code will be given
    if (argc > 2)
    {
        if (strcmp(argv[0], "./Bin2XML") != 0)
        {
            printf("Please enter correctly.\nExample input : \ngcc 2017510024.c -o ./Bin2XML\n./Bin2XML records.dat text.xml\n");
        }
        else
        {
            char *fileName = argv[1];
            char *createFileName = argv[2];
            read_file(fileName, createFileName);
        }
    }
    if (argc < 3)
            printf("Please enter correctly.\nExample input : \ngcc 2017510024.c -o ./Bin2XML\n./Bin2XML records.dat text.xml\n");
    return 0;
}