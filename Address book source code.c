#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h> //This header file contains function declarations and Macros
#include<stdlib.h>
#include<dos.h> //Has a library of functions which add time delays, sound, date and time to the program

struct contact
{
	long ph;
	char name[50],add[50],email[50];
} list;

char query[50],name[50];

FILE *fp,*ft;
int i,n,ch,l,found;

int main()
{
	main:
		system("cls");
		printf("\n\n\t<<<<<<Welcome to Address Book managment software>>>>>>");
		printf("\n\n\t<<<<<<By Pranav Ganesh and Aamil Khan>>>>>>");
		printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add new contact\n\t\t[2] List all contacts\n\t\t[3] Search contact list\n\t\t[4] Edit a contact\n\t\t[5] Delete a contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0:
				printf("\n\tAre you sure you want to exit the program?");
				break;
/* Entering details to add to add a new contact to the address book*/
			case 1:
	    system("cls");
        fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin); //This function clears the input console of the ouput buffer and moves the data to stdout console
            printf("To exit enter blank space in the name input");
            printf("\nName: ");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone (8 digit number):");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
/*Listing all the contacts which exist in the address book*/
        	case 2:
        		system("cls");
        		printf("\n\t\t================================\n\t\t\tLIST OF ALL CONTACTS\n\t\t================================");
        		for(i=97;i<=122;i=i+1)
        		{
        			fp=fopen("contact.dll","r");
        			fflush(stdin);
        			found=0;
            		while(fread(&list,sizeof(list),1,fp)==1)
            		{
            			if(list.name[0]==i || list.name[0]==i-32)
            			{
            				  printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
            				 found++;
						}
					}
					if(found!=0)
					{
					printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
                	getch();
					}
					fclose(fp);
				}
				break;
/*Search for an existing contact by inputing the name of the person*/				
			case 3:
				system("cls");
				do
				{
					found=0;
            	printf("\n\n\t....CONTACT SEARCH\n\t===========================\n\t....Name of contact: ");
            	fflush(stdin);
            	scanf("%[^\n]",&query);
            	l=strlen(query);
            	fp=fopen("contact.dll","r");
            	system("cls");
            	printf("\n\n....Search result for '%s' \n===================================================\n",query);
            	while(fread(&list,sizeof(list),1,fp)==1)
            	{
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\n....Name\t: %s\n....Phone\t: %ld\n....Address\t: %s\n....Email\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("..::Press any key to continue...");
                        getch();
                    }

                }

            }
            if(found==0)

                printf("\n..::No match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);

        break;
/*Editing an existing contact from the address book*/
        	case 4:
        		system("cls");
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to be edited: ");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\n..::Editing '%s'\n\n",name);
        printf("..::Name: ");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("..::Phone: ");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("..::address: ");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("..::email address: ");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
/*Deleting an existing contact from the address book*/
        	case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("contact.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
        if (stricmp(name,list.name)!=0)
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
        
        default:
        	printf("Invalid choice");

        break;
}
		printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			goto main;
    		case 0:
    			break;
    		default:
    			printf("Invalid input");
    		break;
		}
				return 0;
				}
				




