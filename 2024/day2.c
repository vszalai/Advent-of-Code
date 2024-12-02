#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *inputfile = fopen("input_day2.txt","r");

    char temp[128];
    int i = 0;
    int increasing = 0;
    int safe_reports = 0;
    int safety_temp = 0;
    int numbers[16];
    int j = 0;

    while((fgets(temp,sizeof(temp),inputfile)) != NULL){
        numbers[j] = 0;
        while(temp[i] != '\n'){
            if(temp[i] == ' '){
                i++;
                j++;
                numbers[j] = 0;
            }
            else{
                numbers[j] = numbers[j] * 10 + (temp[i] - '0');
                i++;
            }
        }
        if(numbers[0] - numbers[1] > 0){increasing=0;}
        else{increasing=1;}
        for(i= 0;i<j;i++){

            if(increasing){
                if(!((numbers[i] - numbers[i+1]) <= -1 && (numbers[i] - numbers[i+1]) >= -3)){
                    break;
                }
                safety_temp += 1;
            }

            else if(!increasing){
                if(!((numbers[i] - numbers[i+1] )>= 1 && (numbers[i] - numbers[i+1]) <= 3)){
                    break;
                }
                safety_temp += 1;
            }

        }
        if(safety_temp == j){
            safe_reports +=1;
        }
        safety_temp = 0;
        i=0;
        j=0;

    }

    for(i=0;i<sizeof(numbers);i++){
        printf("%d\n",numbers[i]);
    }



    printf("\n%d\n",safe_reports);

    fclose(inputfile);
    return 0;
}