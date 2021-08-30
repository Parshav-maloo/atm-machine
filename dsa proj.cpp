#include<iostream> using namespace std;

 int main(){
 char option;
FILE *myFile;
char name[10];
char password[11],u_password[11];
char temp;
int p;
int id_no = 0;
int user_id = 0;
int m=10;
int all_bal[1000];
int atm_password=1234;
int acc_bal = 0;
int bal = 0;
int counter = 0;
bool vl = 0;
int char_matched = 0;
int atm_bal = 0;
  while (true){
 cout << "Select Option: "
 << endl << "1. Create New Account"
 << endl << "2. Withdraw Cash"
 << endl << "3. Cash Deposit"
 << endl <<"4. Account Summary"
 << endl <<"5. Cash fill in atm"<< endl;
 cin>>option;
 switch (option){
 case '1':
 cout << "Enter Your Name: ";
 cin >> name;
 cout << "Type '0' before your password"<<"Enter Your user Password: ";
 do{
 cin>>temp;
 cout << "*";
 u_password[counter] = temp;

  password[m]= u_password[counter];
 m--;
 counter++;
 } while (temp != 13 && counter < 11);
 counter--;
 password[counter] = '\0';
 counter = 0;
 cout << endl;
 cout << "Enter Opening balance:";
 cin >> acc_bal;
 if (acc_bal < 0){
 acc_bal = 0;
}
vl = 0;
  myFile = fopen("all_passwords.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-')
 {

  if (password[counter] == temp){
 char_matched++;
 counter++;
 }else {
 char_matched = 0;
 counter = 0;
 }
}
  if (temp == '-'){
 if (char_matched == strlen(password)){
 vl = 1;
 }
  }
}
counter = 0;
char_matched = 0;
  }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 if (vl == 0){
 myFile = fopen("all_names.txt", "a");
 fprintf(myFile, "%s", name);

  fprintf(myFile, "%c", '-');
 fclose(myFile);
 cout<<"\n"<<password;
 myFile = fopen("all_passwords.txt", "a");
 fprintf(myFile, "%s", password);
 fprintf(myFile, "%c", '-');
 fclose(myFile);
 myFile = fopen("all_accounts.txt", "a");
 fprintf(myFile, "%d", acc_bal);
 fprintf(myFile, "%c", '\n');
 fclose(myFile);
  cout << "Account created succesfully" << endl;
}
}
 else {
 cout << "account no. Already In Use............." << endl;
 break;
 case '2':
 cout << "Enter Your Name: ";

  cin >> name;
 vl = 0;
 counter = 0;
 char_matched = 0;
 myFile = fopen("all_names.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-'){
 if (name[counter] == temp){
 char_matched++;
 counter++;
 }
 else {
 char_matched = 0;
 counter = 0;
 }
 }
 if (temp == '-'){
 if (char_matched == strlen(name)){
 vl = 1;
 user_id = id_no;
 }
 id_no++;

  } }
}
}
counter = 0;
 char_matched = 0;
  }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 else {
 cout << "account does not exists..." << endl;
 if (vl == 0){
 cout << "account does not exists..." << endl;
 else {
 cout << "Type '0' before your password"<<"Enter Your user Password: " <<
 endl;
 do{
 cin>>temp;
 cout << "*";
 u_password[counter] = temp;
 password[m]= u_password[counter];

  counter--;
m--;
 counter++;
 } while ( counter < 11);
  password[counter] = '\0';
 counter = 0;
 cout << endl;
 vl = 0;
 counter = 0;
 char_matched = 0;
 id_no = 0;
 myFile = fopen("all_passwords.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-' && id_no == user_id){
 if (password[counter] == temp){
 }
char_matched++;
 counter++;
  else {
 }
char_matched = 0;
 counter = 0;
  }

  }
if (temp == '-'){
 if (char_matched == strlen(password)){
 }
vl = 1;
  id_no++;
 counter = 0;
 char_matched = 0;
 }
  fclose(myFile);
 counter = 0;
 char_matched = 0;
 }
 if (vl == 1){
 cout << "ACESS GURANTED***" << endl
 << "Enter Amount to withdraw: ";
 cin >> acc_bal;
 vl = 0;
 counter = 0;
 myFile = fopen("all_accounts.txt", "r");

  if (myFile){
 while (counter <= user_id){
 counter++;
 fscanf(myFile, "%d", &bal);
 }
myFile = fopen("atm_balance.txt", "r");
  if (myFile){
 fscanf(myFile, "%d", &atm_bal);
 } else {
 myFile = fopen("atm_balance.txt", "w");
 fprintf(myFile, "%d", atm_bal);
 }
 fclose(myFile);
 if(bal < acc_bal){
 cout << "You Have only: " << bal << "₹" << endl;
 }
 if(acc_bal > atm_bal && bal >= acc_bal) {
 cout << "Machine Have only: " << atm_bal << "$" << endl;
 }else if(acc_bal <= atm_bal && bal >= acc_bal){
 myFile = fopen("all_accounts.txt", "r");

  counter = 0;
 while (fscanf(myFile, "%d", &all_bal[counter]) == 1){
 counter++;
 }
 fclose(myFile);
 all_bal[user_id] -= acc_bal;
 cout<< "your avialable balance is:"<<all_bal[user_id]<<endl;
 myFile = fopen("all_accounts.txt", "w");
 id_no = 0;
 while (counter != 0){
 fprintf(myFile, "%d", all_bal[id_no]);
 fprintf(myFile, "%s", "\n");
 counter--;
 id_no++;
 }
 fclose(myFile);
atm_bal -= acc_bal;
  myFile = fopen("atm_balance.txt", "w");
 fprintf(myFile, "%d", atm_bal);
 fclose(myFile);
 cout << "\n Take your money. THankx.." << endl;
 }

  }}
counter = 0;
 char_matched = 0;
 }
 } else{
 cout << "Acess Denied.." << endl;
  id_no = 0;
 user_id = 0;
 break;
 case '3':
 cout << "Enter Your Name: ";
 cin >> name;
 vl = 0;
 counter = 0;
 char_matched = 0;
 myFile = fopen("all_names.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-'){
 if (name[counter] == temp){
 char_matched++;
 counter++;

  }
 else {
 char_matched = 0;
 counter = 0;
 }
 }
 if (temp == '-'){
 if (char_matched == strlen(name)){
 vl = 1;
 user_id = id_no;
 }
  } }
