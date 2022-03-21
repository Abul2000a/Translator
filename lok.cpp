#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxRow = 200;
string eng[maxRow] = {};
string arm[maxRow] = {};

void ss(){

    char choice;
    cout << "     =================================="<<endl;
    cout << "       Hello! Welcome to Translator"<<endl;
    
    fstream file;
    file.open("myText.txt");
    std::string candidate ;
  
    std::string username ;
    std::string password ;

	if( file.is_open() )
	{
            std::cout << "-----------------" << std::endl;
            std::cout << " Enter Username"   << std::endl; 
            std::cout << "-----------------" << std::endl;
		std::cin >> username ;
        while( file >> candidate ) 
		      {
			     if( username == candidate){
		    
                      std::cout <<"----------------" << std::endl;
                      std::cout << "Enter password " << std::endl;
                      std::cout <<"----------------" << std::endl;
                      std::cin>> password;
					  system("clear");
                
                    }
                 else if(password == candidate && password!=username){
					
                           std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<std::endl;
                           std::cout << "---------Welcome Admin----------" <<std::endl;
                           std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n"<<std::endl;
						    

                        }
                        while( username!=candidate && password!=candidate){
                               std::cout << "-----invalid Username or Password-----" << std::endl;
                               std::cout<< "---Enter Username---"<<std::endl;
                               std::cin >> username;
                               std::cout << "---Enter Password---"<<std::endl;
                               std::cin >> password;

                            }
                      }            
              }
              
              file.close();
              
              
    }
   

    
void addWord() {
	string ang;
	string armm;
	cin.ignore();
	cout << "Enter English Word >>";
	getline(cin, ang);
	cout << "Enter Armenian Word >>";
	getline(cin, armm);

	for (int i = 0; i < maxRow; i++) {
		if (eng[i] == "\0") {
			eng[i] = ang;
			arm[i] = armm;

			break;
		}
	}

}

void seeAll() {
	system("clear");
	cout << "           W O R D S" << endl;
	cout << "==================================================" << endl;


	int counter = 0;
	cout << " -N.o-  |      English      |       Armenian      " << endl;
	cout << "--------------------------------------------------" << endl;

	for (int i = 0; i < maxRow; i++) {
		if (eng[i] != "\0") {
			counter++;
			cout << "    " << counter << "    " << eng[i] << "                 " << arm[i] << endl;

		}
	}

}

void searchWord(string search) {
	system("clear");
	cout << "                  - W O R D S -" << endl;
	cout << "==================================================" << endl;
	int counter = 0;
	for (int i = 0; i < maxRow; i++) {
		if (eng[i] == search || arm[i] == search) {
			counter++;
			cout << "    " << counter << "    " << eng[i] << "                 " << arm[i] << endl;
			break;
		}
	}



}

void updateWord(string search) {
	string ang;
	string armm;


	int counter = 0;


	for (int i = 0; i < maxRow; i++) {
		if (eng[i] == search || arm[i] == search) {
			counter++;
			cout << "Enter English Word >> ";

			cin >> ang;
			eng[i] = ang;
			cout << "Enter Armenian Word >> ";

			cin >> armm;
			arm[i] = armm;

			cout << "Update Succesfull" << endl;


		}
	}
}

void deleteWord(string search) {
	int counter = 0;
	for (int i = 0; i < maxRow; i++) {
		if (eng[i] == search || arm[i] == search) {
			counter++;
			eng[i] = "";
			arm[i] = "";
			cout << "Succesfully Deleted" << endl;
			break;
		}
	}
}

void saveToFIle()
{
	std::ofstream file("language.txt", std::ios_base::trunc);
	for (int i = 0; i < maxRow; i++)
	{
		if (!eng[i].empty())
		{
			file << eng[i] << " " << arm[i] << std::endl;
            
		}
	}

	file.close();
}

void loadFromFIle()
{
	std::ifstream file("language.txt");
	std::string row;
	std::string engWord, armWord;
	while (file.good())
	{
		file >> engWord >> armWord;
		file.get();

		for (int i = 0; i < maxRow; i++) {
			if (eng[i].empty()) {
				eng[i] = engWord;
				arm[i] = armWord;

				break;
			}
		}
	}
	file.close();
}



int main() {

	loadFromFIle();
	int option;
	string english;
	system("clear");
	label2:
	int chs;
	cout << "======================="<<endl;
	cout << "      H E L L O"<<endl;
	cout << "=======================\n"<<endl;
	cout << "If you are Admin press -1-\n"<<endl;
	cout << "If you are User press  -2-"<<endl;
	cin >> chs;
	system("clear");
	if(chs==2){
		string uu;
		char c;
		cout <<"========================================"<<endl;
	cout << "           Welcome To Translator"<<endl;
	do{
	cout << "Enter Armenian or English Word >> ";

		
		cin.ignore();
		getline(cin,uu);
		searchWord(uu);
		label5:
		cout << "Do You Want to Translate Another Word(Y/n)"<<endl;
		
		cin >> c;
		system("clear");
		
	}
	while(c=='Y');
	if(c=='n'){
		return 0;
		
	}
	if(c!='n' && c!='Y')
	goto label5;
		
		
	}
	else if(chs==1){

	
   ss();
	do {
		cout << "--M E N U--\n";
		cout << "-1-Add Word" << endl;
		cout << "-2-Update Word" << endl;
		cout << "-3-Delete Word" << endl;
		cout << "-4-Search Word" << endl;
		cout << "-5-See All Words" << endl;
		cout << "-6-Exit and Save to text file" << endl;
		cout << "=============================" << endl;

		cout << "-Select Option >> ";
		cin >> option;
		switch (option) {

		case 1:addWord();
			system("clear");
			break;
		case 2:
			cin.ignore();
			cout << "Enter Word You Want to Update >> ";
			getline(cin, english);
			updateWord(english);
			system("clear");
			break;
		case 3:
			cin.ignore();
			cout << "Enter Word You Want to Delete >> ";
			getline(cin, english);
			deleteWord(english);
			system("clear");
			break;
		case 4:
			cin.ignore();
			cout << "Enter Word You Want to Search >> ";
			getline(cin, english);
			searchWord(english);
			break;
		case 5:seeAll();
			break;
		}

	} while (option != 6);
	
	
	saveToFIle();
	}
	else if(chs!=2 && chs!=1){
		goto label2;
	}
	
}
