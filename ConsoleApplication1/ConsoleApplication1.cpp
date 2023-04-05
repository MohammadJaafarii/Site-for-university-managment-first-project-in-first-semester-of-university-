#include <iostream> 

#include <math.h>

#include <string>

#include <time.h>

#include <chrono>
#include <ctime>

using namespace std;

void login_modir_d();
void main_menu();
void daneshjoo();
void ostad();
void modir_kol();
void login_d();
void vorood_d();
void login_modir_o();
void sort_o();
void natije_emtehan();

FILE* sabtenam;

FILE* soalat;

FILE* shomaresh_natije_e;

FILE* sabtenam_o;

FILE* shomaresh_o;

FILE* shomaresh_d;

FILE* time_e;

FILE* tedad_emtehan;

FILE* Natije_E;

int shomaresh_sd;

//for exam's time

struct exam_time {

	int code_e;

	int time_e;

	int date_e;

	int h_e;

	int m_e;

	int tedad_soalat_emtehan;

};

// for username password
struct userpas {



	char username[100];

	char password[100];
};
struct natije {

	int code_en;

	char username_n[100];

	char password_n[100];

	float score;
};
void ekhtiarat_d(userpas);

void ekhtiarat_o(userpas);

void tashkilazmoon_o(userpas);

void azmoon_real(userpas, exam_time, int, int);


//for exam
struct question {

	char question[1000];

	char a[1000];

	char b[1000];

	char c[1000];

	char d[1000];

	char answer;

};

