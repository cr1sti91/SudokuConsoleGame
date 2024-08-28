#include "Sudoku_functions.h"


int main() {
	//Matricile sunt char, pentru ca in locul in care lipseste cifre sa fie inserate spatii
	char matrice[nr][nr];
	char copia_matrice[nr][nr]; //Pastrarea formei initiale
	char matrice_rezolvata[nr][nr];
	int numere_initiale[nr * nr][2];
	int dificultate{}, optiune{};
	int mod_afisare{}; //Initializarea cu zero pentru a face codul mai citibil

	std::string optiuni_intrare{ R"(
			1.Generarea unei grile noi 
			2.Iesire 
	)" };

	std::string optiuni_rulare{ R"(
		1   Modificarea unei casute (numerele intiale nu pot fi modificate) 
		2   Verifica daca modificarile de pana acum au fost corecte
		3   Anuleaza pasul curent (ultimul numar introdus este sters)
		4   Un indiciu
		5   Reseteaza grila la forma intiala
		6   Afisarea grilei rezolvate (grila curenta nu este modificata)
		7   Afiseaza grila curenta
		8   Generarea unei grile noi
		9   Schimba modul de afisare
		10  Iesire din joc
)" };

	/*
	*Grilele pot avea mai multe solutii!

	Grila implicita: este generat aleator mai intai primul patrat 3x3, iar apoi este calculata intraga
					 calculata intreaga grila dupa algoritm constant.

	Grila full random: este generata aleator valoarea pentru fiecare casuta (evident cu respecatarea regulilor)
					   nefiind implicat algoritmul constant de calculare.
	*/



	std::cout << "\tSUDOKU" << std::endl;
	std::cout << "\n\tOptiuni (inscrie numarul din dreptul optiunii necesare): " << std::endl;
	std::cout << optiuni_intrare << std::endl;
	std::cout << "\tOptiunea introdusa: ";
	std::cin >> optiune;
	if (optiune != 1 && optiune != 2) {
		std::cerr << RED << "\tOptiune incorecta!" << std::endl;
		std::cerr << "\tIn mod implicit este aplicata optiunea 1." << RESET << std::endl;
		optiune = 1; 
	}

	

	switch (optiune)
	{
	case 1: {

		std::cout << "\tAlege-ti modul de afisare (1, 2 sau 3): ";
		std::cin >> mod_afisare;
		if (mod_afisare < 1 || mod_afisare > 3) {
			std::cout << RED; 
			std::cout << "\tMod afisare incorect!" << std::endl;
			std::cout << "\tIn mod implicit este aplicat mod afisare - 1." << std::endl;
			std::cout << RESET;
			mod_afisare = 1;
		}

		std::cout << "\n\tIntroduce numarul de cifre ce vor fi afisate in grila: ";
		std::cin >> dificultate;

		bool dif_incorect = false;
		if (dificultate < 0 || dificultate > 81) {
			dificultate = 30;
			dif_incorect = true;
		}
		generare_Sudoku_prim_3x3(matrice, dificultate, matrice_rezolvata, copia_matrice);
		colectarea_indicilor(matrice, numere_initiale); //Pentru diferentierea numerelor initiale de restul

		afisare_tabla(matrice, mod_afisare);
		if (dif_incorect) {
			std::cout << RED; 
			std::cerr << "\tDificultate incorecta!!!" << std::endl;
			std::cerr << "\tIn mod implict este aplicata dificultatea - 30." << std::endl;
			std::cout << RESET;
			dif_incorect = false;
		}

		std::vector<std::vector<int>> pasii{}; //S-ar putea de inlocuit si cu un array[nr*nr][2] de tip int
		int rand{};

		while (true) {

			int ultim_element = sfarsit_rezolvare(aranjament_valid(matrice), matrice);
			analiza_grilei(matrice);

			std::cout << "\n\tOptiuni (inscrie numarul din dreptul optiunii necesare): " << std::endl;
			std::cout << optiuni_rulare << std::endl;
			std::cout << "\tOptiunea introdusa: ";
			std::cin >> optiune;

			switch (optiune)
			{
			case 1: {
				std::cout << "\tIndicii unei casute pot fi doua numere de la 1 la 9." << std::endl;
				std::cout << "\tIntroduceti indicii casutei in care doriti sa introduceti un numar (\"i1 i2\"): ";
				int a{}, b{}, valoare{}; //Initializare cu 0 pentru a face codul mai citibil
				std::cin >> a >> b;
				a--; b--; //Intra valori de la 1 la 9, iar utilizam de la 0 la 8

				if (!compararea_perechi_indici(numere_initiale, a, b)) {

					std::cout << "\tIntroduce-ti numarul pentru casuta respectiva: ";
					std::cin >> valoare;
					if (valoare > 0 && valoare < 10) {
						matrice[a][b] = static_cast<char>(valoare + '0');

						pasii.push_back({ a, b });

						afisare_tabla(matrice, mod_afisare);
						if (ultim_element) {
							if (ultim_element == valoare) {
								std::cout << BLUE;
								std::cout << "\tMatricea este rezolvata corect!!!" << std::endl;
								std::cout << RESET;
							}
							else {
								std::cout << BLUE; 
								std::cout << "\tMatricea este rezolvata incorect!" << std::endl;
								std::cout << RESET; 
							}
						}
					}
					else {
						afisare_tabla(matrice, mod_afisare);
						std::cout << RED; 
						std::cerr << "\tNumar incorect!" << std::endl;
						std::cout << RESET;
						break;
					}
				}
				else {
					afisare_tabla(matrice, mod_afisare);
					std::cout << RED; 
					std::cerr << "\tIndici incorecti!" << std::endl;
					std::cout << RESET; 
					break;
				}

				bool solutie_corecta = true;
				bool grila_plina = true;
				for (size_t i{}; i < nr; i++) {
					for (size_t j{}; j < nr; j++) {
						if (matrice[i][j] != matrice_rezolvata[i][j]) {
							solutie_corecta = false;
						}
						if (matrice[i][j] == ' ') {
							grila_plina = false;
						}
					}
				}
				if (solutie_corecta) {
					std::cout << BLUE;
					std::cout << "\tProbabil grila initiala are o singura solutie." << std::endl;
					std::cout << RESET; 
				}
				else if (grila_plina && ultim_element == valoare) {
					std::cout << BLUE;
					std::cout << "\tGrila poate avea mai multe solutii!!!" << std::endl;
					std::cout << RESET; 
				}

			}break;

			case 2: {
				if (aranjament_valid(matrice)) {
					afisare_tabla(matrice, mod_afisare);
					std::cout << BLUE;
					std::cout << "\tEsti pe calea cea dreapta!" << std::endl;
					std::cout << RESET;
				}
				else {
					afisare_tabla(matrice, mod_afisare);
					std::cout << BLUE; 
					std::cout << "\tAi comis cel putin o greseala!" << std::endl;
					std::cout << RESET;
				}

			}break;

			case 3: {

				if (pasii.size() != 0) {
					matrice[(pasii.back()).at(0)][(pasii.back()).at(1)] = ' ';
					afisare_tabla(matrice, mod_afisare);
					std::cout << BLUE;
					std::cout << "\tNumarul din casuta " << (pasii.back()).at(0) + 1 << " " << (pasii.back()).at(1) + 1 << 
								 " este sters!" << std::endl;
					std::cout << RESET; 
					pasii.pop_back();
				}
				else {
					afisare_tabla(matrice, mod_afisare);
					std::cout << BLUE;
					std::cout << "\tNu exista modificari anterioare!" << std::endl;
					std::cout << RESET; 
				}

			}break;

			case 4: {

				//Un indiciu
				if (aranjament_valid(matrice)) {

					std::cout << "\tCare sunt indicii casutei necunoscute? Indici (\"i1 i2\") : ";
					int rand{}, coloana{}; //Initializare cu zero pentru a face codul mai citibil
					std::cin >> rand >> coloana;
					rand--; coloana--; 
					if (rand < 0 || rand > 8 || coloana < 0 || coloana > 8) {
						afisare_tabla(matrice, mod_afisare);
						std::cout << RED;
						std::cout << "\tAti introdus indici gresiti!" << std::endl;
						std::cout << RESET; 
					}
					else {
						indiciu(matrice, pasii, rand, coloana, mod_afisare);
					}

				}
				else {
					afisare_tabla(matrice, mod_afisare);
					std::cout << BLUE;
					std::cout << "\tGrila contine greseli - nu este rezolvabila! Incearca sa anulezi pasul curent." << std::endl;
					std::cout << RESET;
				}

			}break;

			case 5: {
				//Resetarea matricii la forma ei initiala dupa ultima generare a grilei
				for (size_t i{}; i < nr; i++) {
					for (size_t j{}; j < nr; j++) {
						matrice[i][j] = copia_matrice[i][j];
					}
				}
				afisare_tabla(matrice, mod_afisare);
				std::cout << BLUE; 
				std::cout << "\tMatricea a revenit la forma initiala." << std::endl;
				std::cout << RESET; 
				pasii = {};
				rand = 0;

			}break;

			case 6: {

				std::cout << std::endl;
				afisare_tabla(matrice_rezolvata, mod_afisare);
				std::cout << BLUE;
				std::cout << "\tIn cazul existentei mai multor solutii, aceasta grila este doar una din ele!" << std::endl;
				std::cout << RESET;

			}break;

			case 7: {

				std::cout << std::endl;
				afisare_tabla(matrice, mod_afisare);
				std::cout << BLUE;
				std::cout << "\tGrila curenta." << std::endl;
				std::cout << RESET;

			}break;

			case 8: {
				std::cout << "\t0 - cea implicita (mai putin random, insa neobservabil), 1 - cea full random : ";
				int s_optiune{};
				std::cin >> s_optiune;
				if (s_optiune == 0) {
					std::cout << "\n\tIntroduce numarul de cifre ce vor fi afisate in grila: ";
					int dificultate{};
					std::cin >> dificultate;
					if (dificultate < 0 || dificultate > 81) {
						dificultate = 30;
						dif_incorect = true;
					}
					generare_Sudoku_prim_3x3(matrice, dificultate, matrice_rezolvata, copia_matrice);
					//Stocarea indicilor casutelor cu numerele date initial pentru a le diferentia de restul
					colectarea_indicilor(matrice, numere_initiale);
					pasii = {};
					rand = 0;
					afisare_tabla(matrice, mod_afisare);
					if (dif_incorect) {
						std::cout << RED; 
						std::cerr << "\tDificultate incorecta!!!" << std::endl;
						std::cerr << "\tIn mod implict este aplicata dificultatea - 30." << std::endl;
						std::cout << RESET;
						dif_incorect = false;
					}
				}
				else if (s_optiune == 1) {
					std::cout << "\n\tIntroduce numarul de cifre ce vor fi afisate in grila: ";
					int dificultate{};
					std::cin >> dificultate;
					if (dificultate < 0 || dificultate > 81) {
						dificultate = 30;
						dif_incorect = true;
					}
					generare_Sudoku_full_random(matrice, dificultate, matrice_rezolvata, copia_matrice);
					//Stocarea indicilor casutelor cu numerele date initial pentru a le diferentia de restul si a nu le modifica
					colectarea_indicilor(matrice, numere_initiale);
					pasii = {};
					rand = 0;
					afisare_tabla(matrice, mod_afisare);
					if (dif_incorect) {
						std::cout << RED; 
						std::cerr << "\tDificultate incorecta!!!" << std::endl;
						std::cerr << "\tIn mod implict este aplicata dificultatea - 30." << std::endl;
						std::cout << RESET; 
						dif_incorect = false;
					}
				}
				else {
					afisare_tabla(matrice, mod_afisare);
					std::cout << RED;
					std::cout << "\tOptiune incorecta!" << std::endl;
					std::cout << RESET;
				}

			} break;

			case 9: {
				std::cout << "\tIntroduce modul de afisare (1, 2 sau 3) : ";
				std::cin >> mod_afisare;
				bool afisare_incorecta = false;
				if (mod_afisare < 1 || mod_afisare > 3) {
					afisare_incorecta = true;
					mod_afisare = 1;
				}
				afisare_tabla(matrice, mod_afisare);
				if (afisare_incorecta) {
					std::cout << RED;
					std::cout << "\tMod afisare incorect!" << std::endl;
					std::cout << "\tIn mod implicit este aplicat mod afisare - 1." << std::endl;
					std::cout << RESET;
					afisare_incorecta = false; //Nu este obligatoriu, pt ca este locala
				}
				std::cout << BLUE;
				std::cout << std::endl << "\tGrila afisata in modul " << mod_afisare << std::endl;
				std::cout << RESET;
			}break;

			case 10: {
				std::cout << "\tO zi frumoasa in continuare!" << std::endl;
				return 0;
			} break;
				
			default: {
				afisare_tabla(matrice, mod_afisare); 
				std::cout << RED;
				std::cout << "\tOptiune incorecta, incercati din nou!" << std::endl;
				std::cout << RESET; 
			}
			}
		}
	}

	case 2: std::cout << "\tO zi frumoasa in continuare!" << std::endl;
		return 0;
		break;
	}

	return 0;
}


