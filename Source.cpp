#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>
#include <math.h> 
void ToUpper(char *p)
{
	for (int i = 0; i < strlen(p); i++)
	{
		p[i] = toupper(p[i]);
	}
}
bool isHexa(char *p)
{
	for (int i = 0; i < strlen(p); i++)
	{
		if ((p[i]>='0'&&p[i]<='9')||(p[i]>='A'&&p[i]<='F'))
			continue;
		else
			return false;
	}
	return true;
}
int main()
{
	char* pHexa = (char*)malloc(10*sizeof(char));
	printf("Enter HEX number : ");
	scanf("%s",pHexa);
	ToUpper(pHexa);
	if(isHexa(pHexa)== 0)
	{
		printf("Not a Hexa number\n");
		return 0;
	}
	double count = strlen(pHexa);
	double answer = 0;
	for (int i=0;i<strlen(pHexa);i++)
	{
		if (pHexa[i] >= '0' && pHexa[i] <= '9')
			answer +=(pHexa[i] - 48.0)*pow(16,count-1);
		else if(pHexa[i] >= 'A' && pHexa[i]<= 'F')
			answer += ((pHexa[i] - 65.0)+10.0) * pow(16, count-1);
		count -= 1;
	}
	printf("%s = %.0f", pHexa,answer);
	return 0;
}