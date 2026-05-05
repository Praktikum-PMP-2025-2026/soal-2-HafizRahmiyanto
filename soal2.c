#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char line[], int* output){
int found =1;
    int index=0;
    char temp;
    int i=0;
    int panjang = strlen(line);
    while(found>0){
        found=0;
        for(index; index<panjang; index++){
            temp = line[index];
            if(temp == '(' || temp == ')'){
                i = index;
                found++;
                break;
            }
        }
        if(found>0){
            if(temp == ')'){
                line[i]='2';
                i=0;
                index=0;
            }
            
            else if(temp == '('){
                int tempIndex = i;
                for(int j=tempIndex; j<panjang; j++){
                    if(line[j]=='('){
                        if(j!=panjang-1){
                            int count =0;
                            for(int n=j; n<panjang; n++){
                                if(line[n] == ')'){
                                    count=1;
                                    break;
                                }
                            }
                            if(count > 0){
                                i = j;
                            }
                            else{
                                line[j] ='2';
                            }
                        }
                        else{
                            line[j]='2';
                            index= 0;
                            i=0;
                            break;
                        }
                    }
                    else if(line[j]==')'){
                        line[j]='1';
                        line[i]= '0';
                        i=0;
                        index =0;
                        break;
                    }
                }
            }
        }
    }

    for(int k =0; k<panjang; k++){
        if (line[k] == '2'){
            (*output)++;
        }
    }
    return;
}

int main(){
    char buff[50];
    int N = 0;
    scanf("%s", buff);
    input(buff, &N);
    printf("%d\n", N);
    return 0;
}
