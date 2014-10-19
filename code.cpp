#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int NumOfArgs(char *);
char *partition(char *);

bool argument(char *);
char *funplus(int *);
char *funminus(int *);
char *funmultiplication(int *);
char *fundivision(int *);
char *funfactorial(int *);

void main()
{
	char  str[100];
	gets(str);
	//cout<<endl<<str;

/*	char **b = new char*[2];
	int i=0;
	b[0] = &str[0];
	while(str[i] != '\0')
	{
		if(str[i] == ' ') {str[i]='\0'; b[1] = &str[i+1];}
		i++;
	}
	*/
	//cout<<b[0]<<"    "<<b[1];

	//cout<<endl<<NumOfArgs(str);

	cout<<partition(str);
	getch ();
}

int NumOfArgs(char*s)
{
	int num = 0;
	int skobka = 0;
	int i = 1;
	while(s[i]!='\0')
	{
		if(s[i] == '(')skobka++;
		if(s[i] == ')')skobka--;
		if(skobka == 0 && s[i] == ' ')num++;
		i++;
	}

	return num;
}

char *partition(char *s)
{
	int num = NumOfArgs(s);
	char **b = new char*[num];
	int *args = new int[num + 1];
	args[0] = num;
	
	int k=0;
	while(s[k] != ' ')k++;

	char *znak = new char [k];
	for(int i=0; i < k; i++)
	{
		znak[i] = s[i+1];
	}
	znak[k-1]='\0';
	cout<<znak;

	b[0] = &s[3];
	int skobka = 0;
	int i = 3, j = 1;
	
	while(s[i]!='\0')
	{
		if(s[i] == '(')skobka++;
		if(s[i] == ')')skobka--;
		if(skobka == 0 && s[i] == ' ')
		{ 
			s[i] = '\0';
			b[j] = &s[i+1];
			j++;
		}
		i++;
	}
	s[i-1]='\0';
	for(int i = 0; i < num; i++ )
	cout<<b[i]<<endl;
	cout<<"--------------------"<<endl;
		for(int i = 0; i < num; i++ )
		{
			if(!argument(b[i]))b[i] = partition(b[i]);
			//else args[i]=atoi(b[i]);
		}

		for(int i = 0; i < num; i++ )
		{
			//if(strlen(b[i]) != 1)b[i] = partition(b[i]);
			 args[i+1]=atoi(b[i]);
		}
		 
	char *a;

		if(strcmp(znak,"+") == 0)a=funplus(args);
		if(strcmp(znak,"-") == 0)a=funminus(args);
		if(strcmp(znak,"*") == 0)a=funmultiplication(args);
		if(strcmp(znak,"/") == 0)a=fundivision(args);
		if(strcmp(znak,"!") == 0)a=funfactorial(args);
		
		delete [] args;
		delete [] znak;
	/*	for(int i=num-1 ; i > -1; i--)
		{
			delete b[i];
		}*/
	//	delete b;

		return a;
}

bool argument(char *arg)
{
	int i=0;
	while(arg[i]!=0)
	{
		if(arg[i]=='('||arg[i]==')')return false;
		i++;
	}
	return true;
}

char *funplus(int *arg)
{
		int sum=0;
		int num = arg[0];
		 for(int i = 0; i < num; i++ )
		 {
			 sum+=arg[i+1];
		 }
		 char* a = new char;
		itoa(sum, a,10);
		return a;
}

char *funminus(int *arg)
{
	int razn=arg[1]-arg[2];
	char* a = new char;
		itoa(razn, a,10);
		return a;
}

char *funmultiplication(int *arg)
{
	int proizv=1;
		int num = arg[0];
		 for(int i = 0; i < num; i++ )
		 {
			 proizv*=arg[i+1];
		 }
		 char* a = new char;
		itoa(proizv, a,10);
		return a;
}

char *fundivision(int *arg)
{
	int chasnoe=arg[1]/arg[2];
	char* a = new char;
		itoa(chasnoe, a,10);
		return a;
}

char *funfactorial(int *arg)
{
	int fact=1;
	for (int i=1; i<arg[1]+1; i++)
	{
		fact*=i;
	}
	char* a = new char;
		itoa(fact, a,10);
		return a;
}