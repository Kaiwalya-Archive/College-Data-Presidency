//.......................Collage Management system.....................
/*
This project is going to be fun because I am going to add many real life functions to make it more effective ! Let's Start.
*/

//.............Including the files..............

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>

char un[20];//Global declaration

//..............Admin class...................

class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
    
    public:
        char rollno[15];
        //This function is used to get the student data entry from the ADMIN portal ... all the records entities are made by this method,
        void getstdata()
        {
            cout<<"\nEnter the Student Name : ";
            gets(name);
            
            cout<<"\nEnter the Student ID/Roll No : ";
            cin>>rollno;

            cout<<"\nEnter the Student's Father's name : ";
            gets(fname);

            cout<<"\nEnter the Mobile Number : ";
            gets(mobile);

            cout<<"\nEnter the E-Mail ID : ";
            gets(mail);

            cout<<"\nEnter the Total Subject : ";
            cin>>totsub;

            for(int i=0; i<totsub ;i++)
            {
                cout<<"\nEnter the Subject "<<i+1<<" Name : ";
                cin>>subject[i];
            }

            cout<<"\nCreate the Login Password : ";
            cin>>passwd;

            cout<<"\nEnter the Unique Keyword to Recover Password : ";
            cin>>rpasswd;
            
            cout<<"\n\nPlease note your UserName is ID/Roll no .\n";
        }
        //This function aunthicates the login of both the students & faculties with their reference to their unique ID/Password login is provided 

        int login()
        {
            if((strcmp(::un,rollno))==0)
            {
                cout<<"\nEnter the Login Password : ";
                int len=0;
                len = strlen(passwd);
                char inputpasswd[20];
                for(int i=0; i<len ; i++)
                {
                    inputpasswd[i] = getch();
                    cout<<"#";
                }

                intputpasswd[i] = NULL;
                //cout<<"\n The Entered Password is "<<inputpasswd;

                if((strcmp(::un,roll)==0) && (strcmp(passwd, inputpasswd)==0))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                    
            }

            else
            {
                return 0;
            }
        }

        //This function help both the students & faculties to recover the password with the help of unique keyword provided by the Admin.
};