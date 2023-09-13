#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
class dairy
{
	private:
		char username[20],u[20],s_name[20];
		char pass[20],s1[20],p;
		long int cvv;
		int i;
		long int mob_no,o_accbal,o_mlitre,s_tcost;
	public:
		dairy()    //default constructor
		{
			strcpy(u,"tejalkn");
			strcpy(s1,"tejal123");
			o_accbal=80000;
			o_mlitre=50;
			int i=0;

		}
		void owner_accept();
		void owner_checkbal();
		void owner_milkQ();
		void cust_getdata1(int a[10]);
		void supplier();

};

		void dairy::owner_accept() //scope resolution operator concept
		{
			a:
			cout<<"\nEnter UserName:";
			cin>>username;
			if((strcmp(u,username))!=0)
			{
			cout<<"\n\tUserName is invalid!";
			goto a;
			}
		b:
		cout<<"\nEnter 6 character password:";
		for(i=0;;)
		{
		p=getch();
		if((p>='a' && p<='z')||(p>='A' && p<='Z')||(p>='0' && p<='9'))
		{
			pass[i]=p;
			++i;
			cout<<"*";
		}
		if(p=='\b' && i>=1)
		{
			cout<<"\b \b";
			--i;
		}
		if(p=='\r')
		{
			pass[i]='\0';
			break;
		}
		}
		if(i<=5)
		{
			cout<<"\n Minimum 6 characters needed.\nEnter again..";
			getch();
			goto b;
		}
		if((strcmp(pass,s1))!=0)
		{
			cout<<"\nPassword is invalid!";
			goto b;
		}
		cout<<"\nOwner's login successful!";

		}

		void dairy::owner_checkbal()
		{
			cout<<"\n\tNow Owner's account balance is:"<<o_accbal<<" Rs";
		}

		void dairy::owner_milkQ()
		{
			cout<<"\n\t Now Milk is available in dairy is:"<<o_mlitre<<" Litre";
		}

		void dairy::cust_getdata1(int a[])
		{

			char c_name[20],captcha[10],capt[10];
			int i,o,h;
			int q,tot_rate,ch,c_accno;
			cout<<"\n\t **** DAIRY PRODUCTS ****";
			cout<<"\n\t 1.Milk(half litre):"<<a[0]<<" Rs";
			cout<<"\n\t 2.Curd(250 gm):"<<a[1]<<" Rs";
			cout<<"\n\t 3.Cheeze(250 gm):"<<a[2]<" Rs";
			cout<<"\n\t 4.Ghee(250 gm):"<<a[3]<<" Rs";
			cout<<"\n\t 5.Buttermilk(1 litre):"<<a[4]<<" Rs";
			cout<<"\n\t 6.Lassi(250 gm):"<<a[5]<<" Rs";
			cout<<"\n\t 7.Paneer(250 gm):"<<a[6]<<" Rs";
			cout<<"*****************************";
			g:
			cout<<"\nEnter option you want to purchase:";
			cin>>o;

			if(o>7)
			{
			cout<<"\nPlease enter Valid option..";
			goto g;
			}

			if(o==1 || o==5)
			{
			cout<<"\nIf you want in mililitre then press 1 either press 2 for litre: ";
			cin>>h;
				if(h==1)
				{
				cout<<"\nEnter how many mililitre milk you want:";
				cin>>q;
				if(q==250)
				tot_rate=a[o-1]/2;
				if(q==500)
				tot_rate=a[o-1];
				if(q==750)
				tot_rate=(a[o-1]/2)*3;
				}

				if(h==2)
				{
				cout<<"\nEnter how many litre do you want:";
				cin>>q;
				tot_rate=(a[o-1]*2)*q;
				}
			}
			else if(o>1)
			{
			cout<<"\nif you want in gram then press 1 either press 2 for kilo:";
			cin>>h;
			if(h==1)
			{
			cout<<"\nEnter how many gram do you want:";
			cin>>q;
			if(q==250)
			tot_rate=a[o-1];
			if(q==500)
			tot_rate=a[o-1]*2;
			if(q==750)
			tot_rate=a[o-1]*3;
			}

			if(h==2)
			{
			 cout<<"\nEnter how many kilo do you want:";
			 cin>>q;
			 tot_rate=(a[o-1]*4)*q;
			 }
			 }
			cout<<"\nYour Total Bill is:"<<tot_rate<<" Rs";
			c:
			cout<<"\n\t1.Cash payment \n\t2.Online payment";
			cout<<"\n Enter your choice:";
			cin>>ch;
			switch(ch)
			{

					case 1: cout<<"\nEnter your Name:";
						 cin>>c_name;
						o_accbal=o_accbal+tot_rate;
						cout<<"\n You paid successfully  "<<tot_rate<<" Rs to Owner";
						cout<<"\n\t Thank You Visit Again..!!!";
						getch();
						break;

					case 2:
						strcpy(capt,"CvYop");
						cout<<"\nEnter your Name:";
						cin>>c_name;
						cout<<"\n\t Enter your account number:";
						cin>>c_accno;
						v:
						cout<<"\n\t Enter your CVV Number:";
						cin>>cvv;
						clrscr();
						textbackground(BLACK);
						textcolor(YELLOW);
						d:
						cout<<"\n\t captcha:CvYop";
						cout<<"\n\t Enter captcha here:";
						cin>>captcha;
						cout<<captcha;
						if((strcmp(capt,captcha))==0)
						goto y;
						else
						{
						cout<<"\nPlease enter correct captcha!!";
						goto d;
						}
						y:
						o_accbal=o_accbal+tot_rate;
						cout<<"\nYou paid successfully  "<<tot_rate<<" Rs to Owner!!";
						break;

			 }
		}

		void dairy::supplier()
		{
			int sup_litre,cost_litre;
			cout<<"\nEnter your Name:";
			cin>>s_name;
			cout<<"\nEnter How many Litre Milk you want to supply:";
			cin>>sup_litre;
			cout<<"\nEnter the cost for per litre:";
			cin>>cost_litre;
			if(cost_litre>45)
			{
			cout<<"\n\t\tSorry...Owner is not Affordable to you,\n\t\tYour's rate is out of Owner's Budget...!!! ";
			getch();
			}
			else if(cost_litre<=45)
			{
			o_mlitre=o_mlitre+sup_litre;
			cout<<"\n\tMilk is accepted by owner...";
			getch();
			clrscr();
			cout<<"\n\n\t\tTotal cost is:"<<sup_litre*cost_litre<<" Rs";
			m:
			cout<<"\nEnter your mobile number for transfer money in your account:";
			cin>>mob_no;
			if((mob_no>9999999999 ) || (mob_no<=999999999))
			{
			cout<<"\n Please enter valid mobile number..";
			goto m;
			}
			s_tcost=sup_litre*cost_litre;
			o_accbal=o_accbal-s_tcost;
			cout<<s_tcost<<" Rs is Deposited on your account by Google Pay Successfully!!";
			 getch();
			 }
			clrscr();
			cout<<"\n\n\t\tThank you for coming at Dairy management system!!";

		}

