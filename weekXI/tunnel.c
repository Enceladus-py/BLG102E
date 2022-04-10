#include <stdio.h>

int main(){

int box_number;
scanf("%d",&box_number);
int boxes[box_number][3];

for(int i=0;i<box_number;i++){
scanf("%d %d %d",&boxes[i][0],&boxes[i][1],&boxes[i][2]);
}


for(int i=0;i<box_number;i++){
int b=0;
for(int j=0;j<3;j++){

if(boxes[i][j]<=40){
b+=1;
}
}

if(b>=2){
printf("%.2lf\n",(double)boxes[i][0]*boxes[i][1]*boxes[i][2]);
}
}

return 0;
}