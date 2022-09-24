	#include <iostream>
	#include <sstream>
	#include <limits>

	using namespace std;

	/*
	  Un operatore deve inserire ordini relativi a travi 
	  di ferro o di legno.

	  Le travi di ferro vengono vendute in lunghezze da 6 metri, 
	  e costano 30 euro. 

	  Eventuali ordini di travi di ferro che non siano multipli di 
	  6 metri saranno gestite in modo da fatturare l'eccedenza
	  rispetto ai 6 metri al prezzo di 7 euro al metro.   

	  Es: se l'operatore inserisce 3 metri avro' 3x7 = 21 euro
	  es: se l'operatore inserisce 8 metri avro' 30 + (8-6)*7 = 44 euro

	  Le travi di legno vengono vengono vendute in lunghezze da 
	  4 metri, e possono essere di due tipi: 
	    - sezione 80x80 mm, costo 32 euro. Eccedenza oltre i 4 metri 
	      costa 10 euro al metro. 
	    - sezione 120x120 mm, costo 40 euro. Eccedenza oltre i 4 metri 
	      costa 12 euro al metro. 

	  A. Scrivere un programma in C++ che permetta all'operatore
	  di svolgere le seguenti operazioni:
	  - inserire il tipo di ordine (ferro o legno)
	  - inserire la lunghezza, in metri, relativa all'ordine.
	  - Inserire la sezione, nel caso si tratta di un ordine di travi in legno. 

	  NB: Se l'utente inserisce un numero decimale per la lunghezza richiesta, 
	  il programma dovra' calcolare un opportuno arrotondamento ad un numero intero. 
	  L'operatore dovra' ricevere in output il costo totale dell'ordine. 
	   
	  B. Estendere il programma al fine di permettere all'operatore di 
	  inserire un ordine multiplo, ovvero n metri di trave 
	  in ferro ed m metri di trave in legno di una specifica 
	  sezione. 

	*/

	using namespace std;

	int main(){

	  //E' necessario usare stringhe? 
	  //Potevano essere interi? 
	  const string WOOD = "wood";
	  const string IRON = "iron";

	  const int IRON_RAFTER_LENGTH=6;
	  const int WOOD_RAFTER_LENGTH=4;

	  const int WOOD_SECTION_80_80=80;
	  const int WOOD_SECTION_120_120=120;

	  const float IRON_PRICE_STOCK = 30; // prezzi per una trave di 6 metri
	  const float IRON_PRICE_PER_METER = 7;

	  //prezzo di una trave di 4 metri 80x80 mm
	  const float WOOD_PRICE_80_80_STOCK = 32; // prezzi per una trave di 4 metri

	  //prezzo di una trave di 4 metri 120x120 mm
	  const float WOOD_PRICE_120_120_STOCK = 40;

	  //prezzo per le eccedenze, 80x80 mm e 120x120 mm
	  const float WOOD_PRICE_80_80_PER_METER=10; //eccedenze
	  const float WOOD_PRICE_120_120_PER_METER=12;

	  //Variabili che conterranno il materiale, la lunghezze richiesta
	  // e la sezione (per il legno) 
	  string material = "NO_INPUT";
	  int section, length;
	  float in_length = 0.0;
	  float total_cost;

	  //const float ROUNFING = 1.0; //QUAL E' LA DIFFERENZA? 
	  const float ROUNDING = 0.5;
	  

	  //Insert material, section (optional) length
	  
	  do{
	      cout << "(Q) Welcome, please insert material (\""<< WOOD << "\" or "    << "\"" << IRON << "\"): " << endl;
	      cin >> material;
	      if(cin.fail())
		cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }while(material != WOOD && material!=IRON);
  
	  cout << "(I) You want some rafters of " << material << endl;

	  do{
	      cout << "(Q) Please insert the length (in meters): " << endl;
	      cin >> in_length;
	      if(cin.fail())
		cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }while(in_length<=0);

	  length = (ROUNDING + in_length);
	  cout << "(I) You want " << length << " meters of rafters made by " << material << endl; 
	  
  if(material==WOOD){    

  //Input della sezione
  do{ 
      cout << "(Q) Since you want some " << material << " rafters, please insert the section. Please insert \"80\" for 80x80mm and \"120\" for 120x120 mm" << endl;
      cin >> section;  
      if(cin.fail())
	cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }while(cin.fail() || (section!=WOOD_SECTION_80_80 && section!=WOOD_SECTION_120_120));
  }//~end if

  //Now we calculate the total cost
  if(material == WOOD) 
    if(section == WOOD_SECTION_80_80)
      total_cost = (length%WOOD_RAFTER_LENGTH)*WOOD_PRICE_80_80_PER_METER + length/WOOD_RAFTER_LENGTH * WOOD_PRICE_80_80_STOCK;
    else //section is 120x120   	 
      total_cost = (length%WOOD_RAFTER_LENGTH)*WOOD_PRICE_120_120_PER_METER + length/WOOD_RAFTER_LENGTH * WOOD_PRICE_120_120_STOCK;
  else //material is made of iron!     
      total_cost = (length%IRON_RAFTER_LENGTH)*IRON_PRICE_PER_METER + length/IRON_RAFTER_LENGTH * IRON_PRICE_STOCK;

  stringstream out_section; //Perche' uso stringstream? 
  if(section==WOOD_SECTION_80_80)
    out_section <<  WOOD_SECTION_80_80 << "x" << WOOD_SECTION_80_80;  
  else
    out_section << WOOD_SECTION_120_120 << "x" << WOOD_SECTION_120_120;  

  cout << "(I) Total cost for " << length << " meters of " << material << " rafter "<< (material==WOOD ? out_section.str() : "") << ": " <<  total_cost << endl;
}
