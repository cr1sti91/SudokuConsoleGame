#include "Sudoku_functions.h"


void clearScreen() {
	//std::cout << "\033[2J\033[H"; // Cursorul este mutat in coltul stang sus
	system("CLS");
}



void efectuarea_copiei(char(&matrice_originala)[nr][nr], char(&matrice_copie)[nr][nr]) {
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			matrice_copie[i][j] = matrice_originala[i][j];
		}
	}
}



void inserare_spatii(char(&matrice)[nr][nr]) {
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			matrice[i][j] = ' ';
		}
	}
}


//FUNCTII DE AFISARE: 


void afisare_rand_cu_cifre_1(size_t i, char(&matrice)[nr][nr]) {

	std::cout << "\t\t\t\t   " << CYAN << i + 1 << GREEN << "  $ " << YELLOW << matrice[i][0] << GREEN << " | " 
			  << YELLOW << matrice[i][1] << GREEN << " | " << YELLOW << matrice[i][2] << GREEN << " $ " << YELLOW << matrice[i][3] <<
		GREEN << " | " << YELLOW << matrice[i][4] << GREEN << " | " << YELLOW << matrice[i][5] << GREEN << " $ " << YELLOW << matrice[i][6]
		<< GREEN << " | " << YELLOW << matrice[i][7] << GREEN << " | " << YELLOW << matrice[i][8] << GREEN << " $ " << RESET << std::endl;
}

