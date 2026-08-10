#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Encrypt(char path[]);
void Decrypt(char path[]);
void Caesar_Cipher_Encrypt(char path[]);
void XOR_Cipher_Encrypt(char path[]);
void Caesar_Cipher_Decrypt(char path[]);
void XOR_Cipher_Decrypt(char path[]);

int main() {

char path[100];
  

  
    printf("\nEnter your file path:\n");
  
    printf("Example: C:\\my_folder\\test.txt\n");
  
    printf("Your Path: ");
  

  
    fgets(path, sizeof(path), stdin);
  
    path[strcspn(path, "\n")] = '\0';
  

  

  
    FILE *file = fopen(path, "r");
  

  
    if(file != NULL){
  

  
        printf("Good job! your file path is correct\n");
  

  
        fclose(file);
  

  

  
        printf("\nWhich one do you want?\n");
  
        printf("1. Encrypt\n");
  
        printf("2. Decrypt\n");
  
        printf("3. Exit\n");
  
        printf("Enter Your Choice: ");
  

  

  
        int choice;
  
        scanf("%d", &choice);
  

  
        while(getchar() != '\n');
  

  

  
        switch(choice){
  

  
            case 1:
  
                Encrypt(path);
  
                break;
  

  
            case 2:
  
                Decrypt(path);
  
                break;
  

  
            case 3:
  
                exit(0);
  

  
            default:
  
                printf("Invalid choice\n");
  
        }
  

  
    }else {
  

  
        printf("Wrong path! Try again.\n");}
  

  
return 0;

}

//######Encrypt######

void Encrypt(char path[]) {

printf("\n==== SecureVault Encrypt ====\n");
  
printf("1. Caesar Cipher\n");
  
printf("2. XOR Cipher\n");
  

  
printf("Choose: ");
  

  

  
int choose;
  
scanf("%d", &choose);
  

  
switch(choose){
  

  
    case 1:
  
        Caesar_Cipher_Encrypt(path);
  
        break;
  

  
    case 2:
  
        XOR_Cipher_Encrypt(path);
  
        break;
  

  
    default:
  
        printf("Invalid choice\n");
  
}

}

void Caesar_Cipher_Encrypt(char path[]) {

printf("Enter the key: ");
  

  
int key;
  
scanf("%d", &key);
  

  

  
// fixed offset + user key
  
int shift = (key + 4) % 26;
  

  

  
FILE *input;
  
FILE *output;
  
int ch;
  

  

  
input = fopen(path, "r");
  

  

  
char outputPath[200];
  

  
strcpy(outputPath, path);
  

  

  
char *dot = strrchr(outputPath, '.');
  

  

  
if(dot != NULL){
  

  
    strcpy(dot, "_encrypted.txt");
  

  
}
  
else {
  

  
    strcat(outputPath, "_encrypted.txt");
  

  
}
  

  

  
output = fopen(outputPath, "w");
  

  

  

  
if(input == NULL || output == NULL){
  

  
    printf("Cannot open file\n");
  
    return;
  
}
  

  

  

  
while((ch = fgetc(input)) != EOF){
  

  

  
    if(ch >= 'a' && ch <= 'z'){
  

  

  
        ch = ch + shift;
  

  

  
        if(ch > 'z'){
  

  
            ch = ch - 'z' + 'a' - 1;
  

  
        }
  

  
    }
  

  

  
    else if(ch >= 'A' && ch <= 'Z'){
  

  

  
        ch = ch + shift;
  

  

  
        if(ch > 'Z'){
  

  
            ch = ch - 'Z' + 'A' - 1;
  

  
        }
  

  
    }
  

  

  
    fputc(ch, output);
  

  
}
  

  

  

  
fclose(input);
  
fclose(output);
  

  

  
printf("\nEncryption completed!\n");
  
printf("Saved as: %s\n", outputPath);

}

