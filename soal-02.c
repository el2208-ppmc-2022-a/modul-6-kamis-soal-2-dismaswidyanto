/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : -
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int coeff, power;
	char *token, buffer[256];

	// Masukkan polinomial A
	printf("Masukkan Polinomial A: ");
	scanf(" %[^\n]s", buffer);
	token = strtok(buffer, " + ");
	while (token != NULL)
	{
		sscanf(token, "%dx^%d", &coeff, &power);

		// ...

		token = strtok(NULL, " + ");
	}

	// Masukkan polinomial B
	printf("Masukkan Polinomial B: ");
	scanf(" %[^\n]s", buffer);
	token = strtok(buffer, " + ");
	while (token != NULL)
	{
		sscanf(token, "%dx^%d", &coeff, &power);

		//...

		token = strtok(NULL, " + ");
	}

	// Mencetak Hasil
	printf("Hasil: ");

	return 0;
}
