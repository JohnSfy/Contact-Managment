#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 5

FILE  *fp;



char Name[100],SearchName[100],Address[100],Email[100],Gender[8],k,ch;

char  Phone[10];

void searchContact();

void UpdateContact();

void DeleteContact();

void ListContacts();

void title(void);

void addContact();

void exitEnv(void);

int choice,l,i,j,found,f;

int main()
{
MAIN:

	system("cls");
	title();
	printf("  1.Add New Contact\n");
	printf("  2.Search Contact\n");
	printf("  3.Update Contact\n");
	printf("  4.Delete Contact\n");
	printf("  5.List Contacts\n");
	printf("  6.Exit\n\n");

	printf("-------------------------------------------------------------------------------------------------\n\n");

	printf("Input choice(1-6):");
	scanf("%d",&choice);

	switch (choice)
	{
		case 1:
			system("cls");
			title();
			printf("--> Add New Contact\t|\n");
		    printf("-------------------------\n");

			addContact();

			printf("Press m for menu:");

			fflush(stdin);
		    while(k=getchar())
	        {
		       switch(k)
		       {
			      case 'm':
			        goto MAIN;
			      break;

		    	default:
				    printf("Wrong input! Press m for menu:");
				    fflush(stdin);

			      break;
				}
       	    }

		break;

		case 2:
			system("cls");

			title();

			printf("--> Search Contact\t|\n");
			printf("-------------------------\n\n");



		  	searchContact();

		 	printf("\n\nPress m for menu:");

			fflush(stdin);
		    while(k=getchar())
	        {
		       switch(k)
		       {
			      case 'm':
			        goto MAIN;
			      break;

		    	  default:
				    printf("Wrong input! Press m for menu:");
				    fflush(stdin);

			      break;
				}

		break;

		case 3:
			system("cls");

			title();

			printf("--> Update Contact\t|\n");

			UpdateContact();

			printf("Press m for menu:");

			fflush(stdin);
		    while(k=getchar())
	        {
		       switch(k)
		       {
			      case 'm':
			        goto MAIN;
			      break;

		    	default:
				    printf("Wrong input! Press m for menu:");
				    fflush(stdin);

			      break;
				}
       	    }




		break;

		case 4:
            system("cls");

			title();

			printf("--> delete Contact\t|\n");

			DeleteContact();

			printf("Press m for menu:");

			fflush(stdin);
		    while(k=getchar())
	        {
		       switch(k)
		       {
			      case 'm':
			        goto MAIN;
			      break;

		    	default:
				    printf("Wrong input! Press m for menu:");
				    fflush(stdin);

			      break;
				}
       	    }






		break;

		case 5:
		         system("cls");

			title();

			printf("--> List Contacts\t|\n");

			ListContacts();

			printf("Press m for menu:");

			fflush(stdin);
		    while(k=getchar())
	        {
		       switch(k)
		       {
			      case 'm':
			        goto MAIN;
			      break;

		    	default:
				    printf("Wrong input! Press m for menu:");
				    fflush(stdin);

			      break;
				}
       	    }







		break;

		case 6:
		    title();
			exitEnv();

			return(0);
		break;

		default:

	        printf("\nError: Wrong choice\n");
	        printf("Programm Terminated\n");

		break;
	}

return(0);
}
}



void exitEnv(void)
{
	system("cls");

	printf("\nYou exited programm. Programm terminated.\n ");
}

void addContact()
{

	fp=fopen("contact.txt","a");

	fflush(stdin);

	printf("\tName: ");

	scanf("%s",&Name);

    fflush(stdin);

	printf("\tAddress: ");

	scanf("%s",&Address);

	fflush(stdin);

	printf("\tGender: ");

	scanf("%s",&Gender);

    fflush(stdin);

	printf("\tEmail: ");

	scanf("%s",&Email);

	fflush(stdin);

	printf("\tPhone Number: ");

	scanf("%s",&Phone);

	fprintf(fp,"%s %s %s %s %s\n",Name,Address,Gender,Email,Phone);

	fflush(stdin);

	printf("\nNew entry added!\n");


	fclose(fp);

}