void afisare_tabla_1(char(&matrice)[nr][nr]) {

	std::string bucata0{ R"(        1   2   3   4   5   6   7   8   9)" }; 

	std::string bucata1{ R"(      $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)" };

	std::string bucata2{ R"(      $---*---*---$---*---*---$---*---*---$)" };
	std::string bucata3{ R"(      $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)" };

	bucata0.insert(0, 4, '\t');
	bucata1.insert(0, 4, '\t');
	bucata2.insert(0, 4, '\t');
	bucata3.insert(0, 4, '\t');

	std::cout << CYAN << bucata0 << RESET << std::endl;
	std::cout << GREEN << bucata1 << RESET << std::endl;
	afisare_rand_cu_cifre_1(0, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(1, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(2, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_1(3, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(4, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(5, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_1(6, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(7, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_1(8, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
}



void afisare_rand_cu_cifre_2(size_t i, char(&matrice)[nr][nr]) {

	std::cout << "\t\t\t\t   " << CYAN << i + 1 << GREEN << "  # " << YELLOW << matrice[i][0] << GREEN << " | "
		<< YELLOW << matrice[i][1] << GREEN << " | " << YELLOW << matrice[i][2] << GREEN << " # " << YELLOW << matrice[i][3] <<
		GREEN << " | " << YELLOW << matrice[i][4] << GREEN << " | " << YELLOW << matrice[i][5] << GREEN << " # " << YELLOW << matrice[i][6]
		<< GREEN << " | " << YELLOW << matrice[i][7] << GREEN << " | " << YELLOW << matrice[i][8] << GREEN << " # " << RESET << std::endl;
}

void afisare_tabla_2(char(&matrice)[nr][nr]) {

	std::string bucata0{ R"(        1   2   3   4   5   6   7   8   9)" };
	std::string bucata1{ R"(      #####################################)" };
	std::string bucata2{ R"(      #---*---*---#---*---*---#---*---*---#)" };
	std::string bucata3{ R"(      #####################################)" };

	bucata0.insert(0, 4, '\t');
	bucata1.insert(0, 4, '\t');
	bucata2.insert(0, 4, '\t');
	bucata3.insert(0, 4, '\t');

	std::cout << CYAN << bucata0 << RESET << std::endl;
	std::cout << GREEN << bucata1 << RESET << std::endl;
	afisare_rand_cu_cifre_2(0, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(1, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(2, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_2(3, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(4, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(5, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_2(6, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(7, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_2(8, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
}





void afisare_rand_cu_cifre_3(size_t i, char(&matrice)[nr][nr]) {
	std::cout << GREEN << "\t\t\t\t" << "      " << CYAN << i + 1 << GREEN << " | " << YELLOW << matrice[i][0] << GREEN << " | " << 
		YELLOW << matrice[i][1] << GREEN << " | " << YELLOW << matrice[i][2] << GREEN << " || " << YELLOW << matrice[i][3] << GREEN <<
		" | " << YELLOW << matrice[i][4] << GREEN << " | " << YELLOW << matrice[i][5] << GREEN << " || " << YELLOW << matrice[i][6] <<
		GREEN << " | " << YELLOW << matrice[i][7] << GREEN << " | " << YELLOW << matrice[i][8] << GREEN << " | " << RESET << std::endl;
}

void afisare_tabla_3(char(&matrice)[nr][nr]) {

	std::string bucata0{ R"(          1   2   3    4   5   6    7   8   9)" };

	std::string bucata1{ R"(	______________________________________
	                                |   |   |   ||   |   |   ||   |   |   |)" };

	std::string bucata2{ R"(	|___|___|___||___|___|___||___|___|___|
	                                |   |   |   ||   |   |   ||   |   |   |)" };

	std::string bucata3{ R"(        |___|___|___||___|___|___||___|___|___|
	                                ______________________________________
	                                |   |   |   ||   |   |   ||   |   |   |)" };

	std::string bucata4{ R"(        |___|___|___||___|___|___||___|___|___|)" };

	const int n_tab = 4;
	bucata0.insert(0, n_tab, '\t');
	bucata1.insert(0, n_tab, '\t');
	bucata2.insert(0, n_tab, '\t');
	bucata3.insert(0, n_tab, '\t');
	bucata4.insert(0, n_tab, '\t');

	std::cout << CYAN << bucata0 << std::endl;
	std::cout << GREEN << bucata1 << RESET << std::endl;
	afisare_rand_cu_cifre_3(0, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(1, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(2, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_3(3, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(4, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(5, matrice);
	std::cout << GREEN << bucata3 << RESET << std::endl;
	afisare_rand_cu_cifre_3(6, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(7, matrice);
	std::cout << GREEN << bucata2 << RESET << std::endl;
	afisare_rand_cu_cifre_3(8, matrice);
	std::cout << GREEN << bucata4 << RESET << std::endl;

}


void afisare_tabla(char(&matrice)[nr][nr], int optiune) {
	//clearScreen();
	system("CLS"); 

	switch (optiune)
	{
	case 1: {
		std::cout << std::endl;
		afisare_tabla_1(matrice);
		std::cout << std::endl;
	}break;

	case 2: {
		std::cout << std::endl;
		afisare_tabla_2(matrice);
		std::cout << std::endl;
	}break;

	case 3: {
		std::cout << std::endl;
		afisare_tabla_3(matrice);
		std::cout << std::endl;
	}break;
	}
}

//FUNCTII DE GENERARE SI ANALIZA:

//ANALIZEAZA DACA UN NUMARUL ESTE VALID SA FIE PLASAT INTR-O LOCATIE DATA

bool este_valid(char(&matrice)[nr][nr], int rand, int coloana, int numar) {
	//Verificam daca in patratul 3x3 al casutei (rand, coloana) sunt cifre identice
	//1.Gasirea patratului 3x3:
	int indice_patrat_rand = rand / 3;
	int indice_patrat_coloana = coloana / 3;

	//2.Gasirea primei casute in patratul 3x3:
	int rand_inceput = indice_patrat_rand * 3;
	int coloana_inceput = indice_patrat_coloana * 3;

	//3.Accesarea elementelor din patratul 3x3:
	for (int i{ rand_inceput }; i < rand_inceput + 3; i++) {
		for (int j{ coloana_inceput }; j < coloana_inceput + 3; j++) {
			if ((matrice[i][j] - '0') == numar) {
				return false;
			}
		}
	}

	//Verificarea daca in aceeasi coloana nu este alta valoare identica
	for (size_t i{}; i < 9; i++) {
		if ((matrice[i][coloana] - '0') == numar) {
			return false;
		}
	}
	//Verificarea daca in acelasi rand nu este alta valoare identica
	for (size_t i{}; i < 9; i++) {
		if ((matrice[rand][i] - '0') == numar) {
			return false;
		}
	}
	return true;
}

//REZOLVA GRILA INTRATA FARA DE A FACE VERIFICAREA POZITIILOR DATE INITIAL

bool rezolvare_Sudoku(char(&matrice)[nr][nr]) {
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			if (matrice[i][j] == ' ') {
				for (size_t numar{ 1 }; numar <= nr; numar++) {
					if (este_valid(matrice, i, j, numar)) {
						matrice[i][j] = static_cast<char>(numar + '0');

						if (rezolvare_Sudoku(matrice)) {
							return true;
						}
						matrice[i][j] = ' ';
					}
				}
				return false;
			}
		}
	}
	return true;
}

//PRIMUL PATRAT 3X3 ESTE RANDOM, IAR RESTUL ESTE REZOLVAT DUPA ALGORITM CONSTANT (SUNT NU MAI MULT DE 9! COMBINATII DE GRILE)

void generare_Sudoku_prim_3x3(char(&matrice)[nr][nr], int dificultate, char(&matrice_rez)[nr][nr], char(&matrice_copie)[nr][nr]) {
	//Incep sa dau cifre random in primul patrat 3x3

	inserare_spatii(matrice); //Resetarea matricii

	//Nu este necesara verificarea spatiilor libere pentru ca intial intreaga matrice contine ' '
	for (int i{}; i < 3; i++) {
		for (int j{}; j < 3; j++) {
			while (true) {
				std::random_device rd;
				std::uniform_int_distribution<int> dist(1, 9);
				int numar = dist(rd);
				if (este_valid(matrice, i, j, numar)) {
					matrice[i][j] = static_cast<char>(numar + '0');
					clearScreen();
					break;
				}
			}
		}
	}

	if (!rezolvare_Sudoku(matrice)) {
		generare_Sudoku_prim_3x3(matrice, dificultate, matrice_rez, matrice_copie);
	}

	//Stergerea elementelor pentru a crea dificultate
	//Fara copie viteza executarii este multa mai lenta
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			matrice_rez[i][j] = matrice[i][j];
			matrice[i][j] = ' ';
		}
	}

	for (size_t iterare{}; iterare < dificultate; iterare++) {
		std::random_device rd;
		std::uniform_int_distribution<int> dist(0, 8);
		int i = dist(rd);
		int j = dist(rd);
		if (matrice[i][j] == ' ') {
			matrice[i][j] = matrice_rez[i][j];
			clearScreen();
		}
		else {
			dificultate++; //Astfel se mareste numarul de iterari
		}
	}
	efectuarea_copiei(matrice, matrice_copie);
}

//GRILA ESTE GENERATA COMPLET RANDOM (AVEM MAI PUTIN DE 81! GRILE REZOLVABILE)

void generare_Sudoku_full_random(char(&matrice)[nr][nr], int dificultate, char(&matrice_rez)[nr][nr], char(&matrice_copie)[nr][nr]) {

	inserare_spatii(matrice); //Resetarea matricii

	//Nu este necesara verificarea spatiilor libere pentru ca intial intreaga matrice contine ' '
	//Introduce cifre random cu care matricea este rezolvabila
	for (int i{}; i < nr; i++) {
		for (int j{}; j < nr; j++) {
			while (true) {
				std::random_device rd;
				std::uniform_int_distribution<int> dist(1, 9);
				int numar = dist(rd);
				if (este_valid(matrice, i, j, numar)) {
					matrice[i][j] = static_cast<char>(numar + '0');

					char matrice_copie[nr][nr];
					for (size_t i{}; i < nr; i++) {
						for (size_t j{}; j < nr; j++) {
							matrice_copie[i][j] = matrice[i][j];
						}
					}

					if (rezolvare_Sudoku(matrice_copie)) {
						break;
					}
					else {
						matrice[i][j] = ' ';
					}
				}
			}
		}
	}

	//Stergerea elementelor pentru a crea dificultate
	//Fara copie viteza executarii este multa mai lenta
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			matrice_rez[i][j] = matrice[i][j];
			matrice[i][j] = ' ';
		}
	}

	for (size_t iterare{}; iterare < dificultate; iterare++) {
		std::random_device rd;
		std::uniform_int_distribution<int> dist(0, 8);
		int i = dist(rd);
		int j = dist(rd);
		if (matrice[i][j] == ' ') {
			matrice[i][j] = matrice_rez[i][j];
		}
		else {
			dificultate++; //Astfel se mareste numarul de iterari
		}
	}
	efectuarea_copiei(matrice, matrice_copie);
}

//UTILIZATA LA VERIFICAREA DACA O CASUTA CONTINE UN ELEMENT CE POATE FI MODIFICAT SAU NU (CELE DATE INITIAL NU TREBUIE SA FIE MODIFICABILE)

bool compararea_perechi_indici(int(&array_elemente)[nr * nr][2], int a, int b) {
	if (a < 0 || a > 8 || b < 0 || b > 8) {
		return true;
	}
	for (size_t i{}; i < nr * nr; i++) {
		if (array_elemente[i][0] == a && array_elemente[i][1] == b) {
			return true;
		}
	}
	return false;
}

//DUPA GENERAREA UNEI MATRICI ESTE NECESAR SA STOCHEZ ADRESELE NUMERELOR DATE INTIAL PENTRU A NU LE MODIFICA IN CONTINUARE IN OPTIUNEA 1

void colectarea_indicilor(char(&matrice)[nr][nr], int(&container)[nr * nr][2]) {
	int i_n{}, j_n{};
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			if (matrice[i][j] != ' ') {
				container[i_n][j_n] = i;
				container[i_n++][++j_n] = j;
				j_n = 0;
			}
		}
	}
	for (int i{ i_n }; i < nr * nr; i++) {
		for (int j{}; j < 2; j++) {
			container[i][j] = -1;
		}
	}
}

//VERIFICA DACA A MAI RAMAS DE INTRODUS UN SINGUR ELEMENT PENTRU CA GRILA SA FIE REZOLVATA SI INTOARCE NUMARUL FINAL 
//UTIL LA VERIFICAREA AUTOMATA CAND GRILA ESTE FINALA (STAREA CURENTA INDICA DACA ARANJAMENTUL CURENT ESTE VALID)

int sfarsit_rezolvare(bool starea_curenta, char(&matrice)[nr][nr]) {

	int count{};
	int indice_i, indice_j;
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			if (matrice[i][j] == ' ') {
				count++;
				indice_i = i;
				indice_j = j;
			}
		}
	}
	if (count == 1) {
		if (starea_curenta) {
			char matrice_copie[nr][nr];
			efectuarea_copiei(matrice, matrice_copie);
			rezolvare_Sudoku(matrice_copie);
			return static_cast<int>(matrice_copie[indice_i][indice_j] - '0');
		}
	}
	return 0;
}

//Verifica daca toate pozitiile sunt valide si daca este rezolvabila matricea
bool aranjament_valid(char(&matrice)[nr][nr]) {
	char copie[nr][nr];
	efectuarea_copiei(matrice, copie);
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) {
			if (copie[i][j] != ' ') {
				int temp = static_cast<int>(copie[i][j] - '0');
				copie[i][j] = ' ';
				if (!este_valid(copie, i, j, temp)) {
					return false;
				}
				copie[i][j] = static_cast<char>(temp + '0');
			}
		}
	}
	if (rezolvare_Sudoku(copie)) {
		return true;
	}
	else {
		/*std::cout << BLUE;
		std::cout << "\tGrila nu este rezolvabila!" << std::endl;
		std::cout << RESET;*/
		return false;
	}
}

//Ofera un indiciu pentru matrice[rand][coloana]
void indiciu(char(&matrice)[nr][nr], std::vector<std::vector<int>>& pasii, int rand, int coloana, int mod_afisare) {

	if (matrice[rand][coloana] == ' ') {
		char copie[nr][nr];
		efectuarea_copiei(matrice, copie);
		rezolvare_Sudoku(copie);
		matrice[rand][coloana] = copie[rand][coloana];

		pasii.push_back({ rand, coloana });

		afisare_tabla(matrice, mod_afisare);
		std::cout << std::endl;
		std::cout << BLUE;
		std::cout << "\tIn casuta cu indicii " << rand + 1 << " " << coloana + 1 << " a fost introdus numarul " <<
			copie[rand][coloana] << "." << std::endl << std::endl;

		std::cout << "\tAtentie, cu cat grila intiala contine mai putine elemente, cu atat este mai mare sansa " << std::endl;
		std::cout << "\tca ea sa aiba mai multe solutii. Indicii oferiti sunt in dependenta solutiei inspre care " << std::endl;
		std::cout << "\tdvs va indreptati, astfel ca pot sa nu coincida cu solutia data de optiunea 6, care la fel" << std::endl;
		std::cout << "\teste doar una din cele posibilile!" << std::endl;
		std::cout << RESET;

	}
	else {
		afisare_tabla(matrice, mod_afisare);
		std::cout << BLUE;
		std::cout << "\tCasuta cu indicii " << rand + 1 << " " << coloana + 1 << " este ocupata!" << std::endl;
		std::cout << RESET;
	}
}

//ESTE ASEMANATOARE CU SFARSIT REZOLVARE, INSA IN MOMENTUL IN CARE GRILA ESTE COMPLETA INDICA DACA ESTE SI CORECT ARANJATA

void analiza_grilei(char(&matrice)[nr][nr]) {
	bool finisata = true;
	int count = 0; 
	for (size_t i{}; i < nr; i++) {
		for (size_t j{}; j < nr; j++) { 
			if (matrice[i][j] == ' ') {
				finisata = false;
				count++; 
			}
		}
	}
	std::cout << BLUE;
	std::cout << std::endl << "\tUmplere: " << 81 - count << "/81" << std::endl;
	std::cout << RESET;

	if (finisata && aranjament_valid(matrice)) {
		std::cout << std::endl;
		std::cout << BLUE;
		std::cout << "\tGrila este rezolvata corect!" << std::endl;
		std::cout << RESET;
	}
}