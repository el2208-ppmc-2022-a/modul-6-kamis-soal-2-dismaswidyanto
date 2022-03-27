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

typedef struct Term
{
    int coeff;
    int power;
    struct Term *next;
} Term;

/**
 * @brief Fungsi untuk membuat suku baru
 *
 * @param coeff coeffisien suku
 * @param power pangkat suku
 * @return Term*
 */
Term *makeNewTerm(int coeff, int power)
{
    Term *retval = malloc(sizeof(Term));
    retval->coeff = coeff;
    retval->power = power;
    retval->next = NULL;
    return retval;
}

/**
 * @brief prosedur untuk memnambahkan suku baru ke polinomial
 *
 * @param headPtr pointer ke head dari polinomial
 * @param newTerm suku baru yang akan dimasukkan
 */
void insert(Term **headPtr, Term *newTerm)
{
    Term *head = *headPtr;
    if (head == NULL)
    {
        *headPtr = newTerm;
    }
    else if (head->power <= newTerm->power)
    {
        if (head->power == newTerm->power)
        {
            head->coeff += newTerm->coeff;
            free(newTerm);
        }
        else
        {
            newTerm->next = head;
            *headPtr = newTerm;
        }
    }
    else
    {
        while (head->next != NULL && head->next->power > newTerm->power)
        {
            head = head->next;
        }

        if (head != NULL)
        {
            if (head->next != NULL)
            {
                if (head->next->power == newTerm->power)
                {
                    head->next->coeff += newTerm->coeff;
                    free(newTerm);
                }
                else
                {
                    Term *temp = head;
                    newTerm->next = head->next;
                    head->next = newTerm;
                }
            }
            else
            {
                head->next = newTerm;
            }
        }
    }
}

/**
 * @brief prosedur untuk mencetak polinomial
 *
 * @param head head dari polinomial yang ingin dicetak
 */
void print(Term *head)
{
    if (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL)
            printf(" + ");
        print(head->next);
    }
}

int main()
{
    int coeff, power;
    char *token, buffer[256];
    Term *A = NULL;
    Term *B = NULL;

    // Masukkan polinomial A
    printf("Masukkan Polinomial A: ");
    scanf(" %[^\n]s", buffer);
    token = strtok(buffer, " + ");
    while (token != NULL)
    {
        sscanf(token, "%dx^%d", &coeff, &power);
        insert(&A, makeNewTerm(coeff, power));
        token = strtok(NULL, " + ");
    }

    // Masukkan polinomial B
    printf("Masukkan Polinomial B: ");
    scanf(" %[^\n]s", buffer);
    token = strtok(buffer, " + ");
    while (token != NULL)
    {
        sscanf(token, "%dx^%d", &coeff, &power);
        insert(&B, makeNewTerm(coeff, power));
        token = strtok(NULL, " + ");
    }

    // Penjumlahan A dan B
    while (A != NULL)
    {
        Term *temp = A;
        A = A->next;
        temp->next = NULL;
        insert(&B, temp);
    }

    // Mencetak Hasil
    printf("Hasil: ");
    print(B);

    return 0;
}