int main()
{
	main_menu();

	return 0;
}
void main_menu()
{
	system("cls");

	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << "\t MENU: " << endl;

	cout << "\t <D> : Daneshjoo" << endl;

	cout << "\t <O> : Ostad " << endl;

	cout << "\t <M> : Modir kol" << endl;

	cout << "\t <E> : EXIT" << endl;

	cout << endl;

	cout << "\t Please Choose Your Role: ";

	char role;

	cin >> role;
	if (role == 'D' || role == 'd') {

		daneshjoo();
	}
	if (role == 'O' || role == 'o') {

		ostad();
	}
	if (role == 'M' || role == 'm') {

		modir_kol();
	}

	if (role == 'E' || role == 'e') {

		system("cls");

		cout << "                                    " << "____________________Thanks for using IU system (By Mohammad Jafari) ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);

	}

}
void daneshjoo()
{
	system("cls");

	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> daneshjoo ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << "\t MENU:" << endl;

	cout << "\t <L> : Sign Up " << endl;

	cout << "\t <S> : Sign In " << endl;

	cout << "\t <E> : EXIT" << endl;

	cout << endl;

	cout << "\t Enter Your Choice: ";

	char choice_d;

	cin >> choice_d;

	if (choice_d == 'L' || choice_d == 'l') {


		login_d();

	}

	if (choice_d == 'S' || choice_d == 's') {

		vorood_d();


	}



	if (choice_d == 'E' || choice_d == 'e') {

		system("cls");

		cout << "                                    " << "____________________Thanks for using IU system (By Mohammad Jafari) ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);
	}

}
void ostad()
{
	system("cls");

	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Ostad ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	bool checkbo = true;

	int i = 0;

	int emtehani1;

	userpas o;

	fopen_s(&shomaresh_o, "shomaresh_o.dat", "rb");


	if (!shomaresh_o) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	while (!feof(shomaresh_o)) {

		fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	}

	fclose(shomaresh_o);

	userpas* check_o = new userpas[emtehani1];

	userpas ko;

	cout << endl;

	cout << "\t Username: ";

	cin.ignore();

	fgets(o.username, 100, stdin);

	cout << endl << "\t Password: ";


	fgets(o.password, 100, stdin);

	cout << endl;

	fopen_s(&sabtenam_o, "sabtenam_o.dat", "rb");

	if (!sabtenam_o) {

		cout << "\t File wasnt found";

		exit(0);

	}

	fread(&ko, sizeof(userpas), 1, sabtenam_o);



	while (!feof(sabtenam_o)) {


		check_o[i] = ko;

		i++;

		fread(&ko, sizeof(userpas), 1, sabtenam_o);


	}

	fclose(sabtenam_o);

	char ezafe;

	for (i = 0; i < emtehani1; i++) {


		if (strcmp(check_o[i].username, o.username) == 0 && strcmp(check_o[i].password, o.password) == 0) {

			checkbo = false;


			break;

		}
	}
	while (checkbo) {

		cout << endl;

		cout << "\t Wrong Username or Password Please Try Again " << endl;

		cout << endl;

		cout << "\t Username: ";

		cout << "\t ( for going to main menu Please write 'menu' )  ";


		fgets(o.username, 100, stdin);

		if (strcmp(o.username, "menu\n") == 0) {

			cout << endl;

			cout << "\t Press T for TAID: ";

			cin >> ezafe;

			main_menu();

		}




		cout << endl << "\t Password: ";


		fgets(o.password, 100, stdin);

		cout << endl;

		for (i = 0; i < emtehani1; i++) {

			if (strcmp(check_o[i].username, o.username) == 0 && strcmp(check_o[i].password, o.password) == 0) {

				checkbo = false;

				break;

			}
		}
	}
	if (checkbo == false) {



		cout << "\t \t \t********************************************" << endl;

		if (o.username[0] >= 97) {

			o.username[0] = o.username[0] - 32;
		}

		cout << " \t   \t \t \t         Hi " << o.username << endl << endl;

		cout << "   \t \t   \t    Welcome to ISFAHAN UNIVERSITY System " << endl;

		cout << "\t\t \t********************************************" << endl << endl << endl;

		delete[]check_o;

		cout << "\t PRESS ENTER TO CONTINUE: ";

		cin.ignore();



		ekhtiarat_o(o);



	}




}
void modir_kol()
{
	system("cls");

	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << "\t User name: ";

	char U[9];

	cin >> U;

	cout << endl << "\t Password: ";

	char P[9];

	cin >> P;

	while (strcmp(P, "123456") != 0 || strcmp(U, "isfahanu") != 0) {

		cout << endl;

		cout << "please Enter right password and usermname " << endl;

		cout << endl;

		cout << "\t User name: ";

		cin >> U;

		if (strcmp(U, "menu") == 0)main_menu();

		cout << endl << "\t Password: ";

		cin >> P;

		if (strcmp(P, "123456") == 0 && strcmp(U, "isfahanu") == 0) break;

	}
	system("cls");

	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << "\t MENU" << endl;

	cout << "\t <O> : Ostad" << endl;

	cout << "\t <D> : Daneshjoo" << endl << endl;

	cout << "\t YOUR CHOICE: ";

	char choice_modir;

	cin >> choice_modir;

	if (choice_modir == 'O' || choice_modir == 'o') {
		system("cls");

		cout << "                                        " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Ostad ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t MENU" << endl;

		cout << "\t <L> : LOGIN" << endl;

		cout << "\t <A> : Asami asatid " << endl;

		cout << "\t <T> : Azmoonhaye tashkil shode" << endl << endl;

		cout << "\t YOUR CHOICE: ";

		char modirkol_ostad;

		cin >> modirkol_ostad;

		if (modirkol_ostad == 'L' || modirkol_ostad == 'l') {

			login_modir_o();

		}

		if (modirkol_ostad == 'A' || modirkol_ostad == 'a') {

			system("cls");

			cout << "                                        " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Ostad >> Asami ___________________" << endl;

			cout << endl;

			cout << "************************************************************************************************************************************************************************" << endl;

			sort_o();


		}

		if (modirkol_ostad == 'T' || modirkol_ostad == 't') {

			system("cls");

			cout << "                                        " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Ostad >> Azmoonha ___________________" << endl;

			cout << endl;

			cout << "************************************************************************************************************************************************************************" << endl;

			int shomaresh_tashkil_exam = 0;

			exam_time a;

			fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

			if (!tedad_emtehan) {

				cout << "File wasn't found";

				exit(0);
			}

			fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

			fclose(tedad_emtehan);

			exam_time* asami_eo = new exam_time[shomaresh_tashkil_exam];

			int ios = 0;

			fopen_s(&time_e, "time_e.dat", "rb");

			if (!time_e) {

				cout << "File wasn't found";

				exit(0);
			}

			fread(&a, sizeof(exam_time), 1, time_e);

			while (!feof(time_e)) {

				asami_eo[ios] = a;

				ios += 1;

				fread(&a, sizeof(exam_time), 1, time_e);

			}

			fclose(time_e);

			cout << endl;

			cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;


			cout << "\t\t\t\t\t\t Exam code: " << "                           \t \t " << "Exam time: " << "                           \t \t " << "Exam date" << endl << endl;

			for (ios = 0; ios < shomaresh_tashkil_exam; ios++) {

				cout << "\t\t\t\t                 " << asami_eo[ios].code_e << "                            \t \t " << asami_eo[ios].time_e << "                                \t \t " << asami_eo[ios].date_e << endl << endl;

			}
			cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;

			delete[]asami_eo;

			cout << endl << "\t Press ENTER to continue: " << endl;

			cin.ignore();

			cin.ignore();

			modir_kol();



		}

	}
	if (choice_modir == 'D' || choice_modir == 'd') {

		system("cls");

		cout << "                                        " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Daneshjoo ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t MENU" << endl;

		cout << "\t <L> : LOGIN" << endl;

		cout << "\t <A> : Asami Daneshjooyan " << endl;

		cout << "\t <N> Natayej Azmoonha" << endl << endl;

		cout << "\t YOUR CHOIC: ";

		char modircol_d;

		cin >> modircol_d;

		if (modircol_d == 'L' || modircol_d == 'l') {

			system("cls");

			cout << "                                  " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Daneshjoo >> LOGIN daneshjoo ___________________" << endl;

			cout << endl;

			cout << "************************************************************************************************************************************************************************" << endl;

			login_modir_d();

		}

		if (modircol_d == 'A' || modircol_d == 'a') {

			system("cls");

			cout << "                                    " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Daneshjoo >> Asami ___________________" << endl;

			cout << endl;

			cout << "************************************************************************************************************************************************************************" << endl;

			int i = 0;

			int emtehani1 = 0;

			userpas o;

			fopen_s(&shomaresh_d, "shomaresh.dat", "a+b");


			if (!shomaresh_d) {

				cout << "\t File wasnt found ";

				exit(0);
			}

			fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_d);

			while (!feof(shomaresh_d)) {

				fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_d);

			}

			fclose(shomaresh_d);

			userpas* check_o = new userpas[emtehani1];

			userpas ko;

			if (emtehani1 != 0) {



				fopen_s(&sabtenam, "sabtenam.dat", "rb");

				if (!sabtenam) {

					cout << "\t File wasnt found";

					exit(0);

				}

				fread(&ko, sizeof(userpas), 1, sabtenam);



				while (!feof(sabtenam)) {


					check_o[i] = ko;

					i++;

					fread(&ko, sizeof(userpas), 1, sabtenam);


				}

				fclose(sabtenam);

			}

			int j;

			userpas temp;

			for (i = 0; i < emtehani1 - 1; i++) {

				for (j = 0; j < emtehani1 - 1 - i; j++) {

					if (strcmp(check_o[j].username, check_o[j + 1].username) > 0) {

						temp = check_o[j];

						check_o[j] = check_o[j + 1];

						check_o[j + 1] = temp;
					}
				}

			}

			cout << endl;

			cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

			cout << "\t\t\t\t\t\t\t\t\t Student's name: " << endl << endl;

			for (i = 0; i < emtehani1; i++) {

				cout << "\t\t\t\t\t\t\t\t\t " << check_o[i].username << endl << endl;


			}

			cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

			delete[]check_o;

			cout << endl << "\t Press ENTER for continue: ";

			cin.ignore();

			cin.ignore();

			modir_kol();



		}

		if (modircol_d == 'N' || modircol_d == 'n') {

			system("cls");


			cout << "                                    " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Daneshjoo >>Natayej ___________________" << endl;

			cout << endl;

			cout << "************************************************************************************************************************************************************************" << endl;

			natije_emtehan();
		}


	}



}
// sabtename daneshjoo
void login_d()
{


	system("cls");

	cout << "                                       " << "____________________Welcome to ISFAHAN UNIVERSITY System >> daneshjoo >> LOGIN ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	userpas Daneshjoo;

	bool checknotekrari = false;

	userpas k;

	int i = 0;

	int notekrari = 0;

	fopen_s(&shomaresh_d, "shomaresh.dat", "a+b");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&notekrari, sizeof(int), 1, shomaresh_d);

	while (!feof(shomaresh_d)) {

		fread(&notekrari, sizeof(int), 1, shomaresh_d);

	}

	fclose(shomaresh_d);

	userpas* check_d = new userpas[notekrari];

	if (notekrari != 0) {

		fopen_s(&sabtenam, "sabtenam.dat", "rb");

		if (!sabtenam) {

			cout << "\t File wasnt found";

			exit(0);

		}

		fread(&k, sizeof(userpas), 1, sabtenam);



		while (!feof(sabtenam)) {


			check_d[i] = k;

			i++;

			fread(&k, sizeof(userpas), 1, sabtenam);


		}

		fclose(sabtenam);

	}


	int emtehani = 0;

	fopen_s(&sabtenam, "sabtenam.dat", "ab");

	if (!sabtenam) {

		cout << "\t File wasnt found";

		exit(0);
	}
	cout << "\t Your Username: ";

	cin.ignore();

	fgets(Daneshjoo.username, 100, stdin);

	cout << endl << "\t Your Password: ";


	fgets(Daneshjoo.password, 100, stdin);

	for (i = 0; i < notekrari; i++) {

		if (strcmp(check_d[i].username, Daneshjoo.username) == 0 && strcmp(check_d[i].password, Daneshjoo.password) == 0) {

			checknotekrari = true;

			break;
		}

	}

	while (checknotekrari) {

		checknotekrari = false;

		cout << endl;

		cout << "\t Please choose another username and password " << endl << endl;

		cout << "\t Your Username: (type menu for going to main menu) ";

		fgets(Daneshjoo.username, 100, stdin);

		if (strcmp(Daneshjoo.username, "menu\n") == 0) {

			fclose(sabtenam);

			main_menu();
		}

		cout << endl << "\t Your Password: ";

		fgets(Daneshjoo.password, 100, stdin);

		for (i = 0; i < notekrari; i++) {

			if (strcmp(check_d[i].username, Daneshjoo.username) == 0 && strcmp(check_d[i].password, Daneshjoo.password) == 0) {

				checknotekrari = true;

				break;
			}

		}


	}

	fwrite(&Daneshjoo, sizeof(Daneshjoo), 1, sabtenam);

	fclose(sabtenam);


	if (Daneshjoo.username[0] >= 97) {

		Daneshjoo.username[0] = Daneshjoo.username[0] - 32;
	}
	cout << "                                                        *******************************************************" << endl;

	cout << "                                                                     " << "\t Dear " << Daneshjoo.username << endl;

	cout << "                                                                     " << "\t You login seccessfully " << endl;

	cout << "                                                        *******************************************************" << endl;

	cout << endl << endl;

	fopen_s(&shomaresh_d, "shomaresh.dat", "ab");

	fclose(shomaresh_d);


	fopen_s(&shomaresh_d, "shomaresh.dat", "rb");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	while (!feof(shomaresh_d)) {

		fread(&emtehani, sizeof(emtehani), 1, shomaresh_d);

	}


	fclose(shomaresh_d);

	emtehani += 1;


	// dynamic tedad daneshjooyan 

	fopen_s(&shomaresh_d, "shomaresh.dat", "r+b");

	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fwrite(&emtehani, sizeof(emtehani), 1, shomaresh_d);

	fclose(shomaresh_d);

	cout << "\t <C> : continue " << endl;

	cout << "\t <E> : EXIT" << endl << endl;

	cout << "\t Your choice: ";

	char login_d;

	cin >> login_d;

	if (login_d == 'E' || login_d == 'e') {

		exit(0);
	}

	if (login_d == 'C' || login_d == 'c') {



		if (Daneshjoo.username[0] >= 97) {

			Daneshjoo.username[0] = Daneshjoo.username[0] - 32;
		}
		cout << "\t " << Daneshjoo.username << endl;

		delete[]check_d;

		ekhtiarat_d(Daneshjoo);
	}

}
void vorood_d() {

	system("cls");

	cout << "                                      " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> vorood ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;
	cout << endl;

	bool check = true;

	int i = 0;

	int emtehani1;

	userpas d;

	fopen_s(&shomaresh_d, "shomaresh.dat", "rb");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_d);

	while (!feof(shomaresh_d)) {

		fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_d);

	}

	fclose(shomaresh_d);

	userpas* check_d = new userpas[emtehani1];

	userpas k;

	cout << endl;

	cout << "\t Username: ";

	cin.ignore();

	fgets(d.username, 100, stdin);

	cout << endl << "\t Password: ";


	fgets(d.password, 100, stdin);

	cout << endl;

	fopen_s(&sabtenam, "sabtenam.dat", "rb");

	if (!sabtenam) {

		cout << "\t File wasnt found";

		exit(0);

	}

	fread(&k, sizeof(userpas), 1, sabtenam);



	while (!feof(sabtenam)) {


		check_d[i] = k;

		i++;

		fread(&k, sizeof(userpas), 1, sabtenam);


	}

	fclose(sabtenam);

	char ezafe;

	for (i = 0; i < emtehani1; i++) {

		if (strcmp(check_d[i].username, d.username) == 0 && strcmp(check_d[i].password, d.password) == 0) {

			check = false;


			break;

		}
	}
	while (check) {

		cout << endl;

		cout << "\t Wrong Username or Password Please Try Again " << endl;

		cout << endl;

		cout << "\t Username: ";

		cout << "\t ( for going to menu Please write 'menu' )  ";


		fgets(d.username, 100, stdin);

		if (strcmp(d.username, "menu\n") == 0) {

			cout << endl;

			cout << "\t Press T for TAID: ";

			cin >> ezafe;

			daneshjoo();

		}




		cout << endl << "\t Password: ";


		fgets(d.password, 100, stdin);

		cout << endl;

		for (i = 0; i < emtehani1; i++) {

			if (strcmp(check_d[i].username, d.username) == 0 && strcmp(check_d[i].password, d.password) == 0) {

				check = false;

				break;

			}
		}
	}
	if (check == false) {



		cout << "\t \t \t********************************************" << endl;


		if (d.username[0] >= 97) {

			d.username[0] = d.username[0] - 32;
		}

		cout << " \t   \t \t \t         Hi " << d.username << endl << endl;

		cout << "   \t \t   \t    Welcome to ISFAHAN UNIVERSITY System " << endl;

		cout << "\t\t \t********************************************" << endl << endl << endl;

		delete[]check_d;

		cout << "\t PRESS ENTER TO CONTINUE: ";

		cin.ignore();





		ekhtiarat_d(d);
	}


}

