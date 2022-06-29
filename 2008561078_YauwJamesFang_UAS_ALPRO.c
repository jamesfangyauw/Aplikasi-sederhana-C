#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h> 

void init(int longOfAssignedArray, int NorP, int* arrayInit, int* unsortedArray);
int isPrime(int randomNum);
void printArray (int* array, int longOfAssignedArray, FILE* pointerToFile);
void swap (int* number1, int* number2);
void sort(int* array, int longOfAssignedArray, char* pilUrut, int pilSorting);
int search (int* array, int numberToFind, char* pilUrut, int longOfAssignedArray, int* findedNumberIndex);
int insert (int* array, int numbertoInsert, char* pilUrut, int* longOfAssignedArray);

void main(){
    int programStatus = 1;
    char* token;
    char NorP, pilUrut[10], tempStringInput[60], stringInput[20], buffer[26];
    int longOfAssignedArray, unsortedArray[20], array[20], pilSorting, pilihanMenu, numberToFind;
    int numberToInsert, beforeUpdate, afterUpdate, findedNumberIndex;
    int numberToDelete, tryToCreateFile = 1;
    
    time_t timer;
    struct tm* tm_info;
    
    FILE* pointerToFile;

    puts("");
    puts("   Yauw James Fang Dwiputra Harta   ");
    puts("          2008561078          ");
    puts("      Kelas C Informatika     ");

    while (programStatus)
    {
        int sum = 0, tempIndexLoop = 0, manyEvenOrOddNumber = 0, loopForRenoveComma = 0;

        printf("\n******************************\n");                         
        puts("******* UAS Alpro 2020 *******");
        puts("* Pilih di antara angka 1-14 *");
        puts("******************************");
        printf("1. Init\t\t8. Min\n");
        printf("2. Sort\t\t9. Max\n");
        printf("3. Search\t10. Average\n");
        printf("4. Insert\t11. Ganjil\n");
        printf("5. Update\t12. Genap\n");
        printf("6. Delete\t13. Exit & Saved\n");
        printf("7. Count\t14. Exit Without Save\n");
        printf("Masukkan pilihan : "); scanf("%d", &pilihanMenu); getchar();
        puts("");

        switch (pilihanMenu){
            

            case 1:
                if (tryToCreateFile == 1) {
                        timer = time(NULL);
                        tm_info = localtime(&timer);

                        strftime(buffer, 26, "%Y-%m-%d %H-%M-%S", tm_info);
                        strcat(buffer,".txt");
                        pointerToFile = fopen(buffer, "a");
                        tryToCreateFile++;
                }

                do {
                    printf ("input: init("); scanf ("%d, %c)", &longOfAssignedArray, &NorP);
                    fprintf (pointerToFile, "input: init("); fprintf (pointerToFile, "%d, %c)\n", longOfAssignedArray, NorP);
                    getchar ();      
                } while (! (longOfAssignedArray >= 0 && longOfAssignedArray <= 20) && (NorP == 'n' || NorP == 'p'));

                puts("Output:");
                printf("Init:");

                fprintf(pointerToFile, "Output:\nInit:");
                
                init (longOfAssignedArray, NorP, array, unsortedArray);
                printArray (array, longOfAssignedArray, pointerToFile);
                fprintf (pointerToFile, "\n");
            continue;

            case 2:
                do {
                    printf ("input: sort("); scanf ("%s", tempStringInput); getchar();
                    fprintf (pointerToFile, "input: sort("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    token = strtok (NULL,",");
                    strcpy (pilUrut, token);
                    token = strtok (NULL,",");
                    pilSorting = atoi (token);
                } while (! ( (pilSorting <= 3 && pilSorting >= 1) && (strcmp (pilUrut,"\"asc\"") == 0 || strcmp (pilUrut,"\"desc\"") ==0 ) ) );

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (unsortedArray, longOfAssignedArray, pointerToFile);

                switch (pilSorting) {
                    case 1:
                        puts ("Metode: Bubble Sort");
                        fprintf (pointerToFile, "Metode: Bubble Sort\n");
                    break;
                    
                    case 2:
                        puts ("Metode: Selection Sort");
                        fprintf (pointerToFile, "Metode: Selection Sort\n");
                    break;
                    
                    case 3:
                        puts ("Metode: Insertion Sort");
                        fprintf (pointerToFile, "Metode: Insertion Sort\n");
                    break;
                }

                printf ("Sort:");
                fprintf (pointerToFile, "Sort:");
                sort (array, longOfAssignedArray, pilUrut, pilSorting);
                printArray (array, longOfAssignedArray, pointerToFile);
                fprintf (pointerToFile, "\n");
            continue;

            case 3:
                do {
                    printf ("input: search("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: search("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    numberToFind = atoi (token);
                    token = strtok (NULL,",");
                    token = strtok (NULL,",");
                    strcpy (pilUrut,token);
                } while (! (strcmp(pilUrut,"\"asc\"") == 0 || strcmp (pilUrut,"\"desc\"") == 0) );

                printf ("Output:\nArray:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);
                
                sort (array, longOfAssignedArray, pilUrut, 1);
                printf ("Sort:");
                fprintf (pointerToFile, "Sort:");
                printArray (array, longOfAssignedArray, pointerToFile);
                
                printf ("Search: ");
                if (search (array, numberToFind, pilUrut, longOfAssignedArray, &findedNumberIndex) == 1) {
                    printf ("%d ditemukan pada indeks ke-%d", numberToFind, findedNumberIndex + 1);
                    fprintf (pointerToFile, "%d ditemukan pada indeks ke-%d", numberToFind, findedNumberIndex + 1);
                }
                else {
                    printf ("%d tidak ada dalam array", numberToFind);
                    fprintf (pointerToFile, "%d tidak ada dalam array", numberToFind);
                }
                printf("\n");
                fprintf (pointerToFile, "\n\n");
            continue;

            case 4:
                do {
                    printf ("input: insert("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: insert("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    numberToInsert = atoi (token);
                    token = strtok (NULL,",");
                    strcpy (pilUrut,token);
                } while (! (strcmp(pilUrut,"\"asc\"") == 0 || strcmp (pilUrut,"\"desc\"") == 0));

                puts ("");
                puts ("Output");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);
                
                printf ("Sort:");
                fprintf (pointerToFile, "Sort:");
                sort (array, longOfAssignedArray, pilUrut, 1);
                printArray (array, longOfAssignedArray, pointerToFile);

                printf ("Insert:");
                fprintf (pointerToFile, "Insert:");
                if (insert (array, numberToInsert, pilUrut, &longOfAssignedArray) == 1) {
                    printArray (array, longOfAssignedArray, pointerToFile);
                }
                else {
                    printf (" FULL - index out of bound founded\n");
                    fprintf (pointerToFile, " FULL - index out of bound founded\n");
                }

                fprintf (pointerToFile, "\n");
            continue;
                
            case 5:
               do {
                    printf ("input: update("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: update("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    beforeUpdate = atoi (token);
                    token = strtok (NULL,",");
                    afterUpdate = atoi (token);
                    token = strtok (NULL,",");
                    strcpy (pilUrut,token);
                } while (! (strcmp (pilUrut,"\"asc\"") == 0 || strcmp (pilUrut,"\"desc\"") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);
                sort (array, longOfAssignedArray, pilUrut, 1);
                printf ("Sorting:");
                fprintf (pointerToFile, "Sorting:");
                printArray (array, longOfAssignedArray, pointerToFile);

                if (search (array, beforeUpdate, pilUrut, longOfAssignedArray, &findedNumberIndex) == 1) {
                    printf ("Update:");
                    fprintf (pointerToFile, "Update:");
                    array [findedNumberIndex] = afterUpdate;
                    sort  (array, longOfAssignedArray, pilUrut, 1);
                    printArray (array, longOfAssignedArray, pointerToFile);
                }
                else {
                    printf ("Update: Tidak ditemukan nilai %d\n", beforeUpdate);
                    fprintf (pointerToFile, "Update: Tidak ditemukan nilai %d\n", beforeUpdate);
                    printf ("Insert:");
                    fprintf (pointerToFile, "Insert:");
                    insert (array, beforeUpdate, pilUrut, &longOfAssignedArray);
                    printArray (array, longOfAssignedArray, pointerToFile);
                }

                fprintf (pointerToFile, "\n");
            continue;

            case 6:
                do {
                    printf ("input: delete("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: delete("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    numberToDelete = atoi (token);
                    token = strtok (NULL,",");
                    strcpy (pilUrut,token);
                } while (! (strcmp (pilUrut,"\"asc\"") == 0 || strcmp (pilUrut,"\"desc\"") == 0));
                
                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);
                
                printf ("Sorting:");
                fprintf (pointerToFile, "Sorting:");
                sort (array, longOfAssignedArray, pilUrut, 1);
                printArray (array, longOfAssignedArray, pointerToFile);

                printf ("Delete:");
                fprintf (pointerToFile, "Delete:");
                if (search (array, numberToDelete, pilUrut, longOfAssignedArray, &findedNumberIndex) == 1) {
                    for (int i = findedNumberIndex ; i < longOfAssignedArray; i++) {
                        array [i] = array [i + 1];
                    }
                    longOfAssignedArray--;
                    printArray (array, longOfAssignedArray, pointerToFile);
                }
                else
                {
                    printf (" %d tidak ditemukan pada Array", numberToDelete);
                    fprintf (pointerToFile, " %d tidak ditemukan pada Array\n", numberToDelete);
                }

                fprintf (pointerToFile, "\n");
            continue;

            case 7:
                do{
                    printf ("input: count("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: count("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));
                
                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                printf ("Count: %d item\n\n", longOfAssignedArray);
                fprintf(pointerToFile, "Count: %d item\n\n", longOfAssignedArray);
            continue;

            case 8:
                do {
                    printf ("input: min("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: min("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf(pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                sort (array, longOfAssignedArray, "\"asc\"", 1);
                printf ("Min: %d\n", array[0]);
                fprintf (pointerToFile, "Min: %d\n", array[0]);

                fprintf (pointerToFile, "\n\n");
            continue;

            case 9:
                do {
                    printf ("input: max("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: max("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                sort (array, longOfAssignedArray, "\"desc\"", 1);
                printf ("Max: %d\n", array[0]);
                fprintf (pointerToFile, "Max: %d\n", array[0]);

                fprintf (pointerToFile, "\n\n");
            continue;

            case 10:
                do {
                    printf ("input: average("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: average("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                for (int i = 0; i < longOfAssignedArray; i++) {
                    sum = sum + array[i];
                }

                printf("Average: %d/%d = %.2f\n", sum, longOfAssignedArray, (float) sum/longOfAssignedArray);
                fprintf (pointerToFile, "Average: %d/%d = %.2f\n", sum, longOfAssignedArray, (float) sum/longOfAssignedArray);

                fprintf (pointerToFile, "\n\n");
            continue;

            case 11:
                do {
                    printf ("input: ganjil("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: ganjil("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                printf ("Ganjil: ");
                fprintf (pointerToFile, "Ganjil: ");
                for (int i = 0; i < longOfAssignedArray; i++) {
                    if (array[i] % 2 != 0) {
                        while (loopForRenoveComma < manyEvenOrOddNumber) {
                            printf(",");
                            fprintf (pointerToFile, ",");
                            loopForRenoveComma++;
                        }
                        manyEvenOrOddNumber++;
                        printf ("%d", array[i]);
                        fprintf (pointerToFile,"%d", array[i]);
                    }
                }
                printf("\n");
                fprintf (pointerToFile, "\n");
                printf("Jumlah bilangan ganjil: %d\n", manyEvenOrOddNumber);
                fprintf (pointerToFile, "Jumlah bilangan ganjil: %d\n", manyEvenOrOddNumber);

                fprintf (pointerToFile, "\n\n");
            continue;

            case 12:
                do {
                    printf ("input: genap("); scanf ("%[^)]s", tempStringInput); getchar ();
                    fprintf (pointerToFile, "input: genap("); fprintf (pointerToFile, "%s)\n", tempStringInput);
                    token = strtok (tempStringInput,",");
                    strcpy (stringInput,token);
                } while (! (strcmp (stringInput,"array") == 0));

                puts ("Output:");
                printf ("Array:");
                fprintf (pointerToFile, "Output:\nArray:");
                printArray (array, longOfAssignedArray, pointerToFile);

                printf ("Genap: ");
                fprintf (pointerToFile, "Genap: ");
                for (int i = 0; i < longOfAssignedArray; i++) {
                    if (array[i] % 2 == 0) {
                        while (loopForRenoveComma < manyEvenOrOddNumber) {
                            printf(",");
                            fprintf (pointerToFile, ",");
                            loopForRenoveComma++;
                        }
                        manyEvenOrOddNumber++;
                        printf ("%d", array[i]);
                        fprintf (pointerToFile,"%d", array[i]);
                    }
                }
                printf("\n");
                printf("Jumlah bilangan genap: %d\n", manyEvenOrOddNumber);
                fprintf (pointerToFile, "Jumlah bilangan ganjil: %d\n", manyEvenOrOddNumber);

                fprintf (pointerToFile, "\n\n");
            continue;

            case 13:
            fclose (pointerToFile);
            programStatus = 0;
            continue;

            case 14:
            programStatus = 0;
            continue;

            default:
            continue;
        }   
    }
}

void printArray (int* array, int longOfAssignedArray, FILE* pointerToFile) {
    for (int i = 0; i < longOfAssignedArray; i++)
        printf(" [%d]", array[i]);
    for (int i = 0; i < longOfAssignedArray; i++)
        fprintf(pointerToFile, " [%d]", array[i]);
    for (int i = 0; i < 20 - longOfAssignedArray; i++)
        printf(" []");
    for (int i = 0; i < 20 - longOfAssignedArray; i++)
        fprintf(pointerToFile, " []");
    fprintf(pointerToFile, "\n");
    puts("");
}

int isPrime (int random){
    int sqrtRandom = sqrt(random);
    if (random == 2 || random == 3){
        return 1;
    }
    else if (random == 0 || random == 1){
        return 0;
    }
    else{
        for (int randomNumDivider = 2; randomNumDivider <= sqrtRandom; randomNumDivider++){
            if (random % randomNumDivider == 0){
                return 0;   
            }
        }
        return 1;
    }
    return 0;
}

void swap (int* number1, int* number2) {
    int temp = 0;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void init (int longOfAssignedArray, int NorP, int* array, int* unsortedArray){
    int a = 0, random, sqrtRandom;
    srand(time(0));
    if (NorP=='n') {
        while(a < longOfAssignedArray){
            random = rand();
            srand(random);
            array[a] = random;
            unsortedArray[a] = random;
            a++;
        }
    }
    else if (NorP == 'p') {
        while(a < longOfAssignedArray) {
            random = rand();
            srand(random);
            if (isPrime(random)) {
                array[a] = random;
                unsortedArray[a] = random;
                a++;
            }
        }
    }
}

void sort (int* array, int longOfAssignedArray, char* pilUrut, int pilSorting) {
    int swapped, count = 0, tempAssignedArray = longOfAssignedArray;
    if (strcmp(pilUrut,"\"asc\"") == 0) {
        switch (pilSorting) {
        case 1:
            /* Bubble Sort */
            do {
                swapped = 0;
                for (int i = 0; i < tempAssignedArray - 1; i++) {
                    if (array[i] > array[i + 1]) {
                        swap(&array[i], &array[i + 1]);
                        swapped = 1;
                    }            
                }
                tempAssignedArray--;
            } while (swapped);
            break;

        case 2:
            /* Selection Sort*/
            while (count < longOfAssignedArray){
                int newMinimumIndex = count, count2 = count, minimum = array[count];
                while (count2 < longOfAssignedArray){
                    if (array[count2] < minimum){
                        newMinimumIndex = count2;
                        minimum = array[count2];
                    }
                    count2++;
                }
                swap(&array[newMinimumIndex], &array[count]);
                count++;
            }
            break;
            
        case 3:
            /* Insertion Sort*/
            do{
                int count2 = count;
                while (count2 > 0) {
                    if (array[count2] < array[count2 - 1]) {
                        swap(&array[count2], &array[count2 - 1]);
                    }
                    else {
                        break;
                    }
                    count2--;
                }
                count++;
            } while (count < longOfAssignedArray);
            break;

        default:
        puts("Masukkan pilihan antara 1-3");
            break;
        }
    }
    else if (strcmp(pilUrut,"\"desc\"") == 0) {
        switch (pilSorting) {
            case 1:
                /* Bubble Sort */
                do {
                    swapped = 0;
                    for (int i = 0; i < tempAssignedArray - 1; i++) {
                        if (array[i] < array[i + 1]) {
                            swap(&array[i], &array[i + 1]);
                            swapped = 1;
                        }            
                    }
                    tempAssignedArray--;
                } while (swapped);
                break;

            case 2:
                /* Selection Sort*/
                while (count < longOfAssignedArray){
                    int newMinimumIndex = count, count2 = count, minimum = array[count];
                    while (count2 < longOfAssignedArray){
                        if (array[count2] > minimum){
                            newMinimumIndex = count2;
                            minimum = array[count2];
                        }
                        count2++;
                    }
                    swap(&array[newMinimumIndex], &array[count]);
                    count++;
                }
                break;
                
            case 3:
                /* Insertion Sort*/
                do{
                    int count2 = count;
                    while (count2 > 0)
                    {
                        if (array[count2] > array[count2 - 1]) {
                            swap(&array[count2], &array[count2 - 1]);
                        }
                        else{
                            break;
                        }
                        count2--;
                    }
                    count++;
                } while (count < longOfAssignedArray);
                break;

            default:
            puts("Masukkan pilihan antara 1-3");
                break;
        }
    } 
}

int search (int* array, int numberToFind, char* pilUrut, int longOfAssignedArray, int* findedNumberIndex) {
    int theFirst = 0, theLast = longOfAssignedArray, theMiddle = ((theFirst+theLast)/2);
    while (theFirst <= theLast){
        if(array[theMiddle] == numberToFind) {
            *findedNumberIndex = theMiddle;
            return 1;
        }
        else if (numberToFind < array[theMiddle]) {
            theLast = theMiddle;
            theMiddle = ((theLast + theFirst) / 2);
        }
        else if (numberToFind > array[theMiddle]) {
            theFirst = theMiddle ;
            theMiddle = ((theLast + theFirst) / 2);
        }
    } 
    return 0;
}

int insert (int* array, int numbertoInsert, char* pilUrut, int* longOfAssignedArray) {
    int leftOfSortedArray[20], rightOfSortedArray[20], indexOfLeftElement, indexOfRightElement;
    if (*longOfAssignedArray < 19) {
        if (strcmp(pilUrut,"\"asc\"") == 0){
            for (int i = 0; i < *longOfAssignedArray; i++) {
                if (i == 0 && numbertoInsert < array[i]) {
                    indexOfLeftElement = -1;
                    indexOfRightElement = i;
                    for (int j = indexOfRightElement; j < *longOfAssignedArray; j++) {
                        rightOfSortedArray[j] = array[j];
                    }
                    break;
                }
                else if (array[i-1] < numbertoInsert && array[i] > numbertoInsert) {
                    indexOfLeftElement = i - 1;
                    indexOfRightElement = i;
                    for (int j = 0; j <= indexOfLeftElement; j++) {
                        leftOfSortedArray[j] = array[j];
                    }
                    for (int j = indexOfRightElement; j < *longOfAssignedArray; j++) {
                        rightOfSortedArray[j] = array[j];
                    }
                    break;
                }
                else if (i == *longOfAssignedArray - 1 && numbertoInsert > array[i]) {
                    indexOfRightElement = *longOfAssignedArray;
                    indexOfLeftElement = *longOfAssignedArray - 1;
                    for (int j = 0; j <= indexOfLeftElement; j++) {
                        leftOfSortedArray[j] = array[j];
                    }
                }
            }
        }
        else if(strcmp(pilUrut,"\"desc\"") == 0)
        {
             for (int i = 0; i < *longOfAssignedArray; i++) {
                if (i == 0 && numbertoInsert > array[i]) {
                    indexOfLeftElement = -1;
                    indexOfRightElement = i;
                    for (int j = indexOfRightElement; j < *longOfAssignedArray; j++) {
                        rightOfSortedArray[j] = array[j];
                    }
                    break;
                }
                else if (array[i-1] < numbertoInsert && array[i] > numbertoInsert) {
                    indexOfLeftElement = i - 1;
                    indexOfRightElement = i;
                    for (int j = 0; j <= indexOfLeftElement; j++) {
                        leftOfSortedArray[j] = array[j];
                    }
                    for (int j = indexOfRightElement; j < *longOfAssignedArray; j++) {
                        rightOfSortedArray[j] = array[j];
                    }
                    break;
                }
                else if (i == *longOfAssignedArray - 1 && numbertoInsert < array[i]) {
                    indexOfRightElement = *longOfAssignedArray;
                    indexOfLeftElement = *longOfAssignedArray - 1;
                    for (int j = 0; j <= indexOfLeftElement; j++) {
                        leftOfSortedArray[j] = array[j];
                    }
                }
            }
        }
        for (int i = 0; i <= indexOfLeftElement; i++) {
            array[i] = leftOfSortedArray[i];
        }
        *longOfAssignedArray = *longOfAssignedArray + 1;
        array[indexOfLeftElement + 1] = numbertoInsert;
        for (int i = indexOfRightElement + 1; i < *longOfAssignedArray; i++) {
            array[i] = rightOfSortedArray[i - 1];
        }
        return 1;
    }
    else {
        return 0;
    }
    
}


