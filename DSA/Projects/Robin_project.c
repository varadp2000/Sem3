#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct song
{
struct song *nxt;
char name[30];
char lyrics[200];
struct song *pre;
};


struct song * create_song()
{
 struct song *newsong;
 newsong=(struct song *)malloc(sizeof(struct song));
 printf("\nENTER THE SONG NAME:");
 scanf("%s",newsong->name);
 printf("\nENTER LYRICS:");
 scanf("%s",newsong->lyrics);
 newsong->nxt=NULL;
 newsong->pre=NULL;
 return newsong;
}



struct song *add_beg(struct song *head)
{
    struct song *newsong,*tmp;

 /*   if(head==NULL)
    {
	newsong=create_song();
	head=newsong;
    }
    else{*/
	newsong=create_song();
	tmp=head;
	newsong->nxt=tmp;
	tmp->pre=newsong;
	head=newsong;
 //   }
    return head;
}



struct song *add_end(struct song *head)
{
 struct song *newsong,*tmp;


	newsong=create_song();
	tmp=head;
	while(tmp->nxt!=NULL)
	   tmp=tmp->nxt;
	tmp->nxt=newsong;
	newsong->pre=tmp;

 return head;
}


struct song *add_pos(struct song *head,int pos)
{
  struct song *newsong,*tmp;

	tmp=head;
	for(int i=1;i<pos;i++)
  	{
 	  tmp=tmp->nxt;
 	  newsong=create_song();
  	  newsong->nxt=tmp->nxt;
  	  newsong->pre=tmp->nxt->pre;
 	  tmp->nxt=newsong;
 	  newsong->nxt->pre=newsong;
	}
 return head;
}


struct song * delete_end(struct song *head)
{
 struct song *tmp;
  while(tmp->nxt!=head)
     tmp=tmp->nxt;
  tmp->nxt=NULL;
  tmp->pre->nxt=head;
  head->pre=tmp->pre;
  free(tmp);

return head;
}



struct song * delete_beg(struct song *head)
{
  struct song *tmp1,*tmp;
  tmp1=tmp=head;
  while(tmp->nxt!=head)
	tmp=tmp->nxt;
  tmp1->nxt->pre=tmp;
  head=tmp1->nxt;
  tmp->nxt=head;
  tmp1->nxt=tmp1->pre=NULL;

  free(tmp1);

return head;
}


struct song * delete_pos(struct song *head,int pos)
{
  struct song *tmp;
  int i=1;
  tmp=head;
 	while(i<=pos)
  	{
	  tmp=tmp->nxt;
	  i++;
  	}
  tmp->pre->nxt=tmp->nxt;
  tmp->nxt->pre=tmp->pre;
  tmp->nxt=tmp->pre=NULL;

  free(tmp);

  return head;
}



struct song *create_list(struct song *head)
{
  struct song *tmp;
  tmp=head;
  int ch,n,pos;
  printf("\nENTER THE NUMBER OF SONGS TO BE ADDED:");
  scanf("%d",&n);
  puts("\nADD %d SONGS:");
   for(int i=1;i<=n;i++)
   {
	printf("\n1>-ADD IN THE BEGINNING\n2>-ADD AT THE END\n3>-ADD AT SPECIFIC POSITION");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: head=add_beg(head);
	        break;
	case 2: head=add_end(head);
      	  	break;
	case 3: printf("ENTER POSITION:");
     		scanf("%d",&pos);
       		head=add_pos(head,pos);
      		break;
	}
   }
  	while(tmp->nxt!=NULL)
  	{
  	  tmp=tmp->nxt;
  	}
  tmp->nxt=head;
  head->pre=tmp;

return head;
}



void play_song(struct song *head)
{
  struct song *tmp;
  int ch,res=1;
  do
  {
    printf("\n1>-PLAY BY NAME\n2>-PLAY PREVIOUS SONG\n3>-PLAY NEXT SONG\n4>-STOP");
    scanf("%d",&ch);

	switch(ch)
	{
	  case 1: res=play_name(head);
       		  break;
	  case 2: res=play_prev(head,res);
		  break;
	  case 3: res=play_next(head,res);
		  break;
	  case 4: printf("\n ): STOP PLAYING :(");
		  break;
	}
  }while(ch!=4);
}


int play_name(struct song *head)
{
 char search[30];  int c=0;
 struct song *tmp; int f=0;
 tmp=head;

  printf("\nSEARCH SONG:");
  scanf("%s",search);

  while(tmp->nxt!=head)
  {
    c++;
	if(strcmp(tmp->name,search)==0)
	{
 	 printf("\n$$$$$ %s $$$$$",tmp->name);
	 f=1;
	 printf("\n**LYRICS**\n %s",tmp->lyrics);
         break;
        }
    tmp=tmp->nxt;
  }

  if(f==0)
    {
      printf("\n): NO RESULTS :(");
      return 1;
    }
  else
    {
      return c;
    }
}


int play_next(struct song *head,int pos)
{
    struct song *tmp;
    int i=1;
    tmp=head;
    while(i<=pos)
    {
        tmp=tmp->nxt;
        i++;
    }
    printf("\n** PLAYING **");
    printf("$$$ %s $$$",tmp->name);
    printf("\n %s",tmp->lyrics);
    return(i);
}


int play_prev(struct song *head,int pos)
{
    struct song *tmp;
    int i=1;
    tmp=head;
    while(i<pos)
    {
        tmp=tmp->nxt;
        i++;
    }
    printf("\n** PLAYING **");
    printf("$$$ %s $$$",tmp->name);
    printf("\n %s",tmp->lyrics);
    return(i);

}


struct song *delete_list(struct song *head)
{
    int ch,pos;
    struct song *res;
    do
    {
        printf("\n1>-DELETE FROM BEGINNING\n2>-DELETE FROM END\n3>-DELETE AT SPECIFIC POSITION\n4>-STOP DELETING");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: res=delete_beg(head);
                    break;
            case 2: res=delete_end(head);
                    break;
            case 3: printf("\nENTER POSITION:");
                    scanf("%d",&pos);
                    res=delete_pos(head,pos);
                    break;
            case 4: printf("\n ): STOP DELETING :(");
                    break;
        }
    }while(ch!=4);
    return res;
}


void main()
{
    struct song *head=NULL;
    int ch=0;
    do
    {
        printf("\n1>-CREATE PLAYLIST\n2>-PLAY SONG\n3>-DELETE SONGS FROM PLAYLIST");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=create_list(head);
                    break;
            case 2: play_song(head);
                    break;
            case 3: head=delete_list(head);
                    break;
            case 4: printf("\n ): Exiting the App :(");
                    break;
        }
    }while(ch!=4);
     printf("\n####* EXIT *####");
}