void ekhtiarat_d(userpas hello_d)
{
	system("cls");

	cout << "                                  " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> Dashbord ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;
	cout << endl;

	cout << "\t" << hello_d.username << endl;

	cout << "\t MENU" << endl;

	cout << "\t <L> : List Azmoonha" << endl;

	cout << "\t <V> : Vaziat Azmonnha" << endl;

	cout << "\t <N> : Natije azmoon " << endl;

	cout << "\t <S> : LOGOUT" << endl;

	cout << "\t <E> : EXIT" << endl << endl;

	char choice_ekhtiarat_d;

	cout << "\t YOUR CHOICE: ";


	cin >> choice_ekhtiarat_d;


	if (choice_ekhtiarat_d == 'L' || choice_ekhtiarat_d == 'l') {


		system("cls");


		cout << "                           " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> Dahbord >> List azmoonha ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		int shomaresh_tashkil_exam = 0;

		exam_time a;

		fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

		if (!tedad_emtehan) {

			cout << "File wasn't found";

			exit(0);

		}

		fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

		fclose(tedad_emtehan);

		exam_time* asami_eo = new exam_time[shomaresh_tashkil_exam];

		int ios = 0;

		fopen_s(&time_e, "time_e.dat", "rb");

		if (!time_e) {

			cout << "File wasn't found";

			exit(0);
		}

		fread(&a, sizeof(exam_time), 1, time_e);

		while (!feof(time_e)) {

			asami_eo[ios] = a;

			ios += 1;

			fread(&a, sizeof(exam_time), 1, time_e);

		}

		fclose(time_e);

		cout << endl;

		cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;

		cout << "\t\t\t\t\t\t Exam code: " << "                           \t \t " << "Exam time: " << "                           \t \t " << "Exam date" << endl << endl;

		for (ios = 0; ios < shomaresh_tashkil_exam; ios++) {

			cout << "\t\t\t\t                 " << asami_eo[ios].code_e << "                            \t \t " << asami_eo[ios].time_e << "                                \t \t " << asami_eo[ios].date_e << endl << endl;

		}
		cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;

		delete[]asami_eo;

		cout << endl << "\t Press ENTER to continue: " << endl;

		cin.ignore();

		cin.ignore();

		ekhtiarat_d(hello_d);

	}

	if (choice_ekhtiarat_d == 'V' || choice_ekhtiarat_d == 'v') {

		system("cls");


		cout << "                           " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> Dahbord >> vasiat azmoonha ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		int w, tedad_den = 0;

		int j = 0;

		int shomaresh_tashkil_exam = 0;

		fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

		if (!tedad_emtehan) {

			cout << "File wasn't found";

			exit(0);
		}

		fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

		fclose(tedad_emtehan);

		exam_time abc;

		exam_time* a = new exam_time[shomaresh_tashkil_exam];

		fopen_s(&time_e, "time_e.dat", "rb");

		if (!time_e) {

			cout << "File wasn't found";

			exit(0);
		}

		fread(&abc, sizeof(exam_time), 1, time_e);

		while (!feof(time_e)) {

			a[j] = abc;

			j++;

			fread(&abc, sizeof(exam_time), 1, time_e);
		}
		fclose(time_e);

		int check_ec;

		cout << "\t Please type the Exam code: ";

		cin >> check_ec;

		cout << endl;

		for (j = 0; j < shomaresh_tashkil_exam; j++) {

			if (a[j].code_e == check_ec) {

				break;
			}

		}

		time_t now;

		struct tm date;

		double minute, hour, second = 0;

		now = time(NULL);

		localtime_s(&date, &now);

		hour = date.tm_hour + 1;

		minute = (60 - date.tm_min) * 60;



		if (a[j].date_e == 0 && a[j].h_e < 24 && hour - 1 != a[j].h_e) {

			hour = (a[j].h_e - hour) * 3600;

			minute = (minute + a[j].m_e) * 60;

			second = minute + hour;

		}
		else if (a[j].date_e == 0 && a[j].h_e < 24 && hour - 1 == a[j].h_e) {

			minute = a[j].m_e - date.tm_min;

			second = minute * 60;
		}

		else {

			a[j].date_e = (a[j].date_e - 1) * 3600 * 24;

			hour = (24 - hour) * 3600;

			a[j].h_e = a[j].h_e * 3600;

			a[j].m_e = a[j].m_e * 60;

			second = a[j].m_e + a[j].h_e + hour + a[j].date_e + minute;

		}
		for (w = 0; w < j; w++) {

			tedad_den += a[w].tedad_soalat_emtehan;
		}
		exam_time c;

		c = a[j];

		int time_edmc = a[j].time_e;

		delete[]a;

		if (second <= -time_edmc * 60) {

			cout << "\t Azmoon Payan yafte " << endl;

			cout << endl << endl << "\t Press ENTER to continue: ";

			cin.ignore();

			cin.ignore();


			ekhtiarat_d(hello_d);
		}
		else	if (second <= 0) {

			cout << "\t Azmoon dar hal bargozari" << endl;

			cout << endl << endl << "\t For entrance to Exam Press Enter";

			cin.ignore();

			cin.ignore();

			azmoon_real(hello_d, c, tedad_den, j);

		}

		else if (second > 0) {

			cout << "\t Zaman bargozari fara nareside " << endl;

			cout << endl << endl << "\t Press ENTER to continue: ";

			cin.ignore();

			cin.ignore();


			ekhtiarat_d(hello_d);

		}
	}

	if (choice_ekhtiarat_d == 'N' || choice_ekhtiarat_d == 'n') {

		int shomaresh_e = 0;

		int i = 0;

		int check_code;

		cout << endl;

		cout << "\t Enter the Exam code: ";

		cin >> check_code;

		cout << endl;

		fopen_s(&shomaresh_d, "shomaresh.dat", "rb");

		if (!shomaresh_d) {

			cout << "\t File wasnt found ";

			exit(0);
		}

		fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

		while (!feof(shomaresh_d)) {

			fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

		}

		fclose(shomaresh_d);

		natije n;

		natije* enteghat_natije = new natije[shomaresh_e];

		fopen_s(&Natije_E, "Natije_E.dat", "rb");

		fread(&n, sizeof(natije), 1, Natije_E);

		while (!feof(Natije_E)) {

			if (n.code_en == check_code) {


				enteghat_natije[i] = n;

				i++;

			}

			fread(&n, sizeof(natije), 1, Natije_E);

		}

		fclose(Natije_E);

		natije temp;

		int j;

		// sort bar hasbe nomarat
		for (i = 0; i < shomaresh_e - 1; i++) {

			for (j = 0; j < shomaresh_e - 1 - i; j++) {

				if (enteghat_natije[j].score < enteghat_natije[j + 1].score) {

					temp = enteghat_natije[j];

					enteghat_natije[j] = enteghat_natije[j + 1];

					enteghat_natije[j + 1] = temp;

				}
			}

		}

		for (i = 0; i < shomaresh_e; i++) {

			if (enteghat_natije[i].username_n[0] >= 97) {

				enteghat_natije[i].username_n[0] = enteghat_natije[i].username_n[0] - 32;
			}

			if (strcmp(enteghat_natije[i].username_n, hello_d.username) == 0 && strcmp(enteghat_natije[i].password_n, hello_d.password) == 0) {

				if (i < 3) {
					cout << "\t\t\t\t\t\t Congratulation (:" << endl << endl;

					cout << "\t Your score is: " << enteghat_natije[i].score << endl;
				}
				else {

					cout << "\t Your score is: " << enteghat_natije[i].score << endl;

				}
			}
		}

		cout << endl;

		cout << "\t For continue Press ENTER ";

		cin.ignore();

		cin.ignore();

		delete[]enteghat_natije;

		ekhtiarat_d(hello_d);

	}

	if (choice_ekhtiarat_d == 'S' || choice_ekhtiarat_d == 's') {

		main_menu();

	}

	if (choice_ekhtiarat_d == 'E' || choice_ekhtiarat_d == 'e') {

		system("cls");

		cout << "                                    " << "____________________Thanks for using IU system (By Mohammad Jafari) ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);

	}
}

