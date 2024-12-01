#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int main(){
    FILE *inputfile = fopen("input_day1.txt","r");
    int lines = 0;
    char a;
    //Count the number of lines
    while ((a = fgetc(inputfile)) != EOF){
        if(a == '\n'){
            lines++;
        }
    }
    rewind(inputfile);


    int list1[lines];
    int list2[lines];
    char temp[512];
    int i = 0;
    int j = 0;
    //Create 2 lists of the inputs
    while ((fgets(temp,sizeof(temp),inputfile)) != NULL){
        list1[j] = 0;
        list2[j] = 0;
        while(temp[i] != '\n'){
            if(temp[i] == ' '){
                i += 3;
                while(temp[i] != '\n'){
                    list2[j] = list2[j] * 10 + (temp[i] - '0');
                    i++;
                }
                break;
            }


            list1[j] = list1[j] * 10 + (temp[i] - '0');
            

            i++;
        }
        j++;
        i=0;
    }

    qsort(list1,lines,sizeof(int),compare);
    qsort(list2,lines,sizeof(int),compare);

    int distance = 0;
    for(i=0;i<lines;i++){
        distance += abs(list1[i] - list2[i]);
    }
    printf("%d\n",distance);

    int similarity = 0;
    int amount = 0;

    for(i=0;i<lines;i++){
        for(j=0;j<lines;j++){
            if (list1[i] == list2[j]){
                amount++;
            }
        }
        similarity += list1[i] * amount;
        amount=0;


    }
    
    printf("%d\n", similarity);


    fclose(inputfile);
    return 0;
}