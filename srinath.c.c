#include<stdio.h>
#include<string.h>
#define N_len 10
#define ID_len 10
#define STATUS_len 10
#define CLASS_len 10
#define size 2
#define SUCCESS 1
#define FAILURE 0
typedef struct time
{
    unsigned int hr;
    unsigned int min;
}tim;
typedef struct FR
{
	char name[N_len];
	char id[ID_len];
	unsigned int capacity;
	struct time arr_time;
	struct time dept_time;
	char class[CLASS_len];
	char status[STATUS_len];
	unsigned int staytime;
	char promotedclass[CLASS_len];
	struct time delay_time;

}FR;
typedef struct SR
{
    char name[N_len];
    char id[ID_len];
    char status[STATUS_len];
    struct time delay_time;
}up;
int timecalculation(int x,int y)
{
    return x*60+y;
}
//Initialize function
void Initialize(struct FR flight[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		flight[i].name[0]='\0';
		flight[i].id[0]='\0';
		flight[i].capacity=0;
		flight[i].arr_time.hr=0;
		flight[i].arr_time.min=0;
		flight[i].dept_time.hr=0;
		flight[i].dept_time.min=0;
		flight[i].class[0]='\0';
		strcpy(flight[i].status,"ON_TIME");
	}
}
//Display function
void Display(struct FR flight[],int n)
{
	int i;
	printf("      NAME        ID  CAPACITY   ARRIVAL DEPARTURE     CLASS    STATUS\n");
	for(i=0;i<n;i++)
	{
		if(flight[i].capacity!=0)
        {
            printf("%10s%10s%10d%7d:%2d%7d:%2d%10s%10s\n",flight[i].name,flight[i].id,flight[i].capacity,flight[i].arr_time.hr,flight[i].arr_time.min,flight[i].dept_time.hr,flight[i].dept_time.min,flight[i].class,flight[i].status);
        }
	}
}
//Updateddisplay function
void UpdatedDisplay(struct FR flight[],int n)
{
	int i;
	printf("      NAME        ID  CAPACITY   ARRIVAL DEPARTURE  ORIGINALCLASS    STATUS  PROMOTEDCLASS DELAYTIME\n");
	for(i=0;i<n;i++)
	{
		if(flight[i].capacity!=0)
        {
            printf("%10s%10s%10d%7d:%2d%7d:%2d%15s%10s%15s%7d:%2d\n",flight[i].name,flight[i].id,flight[i].capacity,flight[i].arr_time.hr,flight[i].arr_time.min,flight[i].dept_time.hr,flight[i].dept_time.min,flight[i].class,flight[i].status,flight[i].promotedclass,flight[i].delay_time.hr,flight[i].delay_time.min);
        }
	}
}
//Public_class flights display function
void publicdisplay(struct FR flight[],int n)
{
	int i;
	printf("      NAME        ID  CAPACITY   ARRIVAL DEPARTURE     CLASS    STATUS\n");
	for(i=0;i<n;i++)
	{
		if((flight[i].capacity!=0)&&(strcmp(flight[i].class,"public")==0))
        {
            printf("%10s%10s%10d%7d:%2d%7d:%2d%10s%10s\n",flight[i].name,flight[i].id,flight[i].capacity,flight[i].arr_time.hr,flight[i].arr_time.min,flight[i].dept_time.hr,flight[i].dept_time.min,flight[i].class,flight[i].status);
        }
	}
}
//VIP_class flights display function
void vipdisplay(struct FR flight[],int n)
{
	int i;
	printf("      NAME        ID  CAPACITY   ARRIVAL DEPARTURE     CLASS    STATUS\n");
	for(i=0;i<n;i++)
	{
		if((flight[i].capacity!=0)&&(strcmp(flight[i].class,"VIP")==0))
        {
            printf("%10s%10s%10d%7d:%2d%7d:%2d%10s%10s\n",flight[i].name,flight[i].id,flight[i].capacity,flight[i].arr_time.hr,flight[i].arr_time.min,flight[i].dept_time.hr,flight[i].dept_time.min,flight[i].class,flight[i].status);
        }
	}
}
//VVIP_class flights display funtion
void vvipdisplay(struct FR flight[],int n)
{
	int i;
	printf("      NAME        ID  CAPACITY   ARRIVAL DEPARTURE     CLASS    STATUS\n");
	for(i=0;i<n;i++)
	{
		if((flight[i].capacity!=0)&&(strcmp(flight[i].class,"VVIP")==0))
        {
            printf("%10s%10s%10d%7d:%2d%7d:%2d%10s%10s\n",flight[i].name,flight[i].id,flight[i].capacity,flight[i].arr_time.hr,flight[i].arr_time.min,flight[i].dept_time.hr,flight[i].dept_time.min,flight[i].class,flight[i].status);
        }
	}
}
//Insert function
int Insert(struct FR flight[],int n,char fname[],char fid[],int fcapacity,int arrivaltimehr,int arrivaltimemin,int departuretimehr,int departuretimemin,char fclass[])
{
	int status=SUCCESS;int i,found,free_index;
	i=found=0;
	while((i<n)&&(found==0))
	{
		if((strcmp(flight[i].name,fname)==0)&&(strcmp(flight[i].id,fid)==0))
		{
			found=1;
		}
		else
		{
			i++;
		}
	}
	if(found)
	{
		flight[i].capacity=fcapacity;
		flight[i].arr_time.hr=arrivaltimehr;
		flight[i].arr_time.min=arrivaltimemin;
		flight[i].dept_time.hr=departuretimehr;
		flight[i].dept_time.min=departuretimemin;
		strcpy(flight[i].class,fclass);
	}
	else
	{
		i=free_index=0;
		while((i<n)&&(free_index==0))
		{
			if(flight[i].capacity==0)
			{
				free_index=1;
			}
			else
			{
				i++;
			}
		}
		if(free_index)
		{
			strcpy(flight[i].name,fname);
			strcpy(flight[i].id,fid);
			flight[i].capacity=fcapacity;
            flight[i].arr_time.hr=arrivaltimehr;
		    flight[i].arr_time.min=arrivaltimemin;
		    flight[i].dept_time.hr=departuretimehr;
		    flight[i].dept_time.min=departuretimemin;
			strcpy(flight[i].class,fclass);
		}
		else
		{
			status=FAILURE;
			printf("Insert function is not successful\n");
		}
	}
	return status;
}
//Delete function
void Delete(struct FR flight[],int n,char fid[])
{
    int i=0,flag=0;
    while((i<n)&&(flag==0))
    {
        if(strcmp(flight[i].id,fid)==0)
        {
            flight[i].name[0]='\0';
            flight[i].id[0]='\0';
            flight[i].capacity=0;
            flight[i].arr_time.hr=0;
		    flight[i].arr_time.min=0;
		    flight[i].dept_time.hr=0;
		    flight[i].dept_time.min=0;
            flight[i].class[0]='\0';
            strcpy(flight[i].status,"ON_TIME");
            flag=1;
        }
        else
        {
            i++;
        }
    }
    if(flag==1)
    {
        printf("Your entry is successfully deleted\n");
    }
    else
    {

        printf("Delete function is not successfull\n");
    }
}
//getNumFlights function
void getNumFlights(struct FR flight[],int n)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(flight[i].capacity!=0)
        {
            count++;
        }
    }
    printf("Total number of flights:%d\n",count);
}
//isEmpty function
void isEmpty(struct FR flight[],int n)
{
    int i,flag=0;
    while((i<n)&&(flag==0))
    {
        if(flight[i].capacity==0)
        {
            flag=1;
        }
        else{
            i++;
        }
    }
    if(flag)
    {
        printf("%d flight record is empty in list\n",i);
    }
    else
    {
        printf("Flight record is not empty\n");
    }
}
//isFull function
void isFull(struct FR flight[],int n)
{
    int i,flag=0;
    while((i<n)&&(flag==0))
    {
        if(flight[i].capacity==0)
        {
            flag=1;
        }
        else{
            i++;
        }
    }
    if(flag)
    {
        printf("Flight record is not full\n");
    }
    else
    {
        printf("Flight record is FULL\n");
    }
}
//longeststaytime function
void getFlightWithLongeststay(struct FR flight[],int n)
{
    int i,max=flight[0].staytime,pos,hours,mins;
    for(i=0;i<n;i++)
    {
        if(flight[i].staytime>max)
        {
            max=flight[i].staytime;
            pos=i;
        }
    }
    hours=flight[pos].staytime/60;
    mins=flight[pos].staytime%60;
    printf("Longest staytime flight:%s with id:%s\nstaytime=%d:%d\n",flight[pos].name,flight[pos].id,hours,mins);
}
//Sorting on arrivaltime function
void getSortedOnArrivalTime(struct FR flight[],int n)
{
    int i=0,j,flag=0;
    struct FR temp;
    while((i<n-1)&&(flag==0))
    {
        flag=1;
        for(j=0;j<n-i-1;j++)
        {
            if(timecalculation(flight[j].arr_time.hr,flight[j].arr_time.min)>timecalculation(flight[j+1].arr_time.hr,flight[j+1].arr_time.min))
            {
            	temp=flight[j];
            	flight[j]=flight[j+1];
            	flight[j+1]=temp;
                flag=0;
            }
        }
        i++;
    }
}
//Sorted list on departure time
void getSortedOnDepartureTime(struct FR flight[],int n)
{
    int i=0,j,flag=0;
    struct FR temp;
    while((i<n-1)&&(flag==0))
    {
        flag=1;
        for(j=0;j<n-i-1;j++)
        {
            if(timecalculation(flight[j].dept_time.hr,flight[j].dept_time.min)>timecalculation(flight[j+1].dept_time.hr,flight[j+1].dept_time.min))
            {
            	temp=flight[j];
            	flight[j]=flight[j+1];
            	flight[j+1]=temp;            	
                flag=0;
            }
        }
        i++;
    }
}
//Sorted list on staytime
void getSortedOnStayTime(struct FR flight[],int n)
{
    int i=0,j,flag=0;
    struct FR temp;
    while((i<n-1)&&(flag==0))
    {
        flag=1;
        for(j=0;j<n-i-1;j++)
        {
            if(flight[j].staytime>flight[j+1].staytime)
            {
            	temp=flight[j];
            	flight[j]=flight[j+1];
            	flight[j+1]=temp;              	
                flag=0;
            }
        }
        i++;
    }
}
//Sorting on key function
void getSortedOnKey(struct FR flight[],int n)
{
    int i=0,j,flag=0;
    struct FR temp;
    while((i<n-1)&&(flag==0))
    {
        flag=1;
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(flight[j].id,flight[j+1].id)>0)
            {
            	temp=flight[j];
            	flight[j]=flight[j+1];
            	flight[j+1]=temp;             	
                flag=0;
            }
            else if(strcmp(flight[j].id,flight[j+1].id)==0)
            {
                if(timecalculation(flight[j].arr_time.hr,flight[j].arr_time.min)>timecalculation(flight[j+1].arr_time.hr,flight[j+1].arr_time.min))
                {
                    	temp=flight[j];
             			flight[j]=flight[j+1];
            			flight[j+1]=temp;        	
                        flag=0;
                }
            }
        }
        i++;
    }
}
//Update function
void UpdateFlightStatus(struct FR flight[],struct SR update[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(flight[j].id,update[i].id)==0)
            {
                strcpy(flight[j].status,update[i].status);
                if(strcmp(update[i].status,"DELAY")==0)
                {
                    flight[j].delay_time.hr=update[i].delay_time.hr;
                    flight[j].delay_time.min=update[i].delay_time.min;
                }
                else if(strcmp(update[i].status,"PROMOTED")==0)
                {
                    if(strcmp(flight[j].class,"public")==0)
                    {
                        strcpy(flight[j].promotedclass,"VIP");
                    }
                    else if(strcmp(flight[j].class,"VIP")==0)
                    {
                        strcpy(flight[j].promotedclass,"VVIP");
                    }
                    else if(strcmp(flight[j].class,"VVIP")==0)
                    {
                    	strcpy(flight[j].promotedclass,"VVIP");
					}
                }
            }
        }
    }
}
//Unique list function
void listUnique(struct FR flight[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n;i++)
    {
        j=i+1;
        while((j<n)&&(flag==0))
        {
            if((timecalculation(flight[i].arr_time.hr,flight[i].arr_time.min)==timecalculation(flight[j].arr_time.hr,flight[j].arr_time.min))&&(strcmp(flight[i].id,flight[j].id)==0))
            {
                   if(flight[i].staytime>flight[j].staytime)
                      {
                            flight[i].name[0]='\0';
                            flight[i].id[0]='\0';
                            flight[i].capacity=0;
                            flight[i].arr_time.hr=0;
                            flight[i].arr_time.min=0;
                            flight[i].dept_time.hr=0;
                            flight[i].dept_time.min=0;
                            flight[i].class[0]='\0';
                            flag=1;
                      }
                      else
                      {
                            flight[j].name[0]='\0';
                            flight[j].id[0]='\0';
                            flight[j].capacity=0;
                            flight[j].arr_time.hr=0;
                            flight[j].arr_time.min=0;
                            flight[j].dept_time.hr=0;
                            flight[j].dept_time.min=0;
                            flight[j].class[0]='\0';
                      }
            }
            j++;
        }
    }
}
//Union list function
void listUnion(struct FR flight[],struct FR list2[],struct FR list3[],int n)
{
    int i,j,k;
    i=j=k=0;
    while(j<n)
    {
       list3[k++]=list2[j++];
	}		
    while(i<n)
    {
        list3[k++]=flight[i++];
    }
    for(i=0;i<2*n;i++)
    {
    	j=i+1;
    	while(j<2*n)
    	{
    		if((timecalculation(list3[i].arr_time.hr,list3[i].arr_time.min)==timecalculation(list3[j].arr_time.hr,list3[j].arr_time.min))&&(strcmp(list3[i].id,list3[j].id)==0))
			{
                list3[j].name[0]='\0';
                list3[j].id[0]='\0';
                list3[j].capacity=0;
                list3[j].arr_time.hr=0;
                list3[j].arr_time.min=0;
                list3[j].dept_time.hr=0;
                list3[j].dept_time.min=0;
                list3[j].class[0]='\0';				
			}
			j++;	
		}
	}
}
//list intersection function
void listIntersection(struct FR flight[],struct FR list2[],struct FR list3[],int n)
{
	int i,j,k;
	i=j=k=0;
	while(i<n)
	{
		for(j=0;j<n;j++)
		{
			if((strcmp(flight[i].id,list2[j].id)==0)&&(timecalculation(flight[i].arr_time.hr,flight[i].arr_time.min)==timecalculation(list2[j].arr_time.hr,list2[j].arr_time.min)))
			{
				if(flight[i].staytime<=list2[j].staytime)
				{
					list3[k++]=flight[i];
				}
				else
				{
					list3[k++]=list2[j];
				}
			}
		}
		i++;
	}
}
//List difference function
void listDifference(struct FR flight[],struct FR list2[],struct FR list3[],int n)
{
	int i,j,k,flag;
	i=j=k=0;
	while(i<n)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if((strcmp(flight[i].id,list2[j].id)==0)&&(timecalculation(flight[i].arr_time.hr,flight[i].arr_time.min)==timecalculation(list2[j].arr_time.hr,list2[j].arr_time.min)))
			{
				flag=1;
			}
		}
		if(!flag)
		{
			list3[k++]=flight[i];
		}
		i++;
	}	
}
//List symmetric function
void listSymmetricDifference(struct FR flight[],struct FR list2[],struct FR list3[],int n)
{
    int i,j,k,flag=0;
    i=j=k=0;
    while(j<n)
    {
       list3[k++]=list2[j++];
	}		
    while(i<n)
    {
        list3[k++]=flight[i++];
    }
    for(i=0;i<2*n;i++)
    {
    	j=i+1;
    	flag=0;
    	while(j<2*n)
    	{
    		if((timecalculation(list3[i].arr_time.hr,list3[i].arr_time.min)==timecalculation(list3[j].arr_time.hr,list3[j].arr_time.min))&&(strcmp(list3[i].id,list3[j].id)==0))
			{
                list3[j].name[0]='\0';
                list3[j].id[0]='\0';
                list3[j].capacity=0;
                list3[j].arr_time.hr=0;
                list3[j].arr_time.min=0;
                list3[j].dept_time.hr=0;
                list3[j].dept_time.min=0;
                list3[j].class[0]='\0';
				flag=1;				
			}
			j++;	
		}
		if(flag)
		{
            list3[i].name[0]='\0';
            list3[i].id[0]='\0';
            list3[i].capacity=0;
            list3[i].arr_time.hr=0;
            list3[i].arr_time.min=0;
            list3[i].dept_time.hr=0;
            list3[i].dept_time.min=0;
            list3[i].class[0]='\0';			
		}
	}
}
//MAIN FUNCTION
int main()
{
	FR flight[size];
	FR list2[size];
    	FR list3[2*size];
	int i,flag=1,option,classbutton;
	Initialize(flight,size);
	printf("ENTER THE FLIGHT RECORDS:\n");
	for(i=0;i<size;i++)
	{
		printf("Enter the flight name:");
		scanf("%s",&flight[i].name);
	    printf("Enter the flight id:");
		scanf("%s",&flight[i].id);
		printf("Enter the flight capacity:");
		scanf("%d",&flight[i].capacity);
		printf("Enter the flight arrival time in 24:00 format:\n");
		scanf("%d",&flight[i].arr_time.hr);
		printf(":");
		scanf("%d",&flight[i].arr_time.min);
		printf("Enter the flight departure time in 24:00 format:\n");
		scanf("%d",&flight[i].dept_time.hr);
		printf(":");
		scanf("%d",&flight[i].dept_time.min);
		printf("Enter the flight class:");
		printf("Press\n'1' for public\n'2' for VIP\n'3' for VVIP\n");
		scanf("%d",&classbutton);
		switch(classbutton)
		{
			case 1:
				strcpy(flight[i].class,"public");
				break;
			case 2:
				strcpy(flight[i].class,"VIP");
				break;
			case 3:
				strcpy(flight[i].class,"VVIP");
				break;
			default:
				strcpy(flight[i].class,"public");
		}
		flight[i].staytime=timecalculation(flight[i].dept_time.hr,flight[i].dept_time.min)-timecalculation(flight[i].arr_time.hr,flight[i].arr_time.min);
		if(flight[i].staytime<0)
		{
			flight[i].staytime=1440+flight[i].staytime;
		}
		flight[i].delay_time.hr=flight[i].delay_time.min=0;
		strcpy(flight[i].promotedclass,"not_promoted");
	}
	printf("WELCOME TO FLIGHT RECORD MANAGEMENT SYSTEM\n");
	while(flag==1)
    {
        printf("PRESS THE CORRESPONDING KEY FOR EVERY OPERATION YOU WANT:\n");
        printf("1.Insert a new flight record\n2.Delete an existing record\n3.To know the number of flights\n4.To know any record is empty\n");
        printf("5.To know if list is fully occupied\n6.To get flight with longest staytime\n7.Sorted list on arrival time\n");
        printf("8.Sorted list on departure time\n9.Sorted list on staytime\n");
        printf("10.To update flight status:\n");
        printf("11.To remove duplicate entries:\n12.To merge to record lists:\n13.To find common flights in two record lists:\n");
        printf("14.To remove list2 flights from main record:\n15.Symmetric difference between two lists:\n16.Sorted list on flight class\n17.'QUIT'\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:;
           	char fname[N_len],fid[ID_len],fclass[CLASS_len];
            int fcapacity,arrivaltimehr,arrivaltimemin,departuretimehr,departuretimemin;
            printf("Enter the record to be inserted:\n");
            printf("Enter the flight name:");
            scanf("%s",&fname);
            printf("Enter the flight id:");
            scanf("%s",&fid);
            printf("Enter the flight capacity:");
            scanf("%d",&fcapacity);
            printf("Enter the flight arrival time in 24:00 format:");
            scanf("%d",&arrivaltimehr);
            printf(":");
            scanf("%d",&arrivaltimemin);
            printf("Enter the flight departure time in 24:00 format:");
            scanf("%d",&departuretimehr);
            printf(":");
            scanf("%d",&departuretimemin);
            printf("Enter the flight class:");
            scanf("%s",&fclass);
            if(Insert(flight,size,fname,fid,fcapacity,arrivaltimehr,arrivaltimemin,departuretimehr,departuretimemin,fclass))
            {
                printf("Your entry is successfully inserted\n");
            }
            Display(flight,size);
            break;
        case 2:;
            char matchid[ID_len];
            printf("Enter the id of flight to be deleted:");
            scanf("%s",&matchid);
            Delete(flight,size,matchid);
            Display(flight,size);
            break;
        case 3:
            getNumFlights(flight,size);
            break;
        case 4:
            isEmpty(flight,size);
            break;
        case 5:
            isFull(flight,size);
            break;
        case 6:
            getFlightWithLongeststay(flight,size);
            break;
        case 7:
            getSortedOnArrivalTime(flight,size);
            Display(flight,size);
            break;
        case 8:
            getSortedOnDepartureTime(flight,size);
            Display(flight,size);
            break;
        case 9:
            getSortedOnStayTime(flight,size);
            Display(flight,size);
            break;
        case 10:;
            struct SR update[size];
            int i,statusbutton;
            printf("Enter the updated flight record:\n");
            for(i=0;i<size;i++)
            {
                printf("Enter the flight name:");
                scanf("%s",&update[i].name);
                printf("Enter the flight id:");
                scanf("%s",&update[i].id);
                printf("Enter the flight status:");
                printf("Press \n'1' for ON_TIME\n'2' for DELAY\n'3' for CANCEL\n'4' for PROMOTION");
                scanf("%d",&statusbutton);
                switch(statusbutton)
                {
                    case 1:
                        strcpy(update[i].status,"ON_TIME");
                        break;
                    case 2:
                        strcpy(update[i].status,"DELAY");
                        break;
                    case 3:
                        strcpy(update[i].status,"CANCELLED");
                        break;
                    case 4:
                    	strcpy(update[i].status,"PROMOTED");
                    default:
                        strcpy(list2[i].class,"ON_TIME");
                }                
                if(strcmp(update[i].status,"DELAY")==0)
                {
                    printf("Enter the flight delay time in 24:00hrs format:");
                	scanf("%d",&update[i].delay_time.hr);
                	printf(":");
                	scanf("%d",&update[i].delay_time.min);
				}
            }
            UpdateFlightStatus(flight,update,size);
            getSortedOnKey(flight,size);
            printf("Updated flight record:\n");
            UpdatedDisplay(flight,size);
            break;
        case 11:
            listUnique(flight,size);
            getSortedOnKey(flight,size);
            Display(flight,size);
            break;
        case 12:;

            Initialize( list2,size);
            Initialize( list3,2*size);
            printf("ENTER THE LIST-2 FLIGHT RECORDS:\n");
            for(i=0;i<size;i++)
           {
                printf("Enter the flight name:");
                scanf("%s",&list2[i].name);
                printf("Enter the flight id:");
                scanf("%s",&list2[i].id);
                printf("Enter the flight capacity:");
                scanf("%d",&list2[i].capacity);
                printf("Enter the flight arrival time in 24:00 format:\n");
                scanf("%d",&list2[i].arr_time.hr);
                printf(":");
                scanf("%d",&list2[i].arr_time.min);
                printf("Enter the flight departure time in 24:00 format:\n");
                scanf("%d",&list2[i].dept_time.hr);
                printf(":");
                scanf("%d",&list2[i].dept_time.min);
                printf("Enter the flight class:");
                printf("Press \n'1' for public\n'2' for VIP\n'3' for VVIP\n");
                scanf("%d",&classbutton);
                switch(classbutton)
                {
                    case 1:
                        strcpy(list2[i].class,"public");
                        break;
                    case 2:
                        strcpy(list2[i].class,"VIP");
                        break;
                    case 3:
                        strcpy(list2[i].class,"VVIP");
                        break;
                    default:
                        strcpy(list2[i].class,"public");
                }
                list2[i].staytime=timecalculation(list2[i].dept_time.hr,list2[i].dept_time.min)-timecalculation(list2[i].arr_time.hr,list2[i].arr_time.min);
                list2[i].delay_time.hr=list2[i].delay_time.min=0;
                strcpy(list2[i].promotedclass,"not_promoted");
            }
            listUnion(flight,list2,list3,size);
            getSortedOnKey(list3,2*size);
            Display(list3,2*size);
            break;
        case 13:
            Initialize( list2,size);
            Initialize( list3,2*size);
            printf("ENTER THE LIST-2 FLIGHT RECORDS:\n");
            for(i=0;i<size;i++)
           {
                printf("Enter the flight name:");
                scanf("%s",&list2[i].name);
                printf("Enter the flight id:");
                scanf("%s",&list2[i].id);
                printf("Enter the flight capacity:");
                scanf("%d",&list2[i].capacity);
                printf("Enter the flight arrival time in 24:00 format:\n");
                scanf("%d",&list2[i].arr_time.hr);
                printf(":");
                scanf("%d",&list2[i].arr_time.min);
                printf("Enter the flight departure time in 24:00 format:\n");
                scanf("%d",&list2[i].dept_time.hr);
                printf(":");
                scanf("%d",&list2[i].dept_time.min);
                printf("Enter the flight class:");
                printf("Press \n'1' for public\n'2' for VIP\n'3' for VVIP\n");
                scanf("%d",&classbutton);
                switch(classbutton)
                {
                    case 1:
                        strcpy(list2[i].class,"public");
                        break;
                    case 2:
                        strcpy(list2[i].class,"VIP");
                        break;
                    case 3:
                        strcpy(list2[i].class,"VVIP");
                        break;
                    default:
                        strcpy(list2[i].class,"public");
                }
                list2[i].staytime=timecalculation(list2[i].dept_time.hr,list2[i].dept_time.min)-timecalculation(list2[i].arr_time.hr,list2[i].arr_time.min);
                list2[i].delay_time.hr=list2[i].delay_time.min=0;
                strcpy(list2[i].promotedclass,"not_promoted");
            }
			listIntersection(flight,list2,list3,size);
			getSortedOnKey(list3,2*size);
			Display(list3,2*size);
			break;
		case 14:
            Initialize( list2,size);
            Initialize( list3,2*size);
            printf("ENTER THE LIST-2 FLIGHT RECORDS:\n");
            for(i=0;i<size;i++)
           {
                printf("Enter the flight name:");
                scanf("%s",&list2[i].name);
                printf("Enter the flight id:");
                scanf("%s",&list2[i].id);
                printf("Enter the flight capacity:");
                scanf("%d",&list2[i].capacity);
                printf("Enter the flight arrival time in 24:00 format:\n");
                scanf("%d",&list2[i].arr_time.hr);
                printf(":");
                scanf("%d",&list2[i].arr_time.min);
                printf("Enter the flight departure time in 24:00 format:\n");
                scanf("%d",&list2[i].dept_time.hr);
                printf(":");
                scanf("%d",&list2[i].dept_time.min);
                printf("Enter the flight class:");
                printf("Press \n'1' for public\n'2' for VIP\n'3' for VVIP\n");
                scanf("%d",&classbutton);
                switch(classbutton)
                {
                    case 1:
                        strcpy(list2[i].class,"public");
                        break;
                    case 2:
                        strcpy(list2[i].class,"VIP");
                        break;
                    case 3:
                        strcpy(list2[i].class,"VVIP");
                        break;
                    default:
                        strcpy(list2[i].class,"public");
                }
                list2[i].staytime=timecalculation(list2[i].dept_time.hr,list2[i].dept_time.min)-timecalculation(list2[i].arr_time.hr,list2[i].arr_time.min);
                list2[i].delay_time.hr=list2[i].delay_time.min=0;
                strcpy(list2[i].promotedclass,"not_promoted");
            }
			listDifference(flight,list2,list3,size);
			getSortedOnKey(list3,2*size);
			Display(list3,2*size);
			break;
		case 15:
            Initialize( list2,size);
            Initialize( list3,2*size);
            printf("ENTER THE LIST-2 FLIGHT RECORDS:\n");
            for(i=0;i<size;i++)
           {
                printf("Enter the flight name:");
                scanf("%s",&list2[i].name);
                printf("Enter the flight id:");
                scanf("%s",&list2[i].id);
                printf("Enter the flight capacity:");
                scanf("%d",&list2[i].capacity);
                printf("Enter the flight arrival time in 24:00 format:\n");
                scanf("%d",&list2[i].arr_time.hr);
                printf(":");
                scanf("%d",&list2[i].arr_time.min);
                printf("Enter the flight departure time in 24:00 format:\n");
                scanf("%d",&list2[i].dept_time.hr);
                printf(":");
                scanf("%d",&list2[i].dept_time.min);
                printf("Enter the flight class:");
                printf("Press \n'1' for public\n'2' for VIP\n'3' for VVIP\n");
                scanf("%d",&classbutton);
                switch(classbutton)
                {
                    case 1:
                        strcpy(list2[i].class,"public");
                        break;
                    case 2:
                        strcpy(list2[i].class,"VIP");
                        break;
                    case 3:
                        strcpy(list2[i].class,"VVIP");
                        break;
                    default:
                        strcpy(list2[i].class,"public");
                }
                list2[i].staytime=timecalculation(list2[i].dept_time.hr,list2[i].dept_time.min)-timecalculation(list2[i].arr_time.hr,list2[i].arr_time.min);
                list2[i].delay_time.hr=list2[i].delay_time.min=0;
                strcpy(list2[i].promotedclass,"not_promoted");
            }
			listSymmetricDifference(flight,list2,list3,size);
			getSortedOnKey(list3,2*size);
			Display(list3,2*size);			
			break;
		case 16:
			printf("Press '1' for public class flights\nPress '2' for VIP flights\nPress '3' for VVIP flights\n");
			int button;
			scanf("%d",&button);
			getSortedOnKey(flight,size);
			switch(button)
			{
				case 1:
					publicdisplay(flight,size);
					break;
				case 2:
					vipdisplay(flight,size);
					break;
				case 3:
					vvipdisplay(flight,size);
					break;
		    }
			break;									           	
        case 17:
            flag=0;
        }
        getSortedOnKey(flight,size);
    }


	return 0;
}
