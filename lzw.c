#include <stdio.h>

int main(){

unsigned char **dict;
int *dlength;
unsigned char p[80], temp[80];
char c;
int plength,i,j,k,diff,cd;

plength=1;
cd=256;
p[0]=EOF;
FILE *Fpt;
Fpt = fopen("testcomp.txt","r");
FILE *outfile;
outfile = fopen("output3.txt","w");
dict= (unsigned char *)malloc(99999); //Allocating memory for Dictionary
if(dict == NULL)
	printf("Unable to allocate memory \n");
	dlength=(int *)malloc(99999);
for (i = 0; i < 99999; i++) {
	dict[i]=(unsigned char *)malloc(60);
if(dict[i]==NULL)
	printf("Unable to allocate memory \n");
}

for (i=0;i<256;i++) //loading dictionary with ASCII set
{
	dict[i][0]=i;
	dlength[i]=1;
}

while ((c = fgetc(Fpt)) != EOF)
{
	if(cd==256){
		p[0]=(unsigned char *)c;
		diff=0;
	}
	for (i=0; i<cd; i++)
	{		
		for (k=0; k<plength; k++) //checking to see if p+c in dict
		{
			if(dict[i][k]!=p[k])
				diff=1;
		}
	}

	if (diff==0)
	{
		p[plength]=(unsigned char)c;
		plength++;
	}

	if (diff==1)
	{
		for (i=0; i<cd; i++)
	{
	for (k=0; k<plength; k++)
	{
		if(dict[i][k]!=p[k])
		diff=1;
	}
	if (diff==0)
		j=i;
	}
fputc(j, outfile);


	for (i=0; i<plength; i++)
	{
		dict[cd][i]= p[i];
	}
	dict[cd][plength]=(unsigned char)c;
	cd++;
	p[0]=c;
	}
}

for (i=0; i<cd; i++)
{
	for (k=0; k<plength; k++)
	{
		if(dict[i][k]!=p[k])
		diff=1;
	}
	if (diff==0)
	j=i;
}

fputc(j, outfile);

fclose(outfile);
fclose(Fpt);

}
