#define ENTREE_ANALOGIQUE 0

void setup()
{
  Serial.begin(115200) ;
}

void loop()
{
  // lecture de la valeur analogique à mesurer
  int valeurLue = analogRead(ENTREE_ANALOGIQUE) ;

  // conversion de la valeur lue en une tension en centi-Volts
  float tensionLue = map(valeurLue, 0, 1023, 0, 500);

  // envoi pour affichage sur le moniteur série de la tension mesurée
  Serial.print("Tension :" ) ;
  Serial.println(tensionLue / 100.0) ; // Afficher la valeur en Volts
  Serial.println( "Volts") ;

  // attente d’une seconde (1000 millisecondes) entre deux mesures & affichages
  delay(100) ;
}
