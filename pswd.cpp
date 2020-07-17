/* 
 - This program is to generate password of
   desire length by the user.
 - The program will also show the strength
   of the password and time to bypass it.
 - At the end of passwords generated, it will 
   ask to export the data.

   Author: Ankit Kumar
   Version: 1.0
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

#define MAX 72

string password(int n) {
	
	// This function is used to generate random passwords
	
	char charlib[MAX] = 
		{
		 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		 'u', 'v', 'w', 'x', 'y', 'z',
		 'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		 'U', 'V', 'W', 'X', 'Y', 'Z',
		 '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		 '@', '!', '#', '$', '%', '&', '*', '?', '+', '-'						 
		};
	
	string res = "";
	for(int i = 0; i < n; i++) 
		res += charlib[rand()%MAX];	
		
	return res;	
}

void strength(string& input) {
	int n = input.length();
	
	// This area will valid the following conditions:
	// Upper, Lower, Digits, Special Characters
	
	bool hasLower = false, hasUpper = false;
	bool hasDigit = false, specialChar = false;
	string normalChars = "abcdefghijklmnopqrstuvwxyz" 
						 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						 "1234567890";
	for(int i = 0; i < n; i++) {
		if(islower(input[i]))
			hasLower = true;
		if(isupper(input[i]))
			hasUpper = true;
		if(isdigit(input[i]))
			hasDigit = true;
		size_t special = input.find_first_not_of(normalChars);	
		if(special != string::npos)
			specialChar = true;			
	}
	
	// This area will find the strength of the generated passwords
	
	if(n >= 10) {
		if(hasLower && hasUpper && hasDigit && specialChar)
			cout << "Very Strong";
		else if(hasLower && hasUpper && hasDigit)	
			cout << "Strong";
		else if(hasLower && hasUpper && specialChar)
			cout << "Good";
		else if(hasLower && hasUpper)
			cout << "Weak";
		else if(hasDigit)
			cout << "Very Weak";				
	}
	
	else if(n >= 6) {
		if(hasLower && hasUpper && hasDigit && specialChar)
			cout << "Strong";
		else if(hasLower && hasUpper && hasDigit)	
			cout << "Better";
		else if(hasLower && hasUpper && specialChar)
			cout << "Good";
		else if(hasLower && hasUpper)
			cout << "Weak";
		else	
			cout << "Very Weak"; 
	}
	
	else if(n >= 4) {
		if(hasLower && hasUpper && hasDigit && specialChar)
			cout << "Better";
		else if(hasLower && hasUpper && hasDigit) 
			cout << "Good";
		else if(hasUpper && hasLower)
			cout << "Weak";	
		else 
			cout << "Very Weak";		
	}
	
	else if(n < 4) {
		if(hasUpper && hasLower && hasDigit && specialChar)
			cout << "Weak";
		else
			cout << "Very Weak";	
	}
	
	else 
		cout << "Extremely Weak";
	
	
	// This area will find the time to bypass the generated password
	
	if(n >= 18 && hasDigit && hasUpper && hasLower && specialChar) cout << " - 14qd to 1qt yrs\n";
	else if(n >= 16 && hasDigit && hasUpper && hasLower && specialChar) cout << " - 5bn to 193tn yrs\n";
	else if(n >= 11 && hasDigit && hasUpper && hasLower && specialChar) cout << " - 12 yrs to 71k yrs\n";
	else if(n >= 8 && hasDigit && hasUpper && hasLower && specialChar) cout << " - 13mins to 57days\n";
	else if(n == 5 && hasDigit && hasUpper && hasLower && specialChar) cout << " - 10secs\n";
	
	else if(n >= 18 && hasDigit && hasUpper && hasLower) cout << " - 6tn to 23qd yrs\n";
	else if(n >= 15 && hasDigit && hasUpper && hasLower) cout << " - 1bn to 97bn yrs\n";
	else if(n == 13 && hasDigit && hasUpper && hasLower) cout << " - 25mn yrs\n";
	else if(n >= 12 && hasDigit && hasUpper && hasLower) cout << " - 6k to 108k yrs\n";
	else if(n >= 10 && hasDigit && hasUpper && hasLower) cout << " - 1yr to 106 yrs \n";
	else if(n >= 8 && hasDigit && hasUpper && hasLower) cout << " - 3mins to 10days\n";

	else if(n >= 18 && hasUpper && hasLower) cout << " - 3bn yrs\n";
	else if(n >= 17 && hasUpper && hasLower) cout << " - 143m to 512m yrs\n";
	else if(n >= 15 && hasUpper && hasLower) cout << " - 8k to 212k yrs\n";
	else if(n >= 13 && hasUpper && hasLower) cout << " - 12yrs to 314yrs\n";
	else if(n >= 11 && hasUpper && hasLower) cout << " - 6days to 169days\n";
	else if(n >= 9  && hasUpper && hasLower) cout << " - 13mins to 6hrs\n";
		
	else if(n >= 18 && hasDigit) cout << " - 1yr to 126yrs\n";
	else if(n >=15 && hasDigit) cout << " - 4days to 46days\n";
	else if(n >= 13 && hasDigit) cout << " - 1hr to 11hrs\n";
	else if(n == 11 && hasDigit) cout << " - 6mins\n";
	else if(n >= 10 && hasDigit) cout << " - 4secs to 40secs\n";
	
	else cout << " - Instantly\n";
				 
}

int main(int argc, char **argv) {
  srand(time(NULL));
  cout << "*** PASSWORD GENERATOR *** \n\n";

  cout << "Enter the length of password - ";
  int passwordlength;
  cin >> passwordlength;  
  
  cout << "How many suggestion you want? - ";
  int s;
  cin >> s;
  
  cout << endl << s << " passwords are: \n\n";
  
  string temp;
  
  for(int i = 1; i <= s; i++) {
  	cout << "[" << i << "] \t" << password(passwordlength);
  	temp = password(passwordlength);
  	cout << " - ";
	   strength(temp);
  }
  
  return 0;
}
