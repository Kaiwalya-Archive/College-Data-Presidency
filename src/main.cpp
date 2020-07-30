//.......................Collage Management system.....................
/*
This project is going to be fun because I am going to add many real life functions to make it more effective like 
1. Password Hiding
2. Password Recovery

! Let's Start.

for more view https://kaiwalyakoparkar.github.io/

This is Intended to be the microproject for the third semester.
Developers : 
1. Kaiwalya Koparkar (2nd Year)
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

        int recover()
        {
            //cout<<"\nThe Input Username is : "<<::un;
            char key[20];
            if(strcmp(::un,rollno)==0)
            {
                cout<<"\nEnter the Unique keyword (Provided by Admin) : ";
                cin>>key;

                if((strcmp(key,rpasswd)==0))
                {
                    cout<<"\nYou are a Valid user.";
                    cout<<"\nYour Password is "<<passwd;
                    cout<<"\nPlease Exit to Login Again ";
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

        //This function displays the faculty profile to the faculty at their respective portals

        int faprofile()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nFaculty Name          : "<<name;
                cout<<"\nFaculty Father's Name : "<<fname;
                cout<<"\nFaculty Mobile No     : "<<mobile;
                cout<<"\nFaculty E-Mail ID     : "<<mail;
                return 1;
            }
            else
            {
                return 0;   
            }
        }

        //This function displays the different subjects of the faculty at their respective portals

        int knowfasub()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nFaculty Total Subjects : "<<totsub;
                for(int i=0; i<totsub; i++)
                {
                    cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }

        //This function helps a faculty to add a subject in their module

        void addfasub()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nEnter the New Subject : ";
                cin>>subject[totsub];
                totsub++;
                cout<<"\n\nNew Subject Added Successfully...";
            }
        }

        //This function helps a faculty to delete a subject from their module.

        void delfasub()
        {
            knowfasub();
            int de=0;

            if((strcmp(::un,rollno)==0))
            {
                if(totsub==0||totsub<0)
                {
                    totsub=0;
                    cout<<"\nNone Subjects Exist...";
                    getch();
                    exit(0);
                }
                cout<<"\nEnter the Subject No. to be Deleted : "
                cin>>de;

                if(de==totsub)
                {
                    totsub--;
                    strcpy(subject[totsub]," ");
                }
                else if(totsub==1)
                {
                    totsub=0;
                    strcpy(subject[totsub]," ");
                }
                else
                {
                    de--;
                    strcpy(subject[totsub]," ");
                    
                    for(int p=de; p<totsub; p++)
                    {
                        strcpy(subject[p],subject[p+1]);
                    }
                    totsub--;
                }
                cout<<"\n Records Updated Successfully...";
            }
        }

        //This function helps a faculty to modify his personal profile.

        void modfaprofile()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nThe Profile Details are : ";
                cout<<"\n 1. Faculty E-Mail : "<<mail;
                cout<<"\n 2. Faculty Mobile : "<<mobile;

                int g=-1;
                cout<<"\n\nEnter the Detail No. to be Modified : ";
                cin>>g;

                if(g==1)
                {
                    char nmail[50];
                    cout<<"\nEnter the New Mail Address : ";
                    strcpy(mail, nmail);
                    cout<<"\nRecords Updated Successfully...";
                }
                else if(g==2)
                {
                    char mobile[15];
                    cout<<"\nEnter the new Mobile No : ";
                    gets(nmobile);
                    strcpy(mobile,nmobile);
                    cout<<"\nRecords Updated Successfully...";
                }
                else
                {
                    cout<<"\nInvalid Input Provided...";
                }
            }
        }

        //This function displays the student profile at the student portal 

        int stdprofile()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nStudent Name          : "<<name;
                cout<<"\nStudent Father's Name : "<<fname;
                cout<<"\nStudent Mobile No.    : "<<mobile;
                cout<<"\nStudent E-mail Id     : "<<mail;
            }
            else
            {
                return 0;
            }
        }

        //This function displays the different enrolled subjects of the respective students...according to their profile.

        int knowstsub()
        {
            if((strcmp(::un,rollno)==0))
            {
                cout<<"\nStudent Total Subjects   : "<<totsub;
                
                for(int i=0; i<totsub; i++)
                {
                    cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }

        //This function allows the student to add a subject in total subjects of the student profile...

        void addstsub()
        {
            if((strcmp(::un, rollno)==0))
            {
                cout<<"\nEnter the new subject   : ";
                cin>>subject[totsub];
                totsub++;
                cout<<"\n\nNew Subject Added Successfully...";
            }
        }

        //This function allows the student to delete a subjects in total subjects of the student profile...

        void delstsub()
        {
            knowstsub();
            int de=0;

            if((strcmp(::un,rollno)==0))
            {
                if(totsub==0||totsub<0)
                {
                    totsub=0;
                    cout<<"\nNone Subjects Exists...";
                    getch();
                    exit(0);
                }

                cout<<"\nEnter the Subject No. to be Deleted : ";
                cin>>de;

                if(de==totsub)
                {
                    totsub--;
                    strcpy(subject[totsub]," ");
                }
                else if(totsub==1)
                {
                    totsub=0;
                    strcpy(subject[totsub]," ");
                }
                else
                {
                    de--;
                    strcpy(subject[totsub]," ");
                    
                    for(int p=de; p<totsub; p++)
                    {
                        strcpy(subject[p],subject[p+1]);
                    }
                    totsub--;
                }

                cout<<"\nRecords Updated Successfully...";
            }
        }

        //This function allows the student to modify their personal profile details at the student portal

        void modstprofile()
        {
            if ((strcmp(::un, rollno)==0))
            {
                cout<<"\nThe Profile Details are : ";
                cout<<"\n 1. Student E-Mail : "<<mail;
                cout<<"\n 2. Student Mobile : "<<mobile;

                int g=-9;
                cout<<"\n\nEnter the Detail No. to be Modified : ";
                cin>>g;

                if(g==1)
                {
                    char nmail[50];
                    cout<<"\nEnter the New Mail Address : ";
                    strcpy(mail,nmail);
                    cout<<"\nRecords Updated Successfully...";
                }
                else if(g==2)
                {
                    char nmobile[15];
                    cout<<"\nEnter thr New Mobile No : ";
                    gets(nmobile);
                    strcpy(mobile,nmobile);
                    cout<<"\nRecords Updated Successfully...";
                }
                else
                {
                    cout<<"\nInvalid Input Provided..."
                }
            }
        }

        //This function allows the ADMIN to make a new Record Entry for the different new faculties...new faculty records are updated with the help of this function.

        void getfdata()
        {
            cout<<"\nEnter the Faculty Name : ";
            gets(name);
            cout<<"\nEnter the Faculty ID/Roll No : ";
            cin>>rollno;
            cout<<"\nEnter the Faculty Father's Name : ";
            gets(fname);
            cout<<"\nEnter the Mobile No : ";
            gets(mobile);
            cout<<"\nEnter the E-Mail ID : ";
            gets(mail);
            cout<<"\nEnter the Total Subjects : ";
            cin>>totsub;

            //cout<<"\nThe total subjects choosen are : "<<totsub;

            for(int i=0;l i<totsub; i++)
            {
                cout<<"\nEnter the Subject "<<i+1<<" Name : ";
                cin>>subject[i];
            }
            
            cout<<"\nCreate Your Login Password : ";
            cin>>passwd;
            cout<<"\nEnter the Unique Keyword to Recover the Password : ";
            cin>>rpasswd;
            cout<<"\n\nPlease note your Username is ID/Roll no. \n";
        } 
        
        //This function displaus all the relevant information to the admin related to the Student at the ADMIN portals

        void stdisplay()
        {
            cout<<"\nStudent Name          : "<<name;
            cout<<"\nStudent ID/Roll no    : "<<rollno;
            cout<<"\nStudent Father's Name : "<<fname;
            cout<<"\nStudent Mobile No     : "<<mobile;
            cout<<"\nStudent E-Mail ID     : "<<mail;
            cout<<"\nStudent Subjects      : "<<totsub;

            for(int i=0; i<tosub;i++)
            {
                cout<<"\n     Subjects "<<i+1<<" : "<<subject[i];
            }

            if(totsub==0)
            {
                cout<<"None Subjects are Specified...";
            }
        }

        //This function displaus all the relevant information to the admin related to the Faculty at the ADMIN portals

        void fadisplay()
        {
            cout<<"\nFaculty Name          : "<<name;
            cout<<"\nFaculty ID/Roll no    : "<<rollno;
            cout<<"\nFaculty Father's Name : "<<fname;
            cout<<"\nFaculty Mobile No     : "<<mobile;
            cout<<"\nFaculty E-Mail ID     : "<<mail;
            cout<<"\nFaculty Subjects      : "<<totsub;

            for(int i=0; i<tosub;i++)
            {
                cout<<"\n     Subjects "<<i+1<<" : "<<subject[i];
            }

            if(totsub==0)
            {
                cout<<"None Subjects are Specified...";
            }
        }
}a;

Admin f;
    // a & f are the objects of the class Admin

void main()
{

}