#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define maxsize 50
char genders[3][maxsize]={"Male","Other","Female"};
char symptoms[10][maxsize]={"Headache","Nausea","Fever","ButtPain","DryEyes","Heartattk","Dryskin","Dehyrdation","Vomiting","Paralyze"}; 

int counter=0;
int turnaround=0;
//AK: This is the counter arrays
int ge[3];
int sy[10];
//AK: This is the queue arrays
int genp[maxsize];
int symp[maxsize];
//AK: This is the mean wait time for gender and symptom
double gen[3];
double sym[10];

void next(){
	int x=0;
	int r=0;
	int b=0;
	int c=0;
	b=genp[0];
	c=symp[0];
	r=rand()%101;	
	gen[genp[0]]+= (rand() %30)+1.0;
	sym[symp[0]]+=(rand() %30)+1.0;

	for (x=0; x< counter; x++){
		genp[x]=genp[x+1];
		symp[x]=symp[x+1];
	}
		
	if(r>85){
	genp[counter]=b;
	symp[counter]=c;			
	}

	else{
		if (counter>0){
		counter--;	
		}
	}
}
		
void add(){
	int g=0;
	int s=0;
	if(counter==maxsize){
		turnaround++;
		return;
	}
	 g=rand()%3 +1;
	 s=rand()%10 +1;	
	genp[counter]=g-1;
	symp[counter]=s-1;
	ge[g-1]+=1;
	sy[s-1]+=1;
	counter++;
}
void print(){
int x=0;
int y=0;
printf("Gender Mean Wait Times \n");
for (x=0; x<3;x++){
	printf("%s %f \n", genders[x], gen[x]/ge[x]);
	}
printf("Symptom Mean Wait Time \n");
for(y=0; y<10;y++){
	printf("%s %f \n", symptoms[y], sym[y]/sy[y]);
	}
printf("People turned away %d \n", turnaround);
}


void experiment(){
	int t=0;
	int i=0;
	srand((int) time (NULL));	
	for(i=0; i<10000;i++){
		t=rand()%101;
		if(t>50){
			add();
		}
		else{
			next();
		}

	}

}

void reset(){
	int m=0;
	int d=0;
	int p=0;	
	for(m=0; m<3;m++){
		ge[m]=0;
		gen[m]=0.0;	
	}
	for(d=0;d<10;d++){
		sy[d]=0;
		sym[d]=0.0;
	}
	for(p=0; p<maxsize;p++){
		genp[p]=0;
		symp[p]=0;
	}
}

int main(){

reset();
experiment();
print();
return 0;
}
	