void searchContact()
{
	char *ptr1;
	char *ptr2;
	char *ptr3;
	char *ptr4;
	char *ptr5;
	char ch =0;

	int found=0;



	FILE *fp;

	fp=fopen("contact.txt","r");

    printf("Enter name contact name:");
	scanf("%s", SearchName);

    while(!feof(fp) && found==0)
	{
		fscanf(fp,"%s %s %s %s %s", Name, Address, Gender, Email, Phone);


		ptr1=Name;

		if (strcmp(ptr1,SearchName)==0)
    	{
        	found =1;
        	printf("Record Found!\n\n");
        	printf("-------------------------\n");
        	printf("Name: %s\n",Name);
        	printf("Address: %s\n",Address);
        	printf("Gender: %s\n",Gender);
        	printf("Email: %s\n",Email);
        	printf("Phone Number: %s\n",Phone);
        	printf("-------------------------\n");
        	fclose(fp);
        	return;
    	}

    }
    fclose(fp);
    printf("\nContact not found!");
}

void UpdateContact()
{
	int found=0;
	char *ptr1,ch;


	FILE *fp;
	FILE *fp2;



	printf("Enter name contact name:");
	scanf("%s", SearchName);//The user enters the name that he wants to update
    fp=fopen("contact.txt","r+");
    fp2=fopen("update.txt","w+");
    while(!feof(fp))
	{


		fscanf(fp,"%s %s %s %s %s\n", Name, Address, Gender, Email, Phone);

		ptr1=Name;

		if (strcmp(ptr1,SearchName)==0)
    	{
            found =1;
			char address[100];
			printf("Enter new address: ");
			scanf("%s", address);

			char gender[100];
			printf("Enter new gender: ");
			scanf("%s", gender);

			char email[100];
			printf("Enter new email: ");
			scanf(" %s", email);

			char phone[10];
			printf("Enter new phone: ");
			scanf(" %s", phone);

			fprintf(fp2,"%s %s %s %s %s\n", &Name,&address,&gender,&email,&phone);




    	}
    	else{

            fprintf(fp2,"%s %s %s %s %s\n", &Name, &Address, &Gender, &Email, &Phone);



    	}




    }
    if(found==0)
    {
        printf("contact not found\n");

     }
    else {
    fclose(fp);
    fclose(fp2);
    remove("contact.txt");
    rename("update.txt","contact.txt");
    printf("Contact updated\n");}

}




void DeleteContact()
{

    char *ptr1;

     FILE *fp;
	FILE *fp2;
     int found=0;


	printf("Enter  contact name:");
	scanf("%s", SearchName);//The user enters the name that he wants to update
    fp=fopen("contact.txt","r+");
    fp2=fopen("update.txt","w+");
    while(!feof(fp))
	{


		fscanf(fp,"%s %s %s %s %s\n",Name, Address, Gender, Email, Phone);

		ptr1=Name;

		if (strcmp(ptr1,SearchName)==0)
    	{
            found =1;


    	}
    	else{

            fprintf(fp2,"%s %s %s %s %s\n", &Name, &Address, &Gender, &Email, &Phone);



    	}




    }

    if(found==1) printf("Contact deleted\n");

    else{printf("wrong contact\n");}
    fclose(fp);
    fclose(fp2);
    remove("contact.txt");
    rename("update.txt","contact.txt");




}


void ListContacts()
{

     FILE*fp;
     int count=0;

     fp=fopen("contact.txt","r");



     while(!feof(fp))   //elenxos an to arxeio teleiwse
     {

         fscanf(fp,"%s %s %s %s %s\n",Name, Address, Gender, Email, Phone);
         count++;

         printf("-------------------------\n");
        	printf("Name: %s\n",Name);
        	printf("Address: %s\n",Address);
        	printf("Gender: %s\n",Gender);
        	printf("Email: %s\n",Email);
        	printf("Phone Number: %s\n",Phone);
        	printf("-------------------------\n");






     }


     fclose(fp);
     printf("Number of records found: %d\n",count);



}














void title(void)
{
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\tCONTACTS MANAGEMENT\t\t\t\t\t|\n");
	printf("-------------------------------------------------------------------------------------------------\n\n");
}