void main()
{
	dairy d;
	int ch,o,cnt=0,size;
	int a[10]={30,20,100,200,30,30,50};
	char c,v,b,f;
	char c1;
	int o1,rate;
	clrscr();
	textbackground(BLUE);
	textcolor(YELLOW);
	       b:
		cout<<"\n\t************************************";
		cout<<"\n\t WELCOME TO DAIRY MANAGEMENT SYSTEM";
		cout<<"\n\t************************************";
		cout<<"\n\t 1.OWNER";
		cout<<"\n\t 2.CUSTOMER";
		cout<<"\n\t 3.SUPPLIER";
		cout<<"\n\t 4.Exit";
		cout<<"\n\t ***********************************";
		cout<<"\n\t Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: e:
				do
				{
				clrscr();
				cout<<"\n\t**** OWNER'S MENU ****";
				cout<<"\n\t1.Owner Login";
				cout<<"\n\t2.Change Product's Rate";
				cout<<"\n\t3.Check Account Balance";
				cout<<"\n\t4.Check Milk Quantity";
				cout<<"\n\t***************************";
				cout<<"\n\t Enter option:";
				cin>>o1;
				if(o1==1)
				cnt=cnt+1;
				switch(o1)
				{
					case 1:d.owner_accept();
						break;

					case 2:
						if(cnt==0)
						{
						cout<<"\nYou have to Login first!!";
						getch();
						goto e;
						}
							clrscr();
							c:
							cout<<"\n\t **** DAIRY PRODUCTS ****";
							cout<<"\n\t 1.Milk(1 litre):"<<a[0]<<"\n";
							cout<<"\n\t 2.Curd(250 gm):"<<a[1]<<"\n";
							cout<<"\n\t 3.Cheeze(250 gm):"<<a[2]<"\n";
							cout<<"\n\t 4.Ghee(250 gm):"<<a[3]<<"\n";
							cout<<"\n\t 5.Buttermilk(1 litre):"<<a[4]<<"\n";
							cout<<"\n\t 6.Lassi(250 gm):"<<a[5]<<"\n";
							cout<<"\n\t 7.Paneer(250 gm):"<<a[6]<<"\n0";
							cout<<"*****************************";
							cout<<"\nDo you want to change the rate(yes/no):";
							cin>>c;
							if(c=='y'||c=='Y')
							{
							   a:
							   cout<<"\n\t Enter the option of product for changing rate:";
								cin>>o;
							 if(o>7)
							 {
								cout<<"\n\tPlease enter valid option";
								goto a;
							  }
							 d:
							 cout<<"\n\t Enter the New Rate:";
							cin>>rate;
							if(rate<0)
							 {
							 cout<<"\nplease enter positive rate";
							 goto d;
							 }
							a[o-1]=rate;
							goto c;
							}
							//d.cust_getdata1(a);
							break;

					case 3:if(cnt==0)
						{
						cout<<"\nYou have to Login first!!";
						getch();
						goto e;
						}
						d.owner_checkbal();
						break;

					case 4:if(cnt==0)
						{
						cout<<"\nYou have to Login First!!";
						getch();
						goto e;
						}
						d.owner_milkQ();
						break;

				}
				cout<<"\n\t Do you want to go in Owner's Menu again(yes/no):";
				cin>>c;
				}while(c=='y'||c=='Y');
				goto j;
				break;

			case 2: do
				{
				clrscr();
				d.cust_getdata1(a);
				cout<<"\nDo you want to go in customer's menu again(yes/no):";
				cin>>b;
				}while(b=='y'||b=='Y');
				goto j;

			case 3: do
				{
				clrscr();
				d.supplier();
				cout<<"\nDo you Want to go in Supplier's menu again(yes/no):";
				cin>>f;
				}while(f=='y'||f=='Y');
				goto j;

			case 4:break;

		j:
		cout<<"\nDo you want to go in Main Menu:";
		cin>>v;
		cout<<"\n\t... Thank You Visit Again...";
		}
		if(v=='y'||v=='Y')
		goto b;
		getch();
}






