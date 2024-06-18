# CBC_Encryption
CBC_Encryption is a C library that provides functionalities to encrypt and decrypt data using the Cipher Block Chaining (CBC) mode of operation. This library is designed for educational purposes and provides a straightforward interface for encrypting and decrypting text using symmetric key encryption.

## Features
- Encrypt data using the AES algorithm in CBC mode.
- Decrypt data that was encrypted using the AES algorithm in CBC mode.
- Generate a random initialization vector (IV) for each encryption.
- Handle linked list structures for efficient data manipulation.
- Read data from and write data to files.

## Installation
To use the CBC_Encryption library, you need to compile it from source. Ensure you have OpenSSL installed on your system as this library depends on OpenSSL for cryptographic operations.

### Compiling the Library
- Clone the repository:

- git clone https://github.com/yourusername/CBC_Encryption.git
- cd CBC_Encryption

### Compile the library:

gcc -o cbc_encrypt main.c ../src/cbc.c ../src/fileio.c ../src/linkedlist.c -lcrypto

## Usage
Below is an example of how to use the CBC_Encryption library for encryption and decryption.

- Importing the Necessary Headers

#include "../include/cbc.h"
#include "../include/fileio.h"
#include "../include/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

- Main Function Example

int main() {
  // Read data from a file into a linked list
  struct Node *data = readFile("project/Makefiles/input.txt");
  printf("Original Data: ");
  displayList(data);

  // Encrypt the linked list using CBC encryption
  struct Node *iv = createNode('0');
  struct Node *current = data;
  while (current != NULL) {
    encryptBlock(&current, iv);
    current = current->next;
  }
  printf("Encrypted Data: ");
  displayList(data);

  // Write the encrypted data to a file
  writeFile("project/Makefiles/encrypted.txt", data);

  // Free the memory
  while (data != NULL) {
    struct Node *temp = data;
    data = data->next;
    free(temp);
  }

  free(iv);

  return 0;
}

- Functions
- readFile

struct Node* readFile(const char* filename);
Reads data from a file and stores it in a linked list.

- writeFile

void writeFile(const char* filename, struct Node* head);
Writes the linked list data to a file.

- displayList

void displayList(struct Node* head);
Displays the data in the linked list.

- createNode

struct Node* createNode(char data);
Creates a new node with the given data.

- encryptBlock

void encryptBlock(struct Node** current, struct Node* iv);
Encrypts a block of data using the CBC mode.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments
This library uses the OpenSSL library for cryptographic operations. For more information about OpenSSL, visit https://www.openssl.org.

## Contributing
If you would like to contribute to this project, please fork the repository and submit a pull request.

## Contact
For any questions or feedback, please contact your-email@example.com.
