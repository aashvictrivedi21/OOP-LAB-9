#include<iostream>
using namespace std;
class Bank_Account
{
	protected:
		char customer_name[50];
		char address[100];
		int age;
		long int saving_acc_no;
		double balance;
	public:
		void open_acc()
		{
			cout<<"\nEnter saving accout no. "<<endl;
			cin>>saving_acc_no;
			cout<<"\nEnter customer name:"<<endl;
			cin>>customer_name;
			cout<<"\nEnter age:"<<endl;
			cin>>age;
			cout<<"\nAddress:"<<endl;
			cin>>address;
			fflush(stdin);
			
			cout<<"\nEnter Balance (INR):"<<endl;
			fflush(stdin);
			
			cin>>balance;
			
		}
		
		void withdraw()
		{
			double withdraw_amt;
			cout<<"\nEnter the amount to withdraw:"<<endl;
			fflush(stdin);
			
			cin>>withdraw_amt;
			if (withdraw_amt>balance)
			{
				cout<<"\nCould not withdraw more than balance ..!!";
				return ;
				
			}
			else
			{
				balance = balance - withdraw_amt;
				cout<<"\nAfter withdraw your balance is :"<<balance<<endl;
				
			}
			
		}
		
			void Deposit()
		{
			double deposit_amt;
			cout<<"\nEnter the amount to deposit:"<<endl;
			fflush(stdin);
			cin>>deposit_amt;
			balance = balance + deposit_amt;
			cout<<"\nAfter deposit your updated balance is :"<<balance<<endl;
				
		}
			
		
};
class Life_Insurance : virtual public Bank_Account
{
	protected:
		long int policy_no;
		long int sum_assured;
		long int premium;
		float term;
	public:
		void readdata()
		{
			cout<<"\nEnter the Policy Number:"<<endl;
			cin>>policy_no;
			cout<<"\nEnter the sum assured:"<<endl;
			cin>>sum_assured;
			cout<<"\nTerm:"<<endl;
			cin>>term;
		
		// call for premium calculation
		calculate_premium();	
		}
		
		void calculate_premium()
		{
			if (age <= 25)
			{
				premium  = (sum_assured * 3000) / 100000;	
			}
			else if (age <=45)
			{
				premium  = (sum_assured * 4000) / 100000;	
			}
			
			else if (age <=60)
			{
				premium  = (sum_assured * 5000) / 100000;	
			}
			else 
			{
				premium = 0;
				cout<<"\nNo insurance allowed for this age!!"<<endl;
				
			}
			
		}
		
		void deduct_premium_from_saving()
		{
			balance = balance - premium;
			term = term - 1;
			
		}
		
		void display_life_insurance()
		{
		
			cout<<"\nPolicy No:"<<policy_no<<endl;
			cout<<"\nSum assured:"<<sum_assured<<endl;
			cout<<"\nPremium:"<<premium<<endl;
			cout<<"\nSaving balance:"<<balance<<endl;
			cout<<"\nRemaining Term:"<<term<<endl;
			
		}
};
class Car_Insurance : virtual public Bank_Account
{
protected:
	long int policy_no;
	long int car_sum_assured;
	int car_dtls;
	long carpremium ;
	float duration;
	

public:
	void read_car_insurance()
	{
			cout<<"\nEnter the Car Policy Number:"<<endl;
			cin>>policy_no;
			cout<<"\nEnter the car age (in years):"<<endl;
			cin>>car_dtls;
			cout<<"\nEnter Term (in years):"<<endl;
			cin>>duration;
			
			//calling car premium
			
			calculate_premium();
	}
	
	void calculate_premium()
		{
			if (car_dtls <=1)
			{
				carpremium  = (car_sum_assured * 5000) / 100000;	
			}
			else if ((car_dtls >=2) &&(car_dtls <= 4))
			{
				carpremium  = (car_sum_assured * 3000) / 100000;	
			}
			
			else if ((car_dtls >=5) &&(car_dtls <= 7))
			{
				carpremium  = (car_sum_assured * 2000) / 100000;	
			}
			
			
		}
		
		void deduct_car_premium_from_saving()
		{
			balance = balance - carpremium;
			
			
		}
		
			void display_car_insurance()
		{
		
			cout<<"\nCar Policy No:"<<policy_no<<endl;
			cout<<"\nCar Details:"<<car_dtls<<endl;
			cout<<"\nCar Premium:"<<carpremium<<endl;
			cout<<"\nSaving balance:"<<balance<<endl;
			
		}
		
};

class claim : public Life_Insurance, public Car_Insurance
{
	protected:
		
		int policy_closed_period;
		long int settlement_amount;
		long int car_repairing_exp;
	public:
		void settlement()
		{
			cout<<"\nEnter the policy closed period"<<endl;
			cin>>policy_closed_period;
			if (policy_closed_period <= 5)
			{
			settlement_amount = 0 ;
					
			}
			else if ((policy_closed_period >=6) && (policy_closed_period <= 12))
			{
				settlement_amount = sum_assured * 0.25;
			}
			else if ((policy_closed_period >=13) && (policy_closed_period <= 20))
			{
				settlement_amount = (sum_assured * 0.50) + (sum_assured * 0.20);
				
			}
			else 
			{
				settlement_amount = sum_assured  + sum_assured ;
				
			}
			
			balance += settlement_amount;
			cout<<"\nSettlement amount for life insurance : "<<settlement_amount<<endl;
			cout<<"Your bank balance updated after deposit of amount for the settlement of Life Insurance :"<<balance<<endl;
			 
			
			// car insurancce
			cout<<"\nEnter the amount you spent on car repairing :"<<endl;
			cin >>car_repairing_exp;
			
			balance += car_repairing_exp;
			cout<<"\nSettlement amount for car insurance : "<<car_repairing_exp<<endl;
			cout<<"Your bank balance updated after deposit of amount for the settlement of Car Insurance :"<<balance<<endl;
			
			
			
		}
};

int main ()
{
	
	claim c1;
	//bank account method calls 
	c1.open_acc();
	c1.Deposit();
	c1.withdraw();
	
	
	//Life insurance class method calls
	c1.readdata();
	
	c1.deduct_car_premium_from_saving();
	c1.display_life_insurance();
	
	
	//car insurance class method calls
	
	c1.read_car_insurance();

	c1.deduct_car_premium_from_saving();
	c1.display_car_insurance();
	
	//claim class 
	
	c1.settlement();
	
	return 0;
	
}

