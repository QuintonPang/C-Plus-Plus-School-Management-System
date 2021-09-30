#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// structures with declaration of variables

struct Student {
	string id;
	string name;
	string age;
	string className;
} studentData;  // initialization

struct Teacher {
	string id;
	string name;
	string subject;
	string className;
} teacherData;

int main() {

	int input;

	// infinite loop, any number except  will do
	while(1) {
		cout<<"SCHOOL MANAGEMENT SYSTEM\nBY QUINTON PANG\n\n";
		cout<<"Enter 1 for student access\n";
		cout<<"Enter 2 for teacher access\n";
		cout<<"Enter 0 to exit\n";
		cin>>input;

		system("cls"); // clear screen


		switch(input) {

			// student page
			
			case 1:
				
				while(1){
					cout<<"STUDENT PAGE\n\n";
					cout<<"Enter 1 to register yourself as new student\n";
					cout<<"Enter 2 to check your information\n";
					cout<<"Enter 0 to return to main page\n";
					
					cin>>input;
					
					system("cls");
					
					switch (input){
						
						case 1:
							
							do{
								string flag;
							
								string text;
								int no = 0;
								
								// Read from the text file
								ifstream MyReadFile("student.txt");
								
								// Use a while loop together with the getline() function to read the file line by line
								while (getline (MyReadFile, text)) {
								  no ++; // get latest id
								}
								
								ofstream f1("student.txt",ios::app); // write to file
								
									
								// convert int to string
								std::ostringstream ss;
								ss<<(no/5+1);
								
								
								studentData.id = ss.str();
								cout<<"ENTER YOUR INFORMATION FOR REGISTRATION:\n\n";
								cout<<"Name:";
								cin>>studentData.name;
								cout<<"Age:";
								cin>>studentData.age;
								cout<<"Class:";
								cin>>studentData.className;
								
								cout<<endl<<"Your ID:"<<studentData.id<<endl;
									
								// write inputs to file
								// endl means new line
								
								 f1<<studentData.id<<endl<<studentData.name<<endl<<studentData.age<<endl<<studentData.className<<endl<<endl;
							
								
								cout<<"Enter again? Y for yes, others for no ";
								cin>>flag;
								
								system("cls");
								
								if (flag=="Y"){
									continue;
								}else{
									break;
								}
								
							}while(1);
							
							continue; // repeats from the start again
							
						case 2:
							
							do{
							
								string flag;
								string searchId;
								bool found = false;
								
								cout<<"Enter your id:";
								cin>>searchId;
								cout<<endl;
								
								// Read from the text file
								ifstream MyReadFile("student.txt");
								
								// Use a while loop together with the getline() function to read the file line by line
								while (getline (MyReadFile, studentData.id)) {
								  if (studentData.id==searchId){
								  		
								  		found = true;
								  		
								  		cout<<"STUDENT FOUND !"<<endl<<endl;
									  	cout<<"ID: "<<studentData.id<<endl;
										
										// gets next line
										getline(MyReadFile,studentData.name);
										cout<<"Name: "<<studentData.name<<endl;
										
										getline(MyReadFile,studentData.age);
										cout<<"Age: "<<studentData.age<<endl;
										
										getline(MyReadFile,studentData.className);
										cout<<"Class: "<<studentData.className<<endl;
										
								  }
								  
								  
								}
								
								if (found==false) cout<<"NO RECORD FOUND !"<<endl<<endl;
								
								cout<<"Try again? Y for yes, others for no ";
								cin>>flag;
									
								system("cls");
								
								if (flag=="Y"){
									continue;
								}else{
									break;
									}
							}while(1);
							
							continue;
							
						case 0:
							
							break;
							
						default:
							cout<<"\nPLEASE ENTER VALID INPUT!\n\n";
							continue;
					}
					
					
					break;
				}
				
				continue;
				
			case 2:

					while(1){
					cout<<"TEACHER PAGE\n";
					cout<<"Enter 1 to register yourself as new teacher\n";
					cout<<"Enter 2 to check your information\n";
					cout<<"Enter 0 to return to main page\n";
					
					cin>>input;
					
					system("cls");
					
					switch (input){
						
						case 1:
							
							do{
								string flag;
							
								string text;
								int no = 0;
								
								// Read from the text file
								ifstream MyReadFile("teacher.txt");
								
								// Use a while loop together with the getline() function to read the file line by line
								while (getline (MyReadFile, text)) {
								  no ++; // get latest id
								}
								
								ofstream f1("teacher.txt",ios::app); // write to file
								
									
								// convert int to string
								std::ostringstream ss;
								ss<<(no/5+1);
								
								
								teacherData.id = ss.str();
								cout<<"ENTER YOUR INFORMATION FOR REGISTRATION:\n\n";
								cout<<"Name:";
								cin>>teacherData.name;
								cout<<"Subject:";
								cin>>teacherData.subject;
								cout<<"Class:";
								cin>>teacherData.className;
								
								cout<<endl<<"Your ID:"<<teacherData.id<<endl;
								
								// write inputs to file
								// endl means new line
								
								 f1<<teacherData.id<<endl<<teacherData.name<<endl<<teacherData.subject<<endl<<teacherData.className<<endl<<endl;
							
								
								cout<<"Enter again? Y for yes, others for no ";
								cin>>flag;
								
								system("cls");
								
								if (flag=="Y"){
									continue;
								}else{
									break;
								}
								
							}while(1);
							
							continue; // repeats from the start again
							
						case 2:
							
							do{
							
								string flag;
								string searchId;
								bool found = false;
								
								cout<<"Enter your id";
								cin>>searchId;
								
								// Read from the text file
								ifstream MyReadFile("teacher.txt");
								
								// Use a while loop together with the getline() function to read the file line by line
								while (getline (MyReadFile, teacherData.id)) {
								  if (teacherData.id==searchId){
								  		
								  		found = true;
								  		
								  		cout<<"TEACHER FOUND !"<<endl;
									  	cout<<"ID: "<<teacherData.id<<endl;
										
										// gets next line
										getline(MyReadFile,teacherData.name);
										cout<<"Name: "<<teacherData.name<<endl;
										
										getline(MyReadFile,teacherData.subject);
										cout<<"Subject: "<<teacherData.subject<<endl;
										
										getline(MyReadFile,teacherData.className);
										cout<<"Class: "<<teacherData.className<<endl;
										
								  }
								  
								  
								}
								
								if (found==false) cout<<"NO RECORD FOUND !"<<endl<<endl;
								
								cout<<"Try again? Y for yes, others for no ";
								cin>>flag;
								
								system("cls");
									
								if (flag=="Y"){
									continue;
								}else{
									break;
									}
							}while(1);
							
							continue;
							
						case 0:
							
							break;
							
						default:
							cout<<"\nPLEASE ENTER VALID INPUT!\n\n";
							continue;
					}
					
					
					break;
				}
				
				continue;
				
			case 0:

				break;
	

			default:

				cout<<"\nPLEASE ENTER VALID INPUT!\n\n";
				continue;

		}
		

		break;

	}

	return 0;
}
