#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

struct{
    int dd;
    int mm;
    int yy;
	char note[200];
}R,D;

int gets_1st_weeksday(int year)
{
	int day;
	day=(((year-2)*365)+((year-2)/4)-((year-2)/100)+((year)/400)+1)%7;
	//Given the year, this will find the week for January 1 where Sunday is 6.
	return day;
}

int years()
{
	system("color 3f");
	
	int Month ,Day ,daysinMonth ,weeksday=0 ,startingday;
	char *months[]={"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	
	int year;
	
	printf("Enter Year:");scanf("%d",&year);
	int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(year%4==0 && year%100!=0 || year%400==0)
	monthDay[1]=29;
	startingday=gets_1st_weeksday(year);
	
	
	for(Month=0;Month<12;Month++){
		
		daysinMonth=monthDay[Month];
		printf("\n--------------%s---------------\n",months[Month]);
		printf(" Mon  Tue  Wed  Thur  Fri  Sat  Sun");
		printf("\n");
		
		for(weeksday=0;weeksday<startingday;weeksday++)
		printf("     ");//5 time space
		
		
		for(Day=1;Day<=daysinMonth;Day++){
		    printf("%5d",Day);
		if(++weeksday>6){
		    printf("\n");
		    weeksday=0;
	        }
	        startingday=weeksday;
	    }
	
	} 
	
	
	
}
/*--------------------------------------------------------*/
int check_leapYear(int year){ //checks whether the year passed is leap year or not
    if(year % 400 == 0 || (year % 100!=0 && year % 4 ==0))
       return 1;
    return 0;
}


int getNumberOfDays(int month,int year){ //returns the number of days in given month
   switch(month){                          //and year
      case 1 : return(31);
      case 2 : if(check_leapYear(year)==1)
		 return(29);
	       else
		 return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}

char *getName(int day){ //returns the name of the day
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("Error in getName() module.Invalid argument passed");
   }
}


int getDayNumber(int day,int mon,int year){ //retuns the day number
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while(year >= 100){
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = (year-1)-t1;
    t1 = (t1*2)+t2;
    t1 = (t1%7);
    res = res + t1;
    res = res%7;
    t2 = 0;
    for(t1 = 1;t1 < mon; t1++){
        t2 += getNumberOfDays(t1,y);
    }
    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;
    if(y > 2000)
        res = res + 1;
    res = res % 7;
    return res;
}

char *getDay(int dd,int mm,int yy){
    int day;
    if(!(mm>=1 && mm<=12)){
        return("Invalid month value");
    }
    if(!(dd>=1 && dd<=getNumberOfDays(mm,yy))){
        return("Invalid date");
    }
    if(yy>=1600){
        day = getDayNumber(dd,mm,yy);
        day = day%7;
        return(getName(day));
    }else{
        return("Please give year more than 1600");
    }
}


int main(){
    system("color 3f");
    int choice,i,isFound;
    char ch = 'a';
    FILE *fp;
	while(1)
	{
        system("cls");
        printf("1. Find Out the Day\n");
        printf("2. Print all the months of year\n");
        printf("3. Add Note\n");
        printf("4. Remainders list\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
		{
            case 1:
            	system("color 3f");
                printf("Enter date (DD MM YYYY) : ");
                scanf("%d %d %d",&D.dd,&D.mm,&D.yy);
                printf("Day is : %s",getDay(D.dd,D.mm,D.yy));
                printf("\nPress any key to continue......");
                getch();
                break;
            case 2 :
                years();
                return 0;
                break;
            case 3:
            	system("color 3f");
                note:
    			system("cls");
    			
    			printf("Enter the date\n\nDay-Date: ");
    			scanf("%d",&R.dd);
    			printf("\nMonth: ");
    			scanf("%d", &R.mm);
    			printf("\nYear: ");
    			scanf("%d", &R.yy);
    			
    			printf("\nEnter the Note(200 character max): ");
    			fflush(stdin);
    			scanf("%[^\n]s",R.note);
			    
				fp = fopen("note.txt","a+");
			    
			    for(int i=0;i<strlen(R.note);i++)
			    {
			    	R.note[i]+=3;
				}
			    
    			fprintf(fp,"\n\t%d\t%d\t%d\t%s",R.dd,R.mm,R.yy,R.note);
    			
    			fclose(fp);
    			
    			printf("\n\nPress any key............");
				
				
                printf("\n\nPress 0 to go back\n\nPress 1 to add another note\n\nINPUT: ");
                scanf("%d",&choice);
                
                if(choice==0)
                {
                	break;
				}
				else if(choice==1)
				{
					goto note;
				}
			
			case 4 :
				system("color 3f");
    			system("cls");
			    
			    if((fp = fopen("note.txt","r"))==NULL)
			    {
			    	printf("\n\nList is Empty.......Add some");
				}
			    
			    else
			    {
			    	printf("\n\n\t\t\t\t\tREMAINDER LIST\n\n\n");
    				for(int i=0;i<110;i++)
	    			{
    					printf("-");
					}
					printf("\n");
					
					printf("  %-10s||%50s\n","DATE","NOTE");
    				
					for(int i=0;i<110;i++)
	    			{
    					printf("-");
					}
			    	printf("\n");
					
					while(!feof(fp))
			    	{
			    		fscanf(fp,"\n\t%d\t%d\t%d\t%s",&R.dd,&R.mm,&R.yy,R.note);
			    		
						printf("\n\n%d-%d-%d%8s",R.dd,R.mm,R.yy,"");
						for(int i=0;i<strlen(R.note);i++)
			    		{
			    			R.note[i]-=3;
			    			printf("%c",R.note[i]);
			    			
			    			if(i>1)
			    			{
			    				if(i%93==0)
			    				{
			    					printf("\n\t\t ");
								}
							}
						}
						
					}
					
					fclose(fp);
				}
				
                printf("\n\n\nPress 0 to go back\n\nPress 1 to Exit\n\nINPUT: ");
                scanf("%d",&choice);
                
                if(choice==0)
                {
                	break;
				}
				else if(choice==1)
				{
					exit(0);
				}
			
            case 5 :
                exit(0);
        }
    }
    return 0;
}