void login_modir_d()
{
	system("cls");

	cout << "                                " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Daneshjoo >> LOGIN daneshjoo ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	userpas Modirkol_d_l;

	bool checknotekrari = false;

	userpas k;

	int i = 0;

	int notekrari = 0;

	fopen_s(&shomaresh_d, "shomaresh.dat", "a+b");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&notekrari, sizeof(int), 1, shomaresh_d);

	while (!feof(shomaresh_d)) {

		fread(&notekrari, sizeof(int), 1, shomaresh_d);

	}

	fclose(shomaresh_d);

	userpas* check_d = new userpas[notekrari];

	if (notekrari != 0) {

		fopen_s(&sabtenam, "sabtenam.dat", "rb");

		if (!sabtenam) {

			cout << "\t File wasnt found";

			exit(0);

		}

		fread(&k, sizeof(userpas), 1, sabtenam);



		while (!feof(sabtenam)) {


			check_d[i] = k;

			i++;

			fread(&k, sizeof(userpas), 1, sabtenam);


		}

		fclose(sabtenam);

	}

	int emtehani = 0;

	fopen_s(&sabtenam, "sabtenam.dat", "ab");

	if (!sabtenam) {

		cout << "\t File wasnt found";

		exit(0);
	}
	cout << "\t Your Username: ";

	cin.ignore();

	fgets(Modirkol_d_l.username, 100, stdin);

	cout << endl << "\t Your Password: ";


	fgets(Modirkol_d_l.password, 100, stdin);

	for (i = 0; i < notekrari; i++) {

		if (strcmp(check_d[i].username, Modirkol_d_l.username) == 0 && strcmp(check_d[i].password, Modirkol_d_l.password) == 0) {

			checknotekrari = true;

			break;
		}

	}

	while (checknotekrari) {

		checknotekrari = false;

		cout << endl << "\t Please choose another username and password " << endl << endl;

		cout << "\t Your Username: (type menu for going to main menu) ";

		fgets(Modirkol_d_l.username, 100, stdin);

		if (strcmp(Modirkol_d_l.username, "menu\n") == 0) {

			fclose(sabtenam);

			main_menu();
		}

		cout << endl << "\t Your Password: ";

		fgets(Modirkol_d_l.password, 100, stdin);

		for (i = 0; i < notekrari; i++) {

			if (strcmp(check_d[i].username, Modirkol_d_l.username) == 0 && strcmp(check_d[i].password, Modirkol_d_l.password) == 0) {

				checknotekrari = true;

				break;
			}

		}


	}

	fwrite(&Modirkol_d_l, sizeof(Modirkol_d_l), 1, sabtenam);

	fclose(sabtenam);

	delete[]check_d;

	if (Modirkol_d_l.username[0] >= 97) {

		Modirkol_d_l.username[0] = Modirkol_d_l.username[0] - 32;
	}
	cout << "                                                        *******************************************************" << endl;


	cout << "                                                             \t        " << Modirkol_d_l.username << endl;

	cout << "                                                             \t        " << "LOGIN seccessfully" << endl;

	cout << "                                                        *******************************************************" << endl;

	cout << endl << endl;

	fopen_s(&shomaresh_d, "shomaresh.dat", "ab");

	fclose(shomaresh_d);


	fopen_s(&shomaresh_d, "shomaresh.dat", "rb");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	while (!feof(shomaresh_d)) {

		fread(&emtehani, sizeof(emtehani), 1, shomaresh_d);
	}


	fclose(shomaresh_d);

	emtehani += 1;



	// dynamic tedad daneshjooyan 

	fopen_s(&shomaresh_d, "shomaresh.dat", "r+b");

	if (!shomaresh_d) {

		cout << "\t File wasnt found ";
		exit(0);
	}

	fwrite(&emtehani, sizeof(emtehani), 1, shomaresh_d);

	fclose(shomaresh_d);

	cout << "\t <M> : MENU " << endl;

	cout << "\t <E> : EXIT " << endl << endl;

	cout << "\t YOUR CHOICE: ";
	char modir_login_d;

	cin >> modir_login_d;

	if (modir_login_d == 'M' || modir_login_d == 'm') {

		modir_kol();
	}

	if (modir_login_d == 'E' || modir_login_d == 'e') {

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);


	}



}
void login_modir_o()
{

	system("cls");

	cout << "                                 " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Modir kol >> Ostad >> LOGIN Ostad ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;


	userpas M_Ostad;

	bool checkbo = false;

	int i = 0;

	int emtehani1 = 0;

	userpas o;

	fopen_s(&shomaresh_o, "shomaresh_o.dat", "a+b");


	if (!shomaresh_o) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	while (!feof(shomaresh_o)) {

		fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	}

	fclose(shomaresh_o);

	userpas* check_o = new userpas[emtehani1];

	userpas ko;

	if (emtehani1 != 0) {



		fopen_s(&sabtenam_o, "sabtenam_o.dat", "rb");

		if (!sabtenam_o) {

			cout << "\t File wasnt found";

			exit(0);

		}

		fread(&ko, sizeof(userpas), 1, sabtenam_o);



		while (!feof(sabtenam_o)) {


			check_o[i] = ko;

			i++;

			fread(&ko, sizeof(userpas), 1, sabtenam_o);


		}

		fclose(sabtenam_o);

	}



	int emtehani = 0;

	fopen_s(&sabtenam_o, "sabtenam_o.dat", "ab");

	if (!sabtenam_o) {

		cout << "\t File wasnt found";

		exit(0);
	}
	cout << "\t Your Username: ";

	cin.ignore();

	fgets(M_Ostad.username, 100, stdin);

	cout << endl << "\t Your Password: ";


	fgets(M_Ostad.password, 100, stdin);

	for (i = 0; i < emtehani1; i++) {

		if (strcmp(check_o[i].username, M_Ostad.username) == 0 && strcmp(check_o[i].password, M_Ostad.password) == 0) {

			checkbo = true;

			break;
		}

	}

	while (checkbo) {

		checkbo = false;

		cout << endl << "\t Please choose another username and password " << endl << endl;

		cout << "\t Your Username: (type menu for going to main menu) ";

		fgets(M_Ostad.username, 100, stdin);

		if (strcmp(M_Ostad.username, "menu\n") == 0) {

			fclose(sabtenam_o);

			main_menu();
		}

		cout << endl << "\t Your Password: ";

		fgets(M_Ostad.password, 100, stdin);

		for (i = 0; i < emtehani1; i++) {

			if (strcmp(check_o[i].username, M_Ostad.username) == 0 && strcmp(check_o[i].password, M_Ostad.password) == 0) {

				checkbo = true;

				break;
			}

		}


	}



	fwrite(&M_Ostad, sizeof(M_Ostad), 1, sabtenam_o);

	fclose(sabtenam_o);

	delete[]check_o;

	if (M_Ostad.username[0] >= 97) {

		M_Ostad.username[0] = M_Ostad.username[0] - 32;
	}

	cout << "                                                        *******************************************************" << endl;


	cout << "                                                             \t        " << M_Ostad.username << endl;

	cout << "                                                             \t        " << "LOGIN seccessfully" << endl;

	cout << "                                                        *******************************************************" << endl;

	cout << endl << endl;

	fopen_s(&shomaresh_o, "shomaresh_o.dat", "ab");

	fclose(shomaresh_o);


	fopen_s(&shomaresh_o, "shomaresh_o.dat", "rb");


	if (!shomaresh_o) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	while (!feof(shomaresh_o)) {

		fread(&emtehani, sizeof(emtehani), 1, shomaresh_o);
	}

	fclose(shomaresh_o);

	emtehani += 1;

	// dynamic tedad daneshjooyan 

	fopen_s(&shomaresh_o, "shomaresh_o.dat", "r+b");

	if (!shomaresh_o) {

		cout << "\t File wasnt found ";
		exit(0);
	}

	fwrite(&emtehani, sizeof(emtehani), 1, shomaresh_o);

	fclose(shomaresh_o);

	cout << "\t <M> : MENU " << endl;

	cout << "\t <E> : EXIT " << endl << endl;

	cout << "\t YOUR CHOICE: ";

	char modir_login_o;

	cin >> modir_login_o;

	if (modir_login_o == 'M' || modir_login_o == 'm') {

		modir_kol();
	}

	if (modir_login_o == 'E' || modir_login_o == 'e') {

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);


	}



}