id_no++;
counter = 0;
 char_matched = 0;
 }
 }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 else {
 cout << "account does not exists..." << endl;

  endl;
if (vl == 0){
 }
cout << "account does not exists..." << endl;
 else {
 cout << "Type '0' before your password"<<"Enter Your user Password: " <<
  do{
 cin>> temp;
 cout << "*";
 u_password[counter] = temp;
 password[m]=u_password[counter];
 m--;
 counter++;
 } while (counter < 11);
 counter--;
 password[counter] = '\0';
 counter = 0;
 cout << endl;
 vl = 0;
 counter = 0;
 char_matched = 0;
 id_no = 0;

  myFile = fopen("all_passwords.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-' && id_no == user_id){
 if (password[counter] == temp){
 char_matched++;
 counter++;
 }
 else {
 }
char_matched = 0;
 counter = 0;
  }
 if (temp == '-'){
 if (char_matched == strlen(password)){
 vl = 1;
 }
 id_no++;
 counter = 0;
 char_matched = 0;
 }
 }
 fclose(myFile);

  counter = 0;
 char_matched = 0;
 }
 if (vl == 1){
 cout << "ACESS GURANTED***" << endl
 << "Enter Amount to deposit: ";
 cin >> acc_bal;
 vl = 0;
 counter = 0;
 myFile = fopen("all_accounts.txt", "r");
 if (myFile){ ////IMPORTANT ONE
 while (counter <= user_id){
 counter++;
 fscanf(myFile, "%d", &bal);
 }
myFile = fopen("atm_balance.txt", "r");
  if (myFile){
 fscanf(myFile, "%d", &atm_bal);
 } else {
 myFile = fopen("atm_balance.txt", "w");

  fprintf(myFile, "%d", atm_bal);
 }
 fclose(myFile);
 if(acc_bal >0){
 myFile = fopen("all_accounts.txt", "r");
 counter = 0;
 while (fscanf(myFile, "%d", &all_bal[counter]) == 1){
 counter++;
 }
 fclose(myFile);
 all_bal[user_id] += acc_bal;
 myFile = fopen("all_accounts.txt", "w");
 id_no = 0;
 while (counter != 0){
 fprintf(myFile, "%d", all_bal[id_no]);
 fprintf(myFile, "%s", "\n");
 counter--;
 id_no++;
 }
 fclose(myFile);
 cout << "Your account balance is:"<<all_bal[user_id]<<"\n CASH DE-
 POSITED. THankx.." << endl;

  }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 }
 } else{
 cout << "Acess Denied.." << endl;
 }}
 id_no = 0;
 user_id = 0;
 break;
 case '4':
 cout << "Enter Your Name: ";
 cin >> name; vl = 0;
 counter = 0;
 char_matched = 0;
 myFile = fopen("all_names.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-'){
 if (name[counter] == temp){
 char_matched++;
 }
counter++;
  else {

  }
}
char_matched = 0;
 counter = 0;
   if (temp == '-'){
 if (char_matched == strlen(name)){
 }
vl = 1;
 user_id = id_no;
  id_no++;
 }
