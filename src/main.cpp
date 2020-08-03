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
    int ch;
    clrscr();
    cout<<"\n\n\n\t\t\tWelcome to M. S. Gosavi Polytechnic Database Portal ";
    cout<<"\n\n\n\t\t\tEnter to Continue ";
    getch();
    clrscr();

    cout<<"\n\n\n\t\t\tPress 1 for Admin Portal ";
    cout<<"\n\t\t\tPress 2 for Faculty Portal ";
    cout<<"\n\t\t\tPress 3 for Student Portal ";
    cout<<"\n\n\t\t\tEnter Your Choice : ";
    cin>>ch;
    clrscr();

    if(ch==1)
    {
        char adminuser[20], adminpass[20];
        cout<<"\n\t\t\tWelcome to the Admin Login Portal ";
        cout<<"\n\nEnter the UserName : ";
        cin>>adminuser;
        cout<<"\nEnter the Password : ";
        for(int k=0;k<8;k++)
        {
            adminpass[k] = getch();
            cout<<"*";
        }

        getch();
        adminpass[k]=NULL;

        //Starting the Admin Portal
        if((strcmp(adminuser, "admin")==0)&&(strcmp(adminpass, "password")==0))
        {
            clrscr();
        }
        else
        {
            cout<<"\n\n\t\t\t  Invalid Access to Portal ";
            cout<<"\n\n\t\t\t\tThank You !!! ";
            getch();
            exit(0);
        }

        char opera='y';

        do
        {
            int tmp;
            cout<<"\n\t\t\t\tWelcome To Admin Panel ";
            cout<<"\n\nPress 1 to Add a Faculty Record ";
            cout<<"\nPress 2 to Add Multiple Records of Faculies ";
            cout<<"\nPress 3 to View all Records of Faculties ";
            cout<<"\nPress 4 to Delete the Faculty Records ";
            cout<<"\nPress 5 to Add Student Record ";
            cout<<"\nPress 6 to Add Multiple Records of Students ";
            cout<<"\nPress 7 to View all Records of Students ";
            cout<<"\nPress 8 to Delete the Students Record ";
            cout<<"\nPress 9 to Exit ";
            cout<<"\n\n\tEnter your choice ";

            cin>>temp;
            clrscr();

            //For incerting record of a single faculty
            if(tmp==1)
            {
                cout<<"\nEnter the Details : ";
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }

            //For inserting multiple faculty records.
            if(tmp==2)
            {
                int m=0;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"\nEnter the Details : ";
                    a.getfadata();

                    fs.write((char *)&a,sizeof(Admin));
                    cout<<"Press 0 if you want to Enter More Records : ";
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"\nRecords Entered Suuccessfully...";
            }

            //For viewing all faculty records
            if(tmp==3)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&a,sizeof(Admin));
                    a.fadisplay();
                }
                fs.close();
            }

            //For Deleting a Faculty Record
            for(tmp==4)
            {
                char tmpfaid[15]
                int de=0, result = -1;
                cout<<"\nEnter the Faculty ID/Roll No : ";
                cin>>tmpfaid;
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result = strcmp(tmpfaid, a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    {
                        fs1.write((char *)&a, sizeof(Admin));
                    }

                    if(d==1)
                    {
                        cout<<"\nRecords Deleted Successfully...";
                    }
                    else
                    {
                        cout<<"\nRecord Not Found...";
                    }

                    fs.close();
                    fs1.close();
                    remove("fainfo.txt");
                    rename("fanewinfo.txt","fainfo.txt");
                }
            }

            //For single student record input
            if(tmp==5)
            {
                cout<<"\nEnter the Details : ";
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                a.getsdata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }
            
            //For Multiple Student record
            if(tmp==6)
            {
                int m=0;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);

                do
                {
                    cout<<"\nEnter the Details : ";
                    a.getsdata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout<<"Press 0 if you want to Enter More Records : ";
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }

            //For viewing all students records
            if(tmp==7)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    a.stdisplay();
                }
                fs.close();
            }

            //For Deleting the student records
            if(tmp==8)
            {
                char tmpstid[15];
                int de=0, result = -1;
                cout<<"\nEnter the Student ID/ Rollno : ";
                cin>>tmpstid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&a, sizeof(Admin));
                    result = strcmp(tmpstid, a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    {
                        fs1.write((char *)&a, sizeof(Admin));
                    }
                }
                if(de==1)
                {
                    cout<<"\nRecords Deleted Successfully...";
                }
                else
                {
                    cout<<"\nRecord Not found...";
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
            }

            //For exting the command
            if(tmp==9)
            {
                cout<<"\n\n\n\n\t\t\t\tThank You !!!";
                getch();
                exit(0);
            }

            //For Invalid Input amongst the choices
            if(tmp<1||tmp<9)
            {
                clrscr();
                cout<<"\n\n\n\t\t\t\tInvalid Input...";
            }
            getch();
            cout<<"\n\nPress y ; For More Operation otherwise Press n : ";
            cin>>opera;

            if(opera!='y')
            {
                getch();
                clrscr();
                cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!";
                getch();
            }
            
        }while(opera=='Y'||opera=='y');
    }//Admin Portal Close Here

    //Starting Faculty View Portal
    if(ch==2)
    {
        clrscr();
        char un[20];
        int val, s=0;
        cout<<"\n\t\t\tWelcome to Faculty Login Page";
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            val=-1;
            fs.read((char *)&f,sizeofd(Admin));
            val=f.login();
            if(val==1)
            {
                s=1;
                break;
            }
        }
        fs.close();
        if(s==1)
        {
            clrscr();
        }//If first login is invalid then
        
        if(s!=1)//if first login is invalid then
        {
            clrscr();
            int ho=0;
            cout<<"\n\n\t\tYour Login Credentials are Invalid";
            cout<<"\nThe Username is your ID/Roll no";
            cout<<"\nThe Password is Case Sensitive ";
            cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout<<"\nEnter the Choise : ";
            cin>>ho;
            if(ho==1)
            {
                cout<<"\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re, su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char *)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getch();
                    clrscr();
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User";
                    getch();
                    exit(0);
                }
            }

            if(ho==2)//Re-attempt the Login
            {
                cout<<"\n\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu;//valu for sorting login returned value
                suc for success login
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char *)&f, sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
                    clrscr();
                }
                else
                {
                    getch();
                    cout<<"\nYou are an Invalid User...";
                    cout<<"\nThank You !!!";
                    getch();
                    exit(0);
                    exit(0);
                }
            }

            if(ho!=1 && ho!=2)
            {
                cout<<"\n\nInvalid Input Provided";
                cout<<"\n\t\t\tThank You !!!";
                getch();
                exit(0);
            }
        }//Closing of first invalid login (forger password & recover password)

        //Begin of Faculty
        char con='y';
        do{
            clrscr();
            cout<<"\n\n\t\t\tWelcome to the Faculty Panel ";
            cout<<"\n\n\t\t\t\t\t\tYour UserID is : "<<::un;
            cout<<"\n\nPress 1 to View Your Profile";
            cout<<"\nPress 2 to Know Your Subjects";
            cout<<"\nPress 3 to Add a Subject";
            cout<<"\nPress 4 to Delete a Subject";
            cout<<"\nPress 5 to Modify Your Profile";
            int choice;
            cout<<"\n\nEnter Your Choice : ";
            cin>>choice;

            if(choice==1)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x=0;
                    fs.read((char *)&f,sizeof(Admin));
                    x = f.faprofile();
                    if(x==1)
                    {
                        break;
                    }
                }
                fs.close();
            }//closing of choice 1
            
            if(choice==2)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y=0;
                    fs.read((char *)&f, sizeof(Admin));
                    int y=f.knowfasub();
                    if(y==1)
                    {
                        break;
                    }
                }
                fs.close();
            }//closing of choice 2

            if(choice==3)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs1.open("tmpfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.addfasub();
                    fs1.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("tmpfainfo.txt","fainfo.txt");
            }//closing of choice 3
            
            if(choice==4)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fstream fs1;
                fs1.open("delfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.delfasub;
                    fs1.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("delfainfo.txt","fainfo.txt");
            }//closing of choice 4

            if(choice==5)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                fs1.open("modfainfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char *)&f, sizeof(Admin));
                    f.modfaprofile();
                    fs1.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("modfainfo.txt","fainfo.txt");
            }//closing of choice 5

            if(choice<1||choice>5)
            {
                cout<<"\nInvalid Input Provided...";    
            }
            cout<<"\n\n\t\t\t\tEnter to Continue...";
            getch();
            cout<<"\n\nPress y to Continue ; othervise Press n...";
            cin>>con;

            if(con!='y'&& con!='Y')
            {
                clrscr();
                cout<<"\n\n\n\n\n\t\t\t\tThank You !!!";
                getch();
                exit(0);
            }


        }while(con=='y'||con=='Y');
    }//Closing the faculty view portal

    //Begin of Student view

    if(ch==3)//begin of student view
    {
        clrscr();
        //char un[20];
        int value, s1=0;
        cout<<"\n\t\t\tWelcome to Student Login Page";
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);

        while(!fs.eof())
        {
            value=-1;
            fs.read((char *)&f, sizeof(Admin));
            value=f.login();
            if(value==1)
            {
                s1=1;
                break;
            }
        }
        fs.close();

        if(s1==1)
        {
            clrscr();
            //cout<<"\n\n\n\t\t\t\tWelcome to the Student Page";
        }//if first login was valid

        if(s1!=1)//If the first login was invalid
        {
            clrscr();
            int sho=0;
            cout<<"\n\n\t\tYour Login Credentials are Invalid";
            cout<<"\nThe Username is your ID/Roll no";
            cout<<"\nThe Password is Case Sensitive ";
            cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
            cout<<"\nEnter the Choise : ";
            cin>>sho;
            
            if(sho==1)//Recover the password
            {
                cout<<"\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char *)&f, sizeof(Admin));
                    re=f.recover()
                    
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }

                fs.close();
                if(su==1)
                {
                    getch();
                    clrscr();
                    cout<<"\n\n\n\n\t\t\tThank You !!!";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User !!!";
                    cout<<"\nThank You !!!";
                    getch();
                    exit(0);
                }
            }//recover password

            if(sho==2)//re-attempt of Login
            {
                cout<<"\n\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1, valu;
                suc for success login
                
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char *)&f, sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                
                if(suc==1)
                {
                    clrscr();
                }
                else
                {
                    getch();
                    cout<<"\nYou are a Invalid User...";
                    cout<<"\nThank You !!!";
                    getch();
                    exit(0);
                    exit(0);
                }
            }

            if(sho!=1 && sho!=2)
            {
                cout<<"\nInvalid Input Provided";
                cout<<"\n\n\t\t\tThank You !!!";
                getch();
                exit();
            }

        }//Closing of first invalid login(forget password & recover password)
        //getch();
    }

    //Begin of Student Panel
}