void ekhtiarat_o(userpas hello_o)
{
	system("cls");


	cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> ostad >> Dahbord ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;
	cout << endl;
	cout << "\t " << hello_o.username << endl;

	cout << "\t MENU" << endl;

	cout << "\t <L> : List Azmoonha " << endl;

	cout << "\t <T> : Tashkil Azmonn " << endl;

	cout << "\t <N> : Natayej azmoon" << endl;

	cout << "\t <S> : LOGOUT" << endl;

	cout << "\t <E> : EXIT" << endl << endl;

	char choice_ekhtiarat_o;

	cout << "\t YOUR CHOICE: ";

	cin >> choice_ekhtiarat_o;


	if (choice_ekhtiarat_o == 'L' || choice_ekhtiarat_o == 'l') {

		system("cls");


		cout << "                               " << "____________________Welcome to ISFAHAN UNIVERSITY System >> ostad >> Dahbord >> List Azmoonha ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		int shomaresh_tashkil_exam = 0;

		exam_time a;

		fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

		if (!tedad_emtehan) {

			cout << "File wasn't found";

			exit(0);
		}

		fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

		fclose(tedad_emtehan);

		exam_time* asami_eo = new exam_time[shomaresh_tashkil_exam];

		int ios = 0;

		fopen_s(&time_e, "time_e.dat", "rb");

		if (!time_e) {

			cout << "File wasn't found";

			exit(0);
		}

		fread(&a, sizeof(exam_time), 1, time_e);

		while (!feof(time_e)) {

			asami_eo[ios] = a;

			ios += 1;

			fread(&a, sizeof(exam_time), 1, time_e);

		}

		fclose(time_e);

		cout << endl;

		cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;


		cout << "\t\t\t\t\t\t Exam code: " << "                           \t \t " << "Exam time: " << "                           \t \t " << "Exam date" << endl << endl;

		for (ios = 0; ios < shomaresh_tashkil_exam; ios++) {

			cout << "\t\t\t\t                 " << asami_eo[ios].code_e << "                            \t \t " << asami_eo[ios].time_e << "                                \t \t " << asami_eo[ios].date_e << endl << endl;

		}
		cout << "\t" << "             **********************************************************************************************************************************************" << endl << endl;

		delete[]asami_eo;

		cout << endl << "\t Press ENTER to continue: " << endl;

		cin.ignore();

		cin.ignore();

		ekhtiarat_o(hello_o);


	}

	if (choice_ekhtiarat_o == 'T' || choice_ekhtiarat_o == 't') {
		tashkilazmoon_o(hello_o);
	}

	if (choice_ekhtiarat_o == 'N' || choice_ekhtiarat_o == 'n') {

		system("cls");


		cout << "                                     " << "____________________Welcome to ISFAHAN UNIVERSITY System >> ostad >> Dahbord >> Natayej azmoon ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;


		int shomaresh_e = 0;

		int i = 0;

		int check_code;

		cout << "\t Enter the Exam code: ";

		cin >> check_code;

		cout << endl;


		fopen_s(&shomaresh_d, "shomaresh.dat", "rb");


		if (!shomaresh_d) {

			cout << "\t File wasnt found ";

			exit(0);
		}

		fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

		while (!feof(shomaresh_d)) {

			fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

		}

		fclose(shomaresh_d);

		natije n;

		natije* enteghat_natije = new natije[shomaresh_e];

		fopen_s(&Natije_E, "Natije_E.dat", "rb");

		fread(&n, sizeof(natije), 1, Natije_E);

		while (!feof(Natije_E)) {

			if (n.code_en == check_code) {


				enteghat_natije[i] = n;

				i++;

			}

			fread(&n, sizeof(natije), 1, Natije_E);

		}

		fclose(Natije_E);

		natije temp;

		int j;

		// sort bar hasbe nomarat
		for (i = 0; i < shomaresh_e - 1; i++) {

			for (j = 0; j < shomaresh_e - 1 - i; j++) {

				if (enteghat_natije[j].score < enteghat_natije[j + 1].score) {

					temp = enteghat_natije[j];

					enteghat_natije[j] = enteghat_natije[j + 1];

					enteghat_natije[j + 1] = temp;

				}
			}

		}

		cout << endl;



		for (i = 0; i < shomaresh_e; i++) {

			if (i < 3) {


				cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

				cout << "\t\t\t\t\t\t\t\t\t\t " << enteghat_natije[i].username_n << endl;

				cout << "\t\t\t\t\t\t\t\t\t\t " << enteghat_natije[i].score << endl << endl;

				cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl << endl;



			}

			else {

				cout << "\t " << enteghat_natije[i].username_n << endl;

				cout << "\t " << enteghat_natije[i].score << endl << endl;
			}
		}


		delete[]enteghat_natije;

		cout << "\t Press ENTER to continue ";
		cin.ignore();

		cin.ignore();

		ekhtiarat_o(hello_o);



	}

	if (choice_ekhtiarat_o == 'S' || choice_ekhtiarat_o == 's') {

		main_menu();

	}

	if (choice_ekhtiarat_o == 'E' || choice_ekhtiarat_o == 'e') {

		system("cls");

		cout << "                                    " << "____________________Thanks for using IU system (By Mohammad Jafari) ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << "\t Press ENTER to EXIT" << endl;

		cin.ignore();

		cin.ignore();

		exit(0);

	}

}