counter = 0;
 char_matched = 0;
  }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 }
 else {
 cout << "account does not exists..." << endl;
 }
 if (vl == 0){
 cout << "account does not exists..." << endl;
 }

  else {
 cout << "Type '0' before your password"<<"Enter Your user Password:
 " << endl;
 do{
 cin>>temp;
 cout << "*";
 u_password[counter] = temp;
 password[m]= u_password[counter];
 m--;
 counter++;
 } while (temp != 13 && counter < 11);
 counter--;
 password[counter] = '\0';
 counter = 0;
 cout << endl;
 vl = 0;
 counter = 0;
 char_matched = 0;
 id_no = 0;
 myFile = fopen("all_passwords.txt", "r");
 if (myFile){
 while (fscanf(myFile, "%c", &temp) == 1){
 if (temp != '-' && id_no == user_id){

  if (password[counter] == temp){
 char_matched++;
 counter++;
 }
 else {
 char_matched = 0;
 counter = 0;
 }
 }
 if (temp == '-'){
 if (char_matched == strlen(password)){
 vl = 1;
 }
 id_no++;
 counter = 0;
 char_matched = 0;
 }
 }
 fclose(myFile);
 counter = 0;
 char_matched = 0;
 }

  if (vl == 1){
 cout << "ACESS GURANTED***" << endl;
 vl = 0;
 counter = 0;
 myFile = fopen("all_accounts.txt", "r");
 if (myFile){
 while (counter <= user_id){
 counter++;
 fscanf(myFile, "%d", &bal);
 }
 fclose(myFile);
 cout<<"Your current balance is:"<<bal<<endl;
 }
 }else{
 cout << "Acess Denied.." << endl;
 }
 }
 id_no = 0;
 user_id = 0;
 break;
 case '5':
 cout<<"Enter the atm password: ";
 cin>>p;

  if (p==atm_password)
 {
 cout << "Enter Amount to add: ";
 cin >> bal;
 myFile = fopen("atm_balance.txt", "r");
 if (myFile){
 fscanf(myFile, "%d", &atm_bal);
 } else {
 myFile = fopen("atm_balance.txt", "w");
 fprintf(myFile, "%d", atm_bal);
}
fclose(myFile);
atm_bal += bal;
   myFile = fopen("atm_balance.txt", "w");
 fprintf(myFile, "%d", atm_bal);
 fclose(myFile);
 cout<<"\nCurrent amount in atm is: "<<atm_bal;
 }
 else
 {
 cout<<"Invalid atm password\n";

 }
break;
}
 default:
 break;
cout << "Press any key to continue....";
 }
return 0; }