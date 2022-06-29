//définition des variables
float rayon = 0.1;
int v_max = 315;  //vitesse max du moteur en tr/min
int R = 20;   //rapport de réduction du réducteur
float omega = 0;
float v_rot = 0;
float omega_e = 0;
int pmw = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float omega = vitesse/rayon;              //conversion vitesse en vitesse de rotation
  float v_rot =(omega * 60)/(2 * 3.14);     //conversion en tr/min
  float omega_e = v_rot / R;                //calcul de la vitesse à imposer au moteur avant réduction
  int pmw = omega_e * 255 / v_max;          //obtenir une valeur de vitesse entre 0 et 255
  analogWrite(11,pmw);

}