void sort_o()
{
	int i = 0;

	int emtehani1 = 0;

	userpas o;

	fopen_s(&shomaresh_o, "shomaresh_o.dat", "a+b");


	if (!shomaresh_o) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	while (!feof(shomaresh_o)) {

		fread(&emtehani1, sizeof(emtehani1), 1, shomaresh_o);

	}

	fclose(shomaresh_o);

	userpas* check_o = new userpas[emtehani1];

	userpas ko;

	if (emtehani1 != 0) {



		fopen_s(&sabtenam_o, "sabtenam_o.dat", "rb");

		if (!sabtenam_o) {

			cout << "\t File wasnt found";

			exit(0);

		}

		fread(&ko, sizeof(userpas), 1, sabtenam_o);



		while (!feof(sabtenam_o)) {


			check_o[i] = ko;

			i++;

			fread(&ko, sizeof(userpas), 1, sabtenam_o);


		}

		fclose(sabtenam_o);

	}

	int j;

	userpas temp;

	for (i = 0; i < emtehani1 - 1; i++) {

		for (j = 0; j < emtehani1 - 1 - i; j++) {

			if (strcmp(check_o[j].username, check_o[j + 1].username) > 0) {

				temp = check_o[j];

				check_o[j] = check_o[j + 1];

				check_o[j + 1] = temp;
			}
		}

	}

	cout << endl;

	cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

	cout << "\t\t\t\t\t\t\t\t\t Teacher's name: " << endl << endl;

	for (i = 0; i < emtehani1; i++) {

		cout << "\t\t\t\t\t\t\t\t\t " << check_o[i].username << endl << endl;


	}

	cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

	delete[]check_o;

	cout << "\t For Continue Press ENTER";

	cin.ignore();

	cin.ignore();

	modir_kol();

}