void XOR_Cipher_Encrypt(char path[]) {

printf("Enter the key: ");
  

  
int key;
  
scanf("%d", &key);
  

  

  
FILE *input;
  
FILE *output;
  
int ch;
  

  

  
input = fopen(path, "rb");
  

  

  
char outputPath[200];
  

  
strcpy(outputPath, path);
  

  

  
char *dot = strrchr(outputPath, '.');
  

  

  
if(dot != NULL){
  

  
    strcpy(dot, "_encrypted.txt");
  

  
}
  
else {
  

  
    strcat(outputPath, "_encrypted.txt");
  

  
}
  

  

  
output = fopen(outputPath, "wb");
  

  

  

  
if(input == NULL || output == NULL){
  

  
    printf("Cannot open file\n");
  
    return;
  
}
  

  

  

  
while((ch = fgetc(input)) != EOF){
  

  
    char encrypted = ch ^ key;
  

  
    fputc(encrypted, output);
  

  
}
  

  

  

  
fclose(input);
  
fclose(output);
  

  
printf("File encrypted successfully!\n");

}

//######Decrypt######

void Decrypt(char path[]) {

printf("\n==== SecureVault Decrypt ====\n");
  
printf("1. Caesar Cipher\n");
  
printf("2. XOR Cipher\n");
  

  
printf("Choose: ");
  

  
int choose;
  
scanf("%d", &choose);
  

  
switch(choose){
  

  
    case 1:
  
        Caesar_Cipher_Decrypt(path);
  
        break;
  

  
    case 2:
  
        XOR_Cipher_Decrypt(path);
  
        break;
  

  
    default:
  
        printf("Invalid choice\n");
  
}

}

void Caesar_Cipher_Decrypt(char path[]){

printf("Enter the key: ");
  

  
int key;
  
scanf("%d", &key);
  

  

  
// fixed offset + user key
  
int shift = (key + 4) % 26;
  

  

  
FILE *input;
  
FILE *output;
  
int ch;
  

  

  
input = fopen(path, "r");
  

  

  
char outputPath[200];
  

  
strcpy(outputPath, path);
  

  

  
char *dot = strrchr(outputPath, '.');
  

  

  
if(dot != NULL){
  

  
    strcpy(dot, "_decrypted.txt");
  

  
}
  
else {
  

  
    strcat(outputPath, "_decrypted.txt");
  

  
}
  

  

  
output = fopen(outputPath, "w");
  

  

  

  
if(input == NULL || output == NULL){
  

  
    printf("Cannot open file\n");
  
    return;
  
}
  

  

  

  
while((ch = fgetc(input)) != EOF){
  

  

  
    if(ch >= 'a' && ch <= 'z'){
  
        ch = ch - shift;
  

  

  
        if(ch  < 'a'){
  
            ch = ch + 26;
  

  
        }
  

  
    }
  

  

  
    else if(ch >= 'A' && ch <= 'Z'){
  
        ch = ch - shift;
  

  

  
        if(ch  < 'A'){
  
            ch = ch + 26;
  

  
        }
  

  
    }
  

  

  
    fputc(ch, output);
  

  
}
  

  

  

  
fclose(input);
  
fclose(output);
  

  

  
printf("\nDecryption completed!\n");
  
printf("Saved as: %s\n", outputPath);

}

void XOR_Cipher_Decrypt(char path[]){

printf("Enter the key: ");
  

  
int key;
  
scanf("%d", &key);
  

  

  
FILE *input;
  
FILE *output;
  
int ch;
  

  

  
input = fopen(path, "rb");
  

  

  
char outputPath[200];
  

  
strcpy(outputPath, path);
  

  

  
char *dot = strrchr(outputPath, '.');
  

  

  
if(dot != NULL){
  

  
    strcpy(dot, "_Decrypted.txt");
  

  
}
  
else {
  

  
    strcat(outputPath, "_Decrypted.txt");
  

  
}
  

  

  
output = fopen(outputPath, "wb");
  

  

  

  
if(input == NULL || output == NULL){
  

  
    printf("Cannot open file\n");
  
    return;
  
}
  

  

  

  
while((ch = fgetc(input)) != EOF){
  

  
    char decrypted = ch ^ key;
  

  
    fputc(decrypted, output);
  

  
}
  

  
fclose(input);
  
fclose(output);
  

  
printf("File Decrypted successfully!\n");

}