void tashkilazmoon_o(userpas hello_o)
{

	system("cls");


	cout << "                               " << "____________________Welcome to ISFAHAN UNIVERSITY System >> ostad >> Dahbord >> Tashkil azmoon ___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << endl;
	int i;


	exam_time a;


	cout << "\t How many questions your exam has: ";

	cin >> a.tedad_soalat_emtehan;

	cout << endl;

	question soalat_e;


	cin.ignore();

	fopen_s(&soalat, "soalat.dat", "ab");

	for (i = 0; i < a.tedad_soalat_emtehan; i++) {


		cout << "\t Your question: ";

		fgets(soalat_e.question, 1000, stdin);

		cout << endl << "\t Answer a: ";

		fgets(soalat_e.a, 1000, stdin);

		cout << endl << "\t Answer b: ";

		fgets(soalat_e.b, 1000, stdin);

		cout << endl << "\t Answer c: ";

		fgets(soalat_e.c, 1000, stdin);

		cout << endl << "\t Answer d: ";

		fgets(soalat_e.d, 1000, stdin);

		cout << endl << "\t true answer: ";

		cin >> soalat_e.answer;

		cout << endl;

		cin.ignore();


		fwrite(&soalat_e, sizeof(question), 1, soalat);

	}
	fclose(soalat);

	int shomaresh_tashkil_exam = 0;

	fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "a+b");

	if (!tedad_emtehan) {

		cout << "File wasn't found";

		exit(0);
	}

	fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

	fclose(tedad_emtehan);

	fopen_s(&time_e, "time_e.dat", "ab");

	if (!time_e) {

		cout << "File wasn't found";

		exit(0);
	}

	cout << endl << endl << "\t Exam code: ";

	cin >> a.code_e;

	cout << endl << "\t Exam time: ";

	cin >> a.time_e;

	cout << endl << "\t Exam date: ";
	cin >> a.date_e;
	cout << endl << "\t Exam hour: ";
	cin >> a.h_e;
	cout << endl << "\t Exam minue: ";
	cin >> a.m_e;

	fwrite(&a, sizeof(exam_time), 1, time_e);

	fclose(time_e);

	shomaresh_tashkil_exam += 1;

	fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "r+b");

	if (!tedad_emtehan) {

		cout << "File wasn't found";

		exit(0);
	}

	fwrite(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

	fclose(tedad_emtehan);

	cout << endl << endl;

	char e_o;

	shomaresh_tashkil_exam = 0;

	fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

	if (!tedad_emtehan) {

		cout << "File wasn't found";

		exit(0);
	}

	fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

	fclose(tedad_emtehan);


	cout << "\t <D> : Dashbord " << endl << endl;

	cout << "\t <E> : EXIT " << endl << endl;

	cout << "\t Your choice: ";

	cin >> e_o;

	if (e_o == 'D' || e_o == 'd') {


		ekhtiarat_o(hello_o);
	}

	if (e_o == 'E' || e_o == 'e') {

		cout << "\t Press ENTER to EXIT: ";

		cin.ignore();

		cin.ignore();

		exit(0);
	}

}

void azmoon_real(userpas hello_d, exam_time c, int tedad_den, int j)

{
	system("cls");


	cout << "                       " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> Dashbord >> EXAM ___________________" << endl;

	cout << endl;

	cout << "+ * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ %  " << endl;

	cout << endl;

	int i = 0;

	int a, count;

	int shomaresh_tashkil_exam = 0;

	fopen_s(&tedad_emtehan, "tedad_emtehan.dat", "rb");

	if (!tedad_emtehan) {

		cout << "File wasn't found";

		exit(0);
	}

	fread(&shomaresh_tashkil_exam, sizeof(int), 1, tedad_emtehan);

	fclose(tedad_emtehan);

	a = c.tedad_soalat_emtehan;

	question entefhal_soal;

	question* soalat_e = new question[a];

	fopen_s(&soalat, "soalat.dat", "rb");

	count = 0;

	fseek(soalat, tedad_den * sizeof(question), SEEK_SET);

	while (count != a) {

		fread(&entefhal_soal, sizeof(question), 1, soalat);

		soalat_e[i] = entefhal_soal;

		i++;

		count++;

	}

	fclose(soalat);

	char answer_ed;

	float score_ed = 0, score_bedonnomremanfi = 0;

	float nazade_e = 0;

	float wrong_ed = 0;

	int shomaresh_e = 0;
	i = 0;
	std::cout << "begin\n";

	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()

		+ std::chrono::minutes(c.time_e);

	while (std::chrono::steady_clock::now() < tend && i < a)
	{

		system("cls");

		cout << "                       " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Daneshjoo >> Dashbord >> EXAM ___________________" << endl;

		cout << endl;

		cout << "+ * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ % + * - / ^ %  " << endl;

		cout << endl;

		cout << "\t Question " << i + 1 << " : " << soalat_e[i].question << endl << endl;

		cout << "\t A: " << soalat_e[i].a << endl;

		cout << "\t B: " << soalat_e[i].b << endl;

		cout << "\t C: " << soalat_e[i].c << endl;

		cout << "\t D: " << soalat_e[i].d << endl;

		cout << endl << "\t Your answer (<N> : Nazade) : ";

		cin >> answer_ed;

		cout << endl;

		if (answer_ed == soalat_e[i].answer) {

			score_ed += 1;
		}
		else if (answer_ed == 'n' || answer_ed == 'N') {

			nazade_e += 1;
		}

		else {

			wrong_ed += 1;
		}

		i++;




	}
	std::cout << "end\n";

	float kol_soalat_enteghal = 0;

	kol_soalat_enteghal = a;

	nazade_e = a - (nazade_e + wrong_ed + score_ed) + nazade_e;

	float score_nomremanfi = 0;

	score_nomremanfi = (3 * score_ed);

	score_nomremanfi = (score_nomremanfi - wrong_ed);

	score_nomremanfi = score_nomremanfi / (3 * kol_soalat_enteghal);

	score_nomremanfi = score_nomremanfi * 100;

	score_bedonnomremanfi = (score_ed / kol_soalat_enteghal) * 100;

	cout << "\t Nomre ba nomre manfi: " << score_nomremanfi << endl << endl;

	cout << "\t Nomre bedone nomre manfi: " << score_bedonnomremanfi << endl;

	int code_emtehan = c.code_e;






	fopen_s(&Natije_E, "Natije_E.dat", "ab");

	fwrite(&code_emtehan, sizeof(int), 1, Natije_E);

	fwrite(&hello_d, sizeof(userpas), 1, Natije_E);

	fwrite(&score_bedonnomremanfi, sizeof(float), 1, Natije_E);

	fclose(Natije_E);

	cout << endl << "\t For going to Dashbord Press ENTER ";

	delete[]soalat_e;

	cin.ignore();

	cin.ignore();

	ekhtiarat_d(hello_d);


}
void natije_emtehan()
{
	system("cls");


	cout << "                                     " << "____________________Welcome to ISFAHAN UNIVERSITY System >> ostad >> Dahbord >> Natayej azmoon ___________________" << endl;

	cout << endl;


	cout << "************************************************************************************************************************************************************************" << endl;

	cout << endl;


	int shomaresh_e = 0;

	int i = 0;

	int check_code;

	cout << "\t Enter the Exam code: ";

	cin >> check_code;

	cout << endl;


	fopen_s(&shomaresh_d, "shomaresh.dat", "rb");


	if (!shomaresh_d) {

		cout << "\t File wasnt found ";

		exit(0);
	}

	fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

	while (!feof(shomaresh_d)) {

		fread(&shomaresh_e, sizeof(int), 1, shomaresh_d);

	}

	fclose(shomaresh_d);

	natije n;

	natije* enteghat_natije = new natije[shomaresh_e];

	fopen_s(&Natije_E, "Natije_E.dat", "rb");

	fread(&n, sizeof(natije), 1, Natije_E);

	while (!feof(Natije_E)) {

		if (n.code_en == check_code) {


			enteghat_natije[i] = n;

			i++;

		}

		fread(&n, sizeof(natije), 1, Natije_E);

	}

	fclose(Natije_E);

	natije temp;

	int j;
	// sort bar hasbe nomarat
	for (i = 0; i < shomaresh_e - 1; i++) {

		for (j = 0; j < shomaresh_e - 1 - i; j++) {

			if (enteghat_natije[j].score < enteghat_natije[j + 1].score) {

				temp = enteghat_natije[j];

				enteghat_natije[j] = enteghat_natije[j + 1];

				enteghat_natije[j + 1] = temp;

			}
		}

	}

	cout << endl;



	for (i = 0; i < shomaresh_e; i++) {

		if (i < 3) {


			cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl;

			cout << "\t\t\t\t\t\t\t\t\t\t " << enteghat_natije[i].username_n << endl;

			cout << "\t\t\t\t\t\t\t\t\t\t " << enteghat_natije[i].score << endl << endl;

			cout << "\t\t\t\t\t" << "************************************************************************************" << endl << endl << endl;



		}

		else {
			cout << "\t " << enteghat_natije[i].username_n << endl;

			cout << "\t " << enteghat_natije[i].score << endl << endl;
		}
	}


	delete[]enteghat_natije;

	cout << "\t Press ENTER to continue ";
	cin.ignore();

	cin.ignore();


	modir_kol();





}












